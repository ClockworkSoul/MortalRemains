inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
set("light",0);
    set( "author", "sophia");
set("short", "A dark cellar" );
    set("long", wrap(
"A dark, damp cellar. Wine racks line 2 walls and the stone "+
"sucks the warmth from your toes.  An old crate and several "+
"barrels serve as a table and chairs. "
      ) );
    set( "exits", ([
"window" : "/u/s/sophia/chapel/marry4.c",
    ]) );
set("objects", ([
]) );
reset();
    set("item_desc", ([
"crate" : wrap("An ordinary wooden crate that serves as a "+
"table for the game. It holds an old lamp and "+
"is strewn with cards. "),
"barrels" :  "old wine barrels and tequila barrels. \n",
"cards" : wrap("These cards have pictures on them that "+
"monks of honour should not have. "),
"floor" : "A cold stone floor. \n",
"racks" : "Old wooden wine racks that are empty now. \n",
"window" : "A small iron casement window leading to the courtyard. \n",
    ]) );
}

void reset() {
object monk;
int counter;

::reset();

// If monks are already here, quit now.
if (present("monk", this_object())) return;

counter = 5;

// This is a while loop.  It will run 5 times.
while (counter > 0) {
monk = clone_object("/u/s/sophia/monk.c");
if(monk) monk->move( this_object() );
counter = counter - 1;
}

}

/* End of file */
