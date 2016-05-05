#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Main Street, Lower Ward.") ;
  set("long", @ENDLONG
You are in Main Street in the Lower Wards of Sigil.
ENDLONG
  );
     set ("exits", ([
	"east" : SIGIL+"mainst17.c",
	"west" : SIGIL+"mainst15.c" ]));
}
