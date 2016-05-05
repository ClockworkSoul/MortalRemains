#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("light", 0);
set ("short", "Creepy Crawl");
  set( "long", @EndText
You are in a dark and quite creepy crawlway with passages leaving to the
north, south, and southwest.
EndText
  );
  set( "exits", ([
"southwest" : MAIN+"/LOS01.c",
"north" : MAIN+"/junction.c",
"south" : MAIN+"/foggy.c"
  ]) );

set ("item_desc", ([
]) );
}
