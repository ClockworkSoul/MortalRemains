/*
** The general necromancer' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
** Cyanide made the necro's hourglass, 2 June 98
*/

#define NECRO_MAGE_PATH "/d/class/wizard/std/cmds:/d/class/wizard/necromancer/cmds"
#define GUILDHALL "/d/class/wizard/necromancer/rooms/necro_guild.c"

#include <daemons.h>

inherit OBJECT;

string path;

void create() {
    seteuid(getuid());
    set("short", "an hourglass");
    set("long", "A tall antique hourglass.\n"+
      "Engraved on the side, on a plaque, is the word \"mhelp\".\n");
    set("id", ({ "#CLASS_OBJECT#", "hourglass" }) );
    set("prevent_get", 1);
    set("prevent_sell", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
    set("banned_armor", ({ "suit", "shield", "helmet" }) );
}

void init() {
    add_action("cmd_hook", "", 1);
    if (!living(environment())) remove();
    add_action("guild", "guild");
}

int cmd_hook(string cmd) {
    string file, verb;
    int blah;

    path = NECRO_MAGE_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 

int guild() {
    write("Sorry - you have to find it now. :)\n");
    return 1;
}
