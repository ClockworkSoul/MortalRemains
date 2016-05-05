#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    set("author", "cyanide");
    seteuid(getuid());
    set("forbidden", 1);
    set ("short", "An Endless Staircase") ;
    set( "long", @EndText
    You find yourself on an ancient staircase carved directly
from the living stone. You lose sight of the steps both above
and below you as they gently round a bend.
    You begin to feel very uneasy.
EndText
    );
    set( "exits", ([
      "up" : MAIN+"/infstair.c",
      "down" : MAIN+"/nartunn.c",
    ]) );
}
