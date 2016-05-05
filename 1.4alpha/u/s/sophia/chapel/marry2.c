inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set("short", "A cluttered office" );
    set("long", wrap(
	"A clerk looks up at you from his dest as you enter. It is "+
	"cluttered with executive toys to amuse someone who must be "+
	"veeeeeeery bored. "
      ) );
    set( "exits", ([
      "northeast" : "/u/s/sophia/chapel/marry.c",
    ]) );
    set("item_desc", ([
      "desk" : wrap( " This is a simple and very old pine desk adorned "+
"with nothing but toys and an old book. It matches the utilitarian "+
	"flooring perfectly. "),
      "floor" : wrap( "Plain pine flooring that is obviously very old "+
	"but well kept.  There are some interesting scratches on it. "),
"old book" : wrap("A book of parchment paper used to "+
	"record marriages.  It is bound in an irridescent dragon "+
	"leather.  Come to think of it it looks a lot like "+
	"Loretta did, hmmm. "),
      "scratches" : "Light scratches trace out in an arc from the desk.\n",
    ]) );
}
void init() {
add_action("move", "move");
}
int move(string str) {
if (str=="desk"){
write("You suddenly tumble through a trapdoor and land hard.\n");
say (TPN+ " suddenly disappears through the floor.\n");
this_player()->move_player("/u/s/sophia/chapel/marry5.c");
say(TPN+ " tumbles in down the stairs and lands hard.\n");
return 1;
}
}
