#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
      set ("light", 1) ;
     set ("long",
"You are in a cell. \n"+
"These are some of the cleanest rooms in Sigil.\n") ;
  set("short", "A cell.") ;
  set("objects", ([ 
   MON(prisoner) : 2,
  ]) ) ;
     set ("exits", ([
           "west" : SIGIL+"prison2.c" ]));       
  reset() ;
}
