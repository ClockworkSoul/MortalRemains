// Shakar
// Crafted out of respect for the beast of the same name
// coded by Warlock @ Infinity.  She and he both are missed.

#include <mudlib.h>
#include <config.h>

inherit MONSTER;

void create () {
    object book;

    ::create() ;
    seteuid(getuid());
    set("prevent_summon", 1);
    set("author", "cyanide");
    set("stat/dexterity", 15);
    set("stat/strength", 22);
    set("stat/constitution", 20);
    set("armor_class", -1);
    set("lore_type", "monster");
    set_size(50);
    set("short", "Shakar the Black Dragon");
    set("long", @EndLong
Shakar is an ancient and very famous member of dragonkind. Having been
banished from her previous home on another plane, she has made her home
here.
EndLong
    );
    set("lore_type", "monster");
    set("lore", wrap("Shakar was once an inhabitant of a realm "+
	"by the name of Enfin'ti, and thrived there for many years as the "+
	"most powerful being in the realm. Eventually, however, her master "+
	"(and some say creator), the great and powerful warlock of the realm "+
	"vanished. Without his power she was forced into banishment, and made "+
	"her home here.") );
    set("id", ({ "shakar", "dragon", "black", "black dragon" }) );
    set("magic_resist", 30);
    set("resist_type", ([ "acid" : 0, "poison" : 50 ]) );
    set("special", 10);
    set_skill("Unarmed", 3, "strength");
    set("race", "dragon");
    enable_commands();
    set("damage", ({ 3,10 }) );
    set("damage_type", "slashing");
    set("weapon_name", "razor sharp claws");
    set_verbs( ({ "slash", "slice" }) );
    set_name("Shakar");
    set_living_name("Shakar");
    set("mage_spells", ({ "acidstorm", "bolt", "stoneskin", "enlarge",
      "coldcone", "globe" }) );
    set("spell_points", 800);
    set("max_sp", 800);
    set_level(30);
    set("wealth", (this_object()->query("hit_points")));
    book = clone_object("/d/class/wizard/general/obj/book.c");
    book->set("invisible", 2);
    book->move(TO);
}


void special_attack() {
    object ob;
    int sv, flag = 0;

    if (random(3)) return 0;

    ob = this_object()->query_current_attacker();

    switch(random(13)) {
    case 0 :
	say("Shakar breathes a gout of acid at "+ob->query("cap_name")+
	  "!\n", ob);
	tell_object(ob, "Shakar breathes a gout of acid on you!\n");
	sv = (ob->save_throw(-1));
	if (sv){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob, "You dive out of the way!\n");
	    }else{
		ob->receive_damage((random(18)+9), "acid");
	    }
	} else {
	    ob->receive_damage((random(36)+19), "acid");
	}
	flag = 1;
	break;
    case 1..4 :
	if (query_hit(ob)) {
	    say("Shakar sinks her teeth into "+ob->query("cap_name")+
	      "!\n", ob);
	    tell_object(ob, "Shakar sinks her teeth into your flesh!\n");
	    ob->receive_damage((random(8)+5), "slashing", this_object(), 1);
	}
	flag = 0;
	break;
    case 5..7 :
	{
	    mapping exits;
	    string *mydirs;
	    object dest;
	    int val;
	    if (query_hit(ob)) { 
		exits = environment()->query("exits");
		mydirs = keys(exits);
		if (sizeof(mydirs)) {
		    val = random(sizeof(mydirs));
		    dest = find_object_or_load(values(exits)[val]);

		    say(wrap("Shakar slaps "+ob->query("cap_name")+
			" with her tail, sending "+subjective(ob->query("gender"))+
			" flying!"), ob);
		    tell_object(ob, wrap("Shakar slaps you with her tail,"+
			" sending you flying!"));	
		    if (ob->query("summoner")) ob->set("speed", 10);
		    ob->move_player(dest, "SNEAK");
		    ob->receive_damage(20, "crushing", TO, 1);
		}
	    }
	    flag = 0;
	    break;
	}
    case 8..10 :
	if (query_hit(ob)) {
	    say(wrap("Shakar buffets "+ob->query("cap_name")+
		" with her wings!"), ob);
	    tell_object(ob, wrap("Shakar buffets you with her wings!"));
	    ob->block_attack(random(3)+1);
	} 
	flag = 0; 
	break;  
    case 11..12 :
	{
	    int a, s;
	    object *obs = query_attackers();
	    string *spells = query("mage_spells");
	    a = sizeof(attackers);
	    s = sizeof(spells);

	    // YEEEE HAW!!  Now THAT'S style!!
	    command("cast "+spells[random(s)]+" at "+
	      (obs[random(a)]->query("id"))[0] );

	    flag = 1; 
	    break;  
	}
    }

    return flag;
}


/* EOF */
