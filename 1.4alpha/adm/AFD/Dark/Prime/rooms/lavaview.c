#include "d_roadx.c"

inherit ROOM;

void create() {
  seteuid(getuid());
  ::create();
  describe();
  set ("short", "On an Unnamed Road beside a volcano");
  set("long", @EndText
Here the forest around you is quite dense.  The sky to the north
of you is dominated by the hulking mass of a volcano.  The crimson
lava flows like blood from a deep wound at the moutain's peak.
EndText
  );
  set ("exits", ([
    "northeast" : D_PRIMER+"/d_road7.c",
    "west" : D_PRIMER+"/mt_road1.c",
  ]));
}
