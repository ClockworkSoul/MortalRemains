
#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "author", "Enzyme" );
  set( "light", 1 );
  set( "short", "Enzyme's workroom" );
  set( "long", @EndText
You have entered the workroom of the Wizard, Enzyme. He must think highly
of you or you wouldn't be allowed to view the treasures found through
the portal. Be warry as things are not as they seem.
EndText
  );
  set("item_desc", ([
	"detail#details" : "There aren't any worth mentioning just now.\n",
	"workroom" : "This workroom belongs to Enzyme.\n",
	"enzyme#Enzyme" : "The owner of the workroom.\n",
  ]) );
  set( "exits", ([
    "start" : START,
    "portal"  : "u/e/enzyme/area/room1.c"
  ]) );
}
