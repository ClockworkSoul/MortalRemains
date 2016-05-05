/*
** Register command, to do admin stuff with the player registry.
**
** Credits:
**   14-10-98   Cyanide created this command.
*/

#include <uid.h>
#include <daemons.h>
#include <registry.h>

string help();
int get_info( string ); 
int do_complete_list(); 
void output_status ( int );
int about_registry();

int cmd_register ( string str ) {
    string email;
    int flag;

    if (!adminp(TP)) return 0;

    seteuid(ROOT_UID);

    if (!str || str=="")
    {
	write(help());
	return 1;
    }

    if (str[0..0] == "-") {
	str = replace_string(str, "-", "");

	email = "";
	sscanf(str, "%s %s", str, email);

	switch(str) {

	case "i" :
	    if (!email || email=="") {
		write(wrap("The \"i\" switch requires a name "+
		    "or email argument."));
		return 1;
	    }
	    return get_info(email);
	    break;
	case "R" :
	    if (!email || email=="") {
		write(wrap("The \"R\" switch requires a name "+
		    "or email argument."));
		return 1;
	    }
	    if (strsrch(email, "@")!=-1) {
		flag = REGISTRY_D->remove_email(email);
	    } else {
		flag = REGISTRY_D->remove_player(email);
	    }

	    switch(flag) {
	    case OKAY : write("Name/email successfully purged "+
		  "from registry.\n");
		break;
	    case NO_SUCH_NAME : write(wrap("Could not find "+email+
		    " in registry.\nFailed."));
		break;
	    default : write(wrap("*WARNING* Registry daemon returned "+
		    "an unknown value.\nCheck code!") );
	    }

	    break;
	case "L" :
	    return do_complete_list(); 
	    break;
	case "S" :
	    output_status( REGISTRY_D->query_active() );
	    return 1;
	    break;
	case "a" : 
	    about_registry();
	    return 1;
	    break;
	case "activate" :
	    if (REGISTRY_D->activate()) {
		REGISTRY_D->admin_call(TPN+" has just re-activated "+
		  "the player registry.");
	    } else
		write("The registry daemon is already active\n");
	    return 1;
	    break;
	case "deactivate" :
	    if (REGISTRY_D->deactivate()) {
		REGISTRY_D->admin_call(TPN+" has just deactivated "+
		  "the player registry.");
	    } else
		write("The registry daemon is already inactive\n");
	    return 1;
	    break;
	default : 
	    write("You have entered an invalid switch.\n"+
	      "Type \"help register\" for help.\n");
	    return 1;
	}
    } else {

	// The user doesn't use one of those switch thingies.

	flag = 0;
	email = "";
	if (sscanf(str, "%s %s", email, str) != 2) flag = 1;
	if (sizeof(explode(email, "@")) != 2) flag = 1;
	if (flag) {
	    write("Invalid syntax. Type \"help register\""+
	      "for more info.\n");
	    return 1;
	}
	if (strlen(str) > 12) {
	    write("Sorry, char names cannot exceed 12 characters.\n");
	    return 1;
	}

	flag = REGISTRY_D->add_player(email, str);

	switch(flag) {
	case OKAY : str = "Name has been successfully registered."; break;
	case NAME_IN_USE : str = "That name is already in use."; break;
	case TOO_MANY_NAMES : str = "That address has too many "+
	    "names already registered to it."; break;
	case DAEMON_NOT_ACTIVE : str = "Sorry - the registry daemon is not "+
	    "currently active."; break;
	default: str = "WARNING: Registry daemon returned a result I do "+
	    "not understand."; break;
	}

	str = "Registry Daemon: "+str;
	write(wrap(str));
    }

    return 1;
}

/******************************************************************/

int do_complete_list() {
    write("Sorry - this option is not yet functional.\n");
    return 1;
}

/******************************************************************/

int about_registry() {
    write("Sorry - this option is not yet functional.\n");
    return 1;
}

/******************************************************************/

int get_info( string str ) {
    write(REGISTRY_D->get_info(str));
    return 1;
}

/******************************************************************/

void output_status ( int status ) {
    string str;

    switch(status) {
    case ERROR : str = "in a state of ERROR, and is inactive.";
	break;
    case INACTIVE : str = "currently inactive.";
	break;
    case ACTIVE : str = "active and running normally.";
	break;
    default : str = "in an UNIDENTIFIED STATE. Check code.";
    }

    str = "Status: The Registry Daemon "+str;
    write(iwrap(str));
}

/******************************************************************/

string help () {
    return (@EndHelp
Usage:
     register -i < name | email >   Get info on all names registered to
                                    that name or email.
     register -L                    Gives a complete listing of all registered
                                    emails and names registered to them.
     register -S                    Registry status.
     register -a                    About the registry requirements and limits.
     register -activate             Turn on the registry daemon. (logged)
     register -deactivate           Turns off the registry daemon. (logged)
     register <email> <name>        Registers a name to an email address.
     register -R <email|name>       Deregister a name or email address.
EndHelp
    );

}

/* EOF */
