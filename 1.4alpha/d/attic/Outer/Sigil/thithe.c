// Ilz coded this.
// 24 Apr 98 Cyanide lowered the cost a little. Was WAY too high.

#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    set ("light", 1) ;
    set ("long",
      "This is The Society For the Clerist Annonymous.\n"+
      "Clerics Only Are allowed past these doors.\n"+
      "For a small price (10 coins per point) the priests will\n"+
      "Recharge your thuergy points.\n"+
      "Just type thithe.\n");
   set("short", "Clerics Annoymous");
    set ("exits", ([
     "north" : SIGIL+"partedviel.c",
 ]) );
}


void init(){
    add_action("thithe", "thithe");
}

int thithe(){

    int cost, tpgain, tpmax;

    tpmax = TP->query("max_tp");
    tpgain = ( tpmax - TP->query("theurgy_points"));

    if (!tpgain){
	write("You have all your thuergy points!\n");
	return 1;
    }
    cost = (tpgain * 5);

    if (!(TP->debit(cost))){
   write("You do not have enough money to make a contribution.\n");
	return 1;
    }

    TP->set("theurgy_points", tpmax);
   write("With your contribution, the Clerics call apon your deity to empower you.\n");
    write("They charge you "+cost+" coins.\n");
    return 1;
}
