inherit "/std/board/bboard";
#include <path.h>

void create() {
  bboard::create();
  set_attic_dir(ATTIC);
  set_save_dir(ROOMS+"data");
  set_save_file("hall");
  set_location(ROOMS+"hall");
  set("short", "General purpose bulletin board");
}
