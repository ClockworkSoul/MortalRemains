/*
** File: /u/n/nsd/library/sauna/sauna2.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>

inherit ROOM;



void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set("short", "Sauna");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
You enter a small cabin with enough space for
ten persons at once. The temperature is
comfortable to your skin. There's one long
bench to your left, and another to your
right. You prepare yourself for a steaming
experience. But beware of staying too long!
Who knows what can happen...
EndText
    );
    set( "exits", ([
"out" : "/u/n/nsd/library/sauna/sauna1.c",
    ]) );
    set( "item_desc", ([
"benches" : "Wooden benches. Long enough for
five persons each.\n",
]) );
}

void init() {
call_out("do_steam_func", 30, TP);
}
int do_steam_func(object ob) {
if (environment(ob) != TO) return 0;
tell_object(ob, ([
"Suddenly you feel strange...\n",
"You sweat like never before...\n",
"You start to drain...\n",
"Your skin is burning...\n",
"Your pressure gets higher...\n",
"Your blood is boiling...\n",
"You feel like the devil is biting your ass...\n",
]) );

ob->receive_damage(ob->query_level()*4, "steam");

call_out("do_steam_func", 30, ob);
return 1;
}
/* EOF */
