
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"
object zombie1, zombie2;

reset (arg) {

  if(!zombie1){
    zombie1 = clone_object(PATH+"mobs/zombie.c");
    move_object(zombie1, this_object());
  }
  if(!zombie2){
    zombie2 = clone_object(PATH+"mobs/zombie.c");
    move_object(zombie2, this_object());
  }
  if(!arg){
        set_short("A burial chamber.");
        set_long(
" You have entered a large, cavernous room. This was once a very beautiful \n"+
" place.  There are cathedral ceilings with several marble columns\n"+
" that lead toward a raised dais at the back of the room.\n");
        set_items (({
                "room","The room you are standing in, just look.",
                "large room","This room is bigger than the others you've been in
.",
                "cavernous room","This room is big.",
                "place","The room you are in now.",
                "crack#cracks","Hairline cracks in the marble work. Probably due
 to the age of the place.",
                "dais","A raised section of the floor with three steps up.",
                "raised dais","A section of the floor with three steps leading t
o it.",
                "floor","The floor is hard and flat, except for the steps leadin
g to the dais.",
                "steps","Three steps that lead to the dais.",
                "three steps","The steps that lead to the dais.",
                "column#columns","Six columns lining the hallway, three on the l
eft and three on the right.",
                "left column#left columns","Tall marble columns extending from t
he floor to the ceiling.",
                "right column#right columns","Tall marble columns extending from
 the floor to the ceiling.",
                "ceiling#ceilings","A good 20 to 30 feet above your head. You ca
n't see too clearly.",
"cathedral ceiling#cathedral ceilings","This ceiling is high abo
ve you.",
                "marble","The marble is cracked with age, as you may recall, alm
ost everything here is\n"+
" made from it.\n",
                "marble column#marble columns","The columns are still in very go
od condition.",
                "back#back of room","The part of the room opposite from where yo
u came in.",
        }));
        add_property ("indoors");
        set_light (5);
        set_exits (({
                PATH+"room4.c","west",
        }));
  }
}
