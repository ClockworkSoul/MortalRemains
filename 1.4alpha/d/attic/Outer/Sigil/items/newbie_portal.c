

#include <mudlib.h>

inherit "/std/portal.c";

void create() {
    set("short", "@@query_short");

    set("prevent_get", 1);
    set("prevent_clean", 1);
    set("id", ({ "#PORTAL#" }) );
set("destination", "/d/Prime/Petzoo/rooms/zoo7.c");
set("direction", "east");
set("portalkey", "#NEWBIE#");

}


