#include "mall.h"

inherit BUYONLY_SHOP;

void create()
{
    ::create();
    seteuid( getuid() );
    stock = ([
    "gun.c" : 4,
    "goop.c" : 6,
    "m8ball" : 3,
    "gum" : 4,
    "anvil" : 2,
    "sign" : 2,
  ]);
    set("shopkeeper" , "bozo");
    set("shop_dir" , MALL+"inv/");
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "The Toy Store");
    set("long", wrap(
	"A toy store is just what this place needed. Now you can "+
	"purchase many of those annoying little toys and bug the "+
	"hell out of the people you like the most. If you have a "+
	"toy that you would like to be included, please contact "+
	"Herself. Please be respectful of others. "
      )+"Commands are: list, buy <item>\n");
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Toy Store'. \n",
      "prices" : "The prices are a bit high, but not too bad. \n",
      "walkway" : "It is white and looks freshly waxed. \n",
      "toys" : "There are a bunch of them. \n",
      "toy" : "To play with. \n",
    ]) );
    set("listen" , "Sounds like circus music playing here. \n");
    set("objects" , ([
      "bozo" : MALL+"mons/bozo.c",
      "unhappy" : MALL+"mons/unhappy.c",
      "kid" : MALL+"mons/kid.c",
    ]) );
    reset();
    set( "exits", ([
      "east" : MALL+"mall2.c",
    ]) );
}
/*
void init() {
    add_action("read_sign" , "read");
}
int read_sign(string str) {
    if (!str) {
	write("Read what? \n");
	return 1;
    }
    if (str == "sign"){
	write (@EndText
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
|                                           |
|      Please use these toys responsibly.   |
|      Your friendly wizzes have coded      |
|      them for your enjoyment. We ask      |
|      only that you follow a few simple    |
|      rules. As follows:                   |
|                                           |
|        1. You purchase toys at            |
|           your own risk.                  |
|        2. If someone uses a toy on you,   |
|           try to have a sense of humor.   |
|        3. If a person asks you to         |
|           stop, please do.                |
|        4. Enjoy yourself.                 |
|                                           |
|   Remember, these toys are for fun.       |
|   but if they are abused, they may        |
|   have to be removed from the game.       |
|                                           |
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
EndText);
	say(
	  TPN+" reads the sign. \n");
	return 1;
    }
    return 1;
}
*/
