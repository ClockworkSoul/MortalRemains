#include <mudlib.h>
#include "fuckstick.h"

inherit PUB;

void create()

{
 ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "T & T's Tavern");
   set("long", @ENDTEXT
Loud laughter and cheering fills this bar as 
you enter. You feel relaxed as the barmaid asks for your order.
Commands are: menu, drink <drinkname>, powerheal <drinkname> .
ENDTEXT
);
   set("exits", ([
       "west" : AROOM+"street35.c",
]) );
}
