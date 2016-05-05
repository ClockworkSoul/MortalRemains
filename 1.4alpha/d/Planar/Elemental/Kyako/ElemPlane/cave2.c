#include <mudlib.h>
#include "plane.h"

inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set("light", 0);
    set ("short", "Cave" );
    set( "long", @EndText
You walk into pitch blackness,
because something is obscuring the light
from passing through the water.
There is a sign here; it may be helpful to read it.
EndText
    );
    set( "exits", ([
      "north" : PLANE+"cave1.c",
      "west"  : PLANE+"cave3.c",
    ]) );
    set("item_desc" , ([
      "sign" : @EndSign
A little intelligence test:

1. How many birthdays does the average man have?
2. Some months have 31 days; how many have 28?
3. How many outs are there in an inning?
4. Divide 30 by 1/2 and add 10. What is the answer?
5. If there are 3 apples and you take away 2, how many do you have?
6. A farmer has 17 sheep, and all but 9 die. How many are left?
7. How many animals of each sex did Moses take on the ark?
8. How many two cent stamps are there in a dozen?

Have fun!
EndSign
   ]) );
}
