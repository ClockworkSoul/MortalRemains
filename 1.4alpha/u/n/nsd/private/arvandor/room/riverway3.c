/*
** File: riverway3.c
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
    set("short", "Dense Forest");
    set( "long", @EndText
The rainbow continues to the southwest. The sounds of
the waterfalls are stronger. A cold breeze caresses your
face as you advance. You can see some toadstools at the
feet of the trees. And the grass is lightly moistened.
EndText);
    set( "exits", ([
      "west" : ARV_ROOM+"riverway2.c",
      "southwest" : ARV_ROOM+"riverway4.c",
      "east" : ARV_ROOM+"seeliecourt1.c",
    ]) );
    set("item_desc", ([
      "rainbow" : wrap(
	"The rainbow grows brighter as you advance. The crystal\n"+
	"butterflies glow in different colors as their wings make\n"+
	"contact with the light of the rainbow..."),
      "grass" : wrap(
	"Deep green grass lightly moistened with fresh water.\n"+
	"Same way you feel few cold water drops bathing your\n"+
	"face..."),
      "trees" : wrap(
	"Broad pine trees full of branches. At the feet of them\n"+
	"you find some toadstools."),
      "toadstools" : wrap(
	"Cute mushrooms bigger than normal. They seem to be the home\n"+
	"for some forest creatures. You're so curious you want to\n"+
	"'search' the 'toadstools'."),
    ]) );
    set("listen", wrap(
	"You hear wind chimes, and a low singing voice that\n"+
	"humms a sweet melody. It's a female voice. The humm\n"+
	"mixes with the entrancing sound of the cascade...\n"));
}
void init() {
    add_action("search_toadstools", "search");
}
int search_toadstools(string str) {
    if(!str || str!="toadstools") {
	write("What do you want to search?\n");
	return 1;
    }
    say(wrap(
	TPN+" searches the toadstools, and an angry dwarf bites\n"+
	""+POSS+" hand. Then the dwarf hangs a sign that reads\n"+
	"'DO NOT DISTURB!!'."));
    write(wrap(
	"You search the toadstools, and an angry dwarf bites your\n"+
	"hand. Then the dwarf hangs a sign that reads 'DO NOT DISTURB!!'."));
    return 1;
}

/* EOF */
