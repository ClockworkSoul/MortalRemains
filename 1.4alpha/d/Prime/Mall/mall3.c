#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Mall");
    set("long", wrap(
	"You are in the mall, on the main walkway. "+
	"Shops are on either side of you, and crazed shoppers "+
	"are still rushing past you, knocking into you. "+
	"To the west is Sun 'N Surf, and east is Victoria's "+
	"Secret. "
      ) );
    set("item_desc", ([
      "sign" : "It says 'Welcome to the Mall'. \n",
      "store" : "There are many of them. \n",
      "mall" : "You're in it DUH!\n",
      "east" : "Try looking east.\n",
      "west" : "Try looking west. \n",
      "sales" : "You don't see any good ones. \n",
      "stores" : "There are many of them. \n",
      "shops" : "West is Sun 'N Surf, east is Victoria's Secret/ \n",
      "shop" : "Which one? \n",
      "shoppers" : "Find one you can kill ok? \n",
    ]) );
    set("listen" , "The elevator music makes your ears bleed. \n");
    set( "exits", ([
      "west" : MALL+"store6.c",
      "east" : MALL+"store7.c",
      "south" : MALL+"mall2.c",
      "north" : MALL+"mall4.c"
    ]) );
}
