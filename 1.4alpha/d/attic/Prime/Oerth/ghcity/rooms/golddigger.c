#include <mudlib.h>
#include "oerth.h"
inherit PUB ;

void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
set("objects", ([ "axel" : "/d/Prime/Oerth/ghcity/monster/axeltharnhew.c", "glenda" : "/d/Prime/Oerth/ghcity/monster/glendasilvertoe.c" ]) );
reset();
     set ("long",
 "This the the Gold Digger Tavern. A rather run down \n"+
 "bar in the Old City. It's the best your going to get \n"+
 "unless they allow you into the High Quarter. \n"+
"Commands are: menu , buy <drinkname>, powerheal <drinkname>\n");
     set ("short", "The Gold Digger Tavern") ;
     set ("exits", ([
     "east" : Oerth+"/rooms/proc2",
     ]) );
}
