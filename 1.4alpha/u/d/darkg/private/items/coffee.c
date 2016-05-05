
#include <mudlib.h>

inherit OBJECT ;

void create() {
  seteuid(getuid());
   set ( "id", ({ "coffee", "a mug of coffee", "mug" }) );
   set ("short", "a mug of coffee");
   set ("long", @EndText
This is a mug of hot off the maker coffee.
It was brewed just for you, enjoy all you want.
You think it might be a columbian blend of beans, vintage for this 
time of year.
EndText
 );
   set ("mass", 0);
   set ("bulk", 0);
   set ("value", ({ 0 }) );
}

  void init () {
    add_action ("drink", "drink");
 }

 int drink(string str) {
    object waste;

   if(!str) {
     write ("Drink what?\n");
   return 1;
 }
   if (str == "coffee") {
     write("You sip from the cup and bask in it's caffieneness.\n");
     write("You feel at one with you Juan Valdezness.\n");
     say (this_player()->query("cap_name")+" drinks a mug of coffee.\n");
      waste = clone_object("/u/n/nightmask/private/waste.c");
      waste->set("short", "an empty mug");
      waste->set("long", "It smells like coffee.\n");
      waste->set("id", ({ "mug", "empty mug" }) );
    waste->move(this_player());
    remove();
   return 1;
 }
  return 1;
}
