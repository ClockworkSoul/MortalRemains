/*
** Mage's Guild
** Begun by Cyanide, 10 Aug 97
** Stolen by Nightmask; Ribbed for her pleasure
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)


#include <daemons.h>
#include <mudlib.h>
#include <c_rogues.h>

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set("short", "Guild of Thieves");
    set("long", @Thief
You are standing in the Guild of the Thieves. Seedy looking characters
lurk all around you. The shadows are alive and move as you watch. You
see a few chairs and a table, You see a sign on the wall.
You may: Join or Advance here.
Thief
    );
    set("light", 1);
    set("class", "thief");
    set("group", "rogue");
    set("experience", ROGUE_EXP);
    set("exits", ([
      "south" : "/d/class/rogue/thief/room/t_profroom",
      "north" : "/d/Prime/Central/room/alley3",
    ]));
    set("item_desc", ([
      "sign" : "Watch for more thief classes!\n",
    ]) );
}

void init() {
    ::init();
}

string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("thief");
    if ((string)ob->query("gender")=="female") {
	str = ({
	"$N the AssBandit ($A)",
	"$N the Peeping Jane ($A)",
	"$N the Sneak ($A)",
	"$N the Thug ($A)",
	"$N the Scoundrel ($A)",
	"$N the Petty Thief ($A)",
	"$N the Mugger ($A)",
	"$N the Wallet-Snatcher ($A)",
	"$N the Robber ($A)",
	"$N the Bandit ($A)",
	"$N the Footpad ($A)",
	"$N the Ruffian ($A)",
	"$N the Thief ($A)",
	"$N the Crook ($A)",
	"$N the Larceness ($A)",
	"$N the PickPocket ($A)",
	"$N the Felon ($A)",
	"$N the Cutpurse ($A)",
	"$N the Con-Artist ($A)",
	"$N the Filcher ($A)",
	"$N the Rogue ($A)",
	"$N the Locksmith ($A)",
	"$N the Catburglar ($A)",
	"$N the Lady of Shadows ($A)",
	"$N the Mitresss Thief ($A)",
	"$N the Nightlady ($A)",
	"$N the Mistress of Shadows ($A)",
	"$N the Keeper of Shadows ($A)",
	"$N the Thief of Legend ($A)",
	"$N the Elder Thief ($A)",
      })[lvl];
    } else {
	str = ({
	"$N the Assbandit ($A)",
	"$N the Peeping Tom ($A)",
	"$N the Sneak ($A)",
	"$N the Thug ($A)",
	"$N the Scoundrel ($A)",
	"$N the Petty Thief ($A)",
	"$N the Mugger ($A)",
	"$N the Purse-Snatcher ($A)",
	"$N the Robber ($A)",
	"$N the Bandit ($A)",
	"$N the Burgler ($A)",
	"$N the Footpad ($A)",
	"$N the Ruffian ($A)",
	"$N the Thief ($A)",
	"$N the Crook ($A)",
	"$N the Larcenist ($A)",
	"$N the Pickpocket ($A)",
	"$N the Felon ($A)",
	"$N the Cutpurse ($A)",
	"$N the Con-Artist ($A)",
	"$N the Filcher ($A)",
	"$N the Rogue ($A)",
	"$N the Locksmith ($A)",
	"$N the Catburgler ($A)",
	"$N the Lord of Shadows ($A)",
	"$N the Master Thief ($A)",
	"$N the Nightlord ($A)",
	"$N the Master of Shadows ($A)",
	"$N the Keeper of Shadows ($A)",
	"$N the Thief of Legend ($A)",
	"$N the Elder Thief ($A)",
      })[lvl];
    }
    return str;
}                


int join() {
    object belt;
    int i, t;

    if (TP->query("base_stat/dexterity") < 9) {
	write("You are not nimble enough to be a thief!\n");
	return 0;
    }

    write("A seedy looking man appears from the shadows.\n");
    write("He says, \"You wanna be a thief, eh?\"\n");
    write("He hands you something, then slips back into the shadows.\n");
    write("You hear a voice, \"Yer a Thief now, Go rob something.\"\n");

    this_player()->set_skill("One Weapon Style", 1);
    this_player()->set_skill("Two Weapon Style", 1);      
    //this_player()->set_skill("Shield Style", 1);            
    //this_player()->set_skill("Two Handed Style", 1); 
    this_player()->query_link()->set("level", 1 );
    this_player()->set("wp_free", 3);
    i = (this_player()->query("stat/intelligence") - 11);
    t =	this_player()->query("stat/intelligence");
    if (i < 5){
	if (t < 16) i = 4;
	if (t < 14) i = 3;
	if (t < 12) i = 2;
	if (t < 9) i = 1;
    }

    this_player()->set("nwp_free", (i + 3));


    belt = clone_object(T_OBJ+"belt.c");
    if (!belt) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }
    belt->move(this_player());
    return 1;
}

int advance() {
    int level, hp, max;

    level = TP->query_level("thief");
    write("You advance to level "+level+".\n");
    say(TPN+" advances to level "+level+".\n") ;

    if(level%3==0) TP->add("nwp_free", 1);
    if(level%6==0) TP->add("wp_free", 1);

    hp = ROGUE_HP_ROLL;
    add_hp(TP, hp);
    return 1;
}
