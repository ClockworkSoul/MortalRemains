inherit MONSTER;
 
void create () {
  
        object ob1, ob2, ob3, ob4 ;
  
    ::create();
    seteuid(getuid());
    set("short", "Zed");
    set("long", "Zed is a Huge man. His arms are the size of cannons.
You dont think it would be wise to Fuck with him.\n");
    set("id", ({ "zed", "smith", "blacksmith"}) );
    set_name ("zed");
    set("race", "human");
    set("gender", "male");
    enable_commands();
    set_living_name("zed");
    set ("stat/constitution", 19);
    set ("stat/strength", 18);
    set ("stat/charisma", 5);
    set ("stat/intelligence", 5);
    set ("stat/dexterity", 14);
    set ("stat/wisdom", 9);
    set("damage", ({ 2,4 }) );
    set("weapon_name", "fists");
    set("CLASS", "warrior");
    set_skill("Clubbing Weapons", 3, "Strength");
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;

    // You forgot these:
    set_size(6);       //Man sized.
    set_align("cg");   // Nobody ever add this...  I made him chaotic good,
                       // Just to show how to do it.

    // set_level should always be last in the function so the xp is
    // calculated right.
  set_level(26);
   ob1 = clone_object ("/u/d/darkgoth/weapon/hammer.c") ;
  ob1 -> move (this_object()) ;
     ob2 = clone_object ("/u/d/darkgoth/item/redplate.c") ;
 ob2 -> move (this_object()) ;
    }

void init () {
   ::init();
   command("wield hammer");
   command("equip armor");
}

