inherit "/std/board/bboard";

#define PATH "/d/Outer/data"

void create()
{
        bboard::create();
        set_attic_dir(PATH+"/attic");
        set_save_dir(PATH);
        set_save_file("player");
       set_location("/d/Outer/Sigil/mainst1.c");
        set ("short.text", "The Player Board");
}
