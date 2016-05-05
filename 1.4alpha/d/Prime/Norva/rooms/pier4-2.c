// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Pier 4 North.");
  set("long", @ENDLONG
You stand on the north end of Pier 4 on Naval Station Norva.
The pier extends further to the south.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
     "south" : ROOMS(pier4-1),   
  ]) ) ;
  ::create();
  reset();
}
