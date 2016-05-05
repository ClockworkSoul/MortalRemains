//One of the higher level barbarian's in Ksamthgin forest.
//By Nightmask, July 1st, 1997

#include <mudlib.h>
#include "area.h"
inherit MONSTER ;

object sword, plate;
string query_weapon();

void create () {
  ::create();
  seteuid(getuid());
   set("author", "Nightmask the Dream Warden");
   set("short", "a Death Knight");
   set ("long", @Foo
A chill runs up your spine as he looks at you with hollow eyes.
The ery fires of hell burn within the empyt sockets. His armour is
black and chared, but looks as if it was once worthy of the upmost
honnor and fame.
Foo
);
   set("id", ({ "death knight", "knight" }) );
   set_name("death knight");
   set("gender", "male");
   set("race", "undead");
   set("undead", 100);
   enable_commands() ;
   set("magic_resist", 75);
   set("class", "WARRIOR");
// sword = clone_object("@@query_weapon");  
   sword = clone_object(query_weapon());
// "@@query_weapon" only works in "set" statements.
   sword->move(this_object());
   plate = clone_object(ARM+"dplate.c");
   plate->move(this_object());
   set_skill("Long Blades", 4, "Strength");
   set_skill("Short Blades", 4, "Strength");
   set("natt", 2);
   set ("attack_strength", 5);
   set ("damage", ({ 4,10 }) );
   set ("weapon_name", "massive fists");
   set("stat/constitution", 18);
   set ("stat/strength", 18);
   set("stat/dexterity", 16);
   set("wealth", 500);
     set_verbs( ({ "punch at", "swing at" }) ) ;
     set_verbs2( ({ "punches at", "swings at" }) ) ;
   set ("chat_chance", 10);
   set ("chat_output", ({
   }) );
   set ("att_chat_output", ({
   }) );
   set_level(15);
   // Set_level() needs to be on the bottom of the create() func.
}


   string query_weapon() {
     string str;
       int num = random(4);

      switch(num) {
       case 0 : str = "/d/Prime/Toril/Arabel/weap/knightsword1.c"; break;
       case 1 : str = "/d/Prime/Toril/Arabel/weap/knightsword2.c"; break;
       case 2 : str = "/d/Prime/Toril/Arabel/weap/knightsword3.c"; break;
       case 3 : str = "/d/Prime/Toril/Arabel/weap/knightsword4.c"; break;
     }
   return str;
}

void init() {
   command ("wield sword");
   command ("equip");
   
}
