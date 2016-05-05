#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set( "short", "Rehnbi's Workroom" );
    set( "long", @EndText
You peer into the pitch blackness and see a pervasive
white light, beyond this light you see a large black septagon
outside the window.  The darkness seems to be created from
that shape and is lowering the lumination of the room to a 
tolerable level.  Looking deeper into the room you see
a desk that is cluttered with papers and that are spilling off
onto the floor.  There is a borded up portal to the VOID here.
EndText
    );
    set( "exits", ([
      "baator" : "/d/Outer/Baator/avernus/ave1.c",
      "wizrm" : "/d/Ancients/rooms/wizrm.c",
      "kyako's" : "/u/k/kyako/workroom.c",
      "castle" : "/u/r/rehnbi/rooms/fltcastl1.c",
      "mage" : "/d/class/wizard/general/rooms/m_lobby.c",
    ]));
}

/*
void init() {
    ::init();
}
*/
