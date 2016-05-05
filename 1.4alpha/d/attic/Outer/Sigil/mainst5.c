#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand on Main Street in Sigil, the main road in the town.
You are currently in the Guildhall Ward, home to the great guilds
of all the professionals in the town.
ENDLONG
 );
  set("short", "Main Street, Guildhall Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"gymnasium.c",
         "south" : "/d/class/wizard/general/rooms/m_lobby.c",
	"east" : SIGIL+"mainst6.c",
	"west" : SIGIL+"mainst4.c" ]));
}
