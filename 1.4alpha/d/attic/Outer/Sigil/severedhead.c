#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
         ::create();
        	seteuid(getuid());
	reset();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand in the Severed Head Armory in the town of Sigil, home to the
world-reknown Green Steel Weaponry.  The burly shopkeeper throws you 
a toothless smile as you look around.

A large sign behind the counter details what armours are available.
ENDLONG
  );
  set("short", "The Severed Head Armory.");
  set("item_desc", ([
   "sign" : "You could read it.\n",
  "counter" : "There's nothing interesting about the counter.\n",
  "man" : "He's a burly man, smudged with dirt and sweat.\n",
  "shopkeeper" : "He's a burly man, smudged with dirt and sweat.\n",
  ]) ) ;
     set ("exits", ([
	"west" : SIGIL+"turtlest1.c"]));
	}

int read(string str) {
  if (!str) {
    write("Read what?\n") ;
    return 1;
  }
  if (str == "sign") {
   write(@ENDSIGN
The sign reads:

  All of the following equipment is for sale here:

Sword.......................................45 coins
Shortsword..................................30 coins
Axe.........................................15 coins
Mace........................................24 coins
Dagger.......................................6 coins
Chain armor................................225 coins

             No Returns!  No Exceptions!

Commands are: buy <equipment>
ENDSIGN
  );
  say(TPN+" reads the sign.\n");
  return 1;
 } else return 0 ;
}
void init(){
  add_action("read", "read") ;
 add_action("buy_func", "buy");   
 
 }
 
 void buy_func(string str){
 
 object ob;
 int cost, wealth;
 
  if (!str) {
 write("Buy what?.\n");
 return;
 }
	wealth = this_player()->query("wealth");
  switch (str) {
  case "sword" : cost = 45;
  if (this_player()->query("wealth")<cost){
  	write("You don't have enough cash for that!\n");
  	return 1;
  	}
  	this_player()->debit(cost);
  ob = clone_object ("/d/Outer/Sigil/items/greensword") ;
  ob->move(this_player()); 
  write ("You buy a green steel "+str+".\n");
   say(TPN+" buys a green steel "+str+".\n");
   break;
  case "shortsword" : cost = 30;
  if (this_player()->query("wealth")<cost){
  	write("You don't have enough cash for that!\n");
  	return 1;
  	}
  	this_player()->debit(cost);
  ob = clone_object ("/d/Outer/Sigil/items/greenshortsword") ;
  ob->move(this_player()); 
  write ("You buy a green steel "+str+".\n");
   say(TPN+" buys a green steel "+str+".\n");
   break;
 case "dagger" : cost = 6;
 if (this_player()->query("wealth")<cost){
  	write("You don't have enough cash for that!\n");
  	return 1;
  	}
  		this_player()->debit(cost);
 ob = clone_object ("/d/Outer/Sigil/items/greendagger") ;
 ob->move(this_player()); 
  write ("You buy a green steel "+str+".\n");
   say(TPN+" buys a green steel "+str+".\n");
    break;
 case "mace" : cost = 24;
 if (this_player()->query("wealth")<cost){
  	write("You don't have enough cash for that!\n");
  	return 1;
  	}
  		this_player()->debit(cost);
 ob = clone_object ("/d/Outer/Sigil/items/greenmace") ;
 ob->move(this_player()); 
  write ("You buy a green steel "+str+".\n");
   say(TPN+" buys a green steel "+str+".\n");
    break;
 case "axe" : cost = 15;
 if (this_player()->query("wealth")<cost){
  	write("You don't have enough cash for that!\n");
  	return 1;
  	}
  		this_player()->debit(cost);
 ob = clone_object ("/d/Outer/Sigil/items/greenaxe") ;
 ob->move(this_player()); 
  write ("You buy a green steel "+str+".\n");
   say(TPN+" buys a green steel "+str+".\n");
    break;
 case "chain" : cost = 225;
 if (this_player()->query("wealth")<cost){
  	write("You don't have enough cash for that!\n");
  	return 1;
  	}
  		this_player()->debit(cost);
 ob = clone_object ("/d/Outer/Sigil/items/greenchain") ;
 ob->move(this_player()); 
  write ("You buy a green steel "+str+".\n");
   say(TPN+" buys a green steel "+str+".\n");
    break; 
 default : write ("What did you want to buy?\n"); break;
 return;
 }
return 1;
}
