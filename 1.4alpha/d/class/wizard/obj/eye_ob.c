/*
** File: eye_ob.c
** The spell that goes with "eye.c"
** See that file for more details.
*/

#include <m_spells.h>
#include <magic.h>
#include <mudlib.h>

#define PROMPT "Enter the next command for the eye: "

int end_spell (object);

inherit MONSTER;

object caster;
int duration = 100;

void create() {
   ::create();
   seteuid(getuid());

   duration = 100;
   set("vision", 1);
   set("short", "a floating eyeball");
   set("enchanted", MODERATE);
   set_level(1);
   set_name("floating eye");
   set("size", 1);
   set("long", @EndLong
It's a simple disembodied eyeball, floating in midair.
EndLong
   );
   set("id", ({ "eye", "floating eye" }) );
}

void execute_attack(int a, int b, int c) { return; }

void receive_message (string klass, string message) {
   tell_object(caster, "The eye sees:\n" + message);
   ::receive_message(klass, message);
}

int start_spell(object ob, int lvl) {
   caster = ob;
   duration = lvl * 30;
   caster->set("rest", 2);
   tell_room(environment(caster),
    caster->query("cap_name")+" goes into a deep trance.\n");
   tell_object(caster, PROMPT);
   input_to("next_command");
   return 1;
}

void heart_beat() {
   duration--;
   if (!duration) end_spell(caster);
   ::heart_beat();
}

int end_spell (object caster) {
   caster->delete("rest");
   tell_room(environment(caster), 
    "The eye drops to the ground and decays into dust.\n");
   remove();
}

void die() {
   object killer;

   killer = query("last_attacker");

   tell_object(caster, "** The eye has died. **\n");

   caster->receive_damage(10,"wizard",0,0);
   caster->set("last_attacker", killer);

   call_out("end_spell", 2, caster);
}

void init() {
   if (userp(environment(TO)))
      move(environment(environment(TO)));
}

int next_command (string str) {
   string dir;

   if (!str) {
      tell_object(caster, PROMPT);
      input_to("next_command");
      return 1;
   }

   switch (str) {
      case "north" :
      case "n" : str = "go north"; break;
      case "south" :
      case "s" : str = "go south"; break;
      case "east" :
      case "e" : str = "go east"; break;
      case "west" :
      case "w" : str = "go west"; break;
      case "northwest" :
      case "nw" : str = "go northwest"; break;
      case "northeast" :
      case "ne" : str = "go northeast"; break;
      case "southwest" :
      case "sw" : str = "go southwest"; break;
      case "southeast" :
      case "se" : str = "go southeast"; break;
      case "up" :
      case "u" : str = "go up"; break;
      case "down" :
      case "d" : str = "go down"; break;
      case "end" : str = "end spell";
      default : break;
   }

   if (str == "help") {
      tell_object(caster, @EndHelp
The following commands are valid when controlling the eye:

   go <direction>     Move in a direction. (n, s, w, e are valid)
   look at <item>     Look at something.
   exa <item>         Look at something.
   look               Looks at the room description.
   end spell          Ends the spell ("end" will also work)

EndHelp
      );

      tell_object(caster, PROMPT);
      input_to("next_command");
      return 1;
   }

   if (str=="look") {
      tell_object(caster, 
       "/cmds/std/_look.c"->look_in_room(environment(),0)+"\n");
      tell_object(caster, PROMPT);
      input_to("next_command");
      return 1;
   }

   if (str=="end spell" || str=="end") {
      end_spell(caster);
      return 1;
   }
   
   if (sscanf(str, "go %s", dir) == 1) {
      command(str);
      tell_object(caster, PROMPT);
      input_to("next_command");
      return 1;
   }
   
   if (sscanf(str, "look at %s", dir)==1 ||
    sscanf(str, "exa %s", dir)==1) {
      command ("look at "+dir);
      tell_object(caster, PROMPT);
      input_to("next_command");
      return 1;
   }

   tell_object(caster, "The eye doesn't understand that command. Type 'help'\n"+
    "for help.\n");

   tell_object(caster, PROMPT);
   input_to("next_command");
   return 1;
}

string query_min() {
   return "A floating eye drifts in\n";
}

string query_mout(string dir) {
   return ("A floating eye drifts "+dir+"\n");
}
