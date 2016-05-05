#include "../cavern.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "shya");
    set("light", 0);
}

int roots_check()
{
    object roots;

    roots = present("roots", TO);
    if (roots) {
        write("The roots block your way.\n");
        roots->kill_ob(TP);   
        return 1;
    }
    return 0;
}

void on_roots_die ()
{
    string base_long;

    base_long = query("base_long");
    set("long", wrap(base_long + "  A hold has been hacked through the tangled mass of roots, allowing you to proceed."));
}

void reset ()
{
    object roots;
    string base_long;

    seteuid(getuid());
    ::reset();
    if (!present("roots")) {
        roots = clone_object(MONSTERS "/roots.c");
        if (roots) {
            roots->move(this_object());
            base_long = query("base_long");
            set("long", wrap(base_long + "  A tangled mass of roots blocks your progress."));
        }
        else
            on_roots_die();
    }
    else
        on_roots_die();
}
