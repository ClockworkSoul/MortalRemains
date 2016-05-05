#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"dis/dplain2.c"]));
   set("objects", ([
    "portal" : BAATOR+"dis/portal1",
  ]) ) ;
  reset() ;
}
