/*
** File: helion.c
** Many thanks to the original, where ever he wound up
** for being a good friend and comrade in arms
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
set ("author","shallar");
set("short","Helion the Sinner");
    set ("long", @EndText
Helion is a member of the Sinner Guild from the ancient world of
Mizar. Somehow he accidently got transported here and is trying
to fight his way out. Be careful, he's more dangerous then he looks!
EndText
   );
set_size(6);
set("id",({"sinner","helion","human"}));
set_name("helion the sinner");
set("gender","male");
set("race","human");
set("undead",0);
set("base_ac",1);
set("damage",({4,9}));
set("weapon_name","sword");
set_verbs(({"attack","slice","dice","impale","shred"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
"Helion looks around and wonders what happened to Shallar and Ilon.\n",
"Helion misses Mizar.\n",
"Helion pauses and mourns Gwenever... Karol left us too early.\n",
"Helion calls for a simp, but none come to help him.\n",
"Helion causes a scroll to appears and then claps his hands together to make it vanish.\n",
"Helion closes his eyes and meditates, but no one responds.\n",
    }) );
    set ("att_chat_output", ({
    }) );
set_level(18);
set("wealth",800);

wear("/u/s/shallar/armor/probes.c");
}

int special_attack() {
object ob = query_current_attacker();

if (!random(10)) {
tell_room(environment(TO),wrap("Helion claps his hands together "+
"and a purple fireball appears over his head engulfing "+ob->
query("cap_name")+"!"), ob);

tell_object(ob, wrap("Helion looks at you and claps his hands together, "+
"creating a large, purple fireballs which heads straight at you!"));
call_other("/d/class/wizard/spells/fireball.c","cast_bolt",
 "NONE", query_level() );
return 1;
}
return 0;
}
