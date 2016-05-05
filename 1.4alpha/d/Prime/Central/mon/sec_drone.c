#include <mudlib.h>
#include <central.h>

inherit MONSTER ;
object ob1;

void create () {
    ::create();
    seteuid(getuid());
    set("short", "a security drone");
    set("long", @Endtext
The model SD001 security drone is used as an all-purpose guard.
Unlike life-forms, these security drones are tireless, allowing 
the guarded area to be fully secure.
Endtext
    );
    set("id", ({ "security", "drone", "security drone" }) );
    set_name ("drone");
    set_living_name("drone");
    enable_commands();
    set("gender", "neuter");
    set("race", "machine");
    set("armor_class", 0);
    set("aggressive", 0);
    set("attack_strength", 5);
    set("damage", ({ 2,8 }) );
    set("weapon_name", "mechanical arm");
    set("stat/strength", 17);
    set("stat/dexterity", 17);
    set_skill ("attack", 25, "strength");
    set_skill ("defense", 25, "dexterity");
    set_verbs( ({ "swipe at" , "swing at", "jab at" }) );
    set_verbs2( ({ "swipes at", "swings at", "jabs at" }) );
    ob1 = clone_object(M_OBJ+ "metalarm");
    ob1->move(TO);
    set_level(10);
}
