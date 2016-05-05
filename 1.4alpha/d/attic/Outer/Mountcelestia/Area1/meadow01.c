/*
** Creator: Cyanide (02 Jul 98)
*/

#include <mudlib.h>
#include "heaven.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light", 1);
    set("long", wrap("You are standing in a lush grassy "+
	"meadow beneath an impossibly blue sky. A wonderous "+
	"variety of wildflowers grow all around, filling the air "+
	"with their exotic perfumes.\nYou see what looks like to "+
	"be a man-made pyramid far to the north.") );
    set("short", "A grassy meadow");
    set("exits", ([
      "north" : HEAVEN("meadow02.c"),
    ]) );
    set("item_desc", ([
      "meadow" : "It is filled with rare and delicate wildflowers.\n",
      "sky" : "Beside the occasional whitle cloud, it is flawless.\n",
      "wildflowers" : wrap("A huge variety, most of which you've "+
	"never seen before, and even some colors you could swear "+
	"you've never seen either."),
      "pyramid" : wrap("It is made of bright white stone that "+
	"practically glows in the sunlight."),
      "perfumes" : "How do you propose to do that?\n",
    ]) );
    set("smell", "The scent of exotic perfumes fills the air.\n");
    set("objects", ([
      "#PORTAL#" : H_OBJ("main_portal")
    ]) );
reset();
}

/* EOF */
