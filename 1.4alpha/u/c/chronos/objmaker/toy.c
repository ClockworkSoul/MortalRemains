#include <mudlib.h>

inherit OBJECT ;
inherit "/u/c/chronos/objmaker/objmaker.c" ;

void create() {
   seteuid(getuid()) ;
  set("short", "a simple toy") ;
    set("long", "A non-descript toy.\n") ;
}


void init() { }
