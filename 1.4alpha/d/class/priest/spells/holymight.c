/*
** FILE:        enlarge.c
** PURPOSE:     2st level alteration spell.
** COST:        12 SP
** EFFECTS:     Increases subject's strength by an abount from 1-4 to
**              1-6, depending on level (max 18)
** DURATION:    1 minute/level.
** CREDITS: 
**    29 Sep 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 12

int invoke_holymight (string str ) {
  object targ, ob;
  int lvl = 0;

  seteuid(getuid());

  
  targ = TP;
  
   if (present("#HOLYMIGHT_OB#", targ)) {
    write("You already have a holymight spell active!\n");
    return 0;
  }

  if ((str != "strength") && (str != "dexterity") && (str != "constitution") ){
	write ("You can only enhance strength, dexterity or constitution.\n");
	return 0;
	}
    
    if (!TP->invoke_spell(COST)) { 
      write(NOT_ENOUGH_SP);
      return 0;
    }
    lvl = this_player()->query_level("priest");

    write("You cast holymight.\n");
    say (TPN+" draws upon the power of thier deity!\n");
   

  ob = clone_object("/d/class/priest/obj/holymight_ob.c");
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    return 0;
  }

  ob->move(targ);
  ob->begin_spell(targ, str);
  return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Draw Upon Holy Might (Priest - Level II - Summoning)

Duration: instant 		Area of Effect: 1 Target
Cost: 12 TP

	The caster may choose to increase one ability score 
(only Strength, Dexterity, and Constitution) by 
+1 per three levels of his experience.
When the spell ends, the energy abruptly leaves
the priest's body, leaving him physically drained
and unable to fight for a time.
EndSpellcraft
    );
}
