/*
** File: /u/n/nsd/lust/mare4.c
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
jasmines grows stronger as you advance. You start
to realize those whines belong to a soul in pain. It gets
you pretty nervous...
EndText
  );
  set( "exits", ([
"east" : LUST+"mare3.c",
"west" : LUST+"mare5.c",
  ]) );
set( "item_desc", ([

]) );
set("objects", ([
"gina" : NAZI_MON+"maid5.c",
 ]) );
reset();

}



