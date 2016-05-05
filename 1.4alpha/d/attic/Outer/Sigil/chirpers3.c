#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

object barmaid ;
void create() {
  seteuid(getuid()) ;
     	seteuid(getuid());
   set("objects", ([
   "adamok" : "/d/Outer/Sigil/monsters/adamok",
  ]) ) ;
          set ("light", 1) ;
     set ("long",
@ENDLONG
You are in the east room of the second level in Chirpers Pub.
Sigil's finest and not-so-finest mingle in this large dining area.
ENDLONG
  );
  set("short", "Chirpers.") ;
     set ("exits", ([
     "west" : SIGIL+"chirpers2.c" ]));
   ::create();
   reset() ;
}

void reset() {
  // since the barmaid is moving, we have to track her this way.
  if (!barmaid) {
   barmaid = clone_object("/d/Outer/Sigil/monsters/barmaid") ;
   barmaid -> move(TO) ;
  }
  ::reset() ;
}

