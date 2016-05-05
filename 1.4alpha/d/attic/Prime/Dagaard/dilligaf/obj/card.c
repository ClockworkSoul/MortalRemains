#include <mudlib.h>
inherit OBJECT;
int query_auto_load(){
return 1;
}

void create(){
  seteuid(getuid());
  set("short" , "Admission card");
  set("short" , "A sneaky card");
  set("long" , @EndText
  A card to gain access to Dilligaf's vat of beer. Only to be used
  wisely and by certain people.

  The directions say to type 'in' and 'out'.

EndText
  );
  set("prevent_give" , 1);
  set("prevent_drop" , 1);
  set("prevent_clean" , 1);
  set("id" , ({ "card" }) );
}

void init() {
  add_action("in_func" , "in");
  add_action("out_func" , "out");
}
int in_func(string str){
  if(!str){
    write("Welcome to the lounge.\n");
    say(TPN+" accepts Dilligaf's invitation and leaves.\n");
    this_player()->move_player("/u/d/dilligaf/vat.c");
    return 1;
  }
  return 0;
}
int out_func(string str){
  if(!str){
    write("Cya later.\n");
    say(TPN+" saunters back into the hub-bub.\n");
    this_player()->move_player("/d/Outer/Sigil/mainst1.c");
    return 1 ; }
  return 0;
}
