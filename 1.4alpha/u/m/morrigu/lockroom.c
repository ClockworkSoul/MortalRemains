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

#define OWNER getuid(this_object())

inherit ROOM;

int locked = 1;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
My workroom - nuff said.
EndText
  );
  set( "exits", ([
    "experiment" : "/u/c/cyanide/experiments/workroom.c",
    "start" : START,
    "void"  : VOID,
  ]) );
}

void init() {
  add_action("lock", "lock");
}

int lock (string str) {
  if (getuid(this_player()) != OWNER) return 0;
  
  if (!str ) {
    write ("Shields: "+locked+".\n");
    return 1;
  }

  switch(str) {
    case "on" : locked = 1; return 1; break;
    case "off" : locked = 0; return 1; break;
    default : write ("Usage: lock [on|off]\n"); return 1; break;
  }
}

void receive_object (object ob) {
  if (locked) {
    if (living(ob))
      if (getuid(ob) != OWNER) {
        tell_object(ob,
        "You hit an invisible barrier, and are stunned.\n");
        return 0;
      }
  }
  return 1;
}
