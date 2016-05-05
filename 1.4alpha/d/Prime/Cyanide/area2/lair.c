#include "main.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
    seteuid( getuid());
    ::create();
    set( "light", 1 );
    set ("objects", ([
      "balrog" : MONST+"/balrog.c" ]) );
    set("short","Felayshono's Lair");
    set( "long", @EndText
You have entered the lair of Felayshono. Beware!
For he is a balrog, a demon of might!
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/tresroom.c",
      "west" : MAIN+"/doorstep.c"
    ]) );
    set("arena",1);
    set ("author", "Gothmog, with minor editing by Cyanide");
}
void reset()
{
    object balrog;
    ::reset();
    seteuid( getuid());
    if (present("balrog", this_object())) return ;
    balrog=clone_object(MONST+"/balrog.c");
    balrog->move(this_object());
}
