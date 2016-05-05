// Cyanide redid - 10 June 2000
#include <messages.h>

inherit MONSTER ;

void create () {
    object ob1;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Triel the Fallen") ;
    set ("long", @EndText
Triel is a grossly deformed slug-creature, with vaguely humanoid features
and forelimbs that are more like prehensile tentacles than actual limbs.
Still, a mortal who gazes on the archduke can catch glimpses of the beauty
that Triel once possessed before he fell. 
EndText
    );
    set ("id", ({ "triel", "lord", "baatezu"}) ) ;
    set_name ("triel") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_living_name("triel") ;
    set ("stat/constitution", 13);
    set ("stat/strength", 19);
    set ("stat/charisma", 10);
    set ("stat/intelligence", 21);
    set ("stat/dexterity", 18);
    set ("stat/wisdom", 19);
    set_size(26);
    set ("base_ac", 4);
    set ("armor_class", 4);
    set ("damage", ({ 18,25 }) ) ;
    set ("weapon_name", "tentacles") ;
    set ("CLASS", "wizard");
    set ("weap_resist", 4);
    set ("magic_resist", 70);
    set ("mage_spells", ({ "stoneskin", "fireshield", "swarm", "bolt",  "enlarge" }) );
    set ("max_sp", 1000);
    set ("spell_points", 1000);
    set ("resist_type", ([ "cold" : 0, "poison" : 0, "fire" : 0 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;

    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1->set("invisible", 2);
    ob1 -> move (TO) ;

    // Evil, huh?
    ob1 = clone_object("/d/class/wizard/obj/heartstone_ob.c");
    ob1->begin_spell( TO );

    set("wealth", 6000);
    set_level(64);
}

void init(){
    ::init();
    command ("cast stoneskin");
}


// This function ALMOST unchanged from Ilzarion's original code, merely neatened.

int special_attack() {
    object ob;
    int sv; 
    string target;

    if (query("power_delay") || query("spell_points") < 80) {        
        return 0;    
    } else {    	    
        if (present("#STONESKIN#", TO)) {    
            if (present("#FIRE_SHIELD#", TO)) {    
                if (present("#ENLARGE_OB#", TO)) {    
                    switch (random(2)) {    
                        case 0 : command("cast bolt at "+
                            (query_random_attacker())->query("name")); 
                        break;
                        case 1 : command("cast swarm at "+
                            (query_random_attacker())->query("name"));
                        break;
                    }
                }else{    
                    command("cast enlarge");
                }
            }else{    
                command("cast fireshield");
            }
        }else{    
            command("cast stoneskin");
        }
    }

    return 0;
}
