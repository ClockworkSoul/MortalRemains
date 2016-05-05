#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create ()

{
 ::create();
seteuid(getuid());
set( "light", 1 );
set("short", "Sciv anvenue");
set("exits", ([
       "north" : AROOM+"street31.c",
       "west" : AROOM+"mail.c",
       "east" : AROOM+"street33.c",
]) );
}
