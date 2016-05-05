#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Abbey Road");
    set( "long", @EndText
You are walking along a small cobblestone path named Abbey Road.
As near as you can figure it's named for what it leads to, just a 
bit to the east, you see a strange structure. The main road is back
west, while the cobblestone wanlk leads further east. There is a inn 
to the south, the walls of the town are to the north.
EndText
    );
    set( "exits", ([
     "west" : RM+"rm10.c",
     "east" : RM+"AR2.c",
     "south" : RM+"tavern.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "walk" : "A cobblestone walk right under you.\n",
     "structure" : "You vaguely make it out to the east.\n",
     "road" : "Crest Road is to the west.\n",
     "inn" : "It looks like a tavern, there's a sign.\n",
     "sign" : "The Silver Dagger Inn.\n",
     "walls" : "Cracked and weatherbeaten, they house the town.\n",
     "cracks" : "A spider jumps out at you and scurries away.\n",
    ]) );
}
void init(){
   add_action("boomshakalacka", "read");
 }

int boomshakalacka(string str) {
   if (!str){
     write("What do you want to read?\n");
   return 1;
  }
if (str == "sign") {
     write("#**************************************#\n");
     write("$    The Silver Dagger Tavern and Inn  $\n");
     write("$    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  $\n");
     write("$ Serving the best drinks in town.     $\n");
     write("$   Come on Inn, we're open!           $\n");
     write("$ Tell your friends about us.          $\n");
     write("$    Ozwald, Innkeeper                 $\n");
     write("#**************************************#\n");
   return 1;
  }
return 1;
}
