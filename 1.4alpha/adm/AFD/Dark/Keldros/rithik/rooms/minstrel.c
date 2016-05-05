#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "traveling minstrel");
  enable_commands();
  set("long", @ENDLONG
This is a small human wearing colorful garb and a warm smile.
ENDLONG
  );
  set_alignment(300);
  set_name("traveling minstrel");
  set("id", ({
    "minstrel",
    "traveling minstrel",
  }));
  
  credit(120 );
  set("damage", ({ 5, 15 }) );
  set("armor_class", 8);

  clone_object(OBJ(sbook.c))->move(TO);
  set("attack_strength", 18);
  set("race", "human");
  set("attrib1", "short");  set("attrib2", "slender");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "thwack",
    "jab",
}));
  
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 10, "strength");
  set_level(4);
  set("chat_chance", 1);
  set("chat_output", ({
    "The minstrel sings a happy tune.\n",
    "The minstrel reads a book of songs happily to himself.\n",
  }) );
  set("forgetful", 1);
call_out("wander", 50);
}

int alt_wander(){
  if(this_object()->query_current_attacker()) call_out("alt_wander", 140);
  if(file_name(environment(TO)) == "/d/Dark/Keldros/rithtik/rooms/main.c"){
        command("north");
  }
  if(file_name(environment(TO)) == "/d/Dark/Keldros/rithtik/rooms/street2.c"){
    int x;
     x = random(3);
       switch (x){
         case 0: command("south"); break;
         case 1: command("east"); break;
         case 2: command("west"); break;
       }
    }
    if(file_name(environment(TO)) == "/d/Dark/Keldros/rithtik/rooms/corner.c"){
    x = random(2);
       switch (x){
         case 0: command("south"); break;
         case 1: command("east"); break;
       }
}
call_out("wander", 140);
return 1;
}
int wander()
{
        int x;
   if(this_object()->query_current_attacker()) call_out("wander", 140);
        command("get all");
        x = random(10);
        switch(x)
        {
           case 1:
                {
                command("south");
                break;
                }
           case 2:
                {
                command("west");
                break;
                }
           case 3:
                {
                command("north");
                break;
                }
           case 4:
                {
                command("east");
                break;
                }
          case 5:
                {
                command("snap");
                }
        }
        call_out("wander", 140);
        return 1;
}