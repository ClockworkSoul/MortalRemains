/*
** File: /u/n/nsd/lust/mare3.c
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
...The flower path continues to the west. The scent of
jasmines grows stronger as you advance, and so do the
screams. Every whine pierces your brains and soul...
EndText
  );
  set( "exits", ([
"south" : LUST+"mare2.c",
"west" : LUST+"mare4.c",
  ]) );
set( "item_desc", ([

]) );
set("objects", ([
"dione" : NAZI_MON+"maid4.c",
 ]) );
reset();

}



