/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include "plane.h"
#include <mudlib.h>

inherit ROOM;

void create()
{
object ob1, ob2;
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
  set("objects" ,  (["note" : "note"]));
  set( "light", 1 );
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set("short", "Entrance hallway.");
  set( "long", @EndText
There are four windows in this room.
To the east, there is sky extending forever.
To the south, there is a raging inferno.
To the west, there is an endless ocean.
To the north, there is a wild forest.
There is a pentagram inscribed on the floor. It is glowing softly.
EndText
  );
  set( "exits", ([
    "north" : PLANE+"forest.c",
    "south" : PLANE+"fire.c",
    "east"  : PLANE+"sky.c",
    "west"  : PLANE+"water.c",
  ]) );
}
void init (){
   add_action("bamph", "say");
  }

int bamph(string str){
object ob1;
   if(str == "Pythagoras"){
     write("The pentagram glows slightly, then fades.\n");
  return 1;
 }
   if(str == "sigil"){
     write("The pentagram begins to glow brightly...\n");
     write("In a flash of light, you find yourself back in sigil!\n");
     TP->move("/d/Outer/Sigil/mainst1.c");
     write("The pentagram fades.\n");
  return 1;
 }
 return 0;
}
