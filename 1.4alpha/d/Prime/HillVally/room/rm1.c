#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "The entrance to Hill Vally");
    set( "long", @EndText
You are entering what looks like a small town. You can see a sign
that says "Welcome to Hill Vally", you could get a closer look at
it though. The path that you are on leads into the town.
EndText
    );
    set( "exits", ([
     "north" : RM+"rm2.c",
    ]) );
    set("item_desc", ([
   "town" : "It's to the north, your about to enter it.\n",
   "sign" : "It seems to have words, you could read it.\n",
   "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
void init() {
   add_action("read", "read");
 }

int read(string str){
   if(!str){
     write("Read what?\n");
   return 1;
  }
if (str == "sign") {
     write("X------------------------------------------------X\n");
     write("|    Welcome to Hill Vally, Population 1176      |\n");
     write("| We hope you enjoy your stay here in Hill Vally |\n");
     write("| You'll find Aunt Martha's Bake Shop to have the|\n");
     write("|  Best pies and Cookies in Town. Yuo may also   |\n");
     write("| want to see Tarnish, the Weaponsmith, his wares|\n");
     write("| are the finest in the land.                    |\n");
     write("|     -Mayor Martjak-                            |\n");
     write("X------------------------------------------------X\n");
     write("              #######################             \n");
     write("               #####################              \n");
     write("                 #################                \n");
     write("                 #################                \n");
   return 1;
 }
return 1;
}
