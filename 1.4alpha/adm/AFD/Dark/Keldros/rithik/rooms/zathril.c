#include "../defs.h"

inherit ROOM;   
void create() {
  seteuid(getuid());   
 set_outside("zone","2");
  set("author", "Waxer");  

  set("light", 1);


  set("short", ".");
  
set("long", @ENDLONG
As you progress westward the sky begins to change form.  The sky is now
a deep red.  The trees become very dense and ominous, seemingly examining
you with every step.  You see an intersection ahead.
of you.   
ENDLONG
);

  set("item_desc", ([ 
      "trees" : "You are sure these trees are normal cedarwood trees, not
sentient beings wishing to devour you if you turn your back, really, you are
sure of that.\n",
      "sky" : "There is no godly reason why the sky would be so red.\n",
      "intersection" : "Zathril intersects with a road to the west.\n",
 ]) );
  set("exits", ([
  "west" : "/d/Dark/Prime/rooms/d_road3",
     "east" : "/u/w/waxer/workroom.c",
     ]) );
  ::create();  
}


