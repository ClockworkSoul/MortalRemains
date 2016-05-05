/*
** File: /u/n/nemar/water/city/rooms/central1b.c
**Author:  Lord Nemar of the Shadoweir
*/

#include <config.h>
#include "eloria.h"

inherit ROOM;

void create()
{
    ::create();
seteuid(getuid() );
    set("light", 1);
    set("author", "Nemar");
    set("short" , "Shark Way");
    set("long",@EndText
You are near the square.  You can see a fountain in the distance
to the west.  To the north looks like the bank, and to the south
appears to be the post office.  You see many other businesses
lining the street towards the east.
EndText
    );
    set("exits",([
      "north" : eloria+"bank.c",
      "east" : eloria+"central2b.c",
      "south" : eloria+"post.c",
      "west" : eloria+"square5.c",
    ]) );
    set("item_desc", ([
      "ground" : "The street is made right out of the ocean floor.\n",
      "street" : "The street is made right out of the ocean floor.\n",
      "buildings" : "The buildings are made of coral.\n",
      "walls" : "The building walls are made of coral.\n",
      "bank" : "Why don't you walk in and take a closer look.\n",
      "post" : "Why don't you walk in and take a closer look for yourself.\n",
    ]) );
}
