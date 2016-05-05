// This was coded by Cyanide back around 1996 or so.
// When he was a green coder.

#include "obj.h"
#include <mudlib.h>

inherit ARMOR ;

void create() {
    set ("charges", 3);
    set("id", ({"ring"}));
    if ((this_object()->query("charges"))==1) {
	set ("short", "an ancient golden ring ("+query("charges")+" charges)") ;
    } else set ("short", "an ancient golden ring ("+query("charges")+" charges)");
    set ("long",
      "An ancient ring, apparently of dwarven make. Upon it is borne the\n"+
      "insignia of Torkath the Divine, the last king of Urborg.\n"+
      "Upon the ring is a beautiful inscription the reads 'sanctuary'.\n");
    set("value", ((int)query("charges")*1000) + 2000);
    set_armor_type("ring");
    set("size", -1);
}
void init()
{
    add_action ("sanctuary", "sanctuary");
}

int sanctuary () {
    if ((this_object()->query("charges"))<1) {
	write ("Nothing happens.\n");
	return 1;
    }
    this_object()->set("charges",((this_object()->query("charges")-1)));
    if ((this_object()->query("charges"))==1) {
	set ("short", "an ancient golden ring ("+query("charges")+" charge)") ;
    } else set ("short", "an ancient golden ring ("+query("charges")+"
charges)") ;
    write (
      "Suddenly, you are swept away by a flood of white light!\n");
    say (
      this_player()->query("cap_name")+
      " dissapears in a flash of white light!\n");
    TP->move_player(MAIN+"/safe.c", "SNEAK");
    say (
      this_player()->query("cap_name")+
      " appears in a flash of brilliant white light!\n");
    return 1;
}
