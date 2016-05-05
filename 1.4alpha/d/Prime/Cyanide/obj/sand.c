// sand.c
// The invisable container at the bottom of
// /d/Magic/wforest/dark/main/lakebottom.c

#include "obj.h"
#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

void create() {
object ob;
   ::create() ;
  set("id", ({"sand", "dirt", "bottom" }));
  set ("author", "Cyanide the Sandy Mage");
  set_closed_long("A container. Its lid is closed.\n") ;
  set_open_long("The sandy bottom of the lake. There appears to be something
shiny in it.\n");
  set_possible_to_close(0) ;
  set ("bulk", 250000) ;
  set ("mass", 250000) ;
  set ("capacity", 1000) ;
  set ("volume", 225) ;
  set ("value", ({ 3, "gold" }) ) ;
  set("lock", 0);
  set("prevent_insert","This container doesn't see to be able to fit"+
        " inside another container.\n");
  set("prevent_get", 1) ;
  set("extra_look", "THIS PLAYER HAS AN ILLEGAL ITEM!\n");

ob = clone_object(OBJ+"/goldring.c");
ob -> move(this_object());

}
void init() {
        container::init() ;
        lock::init() ;
}