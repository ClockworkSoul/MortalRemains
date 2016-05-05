#include <mudlib.h>;
#include "mall.h"

inherit BUYONLY_SHOP;

void create()
{
    ::create();
    seteuid( getuid() );
    stock = ([
    "flipper" : 4,
    "wetsuit" : 4,
    "tank" : 2,
  ]);
    set("shopkeeper" , "Hans");
    set("shop_dir" , MALL+"inv/");
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "Sun 'N Surf");
    set("long", wrap(
	"This store is full of sunwear and surfing gear. "+
	"On the left side is where all the bathing suits are. "+
	"On the right are the surfboards, boogie boards, and other "+
	"surfing items. "
      )+"Commands are: list, buy <item>\n");
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Sun 'N Surf'. \n",
      "sunwear" : "Mostly bathing suits, sunglasses, towels... \n",
      "bathing suit" : "Mutli-colored. \n",
      "bathing suits" : "There are many different styles. \n",
      "suit" : "The bathing kind. \n",
      "suits" : "The bathing kind. \n",
      "surfboard" : "Hang ten dude!\n",
      "surfboards" : "Hang ten dude!\n",
      "sunglasses" : "To keep the sun out of your eyes.\n",
      "towels" : "Beach ones. \n",
      "surf board" : "Hang ten dude!\n",
      "board" : "Surf or boogie?\n",
      "surf boards" : "Hang ten dude!\n",
      "boogie board" : "Catch a wave!\n",
      "boogie boards" : "Catch a wave!\n",
      "walkway" : "It is white and looks freshly waxed. \n",
    ]) );
    set("smell" , "It smells like cocoa butter suntan lotion. \n");
    set("objects" , ([
      "teen" : MALL+"mons/teeny.c",
      "kid" : MALL+"mons/kid.c",
      "hans" : MALL+"mons/hans.c",
    ]) );
    reset();
    set( "exits", ([
      "east" : MALL+"mall3.c",
    ]) );
}
