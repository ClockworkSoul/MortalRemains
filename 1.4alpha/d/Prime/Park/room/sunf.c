#include <mudlib.h>
#include <def.h>

inherit ROOM;

void create() {
  ::create();
  seteuid(getuid());
  set("author", "ellie");
  set("light", 1);
  set("short", "A field of sunflowers");
  set("long", wrap(
"This is certainly the most cheerful garden in the entire park. Rows of "+
"sunflowers surround you, lifting their bright yellow blossoms to the sky. "+
"The flowers tower at least a foot above your head, making it difficult to "+
"see what lies in the distance."
     ) );
  set("item_desc", ([
    "rows" : "Rows of sunflowers surround you.\n",
    "row" : "This row is thick with bright sunflowers.\n",
    "sunflowers" : "The sunflowers are tall and bright.\n",
    "sunflower" : "This sunflower is tall and bright.\n",
    "yellow blossoms" : "The blossoms are large and bright.\n",
    "blossoms" : "The blossoms are large and bright.\n",
    "blossom" : "This blossom is large and bright.\n",
    "yellow blossom" : "This blossom is large and bright.\n",
    "sky" : "The sky above is dotted with clouds.\n",
    "flowers" : "The flowers are tall and bright.\n",
    "flower" : "This flower is tall and bright.\n",
    ]) );
  set("smell", "The sunflowers have a faint, but pleasant, scent.\n");
  set("listen", "The flowers rustle in the breeze.\n");
  set("exits", ([
    "north" : P_ROOM+"path4.c",
    "west" : P_ROOM+"path9.c",
    "southeast" : P_ROOM+"lily2.c",
    ]) );
  set("objects", ([
    "bunny" : P_MON+"bunny.c",
    "frog" : P_MON+"frog.c",
    ]) );
  reset();
  }
