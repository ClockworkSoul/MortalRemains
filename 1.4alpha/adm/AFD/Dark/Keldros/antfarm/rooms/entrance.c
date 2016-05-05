
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "Entrance to a very strange cave.");
  
set("long", @ENDLONG
You have entered a cave cut in granite rock, lines of copper run 
through the walls, reflecting some of the light coming from the hole above.  
You can't help but notice a sweet scent in the air; the drive to find the 
source encumbers your thoughts with the prayer that you can irradicate it.  
You notice that this cave extends to the north and curves to the east.
ENDLONG
   );

  set("item_desc", ([
  "walls" : "The walls appear to have been crafted with rough instruments, the copper running through the rock is not uncommon for this depth underground.\n",
    "cave" : "This cave appears to have been built by humanoid creatures.\n",
    "copper" : "This copper could be quite valuable, if mined properly...\n",
    "hole" : "It appears as though you could easily leave the cave through the hole to the fresh air outside.\n",
   ]) );
   set("search_desc", ([
     "wall" : "You find a wall.\n",

   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    "wall"  : "Your body convulses with an enormous sneeze as you inhale the dust off the wall.\n",
    "air"  : "It reminds you of something you can't quite place, a sweet, decaying odor.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear a light clicking sounds.\n",
    "sounds" : "It sounds as if someone is tapping two sticks together.\n",
    
    
  ]) );
  set("objects", ([
    MON(workant) : 1,
      
]) );

  set("exits", ([
    
    "east" : ROOMS(branch),
    "up" :  "/d/Dark/Keldros/rithik/rooms/hole.c",
    "north" : ROOMS(further.c),
    
  ]) );
set ("exit_msg", ([ "up" : "$N crawls out of the hole.\n"]) );
  ::create();  
}
