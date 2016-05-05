
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Gendor");  

  set("light", 1);


  set("short", "A forest path.");
  
set("long", @ENDLONG
You are on a plain forest path.  To the north, you can make out a miniature town.
Small trails of smoke can be seen rising into the sky from the tiny buildings.
ENDLONG
   );

  set("item_desc", ([
  "path" : "The path has little footprints all over it.\n",
    "smoke" : "Thin trails of smoke waft into the air.\n",
   ]) );
  
  set("smell", ([
    "default" : "You smell a pungent odor in the air.\n",
    "air"  : "It reminds you of a barbeque, with a meat you aren't famliar with.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear voices coming from the north.\n",
    "voices" : "It sounds like a communion of sorts.\n"
    
    
  ]) );
  
  set("exits", ([
    
    "north" : ROOMS(outskirts),
    "up" :  "/u/g/gendor/workroom.c",
    
    
  ]) );
  ::create();  
}
