#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are in the densely populated Lady's Ward of Sigil.
It is significantly more crowded here than in other parts of town,
but surpisingly enough, the smell is more pleasant here.
ENDLONG
  );
  set("smell", ([
  "default" :"The smell of sewage is very faint here.\n",
  ]) ) ;
  set("short", "Main Street, Lady's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"fortunepub.c",
	"south" : SIGIL+"ladyst1.c",
	"east" : SIGIL+"mainst21.c",
	"west" : SIGIL+"mainst19.c" ]));
}
