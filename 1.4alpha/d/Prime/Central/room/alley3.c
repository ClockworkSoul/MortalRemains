#include <mudlib.h>
#include <central.h>

inherit ROOM;
void create(){
    ::create();
    set( "light", 0 );
    set( "short", "Dead end in alley" );
    set( "long", wrap(
	"You have reached a point in the alley where it appears you can go "+
	"no further due to a high stone wall. Huge piles of garbage cover "+
	"every inch of ground here. The horrible reek of it makes you dizzy."
	" There is a wooden door to the south, barely attached to the "+ 
	"wall by rusty hinges."
      ) );
    set( "item_desc", ([
      "wall" : "It is a really high brick wall.\n",
      "garbage" : "The garbage piles are incredibly nasty and smelly.\n",
    ]) );
    set( "exits", ([
      "west"  : M_ROOM+"alley2.c",
      "south" : "/d/class/rogue/thief/room/thief_guild",
    ]) );
}
