#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "Victoria's Secret");
    set("long", wrap(
	"You are in lingerie heaven. Your head is spinning "+
	"from the awesome collection. Teddies, nighties, garters... "+
	"The maniquins look like they are ready for a night "+
	"of passion. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Victoria's Secret'. \n",
      "collection" : "It's awesome. \n",
      "passion" : "That is not something you can see. \n",
      "lingerie" : "It's heavenly.\n",
      "teddies" : "Sexy. Woo woo!\n",
      "garter" : "They hold up the stockings. \n",
      "garters" : "They hold up the stockings.\n",
      "stockings" : "Lacey white, with a seem up the back. \n",
      "spiked heals" : "You don't want them to step on you. \n",
      "heals" : "They're spiked, real high.\n",
      "teddy" : "Lacey... hmmm \n",
      "nighty" : "It is a floor length black nightgown. \n",
      "bustierre" : "Red and lacey. Sinful... \n",
      "maniquin" : wrap("You are quite aroused by the "+
	"feminine looking maniquin. She is dressed in a white "+
	"bustierre with garters connected to lacey white "+
	"stockings. She is complete with white spiked heals. "),
    ]) );
    set("objects", ([
      "shopper" : MALL+"mons/shopper.c",
      "clerk" : MALL+"mons/clerk.c",
    ]) );
    reset();
    set( "exits", ([
      "west" : MALL+"mall3.c",
    ]) );
}
