/*  File: armor.c
**  Purpose: You figure it out, duh...
**  Date: July 30th, 1997
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
*/


#define PN this_player()->query("cap_name")
inherit "/u/d/dalceon/ronin/wildbonus.c";
inherit ARMOR;

int do_attack(int);
int do_attack2(int);
int do_attack3(int);
int final_attack(int);
int do_random(object);
int flare_up(string);

int can_attack;
void create() {
    //short is what you see w/o an examine
    set("short", "Armour of Wildfire");

    //long is what is seen when the object is examined. the @SuckMe
    //statement allows you to write a long description without useing
    // n\"+ all the time
    set("long", @WildDesc
The Armour of Wildfire was born from the heart of a volcano.  It glows a
fiery red. The armour has two small shoulder pads that slope down to 
protect the shoulders.  It has two larger shoulder shields that flare out 
to the sides. There are two giant yellow diamonds on either shoulder front
that helps to add to the deceptively beautiful facade of the armour.  The
chest shield is big,red, and more than enough to handle attacks from your
enemies.
WildDesc
    );

    //this allows a player to exa the item in more ways than 1
    set("armor", 12);
    set("material_type", "metal/fine steel");
    set("value", 2000);
    set("equip_func","add_main");
    set("unequip_func", "remove_main");
    set("id", ({ "wildfire", "armour", "wildfire armour"}) );

    //armor_type makes it a type of armor, thew other types can be found
    //in /doc/properties
    set_armor_type("full plate");
    can_attack = 1;
}

void init() {
    add_action("flare_up", "flare");
}

int flare_up(string arg) {

    if((arg != "up now") && (arg != "up")) {
	  write("You try to get the armour to flare up now, but it doesn't work.\n");
      say("The Wildfire armour glows, but then suddenly returns to normal.\n");
	  return 1;
    }
    if(!can_attack) {
	  write("You are drained from your last attack. You cannot summon the energy.\n");
	  return 1;
    }
      else {
	     if(!everything()) {
	     write("You must be wearing all of the Wildfire Armour to make it flare up!!\n");
	     return 1;
	   }
	     else {
	        do_attack(everything());
	     }
    }
}

int do_attack( int which ) {

    write("You scream 'Flare up Now!!', and the armour glows brighter than ever.\n");
    say(PN+" screams: Flare up Now!!, and the armour glows brighter.\n");
    call_out("do_attack2",3,which);
    return 1;
}

int do_attack2( int which ) {
    write("You are engulfed by a massive circle of fire!!\n");
    say(PN+" is engulfed by a massive wall of fire.\n");
   call_out("do_attack3",3,which);
    return 1;
}

int do_attack3( int which ) {
    write("Your eyes become flames as the fire in you grows.\n");
    say(PN+"'s eyes become flames!!\n");
    final_attack(which);
}


int final_attack(int which ) {
    object attacker, wearer;

    wearer = environment(this_object());
    attacker = wearer->query_current_attacker();
    if(!attacker) {
	tell_object(wearer, "You unleash the Wildfire energy into space!! "+
	  "What a waste!!\n");
	message("combat", "The armour unleashes all of its energy into space.\n",
	  all_inventory(environment(wearer)), wearer);
	can_attack = 0;
	call_out("resume_attack",5);
	return 1;
    }
    else {
     	if(which == 1) {
	      write("You release the Wildfire's Flare, but you can't channel the \n");
	      write("massive amount of enery though the swords!!.\n");
	      say(PN+" loses control of the attack!!.\n");
	      do_random(wearer);
	      return 1;
    	}
    	else {
	      write("You channel the Wildfire enery through the Sword of Wildfire!!\n");
	      write("A cone of fire blasts "+attacker->query("cap_name")+".\n");
	      say("A cone of fire erupts from the end of the Sword of Wildfire.\n");
	      say(attacker->query("cap_name")+" is blasted by fire!!\n");
	      can_attack = 0;
	      attacker->receive_damage(25+random(100), "fire");
	      call_out("resume_attack",5);
    	}
    }

}

int do_random(object player ) {

    object * inventory;
    int i = 0;
    inventory = all_inventory(environment(TP));

    for(i;i<sizeof(inventory);i++) {
	   if(living(inventory[i]) && inventory[i] != TP && (random(50)< 30)){
	      inventory[i]->receive_damage(random(20)+random(10), "fire");
          write("You set "+inventory[i]->query("cap_name")+" ablaze!!.\n");
          say(inventory[i]->query("cap_name")+" is blasted by fire!!.\n");
          tell_object(inventory[i], "You are set ablaze!!\n");
          inventory[i]->kill_ob(player);
       }
    }
    can_attack = 0;
    call_out("resume_attack", 20);
    return 1;
}

void resume_attack() {
    can_attack = 1;
}


