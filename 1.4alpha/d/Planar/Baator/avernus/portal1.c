#include <mudlib.h>

inherit PORTAL ;

void create() {
   set("short", "a shimmering portal") ;
   set("long", @ENDLONG
Looking into the portal, you can barely make out a few vague shapes..
There appears to be a series of rolling hills and a large city in the
distance beyond them.

You could "enter" it, if you wanted to.
ENDLONG
  ) ; 
  set("id", ({ "portal", "shimmering portal" }) ) ;
  set_destination("/d/Planar/Baator/dis/dplain1.c") ;
}
