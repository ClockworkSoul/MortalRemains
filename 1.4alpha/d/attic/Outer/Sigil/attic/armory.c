#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
         ::create();
        	seteuid(getuid());
	reset();
     set ("light", 1) ;
     set ("long",
"You are in Armory of Sigil\n"+
"Where you can buy weapons and armor\n"+
"There is a sign on the wall.\n") ;
  set("short", "Armory.") ;
     set ("exits", ([
       "up" : SIGIL+"armory2.c",
     "east" : SIGIL+"petitionerst2.c" ]) ) ;
set("item_desc" , ([
    "sign" : "\n"+
    "                         -={    Armory     }=-\n"+
    "\n"+
    "                                Weapons\n"+
    "          Sword.......................................15 coins\n"+
    "          Axe..........................................5 coins\n"+
    "          Two Handed Sword............................50 coins\n"+
    "          Mace.........................................8 coins\n"+
    "          Shortsword..................................10 coins\n"+
    "          Staff........................................1 coin\n"+
    "          Dagger.......................................2 coins\n"+
    "          Halberd.....................................10 coins\n"+
    "\n"+
    "                                 Armor\n"+
    "          Chainmail...................................75 coins\n"+
    "          Platemail..................................600 coins\n"+
    "          Shield.......................................7 coins\n"+
    "                                  No Returns.\n",
   ]) );
                    
	}
void init(){
 add_action("buy_func", "buy");   
 
 }
 
 int buy_func(string str){
 
 object ob;
 int cost, wealth, notsold;
 
  if (!str) {
 write("Buy what?.\n");
 return 1;
 }
	wealth = this_player()->query("wealth");
  switch (str) {
  case "sword" : cost = 15;break;
  case "two handed sword" : cost = 50;break;
  case "mace" : cost = 8;break;
  case "axe" : cost = 5;break;
  case "dagger" : cost = 2;break;
  case "staff" : cost = 1;break;
  case "chainmail" : cost = 75;break;
  case "platemail" : cost = 600;break;
  case "shield" : cost = 7;break;
  case "halberd" : cost = 10;break;
  case "shortsword" : cost = 10;break;
  default : notsold = 1;
  }
  if (notsold){
write("We don't sell any of those, read the sign berk!\n");
return 1;
}
if (wealth < cost){
	write("You don't have enough money for that!\n");
	return 1;
	}

switch (str){
case "sword" : ob = clone_object("/obj/weapon/sword.c");break;
  case "two handed sword" : ob = clone_object("/obj/weapon/2hsword.c");break;
  case "axe" : ob = clone_object("/obj/weapon/battleaxe.c");break;
  case "mace" : ob = clone_object("/obj/weapon/mace.c");break;
  case "dagger" : ob = clone_object("/obj/weapon/dagger.c");break;
  case "staff" : ob = clone_object("/obj/weapon/staff.c");break;
  case "halberd" : ob = clone_object("/obj/weapon/halberd.c");break;
  case "shortsword" : ob = clone_object("/obj/weapon/shortsword.c");break;
  case "chainmail" : ob = clone_object("/obj/armor/chainmail.c");break;
  case "platemail" : ob = clone_object("/obj/armor/platemail.c");break;
  case "shield" : ob = clone_object("/obj/armor/shield.c");break;
  default : notsold = 1;
  }
 if (notsold){
write("We gots an anomoly berk!\n");
return 1; 
}
ob->move(this_player());
this_player()->debit(cost);
write("You pay "+cost+" coins for a "+str+".\n");
return 1;
}
