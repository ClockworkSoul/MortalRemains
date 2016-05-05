/*
** The player registry daemon.
**
** Written by Cyanide while the MUD was down during the dark
** days of September, 1998.
**
** Purpose:  To keep track of email registered players and their doubles.
**     Players are allowed a max of total characters equal to MAX_CHARS
**     ( originally set to 2 ). Wizards 3, admin 4.
**
** Credits:
**    15 Sep 98  Cyanide started the file. It will be ugly.
**    08 Dec 98  Made so you can REMOVE shit now. Woo.
**
** Todo:
**   (i) Add log file and data dumping.
**  (ii) Link in logind.c to make sure no doubles are logged in, except
**       for wizard characters.
** (iii) Link to purge and nuke to remove the registered character.
**       Support option of removing all registered characters.
**  (iv) Make so nuke will optionally de-register a character name.
**
*/

#include <logs.h>
#include <registry.h>
#include <daemons.h>
#include <uid.h>
//#include "/u/c/cyanide/debug.h"

// Global variables.
int active = INACTIVE;
mapping reg_map = ([]);

// Prototypes
string find_email( string );
int save_reg_data();
int load_saved_data();
int max_chars (string);
int query_active();
nomask int save_all();

inherit "/adm/daemons/timezone";

/******************************************************************/

/*
** Function:   void admin_call()
** Purpose:    Notifies admin when Something Bad (tm) happens.
** Receives:
**    string str      The string to announce.
** Returns:    Void
** Credits: 
**    21 Sep 98   Cyanide created the function 21 Sep 98.
*/ 

void admin_call(string str) 
{
    object *obs = users();
    int i, sz;

    if (getuid(previous_object()) != ROOT_UID &&
      !member_group(TPN, "admin") ) return;

    str = iwrap("** ADMIN NOTICE: "+str+" **");
    sz = sizeof(obs);

    for (i=0; i<sz; i++)
	if (adminp(obs[i]))
	    tell_object(obs[i], str);

    return ;
}


/******************************************************************/

/*
** Function:   int add_player()
** Purpose:    Adds a players name to the registry, associating it
**	with a specific email address.
** Receives:
**    string email    Player's email address
**    string name     Name of player to be registered.
** Returns:
**    0   Successful.
**    1   Name already in use.
**    2   Email has too many names associated with it.
**    4   Daemon is not active.
** Credits: 
**    21 Sep 98   Cyanide created the function 21 Sep 98.
** ToDo: 
**   (i) Cross referance listing with all banned names and all 
**       emails with banned sites.
**  (ii) Check for wizard status of all names already in array.
*/

int add_player(string email, string name)
{
    string *emails, *names;
    mapping tmp_map;
    int i, j, val = 0;

    //if (active!=ACTIVE) return DAEMON_NOT_ACTIVE;

    // We use emails as a temporary storage so that we can get a 1-d
    // array of all currently registered names.

    emails = values(reg_map);
    names = ({});
    for (i=0; i<sizeof(emails); i++) 
	for (j=0; j<sizeof((string *)emails[i]); j++) 
	    names = ( names + ({ emails[i] }) );

	// First, we make sure nobody else has that name registered.

    if (find_email(name)!="")
	return NAME_IN_USE;

	if (name == "cyanide" || name == "chronos" || name == "driver")
	return NAME_IN_USE;


    emails = keys(reg_map);

    i = member_array(email, emails);
    if (i==-1) {
	tmp_map = ([ email : ({ name }) ]);
	reg_map += tmp_map;
    } else {

	// Now, we make sure that the player has no more than MAX_CHARS
	// registered to him/her/it.

	names = (string *)(values(reg_map)[i]);
	if ( sizeof(names) >= max_chars(name) )
	    return TOO_MANY_NAMES;
	else {
	    names = ( names + ({ name }) );
	    reg_map[email] = names;
	}
    }

#ifdef REG_LOG
    log_file(REG_LOG, ctime(time())[4..15]+" registered "+
      capitalize(name)+" to "+email+"\n");
#endif

    save_all();
    return OKAY;
}

/******************************************************************/

int activate() {
    if (getuid(previous_object()) != ROOT_UID &&
      previous_object() != TO ) 
	return 0;

    if (active == INACTIVE) {
	active = ACTIVE;
	return 1;
    }

    return 0;
}

/******************************************************************/

void core_dump() {
    int i, j, num, num2, count;
    string *emails, *names, *tmp, str;

    if (file_exists(REG_DUMP_LOG))
	rename(REG_DUMP_LOG, REG_DUMP_LOG+".bak");
    write_file(REG_DUMP_LOG, "Registry Core Dump: \n");

    emails = keys(reg_map);
    names = values(reg_map);
    num = sizeof(emails);
    count = 0;

    for (i=0; i<num; i++) {
	str = emails[i]+"   ";
	tmp = (string *)names[i];

	num2 = sizeof(tmp);
	if (num2) {
	    str += capitalize(tmp[0]);
	    count++;
	}
	for (j=1; j<num2; j++) {
	    str += ", "+capitalize(tmp[j]);
	    count++;
	}
	str += "\n";
	write_file(REG_DUMP_LOG, str);
    }
    str = "\n  "+num+" emails, "+count+" names registered.\n"+
    "  Completed: " + ctime(query_tzone("EST"));
    write_file(REG_DUMP_LOG, str);
}

