inherit "inherit/room";
#include "/players/zanzibar/include/area.h"
object slime;

reset (arg) {
if(!slime){
    slime = clone_object(PATH+"mobs/slime.c");
    move_object(slime, this_object());
  }

  if(!arg){
    set_short("An earthen hallway under the mausoleum.");
    set_long (
" The air is stifling as you travel further under the earth. You are now in a\n"
+
" sloping passage under the mausoleum. The passage is smooth, a truly skillful\n
"+
" being must have made this. The marble has ceaced here though and now earthen\n
"+
" walls with wooden support beams to keep from being buried alive.\n");
set_items (({
         "air","The air is still and feels heavy.",
        "earth#earthen","You are underground and the walls are made of dirt.",
         "passage#sloping passage","This passage slopes slightly downward.",
         "mausoleum","This is where you came from.",
         "being#skillful being","The being who made this passage really knew his
 stuff.",
         "marble","The marble ended when you left the mausoleum.",
         "wall#walls#earthen wall#earthen walls","The walls are made of earth as
 you are underground.",
         "dirt","When you dig underground you usually find dirt like this.",
         "beam#beams#support beam#support beams","Stout wooden beams that help t
o keep the dirt from caving in on you.",
        "wooden beams#wooden beam"," Stout beams made of wood that help keep the
 walls from caving in.",
    }));
  add_property ("indoors");
  set_light(1);
  set_smell(" The air smells heavy and a bit smokey.\n");
  set_exits (({
         PATH+"room9.c","southwest",
         PATH+"room6.c","north",
}));
  }
}
