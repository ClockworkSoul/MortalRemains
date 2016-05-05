#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 1);
set ("area_type", ([
  "black" : 2,
  ]) );
set ("short", "Cliff Ledge");
  set( "long", @EndText
This is a rock-strewn ledge near the base of a tall cliff. The bottom of the
cliff is another fifteen feet below. You have little hope of climbing up the
cliff face, but you might be able to scramble down from here (though it's
doubtful you could return).
A long piece of rope is dangling down from the top of the cliff and is just
within your reach.
EndText
  );
  set( "exits", ([
"up" : MAIN+"/cliff.c",
"down" : MAIN+"/clbase.c",
  ]) );

set ("item_desc", ([
"ledge" : "It is large enough to hold you, but don't push it...\n",
"bottom" : "If you're lucky, you won't twist your ankle on the way down.\n",
"rope" : "As long as that's there, you can scramble up it.\n",
]) );
}
