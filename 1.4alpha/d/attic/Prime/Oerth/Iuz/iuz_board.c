inherit "/std/board/bboard";


void create()
{
        bboard::create();
set_attic_dir("/d/Prime/Oerth/Iuz/data/attic");
set_save_dir("/d/Prime/Oerth/Iuz/data");
set_save_file("player");
set_location("/u/i/iuz/workroom.c");
set("short.text", "Iuz's Personnal Board");
}
