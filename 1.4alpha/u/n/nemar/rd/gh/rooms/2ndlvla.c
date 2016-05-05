/*
** File /u/n/nemar/rd/city/rooms/2ndlvla.c
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
You have reached the second level of the guild.  You see a sign here, perhaps you
could look at it.  You see a spiral staircase leading up and down.
EndText
  );
  set( "exits", ([
    "up" : "/u/n/nemar/rd/gh/rooms/3rdlvla.c",
    "down" : "/u/n/nemar/rd/gh/rooms/1stlvla.c",
  ]) );
  set( "item_desc", ([
    "tree" : "The inside walls is perfectly smooth.\n",
    "oak" : "The inside walls is perfectly smooth.\n",
    "ground" : "The floor is perfectly smooth with no apparent scratches.\n",
    "floor" : "The floor is perfectly smooth with no apparent scratches.\n",
    "wall" : "The walls are so smooth they almost shine.\n",
  ]) );
}

