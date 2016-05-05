// 22 May 98   Cyanide created the file.

#include "/u/c/cyanide/debug.h"
#include <daemons.h>
#include "central.h"

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set("short", CITY_NAME+" CopBot Number "+
      (random(1000) + 100) );
    set("race", "robot");
    set("long", wrap(
	"This is a CopBot, a massive technomagical construct "+
	"designed for protection of the citizenry of "+CITY_NAME+
	". Though they have a few minor design flaws (such as a small "+
	"tendency to go berzerk at random times), they generally do "+
	"an exceptional job.") );
    set("lore_type", "arcanology");
    set("lore", wrap(
	"As technology increased and the individual's potential for "+
	"destruction increased with it, a new breed of police officer "+
	"was required. About 10 years ago, the Macrosoft Corporation "+
	"supplied the solution: the CopBot"+
	"\n\n(*CopBot (tm) is a registered trademark of the Macrosoft "+
	"Corporation).") );
    set("id", ({ "bot", "copbot", "cop" }) );
    set_name( query("short") );
    set_size(8);
    set("weapon_name", "stun baton");
    set("damage_type", "electricity");
    set_verbs( ({ "zap", "jolt", "shock" }) );
    set("damage", ({ 5, 20 }) );
    set("armor_class", 5);
    set("alt_corpse", M_OBJ+"deadcopbot.c");
    set_level(15);

    set("chat_chance", 15);
    set("chat_output", ({
      "CopBot vocalizes: # Good afternoon, citizen. #\n",
      "CopBot vocalizes: # Please keep the city clean. Thank you. #\n",
      "The CopBot picks up a bit of trash.\n",
    }) );
    set("att_chat_output", ({
      "CopBot vocalizes: # Lower your weapons. You are under arrest. #\n"
    }) );
}

void init() {
    ::init();

    if (TP && environment(TO) && LAW_D->is_suspect(TP)) {
	call_out("do_arrest", 1, TP);
    }
}

void do_arrest(object ob) {
    string pname = TP->query("name");
    command("to "+pname+" # Halt - you are under arrest. #");
    kill_ob(TP);
}

int kill_ob(object ob) {
    int i;

    i = ::kill_ob(ob);

    if (i) LAW_D->add_suspect(ob);
    return i; 
}

/* EOF */
