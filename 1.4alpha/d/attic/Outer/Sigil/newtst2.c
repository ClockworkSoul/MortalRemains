#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
This is Newt Street, where all kinds of liquids can be found.
An apothecary lies to the east.
ENDLONG
  );
set ("short","Newt st., Market ward");
     set ("exits", ([
	"south" : SIGIL+"newtst1.c",
	"east" : SIGIL+"elixers.c" ]));
}
