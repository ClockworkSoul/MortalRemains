#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in the guildhall district of Sigil, on Main street.
The Embalming Shop is to the north.
ENDLONG
  );
  set("short", "Main Street, Guildhall Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"embalmers.c",
"south" : SIGIL+"clericguild.c",
	"east" : SIGIL+"mainst7.c",
	"west" : SIGIL+"mainst5.c" ]));
}
