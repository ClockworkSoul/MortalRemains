#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
This is the Embalmer's Shop in Sigil.  This place has been closed due
to the fact that the corpses in the area have been deteriorating so
fast that nobody wants anyone embalmed for funerals.
This shop is deserted.
ENDLONG
  );
  set("short", "Zakk's Corpse Curing.") ;
     set ("exits", ([
	"south" : SIGIL+"mainst6.c" ]));
}
