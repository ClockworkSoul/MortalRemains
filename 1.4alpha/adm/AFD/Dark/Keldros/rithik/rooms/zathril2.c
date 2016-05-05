#include "../defs.h"

inherit ROOM;   
int ring;
void create() {
  seteuid(getuid());   
 set_outside("zone","2");
  set("author", "Waxer");  
  set("light", 1);
  set("short", "Zathril continues.");
set("long", @ENDLONG
Zathril continues continues to the east and west.  The trees become 
warped and twisted in the darkness.  Vision to the east and west is
very difficult.  You can see what appears to be chimney smoke
to the northwest.
ENDLONG
);

  set("item_desc", ([ 
      "trees" : "You are sure these trees are normal cedarwood trees, not
sentient beings wishing to devour you if you turn your back, really, you are
sure of that.\n",
      "sky" : "There is no godly reason why the sky would be so red.\n",
      "smoke" : "The smoke rises in a tubular fashion, suggesting that has been emanated
from a chimney or other orrifice.\n",
 ]) );
  set("exits", ([
     "east" : "/d/Dark/Prime/rooms/d_road3.c",
     "west" : ROOMS(zathril3), 
     ]) );
  ::create();  
}
