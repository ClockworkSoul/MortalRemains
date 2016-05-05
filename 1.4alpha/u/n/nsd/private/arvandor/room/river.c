/*
** File: river.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Nimph river");
    set( "long", @EndText
You're at the Nimph river. Here the birds sing
their sweet melodies. All around the river you
can see the evergreen pine trees. There's a big
rock in the middle of the water, in which you can
lay down. The water looks temptingly inviting.
'enter' the 'water' and enjoy it...
EndText);
    set( "exits", ([
      "rockpath" : ARV_ROOM+"cascade.c",
    ]) );
    set("item_desc", ([
      "trees" : "Evergreen pine trees. Here they grow broad and healthy.\n",
      "river" : "Really calmed. The water invites you to 'get into' it.\n",
      "rock" : "Seems big from where you are. To go there, type 'rock'.\n",
    ]) );
    set("listen", wrap(
      ));
}
void init () {
    add_action("enter_water", "enter");
    add_action("rock", "rock");
    add_action("swim", "swim");
}
int enter_water (string str) {
    say(TPN+" cringes at the contact with the cold river water.\n");
    write(wrap(
	"yaeeeiii!!! the water is too cold. You blush when you\n"+
	"notice the phisical reaction it causes you. Well, now\n"+
	"you're adapted to it's coldness. You're ready to 'swim'.\n"));
    return 1;
}
int rock(string str) {
    write(
      "You swim to the rock...\n");
    say(TPN+" swims to the rock ...\n");
    this_player()->move_player(ARV_ROOM+"rock.c");
    say(TPN+" has followed you to the rock.\n");
    return 1;
}
int swim(string str) {
    say(TPN+" swims in the river waters. \n");
    write(wrap(
	"You're swimming in the river, and will stay there\n"+
	"a little longer till you make sure no one is watching.\n"+
	"You're ashamed of the reaction your body had with the\n"+
	"cold water...\n"));
    return 1;
}

/* EOF */
