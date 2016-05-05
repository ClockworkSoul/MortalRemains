#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"This is The Barracks of The Harmonium.\n"+
"There is some equipment and a small forge here to optimize armor\n"+
"Type optimize <armor>\n");
  set("short", "Barracks.") ;
     set ("exits", ([
	"up" : SIGIL+"barracks1.c",
	"west" : SIGIL+"ladyst2.c"]));
}
void init(){
 add_action("smith_func", "optimize");   
 
 }
 
 void smith_func(string str){
 
	int hit, dmg, l, res, value ;
	object ob;

if (!TP->query_skill("Armorer")){
	notify_fail("You need to have the armorer skill first!\n") ;
		return 0 ;
	}


	if (!str) {
		notify_fail("What do you want to optimize?\n") ;
		return 0 ;
	}

	
	ob = present(str,this_player()) ;
	if (!ob) {
		notify_fail("You don't have one to optimize!\n") ;
		return 0 ;
	}
	if (!ob->query("armor_object")){
		notify_fail("That isnt armor!\n") ;
		return 0 ;
	}
if (!ob->query("armor")){
		notify_fail("You can only optimize physical armor!\n") ;
		return 0 ;
	}
	if (ob->query("reforged")){
	notify_fail("That armor has already been optimized!\n") ;
		return 0 ;
	}

	//this is what figures out how good u are and what bonus u will get.
	value = (random(20)+1) + (TP->query_level()/10) + (TP->query("stat/strength")/6);
	
	switch(value){
	case -20..7 : hit = -1;dmg = 120;break;
	case 8..10 : hit = 0;dmg = 100;break;
	case 11..16 : hit = 0;dmg = 80;break;
	case 17..20 : hit = 1;dmg = 70;break;
	default : hit = 2;dmg = 60;
	}

hit += ob->query("armor");
dmg = ((ob->query("mass") * dmg)/100);
ob->set("mass", dmg);
ob->set("armor", hit);
ob->set("reforged", 1);
	write("You optimize the armor to the best of your ability.\n");
	say(TPN+" re-forges a "+ob->query("name")+".\n");
	return 1 ;
}
