#include <mudlib.h>
#include <td.h>

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("short", "The ThunderDome.") ;
  set("long", @ENDLONG
You're in the Thunderdome.  A poster is on the wall,
listing the top warriors.
ENDLONG
  );
  set("item_desc", ([
    "poster#sign" : "You could read it too.\n",
  ]) ); 
  set("exits", ([
    "east" : OB_ROOM,
  ]) );
  ::create() ;
  reset() ;
}

void init() {
  add_action("read", "read") ;
}

int read(string str) {
  if (!str) {
     write("Read what?\n") ;
     return 1;
  }
  switch(str) {
     case "poster" : write(TD_D->list_rankings()) ;
            break ;
     case "sign" : write(@ENDSIGN
The sign reads:

	Welcome to the ThunderDome!

 To the east is the observation room where you can watch the battles.
ENDSIGN
  ) ;  break ;
     default: 
     write("Read what?\n") ;       break ;
  }
  return 1;
}
