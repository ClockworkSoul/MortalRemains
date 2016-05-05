/*
** behir.c
** Cyanide, Mar 21, 2000
*/

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "a behir");
    set("long", @EndLong
The behir is a snake-like reptilian monster whose dozen legs allow
to to move with considerable speed. It has deep blue scales banded
with bands of grey-brown. 
EndLong
    );
    set("id", ({ "behir" }) );
    set("base_ac", 4);
    set("armor_class", 4);
    set_skill("Unarmed", 3, "strength");
    set("damage", ({ 3, 8 }) );
    set_verbs( ({ "bite" }) );
    set("weapon_name", "jaws");
    set("damage_type", "piercing");
    set_name("behir");
    set("stat/constitution", 12);
    set_size(40);
    set("resist_type", ([
      "poison" : 0,
      "electricity" : 0
    ]) );
    credit(1200);
    set("special", 2);
    set_level(12);
}

int special_attack() {
    object ob = query_current_attacker();

    if (!random(10)) {
	tell_room(environment(TO), wrap("The behir belches a massive "+
	    "stroke of electicity at "+ob->query("cap_name")+"!"), ob);
	tell_object(ob, wrap("The behir belches a massive stroke of "+
	    "electricity at you!"));
	call_other("/d/class/wizard/spells/bolt.c", "cast_bolt",
	  "NONE", query_level() );
	return 1;
    }

    return 0;
}

