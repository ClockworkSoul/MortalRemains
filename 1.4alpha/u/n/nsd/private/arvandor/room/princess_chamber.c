/*
** File: princess_chamber.c
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
    set("short", "A chamber");
    set( "long", @EndText
You are in a private chamber. It's made of bricks, and it's
in the top of a castle tower. Here you can find a king-size bed
covered with a quilt of burgundy damask. Only one window allows
you contact with the outside world. To the right side of the bed,
you find a table set for embroidery, and to the left is a big sofa.
EndText);
    set( "exits", ([
    ]) );
    set("item_desc", ([
      "window" : wrap("A rustic wooden window that allows you to look\n"+
	"outside. A river must be close, because you can hear\n"+
	"the sound of the water falls."),
      "sofa" : wrap("Big and comfortable. You can sit on it. Seems really\n"+
	"heavy to try to move it, so don't do unless you want an hernia.\n"+
	"Something is attached to one of the sofa legs. Something that seems\n"+
	"like a rope..."),
      "rope" : wrap("A long rope made of slashed blankets, tied by the\n"+
	"edges of each blanket strip. This rope can be used to 'climb down'\n"+
	"the tower from the window. But you must be careful not to be caught."),
      "bed" : wrap("A king-size pillar bed. It's blankets are made of\n"+
	"burgundy velvet, and they're protected with a burgundy damask\n"+
	"quilt. It's perfect for resting on it."),
      "table" : wrap("A small table set for embroidery. It's crowded of\n"+
	"pins, needles of all sizes, all thread colors, and some finished\n"+
	"fabrics beautifully embroidered. Some are tapestries. Their topics\n"+
	"are generally romantic, and full of enchantments."),
    ]) );
    set("listen", wrap("You're entranced by the falling sound of the \n"+
	"waterfalls, which invite you to go swim, and perhaps\n"+
	"something else...\n"));
}
void init() {
    add_action("climb_down", "climb");
    add_action("sit_on_sofa", "sit");
    add_action("rest_on_bed", "rest");
}
int climb_down (string str) {
    write(wrap(
	"You climb all the way down from the tower, using\n"+
	"a rope made of slashed blankets, and find yourself quickly\n"+
	"touching the ground with your feet. You hurry fearing someone\n"+
	"can be watching...\n"));
    say(TPN+" climbs down through the window of the tower.\n");
    this_player()->move_player(ARV_ROOM+"town.c");
    say(TPN+" touches the ground with "+POSS+" feet, and hides.\n");
    return 1;
}
int sit_on_sofa (string str) {
    write(wrap(
	"You sit on this sofa, and immediately some lustful thoughts\n"+
	"invade your mind. You feel pleasantly comfortable...\n"));
    say(TPN+" sits on the sofa and feels pleasantly comfortable.\n");
    return 1;
}
int rest_on_bed (string str)  {
    write(wrap(
	"The matress adjusts to your anatomy as you lay down.\n"+
	"It feels so comfortable you fall asleep...zzzzzzzzzzz\n"));
    say(TPN+" lays down on bed and falls asleep.\n");
    return 1;
}

/* EOF */
