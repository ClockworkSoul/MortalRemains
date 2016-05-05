// The inheritable weapon/armor object.
// See original weapon and armor code for the real headers.
#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

#include <value.h>

inherit "/std/raise_stats.c" ;

string *vb, *vb2 ;

void unequip(int silent) ;

int move (mixed dest) {

        object fellow ;

        fellow = environment(this_object()) ;
      if (fellow && query("worn")) unequip(0);
        return ::move(dest) ;
}

int remove() {

        object fellow ;

        fellow = environment(this_object()) ;
  if (fellow) 
   if (query("worn")) unequip(0); 
        return ::remove() ;
}

int is_weapon() {  return 1; }
int is_weaparm() { return 1; }

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
          class  = query("weapon") ;
    fellow->add("magical_offense", -1 * class) ;
                tmp = query("remove_func");
                if(tmp)  call_other(this_object(), tmp);
                if(!silent)
                tell_object(fellow,"You remove "+obj->query("short")+".\n") ;
                                if(fellow && environment(fellow) && !silent)
                tell_room (environment(fellow),fellow->query("cap_name")+" removes "+obj->query("short")+".\n",fellow) ;
                armor = fellow->query("armor") ;
                map_delete(armor,type) ;
                fellow->set("armor",armor) ;
  lower_stat();
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
