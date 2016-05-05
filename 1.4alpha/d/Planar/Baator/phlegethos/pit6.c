/*
** Hp room
** Written by Ilzarion, exploiting Cyanide's code.
** Nobody knows when.
**
** Cyanide cleaned the hell out of it, 22 Aug 1999
*/

#include <daemons.h>
#include "/u/c/cyanide/debug.h"
#include "baator.h"

#define CASH_COST 50000
#define XP_COST 20000

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set("short","Pit of Flame");
    set( "long", wrap("You stand at the edge of a great lake of "+
	"fire. Demons standing within howl and beckon to you, "+
	"temping you with the power of the purifying flames. For "+
	"a small fee of 50,000 credits and 20,000 experience "+
	"points, the demons of Baator will "+
	"allow you to <bathe> in the purifying fires of the Pit "+
	"of Flame."
      ) );
    set( "exits", ([
      "west" : BAATOR+"phlegethos/pit5.c",
    ]) );

}

void init(){
    add_action("raise_hp", "bathe");
}

int raise_hp(){
    string statr;
    int lvl, xp, conb, hp, hpmax;

    if (wizardp(TP)) {
	write("You're a wizard - go code something!  ;)\n");
	return 1;
    }

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
    DEBUG(TP->query("cap_name")+"'s max = "+hpmax+" HP\n");

    if (TP->query("max_hp") > hpmax){
	write("You Have been purified enough mortal!,\n"+
	  "Come back when you are more experienced!\n");
	return 1;
    }

    if (!TP->debit(CASH_COST)){
	write("You cannot pay the fee. The demons just laugh and "+
	  "throw filth at you.\n");
	return 1;
    }

    DEBUG("Pit of Flame result: "+TP->add_experience(XP_COST * -1)+"\n");

    add_hp(TP, (1 - conb));

    write(wrap("The demons gleefully count their credits, grab "+
	"you, and unceromoniously toss you into the Pit of Flame! "+
	"After what seems like hours of agony, they drag you out, "+
	"and abandon you at the fiery lake's edge.") );

    say(wrap(TPN+" pays the fiends the fee. The demons gleefully "+
	"count their credits, grab "+TPN+", and unceromoniously "+
	"toss "+objective(TP->query("gender"))+" into the Pit of "+
	"Flame! After what seems like hours of agony, they drag "+
	objective(TP->query("gender"))+" out, and abandon "+
	objective(TP->query("gender"))+" at the fiery lake's edge.") );

    return 1;
}

/* EOF */
