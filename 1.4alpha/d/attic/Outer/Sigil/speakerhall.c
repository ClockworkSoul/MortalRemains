#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "tripicus" : "/d/Outer/Sigil/monsters/tripicus" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand in the Hall of Speakers in Sigil, on the first floor.
ENDLONG
  );
  set("short", "Hall of Speakers.") ;
     set ("exits", ([
	   "north" : SIGIL+"speakerhall1.c",
        "up" : SIGIL+"speakerhall3.c",
        "west" : SIGIL+"thistlewindst1.c" ]));       
}
