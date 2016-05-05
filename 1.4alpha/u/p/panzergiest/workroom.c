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
#include <pan.h>

inherit PRIVATE_ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set( "short", "PanzerGiest's Safe House" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
The walls peel around the open holes in the wall. The lights flicker
making the shadows dance. The stark conditions of the room refelect
the out side world, cold and bare. The window opens out twords the city
and possibly to find the last shred of hope for mankind.
To the west is the bed room and to the east is the kitchen.
EndText
  );
  set( "exits", ([
    "void"  : VOID,
"east" : M_ROOM+ "kitchen.c",
"west" : M_ROOM+ "bedroom.c",
  ]) );
set("item_desc",([
"holes" : "The holes have exposed wires sticking out of them.\n",
"wires" : "The wires are live; they sizzle and pop with charged electricity.\n",
"window" : "The neon sign just out side the window flickers with the name of The Puss and Boots Club.\n",
]) );
}
