#include <mudlib.h>
#include "sigil.h"

inherit SHOP ;

void create() {
     ::create();
     set ("light", 1) ;
	set("forbidden", 1);
     set ("long",
@ENDLONG
You are in the Grand Bazaar of Sigil, home to all your adventuring
needs.  This shop buys and sells all manner of things, usually selling
them for a lot more than they bought things for.

Commands are: buy, list, sell, and appraise.
ENDLONG
  );
  set("short", "The Grand Bazaar of Sigil.") ;
     set ("exits", ([
	"west" : SIGIL+"duskgatest2.c" ]));
}
