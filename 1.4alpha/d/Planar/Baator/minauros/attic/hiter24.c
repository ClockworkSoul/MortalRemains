#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in a city of chains.\n"+
"Chains reach into the skies and even the buildings themselves.\n"+
"Are fashioned from this odd material.\n");
set ("short","Jangling Hiter, city of chains");
     set ("exits", ([   
          "east" : BAATOR+"minauros/hiter25.c"]));
  ::create();  // Chronos added this line to prevent monster
               // errors from making this room have no exits.
reset();
	}
int reset(){
// object ob1, ob2, ob3 ;
// Chronos saves variables and memory!
object ob1, ob2 ;
::reset();
 seteuid(getuid()) ;  
if (present("kocrachon", this_object()) || present("cornugon", this_object())  ) return 1;
/* Completely commented out by Chronos.
ob1 = clone_object(BAATOR+"monsters/cornugon");
  if (ob1)    // This line added by Chronos to prevent silly error.
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/kocrachon");
ob2->move(this_object());
ob3 = clone_object(BAATOR+"monsters/kocrachon");
ob3->move(this_object());
ob1->set("aggressive", 9);
ob2->set("aggressive", 9);
ob3->set("aggressive", 9);
*/
// Completely rewritten by Chronos to insure no silly loading errors.  :)
  ob1 = clone_object(BAATOR+"monsters/cornugon");
  if (ob1) {
  ob1->move(TO) ;
  ob1->set("aggressive", 9) ;
  }
  ob2 = clone_object(BAATOR+"monsters/kocrachon") ;
  if (ob2) {
  ob2->move(TO);
  ob2->set("aggressive", 9) ;
  }
  // Reusing the variable ob2.  I love saving memory! :)
  ob2 = clone_object(BAATOR+"monsters/kocrachon") ;
  if (ob2) {
  ob2->move(TO);
  ob2->set("aggressive", 9) ;
  }   
  // END of Chronos Mod.
return 1;
}

