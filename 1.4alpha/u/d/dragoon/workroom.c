/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

#include <mudlib.h>
#include "/u/d/dragoon/include/format.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
   set( "short" , "Dragoon's workroom");
   set ( "long" , format(
       "This is a temporary workroom for those wizards who do not have one of "
       "IT IS EASY TO ADD STUFF IN THE CENTER "
       "their own that will load.  This is also a test of my format command "
       "to see if it will work here."
       ));
  set( "exits", ([
       "start" : "/d/Ancients/rooms/wizrm.c",
       "void" : "/d/std/void.c",
  ]) );
}
