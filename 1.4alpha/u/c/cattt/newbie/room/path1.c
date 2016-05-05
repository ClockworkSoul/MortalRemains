#include <newbie.h>

inherit ROOM;

void create(){
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("light",1);
    set("short","A path through the park.");
    set("long", @End
As you walk down the path, a gentle breeze blows across your skin.
The grass stretches out giving plenty of room for playing.  Trees
spring up here and there giving shade for the weary traveler. The
path divides here, heading west you see the playground closer while
the south path heads towards the hill.
End
    );
    set("item_desc", ([
      "trees":"Large and majestic, the trees tower over the area.\n",
      "tree":"There are so many none stand out in particular.\n",
      "path":"A paved path that winds towards the west and the south.\n",
      "grass":"The green grass looks fun to play on.\n",
      "shade":"By the trees there is some shade from the sun.\n",
      "playground":"It looks big, you should take a closer look.\n",
      "hill":"A hill off to the southeast.\n",
    ]));
    set("smell", "The fresh cut grass smell permeates the air.\n");
    set("exits", ([
      "east" : M_ROOM+"park1.c",
      "west" : M_ROOM+"path2.c",
      "south": M_ROOM+"hillpath1.c",
    ]));
}

void init () {
    add_action("play","play");
}
int play (string str) {

    // if str == "on grass" && this_player()->query("all_inventory") == "boots") {
    // 2 errors: forgot the leading ( and "all_inventory()" returns
    // the total array of everything a player has - not one item.
    if (str=="on grass" && present("boots", TP)) {
	this_player()->command("unequip boots");
	write("You remove your boots and play in the grass.\n");
	say(TPN+" removes their boots and plays in the grass.\n"); 
    }
    if (str== "on grass")  {
	write ("You play around on the green grass.\n");
	say(TPN+" plays around on the green grass.\n");
    }

    else {
	write ("Play on what?\n");
    }
    return 1;
}

