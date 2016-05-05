//Last edited by Morrigu 4/29/97
//from generic workroom "workroom.c"
#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
seteuid(geteuid());
  set( "light", 1 );
set( "short", "Morrigu's workroom");
set("c_long", @EndText
This is Morrigu's workroom.
It's a small, square, white room with no obivious
enterances, but it has several exits...  How does
that work?
EndText
);
  set( "exits", ([
   "north" : "~morrigu/workroom2.c",
   "south" : "~morrigu/workroom2.c",
   "east" : "~morrigu/workroom2.c",
   "west" : "~morrigu/workroom2.c",
   "up" : "~morrigu/workroom2.c",
   "down" : "~morrigu/workroom2.c",
    "start" : START,
    "void"  : VOID,
  ]) );
}
