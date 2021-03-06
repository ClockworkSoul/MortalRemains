
#include "../defs.h"
inherit ROOM;
int found;
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In an Animal's cage.");
  
set("long", @ENDLONG
The smell of decaying oats and barley wafts through the air here.  You
see a long trough filled with the origin of this malicious odor.  A thin
layer of hay rests beneathe your feet.
ENDLONG
);

  set("item_desc", ([
    "hay" : "The hay is obviiously used as a bed for a very large creature.\n",
    "trough" : "This is a storage unit for feeding horses and the like.\n",
 ]) );
  set("smell", ([ "default" : "Your stomach rolls from the intense stench that
pervades the entire cage.\n",
]) );
  set("objects", ([ MON(2horse) : 1, ]) );
  set("exits", ([
   "out" : ROOMS(cage2),
]) );
  ::create();  
}
void init(){ add_action("src","search"); }
int src(string what)
{
        if(what !="hay" && what !="floor") return 0;
        if(found){
          write("You find nothing hidden in the hay.\n"); return 1; }
found = 1;
write("You find a pile of coins in the hay!\n");
TP->credit(100+random(100));
        return 1;
}