
#include <mudlib.h>
#include "/u/d/dragoon/include/format.h"

inherit ROOM ;

void create()
{
    ::create() ; 
    set ("light", 1) ;
    set ("short", "Yvan's private study") ;
    set ("long", format (
	"my study needs a description and a lock. "
      )) ;
    set ("exits", ([
      "workroom" : "/u/y/yvan/workroom.c",
    ])) ;
}


