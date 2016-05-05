inherit "/std/board/bboard";

void create()
{
    bboard::create();
    set_attic_dir ("/d/Ancients/data/attic");
    set_save_dir("/d/Ancients/data");
    set_save_file("immortal");
    set_location("/d/Ancients/rooms/wizrm.c");
    set("short.text", "Notes, Questions, Comments, Quotes");
}
