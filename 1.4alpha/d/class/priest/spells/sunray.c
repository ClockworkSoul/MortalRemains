
#define COST 80
#define SYNTAX "Syntax: invoke sunray at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;



varargs int invoke_sunray (string str) {   
   object target, ob;
   int x;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   
   if (!check_valid_targ(TP, target)) return 0;
   if (!TP->invoke_spell(COST)) return 0;

   if (present("#SUNRAY#", target)){
   write("They already are bathed in sunlight!\n");
   return 1;
   }

      write("You call down a sunray upon "+target->query("cap_name")+"...\n");
      say(TPN+" calls down brilliant beams of light...\n");

    ob = clone_object("/d/class/priest/obj/sunray_ob.c");
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    say(TPN+" spells fizzles.\n");
    return 0;
  }
  ob->move(target);
  ob->begin_spell(TP);
  ob->kill_ob(TP);
  return 1;
  
}

string spellcraft() {
    return (@EndSpellcraft
Sunray (Priest - Level VII - Sun)

Duration: d4+1 rounds 		Area of Effect: 1 Target
Cost: 80 TP

	This spell bathes the target in searing rays of
light. Undead are especially suceptible to this spell.
EndSpellcraft
    );
}
