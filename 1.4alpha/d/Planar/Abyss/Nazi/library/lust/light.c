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
#include "nazi.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set("author", "nsd");
set( "short", "Nightmare becomes a dream..." );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
set( "long",@EndText
A resplandecent light invades the room. It's so
bright, it makes you blind. You see nothing, but
you can hear a voice that will tell you what to 
do...
EndText
  );
  set( "exits", ([
  ]) );
set("item_desc", ([
]) );
set("objects", ([
"child" : NAZI_MON+"voice.c",
]) );
reset();
}

void init() {
add_action("wake_up", "wake");
}

int wake_up(string str) {
write(
"...Suddenly you open your eyes and find 
yourself somewhere else...\n");
say(TPN+" wakes up...\n");
this_player()->move_player("/d/Prime/Central/room/startroom.c"); //
say(TPN+" has waken up from a terrible nightmare...\n");
return 1;
}

