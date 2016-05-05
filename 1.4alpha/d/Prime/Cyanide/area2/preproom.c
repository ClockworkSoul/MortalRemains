#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", "cyanide");
    set ("short", "Preparation Room");
    set( "long", @EndText
When Torkath was to appear before his people or visiting dignitaries,
he would meet here with his advisors and any other servants that deemed
important enough for the task at hand.
EndText
    );
    set( "exits", ([
      "west" : MAIN+"/room8'5.c",
      "east" : MAIN+"/spireante.c",
    ]) );

    set ("item_desc", ([
    ]) );
}
void init () {
    add_action ("exits","exits");
}
int exits() {
    write ("You begin to get a nasty headache.\n");
    say (NAME+" begins to look very confused.\n");
    return 1;
}
