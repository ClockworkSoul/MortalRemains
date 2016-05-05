#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
set( "short", "Northeast end of square" );
  set( "long", @EndText
Standing underneith the skywalk connecting the Traveller's Guild to
your northeast and the hourglass tower to the southwest, you notice
that it is very calm here on the town square.  People are busy 
moving back and forth, but there is little comotion.  The street is
well kept and the garden up against the tower has a beautiful array
of flowers.
EndText
);
  set( "exits", ([
	"northwest" : "/u/c/chakan/edge/square/r1.c",
	"northeast" : "/u/c/chakan/edge/city/travelers.c",
	"southeast" : "/u/c/chakan/edge/square/r3.c",
  ]) );

       set ("item_desc", ([ 
"garden" : "A rich-soiled flower bed surrounds the tower.  There is a\n"+
"wide variety of botanical pleasures here, from lilacs to daisies.\n",
"main tower"  :  "The main tower is in the shape of an hourglass and reaches\n"+
"a good five hundred feet into the air.  It seems to be made of\n"+
"solid grey stone--as there are no seems in the masonary.  There\n"+
"are several barred windows from top to bottom and it appears\n"+
"as though there is an observation deck at the exact middle floor\n"+
"which allows people to look out across the city.\n",
"towers"  :
"There are two support towers visible from this angle.  One to the west\n"+
"and one directly south.  Each support tower is huge in their\n"+
"own right, about twenty-five feet in diameter.  They are made of a\n"+
"greyish stone and don't seem to have any seams where the rock has\n"+
"been laid together, as if they are each a giant solid stone cylinder\n"+
"rising hundreds of feet into the sky.\n",
	"brick" : 
"The red brick street is somewhat uneven, as if a great amount\n"+
"of traveling is done on them and they have already worn down.\n"+
"Perhaps the ground here is not the greatest foundation.  It is\n"+
"a wonder that the enormous tower still stands\n",
	"street" :
"The street is constructed of a red brick laid down to make a strong\n"+
"road for travelers to walk on.  It is much nicer than most of the\n"+
"streets in the city, which are made of packed dirt.\n",
	"skywalk" :
"From this vantage point, the skywalks look very well constructed,\n"+
"perhaps even of dwarven make.  With closer inspection, you notice,\n"+
"that the construction is so fine that you cannot even find the\n"+
"seams in the masonry.\n",
     ]) );

}