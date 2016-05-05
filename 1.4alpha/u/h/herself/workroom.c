#include "herself.h"
#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "Herself");
    set( "short" , "Herself's Front Room");
    set("c_long" , wrap(
	"As you enter, you are immediately greeted by "+
	"the abundant daylight which streams in from the "+
	"unshaded windows. "+
	"Looking around, you can see that this is the most used room "+
	"in the house. There is a desk against the far wall, a couch "+
	"facing the windows, and a few tables around the couch. "+
	"Other objects in the room are a stereo, some pictures on "+
	"the walls, and a bookcase. "
      ) );
    set("item_desc", ([
      "couch" : "It is soft and inviting... Take a seat. \n",
      "clutter" : "It is made up of papers and other junk. \n",
      "desk" : wrap( "It is completely burried under"+
	" a huge pile of clutter... You wonder "+
	"how anyone ever gets any work done on it. "),
      "window" : wrap( "A huge bay window, the curtain blows"+
	" inward and you realize someone has left it open,"+
	" you pick up the scent of new spring flowers on the"+
	" warm breeze..."),
      "picture" : "It's a picture of Herself and her mom, how sweet. \n",
      "daylight" : "It is bright and cheery. \n",
      "stereo" : "It's Kenwood, and its Rockin!\n",
      "walls" : "They're white. \n",
      "wall" : "It's white, with stuff hanging on it. \n",
      "bookcase" : wrap("It's filled with books. Most written by "+
	"Dean Koontz and John Saul. Horror and supernatural novels."),
    ]) );
    set("listen" , "You hear some crazy song playin... it's Buddy Holly by Weezer\n");
    set( "exits", ([
      "up" : ROOMS+"bedroom.c",
      "start" : START,
      "void"  : VOID,
      "portal" : "/d/Prime/Mall/mall.c",
    ]) );
}
