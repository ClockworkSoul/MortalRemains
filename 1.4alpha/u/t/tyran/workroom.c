/*
//This is Tyran's workroom.
//Re-coded: June 12, 2000 by Tyran
*/

#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );

  set( "short", "	Tyran's Throne Room" );
  set( "long", @EndText
  This large and elegant throne room radiates power
and royalty.  Long elegant tapestries hang on the
walls depicting Tyran's various battle victories
over his long career as the Manasi Military Adjunct.
A long red carpet runs along the floor, leading up
to Tyran's throne.  The throne is a large ornate
oaken chair carved with various glyphs.  On the east,
south, and west walls are various round gates that
swirl with blue-white energy.  They seem to lead to
other places.  There is a large dais with computer
paraphenelia and a viewscreen that shows Tyran
various aspecst of his area.  This is where he does
his work.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
    "gate" : "/u/t/tyran/spider/rooms/spcave01.c",
  ]) );
}