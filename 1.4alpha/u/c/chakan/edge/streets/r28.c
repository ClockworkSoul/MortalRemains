#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
set( "short" , "basic street" );
  set( "long", @EndText
Generic street.
EndText
  );
  set( "exits", ([
	"southwest" : "?",
	"northwest" : "/u/c/chakan/edge/streets/r30.c",
	"north" : "/u/c/chakan/edge/streets/r29.c",
	"south" : "?",
	"east" : "/u/c/chakan/edge/streets/r27.c",
	"west" : "/u/c/chakan/edge/streets/fountain.c",
  ]) );
}
