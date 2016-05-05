#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Good Bye and have a good day!" );
    set( "long", @EndText
BBBBBB      YYYY    YYYY    EEEEEE    !!!!!
BB  BBB      YY      YY     EE        !!!!!
BB   BBB      YY    YY      EE        !!!!!
BB  BBB        YY  YY       EE         !!!
BBBBBB          YYYY        EEEE       !!!
BB  BBB          YY         EE          !
BB   BBB         YY         EE          
BB  BBB          YY         EE         !!!         
BBBBBB          YYYY        EEEEEE     !!!
------------------------------------------
------------------------------------------
Have a good day and i hope you enjoyed your visit to Tantallon!
EndText
    );
    set( "exits", ([
"south"  :  "/u/a/abyss/town/t1.c.c",
     "north"  :  "/u/a/abyss/town/nexit.c",
    ]) );
}
