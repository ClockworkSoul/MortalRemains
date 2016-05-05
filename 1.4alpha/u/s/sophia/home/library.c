#include "sophia.h"
inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
set( "author", "sophia");
set( "short", "An ancient library" );
set("long", wrap(
"An immediate sense of comfort envelopes you as you "+
"enter this room filled with both new books and ancient tomes. "+
"A leather sofa polished from years of use invites you to "+
"curl up and read. "
) );
set( "exits", ([
"down" : HOME+"bedroom2.c",
"balcony" : HOME+"balcony.c",
]) );
set("item_desc",([
"sofa" : wrap("A mahogany brown leather sofa; deep and wide "+
"enough for Sophia and at least one guest to read "+
"comfortably for hours. "),
"books" : wrap("An eclectic maze of titles rest on mahogany "+
"bookshelves. More are scattered around the room on the chairs "+
"and tables."),
"chairs" : wrap("Two deep and comfortable chairs arranged in a classic "+
"setting across from the sofa. "),
"tables" : wrap("Two end tables and a coffee table in a "+
"surprising steel. The material seems incongruous here but "+
"the lines are so beautifully clean you understand why "+
"Sophia has put them here. There is a book on the endtable. "),
"endtable" : wrap("A book about black holes and such stuff by a "+
"guy named Kip??? Who the heck would read such stuff? "),
"tomes" : wrap("Ancient books in an eleven script that you cannot "+
"read but is beautifully illuminated. "),
]) );
}
