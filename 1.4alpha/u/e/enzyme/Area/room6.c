
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"

reset(arg) {
  if(!arg){
        set_short("A dark cramped room.");
        set_long (
" You have entered a rather cramped and utterly dark room. If it weren't for\n"+
" the dim light coming from the room above, you'd probably never get out!\n"+
" The walls, floor and ceiling of this room are made entirely of marble. Though\
n"+
" in appearance this room looks normal, something tells you to turn back now.\n"
);
        set_items (({
                "room","The small cramped place you are in now.",
                "dark room","This room has little light.",
                "ceiling","Smooth and seamless, dangerously close to your head."
,
                "cramped room","This room is not very big at all.",
                "light","A dim glow coming from the room above.",
 "dim light","A glow coming from the room above.",
                "dim glow","Light coming from the room above.",
                "wall#walls","Made of marble and lacking the signs of age.",
                "floor","Apparantly solid marble, no chips or cracks.",
                "marble floor","No chips or cracks here.",
                "chips#cracks","The marble is in very good shape here.",
                "place","Why not just look?",
                "cramped place#small place","This room is small and cramped.",
                "glow","A small amount of light.",
                "marble","It looks brand new.",
                "marble wall#marble walls", "The walls are smooth and lacking ch
ips and cracks.",
                "signs#signs of age","The usual cracks and chips are lacking her
e.",
        }));
        add_property("indoors");
        set_light(2);
        set_exits (({
                PATH+"room4.c","up",
                PATH+"room8.c","south",
}));
  }
}
