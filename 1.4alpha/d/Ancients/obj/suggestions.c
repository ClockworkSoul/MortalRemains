inherit "/std/board/bboard";

void create()
{
        bboard::create();
    set_attic_dir("/d/Ancients/data/attic");
    set_save_dir("/d/Ancients/data");
    set_save_file("suggestions");
    set_location("/d/Ancients/rooms/suggest_rm.c");
    set("short.text", "The Suggestions Board");
}
