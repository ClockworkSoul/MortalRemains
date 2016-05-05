#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
  You are standing in a room filled with multiple television and
monitor screens, flashing neon and fluorescent lights, and a set
of all leather furniture.  You have entered Lysander's workroom.
EndText
  );
  set( "item_desc",
([
"televisions":"They crackle with static.\n",
"screens":"They crackle with static.\n",
"monitors":"They crackle with static.\n",
  "static":"It is completely random.\n",
"lights":
      "They emit a powerful glow.\n",
"fluorescent lights":"They emit a powerful glow.\n",
"neon lights":"They emit a powerful glow.\n",
"glow":"It seems to pulse eerily.\n",
"furniture":"It is of fine leather.\n",
"leather":"It looks very regal.\n",
]) );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
