// Created by Cyanide, 2000 April 26
// Maybe player will get a kick out of it.
// This emulates a version Chronos once did, but has since beenlost

#include "school.h"

inherit OBJECT;

void create() {
set("short", "a joint");
set("id", ({ "joint", "weed", "pot" }) );
}

void init() {
add_action("smoke", "smoke");
}

int smoke( string str ) {
object stoned;

if (!id(str)) return 0;

stoned = present("#STONED#", TP);
if (!stoned) stoned = clone_object(S_OBJ("stoned.c"));

stoned->more_stoned(TP);

 return 1;
}

