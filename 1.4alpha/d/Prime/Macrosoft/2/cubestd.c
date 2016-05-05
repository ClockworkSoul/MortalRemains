/*
** FILE:    cubestd.c
** PURPOSE: The room inherited by all the cubicles on the second 
**          floor of the Macrosoft building. It has support to
**          add two random objects and their item_descs in each
**          room, and 5 times out of 6 will add a worker as well.
*/

#include "macrosoft.h"

inherit MS_STD_ROOM;

mapping descs = ([
"family pictures" : "A bunch of pretty ugly people.\n", 
"cat photos" : "Yay. Cats.\n", 
"a reptile calender" : "It's a month behind.\n",
"Dilbert cartoons" : "They give you a decent chuckle.\n",
"a few useless books" : "Nothing very interesting.\n", 
"reams of papers" : "Most are dated from months ago.\n",
"discarded floppy diskettes" : "They seem to be everywhere!\n", 
"a vast collection of pens" : "Lots of pens in random colors.\n",
"an antiquated ID badge" : "It is all worn and discolored.\n", 
"an old clock" : "It seems to have stopped running.\n", 
"a chain of paperclips" : "How...  interesting.\n",
"a big corkboard" : "Cluttered with miscellaneous crap.\n", 
"a VERY cluttered desk" : "Ick.\n",
"an old coffee mug" : "It reads: Get up, goto work, sleep...\n",
"a filing cabinet" : "It's locked. Bummer.\n",
"an old Rolodex" : "Why bother?\n",
"a battered dictionary" : "Hmm... print date, 1987. How ancient!\n",
"a big black stapler" : "A pretty standard stapler.\n",
"a name plaque" : "It reads: Cyanide was here, August 4, 1999.\n",
]);


void create() {
    int *x = ({ 0, 0 }), i;
    string str1, str2, *strs, *words;

    strs = keys(descs);
    x[0] = random(sizeof(strs));
    x[1] = x[0];
    while (x[0]==x[1]) x[1] = random(sizeof(strs));

    ::create();
    set("short", "In A Cubicle");
    set("long", wrap(
	"You have intruded into some poor schmuck's cubicle, whose "+
	"low beige walls provide a semblance of privacy while still "+
	"allowing the supervisors to keep their vulture's eyes on the "+
	"lowly employees. This particular cublicle is decorated only "+
	"by "+strs[x[0]]+" and "+strs[x[1]]+"."
      ) );

    set("item_desc", ([
      "cubicle" : "It seems more like a small earth-toned "+
      "prison cell.\n",
      "walls" : wrap("They are basically featureless, with the "+
	"exception of what the managers allowed the employees "+
	"to put up."),
      "supervisors" : "The employees seem to hide from them.\n",
      "employees" : "You feel only pity for them.\n",
    ]) );
    set("listen", ([
      "default" : wrap("You hear only the sounds of phones "+
	"ringing, keyboards tapping, and fax machines chirping."),
    ]) );
    set("smell", "It smells like an office in here.\n");

    // This loops adds the item descs of the random objects.
    for (i=1; i>=0; i--) {
	words = explode(strs[x[i]], " ");
	add("item_desc", ([ 
	  lower_case(words[(sizeof(words) - 1)]) :
	  (values(descs))[x[i]]
	]) );
}

// Clones an office worker 5 times out of 6.
if (random(6))
    set("objects", ([ "worker" : MS_MON("officewkr.c") ]) );
reset();
}

/* EOF */
