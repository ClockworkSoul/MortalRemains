/*
** File: riverway4.c
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
the waterfalls are stronger. The cold breeze that
caresses your face has now tiny cold water drops.
An old oak tree stands between the pine trees.
The grass is moistened and fresh. You feel the passion
that this place inspires...
EndText);
    set( "exits", ([
      "northeast" : ARV_ROOM+"riverway3.c",
      "southwest" : ARV_ROOM+"cascade.c",
    ]) );
    set("item_desc", ([
      "rainbow" : wrap(
	"The rainbow grows brighter as you advance. The crystal\n"+
	"butterflies glow in different colors as their wings make\n"+
	"contact with the light of the rainbow..."),
      "grass" : "Fully moistened by the water drops of the cascade.\n",
      "oak tree" : wrap(
	"An old oak tree, which is rare to find in a place like this.\n"+
	"If you look closer, you'll see it has a 'hole'."),
      "hole" : "Seems empty, but if you 'search' it, you can find something.\n",
    ]) );
    set("listen", wrap(
	"You close your eyes for a moment, and hear the humming\n"+
	"voice echoing ghostly, and fade away with the imponent\n"+
	"sound of the waterfalls...\n"));
}
void init() {
    add_action("search_hole", "search");
}
int search_hole(string str) {
    object faerie;
    if (!present("faerie", this_object() )) {
	for(int i = 0;i<8;i++) {
	    faerie = clone_object(ARV_MON+"faerie.c");
	    faerie->move(this_object() );
	}
	write("You search the hole, and a bunch of faeries fly out.\n");
	say(wrap(
	    "As "+TPN+" searches the hole, a bunch of faeries fly out\n"+
	    "towards "+ objective(TP->query("gender"))+"!"));
	return 1;
    }
}
/* EOF */
