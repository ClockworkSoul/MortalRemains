/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
seteuid(getuid());
  set( "light", 1 );
set("short", "The home of Minx");
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
   set("long", @EndText
As you enter the semi circular alcove you see a large, deep, pool
set into the tiled floor. The pool is kept constantly filled from a 
waterfall trickling musicaly down the rough stone wall, where the 
water comes from and to where it eventualy goes is not apparent. 
Testing the water in the pool you find that it is very warm, the 
perfect soaking temperture. There is a stack of fluffy white towels
on the floor beside the pool. The air is sented, thick and sweet, of 
tropical blossoms. Live plants are spaced about the room and on either
side of the waterfall are floor to ceiling windows looking down upon a
beautiful valley.
you may "breathe" deeply if you wish
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
    "sanctuary" : "/u/m/minx/workroom.c",
  ]) );
}

void init(){
add_action("breathe", "breathe");
add_action("enter", "enter");
}

int breathe(){
write ("You breathe the scented air.\n"+
"You feel invisible hands undressing you and\n"+
"brushing lightly over your skin.\n");
say (TP->query("cap_name")+" breathes the scented air.\n");
return 1;
}
int enter(string str){
if (str != "pool"){
write ("you may only enter the pool.\n");
return 1;
}
write ("You get into the soothing waters.\n");
say (TP->query("cap_name")+" gets in the pool.\n");
return 1;
}
