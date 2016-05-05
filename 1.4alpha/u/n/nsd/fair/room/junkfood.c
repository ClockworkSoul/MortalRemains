/*
** File: junkfood.c
** Author: Lady Nsd
*/

#include "fair.h"

inherit BUYONLY_SHOP;

void create()
{
    ::create();
    seteuid( getuid() );
    stock = ([
    "nachobowl.c" : 20,
    "pizza.c" : 20,
    "hotdog.c" : 20,
    "cotton.c" : 20,
    "frappe.c" : 20,
    "cola1.c" : 20,
    "cola2.c" : 20,
    "beer.c" : 20,
  ]);
    set("shopkeeper" , "candy man");
    set("shop_dir" , FAIR_OBJ);
    set( "light", 1 );
    set("author", "nsd");
    set("short" , "Lil booth of Junk Food");
    set("long", wrap(
	"This is the spot to end your hunger or your thirst. We got\n"+
	"all kinds of candies, healthy junk, and beverages. Choose\n"+
	"your favorite ;-)\n"+
	"Comands are: <list> and <buy> item.\n"));
    set("item_desc", ([
    ]) );
    set("listen" , "Nothing but the ordinary sounds of a fair.\n");
    set("objects" , ([
      "candy man" : FAIR_MON+"candyman.c",
    ]) );
    reset();
    set( "exits", ([
      "east" : "?",
      "west" : "?",
    ]) );
}
