/*
** File: /u/n/nsd/lust/mare5.c
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
...The flower path continues to the south. The scent of
jasmines grows stronger as you advance. You hear a 
tiny voice crying for help. Sends chills up to your spine...
EndText
  );
  set( "exits", ([
"east" : LUST+"mare4.c",
"south" : LUST+"mare6.c",
  ]) );
set( "item_desc", ([

]) );
 set("objects", ([
"angelique" : NAZI_MON+"maid6.c",
 ]) );
reset();

}



