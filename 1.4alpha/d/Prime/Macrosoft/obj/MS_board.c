inherit "/std/board/bboard";

#include "macrosoft.h"
#define BASE "/d/Prime/"

void create()
{
    bboard::create();
    set_attic_dir(BASE+"data/attic");
    set_save_dir(BASE+"data");
    set_save_file("MS");
    set_location(FLOOR_1("entrance.c"));
    set("author", "cyanide");
    set("short.text", "a brand new posting board");
}
