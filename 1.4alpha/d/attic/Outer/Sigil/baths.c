// 28 Oct 98 - Cyanide cleaned up.

#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    set("objects", ([
      "#PORTAL#" : "/d/Outer/Sigil/items/con_portal",
      "iarmid" : "/d/Outer/Sigil/monsters/iarmid"])
    );
    set ("light", 1) ;
    set ("long", wrap("This great marble building is one of the "+
      "greatest centers of relaxation in Sigil. Here you can soak "+
      "in the hot baths, swim in the specially chilled pools, or "+
      "steam in one of the saunas. The owner, Iarmid, directs the "+
      "activities here.") );
    set("short", "The Baths.") ;
    set ("exits", ([
      "up" : SIGIL+"baths1.c",
      "west" : SIGIL+"newtst1.c" ]));
    reset();
}

/* EOF */
