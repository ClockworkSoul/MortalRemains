#include <newbie.h>

inherit ROOM;

void create(){
   ::create();
   seteuid(getuid());
   set("author","cattt");
   set("light",1);
   set("short","A large playground.");
   set("long", @End
WOW, does this place look like a kid's wet dream or what?  All the
fun toys to play with.  The question is where does one begin?!
End
);
    set("item_desc", ([
      "playground":"Large and full of toys, this place is heaven.\n",
      "toys":"You see a variety of toys to go try out.\n",
     ]));
    set("smell","The smell of sweat from all the action is everywhere.\n");
    set("exits", ([
        "out" : M_ROOM+"path2.c",
        "slide": M_ROOM+"slide.c",
        "swing": M_ROOM+"swing.c",
        "horsey": M_ROOM+"horsey",
        "sand box": M_ROOM+"sandbox.c",
        
     ]));
}
