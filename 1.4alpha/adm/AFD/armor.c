// Inheritable armor object. For now.
// Mobydick@TMI-2, 9-11-92
// Chronos changed it all to "worn" instead of "equipped".  :D
// (05-??-96) Chronos added the set_type() function and implemented
//            stat raising functions.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;
inherit "/std/raise_stats.c";

#include <value.h>

void unequip(int silent);

// Armor has its own move function which forces the player to unequip the
// armor if he drops it, gives it away, or otherwise moves it.

int move (mixed dest) {

        object fellow ;

        fellow = environment(this_object()) ;
        if (fellow) {
                if (query("worn")) {
                        unequip(0);
                }
        }
        return ::move(dest) ;
}

// Similarly, armor has its own remove function, to force the player to
// unequip the armor if it is dested or in some other way destructed.

int remove() {

        object fellow ;

        fellow = environment(this_object()) ;
        if (fellow) {
                if (query("worn")) {
                        unequip(0);
                }
        }
        return ::remove() ;
}

// The basic unequip procedure. Several commands can call this, which is why
// it is in the armor instead of in a command daemon. Unequip the object and
// alter the player's armor class.

void unequip(int silent) {

        object fellow, obj ;
        string type, tmp ;
        mapping armor ;
        int class ;

        fellow = environment(this_object()) ;
        if (fellow) {
                obj = this_object() ;
                type = obj->query("type") ;
                obj->set("worn", 0);
         tmp = query("pre_remove_func") ;
  if (tmp) if (call_other(this_object(), tmp)==0) return 0;
                if(!silent)
                tell_object(fellow,"You remove "+obj->query("short")+".\n") ;
                                if(fellow && environment(fellow) && !silent)
  message("say", fellow->query("cap_name")+ " removes "+obj->query("short")+
   ".\n", environment(fellow), ({ fellow }) ) ;
                armor = fellow->query("armor") ;
                map_delete(armor,type) ;
                fellow->set("armor",armor) ;
  lower_stat();
   tmp = query("remove_func") ;
  if (tmp) call_other(this_object(), tmp) ;
                return ;
        }
}

int set_ac(int x) {
  set("armor", x);
  return 1;
}

int set_type(string x) {
  switch(x) {
    case "body" :
   case "suit" : 
    case "vest" :
   case "armor" :
    case "armour" :
       set("type", "body"); break;
  case "gloves" :
   case "gauntlets" :
    set("type", "gloves"); break;
   case "helmet" :
   case "helm" :
    set("type", "helmet"); break;
  case "cloak" :
  case "hood" :
   case "cape" :
   set("type", "cloak"); break;
  case "boots": 
    set("type", "boots"); break;
  case "leggings" :
   set("type", "leggings"); break;
  case "bracers" :
  case "bracer" :
   set("type", "bracers"); break;
   case "amulet" :
  case "necklace" :
   set("type", "amulet"); break;
  case "ring" :
   set("type", "ring"); break;
  case "shield" :
    set("type", "shield"); break;
  default: set("type", "costume");  break;
 }
  if (!query("size")) set("size", 6);
}

int is_armor() { return 1; }
