#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;
object kylie ;

void reset() {
  if (!kylie)
{
   kylie = clone_object("/d/Outer/Sigil/monsters/kylie") ;
   kylie ->move(TO) ;
  }
  ::reset() ;
}


void create() {
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand on Duskgate Road, one of the major streets in Sigil.
To your east lies a bazaar, and to your west lies a tattoo shop.
ENDLONG
  );
  set("short", "Duskgate Road, Market Ward.") ;
     set ("exits", ([
	"south" : SIGIL+"duskgatest1.c",
	"east" : SIGIL+"bazaar.c",
	"west" : SIGIL+"tattoos.c" ]));
  ::create() ;
reset();
	}
