/*
** File: jack_box.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit OBJECT ;

void create() {
    seteuid( getuid() );
    set("author" , "Herself");
    set ("id", ({ "fountain" , "water" }) ) ;
    set("short" , "A Fountain");
    set ("long", @EndLong
This is a beautifully ornate fountain. A 
stone mermaid is in the center. Water
cascades from her mouth forming a perfect
 arc into the pool collected all around her. 
You see pennies sparkling on the marble bottom 
of the pool. Maybe if you are lucky, your wish 
will come true.
EndLong
    );
    set("mass" , 1000);
    set("volume" , 1000);
}
void init() {
    add_action ("throw_penny" , "throw");
    add_action ("search_fountain" , "search");
}
int throw_penny (string str) {
say(TPN+" tosses a penny into the fountain. \n");
write(@EndText
You close your eyes and toss a penny into the fountain...
EndText);
    return 1;
}
int open_lid (string str) {
    object jack;
    jack = clone_object("/u/n/nsd/clown/clown_jack.c");
    if (jack) {
	say(TPN+" opens the box lid, and a Jack leaps out!\n");
	write("You open the lid, and a Jack jumps out of the box!\n");
	jack->move( environment( this_player() ) );
	jack->kill_ob( this_player() );
    }else
	write("Error loading object!\n");
    return 1;
}
