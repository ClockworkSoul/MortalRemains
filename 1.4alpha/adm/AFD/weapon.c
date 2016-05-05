// Inheritable weapon object. For now.
// Mobydick@TMI-2, 9-11-92
// (05-28-96) Chronos added support for the new handedness code.
//            Cleaned up a bit too. :)
// modified to work with the weaparm code.
// modified again to remove all remaining references to attack_strength,
// which has long since been removed from the lib.  :D
// (09-??-96) Above comments made.. Chronos also cleaned up
//            everything in here.  Removed the screwed-up stupid code. :)

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;
#include <value.h>   // This has to go after the inherit line.  Trust me.
inherit "/std/raise_stats.c" ;

string *vb, *vb2 ;

void unwield(int silent);

int move (mixed dest) {
  if (environment() && query("wielded")) unwield(0);  // quiet.. 
        return ::move(dest) ;
}

int remove() {
   if (environment() && query("wielded")) unwield(0); // shh
        return ::remove() ;
}

int unwield(int silent) {
  object obj, fellow, leftwep ;
  string str, name ;
        int class ;

        fellow = environment(this_object()) ;
        if (fellow) {
    str = query("pre_unwield_func") ;
 if (str) if (call_other(this_object(), str) == 0) return 0;
                obj = this_object() ;
  leftwep = fellow->query("left_hand") ;
                if(!silent)
  tell_object(fellow, "You stop wielding "+obj->query("short")+".\n") ;
                if(fellow && environment(fellow) && !silent)
                tell_room (environment(fellow),fellow->query("cap_name")+" stops wielding "+obj->query("short")+".\n",fellow) ;
  if (obj==leftwep) fellow->delete("left_hand") ;
  else fellow->delete("right_hand") ;
        str = obj->query("unwield_func") ;
        if (str) call_other(obj,str) ;
        this_object()->lower_stat();
   }
  obj->delete("wielded") ;
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
varargs
int weapon_hit(int damage, object victim) { return 0 ;}

void set_type(string type) {
  set("type", type);
}

int is_weapon() {  return 1; }

int query_wc() { return query("weapon") ; }
