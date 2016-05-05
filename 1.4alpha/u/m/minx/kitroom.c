#include <mudlib.h>


inherit ROOM ;

void create() {
                ::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the Kitten Room for lack of a better,\n"+
"idea. It's the kitten room for obvious reasons,\n"+
"It's filled with kittens.\n"+
"You wind you way amongst running, pounceing kittens.\n");
set ("short","The Kitten Room");
     set ("exits", ([   
     "north":"/u/m/minx/workroom.c" ]));
reset();                                                            


        }
int reset(){
object ob1, ob2, ob3, ob4;
::reset();
 seteuid(getuid()) ;  
if (present("kitten", this_object())  ) return 1;
ob1 = clone_object("/u/m/minx/kitten.c");
ob1->move(this_object());
ob2 = clone_object("/u/m/minx/kitten.c");
ob2->move(this_object());
ob3 = clone_object("/u/m/minx/kitten.c");
ob3->move(this_object());
ob4 = clone_object("/u/m/minx/kitten.c");
ob4->move(this_object());
ob1->set("protectors", ({ ob2, ob3, ob4 }));
ob1->set("protectees", ({ ob2, ob3, ob4 }));
ob2->set("protectors", ({ ob1, ob3, ob4 }));
ob2->set("protectees", ({ ob1, ob3, ob4 }));
ob3->set("protectors", ({ ob2, ob1, ob4 }));
ob3->set("protectees", ({ ob2, ob1, ob4 }));
ob4->set("protectors", ({ ob2, ob1, ob3 }));
ob4->set("protectees", ({ ob2, ob1, ob3 }));
ob1->set("no_attack",0);
ob2->set("no_attack",0);
ob3->set("no_attack",0);
ob4->set("no_attack",0);
return 1;

}