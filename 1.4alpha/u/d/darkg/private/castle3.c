#include "castle.h"

inherit ROOM;

void create()

{
 ::create();
   seteuid(getuid());
   set("light", 1);
   set("short", "Room of mourning.");
   set("long", @ENDTEXT
The walls of this room are lined with coffins. Assorted
bones are scatterd across the floor.
ENDTEXT);
   set("exits", ([
   "southwest" : AROOM + "castle2.c",
   ]) );
set("item_desc", ([
    "coffins" : "The coffins are made of rotten wood, most
    of them are over turned and their contents are
    spilled across the floor.\n",
   ]) );
   }
