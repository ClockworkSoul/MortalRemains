// This is a replica of a shop in the town of Sigil.
// Use this room as an example for making BUY ONLY SHOPS.
// -Chronos.

#include <mudlib.h>
#include "../camel.h"

inherit BUYONLY_SHOP ;

void create() {
    ::create();
    seteuid(getuid());
    stock = ([
  ]) ;
    set ("light", 1) ;
   set("objects", ([ "martha" : MON+"aunt_martha.c" ]) );
   set("short", "Aunt Martha's Bakeshop");
    set ("long", @ENDLONG
This is a quaint little bakeshop owned by Aunt Martha. The sweet 
little old lady rests behind the counter and smiles at you. There are
shelves and cases that house the wonderful bakery treats. You also
notice that Aunt Martha sells coffee.
There is a sign here.
Commands are: list, buy <item>
ENDLONG
    );
   set("shopkeeper", "aunt martha");
   set("shop_dir", ITEM+"stuff/");
    set("restock_msg", @ENDMSG
A UPS delivery guy walks in and drops off a package.
ENDMSG
    );
   set("item_desc", ([
     "cases" : "You see all sorts of pastries in the cases.\n",
     "shelves" : "You see all kinds of cookies and cakes on them.\n",
     "sign" : "You can read it.\n",
   ]));
    set ("exits", ([
     "east" : RM+"rm3.c",
    ]));
    reset();
}
void init(){
   add_action("read", "read");
  }
int read(string str) {
   if(!str){
     write("Read what?\n");
   return 1;
  }
if (str == "sign") {
   write("X--------------------------------------X\n");
   write("|  We are currentally closed due to    |\n");
   write("|   renovations, please come back soon |\n");
   write("| Sorry for the inconvenience          |\n");
   write("|           Aunt Martha                |\n");
   write("X--------------------------------------X\n");
 return 1;
}
return 1;
}
