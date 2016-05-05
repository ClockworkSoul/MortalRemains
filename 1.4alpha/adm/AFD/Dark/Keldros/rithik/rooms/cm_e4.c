#include "cm_h"
void create() {
  seteuid(getuid());   
  make_scary();
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In a mysterious cemetary.");
set("long", @ENDLONG
The cedar trees surrounding the cemetary create a canopy
of darkness which envelops the entire area.  You stand
on a walkway through the cemetary.  Graves of many sizes
and shapes can be seen to the west and east.  A tall iron
fence prevents you from going south.  The walkway forks to
the north.
ENDLONG
);
set("exits", ([
  "east" : ROOMS(cm_e5),
  "west" : ROOMS(cm_e3),
  "north" : ROOMS(cm_ne),
]) );

::create();
}