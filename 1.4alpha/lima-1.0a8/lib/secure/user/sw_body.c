/* Do not remove the headers from this file! see /USAGE for more info. */

#include <config.h>
#include <daemons.h>
#include <security.h>

string query_userid();

void save_me();
void remove();

void report_login_failures();

void modal_simple(function input_func, mixed prompt, int secure,int lock);

void set_privilege(mixed priv);		// from M_ACCESS
mixed unguarded(mixed priv, function fp);

void start_shell();
void run_login_script();

int query_n_gen();

/*
** The file name for the body object
*/
private string		body_fname;

/*
** The body object once it has been instantiated
*/
nosave private object	body;


nomask string query_body_fname()
{
    return body_fname;
}

nomask object query_body()
{
    return body;
}

//### temp hack for upgrading link files. see restore_me()
protected nomask void set_body_fname(string new_body_fname)
{
    body_fname = new_body_fname;
}


varargs nomask void switch_body(string new_body_fname, int permanent)
{
    object where;
    object old_body;

    if (previous_object() != body && this_body() != body)
	error("security violation: bad body switch attempt\n");

    where = body ? environment(body) : (mixed)VOID_ROOM;

    if ( permanent && new_body_fname )
    {
	body_fname = new_body_fname;
	save_me();
    }

    if ( !new_body_fname )
	new_body_fname = body_fname;

    old_body = body;
    body = new(new_body_fname, query_userid());
    master()->refresh_parse_info();

    if (old_body) {
	old_body->move(VOID_ROOM);
	old_body->quit();
	if ( old_body )
	    catch(old_body->remove());
    }

    report_login_failures();

    /* NOTE: we are keeping the same shell for now... */

    body->su_enter_game();
    body->move(where);
}


/*
** Functions to get the body set up and the user into the game.
*/

private nomask void incarnate(int is_new, string bfn)
{
    if (bfn) body_fname = bfn;

    body = new(body_fname, query_userid());
    master()->refresh_parse_info();

    LAST_LOGIN_D->register_last(query_userid(), query_ip_name(this_object()));
    if ( query_n_gen() != -1 )
	body->set_gender(query_n_gen());
    save_me();

    start_shell();
    body->enter_game(is_new);
    run_login_script();

    if ( is_new )
    {
#ifdef USE_STATS
	this_body()->init_stats();
#endif
	body->save_me();
    }
}

void sw_body_handle_existing_logon(int);

private nomask void rcv_try_to_boot(object who, string answer)
{
    answer = lower_case(answer);
    if( answer == "yes" || answer == "y" )
    {
	who->receive_private_msg("You are taken over by yourself, or something.\n");
	who->quit();

	sw_body_handle_existing_logon(0);
	return;
    }
    if( answer == "n" || answer == "no" )
    {
	if ( wizardp(query_userid()) )
	{
	    sw_body_handle_existing_logon(1);
	    return;
	}

	write("Try another time then.\n");
	destruct(this_object());
    }

    write("please type 'y' or 'n'  >");
    modal_simple((: rcv_try_to_boot, who :),0,0,1);
}

protected nomask void sw_body_handle_existing_logon(int enter_now) {
    remove_call_out();	/* all call outs */

    if (!enter_now) {
	/*
	** Okay... an existing user is ready for their body.  Look for other
	** users currently connected with this userid.  Those other users may
	** be interactive or link-dead.  Do the right thing...
	*/
	object * users;
	string * ids;
	int idx;
	object the_user;

	/* adjust the privilege of the user ob */
	if ( adminp(query_userid()) )
	    set_privilege(1);
	else
	    set_privilege(query_userid());

	/* check for link-deadedness */
	users = children(USER_OB) - ({ this_object() });
	ids = users->query_userid();
	if ( (idx = member_array(query_userid(), ids)) != -1 ) {
	    if ( !interactive(the_user = users[idx]) ) {
		if ( body = the_user->query_body() ) {
		    master()->refresh_parse_info();
		    the_user->steal_body();
		    start_shell();
		    body->reconnect(this_object());
		    return;
		}
	    } else {
		write("\nYou are already logged in!\nThrow yourself off?  ");
		modal_simple((: rcv_try_to_boot, the_user :),0,0,1);
		return;
	    }
	}
    }

    write("\n"+read_file(MOTD_FILE));

    report_login_failures();
    BIRTHDAY_D->report();

    incarnate(0, 0);
}

/* when a user reconnects, this is used to steal the body back */
nomask void steal_body()
{
    /* only USER_OB can steal the body, and we should be non-interactive */
    if ( base_name(previous_object()) != USER_OB || interactive() )
	error("illegal attempt to steal a body\n");

    body = 0;
    remove();
}

/*
** A new character has been created and all inputs have been entered.
** Do a bit of additional work and go for a body.
*/
protected nomask void sw_body_handle_new_logon()
{
    remove_call_out();	/* all call outs */

#ifdef AUTO_WIZ
    /* auto-wiz everybody as they are created */
    write(">>>>> You've been granted automatic guest wizard status. <<<<<\n");
    unguarded(1, (: SECURE_D->create_wizard($(query_userid())) :));
#endif

    /* auto-admin the first wizard if there are no admins */
    {
	string * members = SECURE_D->query_domain_members("admin");

	if ( !sizeof(members) )
	{
	    if( !wizardp(query_userid())) unguarded( 1, (: SECURE_D->create_wizard($(query_userid())) :));
	    write( ">>>>> You have been made admin. Remember to use admtool. <<<<<\n");
	    unguarded(1, (: SECURE_D->add_domain_member("admin",
		  $(query_userid()),
		  1) :));
	}
    }

    /* adjust the privilege of the user ob */
    if ( adminp(query_userid()) )
	set_privilege(1);
    else
	set_privilege(query_userid());

    // pass a lfun pointer so that we don't have to worry about validating
    // the call.
    NEW_USER_D->create_user( (: incarnate, 1 :) );
}
