// Dragon cast is the same as mage's cast.
// Cyanide,  1 Dec 98

#include "/u/c/cyanide/debug.h"

int cmd_cast (string str) {
    seteuid(getuid());

    return ("/d/class/wizard/std/cmds/_cast.c"->cmd_cast(str));
}

/* EOF */
