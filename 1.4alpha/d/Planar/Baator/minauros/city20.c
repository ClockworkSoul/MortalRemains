#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("long", @EndLong
You are on the wide main street running though the Sinking City. All manner
of bizarre demon and fiend walk on this road, casting you sidelong glances
as you pass. To the east is the huge black palace of Minauros himself. The
road here curves to the south.
EndLong
    );
    set ("short","Main Street of Minauros");
    set ("exits", ([   
    "west" : BAATOR+"minauros/city19.c",
    "south" : BAATOR+"minauros/city27.c"
    ])); 
}