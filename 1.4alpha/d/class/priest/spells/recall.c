/*
**ilz
*/

#define COST 60

inherit SPELL;


int invoke_recall () {
	int i;
   object env;
	string target;
   seteuid(getuid());
  
        if (!TP->invoke_spell(COST)) return 1;
  
switch(TP->query("deity")){

	case "tempus" : target = "/d/class/priest/battleguard/rooms/priest_guild.c";break;
	case "oghma" : target = "/d/class/priest/lorekeeper/rooms/priest_guild.c";break;
	case "talos" : target = "/d/class/priest/stormlord/rooms/priest_guild.c";break;
	default : target = "/d/Outer/Sigil/mainst1.c";break;
  }
  
  write("You recall yourself to the sanctuary of your priesthood!!\n");
say(TP->query("cap_name")+" returns to thier sanctuary!!\n");

 TP->move_player(target);
 return 1;
 }
string spellcraft() {
    return (@EndSpellcraft
Word of Recall (Priest - Level VI - Summoning)

Duration: instant 		Area of Effect: Caster
Cost: 60 TP

	This spell instantly transports the caster to
thier temple of thier diety.
EndSpellcraft
    );
}



