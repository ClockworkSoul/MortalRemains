// The Infamous Object Maker, by Chronos.
// This is the inheritable file that adds the "make" action to whatever
// object you inherit this into.  This is basically so Cyanide can add
// this shit to his black crystal staff.  :D
// (30 Aug 1999) Chronos begins the code.  [Y2k Compliant!]
inherit OBJECT ;
#include "/u/c/chronos/defs/objmaker.h"
string fix(string str) ;

void create() {
 seteuid(getuid()) ;
  set("short", "a blood-red orb") ;
   set("long", "It's boring.\n") ;
 set("id", ({ "orb", "toy" }) ) ;
  }
void init() {
  add_action("make", "make") ;
/*
  ::init() ;  // Call the original init to make sure you don't lose anything.
*/
}

int make(string str) {
  if (!str) {
    write(@ENDSHIT
 You sense that you can use the following commands:

      make object               Make a generic object with no special props.
      make weapon               Make a weapon.
      make armor                Make an armor.
      make monster              Make a living being.
      make room                 Make a room.


ENDSHIT
    );
    return 1;
  }
  switch(str) {
    case "object" :
    case "item"   :
      write("Enter the filename of the object you wish to create.\n]");
      input_to("item");
      break ;
    case "weapon" :
    case "wep" :
      write("Enter the filename of the object you wish to create.\n]");
      input_to("wep");
      break ;
    case "armor" :
    case "armour" :
    case "arm" :
      write("Enter the filename of the object you wish to create.\n]");
      input_to("arm");
      break ;
    case "monster" :
    case "being" :
    case "mon" :
      write("Enter the filename of the object you wish to create.\n]");
      input_to("mon");
      break ;
    case "room" :
      write("Enter the filename of the object you wish to create.\n]");
      input_to("room");
      break ;
    default:
      write(@ENDSHIT
 You sense that you can use the following commands:

      make object               Make a generic object with no special props.
      make weapon               Make a weapon.
      make armor                Make an armor.
      make monster              Make a living being.
      make room                 Make a room.


ENDSHIT
    );
      break ;
  }
  return 1;
}

int arm(string str) {
  call_other(OBJMAKER+"arm.c", "make_arm", fix(str));
  return 1;
}

int mon(string str) {
  call_other(OBJMAKER+"monster.c", "make_mon", fix(str));
  return 1;
}

int item(string str) {
  call_other(OBJMAKER+"item.c", "make_item", fix(str));
  return 1;
}

int room(string str) {
  call_other(OBJMAKER+"room.c", "make_room", fix(str));
  return 1;
}

int wep(string str) {
  call_other(OBJMAKER+"wep.c", "make_wep", fix(str));
  return 1;
}

string fix(string str) {
  string x;
  if (!str) return 0;
  if (sscanf(str, "%s.c",x)!=1) str=str+".c" ;
  if (sscanf(str, "/%s",x)!=1) return ((string)TP->query("cwd")+"/"+str) ;
  else return str ;
}
