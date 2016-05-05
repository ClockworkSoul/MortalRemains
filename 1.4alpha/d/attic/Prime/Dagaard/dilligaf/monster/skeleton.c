#include <mudlib.h>
inherit MONSTER ;

object axe;

void create () {
  ::create();
  seteuid(getuid());
   set("short", "a skeleton");
   set ("long", @Foo
This is one of the lower members of the undead, his hollow sockets 
stare back at you with malicious intent. Be wary for even though
he has no flesh left on his bones...he looks strong and dagerous.

Foo
);
   set("id", ({ "skeleton" }) );
    set_level(1+random(3));
  set("aggressive" , 50);
   set_size(6);
   set_name("a skeleton");
   set_living_name("skeleton");
   set("gender", "male");
   set("race", "skeleton");
   set("undead", 1);
   axe = clone_object("/doc/examples/axe.c");
   axe->move(this_object());
   set("damage", ({ 1,4 }) );
   set("weapon_name", "skeletal fists");
   set_verbs( ({ "smack", "uppercut" }) );
   set_verbs2( ({ "smacks", "uppercuts" }) );
   enable_commands() ;
   set("natt", 1);
   set ("chat_chance", 10);
   set ("chat_output", ({
   }) );
   set ("att_chat_output", ({
   }) );
}

void init() {
   command("wield axe");
 }
