// safe.c
// The location a player is brough to by OBJ+"goldring.c"

#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Sanctuary");
    set( "long", @EndText
You are in an endless void. There is nothing here.
Despite its emptiness, you feel rather safe here.
You know instinctively that if you wished, you could
'wish' your way back from where you came.
EndText
    );
}

void init()
{
    add_action( "wish", "wish" );
}

void reset() {
    object ob;

    ::reset() ;
    seteuid( getuid() );
    if (present( "torch", this_object() ) ) return;
    ob = clone_object("/obj/obj/torch.c");
    ob -> move(this_object());
}

int wish()
{
    this_player()->move_player(this_player()->query("last_location"));
    return 1;
}
