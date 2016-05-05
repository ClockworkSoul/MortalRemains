#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit SHOP;

void create()
{
  ::create();
  seteuid(getuid());
  set("objects" , ([ "killian" : MON+"killian.c" ]) );
  reset();
  set( "light", 1 );
  set("short" , "Killian's Shop");
  set( "long" , @EndText
  You stand in Killian's Shop of Shops, it is a magnificent shop as
  it is the only one in towne. To the far end of the shop is a small
  counter with a man standing behind it. All sorts of shit is hanging
  from the walls and you get the impression that Killian is a trader
  of all things...no matter what it is...or where it came from.

  The commands are: list, buy <item>, sell <item>, appraise <item>.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street19.c",
  ]) );
  set("item_desc" , ([
    "counter" : "A nice wooden counter, very polished and shiny\n",
    "shit" : "Various items for sale.\n",
    "items" : "Just simply type list.\n",
  ]));
}
