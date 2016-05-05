#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "tarholt" : "/d/Outer/Sigil/monsters/tarholt" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
The Sigil Foundry is a large weapon-smithing shop.  For those of you
who are skilled in the ways of Weaponsmithing, you could smith an
object here.. for a price.

Commands are: smith <object>
ENDLONG
  ) ;
  set("short", "The Sigil Foundry.") ;
     set ("exits", ([
     	"north" : SIGIL+"foundry1.c",
     	"south"	: SIGIL+"mainst17.c" ]) ) ;
}
void init(){
 add_action("smith_func", "smith");   
 
 }
 
 void smith_func(string str){
 
	int hit, dmg, l, res, value ;
	object ob;

if (!TP->query_skill("Weaponsmithing")){
	notify_fail("You need to have the weaponsmithing skill first!\n") ;
		return 0 ;
	}


	if (!str) {
		notify_fail("What do you want to smith?\n") ;
		return 0 ;
	}

	
	ob = present(str,this_player()) ;
	if (!ob) {
		notify_fail("You don't have one to smith!\n") ;
		return 0 ;
	}
	if (!ob->query("weapon")){
		notify_fail("That isnt a weapon!\n") ;
		return 0 ;
	}
	if (ob->query("reforged")){
	notify_fail("That weapon has already been tampered with!\n") ;
		return 0 ;
	}

	//this is what figures out how good u are and what bonus u will get.
	value = (random(20)+1) + (TP->query_level()/10) + (TP->query("stat/intelligence")/6);
	
	switch(value){
	case -20..7 : hit = -1;dmg = -1;break;
	case 8..10 : hit = 0;dmg = 0;break;
	case 11..16 : hit = 1;dmg = 0;break;
	case 17..20 : hit = 0;dmg = 1;break;
	default : hit = 1;dmg = 1;
	}
   if (!TP->debit(TP->query_level() * 100)) {
     write("You can't afford the "+TP->query_level()*100 +
    " coins it costs to use the foundry rihgt now.\n") ;
    return 1;
   }
res = ob->query("enchantment");
hit += ob->query("to_hit_adj");
dmg += ob->query("dam_adj");
ob->set_bonus(res, hit, dmg);
ob->set("reforged", 1);
	write("You smith the weapon to the best of your ability.\n");
	say(TPN+" re-forges a "+ob->query("name")+".\n");
	return 1 ;
}
