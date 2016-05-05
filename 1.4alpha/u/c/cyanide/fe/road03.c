#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("short", "A small junkyard");
    set("long", @Endtext
Piles of scraps are heaped upon one another in this junkyard.  A few
smashed vehicles lay on top of one another in a twisted stack.  Torn
tires, broken glass, and rusted steel drums are also everywhere.  It
appears that the trash has been categorized by some means.  Two huge
mountains of garbage is to the east and west.  A small building is to
the north.  A strange symbol is above the door.
Endtext
    );
    set("item_desc", ([
      "vehicles" : "They are probably used for spare parts in machines.\n",
      "steel drums" : "Empty oil drums which were discarded a long time ago.\n",
      "tires" : "Many of them are torn in several places, making them unusable.\n",
      "glass" : "Pieces of shattered windshields and mirrors.  They look sharp.\n",
      "symbol" : "   |~| |~|\n"+
      "   ._ ~ _.\n"+
      "     | |\n"+
      "     | |\n"+
      "     | |\n"+
      "   .~ _ ~.\n"+
      "   |_| |_|\n",
    ]) );
    set("exits", ([
      "north" : ROOMS+ "repair-shop",
      "east"  : ROOMS+ "junkyard02",
      "south" : ROOMS+ "road06",
      "west"  : ROOMS+ "junkyard01",
    ]) );
    create_door("north", "south", "A cast iron door with no markings", "open");
    reset();
}

