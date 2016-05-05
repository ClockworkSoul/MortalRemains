#include <newbie.h>
#include <config.h>
#include <mudlib.h>

inherit DOORS;

inherit ROOM;
void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Attic");
    set( "long",@EndText
As you enter the attic, the smells of dust and old wood
assault your nostrils. Crossbeams made of oak zigzag
over your head to form a spell of protection that shields
the entire house from unknown magical forces. You also
notice that it is quite warm here.
EndText
    );
    set( "exits", ([
"west" : N_ROOM+"attic2.c",
"down" : N_ROOM+"room16.c",
    ]) );
    
create_door("down", "up", "A strong wooden door "+
"which forms another complex spell of magic within its "+
"framework.", "locked", "magic key", 25);
    
}


/* EOF */
