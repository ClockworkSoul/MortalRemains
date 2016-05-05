//   Cattt is taking this sewer idea from BatMud //

#include <mudlib.h>
#include <sewers.h>

inherit OBJECT;
void create(){
    seteuid(getuid());
    set("author","cattt");
    set("id", ({ "paper", "" }) );
    set("short", "a piece of paper");
    set("long", "A piece of paper. Perhaps you should read it. \n" );
    set("value", 0);
}
void init () {
    add_action ("read", "read");
}

int read (string str) {
    if (!str) {
	write ("Read what?\n");
	return 1;
    }
    if (str=="paper") {

	write (@End
                 The story of the legendary SewerBlade

Long ago there was a mighty warrior who was afraid of his superior weapon 
being misused as he was about to retire.  As a safety precaution, the 
warrior drove his blade into a rock deep in the sewers of the realm.  
Legend has it that the only way to retrieve this powerful blade is to
find the rock and the four tributes that when placed on the rock will
lossen the stone and let the blade be removed.  


End
);


} else {
    write("Read what?\n");
}
return 1;
}
