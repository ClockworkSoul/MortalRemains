//Started by Shya 8-5-00 finished by Sophia whenever she finishes it with her changes.

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set ("short", "Hildergard");
    set ("long", "Hildergard the high potentate recorder of marriages, divorces and other vital statistics..\n");
    set ("id", ({"hildergard"}) );
    set_name("hildergard");
    set ("gender", "female") ;
    set ("race", "human");
    enable_commands() ;
    set_living_name("hilderguard");
    set ("stat/constitution", 10);
    set ("stat/strength", 8);
    set ("base_ac", 8);
    set ("armor_class", 8);
    set ("CLASS", "");
    set ("damage", ({ 6,12 }) ) ;
    set ("weapon_name", "quill");
    set_verbs( ({ "hits with", "stabs with", "scribbles viscious notes with" }) ) ;
    set ("weap_resist", 0);
    set("resist_type", ([  ]));
    set("magic_resist", 0);
    set_size(6);
    set_level(5);
    set ("moving", 1);
    set ("speed", 1);
    set ("chat_chance", 5);
    set ("chat_output", ({
         "peers at you.\n",
	   "scribbles something in her book.\n",
	   "looks bored, since nothing happens around here.\n",
	   "looks up at you and lets out a tiny squeak.\n"
       }) );
    arm("/u/s/shya/quill.c");

}
void init(){
	add_action("purchase_func", "purchase");
	add_action("read_func", "read");
}

void do_revoke(string when){

}

void do_married(string when){

}

int purchase_func(string str){
    return 0;

}

int read_func(string str){


}
