#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A bountiful garden");
  set("long", wrap(
"Tall rows of corn flank the narrow dirt path in this section of the garden. "+
"Large green ears stand out from the narrow stalks, ready to be harvested. "+
"A scarecrow hangs on a wooden post, dressed in black and sporting a big "+
"smile."
     ) );
  set("item_desc", ([
    "rows" : "Rows of corn are planted near the path.\n",
    "corn" : "Rows of corn are planted near the path.\n",
    "narrow dirt path" : "The path is flanked by rows of corn.\n",
    "dirt path" : "The path is flanked by rows of corn.\n",
    "path" : "The path is flanked by rows of corn.\n",
    "garden" : "The vegetable garden is large and bountiful.\n",
    "large green ears" : "Ears of corn are ready to be harvested.\n",
    "green ears" : "Ears of corn are ready to be harvested.\n",
    "ears" : "Ears of corn are ready to be harvested.\n",
    "narrow stalks" : "Ears of corn stick out from narrow stalks.\n",
    "stalks" : "Ears of corn stick out from narrow stalks.\n",
    "scarecrow" : "A scarecrow hangs from a wooden post.\n",
    "wooden post" : "A scarecrow hangs from a wooden post.\n",
    "post" : "A scarecrow hangs from a wooden post.\n",
    "big smile" : "The scarecrow is smiling and cheerful.\n",
    "smile" : "The scarecrow is smiling and cheerful.\n",
    ]) );
  set("smell", "You detect the faint scent of fresh corn.\n");
  set("listen", "You head the stalks rustling in the breeze.\n");
  set("exits", ([
    "southeast" : P_ROOM+"lilac.c",
    "southwest" : P_ROOM+"veg1.c",
    "northeast" : P_ROOM+"veg3.c",
    ]) );
  set("objects", ([
    "crow" : P_MON+"crow.c",
    "worm" : P_MON+"worm.c",
    ]) );
  reset();
  }
