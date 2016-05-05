// Created by Cyanide to find invalid help() functions
// which return integer values.
// This is a quick kludgey hack and he knows it.

#include "/u/c/cyanide/debug.h"

#define OK 1
#define NO_HELP 0
#define INTEGER -1
#define OTHER   -2

int check_command( string, string );

inherit DAEMON;

int cmd_helpcheck( string str ) {
    int i, flag;
    string dir, cmd, *files, *nohelp, *inthelp, *other;
    mixed result;

    seteuid(getuid());

    nohelp = ({});
    inthelp = ({});
    other = ({});
    flag = 0;

    dir = (string)TP->query("cwd") + "/";

    if (!str || str=="") {
	str = "_*.c";
    }

    files = get_dir( dir + str );

    for (i=0; i<sizeof(files); i++) {
	switch( check_command( dir, files[i] ) ) {
	case INTEGER : inthelp += ({ files[i] }); break;
	case NO_HELP : nohelp += ({ files[i] }); break;
	case OTHER : other += ({ files[i] }); break;
	default : break;
	}
    }

    write("\n ** Helpcheck results: \n");
    if (sizeof(inthelp)) {
	str = "";
	flag = 1;
	str = "HELP RETURNS AN INTEGER: "+inthelp[0];
	for (i=1; i<sizeof(inthelp); i++) str += ", "+inthelp[i];
	write(iwrap(str));
	str = "";
    }
    if (sizeof(nohelp)) {
	str = "";
	flag = 1;
	str += "HAVE NO HELP DEFINED: "+nohelp[0];
	for (i=1; i<sizeof(nohelp); i++) str += ", "+nohelp[i];
	write(iwrap(str));
    }
    if (sizeof(other)) {
	str = "";
	flag = 1;
	str += "OTHER PROBLEMS: "+nohelp[0];
	for (i=1; i<sizeof(other); i++) str += ", "+other[i];
	write(iwrap(str));
    }

    if (!flag)
	write("Helpcheck: All files set correctly.\n");

    return 1;
}

int check_command( string dir, string file ) {
    mixed result;
    int flag = OTHER;
    object ob;

    DEBUG("Finding "+file+" in "+dir+"\n");
    if (file_exists( dir + file ))
	ob = find_object_or_load( dir + file );
    else
	write(file+": No such file.\n");

    if (ob) {
	if (function_exists("help", ob)) {
	    result = ob->help();

	    if (intp(result)) flag = INTEGER;
	    if (stringp(result)) flag = OK;
	} else {
	    flag = NO_HELP;
	}
    }

    return flag;
}


string help() {
    return(
      iwrap("This shows incorrectly set help files in "+
	"commands. Incorrectly set files WILL spam you."));
}

/* EOF */
