/* 
** This was written by Ilzarion a couple of years ago.
** On 1 March 2000 Cyanide cleaned it up a little and added
** this header.
*/

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>
void do_word(object target, int smite);
int cmd_smite(string targ) {
    object ob, weapon, smitten, invis_ob;
    int level, targlevel, wrath;   //Forgot this, too.
    string type, playeth, targeth, playmor, targmor;

    if ((this_player()->query_skill("Smite"))<1){
	write("You must have the proficiency first!\n");
	return 1;
    }

    if (!targ) {
	write("Smite what?\n");
	return 1;
    }
    ob = present(targ, environment(this_player()));

    if (!ob) {
	write("There's nothing by that name to smite.\n") ;
	return 1;
    }    

    if (!living(ob)) {
	write ("That's not alive!\n");
	return 1;
    }

    if (ob->query("no_attack")) {
	write("You are not permitted to attack that.\n") ;
	return 1;
    } 

    smitten = present("SMITTEN", ob);

    if (smitten) {
	if (member_array((string)this_player()->query("name"),
	    (string *)smitten->query("smitten")) == -1) {
	    smitten->add("smitten", ({ this_player()->query("name") }) );
	} else {
	    write(ob->query("cap_name")+" has already felt the wrath of your god...\n");
	    return 1;
	}
    } else {
	smitten = clone_object("/d/class/priest/obj/smitten.c");
	if (!smitten) {
	    write("Your skills fail you.  Notify Cyanide.\n");
	    return 1;
	}
	smitten->set("smitten", ({ this_player()->query("name") }) );
	smitten->move(ob);
    }

    level = TP->query_level("priest");
    targlevel = ob->query_level();
    playeth = TP->query_ethics();
    targeth = ob->query_ethics();
    playmor = TP->query_morals();
    targmor = ob->query_morals();
    wrath = level - targlevel;

    if (playeth != targeth) wrath += 5;
    if (playmor != targmor) wrath += 5;
    if ((playmor == targmor) && (playeth == targeth)) wrath -= 5;
    write(ob->query("cap_name")+" feels the wrath of "+capitalize(TP->query("deity"))+"!!!\n");
    do_word(ob, wrath);
    return 1;
}

void do_word(object target, int wrath){
    int rand;
    target->set("last_attacker", TP);
    target->kill_ob(TP);

    switch (wrath){
    case -500..1 :
	{
	    say(target->query("cap_name")+" is blinded from divine light!\n");
	    write(target->query("cap_name")+" is blinded from divine light!\n");
	    rand = random(4)+1;
	    target->set("blind", rand);
	};break;
    case 2..6 :
	{
	    say(target->query("cap_name")+" falls to thier knees in subjugation!\n");
	    write(target->query("cap_name")+" falls to thier knees in subjugation!\n");
	    rand = random(4)+random(4)+2;
	    target->set("no_move", rand);
	};break;
    case 7..10 :
	{
	    say(target->query("cap_name")+" is bathed in holy flames!\n");
	    write(target->query("cap_name")+" is bathed in holy flames!\n");
	    rand = random(60)+11;
	    target->set("last_attacker", TP);
	    target->receive_damage(rand, "fire", this_player(), 0 );
	};break;
    case 11..15 :
	{
	    say(target->query("cap_name")+" is stunned by your divinity!\n");
	    write(target->query("cap_name")+" is stunned by your divinity!\n");
	    rand = random(4)+1;
	    target->block_attack(rand);
	};break;
    case 16..20 :
	{
	    say(target->query("cap_name")+" is paralyzed from fear!\n");
	    write(target->query("cap_name")+" is paralyzed from fear!\n");
	    rand = random(4)+1;
	    target->block_attack(rand);
	    target->set("no_move", rand);
	};break;
    default :
	{
	    say(target->query("cap_name")+" life is snuffed out by your god!\n");
	    write(target->query("cap_name")+" life is snuffed out by your god!\n");
	    target->set("last_attacker", TP);
	    target->set("hit_points", -1);
	}
    }
    return;
}
