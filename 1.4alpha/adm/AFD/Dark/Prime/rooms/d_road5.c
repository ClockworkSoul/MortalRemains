#include "d_roadx.c"

inherit ROOM;

void create() {
  seteuid(getuid());
  ::create();
  describe();
  set ("short", "On an Unnamed Road, North of a Bridge");
  set("long", @EndText
You are standing just north of an ancient, crumbling stone bridge on
an often travelled, though apparently unnamed road. Around you the
trees of the forest seem to almost leer at you from the unnatural
darkness. The only light here is the hellish red glow of the sky.
EndText
  );
  set ("exits", ([
    "north" : D_PRIMER+"/d_road4.c",
    "south" : D_PRIMER+"/lavabridge.c",
  ]));
}
