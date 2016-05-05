/*
** Creator: Cyanide (02 Jul 98)
*/

#include <mudlib.h>
#include "heaven.h"

inherit ROOM;

void create() {
    ::create();
    set("light", 1);
    set("long", wrap("You are standing at the base of a huge, "+
	"stepped pyramid made of flawless white marble. A set of "+
	"steps run up the center toward the apex, where a roaring "+
	"column of flame stands, burning brilliantly.") );
    set("short", "Pyramid Base");
    set("exits", ([
      "south" : HEAVEN("meadow02.c"),
      "up" : "/adm/obj/pyr_top.c",
    ]) );
    set("item_desc", ([
      "pyramid" : wrap("It is a tall, stepped pyramid of "+
	"flawless white marble. At its apex, is a tall column of "+
	"flame."),
      "apex" : "That's just another name for the top of the pyramid.\n",
      "top" : "That's just another name for the apex of the pyramid.\n",
      "bonfire" : "Actually, it's more like a column of fire.\n",
      "column" : "It seems to be waiting.\n",
      "steps" : "The run up from here, to the column of fire.\n",
    ]) );
    set("smell", "The scent of exotic perfumes fills the air.\n"+
      "Strangely, you smell no smoke.\n");
    set("listen", "You hear nothing but the roaring of the flames.\n");
}

/* EOF */
