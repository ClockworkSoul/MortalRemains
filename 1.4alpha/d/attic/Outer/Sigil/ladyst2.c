#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are on Lady's Row in Sigil, where the Law is a stifling presence.
To the east are the barracks, and to the west is the Court.
ENDLONG
  );
  set("short", "Lady's Row, Lady's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"ladyst1.c",
	"east" : SIGIL+"barracks.c",
	"west" : SIGIL+"court.c" ]));
}
