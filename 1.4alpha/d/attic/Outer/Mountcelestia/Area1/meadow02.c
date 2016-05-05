/*
** Creator: Cyanide (02 Jul 98)
*/

#include <mudlib.h>
#include "heaven.h"

inherit ROOM;

void create() {
    ::create();
    set("light", 1);
    set("long", wrap("You are standing in a lush grassy "+
	"meadow beneath an impossibly blue sky. The brilliant white "+
	"pyramid is much closer now, and from here you can make out "+
	"a large bonfire at the apex of the pyramid.") );  
    set("short", "A grassy meadow");
    set("exits", ([
      "north" : HEAVEN("pyr_base.c"),
      "south" : HEAVEN("meadow01.c"),
    ]) );
    set("item_desc", ([
      "meadow" : "It is filled with rare and delicate wildflowers.\n",
      "sky" : "Beside the occasional whitle cloud, it is flawless.\n",
      "wildflowers" : wrap("A huge variety, most of which you've "+
	"never seen before, and even some colors you oculd swear "+
	"you've never seen either."),
      "pyramid" : wrap("It is a tall, stepped pyramid of "+
	"brilliantly white stone. At its apex, is a tall column of "+
	"flame."),
      "apex" : "That's just another name for the top of the pyramid.\n",
      "top" : "That's just another name for the apex of the pyramid.\n",
      "perfumes" : "How do you propose to do that?\n",
      "bonfire" : "Actually, it's more like a column of fire.\n",
      "column" : "You can't make out any details from here.\n"
    ]) );
    set("smell", "The scent of exotic perfumes fills the air.\n");
}

/* EOF */
