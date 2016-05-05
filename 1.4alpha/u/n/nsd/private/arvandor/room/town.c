/*
** File: town.c
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
    set("short", "Village Town");
    set( "long", @EndText
You're in the Village Town down from the tower. Here you
can see some peasants walking by, and some merchants selling
vegetables, chickens, fruits, ...all kinds of food. Also a
few buffoons doing their acrobatic acts. Seems like a
celebration is taking place here. But the sound of the
waterfalls calls you...
EndText );
    set( "exits", ([
      "east" : ARV_ROOM+"pathway.c",
    ]) );
    set("item_desc", ([
      "tower" : wrap(
	"A castle tower made of bricks. You can see a window at the\n"+
	"top of it. Something seems to hang from that window and it's\n"+
	"hidden behind the bushes that border the tower."),
      "bushes" : wrap(
	"Small bushes that border the tower. They're perfect for\n"+
	"hiding evidence of escape from the tower. Looking carefully,\n"+
	"you'll find a rope within the bushes."),
      "rope" : wrap(
	"A long rope made of slashed blankets tied by the edges of\n"+
	"each strip. Seems strong enough to 'climb up'."),
      "peasants" : "Just peasants walking by.\n",
      "merchants" : wrap(
	"They're selling fruits, vegetables, chickens... all kinds\n"+
	"of food."),
      "buffoons" : wrap(
	"Funny buffoons making their acrobatic acts."),
      "fruits" : "Recently picked fruits. They look yummy.\n",
      "vegetables" : "Fresh vegetables. The best of the harvest.\n",
      "chickens" : wrap(
	"Noisy chickens that can be used to fix a delicious dinner."),
    ]) );
    set("listen", wrap(
	"Too much noise of people's gossips and whispers. But the\n"+
	"entrancing sound of the waterfalls is louder. You really\n"+
	"have the need of finding it, for you're hipnotized...\n"));
}
void init() {
    add_action("climb_up", "climb");
}
int climb_up(string str) {
    write(wrap(
	"You grab the blanket rope, and start to climb up the tower\n"+
	"walls to go back to your chamber. You enter through the\n"+
	"window, and pull the rope to you in order to hide the\n"+
	"escaping evidence...\n") );
    say(TPN+" climbs up the tower wall through a rope.\n");
    this_player()->move_player(ARV_ROOM+"princess_chamber.c");
    say(TPN+" enters through the window and hides the rope quickly.\n");
    return 1;
}

/* EOF */
