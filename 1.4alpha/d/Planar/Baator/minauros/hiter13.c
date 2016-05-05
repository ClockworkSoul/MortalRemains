#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

string query_sign();

void create() {    
    ::create();
    add ("long", wrap("There is a large greenish portal here, beside "+
	"which which is an ancient wooden sign.") );
    add("item_desc", ([ 
      "sign" : "@@query_sign"
    ]) );
    set ("exits", ([       
      "portal" : BAATOR+"dis/dtower1.c",
      "east" : BAATOR+"minauros/hiter14.c"
    ]));
}

void init() {
    add_action("read", "read");
}

int read( string str ) {
    if (str=="sign") {
	write(query_sign());
	return 1;
    }

    write("Read what?\n");
    return 1;
}

string query_sign() {
    return (@EndSign
                              -----------------------------
                              | Welcome to Jangling Hiter |
                              |    The City of Chains     |
                              -----------------------------
EndSign
    );
}
