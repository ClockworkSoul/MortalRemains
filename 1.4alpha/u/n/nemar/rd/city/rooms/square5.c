/*
** File: /u/n/nemar/rd/city/rooms/square5.c
** Author: Lord Nemar of the Shadoweirs
*/

#include <config.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "author", "nemar" );
  set( "short", "Mapleleaf Square" );
  set( "long", @EndText
You are on the eastern edge of the square that surrounds the giant Oak tree.
EndText
  );
  set( "exits", ([
    "north" : "/u/n/nemar/rd/city/rooms/square3.c",
    "east" : "/u/n/nemar/rd/city/rooms/maplest1e.c",
    "south" : "/u/n/nemar/rd/city/rooms/square8.c",
  ]) );
  set( "item_desc", ([
    "tree" : "It's GIGANTIC.  The limbs spread out covering the entire square.\n",
    "oak" : "It's GIGANTIC.  The limbs spread out covering the entire square.\n",
    "ground" : "The cobblestone street is in stark contrast to all the technology the world now has.\n",
    "street" : "The cobblestone street is in stark contrast to all the technology the world now has.\n",
    "cobblestone" : "Wonderfully crafted with care yet looking very week.  They must replace many of these a day.\n",
  ]) );
}
