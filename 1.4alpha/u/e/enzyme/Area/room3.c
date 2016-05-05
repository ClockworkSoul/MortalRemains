inherit "inherit/room";
#include "/players/zanzibar/include/area.h"
object ghoul1, ghoul2;

reset (arg) {
  if(!ghoul1){
    ghoul1 = clone_object(PATH+"mobs/ghoul.c");
    move_object(ghoul1, this_object());
  }
  if(!ghoul2){
    ghoul2 = clone_object(PATH+"mobs/ghoul.c");
    move_object(ghoul2, this_object());
  }
  if(!arg) {
        set_short("A dark room in the mausoleum");
        set_long (
" You have entered an old ceremonial chamber used to perform dark rituals.\n"+
" There is a strange stone altar here with a pentagram etched into each side.\n"
+
" The stench of death and decay is unbelievably stronger here somehow.\n");
        set_items (({
                "chamber","Almost square, rounded at the corners.",
                "corners#corner","There are no corners here, as they are rounded
 off.",
                "stonework#unknown stonework","Almost flawless to the point of n
ear perfection.",
                "strange stone","You have never seen stone like this before.",
                "stone","This is strange stone, unlike anything you have ever se
en.",
                "stench#stench of death","A strong, foul smell.",
                "side#sides","There are carved pentagrams here.",
                "symbol#symbols","This appears to be a pentagram.",
                "pagan symbol#pagan symbols","They look like pentagrams.",
                "altar","Solid and made of some unknown stonework.",
                "strange altar","This altar seems to have symbols on it.",
                "stone altar","The altar is made from strange stone.",
                "ceremonial chamber","This chamber appears to be used to perform
 some kind of ceremony.",
                "magic#arcane magic","This magic is beyond your comprehension.",
                "odor","There is a foul smell here.",
		"monstrosities", "There seem to be ghoulish shapes moving about here",
                "pentagram#pentagrams","An old pagan symbol of arcane magic.",
                "shape#shapes","The wandering monstrosities that are about to at
tack!\n",
                }));
        add_property ("indoors");
        set_smell (
" This room smells foul!\n");
        set_light (5);
        set_exits (({
                PATH+"room2.c","south",
                PATH+"room4.c","east",
        }));
  }
}
