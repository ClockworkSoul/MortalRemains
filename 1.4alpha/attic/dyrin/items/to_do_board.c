inherit BOARD;

#define HOME_DIR "/u/d/dyrin"

void create()
{
    bboard::create();
    set_attic_dir(HOME_DIR+"/data/attic");
    set_save_dir(HOME_DIR+"/data") ;
    set_save_file("to_do");
    set_location(HOME_DIR+"/workroom.c");
    set("short.text","Dyrin's to-do-board");
}
