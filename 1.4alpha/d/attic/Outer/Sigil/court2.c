#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
      	seteuid(getuid());
     set ("objects", ([ "nye" : "/d/Outer/Sigil/monsters/nye" ]) );
	reset();
     set ("light", 1) ;
  set("short", "Second Floor, Courthouse.") ;
  set("long", @ENDLONG
There are many offices here where you can hire the services of
lawyers to plead your case for you.
ENDLONG
  );
     set ("exits", ([
	"down" : SIGIL+"court.c",
	"up" : SIGIL+"court3.c" ]));
}
