/*
** FILE:     shovel.c
** DATE:     Apr 1996
** PURPOSE:  Toy to be sold in Mir.
** CHANGES:     Apr 1996     Created the file.
**           05 Apr 1998     Fully two years laterm Cyanide 
**                           transferred the file to NKeep!
*/

#include <mudlib.h>

#define NAME this_player()->query("cap_name")
#define POSS possessive(this_player()->query("gender"))

inherit OBJECT;

void create () {
    seteuid(getuid());
    set ("short", "a magic shovel");
    set("id",({"shovel","magic shovel", "a magic shovel"}) );
    set ("long", @EndText
One of the magic shovels created by the ancient one known
as Cyanide. You can probably "dig" with it, or "fill" a
hole.
EndText 
    );
    set ("author", "cyanide");
    set("mass", 1);
    set ("value", 255);
    set ("enchanted", 2);
    set ("schools", ({ "enchantment", "alteration" }) );
}

void init() {
    add_action ("floyd", "dig");
    add_action ("harold", "fill");
}

int floyd() {
    object Cy_hole, hole_obj;

    Cy_hole=present("Cy_hole", environment(this_player()));
    if (!Cy_hole) {
	hole_obj=clone_object("/u/c/cyanide/toys/hole.c");
	hole_obj->move(environment(this_player()));
	write ("You dig a small hole.\n");
	say (NAME+" digs a small hole.\n"); 
	return 1;
    }
    if (Cy_hole->query("invisible")<1) {
	write ("There is already a perfectly good hole here!\n");
	return 1; }
    Cy_hole->set("invisible",0);
    write ("You dig a small hole.\n");
    say (NAME+" digs a small hole.\n");
    return 1;
}

int harold (string str) {
    object Cy_hole;

    if (str!="hole" && str!="small hole") {
	notify_fail ("Fill what?\n");
	return 0; }
    Cy_hole=present("Cy_hole", environment(this_player()));
    if (!Cy_hole) {
	write ("There doesn't seem to be any hole for you to fill!\n");
	return 1; }
    if (Cy_hole->query("invisible")>0) {
	write("There doesn't seem to be any hole for you to fill!\n"); 
	return 1; }
    Cy_hole->set("invisible",2);
    write ("You fill in the hole at pat the dirt firmly.\n");
    say (NAME+" fills in the hole and pats the dirt with "+POSS+
      " shovel.\n");
    return 1;
}
