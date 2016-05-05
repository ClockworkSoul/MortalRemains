#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Thistlewind Way, Clerk's Ward.") ;
set("long", @ENDLONG
You are on Thistlewind Way in the Clerk's Ward of Sigil.
To the east lies the Hall of Speakers, and a large statue of a 
horse lies to the west.
ENDLONG
  );
     set ("exits", ([
	"south" : SIGIL+"mainst8.c",
	"east" : SIGIL+"speakerhall.c",
	"west" : SIGIL+"trioptic.c" ]));
}
