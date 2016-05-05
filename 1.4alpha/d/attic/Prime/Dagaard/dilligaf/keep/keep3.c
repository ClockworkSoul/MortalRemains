#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;
object maker;
object ob1;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "Inside Soth's Keep [1rst Floor]");
  set( "long" , @EndText
  You are walking down an extended hallway. The intricate details in
  this place are incredible. Everything from the magikal candles, to
  the red plush rug that you walk upon. Its almost like a dream. Up
  ahead you can see the staircase, while behind you is the rest of
  the hallway, and the main door that you came in from.

EndText
  );
  set( "exits", ([
    "north" : KEEP+"keep2.c",
    "stairs" : KEEP+"keep6.c",
  ]) );
  set("item_desc" , ([
    "candles" : "They seem to be magikal. As the wax melts it dissapears and reforms as part of the candle. They never go out.\n",
    "wax" : "It dissapears and reforms as part of the candle.\n",
    "ceiling" : "Its WAY up there.\n",
    "rug" : "A nice plush red rug leading to and up the stairs.\n",
    "staircase" : "Stairs leading up.\n",
    "stairs" : "They lead up.\n",
    "door" : "You can't quite see it from here.\n",
    "hallyway" : "A giant hallway with very high ceilings.\n",
    "details" : "Its the little things, like the paintings.\n",
    "paintings" : "Which one?\n",
    "painting 1" : "This seems to be a portrait of Lord Soth and his wife. She is a stunning blond woman whose large brown eyes seem to bore right through your soul. Soth is a regal looking man who's gaze is even more powerful than his wife's.\n",
    "painting 2" : "All that remains of this canvas is the frame and a few tattered shreds of what the painting once was.\n",
    "shreds" : "You can't piece it all together.\n",
    "frame" : "A beautiful oak frame, with small engravings.\n",
    "engravings" : "Maybe if you work at it, you could decypher them.\n",
  ]));
reset();
}
void init(){
  add_action("decypher_func" , "decypher");
}
int decypher_func(string str){
  if(!str){
    write("Decypher what?\n");
  return 1; }
  if(str == "engravings"){
    write("You work and stare at the engravings and manage to peice together the phrase 'A fowl curse on you Soth, may you live your days without rest and without soul'.\n");
    say(TPN+" studies the frame for a little bit.\n");
  return 1; }
return 1;
}
