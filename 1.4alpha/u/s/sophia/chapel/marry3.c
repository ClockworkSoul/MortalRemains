inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "objects", ([
      "bouquet" : "/u/s/sophia/bouquet.c",
    ]) );
    reset();
    set( "short", "A lovely room" );
    set("long", wrap(
	"A lovely room in which lovers of all beliefs may be married, "+
	"quietly, or surrounded by many joyous guests.  There are "+
	"pillows, tapestries and a small stone table here."
      ) );
    set( "exits", ([
"northwest" : "/u/s/sophia/chapel/marry.c",
    ]) );
    set("item_desc", ([
      "tapestries" : wrap("Handwoven tapestries depict stories of the "+
	"faerie king and queen; lovers of great renown. "),
      "vase" : wrap("This vase is carved as one with the table and "+
	"cannot be moved.  It holds a small bouquet for the bride. "),
      "bouquet" : "A small bouquet of white roses and ivy.\n",
      "table" : wrap("Gray granite has been carved into a beautiful "+
	"table. It is generally used by the one performing the marriage "+
	"although it has on occasion been used as a bar.  There is a "+
	"stone vase with a bouquet for the bride. "),
      "carvings" : wrap("carvings of the fearie king and queen and "+
	"others cavorting in the woods. "),
      "pillows" : wrap("large comfy pillows for the guests to relax "+
	"on for the ceremony or party after? "),
    ]) );
}
void init() {
    add_action("take", "take",);
}
int take (string str) {
    if (str=="bouquet from vase") {
	say(TPN+" lifts the bouquet from the vase\n");
	write(
	  "You take the bride's bouquet from the vase.\n");
	return 1;
    }
}
