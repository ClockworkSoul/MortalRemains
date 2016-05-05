// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
    seteuid(getuid());
  set("short", "The training area.") ;
   set("long", @ENDLONG
You are in the proving grounds for the guard trainees.
ENDLONG
    );
    set("light", 1);
    set("exits", ([
  "south" : ROOMS(training4a) ,
    ]) );
    set("item_desc", ([
    ]) );
    set("search_desc", ([
    ]) );
    set("objects", ([
    ]) );
    set("exit_msg", ([
    ]) );
    ::create();
    reset() ;
}

void reset() {  // time to fill the room a bit.
    int i ;
  if (present("trainee", TO)) return ;
    i = random(2) + 1 ; 
    while (i) {
	clone_object(MON(trainee1))->move(TO) ;
	i-- ; 
    }
    i = random(3) ;
    while (i) {
	clone_object(MON(trainee2))->move(TO) ;
	i-- ;
    }
    ::reset() ;
}
