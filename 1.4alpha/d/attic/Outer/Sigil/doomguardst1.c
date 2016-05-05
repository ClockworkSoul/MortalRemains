#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    set("long", @ENDLONG
You stand on Doomguard Walk, where only the damned dare lay their feet.
The Temple of the Abyss is to the west.
ENDLONG
    );
    set("short", "Doomguard Walk, Lady's Ward.") ;
    set ("exits", ([
      "south" : SIGIL+"mainst19.c",
      "west" : "/d/class/priest/stormlord/rooms/priest_guild.c" ]));
    set("light", 1);
}
