#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;
object bed, hottub;
void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set("short", "Shya's Bedroom");
set("long", @EndText
This room is Shya's private domain.  
Everything that is said and done in here stays.
On one wall you see an Ansel Adams hanging in a black frame.
On another wall there is a large picture window overlooking her
winter wonderland. There is plenty of room for fun and games 
among all those multi-colored pillows stacked everywhere.
EndText
  );
  set( "exits", ([
"workroom" :"/u/s/shya/workroom.c",
"shallar" : "u/s/shallar/workroom.c" 
  ]) );

  bed=clone_object("/u/s/shya/private/bed.c");
   bed->move(this_object());
  hottub=clone_object("/u/s/shya/private/special.c");
   hottub->move(this_object());

  set("item_desc", ([
    "bed" : "This bed is fit for a king and his many mistresses.",
    "pillows" : "Light and fluffy and multi-colored, good enough for a pillow fight.\n"]));

  set("pre_exit_func", ([
        "start" : "handcuff_check",  
        "home" : "handcuff_check",
    ]) );
    reset();
}
int handcuff_check() {
    if (present("handcuffs", TO)) {
        write("You are in the only place to be when Shya's"+
              "prisoner.\n");
        return 1;
    }
else {
    return 0;
}
}

