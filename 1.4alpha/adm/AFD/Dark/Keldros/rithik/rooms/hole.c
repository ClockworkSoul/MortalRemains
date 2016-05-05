#include "../defs.h"

inherit ROOM;   
int ring;
void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The beginning of a cobblestone street.");
  
set("long", @ENDLONG
It appears the Zathril comes to a stop here.  The trees are much too thick for 
travel to the west.  A large mound of dirt has accumulated here, standing at 
nearly five feet tall. The mound is  made of a thick grey mud that has nearly 
hardened completely.
ENDLONG
);

  set("item_desc", ([ 
      "mound" : "There looks to be a hole large enough to fit through, perhaps
you should go down and see where it leads.\n",
      "trees" : "Thick cedar and pine trees surround zathril road.\n",
      "mud" : "This mud appears to be constructed by humanoid hands.\n",
      ]) );
  set("smell", ([
    "default" : "A feint sweet smell lurks in the air.\n",
    "hole" : "A pungent odor is being emitted from down there.\n",
    "mound" : "It smells of dirt freshly made wet.\n",   
  ]) );
  set("exits", ([
     "east" : ROOMS(zathril3),
     "down" : "/d/Dark/Keldros/antfarm/rooms/entrance.c",
     ]) );
  
  set("exit_suppress", ({ "down" }) );
set ("exit_msg", ([ "down" : TPN+" crawls out of the hole.\n"]) );
::create();  
}


