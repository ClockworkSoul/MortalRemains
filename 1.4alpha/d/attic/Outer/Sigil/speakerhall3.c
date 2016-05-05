#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "prisine" : "/d/Outer/Sigil/monsters/prisine" ]) );
	reset();
     set ("light", 1) ;
  set("short", "Hall of Speakers.") ;
  set("long", @ENDLONG
You are in the Hall of Speakers in Sigil, on the second floor.
ENDLONG
  );
     set ("exits", ([
        "down" : SIGIL+"speakerhall.c" ]));       
}
