/*
** File /u/n/nemar/rd/city/rooms/3rdlvla.c
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
You have reached the top of the guild.  This is the throne room where the
guild leader conducts his daily business.  You see a spiral staircase leading down.
EndText
  );
  set( "exits", ([
    "down" : "/u/n/nemar/rd/gh/rooms/2ndlvla.c",
  ]) );
  set( "item_desc", ([
    "tree" : "The inside walls is perfectly smooth.\n",
    "oak" : "The inside walls is perfectly smooth.\n",
    "ground" : "The floor is perfectly smooth with no apparent scratches.\n",
    "floor" : "The floor is perfectly smooth with no apparent scratches.\n",
    "wall" : "The walls are so smooth they almost shine.\n",
  ]) );
}

