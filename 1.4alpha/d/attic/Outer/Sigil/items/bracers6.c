// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "bracers" }) ) ;
        set ("short", "bracers of mild power") ;
        set ("long", "Mildly powerful, ornate bracers.\n") ;
      set_armor_type("bracers");
	set("bonus", 4);
set("size", -1); 
set("value",   1500);
}
