
#include "/u/c/cyanide/debug.h"

inherit DAEMON;

int cmd_spellcheck( string str ) {
    string *files, dir;
    int i;

    seteuid(getuid());

    dir = (string)TP->query("cwd") + "/";

    if (!str || str=="") {
	str = "*.c";
    }

    files = get_dir( dir + str );

    for (i=0; i<sizeof(files); i++) {
	object sob = clone_object( dir + files[i] );
	str = "Trying "+files[i]+": ";

	if (!sob) {
	    str += "*Could not clone object.*\n";
	} else {
	    if (sob->query_spell()) {
		str += "query_spell() is true.\n";
	    } else {
		str += "query_spell() is FALSE\n";
	    }
	}
	destruct(sob);
	write(str);
    }

    return 1;
}

/* EOF */
