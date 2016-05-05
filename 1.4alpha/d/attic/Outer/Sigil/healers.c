#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid());
    set ("light", 1) ;
    set ("long",
@ENDLONG
Strange herbs and exotic plants hang all around you in this rickety
old building called the House of Healing.  The healers of this place
specialize in curing all ailments that cannot be cured by a good strong
drink.  A sign hangs on the wall here.
ENDLONG
  );
   set("short", "The House of Healing.") ;
    set("objects", ([
      "#PORTAL#" : "/d/Outer/Sigil/items/newbie_portal",
    ]) );
  set("smell", ([
   "default" : "You smell some very odd odors mixed together in here.\n",
  ]) ) ;
  set("item_desc", ([
  "sign" : "You could read it if you like.\n",
   "herbs" : "You don't recognize any of them.\n",
  "plants" : "You don't recognize any of them.\n",
  "wall" : "There is a sign on the wall.\n",
  ]) ) ;
    reset();
    set ("exits", ([
      "east" : SIGIL+"duskgatest1.c" ]));
}

void init(){
    add_action("cure", "cure");
   add_action("read", "read") ;
}


int read(string str) {
  if (!str) {
    write("Read what?\n");
   return 1;
  }
  if (str == "sign") {
    write(@ENDSIGN
The sign reads:

We cure all ailments that plague you for only 1,000 gold coins!

Poisoning, blindness, enfeeblement, severe wounds, and more!

Type "cure <ailment>" to be cured!
ENDSIGN
  );  say(TPN+" reads the sign.\n");
   return 1;
  } else return 0;
}

int cure(string str){

    object ob;
    switch(str){
    case "feeblemind" : ob = present("#FEEBLEMIND#", TP);
	if (!ob) {
	    write("You're just as smart as ever.\n");
	    return 1;
	}
	if (!TP->debit(1000)) {
	    write("You can't afford that!\n");
	    return 1;
	}
	write("The healer prounounces your smart again.\n");
	ob->remove();
	break;

    case "wound" : ob = present("#WOUND_OB#", this_player());
	if(!ob){
	    write("You're Fine!\n");
	    return 1;
	}
	if (!TP->debit(10000)) {
	    write("You can't afford that!\n");
	    return 1;
	}
	write("Your wounds magically seal up as the healer helps you.\n");
	ob->remove();
	break;
    case "wounds" : ob = present("#WOUND_OB#", this_player());
	if(!ob){
	    write("You're Fine!\n");
	    return 1;
	}
	if (!TP->debit(10000)) {
	    write("You can't afford that!\n");
	    return 1;
	}
	write("Your wounds magically seal up as the healer helps you.\n");
	ob->remove();
	break;
    case "bleeding wounds" : ob = present("#WOUND_OB#", this_player());
	if(!ob){
	    write("You're Fine!\n");
	    return 1;
	}
	if (!TP->debit(10000)) {
	    write("You can't afford that!\n");
	    return 1;
	}
	write("Your wounds magically seal up as the healer helps you.\n");
	ob->remove();
	break;
    default : write("Type cure <injury> , injury = wounds, poison etc.\n");
    }
    return 1;
}
