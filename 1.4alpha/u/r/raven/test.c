/*
** File: /u/r/raven/entrance.c
** Author: Raven
** Last Updated:  4/11/2000
**
** Main entrance to first area
*/

#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
   ::create();
   seteuid( getuid() );
   set( "light", 1 );
   set ("author", "raven");
   set("short", "Forest Entrance");
   set("long", @EndText
You are standing on the edge of a great forest.  To the North is a dense 
forest with, a path leading into it, to the South is a field, and off in
the distance to the East is what appears to be a town. 
EndText
);
   set("exits", ([
      "north" : "/u/r/raven/workroom.c",
      "south" : "/u/r/raven/workroom.c"
   ]));
   set("item_desc", ([
      "forest" : "A great many trees.  Many appear to be very old.\n",
      "trees" : "Trees that appear to be as old as the world itself.\n",
      "path" : "A path leading into the dense trees.\n",
      "field" : "A field of wild grass.\n",
      "grass" : "It is grass, what did you expect?.\n",
      "town" : "You cannot see the town from here.\n",
      "city" : "You cannot see the town from here.\n",
   ]) );
}