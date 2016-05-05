#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Someplace bad.");
  set( "long" , @EndText
  You have fallen into the deepest pits of Oblivion. In the backround
  you can hear the demonic laughing of hysterical creatures, utterly
  enticed that you have fallen amongst them. The walls are hot to the
  touch and them seem to be melting by the minute, however as one
  section erodes, a small man appears and shoves it all back into
  place. In one corner of the room sits a large throne, its jet-black
  frame fits rather nicely with the decor of the room. The arms of the
  throne curl up and circle nicely into the shape of a sleeping dragon.
  On the seat of the throne is a large pillow, its dark red color
  reminds you of blood. On the walls there are heads, seven of them
  all in different positions of pain and anguish, it looks as if
  who ever cut them off wanted to savor the moment.

EndText
  );
  set( "exits", ([
    "pray" : "/u/d/dilligaf/workroom.c",
  ]) );
  set("item_desc" , ([
    "walls" : "They seem to be bleeding.\n",
    "pillow" : "Its not a pillow....its a sack full of blood.\n",
    "throne" : "I wouldn't want to sit on the thing.\n",
    "head" : "There are signs under each one.\n",
    "heads" : "There are signs under each one.\n",
    "dragon" : "It looks as if it is sleeping.\n",
    "sign" : "Which sign?\n",
    "signs" : "Which sign?\n",
    "man" : "A small man, though on closer inspection he seems to\n"+
    "have a strange protrusion...sort of like a tail.\n",
    "sack" : "You wonder if it is comfortable, so you sit on it...\n",
    "sign 1" : "'Gluttony' the sign reads under the face of a very\n"+
    "large man whose fat rolls down the side of his face like silly\n"+
    "putty.\n",
    "sign 2" : "'Envy' the sign reads under the face of a man who\n"+
    "looked as if he had nothing.\n",
    "sign 3" : "'Sloth' the sign reads under the head of a Union\n"+
    "Worker.\n",
    "sign 4" : "'Lust' the sign reads under the head of a man who's\n"+
    "eyes follow you strangely around the room.\n",
    "sign 5" : "'Greed' the sign reads under the head of a man with\n"+
    "what looks to be gold coins stuffed into his gaping mouth.\n",
    "sign 6" : "'Wrath' the sign reads under the head of a man whose\n"+
    "face is contorted in anger.\n",
    "sign 7" : "'Pride' the sign reads under the head of a man who\n"+
    "seems to shine with an unholy light.\n",
  ]));
}
