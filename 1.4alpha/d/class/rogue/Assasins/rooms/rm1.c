#include <mudlib.h>

inherit ROOM;

void create(){
     ::create();
  seteuid(getuid());
   set("light", 1);
  set("short", "the Storeroom of the Gem Shoppe");
  set("long", @Room
This is a store room, it store stuff, nothing here now though.
The shadows in the corners of the room dance, as the cobwebs seem
to add to the mystery of this room.
Room
);
  set("exits", ([
    "stairs" : "/d/Prime/Toril/Arabel/city/gemshop.c",
 ]) );
   set("items", ([
     "shadows" : "The seem to swirl and move.\n",
     "cobwebs" : "They line the walls making intriquate patterns.\n",
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
