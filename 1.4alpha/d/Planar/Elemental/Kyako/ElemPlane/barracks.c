/*
// A blank room, take it to make new rooms.
*/

#include <mudlib.h>
#include "plane.h"
inherit ROOM;

void create()
{
  ::create();
   seteuid(getuid());
   set( "light", 1 );
   set ("objects", ([ "pirate" : PLANE+"monsters/pirate",
     "pirate2" : PLANE+"monsters/pirate",
   ]) );
   set("short", "The pirate's barracks.");
   set( "long", @EndText
You are in the pirate's barracks on the ship.
Like the storage room, everything is somewhat damp.
You see uncomfortable bedding strewn about the room,
with some drawers for the pirate's dirty clothing.
There is a real bed and a sink in one corner,
presumably for the First Mate.
EndText
  );
  set( "exits", ([
    "east" : PLANE+"storage.c",
  ]) );
  set( "item_desc", ([
  ]) );
   reset();
}

void init() {
  add_action("search", "search");
}

int search(string str) {
  string place;
  switch(str){
    case "drawers" : place = "nope";break;
    case "sink" : place = "nope";break;
    case "clothing" : place = "nope";break;
    case "bedding" : place = "yup";break;
    default : place = "what";
  }
  if (place == "nope") {
    write("You don't find anything in the "+str+".\n");
    return 1;
  }
  if (place == "yup") {
    int i;
    i = TP -> query("kyflag1");
    if (i == 0) {
      object ruby;
      write("As you search through the bedding, you find a ruby!\n");
      ruby = clone_object(PLANE+"obj/ruby.c");
      ruby -> move(TP);
      TP -> set("kyflag1", 1);
      return 1;
    } else {
      write("You don't find anything in the "+str+".\n");
      return 1;
    }
    return 1;
  }
  if (place == "what") {
    write("Search what?\n");
    return 1;
  }
  return 1;
}
