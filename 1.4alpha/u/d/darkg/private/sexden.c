#include <config.h>
#include <mudlib.h>

inherit ROOM;

object lori;
void create()
{
  ::create();
  seteuid(getuid());
lori = clone_object("/u/d/darkgoth/monsters/slave.c");
lori->move(this_object());
  set ("light", 1);
  set( "light", 1 );
  set("short", "Sex Den");
  set( "long", @EndText
  This room is filled with an assortment of whips, chains
and other sexual torture devices. There is a rack in one corner
with a naked woman tied and gagged to it. On the floor lies scattered
remains of decaying flesh and unknown stains. The musky smell of sex waift
throughout the room. making the weak at heart vomit. and
the Strong Willed  HORNEY.
EndText
  );
  set( "exits", ([
       "west" : "/u/d/darkgoth/room/porn.c",
  ]) );
  set("item_desc", ([
       "whips" : "There are whips with metal barbs attached to them
and others made of the softest leather.\n",
 ]) );
}
