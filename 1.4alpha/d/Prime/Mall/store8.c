#include "mall.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set("short" , "Jewelry Store");
    set("long", wrap(
	"The room sparkles as the light bounces off various "+
	"diamond rings and other jewelry on display here. "+
	"There is a display case in the center of the store. "+
	"Take a look and pick something out for that special "+
	"someone. "
      ) );
    set("item_desc", ([
      "floor" : "It is white and looks freshly waxed. \n",
      "sign" : "It says 'Some Jewelers'. \n",
      "display case" : wrap("There are tons of rings on "+
	"display here. Diamond engagement rings seem "+
	"to be the majority. Perfect for when you want to "+
	"'pop the question'. "),
      "walkway" : "It is white and looks freshly waxed. \n",
      "diamond ring" : "It is sparkly.\n",
      "diamond rings" : "They're really nice. \n",
      "ring" : "For your finger. \n",
      "rings" : "For your finger. \n",
      "display" : "Rings and other jewelry. \n",
      "case" : "Try 'display case'. \n",
      "jewelry" : "Mostly gold... rings, necklaces, bracelets...\n",
      "necklaces" : "Assorted gold necklaces. \n",
      "necklace" : "Gold herring bone. \n",
      "bracelet" : "Some match the necklaces.\n",
      "bracelets" : "Some match the necklaces. \n",
    ]) );
    set( "exits", ([
      "east" : MALL+"mall4.c",
    ]) );
}
