/*
**ilz
*/

#define COST 60
#define SUMMON ({ \
  "/d/Inner/monsters/airelem.c" \
  })

inherit SPELL;

int invoke_summonair (string str, int obj) {
   object monster, target;

   seteuid(getuid());
   if (!str) str = "NONE";
   if (str=="NONE") target=TP->query_current_attacker();

   if (!obj) {
      obj = query_caster_level(TP, "priest");
      if (!TP->invoke_spell(COST)) return 1;
   }

   monster=clone_object(SUMMON[random(sizeof(SUMMON))]);
     monster->set_level(random(13)+ 12);
     monster = summon(monster, TP);                 
   if (!monster) {
     write("Summons failed. Please notify Cyanide.\n");
     return 1;
   }

   TP->add("followers", ({ monster}) ); 
   TP->add("protectors", ({ monster }) );
 
   monster->add("protectees", ({ TP }));
 monster->set("weap_resist", 0);
   monster->move(environment(TP));
   if (target) monster->kill_ob(target);
   //target = clone_object("/adm/obj/summon_ob.c");

  write("You summon "+monster->query("short")+"!\n");
  say(TPN+" summons "+monster->query("short")+"!\n");
   return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Summon Air Elemental (Priest - Level VI - Summoning, Air)

Duration: permanent 	
Cost: 60 TP

	This spell summons an air elemental to aid
and protect the caster.
EndSpellcraft
    );
}
