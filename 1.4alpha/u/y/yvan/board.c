inherit "/std/board/bboard" ;

void create()
{
    bboard::create() ;
    set_attic_dir ("/u/y/yvan/data/attic") ;
    set_save_dir ("/u/y/yvan/data") ;
    set_save_file ("bbnotes") ;
    set_location ("/u/y/yvan/workroom.c") ;
    set ("short.text", "post here") ;
}
