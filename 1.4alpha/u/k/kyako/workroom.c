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
#define NAME this_player()->query("cap_name")

inherit PRIVATE_ROOM;

void create()
{
object ob1, ob2;
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
  set("objects" ,  (["note" : "note"]));
  set( "light", 1 );
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
set("short","Kyako's Workroom");
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
    "start" : START,
    "void"  : VOID,
"room" : "/d/Ancients/rooms/wizrm.c",
    "area" : "/d/Inner/Kyako/ElemPlane/firstrm.c",
  ]) );
}
void init (){
   ::init();
   add_action("bamph", "say");
  }

int bamph(string str){
object ob1, ob2;
   if(str == "Pythagoras"){
     write("You say: Pythagoras\n");
     say(NAME+" says: Pythagoras\n");
     write("The pentagram glows slightly, then fades.\n");
     say("The pentagram glows slightly, then fades.\n");
  return 1;
 }
   if(str == "I call on the brotherhood to give me strength!"){
     write("You exclaim: I call on the brotherhood to give me strength!\n");
     say(NAME+" exclaims: I call on the brotherhood to give me strength!\n");
     write("The pentagram begins to glow brightly...\n");
     say("The pentagram begins to glow brightly...\n");
     write("In a flash of light, Kyako's robes and staff appear!\n");
     say("In a flash of light, Kyako's robes and staff appear!\n");
     ob1 = clone_object("/d/Inner/user/kyako/robe.c");
     ob1->move(this_object());
     ob2 = clone_object("/d/Inner/user/kyako/staff.c");
     ob2->move(this_object());
     write("The pentagram fades.\n");
     say("The pentagram fades.\n");
  return 1;
 }
 return 0;
}
