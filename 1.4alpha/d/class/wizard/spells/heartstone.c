/*
** File: heartstone.c
** Purpose: heart of stone
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 100

string help();

int cast_heartstone () {
  object shield;

  seteuid(getuid());

  if (present("#HEARTSTONE_SPELL#", TP)) {
    write("You already have a heart of stone!\n");
    return 0;
  }

  if (!TP->cast_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting Heart of Stone.\n");
   write ("Your body becomes fortified and resistant to harm.\n");

  say ("Begins muttering arcane verses...\n");

  shield = clone_object(M_OBJ(heartstone_ob.c));
  if (!shield) {
    write("Your spell fizzles.  Contact Cyanide.\n");
    say(TPN+"'s spell fizzles...\n");
    return 0;
  }

  shield->move(TP);
  shield->begin_spell(TP);
  return 1;
}

string spellcraft() {
    return (@EndSpell
Heart of Stone (Level VIII Wizard Spell - Alteration, Necromancy)

Cost: 100 Spell Points				Area of Effect: Caster
Duration: 20 sec/lvl

	This potent spell exchanges the necromancer�s own living 
heart for a finely crafted heart of perfect, unblemished stone 
that alters the very nature of the wizard�s body. As long as the
heart of stone remains in effect, the caster need not fear attacks
that pierce, slash, or cut him; he does not bleed and can ignore
the most horrible injuries of this kind. The disadvantage to all this
is that most forms of healing are ineffective on the caster.
EndSpell
    );
}

/* EOF */
