
#include "main.h"

inherit MAIN+"/palacestd.c";

void create() {
    set("smell", @EndSmell
The organic scents of a humid forest in full bloom swim in
your nostrils with a mixed pungency of natural wilderness and a
stench of something unnatural.
EndSmell
    );
    set("listen", @EndListen
The sounds of strange and unusual beasts echo throughout the
garden.
EndListen
    );
    ::create();
}

/* EOF */
