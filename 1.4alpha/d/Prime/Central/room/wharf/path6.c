inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "A Sandy Path");
    set("long", wrap(
	"You are on a narrow beach path seperating the industrial "+
	"piers to the northwest from the beach to the east. "+
	"The path is narrow, and beach grass and poison "+
	"ivy restrict your movement."
      ) );
    set("exits", ([
      "east" : "/d/Ocean/Main/room/beach5.c",
      "northwest" : "/d/Prime/Central/room/wharf/wharf5.c",
    ]) );
    set("listen", ([
      "default" : "You can hear the pounding of the surf clearly.\n",
    ]) );
    set("item_desc", ([
      "path" : "It is narrow and very sandy.\n",
      "sand" : "Clean white sand that burns your feet.\n",
      "pier#piers#beach" : "You can't quite see it from here.\n",
      "grass#beach grass" : "It grows in large matted masses.\n",
      "ivy#poison ivy" : "There's a faded old sign in the middle of it all.\n",
      "sign" : "It reads: BEWARE: POISON IVY. How thoughtful.\n",
    ]) );
    set("exit_msg", ([
      "northwest" : "$N walks down the path towards the piers.\n",
      "east" : "$N wanders down the path towards the beach.\n",
    ]) );
    set("smell", ([
      "default" : "The smell of salt air fills your nostrils.\n",
    ]) );
}

/* EOF */
