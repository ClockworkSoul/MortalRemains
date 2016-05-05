#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand on Main Street in Sigil, along the Clerk's Ward.
Hull Road lies to the south and Thistlewind Way lies to the north.
ENDLONG
  ) ;
  set("short", "Main Street, Clerk's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"thistlewindst1.c",
	"south" : SIGIL+"hullst1.c",
	"east" : SIGIL+"mainst9.c",
	"west" : SIGIL+"mainst7.c" ]));
}

