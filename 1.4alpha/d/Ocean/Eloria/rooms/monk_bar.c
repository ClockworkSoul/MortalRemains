/*
* FILE: Monk Jazz Bar
* DESC:
*/

#include <mudlib.h>
#include "eloria.h"
#include "mpub.h"

inherit PUB;

void init()
{
    add_action("display_menu", "read");
    add_action("order_drink",  "order");
//add_action("order_drink", "buy");
}

void create()
{
    ::create();
    seteuid( getuid() );
    set("drink_types", BEVLIST);
    set( "light", 1 );
    set( "smell", "" );
    set( "short", "The Monk Jazz Bar" );
    set( "safe", 1);
    set( "forbidden", 1);
    set( "long", wrap(
	"You are standing in a smokey jazz bar. "+
	"All around you, jazz heads are diggin' the tunes. "+
	"There is a menu at the bar for you to read.\n"
      ));

    set("item_desc", ([
      "jazz heads" : "They wear barret's, smoke ciggerates and are boppen their heads to the music.\n",
      "bar" : "The bar wraps around the north and east walls. Regulars sit around it, holding it up.\n",
      "menu" : "A drink menu that perhaps you could read.\n",
    ]));

    set( "exits", ([
      "north" : eloria+"central1a.c",
    ]));
}

int display_menu(string arg)
{

    if(!arg) write("Read what?\n");
    if(lower_case(arg) != "menu") write("You don't see that here.\n");

    write(@ENDTEXT
------------------ On Tap -------------------
Guinness
Harpoon IPA
Sam Adams
Pete's Seasonal

------------------ Liquors -------------------
Jack Daniels                Southern Comfort
Quervo Gold                 Absolut
Captain Morgans             Tanqueray

------------------ Mixed Drinks -------------------
Margarita                   Long Island Iced tea
Red Death                   Alabama Slammer
B52                         Kamakazi
Lemmon Drop                 

ENDTEXT
    );
    return 1;
}

string drink(string str)
{
    switch(lower_case(str))
    {
    case "guinness" : str = "You drink down a wonderful Guinness.\n"; break;
    case "harpoon ipa" : str = "The Harpoon goes down smoothly.\n"; break;
    }
    return str;
}

int order_drink(string arg)
{

    if(!arg) return notify_fail("Order what?\n");

    switch(lower_case(arg))
    {
    case "guinness" :
	write(@ENDBLAH
The bartender makes you a beautiful Guinness!
You pay the bartender 50 credits.

ENDBLAH
	);
	this_player()->debit(50);
	break;
    case "long island iced tea" :
	write(@ENDBLAH
The bartender makes a Long Island Iced Tea.
He adds:
1/2 oz Vodka
1/2 oz Gin
1/2 oz Light Rum
1/2 oz Tequila
Juice of 1/2 Lemon
1 dash Cola
Ice

You pay the bartender 50 credits.

ENDBLAH
	);
	break;
    default :
	write("Sorry, we don't have "+arg+".\n");
	break; 
    }
    return 1;
}
