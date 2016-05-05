
#include "mudlib.h"
#include "area.h"
inherit "inherit/clothing.c";

void reset (status arg) {
  if(!arg){
    set_name("rags");
    set_alias("rags");
    set_short("A set of rags");
    set_long (
" These simple rags appear to be the same clothes that these poor wretched\n"+
" souls were burried in. From the obvious condition they are in these rags\n"+
" are very old indeed. It is doubtful if they would even provide any protection\
n");
    set_weight(1);
    set_sell_destruct(1);
    set_value(5);
  }
}
