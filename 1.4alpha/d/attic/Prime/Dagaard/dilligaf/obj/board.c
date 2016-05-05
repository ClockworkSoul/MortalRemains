inherit "/std/board/bboard";

void create()
{
        bboard::create();
      set_attic_dir("/d/Prime/Dagaard/dilligaf/data/attic");
      set_save_dir("/d/Prime/Dagaard/dilligaf/data");
      set_save_file("problems");
      set_location("/d/Prime/Dagaard/dilligaf/street/street1.c");
      set("short.text" , "board to bitch and moan on");
}
