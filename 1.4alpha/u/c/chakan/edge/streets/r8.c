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
	"north" : "?",
	"south" : "/u/c/chakan/edge/streets/r9.c",
	"east" : "?",
	"west" : "/u/c/chakan/edge/streets/r7.c",
  ]) );
}
