inherit "/std/board/bboard";

#define AREA "/d/Prime/Cyanide/"

void create()
{
    bboard::create();
    set_attic_dir("/d/Prime/data/attic");
    set_save_dir("/d/Prime/data");
    set_save_file("Cyanide1");
    set_location(AREA+"area1/a1path02.c");
    set("short.text", "a weathered posting board");
}
