#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
"You are in the Lady's ward of Sigil.\n"+
  set("long", @ENDLONG
You are on Main Street in the Lady's Ward of Sigil.
ENDLONG
 );
set("short", "Main Street, Lady's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"doomguardst1.c",
	"east" : SIGIL+"mainst20.c",
	"west" : SIGIL+"mainst18.c" ]));
}
