#include <config.h>
#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "Saint Xavirous");
  set("long", @ENDTEXT
This is the Temple of Saint Xaviorious. The room
is filled with a aura of holy power. There are rows 
of pews and in the back is the altar with a statue of
a person.  The Priest stands behind the altar reading a book.
ENDTEXT
);
  set( "exits", ([
          "southeast" : AROOM+"street14.c",
  ]) );
  set("item_desc", ([
       "statue" : "The statue resembles an old man.
He has Very deep set eyes and it looks like his skin is just
hanging on his bones. He carries a book in his right hand,
in his left is a glowing ball.\n",
       "ball" : "It contains swirling colors that change constantly
Funny, but it seems to pluse as if it was a heartbeat.\n",
       "altar" : "The altar seems to be just a stone slab floating above
the floor. there are candles burning and the faint smell of Patchulli
waifting in the air.  There is a open book on the altar and a 
sacrifical dagger.\n",
       "book" : "And on the glorious day our lord stood up before the
vile dragons and spoke the words of power.  Down from the heavens came 
the beasts of Evil. Down into the pit of Ghenna......\n",
 ]) );
}
