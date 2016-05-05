
//ILZ
#include <m_spells.h>
#include <mudlib.h>

#define COST 80

inherit SPELL;

int invoke_regenerate(string str) {
  object ob;

  seteuid(getuid());

    if (present("#REGEN_OB#", TP)) {
    write("You already have a regenerate spell active.\n");
    return 0;
  }

 
    if (!TP->invoke_spell(COST)) return 0;
 

  ob = clone_object("/d/class/priest/obj/regen_ob.c");
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    say(TPN+" spells fizzles.\n");
    return 0;
  }
  ob->move(TP);
  ob->begin_spell(TP->query_level("priest"));
  return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Regenerate (Priest - Level VII - Necromantic)

Duration: 30 sec/lvl 		Area of Effect: Caster
Cost: 80 TP

	This spell grants swifter healing to the caster.
EndSpellcraft
    );
}
