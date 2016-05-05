/*
**  File: imprison.c (Disintegrate)
**  Purpose: Combat spell
**  Effects: imprisons a target.
**  Cost: 120 SP (6th level evocation)
**  Credits:
**    9 Nov 97  Ilzarion created the file.
*/

#define COST 120
#define SYNTAX "Syntax: cast imprison at target\n"

#include <m_spells.h>
#include <mudlib.h>
#include <config.h>

 // Prototypes:
void do_swarm (object);
void begin_hell (object);

inherit SPELL;

varargs int cast_imprison (string str, int obj) {
   string name;
   object target = 0, caster;
   int x;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }     
   caster=TP;
   if (!check_valid_targ(TP, target)) return 0;
   if (!obj) {
      if (!cast_spell(TP, COST)) return 0; 
      obj = query_caster_level(TP, "wizard");
   }
      write("You grin evilly and begin casting Imprisionment...\n");
      say(TPN+" grins evilly and begins uttering arcane words...\n");

      tell_room(environment(TP), wrap(TPN+
         "'s hand begins to glow with arcane power!"), ({ caster, target }) );
      write("Your hands glow with power!\n");
      tell_object(target, TPN+" hands glow with power!\n");   
   x = caster->query_hit(target);
   name = target->query("cap_name");
   if (!visible(caster, target)) name = "Somebody";
   if (!check_magic_resist(obj,target,COST,1000)) return;

   if (!x) {
           tell_room(environment(target), target->query("cap_name")+
         " nimbly dodges the touch!\n", ({ caster, target }) );
       tell_object(target, "You manage to dodge the touch!!\n");
       write(target->query("cap_name")+" nimbly dodges the touch!\n");
         return 1;     
   }

   target->kill_ob(caster);
   target->set("last_attacker", caster);

     tell_room(environment(target), wrap(target->query("cap_name")+
       " screams as "+subjective(target->query("gender"))+" slowly "+
       " sinks into the ground.\n"), ({ caster, target }) );
     tell_object(target, "You look on in horror as you watch yourself slowly sinking into the ground!");
     write(target->query("cap_name")+" watches in horror as "
       +subjective(target->query("gender"))+" slowly sinks into the ground!\n");
     target->set("last_attacker", TP);
     target->move("/d/class/wizard/obj/prisonroom.c");
     
   return 1;
}
string spellcraft() {
    return (@EndSC
Imprisonment             [Level IX Mage spell, (Abjuration)]

Cost: 120 Spell Points           Area of Effect: 1 target

	Imprisonment allows the caster to imprison a target if
you successfully touch them.
EndSC
    );
}
