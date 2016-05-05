#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand on the south end of Turtle Lane in the Market Ward of Sigil.
A strange, macabre shop lies to the east and a tastefully decorated
antique shoppe lies to the west.
ENDLONG
  ) ;
  set("short", "Turtle Lane, Market Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"turtlest1.c",
	"east"	: SIGIL+"parts.c",
	"west" : SIGIL+"antiques.c" ]));
}
