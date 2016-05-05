/*
** File: riverway2.c
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
The rainbow continues to the east. The sounds of
the waterfalls are stronger, giving you the hint
of being almost there. Passion invades your
nostrills... you don't wanna leave...
EndText
    );
    set( "exits", ([
      "north" : ARV_ROOM+"riverway.c",
      "east" : ARV_ROOM+"riverway3.c",
    ]) );
    set("item_desc", ([
      "rainbow" : wrap(
	"The rainbow grows brighter as you advance. The crystal\n"+
	"butterflies glow in different colors as their wings make\n"+
	"contact with the light of the rainbow..."),
    ]) );
    set("listen", wrap(
	"Birds humming, wind chimes, and water sounds...\n"+
	"Certainly this forest is enchanted. And the entrancing\n"+
	"sound of the cascade that haven't ceased, but grown\n"+
	"louder, keeps you hypnotized...\n"));
}

/* EOF */
