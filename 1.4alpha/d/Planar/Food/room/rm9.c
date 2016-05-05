#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../food.h"

void create()
{
    ::create();
    seteuid( getuid() );
   set("objects", ([ "dope1" : MON+"foodman.c",
                     "dope2" : MON+"fooddude.c",
      ]) );
   reset();
    set( "light", 1 );
   set("short", "Inside a house");
    set( "long", @EndText
You are in one of the many houses in Foodsburg. It looks to be
made of gingerbread, you prolly don't want to eat it though.
EndText
    );
    set( "exits", ([
   "west" : RM+"rm6.c",
    ]) );
    set("item_desc", ([
   "gingerbread" : "Ick, you definatally do not want to eat it.\n",
   "house" : "You are in it.\n",
   "floor" : "Right there under you feet, what did you expect?\n",
    ]) );
}
