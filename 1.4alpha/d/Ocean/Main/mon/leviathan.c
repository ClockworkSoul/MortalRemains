
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "leviathan");
    set("prevent_summon" , 1);
    set ("long", @EndText
A monstrous beast of the ocean. His body style is not unlike
that of a dragon. He commands the power of the ocean and can
use it any way he desires. Beware this beast!
EndText
    );
    set("id" , ({"leviathan" , "lev" , "beast"}) );
    set_size(20);
    set("wealth" , 2159);
    set_name("leviathan");
    set("resist_damage_type" , "suffocation");
    set_living_name("leviathan");
    set("gender" , "male");
    set("race" , "dragon");
    set("lore_type" , "monster");
    set("damage" , ({10,15}) );
    set("damage_type" , "slashing");
    set("weapon_name", "claws") ;
    set_verbs( ({"slash at" , "swipe at" , "gouge"}) );
    set_verbs2( ({"slashes at" , "swipes at" , "gouges"}) );
    set("chat_chance" , 6);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    arm("/d/Ocean/Main/weap/levsword.c");
    set("special" , 5);
    set_level(34);
}
void special_attack(){
    object ob;
    int sv;
    ob = this_object()->query_current_attacker();
    if(random(3) == 0){
	say("Leviathan unleashes a fury of water on "+
	  ob->query("cap_name")+"!\n", ob);
	tell_object(ob, "Leviathan unleashes a fury of water on you!\n");
	sv = (ob->save_throw(-6));
	if (sv) {
	    if((ob->query_skill("Evasion"))>0){
		tell_object(ob, "You dive out of the way!\n");
	    }else{
		ob->receive_damage((random(20)+10), "crushing");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(30)+10), "crushing");
	}
    }else{
	say("Leviathan slashes at "+ob->query("cap_name")+" with "+
	  "his claws!\n", ob);
	tell_object(ob, "Leviathan tears into you. \n");
	ob->receive_damage((random(14)+10), "slashing" , this_object(),1);
    }
}
int hit_func(object ob, int damage){
    if (!random(25)) {
	tell_object(ob, "Leviathan summons a whirlpool from below you. "+
	  "It spins you around leaving you dizzy!\n");
	ob->block_attack(random(2) + 1);
	ob->receive_damage((random(10)+10), "suffocation");
    }
    return damage;
}
