#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()

{
 ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Wade");
   set("long", @ENDTEXT
this is a standard room
leave me alone i'll get to it!!!!
ENDTEXT
);
   set("exits", ([
       "north" : AROOM+"street34.c",
       "east" : AROOM+"street37.c",
]) );
}
