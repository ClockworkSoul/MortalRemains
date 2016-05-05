#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "Under towering pines");
  set("long", wrap(
"You are dwarfed by the giant pines that grow in this area. You crane your "+
"neck but are unable to see the tops of the trees. Is it rather dark here, in "+
"the shade of the mammoth pines. Birds occassionally fly by, but otherwise it "+
"is completely still.\n",
     ) );
  set("item_desc", ([
    "giant pines" : "The pines are large and magestic.\n",
    "giant pine" : "This pine is large and magestic.\n",
    "pines" : "The pines are large and magestic.\n",
    "pine" : "This pine is large and magestic.\n",
    "trees" : "The trees stand tall and still.\n",
    "tree" : "This tree stands tall and still.\n",
    "tops" : "You cannot see the tops of the trees.\n",
    "shade" : "It is cool and quiet in the shade.\n",
    "birds" : "The birds flit from tree to tree.\n",
    "bird" : "A small bird flies overhead.\n",
    ]) );
  set("smell", "The strong scent of pine tickles your nose.\n");
  set("listen", "You hear birds chirping nearby.\n");
  set("exits", ([
    "north" : P_ROOM+"orchard1.c",
    "west" : P_ROOM+"path7.c",
    ]) );
  set("objects", ([
    "woodpecker" : P_MON+"woodpecker.c",
    "owl" : P_MON+"owl.c",
    ]) );
  reset();
  }
