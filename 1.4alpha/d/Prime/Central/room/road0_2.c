// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    set("author", "cyanide");
    set("light", 1);
    set("short", RD_Y);
    set("long", wrap(
	"You are standing in the heart of the Elven District, "+
	"known for its incredible cleanliness and aesthetic beauty. "+
	"Incredible trees line the sides of the street here, each one "+
	"tended by the private citizens of the city into elaborate "+
	"works of art. Even the shops and homes here seem to have been "+
	"grown rather than constructed, and not so much as a scratch of "+
	"graffiti mars the walls here. To the west stands the city Post "+
	"Office, and to the east stands a massive black pyramid: "+
	"the esteemed Magicka University."
      ) );
    set("exits", ([
      "north" : M_ROOM+"road0_3.c",
      "east" : "/d/class/wizard/general/rooms/m_lobby.c",
      "south" : M_ROOM+"road0_1.c",
      "west" : M_ROOM + "post_office.c",
    ]) );
    set("item_desc", ([
      "walls" : "They are made of some organic stony substance.\n",
      "trees" : "They have been shaped into elaborate abstract forms.\n",
      "street" : "It is clean, and well maintained.\n",
      "works" : "Almost everything here is artwork...\n",
      "shops" : wrap("Many of them are decorated with elaborate "+ 
	"murals, or lovingly tended ivy."),
      "homes" : "They are small but comfortable-looking.\n",
      "graffiti" : "There is none to speak of.\n",
      "post office" : "It is to the west.\n",
      "pyramid" : "It houses Magicka University.\n",
    ]) );
   ::create() ;
   reset() ; 
}

// EOF
