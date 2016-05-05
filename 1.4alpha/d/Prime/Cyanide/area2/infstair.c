#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "cyanide");
    set ("short", "An Endless Staircase" );
    set( "long", @EndText
    You find yourself on an ancient staircase carved directly
from the living stone. You lose sight of the steps both above
and below you as they gently round a bend.
    You begin to feel very uneasy.
EndText
    );
    set( "exits", ([
      "up" : MAIN+"/hallway.c",
      "down" : MAIN+"/infstair2.c"
    ]) );
}
