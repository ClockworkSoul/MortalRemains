inherit "/std/board/bboard";

void create()
{
        bboard::create();
	set_attic_dir ("/u/c/chakan/data/attic");
	set_save_dir("/u/c/chakan/data");
	set_save_file("general");
	set_location("/u/c/chakan/workroom.c");
	set ("short.text", "The Unorthadox Kobold Page (literacy not required)");
}
