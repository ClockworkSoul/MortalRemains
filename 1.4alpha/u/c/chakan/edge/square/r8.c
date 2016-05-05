#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
set( "short", "North end of square" );
  set( "long", @EndText
The great hourglass-shaped tower overshadows this portion of the 
town square. The streets appear to be well-kept here, made of brick 
laid down to create a solid walkway for travelers.  Directly south is 
one of the supporting towers for the main structure, surrounded by a 
flower garden on the ground level.  To the east and west are skywalks 
reaching from the main tower to other buildings on the outside of the 
town square.
EndText
);
  set( "exits", ([
	"northwest" : "/u/c/chakan/edge/inn/entrance.c",
	"northeast" : "/u/c/chakan/edge/square/r1.c",
	"southwest" : "/u/c/chakan/edge/square/r7.c",
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
"There are three support towers visible from here.  One directly south\n"+
"and one to the southeast and to the southwest.  Each are huge in their\n"+
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
"streets in the city, which are made of packed dirt.  You also notice\n"+
"that there is a small grate at your feet, indicating that this city\n"+
"must be built with a sewer system of some sort.\n",
	"skywalk" :
"The two skywalks visible from this angle go from the main hourglass\n"+
"tower to the Journeyman's Guild and the other to the Sacred Feather Inn.\n"+
"Each skywalk is about fifteen feet off the ground and seems to be very\n"+
"well-built.\n",
     ]) );

}
