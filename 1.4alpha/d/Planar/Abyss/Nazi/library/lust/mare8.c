/*
** File: /u/n/nsd/lust/mare8.c
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
...A dark dungeon that's been in oblivion for so long.
A strong scent of moisture comes from the walls. Spider
webs hang from the ceiling. You hear the squeeking of
rats. This place is tattered and old. There's nothing 
in it, except for a rocking chair that makes a crackling
sound as it swings.
EndText
  );
  set( "exits", ([
"south" : LUST+"mare7.c",
  ]) );
set( "item_desc", ([

]) );

set("objects", ([
"girl" : NAZI_MON+"child.c",
]) );
reset();
}


void init() {
add_action("open_portal", "open");
}

int open_portal(string str) {
write(
"The child opens a portal...\n");
say("As the child opens the portal, "+TPN+" and her are soaked into it.\n");
this_player()->move_player(LUST+"light.c"); //
say(TPN+" is blinded by a bright light...\n");

return 1;
}

/* EOF */
