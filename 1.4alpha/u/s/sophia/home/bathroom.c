#include "sophia.h"
inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set( "author", "sophia");
set( "short", "Sophia's bath room" );
set("long", wrap(
"You stumble slightly as you come through the hidden door but "+
"you are soon entranced with the softness of the mossy floor "+
"and the quiet trickle of water down a stone wall into a "+
"largish tub. Soft towels and various small bottles sit on a table "+
"near a large soft lounge chair. "
) );
  set( "exits", ([
"door" : HOME+"bedroom2.c"
]) );
set( "item_desc", ([
"floor" : wrap("Thick green moss has grown together to form a "+
"soft carpet under your feet. Sophia oftens walks here just to feel "+
"the coolness under her bare feet. "),
"wall" : wrap("A wall of indigenous stone probably makes Sophia "+
"feel safe and secure when she bathes at the base of it. Water trickles "+
"down it from a warm spring. "),
"tub" : wrap("Seemingly carved by the natural action of the spring "+
"flowing into it, this tub is large and smooth. You ponder if "+
"it was carved here after the house or the house built around it? "),
"water" : wrap("Directly from a warm mineral spring, it looks so "+
"good it occurs to you to ask Sophia if you may soak "+
"your weary bones. "),
"bottles" : wrap("Small bottle of essential oils for massage "+
"or pouring in the bath; a different one for most moods. "),
"table" : wrap("A small table to hold oils on a tray or to sit "+
"on to talk with Sophia while you wait for her to finish "+
"her bath. "),
"chair" : wrap("A moss green velvet lounge chair to just "+
"lay back and relax in. "),
"towels" : wrap("Very large and soft sage green towels are "+
"stacked here. They are monogrammed..ah a clue to "+
"Sophia's private life! "),
"monogram" : wrap("A beautifully stitched monogram in gold thread. "+
"You sigh as you realize it is in an ancient elven script that "+
"you cannot read. "),
]) );
}
