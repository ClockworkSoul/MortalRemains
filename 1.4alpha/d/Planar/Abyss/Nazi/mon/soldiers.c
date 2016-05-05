/*
**File: soldiers.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("short", "NAZI Storm Trooper");
    set ("long", @EndText
A foot soldier of the NAZI movement. Loyal and harmful.
EndText
    );
    set("id", ({ "NAZI Storm Trooper", "soldier", "demon", "nazi" }) );
    set_size(6);
    set_name("nazi storm trooper");
    set("gender", "male");
    set("race", "demon");
    set("undead", 1);
    set("lore_type", "demon lore");
    set("damage", ({9, 16}) );
    set("damage_type", "fire");
    set("weapon_name", "grenade launcher") ;
    set_verbs( ({ "attack", "shoot", "swing at", "peer at"}) ) ;
    set("nat", 1);
    set("chat_chance", 25);
    set ("chat_output", ({
      "Soldier marches in straight order.\n",
      "Soldier stops and salutes the swastika.\n",
      "Soldier extends his right hand and shouts: Hail Hitler.\n",
      "Soldier prepares to march again.\n",
    }) );
    set ("att_chat_output", ({
      "TAKE NO PRISONERS, WE SHALL\n",
      "NON-NAZI's must DIE!!!\n",
      "DIE INFERIOR SCUM!!!!!\n",
    }) );
    set_level(16);

    set("patrol", ({ "north", "south", "east", "west" }) );

    set("wealth", 200);
    set("ammo", ([ "gas grenade" : 20 ]) );
    arm("/d/Planar/Abyss/Nazi/obj/launcher.c", "grenade launcher");
    wear("/d/Planar/Abyss/Nazi/obj/mask.c", "gas mask");
}

/* End of File */

int ammo_debit( int i, string t) { return 1; }

