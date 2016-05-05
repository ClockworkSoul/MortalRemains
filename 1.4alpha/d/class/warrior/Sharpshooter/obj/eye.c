/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

#define SS_PATH "/d/class/warrior/Sharpshooter/cmds"

#include <daemons.h>

inherit ARMOR;

string path;

void create() {
    seteuid(getuid());
    set("short", "a cybernetic eyelink");
    set("long", @EYE
This is a cybernetic eyelink that enables you to hit your target more
effectivally. It's a round, red disc with a scope on it. It attaches
itself to your right eye, from the back of your head. The word "shelp"
implants itself into your eyes data pack.
EYE
    );
  set("chat", 1) ; // chatline default to on.
  set("id", ({ "#CLASS_OBJECT#", "link", "eyelink", "cybernetic eyelink" })) ;
    set("prevent_sell", 1);
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
    set_armor_type("helmet");
   set("extra_look", (TPN+" has a cybernetic eye implant.\n"));
}

void init() {
  if (!living(environment())) remove() ;
  find_object_or_load(SS_PATH+
    "/login.c")->login(TP) ;
    add_action("cmd_hook", "", 1);
}

int cmd_hook(string cmd) {
    string file, verb;
    int blah;

    path = SS_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 
