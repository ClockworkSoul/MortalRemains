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
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "Sophia's bedchamber" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
This comforting room is home to a warm bed and cosy looking fireplace.
An ironwood spiral staircase leads up from here.
EndText );
    set( "exits", ([
      "down" : "/u/s/sophia/workroom.c",
      "panel" : "/u/s/sophia/bathroom.c",
      "up" : "/u/s/sophia/library.c",
    ]) );
    set("item_desc", ([
      "bed" : "A sleigh bed made of ironwood obviously carved by a talented
hand long ago. Even this wood is worn where hands have traced across it.
The mattress is soft and you sink into it when you lay down. A small
feather peeks out of a small hole where one of the seams is slightly
worn.  A shallow bowl sits on a small table beside the bed.\n",
"feather" : "a small irridescent blue feather\n",
"bowl" : "This is a beaten copper bowl, darkened with age and with
elven symbols inscribed around the inside of the rim. It is 
filled with a dark watery liquid that although it beckons you to
touch it but you fear to disturb,\n",
"flooring" : "The floor is made of rich warm wood inlaid to match the
fireplace panels. It seem to have small scratches in it near the
fireplace edge.\n",
"fireplace" : "No fire burns here yet but kindling is stacked neatly
on the grate ready to be lit if anyone feels the need for warmth
or romance. The fireplace itself is old stone with beautifully carved 
mantle and inlaid panels that match the flooring.\n",
]) );
}
void init() {
add_action("disturb", "disturb");
add_action("touch", "touch");
}
int disturb(string str) {
if (str=="liquid") {
say(TPN+" seems to see something you don't\n");
write(
"As a slight shock runs up your "+
"hand and arm a picture forms and you realize that this is a "+
"treasures and rare elven image keeper. You wonder who it is whose "+
"image is kept here.\n");
return 1;
}
int touch(string str){
if (!str){
write("Search what?\n");
return 1;
}
if (str == "panel") {
write("As you touch you discover a secret exit.\n");
say("TPN+" discovers an exit.\n");
set ("exits", ([ "panel" : "/u/s/sophia/bathroom.c" ]) );
return 1;
}
return 1;
}
}
