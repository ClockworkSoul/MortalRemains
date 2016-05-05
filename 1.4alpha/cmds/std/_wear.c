/*
** _wear.c
** A quick hack because "wear" is cooler than "equip".
** Cyanide, 27 Sep 97
** Chronos adds a help() function, 21 Dec 98.
*/

#include <mudlib.h>

int cmd_wear(string str, int silent) {
    seteuid(getuid());

    call_other("/cmds/std/_equip.c", "cmd_equip", str, silent);
    return 1;
}

string help() {
  return @ENDHELP

Usage: wear all
       wear <item>

This command allows you to attempt to wear an item as armor.

See also: equip, unequip, remove, wield, unwield
ENDHELP
  ;
}
