/*
** The general diviner class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
** Cyanide made the diviner's spectacles, 8 Nov 98
*/

#define DIV_MAGE_PATH "/d/class/wizard/std/cmds:/d/class/wizard/diviner/cmds"
#define GUILDHALL "/d/class/wizard/diviner/rooms/diviner_guild.c"

#include <daemons.h>

inherit OBJECT;

string path;

void create() {
    seteuid(getuid());
    set("short", "a pair of spectacles");
    set("long", "An ornate and fragile pair of antique gilded "+
      "spectacles.\nEngraved along the inside is the word \"mhelp\".\n");
    set("id", ({ "#CLASS_OBJECT#", "spectacles", "specs", 
        "diviner specs" }) );
    set("prevent_get", 1);
    set("prevent_sell", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
    set("banned_armor", ({ "suit", "shield", "helmet" }) );
}

void init() {
    add_action("cmd_hook", "", 1);
    if (environment() && !living(environment())) remove();
}

int cmd_hook(string cmd) {
    string file, verb;
    int blah;

    path = DIV_MAGE_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 

/* EOF */
