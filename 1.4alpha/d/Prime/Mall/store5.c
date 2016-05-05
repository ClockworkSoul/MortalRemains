#include "mall.h"

inherit BUYONLY_SHOP;

void create()
{
    ::create();
    seteuid( getuid() );
    stock = ([
    "pgown.c" : 10,
    "ngown.c" : 6,
    "ggown.c" : 3,
    "egown.c" : 1,
  ]);
    set("shopkeeper", "sarah");
    set("shop_dir", MALL+"inv/");
    set( "light", 1 );
    set("author", "Herself");
    set("objects" , (["sarah" : MALL+"mons/sarah.c"]) );
    reset();
    set("short" , "Bride's Boutique");
    set("long", wrap(
	"You are in the Bridal shop. A rack on the left "+
	"holds the various styles of wedding dresses. "+
	"On the right, are the veils and bride's maid's "+
	"dresses. "
      )+"Commands are: list, buy <item>\n");
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "wedding gown" : "It is a gown to wear at your wedding. \n",
      "dress" : "A wedding dress. \n",
      "dresses" : "Various wedding dresses. \n",
      "bride's maid's dress" : "They're ugly! \n",
      "bride's maid's dresses" : "They're ugly! \n",
      "gown" : "To wear at your wedding. \n",
      "nice gown" : "It's nice. \n",
      "plain gown" : "It's plain. \n",
      "gorgeous gown" : "It's gorgeous. \n",
      "elegant gown" : "It's elegant!\n",
      "sign" : "It says 'Bride's Boutique'. \n",
      "prices" : "The prices are a bit high, but not too bad. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set( "exits", ([
      "west" : MALL+"mall2.c",
    ]) );
}
