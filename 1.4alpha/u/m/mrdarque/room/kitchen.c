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

inherit PRIVATE_ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set( "short", "The Kitchen" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
The Kitchen is in disrepear. The walls a delapitated and covered in
grim. The refriderator hums loudly and makes an clank every once and a
while. In the center of this mess is a beer can covered table with four
chairs. To the left is a window and west is the living room.
EndText
  );
  set( "exits", ([
"west" : "/u/p/panzergiest/workroom.c",
  ]) );
set("item_desc",([
"window" : "You see the smog,dirt and garbage filled world below.\n",
"refridgerator" : "OLD, looks like it was around before you where born.\n",
]) );
}
