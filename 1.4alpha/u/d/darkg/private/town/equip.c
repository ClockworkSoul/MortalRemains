#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit SHOP;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
    set("short", "Gunthars Equipments");
  set("long", @ENDTEXT
This is the item shop. Gunthar sells any kind of items for a reasonable price.
There are pelts of fur, lanterns, pots & pans, and clothing.
ENDTEXT
);
  set( "exits", ([
       "south" : AROOM+"street23.c",
  ]) );
  set("item_desc", ([
	"fur" : "These range from racoon,chipmunk, and bears to large multicolored
scaled pelts.",
	"lantern" : "Yup it's a lantern...nothing strange about that.",
	"pots" : "These are Pots used for cooking.",
	"pans" : "These are used for frying food. OR..a good
blunt weapon.",
	"clothing" : "Nothing fancy just plain ole clothes.",
]) );
}
