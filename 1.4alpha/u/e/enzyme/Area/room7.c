
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"

object MOB1, MOB2;

#define PATH "/players/zanzibar/area/"
reset (arg) {
  if(!MOB1){
    MOB1 = clone_object(PATH+"mobs/skeleton.c");
    move_object(MOB1, this_object());
  }
  if(!MOB2){
    MOB2 = clone_object(PATH+"mobs/skeleton.c");
    move_object(MOB2, this_object());
  }
  if(!arg) {
        set_short("A guarded chamber.");
set_long (
" You have entered an ante-chamber set off from the main hallway. There is\n"+
" a large statue here with a dedication inscribed on its base. The rest of the\n
"+
" chamber is bare, except for scattered piles of debris. There is an aura of\n"+
" death eminating from the statue and the room itself. This is not a place\n"+
" to stop and rest!\n");
        set_items (({
                "chamber#antechamber#ante-chamber","This is the room you are in
now.",
                "hallway#main hallway","That is where you just came from.",
                "statue#large statue", "This appears to be a large human male. H
e is dressed in foreign clothing and\n"+
" has a look of disdain on his face.\n",
                "clothing#foreign clothing","Clothing from a distant land judgin
g by the looks of it.",
                "distant land#land","The clothing is foriegn, as in somewhere el
se.",
                "male#large male#human male#large human male","This statue is ca
rved in the likeness of a man.",
                "man","The statue looks like a human male.",
                "face","The face of an arrogant man.",
                "look#look of disdain","The man seems arrogant.",
                "base","There is an inscription here that you might be able to r
ead.",
"dedication","This is an inscription on the base of the statue."
,
                "inscription","There is an inscription here you might be able to
 read.",
                "aura","The statue gives off a feeling of death befitting this p
lace.",
                "room","You are in an ante-chamber off of the main hallway. Ther
e is a statue here.",
                "place","This particular room.",
                "pile#piles","Just scattered debris. Maybe someone should hire a
 maid.",
                "maid","Yes, a maid should be hired.",
                "debris","Piles of chipped marble and dust.",
                "chipped marble#cracked marble","The marble is chipped and crack
ed.",
                "piles of debris","They look like marble and dust.",
                "marble","Just about everything here is made from it.",
                "dust","Yes it is very dirty here.",
        }));
        add_property ("indoors");
        set_light (5);
        set_exits (({
                PATH+"room2.c","north",
        }));
 }
}

void init() {
  ::init();
  add_action("readme", "read");
}

status readme(string str) {
  if(!str) {
    write("Read what?\n");
    return 1;
  }
  if(str != "inscription" && str != "dedication") return 0;
  write("The dedication reads:\n\t\t\t'The Great Creator'\n\n");
  return 1;
}
