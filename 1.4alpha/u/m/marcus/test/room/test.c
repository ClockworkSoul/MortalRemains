inherit "/std/room";

void create(){
  ::create();
  seteuid(getuid());
  set("short", "Marcus' First Room in TMI2");
  set("long", "This is Marcus' first room...\n");
  set("light", 1);
  set("exits", ([
    "workroom": "/u/m/marcus/workroom.c",
  ]));
}
