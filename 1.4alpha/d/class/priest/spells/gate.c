/*
** File: locate.c (Locate Creature)
** Purpose: 4th level wizard divination spell
** Cost: 30 SP
** Credits:
**   24 Nov 97  Cyanide created the spell.
*/

#define SYNTAX "Syntax: invoke gate <target>\n"
#define COST 100

#include <magic.h>
#include <m_spells.h>

inherit SPELL;

int invoke_gate(string str) {
   object where, here, target, gate;
   int found, lvl;

   if (!str) {
           write(SYNTAX);
      return NO_TARGET;
   } 

   str = lower_case(str);
   target = find_player(str);
  
   if (!target) {
       write(SYNTAX);
      return NO_TARGET;
   }


  
      if (!TP->invoke_spell(COST)) return NO_STRENGTH;
      lvl = query_caster_level(TP, "wizard");

      write("You begin casting Gate...\n");
      say(TPN+" begins uttering arcane words of power...\n");
 

   found = 1;
   where = environment(target);
   here = environment(TP);

   if (target->query_skill("nondetection")) found = 0;
   if (present("#NONDETECTION#", target)) found = 0;

   if (!where) {
      write(target->query("cap_name")+" is lost in the Void.\n"); 
      return SPELL_CAST;
   }

   if (!found) {
      write("That target cannot be located.\n");
      return SPELL_CAST;
   }
seteuid(getuid());
   if (where==here) {
   str = target->query("cap_name")+" is in the same room as you are!\n";
   } else {
     gate =  clone_object ("/d/class/priest/obj/gate_ob.c") ;
	gate->set("destination", file_name(here));
	gate->move(where);

 gate =  clone_object ("/d/class/priest/obj/gate_ob.c") ;
	gate->set("destination", file_name(where));
	gate->move(here);

	if (target->query_save()){
	str = target->query("cap_name")+" resists the force of your will!\n";
	tell_object(target, "A shimmering gate pulls you toward it, but you resist.\n");
	}else{
	str = target->query("cap_name")+" is forced to step through the gate by your force of will!\n";
	tell_object(target, "A shimmering gate appears and you are magically forced through.\n");
	target->move_player(here);
   }
}
   write(str);
   return SPELL_CAST;
}
string spellcraft() {
    return (@EndSpellcraft
Gate (Priest - Level VII - Summoning)

Duration: 1 minute 		Area of Effect: 1 Player
Cost: 100 TP

	This spell opens a portal to the target player
and attempts to force them to step through. The portal
is two-way, and lasts 1 minute.
EndSpellcraft
    );
}
