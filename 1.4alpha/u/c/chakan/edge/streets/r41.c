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
	"north" : "/u/c/chakan/edge/grave/entrance1.c",
	"south" : "/u/c/chakan/edge/guard/back.c",
	"east" : "/u/c/chakan/edge/streets/r42.c",
	"west" : "/u/c/chakan/edge/streets/r40.c",
  ]) );
}
