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
    set( "short", "Haven of Blades" );
    set( "long", @EndText
As you enter this room, blinding flashes of light glint off of hundreds
and hundreds of sharpened and proudly displayed blades.  They range from
cunningly crafted works made to look like other items such as staves,
mirrors and animal carvings that hide a deadly nature. It seems as though
you might find something of use here.
EndText
    );
    set("item_desc",([
      "blades" : "lots of blades are here, as you scan the room, you
notice one that looks like something you could take.\n",

    ]) );

}

void init() {
 add_action("take", "take");
}
 
 int take (string str) {
  object amulet ;

if (str=="blade") {
if (amulet_here) {
   amulet=clone_object("/d/Prime/Magehouse/items/talisman2.c");
   amulet->move(TP);
   write("As you grab the blade it transforms into a strange talisman.\n");
   say(TPN+" grabs a blade.\n");
   amulet_here=0;
   return 1; 
}   
return 0;
}
}  
