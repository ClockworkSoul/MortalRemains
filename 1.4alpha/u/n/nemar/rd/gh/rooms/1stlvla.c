/*
** File /u/n/nemar/rd/city/rooms/1stlvla.c
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
  set( "short", "Shadoweir Guild" );
  set( "long", @EndText
You have entered the first level of the guild.  You see many pictures along the
walls showing various people.  You see a spiral stairase leading up and down.
EndText
  );
  set( "exits", ([
    "up" : "/u/n/nemar/rd/gh/rooms/2ndlvla.c",
    "down" : "/u/n/nemar/rd/gh/rooms/entrance.c",
  ]) );
  set( "item_desc", ([
    "tree" : "The inside walls is perfectly smooth.\n",
    "oak" : "The inside walls is perfectly smooth.\n",
    "ground" : "The floor is perfectly smooth with no apparent scratches.\n",
    "floor" : "The floor is perfectly smooth with no apparent scratches.\n",
    "wall" : "The walls are so smooth they almost shine.\n",
  ]) );
}

