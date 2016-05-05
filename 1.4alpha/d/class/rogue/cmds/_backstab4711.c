// DOne by Nightmask with a little help from Cyanide.

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>
#include <rogues.h>

int cmd_backstab2(string targ) {
   object ob, weapon, bksb;
   int *dmj, dmin, dmax, damage;
   int multiplier;
   int level;   //Forgot this, too.
   string type;

   if (!targ) {
     write("Backstab what?\n");
      return 1;
   }

   weapon = (object)this_player()->query("weapon1");

   if (!weapon) {
      write("You can't backstab with your bare hands!\n");
      return 1;
   }

   type = (string)weapon->query("damage_type");

   if (!this_player()->query("invisible")) {
      write("You're not hidden...  that target will see you coming!\n");
      return 1;
   }

   if (!weapon) {
      write("You need a weapon to backstab with!\n");
      return 1;
   }

   dmj = weapon->query("damage");
   ob = present(targ, environment(this_player()));

   if (!living(ob)) {
      say ("That's not alive!\n");
      return 1;
   }

   bksb = present("BACKSTABED", ob);
   if (bksb) {
      if (member_array((string)this_player()->query("cap_name"),
       (string *)bksb->query("backstabbed")) != -1) {
         bksb->add("backstabbed", ({ this_player()->query("name") }) );
      } else {
         write(ob->query("cap_name")+" is wary of you now...\n");
         return 1;
      }
   } else {
     bksb = clone_object("/d/class/rogue/obj/BACKSTABED.c");
      if (!bksb) {
         write("Your skills fail you.  Notify Nightmask.\n");
         return 1;
      }
      bksb->set("backstabbed", ({ this_player()->query("name") }) );
      bksb->move(ob);
   }


   level = TP->query_level("thief");
   dmin = dmj[0]; dmax = dmj[1];

   damage = random(1 + dmax - dmin) + dmin;
   write("Rolled: "+damage+"\n");
   if ((random(19)+1) >1){
     damage*=2;
     write("sdakjh.\n");
  }
write("time 3 = "+damage+"\n");

   multiplier = 0;
write("level="+level+"\n");
   switch (level) {
       case 0 : break;
       case 1..4 : multiplier+=6; break;
       case 5..8 : multiplier+=9; break;
       case 9..12 : multiplier+=12; break;
      case 13..16 : multiplier+=15; break;
      case 17..20 : multiplier+=18; break;
      case 21..24 : multiplier+=21; break;
      case 25..27 : multiplier+=24; break;
      case 28..29 : multiplier+=27; break;
      default : multiplier+=30; break;
  }

/*
write("Mult 1: "+multiplier+"\n");
*/
   if (present("#BKSB#", this_player())) {
      for(dmin=0;dmin<sizeof(all_inventory(TP));dmin++) {
        dmax = all_inventory(TP)[dmin]->query("bksb_mult");
         if (dmax) multiplier += dmax;
      }
   }

   damage*=multiplier;
   damage+=PROPERTY_D->query_str_dam(this_player());

/*
write("End mult: "+multiplier+"\n");
write("After stuff: "+damage+"\n");
*/

   this_player()->set("invisible", 0);
                                                     

  if (damage <= ob->query("hit_points")) {
   tell_object(ob, TPN+" sneaks out of the shadows and stabs you in the back.\n"
);
   write("You successfully stab "+ob->query("cap_name")+" in the back!\n");
   say(TPN+" steps out of the shadows and stabs "+ob->query("cap_name")+
      " in the back", ({ ob, this_player() }) );
   } else {
      write("You slay "+ob->query("cap_name")+" in one blow!\n");
     tell_object(ob,wrap("You are surprised to see a blade suddenly come"+
         " out of your gut!"));
      say(wrap(TPN+" steps out of the shadows behind "+
         ob->query("cap_name")+" as "+subjective(ob->query("gender"))+
        " slumps to the floor."), ({ TP, ob }) );
   }


   ob->receive_damage(damage, type, this_player());
   ob->kill_ob(this_player());
   return 1;
}                 
