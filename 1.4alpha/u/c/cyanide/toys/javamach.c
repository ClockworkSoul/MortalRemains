inherit OBJECT;

void create() {
    seteuid(getuid());
    set("mass", 120);
    set("prevent_get", 1);
    set("long", @EndLong
A big, industrial coffee machine. For 1 debit, it will "dispense"
coffee just the way you like it.
EndLong
    );
    set("short", "a coffee machine");
    set("id", ({ "machine", "coffee machine" }) );
}

void init() {
    add_action("dispense", "dispense");
}

int dispense() {
    object java;

    if (!TP->debit(1)) {
	write("You're broke!  Beg for change, monkey!\n");
	return 1;
    }

    java = clone_object("/u/c/cyanide/toys/coffee.c");
    if (java) java->move(TP);
    else
	write("The machine seems to be broken.\n");

    write("Out pops a coffee, just how you like it!\n");
    say(TPN+" buys a coffee.\n");
    return 1;
}

