/*
** Done by Nightmask with a little help from Cyanide.
** 30 Sep 97 - Cyanide fixed a damage type error and neatened Ilzarion's
**    LAZY code.  ;)
**  8 Oct 97 - It would appear Ilzarion added weapon + restrictions?
**    Cyanide did this header.
**  9 Oct 97 - Cyanide fixed a logic bug in Ilz's previous fix. No biggie.
*/

inherit DAEMON;

#include <daemons.h>
#include <mudlib.h>
#include <rogues.h>

int cmd_backstab2 (string targ) {
   object ob, weapon, bksb;
   int *dmj, dmin, dmax, damage;
   int multiplier, hit;
   int level;   //Forgot this, too.
   string type;

   if (!targ) {
     write("Backstab what?\n");
      return 1;
   }
  
   weapon = (object)this_player()->query("weapon"+
     (this_player()->query("handedness")));

   if (!weapon) {
      write("You can't backstab with your bare hands!\n");
      return 1;
   }

   if (!this_player()->query("invisible")) {
      write("You're not hidden...  that target will see you coming!\n");
      return 1;
   }

   if (!weapon) {
      write("You need a weapon to backstab with!\n");
      return 1;
   }

   if (((string)weapon->query("weapon_type") != "Short Blades") && ((string)weapon->query("weapon_type") != "Long Blades")) {
      write("You can't backstab with that!\n");
      return 1;
   }
 
   dmj = weapon->query("damage");
   type = weapon->query("damage_type");
   ob = present(targ, environment(this_player()));

   if (!ob) {
      write("There's nothing by that name to backstab.\n") ;
      return 1;
   }    

   if (!living(ob)) {
      write ("That's not alive!\n");
      return 1;
   }

   if (ob->query("no_attack")) {
  write("You are not permitted to attack that.\n") ;
                return 1;
        } 

   bksb = present("BACKSTABED", ob);
   if (bksb) {
      if (member_array((string)this_player()->query("name"),
       (string *)bksb->query("backstabbed")) == -1) {
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

//write("range: "+dmin+" to "+dmax+"\n");
//write("type: "+type+"\n");
   damage = random(1 + dmax - dmin) + dmin;

//write("Rolled: "+damage+"\n"); 

 damage+=PROPERTY_D->query_str_dam(this_player()); 
   damage+=(int)weapon->query("dam_adj");
   damage+=(int)weapon->query("temp_dam_adj");
   hit = 4;
   hit+=(int)weapon->query("temp_to_hit");
    hit+=(int)weapon->query("to_hit_adj");
   multiplier = 0;

//write("level="+level+"\n"); 

   switch (level) {
      case 0..29 : break;
      case 30..33 : multiplier+=30; break;
      case 34..38 : multiplier+=32; break;
      case 39..43 : multiplier+=34; break;
      case 44..48 : multiplier+=36; break;
      case 49..53 : multiplier+=38; break;
      case 54..58 : multiplier+=40; break;
      case 59..63 : multiplier+=42; break;
      case 64..68 : multiplier+=44; break;
      case 69..73 : multiplier+=46; break;
      case 74..78 : multiplier+=48; break;
      case 79..83 : multiplier+=50; break; 
      case 84..88 : multiplier+=52; break;
      case 89..93 : multiplier+=54; break;
      case 94..97 : multiplier+=56; break; 
      case 98..99 : multiplier+=58; break;
      default : multiplier+=60; break;
  }
  if (userp(ob)) multiplier*=2;
 write(damage+" damage\n");

 damage*=multiplier;
//write("Mult 1: "+multiplier+"\n"); 
   if (present("#BKSB#", this_player())) {
      for(dmin=0;dmin<sizeof(all_inventory(TP));dmin++) {
        dmax = all_inventory(TP)[dmin]->query("bksb_mult");
         if (dmax) multiplier += dmax;
      }
   }

//ilz puts in criticals cause it seems to be missing
//write("b4 crit: "+damage+"\n");  

    if (random(20) == 0) damage *= 2;

//write("after crit: "+damage+"\n"); 

//write("After stuff: "+damage+"\n");  

   this_player()->set("invisible", 0);

   if (this_player()->query_hit(ob, hit)) {                                                     

   dmin = ob->query("weap_resist");
   if (!dmin) dmin = 0;
   dmax = (weapon->query("enchantment"));
   if (!dmax) dmax = 0;
	 
      if (dmax >= dmin){    

         if (damage <= ob->query("hit_points")) {
            tell_object(ob, TPN+" sneaks out of the shadows and stabs you"+
             " in the back.\n");
            write("You successfully stab "+ob->query("cap_name")+
             " in the back!\n");
            say(TPN+" steps out of the shadows and stabs "+
             ob->query("cap_name")
             +" in the back", ({ ob, this_player() }) );
         } else {
            write("You slay "+ob->query("cap_name")+" in one blow!\n");
            tell_object(ob,wrap("You are surprised to see a blade suddenly"
             + " come out of your gut!"));
            say(wrap(TPN+" steps out of the shadows behind "+
             ob->query("cap_name")+" as "+subjective(ob->query("gender"))+
             " slumps to the floor."), ({ TP, ob }) );     
         }

         damage = ob->receive_damage(damage, type, this_player(), 1);

         write("If this number is 0: ----> "+damage+"\n"+
          "The prob is the damage type or receive damage.\n");

         ob->set("last_attacker", this_player());
         ob->kill_ob(this_player());

      } else {
         write("Your weapon is useless against "+ob->query("cap_name")+"!\n");
      }

      ob->kill_ob(this_player());

   } else {
      write("You miss!\n");
      tell_object(ob,wrap("You are surprised to see a blade pass within "+
       " inches of you!"));
      say(wrap(TPN+" steps out of the shadows behind "+
      ob->query("cap_name")+" and misses."), ({ TP, ob }) );                 
      ob->kill_ob(this_player());
   }

   return 1;
}

/* EOF */
