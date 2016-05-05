/*
** File: fountain.c
** Author: Herself
** Special Thanks: to Nsd for letting me use her code,
** and teaching me how to use it!!
*/

#include <mudlib.h>
#include "mall.h"

int mermaid_flag;
int guard_flag;

inherit OBJECT ;

void create() {
    seteuid( getuid() );
    set("author" , "Herself");
    set ("id", ({ "fountain" , "water" }) ) ;
    set("short" , "The Fountain");
    set ("long", @EndLong
This is a beautifully ornate fountain. A 
stone mermaid is in the center. Water
cascades from her mouth forming a perfect
arc of water, into the pool collected
all around her. You can see pennies
sparkling on the botton of the pool.
Maybe if you throw a penny, your 
wish could come true.
EndLong
    );
    set("mass" , 1000);
    set("prevent_get", 1);
    mermaid_flag = 1;
    guard_flag = 1;
}
void init() {
    add_action ("throw_penny" , "throw");
    add_action ("search_fountain" , "search");
    add_action ("kick_fountain" , "kick");
}
int kick_fountain (string str) {
    if(!str) {
	write ("Kick what?\n");
	return 1;
    }
    write(wrap(
	"You kick the fountain. What a dumbass, now \n"+
	"your foot hurts!\n"));
    say(wrap(
	TPN+" kicks the fountain. What a dumbass, now "+
	objective(TP->query("gender"))+" foot hurts!\n"));
    return 1;
}
int throw_penny (string str) {
    object mermaid;
    mermaid = clone_object(MALL+"mons/mermaid.c");
    if(mermaid && mermaid_flag) {
	say(TPN+" throws a penny into the fountain... the mermaid comes to life!\n");
	write(@EndText
You close your eyes and toss a penny into the fountain...
Suddenly the mermaid comes to life and attacks!
EndText);
	mermaid->move( environment(this_player() ) );
	mermaid->kill_ob( this_player() );
	mermaid_flag = 0;
    }else
	write("You wish for luck.\n");
    return 1;
}
int search_fountain (string str) {
    object guard;
    guard = clone_object(MALL+"mons/guard.c");
    if(guard && guard_flag) {
	say(TPN+" gets caught trying to steal pennies!\n");
	write(@EndText
You roll up your pants and step into the fountain
like an idiot. A guard catches you and attacks!
EndText);
	guard->move( environment(this_player() ) );
	guard->kill_ob( this_player() );
	guard_flag = 0;
    }else
	write("You search around but find nothing of interest.\n");
    return 1;
}

void fix_flag() { mermaid_flag = 1; }

