/*
** Assassin's Guild
** Begun by Cyanide, 10 Aug 97
** Stolen by Nightmask; Ribbed for her pleasure
*/

/*
#define FIND find_player("nightmask")
*/

#define ALLOWED_RACES ({ "drow", "human" })

#include <daemons.h>
#include <mudlib.h>
#include <c_rogues.h>

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set("objects", ([ "thadius" : A_MON+"guild_master.c" ]) );
    reset();
    set("short", "The Assassin's Guild Hall");
    set("long", @Thief
You stand in a great hall made of pure Ivory and Jade. Pillars stand
a full 12 feet tall and hold up the massive roof that depicts a scene
of the most famous of all Assassins in action. To the north is a common
place, where Assassins may go to rest or talk of rumors.
Commands: <join> and <advance>.
Thief
    );
    set("light", 1);
    set("class", "assassin");
    set("group", "rogue");
    set("experience", ROGUE_EXP);
    set("exits", ([
      "north" : "/d/class/rogue/Assasins/rooms/rm1.c",
    ]));
}

void init() {
    ::init();
}

string titles(object ob) { return "$N the Assassin ($A)"; }


/*
string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("assassin");
    if (lvl > 30) lvl = 30;
    if ((string)ob->query("gender")=="female") {
	str = ({
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
      })[lvl];
    } else {
	str = ({
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
	"$N the Assassin ($A)",
      })[lvl];
    }
    return str;
}                
*/


int join() {
    object belt;

    if (TP->query("base_stat/dexterity") < 17) {
	write("You are not nimble enough to be an assassin!\n");
	return 0;
    }
    if (TP->query("base_stat/strength") < 14) {
	write("You are not strong enough to be an assassin!\n");
	return 0;
    }
    if (TP->query("base_stat/intelligence") < 12) {
	write("You are not smart enough to be an assassin!\n");
	return 0;
    }
     if (!(TP->query_alignment() == "chaotic evil")) {
	write("You are not evil enough to join us!\n");
	return 0;
    }
    write("Thadius says, \"Welcome to the family.\n");
    write("He hands you somthing, then wishes you fame and fortune.\n");

    belt = clone_object(A_OBJ+"bandana.c");
    if (!belt) {
	write("\nA voice says, \"Yer fucked!\n"+
	  "Please notify Nightmask.\n");
	return 0;
    }
    belt->move(this_player());
    TP->add("nwp_free", 3);
    TP->add("wp_free", 2);
    return 1;
}

int advance() {
    int level, hp, max;

    level = TP->query_level("assassin");
    write("You advance to level "+level+".\n");

    if (level%4==0) {
	TP->add("nwp_free", 1);
	TP->add("wp_free", 1);
    }

    hp = ROGUE_HP_ROLL;
    add_hp(TP, hp);
    return 1;
}

/* EOF */
