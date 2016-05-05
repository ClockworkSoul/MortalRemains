
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"
object zombie1, zombie2, zombie3;

void init(){
  ::init();
  add_action("enter_it", "enter");
}
status enter_it(string str) {
  if(!str) return 0;
  if(str != "coffin") return 0;
  write("You enter the coffin!\n");
  say((this_player()->query_name()+" enters the coffin.\n"), this_player());
  move_object(this_player(), PATH+"room6.c");
  this_player()->look();
  return 1;
}
reset(arg) {
  if(!zombie1){
    zombie1 = clone_object(PATH+"mobs/zombie.c");
    move_object(zombie1, this_object());
  }
  if(!zombie2){
    zombie2 = clone_object(PATH+"mobs/zombie.c");
    move_object(zombie2, this_object());
  }
  if(!zombie3){
    zombie3 = clone_object(PATH+"mobs/zombie.c");
    move_object(zombie3, this_object());
  }
  if(!arg){
        set_short("A dark room on the left side of the mausoleum.");
        set_long (
" This room must have been visited recently. There are footprints everywhere\n"+
" in the layer of dust that covers everything. There seems to be a slight\n"+
" breath of air coming from one of the coffins lining the walls here.\n");
        set_items (({
                "room","It is hard to determine the exact specs, but just look."
,
                "footprint#footprints","It seems that something has been moving
about lately.",
                "dust","Old things are usually dusty and this room is obviously
old.",
                "layer of dust","This room is dusty.",
                "air#breath of air","You trace the air and find it is coming fro
m one of the coffins.",
                "coffins","Ornately carved resting places for the dead, or rathe
r, UN-dead.",
                "coffin","It seems you could enter this coffin, but where does i
t lead?",
                "wall#walls","There seems to be an eerie glow coming from these
coffined lined walls.",
                "form#forms","The obviously unhappy nasties that are shuffling t
oward you.",
                "glow#eerie glow","The eerie greenish glow of the undead.",
                "something","There might be something here, try looking.",
                "everything","You can't see everything. Be more specific.",
		"resting places","These appear to be coffins.",
                "dead","Coffins have dead people in them.",
                "un-dead#undead","You have seen some of them in previous rooms.",
		"unhappy nasties","Try looking and see if they are here.",
        }));
        add_property ("indoors");
        set_light (5);
        set_exits (({
                PATH+"room3.c","west",
                PATH+"room5.c","east",
        }));
  }
}
