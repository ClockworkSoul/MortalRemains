#include <mudlib.h>
#include "plane.h"

inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    seteuid(geteuid());
    set("light", 1);
    set ("short", "Hallway" );
    set( "long", @EndText
You jump down the entrance to the passage.
You stand underwater, but you appear to be
in an air pocket shaped like a hallway.
It would be breathtaking, but you are worried
about the fact that you can't reach the door you entered from above.
EndText
    );
    set( "exits", ([
      "south" : PLANE+"cave2.c",
    ]) );
}

void init() {
   add_action("futile", "jump");
}

int futile(string str) {
  if (str != "up") {
    write("Jump where?\n");
    return 1;
  } else {
    write("It's too high!\n");
    write("Haha!\n");
    return 1;
  }
  return 0;
}
