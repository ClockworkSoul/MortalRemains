#include "main.h"

inherit MAIN+"/gardenstd.c";

void create()
{
    ::create();
    set ("short", "A Beautiful Garden" );
    set( "long", @EndText
The many great trees and shrubs here are indeed beautiful to the 
point of intoxication - but are also grotesque in the extreme. You
sicken as you realize that all around you the plants and wildlife 
are twisted into obscene mockeries of nature.
EndText
    );
    set("item_desc", ([
      "trees" : wrap("The tress in this part of the garden "+
	"are large pine tress bristling with black quills."),
      "shrubs" : wrap("The shrubs all have black, razor-sharp"+
	" leaves and twisted black thorns poking through masses "+
	"of sickly purple or pea green blooms."),
      "wildlife" : wrap("Most of it is hidden, but you "+
	"catch a glimpse of a 6 inch human male with an extra "+
	"set of legs in place of arms."),
      "plants" : "This part of the garden holds numerous tress"+
      " and shrubs.\n",
    ]) );  
    set( "exits", ([
      "south" : MAIN+"/gpathe.c",
      "west" : MAIN+"/ngarden.c",
    ]) );
}

/* EOF */
