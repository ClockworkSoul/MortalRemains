/*
** File: /u/n/nsd/lust/mare6.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include <config.h>
#include <mudlib.h>
#include "nazi.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set("author", "nsd");
set( "short", "Your nightmare is...");
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
set( "long",@EndText
...The flower path continues to the east. The scent of
jasmines grows stronger as you advance. You hear a 
desperate child cry for help. It starts to madden you...
EndText
  );
  set( "exits", ([
"north" : LUST+"mare5.c",
"east" : LUST+"mare7.c",
  ]) );
set( "item_desc", ([

]) );
 set("objects", ([
"michelle" : NAZI_MON+"maid7.c",
 ]) );
reset();

}



