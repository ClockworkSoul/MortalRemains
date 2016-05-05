
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"

void reset (status arg) {
  ::reset(arg);
  if(!arg){
  set_short("A Room on the second level of the mausoleum.");
  set_long (
" You have entered a room on the second level of the mausoleum. The walls\n"+
" are still made of earth and the wooden support beams are still evident.\n"+
" Though being underground should be cooler than above ground, the air here has\
n"+
" a definate unholy chill. There seems to be a light just ahead.\n");
  set_items (({
        "room","The room where you now stand is all around you.",
        "mausoleum#second level","The physical structure is now well above you a
s you have traveled underground.",
        "structure#physical structure","The mausoleum.",
        "structure above","The mausoleum.",
"wall#walls","Packed dirt walls.",
        "packed dirt walls#dirt walls","This room is actually dug out from the g
round under the mausoleum.",
        "dirt wall#packed dirt wall","This isn't actually a 'wall' at all but me
arly the effect of digging out this\n"+
" room from under the mausoleum.",
        "earth","Being underground usually meand digging in the dirt, hence the
dirt walls.",
        "dirt#packed dirt","Dirt, as in the ground.",
        "ground","You know the earth you walk on. Don't be silly.",
        "wooden beams#beams#support beams#wooden support beams","Thick wooden be
ams used to keep the general shape of the room, as well as\n"+
" keeping the structure above from caving in on you.",
        "thick beam#beam#thick beams#thick wooden beams#thick wooden beam","Thes
e wooden beams are roughly six to eight inches thick.",
        "air","The air has a chill to it, as if something unholy was resident he
re.",
        "something#something unholy","You seem to remember a legend of something
 evil living in the depths of the mausoleum.",
        "evil#something evil","The name slips your mind, but immages of death an
d torture come all to easily.",
        "chill#unholy chill","The air is oddly cool in here.",
        "light","The familiar light of burning torches coming from just ahead.",
        "torches#burning torches","The light seems to be coming from just ahead.
",
  }));
  set_exits (({
PATH+"room10.c","east",
        PATH+"room8.c","northeast",
  }));
  }
}
