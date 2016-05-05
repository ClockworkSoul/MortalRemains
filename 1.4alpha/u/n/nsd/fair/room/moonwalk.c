/*
** File: moonwalk.c
** Author: Lady Nsd
** Mention of honnor: Herself gave a couple of ideas for the
**                 actions of this room :-D
*/

#include <config.h>
#include <mudlib.h>
#include "fair.h"
int teen_flag = 0;

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set("light", 1);
    set("author", "nsd");
    set("short", "Inside the moonwalk...");
    set("long", @EndText
This is an enormous inflatable tent filled with hot air,
so you can jump or walk in it, and have the feeling
of floating on the moon... 
It's interiors are bright yellow, and the floor is royal blue.
There's a sign on one of the walls.
EndText);
    set("exits", ([
      "out" : FAIR_ROOM+"premoon.c",
    ]) );
    teen_flag = 0;
    set("item_desc", ([
      "floor" : "Big inflatable royal-blue floor. You're stepping on it.\n"+
      "Stop being so scientific, and start to 'jump'. Enjoy!!\n",
      "tent" : "Just a common inflatable tent.\n",
      "interiors" : "Bright yellow interiors.\n",
      "walls" : "Inflatable yellow walls. One of them has a sign.\n",
      "sign" : "Seems like you can read it :-)\n",
    ]) );
}
void init() {
    add_action("walk", "walk");
    add_action("jump", "jump");
    add_action("nap", "nap");
    add_action("lay", "lay");
    add_action("bellyflop", "bellyflop");
    add_action("roll", "roll");
    add_action("tumble", "tumble");
    add_action("sumersault", "sumersault");
    add_action("read_sign", "read");
    add_action("bad_emote", "kick");
    add_action("bad_emote", "bop");
    add_action("bad_emote", "boot");
    add_action("bad_emote", "sodomize");
    add_action("bad_emote", "smack");
    add_action("bad_emote", "slap");
    add_action("bad_emote", "bite");
    add_action("bad_emote", "bump");
    add_action("bad_emote", "buttkick");
    add_action("bad_emote", "piddle");
    add_action("bad_emote", "piss");
    add_action("bad_emote", "puke");
    add_action("bad_emote", "mount");
    add_action("bad_emote", "fc");
    add_action("bad_emote", "strip");
}

int walk(string str) {
    say(TPN+" starts to walk and feels how "+POSS+" bare feet sink.\n");
    write("You start to walk and feel how your bare feet sink on\n"+
      "the inflatable floor...\n");
    return 1;
}
int nap(string str) {
    say(TPN+" feels so comfortable "+subjective(TP->query("gender"))+
      " decides to take a nap...\n");
    write("You are so comfortable, you decide to take a nap...\n"+
      "You lay down and feel how your body sinks...\n");
    return 1;
}
int lay(string str) {
    say(TPN+" lays by your side :D\n");
    write("You lay on that fluffy surface... :D\n");
    return 1;
}
int bellyflop(string str) {
    say(TPN+" jumps up in the air, and smashes down on "+POSS+" belly.\n");
    write("You jump up in the air and smash down on your belly. :D\n");
    return 1;
}
int roll(string str) {
    say(TPN+" rolls all around the air stuffed floor.\n");
    write("You roll and feel how your body sinks...  :D\n");
    return 1;
}
int tumble(string str) {
    say(TPN+" tumbles as "+subjective(TP->query("gender"))+
      " loses balance for a while.\n");
    write("You tumble as you lose balance for a while...\n");
    return 1;
}
int sumersault(string str) {
    say(TPN+" does sumersaults all around the moonwalk!!!\n");
    write("You do sumersaults all around the moonwalk!!!\n");
    return 1;
}
int read_sign(string str) {
    if(!str || str!="sign") {
	write("What do you want to read?\n");
	return 1;
    }
    say(TPN+" reads the sign.\n");
    write(@EndText
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
|                                           |
|    In order to enjoy the moonwalk         |
|    without getting hurt, is important     |
|    to follow all the instructions:        |
|                                           |
|      *No food or drinks in here           |
|      *Everyone must be barefoot           |
|      *Don't push or fight in here         |
|                                           |
|    THESE ARE THE THINGS YOU CAN DO:       |
|                                           |
|    'bellyflop'     'roll'                 |
|    'tumble'        'sumersault'           |
|    'walk'          'jump'                 |
|    'nap'           'lay'                  |
|                                           |
|                                           |
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~
EndText);
    return 1;
}
int bad_emote (string str) {
    if("kick" && "bop" && "boot" && "sodomize" && "smack" && "slap"
      && "bite" && "bump" && "buttkick" && "piddle" && "piss" && "puke"
      && "mount" && "fc" && "strip") {
	write(
	  "For breaking the rules, the Fair Keeper boots you off the tent!!\n");
	say(
	  "The Fair Keeper grabs "+TPN+" by the ear and kicks "+
	  objective(TP->query("gender"))+" off\n"+
	  "the tent!!\n");
	this_player()->move_player(FAIR_ROOM+"premoon.c");
	say(TPN+" was kicked off the moonwalk for bad behavior!!!\n");
	return 1;
    }
}

int jump(string str) {
    object teen;
    if (!teen_flag) {
	for(int i = 0;i<5;i++) {
	    teen = clone_object(FAIR_MON+"spoiled.c");
	    teen->move(this_object() );
	}
	write("You start to jump when a gang of spoiled teens come in.\n");
	say(TPN+" starts to jump when a gang of spoiled teens come in.\n");
	teen_flag = 1;
    }else
	say(
	  TPN+" jumps so high you think "+subjective(TP->query("gender"))+
	  " can reach the stars...\n");
    write("You jump as high as if wanting to reach the stars...\n");
    return 1;
}
int reset() {
    teen_flag = 0;
    return ::reset();
}

/* EOF */
