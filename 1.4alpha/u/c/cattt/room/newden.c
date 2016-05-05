/*
** Cyanide's lockable room.  
*/

#include <mudlib.h>
#include <config.h>

inherit PRIVATE_ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author","cattt");
  set("short", "My Lil Den");
// Note that "c_long" is used for the long description instead of 
// "long".  You can use "long", but you will no longer get the
// status heading in the room description.

  set("c_long", @EndLong
A cozy room.  If need be, use "guest help".
EndLong
   );
  set("exits", ([
    "void" : VOID,
    "start" : START,
    "there" : "/u/c/cattt/workroom.c",
  ]) );
}

void init() {
  ::init();    //This is VERY important!
}
