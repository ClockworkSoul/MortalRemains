#include "d_roadx.c"

inherit ROOM;

void create() {
  seteuid(getuid());
  ::create();
  describe();
  set ("short", "On An Unnamed Road");
  set("long", @EndText
You are standing on an often travelled though apparently unnamed
road. Around you the trees of the forest seem to almost leer at you
from the unnatural darkness. The only light here is the hellish red
glow of the sky
EndText
  );
  set ("exits", ([
    "north" : D_PRIMER+"/d_road3.c",
    "south" : D_PRIMER+"/d_road5.c",
  ]));
}