/******************************************************************/

int deactivate() {
    if (getuid(previous_object()) != ROOT_UID &&
      previous_object() != TO ) 
	return 0;

    if (active != INACTIVE) {
	active = INACTIVE;
	return 1;
    }

    return 0;
}

/******************************************************************/

string find_email( string name ) {
    int i, j, size, size2;
    string *emails, *names, *tmp, email;

    emails = keys(reg_map);
    email = "";
    names = values(reg_map);
    size = sizeof(emails);

    for(i=0; i<size; i++) {
	tmp = (string *)(names[i]);
	if (member_array(name, tmp)!=-1) {
	    email = emails[i];
	    break;
	}
    }

    return email;
}

/******************************************************************/

string get_info(string str) {
    int i, val;
    string tmp = ("Info for "+str+":\n");
    string *array;

    // If the user enters an email address:
    if (strsrch(str, "@")==-1) str = find_email(str);

    val = member_array(str, keys(reg_map));
    if (val==-1)
	return ("That name or email is not registered.\n");

    array = (string *)(values(reg_map)[val]);

    tmp += ("  Email: "+str+"\n");
    val = sizeof(array);
    if (!val) {
	tmp += "  No names registered to that email.\n";
    } else {
	tmp += ("  Names: "+capitalize(array[0]) );
	for (i=1; i<val; i++)
	    tmp += (", "+capitalize(array[i]));
	tmp += " ("+val+" names.)\n";
    }

    return tmp;
}

/******************************************************************/

/*
** int is_registered
** Purpose: Tell if a name or email is registered.
*/

int is_registered( string str )  {
    int val;

    if (INACTIVE) return 1;

    if (strsrch(str, "@")==-1) str = find_email(str);

    val = member_array(str, keys(reg_map));

    (val==-1) ? val=0 : val=1;
    return val;
}

/******************************************************************/

nomask int save_all() {
    save_object(SAVE_PATH_MAIN+SAVE_NAME);
    save_object(SAVE_PATH_ATTIC+SAVE_NAME);
}

/******************************************************************/

nomask int load_saved_data() 
{
    if (!restore_object(SAVE_PATH_MAIN+SAVE_NAME)) 
    {
	admin_call("ERROR: Failure in loading primary "+
	  "registry! Attempting to load from backup copy.");
	if (!restore_object(SAVE_PATH_ATTIC+SAVE_NAME)) {
	    admin_call("ERROR: Fatal failure loading "+
	      "backup copy. Registry entering inactive mode.");
	    active = ERROR;
	} else {
	    active = ACTIVE;
	}
    } else {
	active = ACTIVE;
    }

    return active;
}

/******************************************************************/

int max_chars (string name) {
    int num = MAX_CHARS;

    if (member_group(name, "adminaccess")) num++;

    return num;
}

/******************************************************************/

// PURPOSE: ** EMERGENCY USE ONLY!!! **
// This prime the player registry after a crash or accidental
// deletion. (It happens.)

int prime() {
    if (getuid(previous_object()) != ROOT_UID &&
      previous_object() != TO ) 
	return 0;

    if (active!=ERROR) return 0;

}

/******************************************************************/

/*
** Function:   query_active()
** Purpose:    Returns the active status of the registry daemon.
*/

int query_active() { 
return 0;
//return active; 
}

/******************************************************************/
// PURPOSE: This func filters out the email address from the
//      registry.

int remove_email ( string email ) {
    int i, sz, flag = NO_SUCH_NAME;
    mapping tmp = ([]);
    string *emails;

    //if (active!=ACTIVE) return DAEMON_NOT_ACTIVE;

    emails = keys(reg_map);
    sz = sizeof(emails);

    for (i=0; i<sz; i++) {
	if (emails[i]!=email) {
	    tmp += ([ emails[i] : reg_map[emails[i]] ]);
    } else {
	flag = OKAY;
    }
}

reg_map = tmp;
save_all();
return flag;
}

/******************************************************************/

int remove_player ( string name ) {
    int i, j, sz;
    string *emails, *names, tmp = "";

    // Temporarily borrowing the 'emails' variable.
    sz = sizeof(keys(reg_map));
    emails = values(reg_map);
    for (i=0; i<sz; i++) {
	if (member_array(name, emails[i]) != -1) 
	{
	    names = (string *)emails[i];
	    tmp = keys(reg_map)[i];
	    break;
	}
    }

    if (!tmp || tmp=="")  return NO_SUCH_NAME;

    // Now we filter out the name we don't want anymore.
    names = filter_array(names, "filter_names", TO, name);

    // Put the filtered names array back in the mapping.
    reg_map[tmp] = names;

    save_all();

    return OKAY;	
}

/******************************************************************/

int filter_names( string str, string name ) {
    if (str==name) return 0;
    return 1;
}

/******************************************************************/

mapping dump_registry() { return reg_map; }

/******************************************************************/

void create() 
{
    seteuid( ROOT_UID );
    load_saved_data();
}

/* EOF */
