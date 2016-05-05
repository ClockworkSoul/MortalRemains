#include <mudlib.h>
#include <where.h>

inherit OBJECT ;

void create() {
    set ("id", ({ "syringe", "dirty syringe", "needle" }) );
    set("author","cattt");
    set ("short", "a dirty syringe");
    set ("long", @EndText
A dirty, half used syringe.  Looking carefully at it you can see
it still has some drug residue in it.  You can only imagine how
many people have used this one needle.
EndText
    );
    set ("mass", 1);
    set ("bulk", 0);
    set ("value", 3);
    set ("prevent_drop", 0);
    set ("prevent_insert", 0);
    set ("prevent_give", 0);
}
void init () {
    add_action ("inject", "inject");
}

int inject (string str) {
    if (!str) {
	write ("Do you mean inject syringe?\n");
	return 1;
    }
    if (str=="syringe" || str=="me") {

	write ("You inject yourself with the syringe.\n");
	write ("You suddenly feel lightheaded, but only for a moment.\n");

	say(wrap(TPN+" injects "+objective(TP->query("gender"))+"self "+
	    "and gets a goofy look for a moment.") );

    } else {
	write("Just what do you want to inject?\n");
    }
    return 1;
}

