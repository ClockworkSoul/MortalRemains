#include <mudlib.h>

inherit ROOM;

void create(){
     ::create();
  seteuid(getuid());
   set("light", 1);
  set("short", "the Storeroom of the Gem Shoppe");
  set("long", @Room
This is a store room, it store stuff, nothing here now though.
Room
);
  set("exits", ([
    "stairs" : "/d/Prime/Toril/Arabel/city/gemshop.c",
 ]) );
}

void init() {
   add_action("enter", "enter");
 }

int enter(string str) {
  if(!str) {
   return 1;
}

   if (str == "shadows") {
   this_player()->move_player("/d/class/rogue/Assasins/rooms/assassin_guild.c");
   return 1;
 }
return 1;
}
