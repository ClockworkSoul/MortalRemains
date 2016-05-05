// Inheritable weapon object. For now.
// Mobydick@TMI-2, 9-11-92
// (05-28-96) Chronos added support for the new handedness code.
//            Cleaned up a bit too. :)
// modified to work with the weaparm code.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;
#include <value.h>   // This has to go after the inherit line.  Trust me.
inherit "/std/raise_stats.c" ;

string *vb, *vb2 ;

void unwield(int silent);

int move (mixed dest) {

        object fellow ;

        fellow = environment(this_object()) ;
        if (fellow && query("wielded")) unwield(0);
        return ::move(dest) ;
}

int remove() {

        object fellow ;

        fellow = environment(this_object()) ;
        if (fellow) {
                if ((object)fellow->query("left_hand")==this_object() ||
                    (object)fellow->query("right_hand")==this_object()) {
                        unwield(0);
                }
        }
        return ::remove() ;
}

int unwield(int silent) {

        object leftwep, rightwep, obj ;
        string str ;
        object fellow, wep ;
        string name ;
        int class ;

        fellow = environment(this_object()) ;
        if (fellow) {
                leftwep = fellow->query("left_hand") ;
                rightwep = fellow->query("right_hand") ;
                obj = this_object() ;
                if(!silent)
                tell_object (fellow,"You stop wielding "+obj->query("short")+".\n") ;
                
                if(fellow && environment(fellow) && !silent)
                tell_room (environment(fellow),fellow->query("cap_name")+" stops wielding "+obj->query("short")+".\n",fellow) ;
                if (obj==leftwep) {
                        if (rightwep) {
                               fellow->delete("left_hand");
     class = query("weapon") ;
   fellow->add("attack_strength", -1 * class) ;
                        } else {
   class = query("weapon");
   fellow->delete("left_hand") ;
   fellow ->add("attack_strength", -1 * class) ;
                        }
                } else {
                        if (leftwep) {
  class = query("weapon") ;
         fellow->delete("right_hand");
   fellow->add("attack_strength", -1 * class) ;
                        } else {
                                fellow->delete("right_hand");
    class = query("weapon") ;
    fellow->add("attack_strength", -1 * class) ;
                        }
                 }
        }
     obj->delete("wielded");
        str = obj->query("unwield_func") ;
        if (str) call_other(obj,str) ;
        this_object()->lower_stat();
}

void set_verbs(string *verbs) {

        int i ;
        string w1, w2 ;

        vb = verbs ;
        vb2 = allocate(sizeof(vb)) ;
        for (i=0;i<sizeof(verbs);i++) {
                if (sscanf(verbs[i],"%s %s",w1,w2)==2) {
                        vb2[i]=w1+"s "+w2 ;
                } else {
                        vb2[i]=verbs[i]+"s" ;
                }
        }
}

void set_verbs2 (string *verbs) {
        vb2 = verbs ;
}

string *get_verb() {
        int i ;
        i = random(sizeof(vb)) ;
        return ({ vb[i], vb2[i] }) ;
}

// This is for special hit functions in weapons.  
// It's a dummy function to insure that all weapons have one.
int weapon_hit(int damage) { return 0; }

void set_type(string type) {
  set("type", type);
}

int is_weapon() {  return 1; }

int query_wc() { return query("weapon") ; }
