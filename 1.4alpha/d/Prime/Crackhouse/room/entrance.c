// QC passed - Cy

#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    set("author","cattt");
    set("light", 1);
    set("short", "A dimly lit entrance");
    set("long", wrap(
	"Boarded up windows can't even hide the stench coming "+
	"from within this building. The door, which is merely "+
	"a large panel of plywood, hardly closes correctly, "+ 
	"having warped from the elements a long time ago. "+
	"A light barely flickers from atop the doorframe, just "+
	"moments away from burning out it seems. "
      ) );
    set("item_desc", ([
      "windows" : "Wooden boards cover the window panes.\n",
      "window" : "Wooden boards cover the window panes.\n",
      "boards" : "The boards are covered with graffitti.\n",
      "board" : "The boards are covered with graffitti.\n",
      "door" : "Warped and covered in paint, it doesn't close.\n",
      "plywood" : "This 'door' is barely held onto the building.\n",
      "panel" : "The plywood looks to be years old.\n",
      "light" : "Hardly a welcoming committee with its dimness.\n",
      "doorframe" : "You are quite surprised it can hold the door.\n",
      "stench" : "A putrid smell eminates from the beat up building.\n",
      "building" : "A large yet rundown place.\n",
    ]) );
    set("smell", ([
      "default" : "A putrid smell eminates from the beat up building.\n",
    ]) );
    set("exits", ([
      "west" : "/d/Prime/Central/room/road0_-1.c",
      "east" : M_ROOM+"hallway.c",
    ]) );
}

