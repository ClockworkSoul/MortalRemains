
inherit ROOM;
#include "area.h"

static int found;

void create() {
  ::create();
  seteuid( getuid() );
  set ("author", "enzyme");
    found = 0;
    set("short", "A cold dark room in the mausoleum\n");
    set("long", (
" You have entered a cold, musty room in this place of death. The smell of\n"+
" decay is almost overpowering. There are several coffins lining the walls\n"+
" here; one of them looks a bit odd. Some of the lids have been broken\n"+
" and lay crumbling on the floor.\n"));
    set("items", ([
        "room" : "This room you are looking at now.\n",
        "cold room" : "This room seems cold.",
        "damp room" : "This room feels damp.\n",
        "place" : "This place you are in now.",
        "place of death" : "This is a place where dead people are, hence 'place of death'.\n",
        "musty room" : "This room smells musty.\n",
        "smell#smell of death" : "How can you see a smell?\n",
        "coffins" : "Coffins with corpses in them. One corpse looks odd.\n",
        "corpses" : "Dead bodies that are laid to rest here.\n",
        "people#dead people#bodies" : "These are corpses that are laid to rest here. One of them looks different.\n",
        "bodies#dead bodies" : "Corpses laid to rest. One looks diferent.\n",
        "stone coffins" : "They contain corpses, and one looks less dead than the rest.\n",
        "coffin" : "You can't see anything from here try looking at something else.\n",
        "walls#wall" : "Cracked marble, very old.\n",
        "marble#cracked marble" : "The whole place is made of marble, so it appears.\n",
        "lid#lids" : "Tops of the coffins, some of which are broken.\n",
        "broken lids#broken lid" : "Some of the lids are broken and lay on the floor.\n",
        "floor" : "Cold, hard and made of marble.\n",
        ]));
  set("smell", (
" This room smells musty and of decay.\n"));
    set("light", 5);
    set("exits" , ([
        PATH+"room1.c","west",
        PATH+"room3.c","north",
        PATH+"room7.c","south",
        ]);
}
void init() {
  ::init();
  add_action("lookit", "l");
  add_action("lookit", "look");
  add_action("exait", "exa");
  add_action("exait", "examine");
  add_action("exait", "search");
}

status lookit(string str) {
  if(!str) return 0;
  if(str != "corpse" && str != "at corpse") return 0;
  write ("The corpse seems almost alive. Maybe you should examine it further\n");
  return 1;
}

status exait(string str) {
  object monster;
  if(!str) return 0;
  if(str != "corpse" && str != "at corpse") return 0;
  if(found) {
    write("There is no corpse here.\n");
    return 1;
  }
  write("The corpse moves to attack you!\n");
  monster = clone_object(PATH + "mon/corpse");
  move_object(monster, this_object());
  "/daemons/combat_d.c"->hit_player(monster, this_player(), 0, 0);
  write("The corpse attacks!\n");
  found = 1;
  return 1;
}
