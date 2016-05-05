#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
inherit DOORS;
object maker;
object ob1;
int got = 0;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "The library");
  set( "long" , @EndText
  You walk into this room and find that you are in the library. There
  are shelves and shelves of books everywhere. Books are strewn all
  around here, all neatly arranged in small piles on the floor. In the
  middle of the room is a large book laying on a desk. There are some
  paintings along the east wall, and a large senic window on the north
  wall. Soft light comes from the candles up above you.

EndText
  );
  set( "exits", ([
    "west" : KEEP+"keep2.c",
  ]) );
  set("item_desc" , ([
    "candles" : "They seem to be magikal. As the wax melts it dissapears and reforms as part of the candle. They never go out.\n",
    "wax" : "It dissapears and reforms as part of the candle.\n",
    "ceiling" : "Its WAY up there.\n",
    "book" : "A large book, 'Skeletons' is the title.\n",
    "desk" : "A small desk with a few papers on it.\n",
    "papers" : "You have no idea what language they are written in.\n",
    "books" : "They are everywhere.\n",
    "piles" : "Piles of books.\n",
    "paintings" : "There is a large canvas painting of what seems to be Lord Soth in battle with a large two headed Firbolg.\n",
    "painting" : "There is a large canvas painting of what seems to be Lord Soth in battle with a large two headed Firbolg.\n",
    "window" : "You get a panoramic view of the courtyard with all its burnt grass.\n",
    "courtyard" : "Has it been that long since you were there?\n",
    "grass" : "Its just as burnt as when you came in.\n",
    "shelves" : "They are covered in books, someone in here likes to read, or at least did at one point.\n",
    "soth" : "Lord Soth in heated combat.\n",
    "firbolg" : "A member of the giant family, though you have never heard of a two headed one.\n",
  ]));
  create_door("west","east","A large set of double doors","closed","");
reset();
}
void init(){
  add_action("get_func" , "get");
}
int get_func(string str){
  if(!str){
    write("What would you like to get?\n");
  return 1; }
   if(str == "book"){
  if(got==0){
    write("As you pick the book up, it dissapears and you hold a key in you hand. The book then reappears back on the table.\n");
    say(TPN+" picks up the book and it vanishes, only to reappear on the table.\n");
    ob1 = clone_object("/d/Prime/Dagaard/dilligaf/keys/skeleton_key.c");
    ob1->move(this_player() );
   got = 1;
    } else {
    write("Someone already has taken the key.\n");
    }
    return 1; }
  return 0;
}
