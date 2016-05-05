
#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("smell" , "You can faintly smell tuntan oil.\n");
    set("listen" , "You hear the waves crashin on the beach. \n");
    set("author" , "herself");
    set("short" , "The Beach");
    set( "long", wrap( 
	"You are standing on the sandy beach. East and west, the "+
	"beach seems to continue for miles. Waves crash as they "+
	"approach the beach. The sand squishes "+
	"between your toes, and the hot sun "+
	"beats down on your head. "
      ));

    set("objects" , ([
      "noise" : O_MON+"ocean_sounds.c",
      "turtle" : O_MON+"turt.c",
      "crab" : O_MON+"crab.c",
    ]) );
    reset();
    set("item_desc", ([
      "beach#sandy beach" : "You are standing on it. It is sandy. \n",
      "wave#waves" : "They crash on the beach. \n",
      "sun#hot sun" : "You squint up at the sun, but it hurts your eyes. \n",
      "water" : "You can see your reflection, a bit distorted. \n",
      "reflection" : "It looks like you, except a bit twisted. \n",
      "sand" : "It's pure white, and sparkles. \n",
      "toes" : "Your toes are half burried in the sand. \n",
      "head" : "You can't see your head silly! \n",
      "east#west" : "Try looking in the direction. \n",
    ]));

    set( "exits", ([
      "west" : O_ROOM+"beach7.c",
      "east" : O_ROOM+"beach.c",
    ]) );
}
