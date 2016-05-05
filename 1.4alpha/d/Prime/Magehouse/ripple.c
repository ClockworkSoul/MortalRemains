#include <teleport.h>
#include <mudlib.h> 

inherit ROOM;

int amulet_here;

void create()
{
    ::create();
    seteuid( getuid() );
    amulet_here = 1;  
    set("no_teleport", NO_IN_OR_OUT);
    set( "light", 1 );
    set("author","blood");
    set( "short", "Ripple of the void" );
    set( "long", @EndText
Utter blackness accompanies yourself and no other in this room.  The only
appreciable items are the four cubes floating around in the air here.
They move in a circular pattern at the four corners of the room.
EndText
    );
    set("item_desc",([
      "cubes" : "There are four cubes, which did you want to look at?\n"+
      "Cube 1, 2, 3 or 4?\n",
      "cube 1" : "a cube that appears to be made of some strange flexable
energy.\n",
      "cube 2" : "a cube that appears to be made of some strange flexable
energy.\n",
      "cube 3" : "this cube is similar to the others save for a glittering
object in its center. Perhaps you could open it.\n",
      "cube 4" : "a cube that appears to be made of some strange flexable
energy.\n",
    
    ]) );

}

void init() {
 add_action("open", "open");
}               
                
 int open (string str) {
  object amulet ;
      
if (str=="cube 3") {
if (amulet_here) {
amulet=clone_object("/d/Prime/Magehouse/items/talisman.c");
   amulet->move(TP);
   write("You find an amulet in the cube and take it quickly!\n");
   say(TPN+" opens a cube and finds something within.\n");
   amulet_here=0;
   return 1;
}
return 0;
}
}
