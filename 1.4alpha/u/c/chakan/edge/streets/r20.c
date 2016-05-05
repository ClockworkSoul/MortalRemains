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
	"south" : "/u/c/chakan/edge/wagon/entrance1.c",
	"east" : "/u/c/chakan/edge/streets/r19.c",
	"west" : "/u/c/chakan/edge/streets/r21.c",
  ]) );
}
