/* Just a little reminder to Chronos, from Chronos.
   DO NOT TRY TO MAKE THE SIGN "read"-able!!!!!
   Remember, there is a board here that uses the read command.  :)
       Dumb Ass.
*/
#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    reset();
    set ("light", 1) ;
    set("long", @ENDLONG
You are in the center of the crowded Market Ward in Sigil.
It is crowded, hazy, and reeks of sewage.
There is a sign here on what's new.
ENDLONG
    );
    set("short", "Main Street, Center of the Market Ward.") ;
    set ("exits", ([
      "north" : SIGIL+"duskgatest1.c",
      "south" : SIGIL+"turtlest1.c",
      "east" : SIGIL+"mainst2.c",
      "west" : SIGIL+"mainst22.c" ]));

    set("smell", ([
      "default" : "The smell of sewage lingers in the air.\n",
    ]) ) ;
    set("item_desc" , ([
      "sign" : @EndSign

                        What's new in Sigil
                     =-----------------------=
(Updated 18 October, 1998)

                          WELCOME BACK!!

Current class updates:
  Fighters, Knights, and Barbarians all work. Don't ask for
     percentages. We don't know them.  ;)
  Mages and Necromancers both in. Invokers and Conjurers on
     the way.
  Priests coming along as well (Tempus, Talos, and Oghma all in).
     Others on the way as well.
  Thieves guild almost complete.

 * HERO GUILDS HAVE BEEN ABOLISHED - LEVEL CAP HAS BEEN REMOVED *
 * Most existing hero guilds will become full fledged classes. *

EndSign
    ]) );
    call_other("/d/Outer/Sigil/obj/player_board.c", "foo");  
}
