#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short","Throneroom of Bel, the Warlord of Avernus.");
    set ("long", "@@query_long");
    set ("exits", ([
      "down" : BAATOR+"avernus/fortbel8.c"
    ]));
    set("item_desc", ([
        "throne" : "It is made to look as though it is constructed from "+
            "thousands of metal\nbones from hundreds of beings. The "+
            "overall impression is both\noverwhelmingly impressive and "+
            "nauseatingly horrid.\n",
    ]) );
    set ("objects" , ([ "bel" : BAATOR+"monsters/bel" ]));
    reset();
}


string query_long() {
    string str = (@EndText
You enter a massive chamber constructed completely of iron. A massive iron
throne is at the back of the room, the solid metal back of which is 
stylized and decorated to the point where it has spread to cover the 
entire wall it is set upon.
EndText
    );

    if (present("bel", TO))
        str += "Bel, the Lord of Avernus, the First Layer of Baator, "+
            "is seated upon the\nIron Throne, dwarfing even it.\n";

    return str;
}