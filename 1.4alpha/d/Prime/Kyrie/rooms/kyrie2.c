
#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short" , "Kyrie Forest" );
  set( "long", @EndText
As you go deeper in the forest of Kyrie you notice that there are
more than just one shadow following you now.  As you speed up
they speed up and when you slow down they slow down.  The stream
still runs very peacefully north here.
EndText
  );
  set( "exits", ([
"south" : KYRIE+"kyrie1.c",
"north" : KYRIE+"kyrie3.c",
  ]) );
}
