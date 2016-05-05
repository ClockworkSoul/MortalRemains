#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand in a narrow sidestreet breaking off from Main Street to the
north.  To the east lies a tall, colorful palace of some sort.
ENDLONG
  );
  set("item_desc", ([
   "palace" : "It's awfully.. colorful.\n",
 ]) ) ;
  set("short", "Lady's Row, Lady's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"mainst20.c",
	"south" : SIGIL+"ladyst2.c",
	"east" : SIGIL+"palace.c" ]));
}
