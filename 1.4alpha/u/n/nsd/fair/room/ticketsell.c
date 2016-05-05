/*
** File: ticketsell.c
** Author: Lady Nsd
*/

#include "fair.h"

inherit BUYONLY_SHOP;

void create()
{
    ::create();
    seteuid( getuid() );
    stock = ([
    "ticket.c" : 100,
  ]);
    set("shopkeeper" , "ticket seller");
    set("shop_dir" , FAIR_OBJ);
    set( "light", 1 );
    set("author", "nsd");
    set("short" , "Ticket dispenser booth");
    set("long", wrap(
	"Finally you find the ticket seller booth. Buy as many tickets\n"+
	"as you can afford. You might want to enjoy the whole fair. :-p\n"+
	"Comands are: <list> and <buy ticket>. \n"));
    set("item_desc", ([
    ]) );
    set("listen" , "Nothing but the ordinary sounds of a fair.\n");
    set("objects" , ([
      "ticket seller" : FAIR_MON+"tkseller.c",
    ]) );
    reset();
    set( "exits", ([
      "east" : "?",
      "west" : "?",
    ]) );
}
