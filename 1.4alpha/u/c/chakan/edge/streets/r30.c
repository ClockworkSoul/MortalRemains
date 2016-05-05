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
	"southeast" : "/u/c/chakan/edge/streets/r28.c",
	"north" : "/u/c/chakan/edge/streets/r31.c",
	"south" : "/u/c/chakan/edge/streets/fountain.c",
	"east" : "/u/c/chakan/edge/streets/r29.c",
	"west" : "?",
  ]) );
}
