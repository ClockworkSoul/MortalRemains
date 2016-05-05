#include "d_roadx.c"

inherit ROOM;

void create() {
  seteuid(getuid());
  ::create();
  describe();
  set ("short", "On An Unnamed Road");
  set("long", @EndText
You are standing just south of the gates of the Castle Ashenhold on
an often travelled though apparently unnamed road. Around you the
trees of the forest seem to almost leer at you from the unnatural
darkness. The only light here is the hellish red glow of the sky.
EndText
  );
  set ("exits", ([
     "north" : "/u/c/cyanide/workroom.c",
      "south" : D_PRIMER+"/d_road2.c",
  ]));
}
