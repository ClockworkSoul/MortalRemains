/*
** Hp room
** based upon  ilz code
*/




#include <daemons.h>
#include <mudlib.h>
#include <c_deathdealer.h>
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>
#include "/adm/daemons/propertyd.c"
#include "/d/Outer/Sigil/sigil.h"
inherit GUILD;

void create() {
  ::create();
  seteuid(getuid());
   set( "light", 1 );
set("short","Pit of Flame");
  set( "long", @EndText
For a fee the Demons of the plane will allow you to bathe
in the purifying waters of the pit of flame.
Commands: < bathe >
EndText
  );
  set( "exits", ([
"up" : "/d/Outer/Baator/pit8.c",
  ]) );
 
}

void init(){
::init();
add_action("joinhero","join");
add_action("advance","advance
");
add_action("raise_hp", "bathe");
}

int raise_hp(){
string statr;
int lvl, xp, conb, hp, hpmax;

switch (TP->query_class()){
	case "wizard" : hp = 12;break;
	case "rogue" : hp = 18;break;
	case "priest" : hp = 24;break;
	case "warrior" :
		if (TP->query_level("barbarian")){
		hp = 36;
		}else{
		hp = 30;
		};break;
	default : hp = 30;break;
	}

conb = PROPERTY_D->query_con_hp_bonus(this_player());

hpmax = (TP->query_level())*(hp + conb);

if (TP->query("max_hp") > hpmax){
	write("You Have been purified enough mortal!,\n"+
	"Come back when you are more experienced!\n");
	return 1;
	}

if (!TP->debit(1000000)){
	write("You fail to pay the required 1000000 coins.\n");
	return 1;
	}
TP->set("experience", (TP->query("experience") - 100000));
 add_hp(TP, (1 - conb));
 return 1;
}



int joinhero() {
 
    write("This aint no guild!\n");
    return 0;
  }


int advance() {

    write("This aint no guild!\n");
    return 0;
  }
