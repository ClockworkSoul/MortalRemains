#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set("objects", (["shovel" : "/d/Prime/Magehouse/items/shovel.c"]) );
    reset();
    set( "short", "The Attic" );
    set( "long", @EndText
As you enter the attic, the smell of dust and old wood
assaults your nostrils. Crossbeams made of oak zigzag
over your head to form a spell of protection that shields
the entire house from unknown magical forces. You also
notice you are starting to feel like you're burning up.
EndText
    ); 
                    
    set( "exits", ([            
      "east" : N_ROOM+"attic3.c" 
    ]) );
}
void init() {
    call_out("do_fire_func", 60, TP);
}

int do_fire_func( object ob ) {
    if (environment(ob) != TO) return 0;
    tell_object(ob, "You feel yourself roasting slowly as if on a spit.\n");
    
    ob->receive_damage(ob->query_level()*6, "fire");
    
    call_out("do_fire_func", 60, ob);
    return 1;
}
