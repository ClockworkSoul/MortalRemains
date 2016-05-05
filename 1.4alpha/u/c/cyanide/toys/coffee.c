// Cyanide, 1 Jun 2000

inherit OBJECT;

int sip = 8;

void create() {
    seteuid(getuid());
    set("short", "a steaming cup of coffee");
    set("long", @EndLong
A hot cup of coffee, just like you like it!
You can "sip" it, or "drink" it all.
EndLong
    );
    set("id", ({ "cup", "coffee", "java" }) );
}

void init() {
    add_action("sip", "sip");
    add_action("drink", "drink");
}

int drink( string str ) {
    object cup;

    if (!str) return 0;
    if (!id(lower_case(str))) return 0;

    write("You drink the entire cup in one gulp!\n");
    say(TPN+" slams an entire cup of coffee in one gulp!\n");


    cup = clone_object("/u/c/cyanide/toys/scup.c");
    if (cup) cup->move(TP);
    remove();

    return 1;
}

int sip (string str) {
    object cup;

    if (!str) return 0;
    if (!id(lower_case(str))) return 0;

    if (--sip) {
	write("You take a sip of your coffee.\n");
	say(TPN+" takes a small sip of "+
	  possessive(TP->query("gender"))+" coffee.\n");
    } else {
	write("You finish off your cup of coffee.\n");
	say(TPN+" finishes off the last sip of "+
	  possessive(TP->query("gender"))+" coffee.\n");

	cup = clone_object("scup.c");
	if (cup) cup->move(TP);
	remove();
    }

    return 1;
}
