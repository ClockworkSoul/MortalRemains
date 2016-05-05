 
//	File	:  /std/connection.c
//	Creator	:  Buddha@TMI  (1/93)
//	Updated	:  Watcher@TMI (2/28/93) to move wizard flag from user
//		    object to the connection object.
//		   Watcher@TMI (3/16/93) to setup new body connection system
//
//	This is a generic user connection object which is linked 
//	to a specific user body.

#include <uid.h>
#include <login.h>
#include <daemons.h>

string name, password, body, email, real_name, ip, userid, session, finger_string;
string gender, title, spouse;
mapping domains;
mixed *passwd_fail;
int wizard, last_on, dead, hibernate, level, email_hide;

static object body_ob, tmp_body;
static string termtype;

int remove();
int save_data_conn();
static void terminal_type(string term);

//  It would be Bad (tm) to allow a connection object to be shadowed.

int query_prevent_shadow() {  return 1;  }
 
// Keep this static so that only driver can call this.
static void logon() {
	seteuid(0);
//	seteuid("Logon") ;
	wizard = 0;
	call_out("check_status", 5 * 60);
	LOGIN_D->logon(this_object());
}

int connect() {
	if (geteuid(previous_object()) != ROOT_UID) return 0;
	if (!body_ob) return 0;
	if (!interactive(this_object())) {
		if (!interactive(body_ob)) body_ob->remove();
		remove();
	} 

/*  I think this is not needed but I might be wrong ;)
	ip = query_ip_name( this_object() );
	last_on = time();
*/
 
	if (!exec(body_ob, this_object())) {
		write("Error connecting to your body... try again...\n");
		body_ob->remove();
		remove();
		return 0;
	}
	body_ob->set_link(this_object());
	return 1;
}
 
int switch_body() {

   if((geteuid(previous_object()) != ROOT_UID && 
       previous_object() != body_ob) || !tmp_body)  return 0;
 
   if(interactive(tmp_body) || !interactive(body_ob) ||
      !exec(tmp_body, body_ob))  return 0;
 
   body_ob = tmp_body;
   export_uid(body_ob);
   tmp_body = 0;
 
   body_ob->set_link(this_object());
   body_ob->restore_body();

return 1; }
 

nomask void receive_message(string class, string msg) {
	receive(msg);
}

void link_dead() {
	save_data_conn();
	remove();
}

// We need this function in case a player is queried for his link while he<
// is in login or for some other reason has no body.

object query_link() {
	return this_object() ;
}

 
int save_data_conn() {
	if (!name || name == "Logon" || !password) return 0;
	assure_user_save_dir(this_object());
	save_object(user_data_file(this_object()));
	return 1;
}


int restore() {

	int success ;

   if( !name || geteuid( previous_object() ) != ROOT_UID ) return 0;
// printf( "Debug: PO is %O\n", previous_object() );
// printf( "Debug: geteuid(PO) is %O\n",  geteuid( previous_object() ) );
// printf( "Debug: getuid(PO) is %O\n",  getuid( previous_object() ) );
//    printf("Debug: Euid is %s.\n", geteuid());
// seteuid(name);
// Removed by Blue.  It appears to have no effect. 940425.
//    printf("Debug: Euid is %s.\n", geteuid());
#if 0
	return restore_object(user_data_file(this_object()));
#else
// Log data files which don't load...don't exist? wrong permissions at
// Unix level?
        if (catch(success = restore_object(user_data_file(this_object())))) {
                log_file("restore_err",
                sprintf("[%s] Unable to restore_object(\"%s\")\n", name,
                      user_data_file(this_object()) ));
                      success = 0;
        }
        return success;
#endif
}

int restore_body() {
	if (geteuid(previous_object()) != ROOT_UID) return 0;
	if (!name || !body) return 0;
	seteuid(name);
	if(catch( body_ob = new(body) ))  return 0;
	export_uid(body_ob);
	if (!body_ob) {
		write("Could not create a " + body + " for you to log into.\n");
		return 0;
	}
	return (int) body_ob->restore_body();
}

int remove() {
	save_data_conn();
	destruct(this_object());
	return 1;
}

int remove_user() {  call_out("remove", 0);  return 1;  }
 
int clean_up() {
	if (!body_ob || !interactive(body_ob)) return remove();
	save_data_conn();
	return 1;
}

nomask mixed query(string what) {

	if (!what) return 0;
	switch (what) {
		case "name" :
			return (name ? name : "logon");
		case "cap_name" :
			return (name ? capitalize(name) :"Logon");
		case "password" : return password;
                 case "spouse" : return spouse;
                case "title" : return title;
		case "wizard" : return wizard;
		case "body" : return body;
                case "finger_string": return finger_string;
		case "dead" : return dead;
    case "gender" : return gender;
		case "tmp_body" : return tmp_body;
		case "hibernate" : return hibernate;
		case "real_name" : return real_name;
		case "passwd_fail" : return passwd_fail;
		case "email" : return email;
		case "body_ob" : return body_ob;
		case "last_on" : return last_on;
		case "ip" : return ip;
                case "email_hide" : return email_hide;
                case "level" : return level;
                case "session" : return session;
                case "termtype" : return termtype;
		case "userid" : {
		  if(geteuid(previous_object()) != ROOT_UID) return 0;
	 	  else return userid;
		}
		case "domains" : {
			if (geteuid(previous_object()) == ROOT_UID)
	{
				return domains;
			}
			else return copy(domains);
		}
		default : return 0;
	}
}

nomask void set(string what, mixed val) {
        if (!what) return 0;
 
	if(geteuid(previous_object()) != ROOT_UID &&
	   previous_object() != body_ob)  return;
 
        switch (what) {
                case "name" : name = val; seteuid(name); break;
       case "password" : password = val;break;
       case "spouse" : spouse = val ; break;
		case "wizard" : wizard = val; break;
		case "passwd_fail" : passwd_fail = val; break;
                case "title" : title = val ; break;
                  case "gender" : gender = val; break;
                case "session" : session = val; break;
                case "finger_string" : finger_string = val;break;
                case "email_hide" : email_hide = val; break;
                case "level" : level = ((val > 0) ? val : 1);break;
          //    case "level" : level = val; break;
                case "body" : body = val; break;
		case "tmp_body" : tmp_body = val; break;
		case "real_name" : real_name = val; break;
                case "email" : email = val; break;
		case "body_ob" : body_ob = val; break;
		case "hibernate" : hibernate = val; break;
		case "dead" : dead = val; break;
		case "domains" : domains = val; break;
		case "userid" : userid = val; break;
		case "last_on" : last_on = val; break;
		case "ip" : ip = val; break;
		case "termtype" : termtype = val; break; // Leto
		default : return;
        }
	save_data_conn();
}

int check_status() {

   remove_call_out("check_status");
 
   if(interactive(this_object()) || !body_ob || !interactive(body_ob))
	remove();

return 1; }

 

void terminal_type(string term) {

termtype = term;
}
