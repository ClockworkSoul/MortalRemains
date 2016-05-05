/*
** File /u/n/nemar/rd/city/rooms/square1.c
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
You have reached the northwest corner of the square that
surrounds the giant Oak tree.
EndText
  );
  set( "exits", ([
    "east" : "/u/n/nemar/rd/city/rooms/square2.c",
    "south" : "/u/n/nemar/rd/city/rooms/square4.c",
  ]) );
  set( "item_desc", ([
    "tree" : "It's GIGANTIC.  The limbs spread out covering the entire square.\n",
    "oak" : "It's GIGANTIC.  The limbs spread out covering the entire square.\n",
    "ground" : "The cobblestone street is in stark contrast to all the technology the world has now.\n",
    "street" : "The cobblestone street is in stark contrast to all the technology the world has now.\n",
    "cobblestone" : "Wonderfully crafted with care looking very week.  They must replace many of these a day.\n",
  ]) );
}
