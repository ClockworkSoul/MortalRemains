#include "../Prime.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  seteuid(getuid());  // need this line if your gonna clone anything.
  set ("outside", "Dark");
  set( "light", 1 );
  set ("short", "The City Center");
  set( "long", @EndText
This is the city's marketplace, the very heart of Darkmir. Here most
of the major transactions take place, whether legal or not, and 
carts and booths sell a variety of wares. In the very center of the
marketplace, avoided by all, is a raised wooden platform - upon which
is a skeletal-looking gallows.
EndText
  );
  set ("author", "cyanide");
  set( "exits", ([
    "north" : D_PRIMER+"/road0'1.c",
    "south" : D_PRIMER+"/road0'-1.c",
    "east" : D_PRIMER+"/road1'0.c",
    "west" : D_PRIMER+"/road-1'0.c",
  ]) );
  ::create(); // this also resets the room! :)
  set_items( ([
    "marketplace" : "There are vendors everywhere, but they seem to shun "+
      "the gallows.\n",
    "wares" : "Hmm... nothing interesting.\n",
    "platform" : "It seems quite old, but it is still very sturdy.\n"+
      "There is a wooden gallows upon it.\n",
    "gallows" : "The sudden image of you in the noose fills you mind.\n"+
      "The sensation threatens to overwhelm you.\n",
    ({ "carts", "booths", "vendors" }) :
      "They offer a variety of wares, from pottery to fruits and vegetables.\n",
   ]) );
  set ("smell", ([
    "marketplace" : "How do you propose to do that?\n",
    "carts" : "Why bother?\n",
    "booths" : "Why bother?\n",
    "vendors" : "The may not appreciate that.\n",
    "wares" : "Why bother?\n",
    "platform" : "It smells likle old hardwood and blood.\n",
    "gallows" : "You can't do that from here.\n",
    "default" : "The dank smells of stagnant water and smoke overcome you.\n",
 ]) );
  set ("listen", ([
    "marketplace" : "It seems unusually quiet for a marketplace...\n",
    "vendors" : "They hawk their wares loudly.\n",
    "default" : "It seems unusually quiet here, with the exception of "+
      "the occasional guard\nbeating a supposed \"criminal\".\n",
  ]) );
  set ("search_desc", ([
    "marketplace" : "That would take a small army hours of work.\n",
    "carts" : "You don't find them very interesting.\n",
    "vendors" : "They may not appreciate that.\n",
    "booths" : "You don't find them very interesting.\n",
    "platform" : "You could probably climb up to it.\n",
    "gallows" : "You can't search that from here.\n",
 ]) );
}

