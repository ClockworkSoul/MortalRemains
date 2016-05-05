/*
** File: pathway.c
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
You're in the middle of the Village. Peasants of all races
come here to buy some food among other things. To the west
is the castle tower. To the north is the gate that conducts
you out of the village.
EndText);
    set( "exits", ([
      "west" : ARV_ROOM+"town.c",
      "north" : ARV_ROOM+"gate.c",
    ]) );
    set("item_desc", ([
      "peasants" : "Just peasants walking by.\n",
      "tower" : "Not from here. You have to go west.\n",
      "gate" : "Not from here. You have to go north.\n",
      "merchants" : wrap(
	"They're selling fruits, vegetables, chickens... all kinds\n"+
	"of food."),
      "fruits" : "Recently picked fruits. They look yummy.\n",
      "vegetables" : "Fresh vegetables. The best of the harvest.\n",
      "chickens" : wrap(
	"Noisy chickens that can be used to fix a delicious dinner."),
    ]) );
    set("listen", wrap(
	"Whispers, gossips, songs... All the normal noise of a\n"+
	"crowd. But still the cascade sounds stronger...\n"));
}

/* EOF */
