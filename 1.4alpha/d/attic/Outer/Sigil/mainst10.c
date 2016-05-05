#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in the Clerk's Ward of Sigil, on Main Street.
ENDLONG
  );
  set("short", "Main Street, Clerk's Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"transit.c",
	"east" : SIGIL+"mainst11.c",
	"west" : SIGIL+"mainst9.c" ]));
}
