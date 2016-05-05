#include <mudlib.h>
#include <path.h>

inherit ROOM;
int i;

void create() {
  ::create();
  set("light", 1);
  set("short", "A concrete road");
  set("long", @Endtext
The sides of the road are stacked high with garbage.  A few pieces of
trash look interesting, but upon closer inspection, but are utterly
useless.  Small traces of a black substance is inside the cracks of
the damaged concrete.  A manhole is in the middle of the street.
Endtext
 );
  set("item_desc", ([
    "garbage" : "It consists mainly broken machines and papers.\n",
    "substance" : "It appears to be gasoline.\n",
    "concrete" : "It has been quite some times since it was repaired.\n",
    "manhole" : "It leads underground into the city's sewer system.\n",
  ]) );
  set("exits", ([
    "north" : ROOMS+"road02",
    "south" : ROOMS+"road10",
  ]) );
  i = 0;
}

void init() {
/*
  add_action("open_hole", "open");
*/
}

int open_hole(string str) {
  if(!str) return 0;
  if(str == "manhole") {
    if(i!=0) {
      write("The manhole is already open.\n");
      return 1;
    }
    write("With a little effort, you open the manhole cover.\n");
    say(TPCN+" pulls open the manhole cover.\n");
    set("exits/down", ROOMS+ "sewer01");
    i = 1;
    return 1;
  }
  return 0;
}

