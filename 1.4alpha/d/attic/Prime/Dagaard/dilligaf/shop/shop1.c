#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "A small parlor");
  set( "long" , @EndText
  You stand inside of a small parlor, the amber hues of this room give
  you the feeling of instant peace and sanctuary. Red drapes hang
  sullenly over the windows letting in just a little sun. Over on the 
  west wall there is a booth with a small bell on the table next to
  it. On the floor are som of the most exquisit rugs that you have
  ever seen, intricate details and meticulous stiching tell you that
  these rugs are worth a fortune.

EndText
  );
  set( "exits", ([
    "north" : STREET+"street4.c",
    "south" : SHOPS+"shop2.c",
  ]) );
  set("item_desc" , ([
    "drapes" : "Red drapes shielding the inside of the room from\n"+
    "the sun.\n",
    "windows" : "You can see the street and all of the people that\n"+
    "are milling about. Its funny because you don't remember\n"+
    "seeing any windows on the outside.\n",
    "booth" : "A small booth where the clerk sits.\n",
    "bell" : "Try ringing it.\n",
    "rugs" : "Well designed rugs, they seem to be worth quite a bit.\n",
    "details" : "You notice that there is a loose thread in the\n"+
    "stiching.\n",
    "thread" : "Maybe you could pull it. But do you want to?\n",
  ]));
}
