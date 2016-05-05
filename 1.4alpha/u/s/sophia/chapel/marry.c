inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "A small anteroom" );
    set("long", wrap(
	"You have entered a small anteroom which is nicely decorated "+
	"especially considering the area.  There is a small table in the "+
	"middle of the room and a handsome plaque on the far wall. "+
	"Two doors lead further into the structure. "
      ) );
    set( "exits", ([
"north" : "/u/s/sophia/chapel/marry4.c",
      "southeast" : "/u/s/sophia/chapel/marry3.c",
      "southwest" : "/u/s/sophia/chapel/marry2.c",
    ]) );
    set("item_desc", ([
      "table" : wrap("A small round table with a clean cloth over it. "+
	"A glass vase holds flowers from a garden kept secret by "+
	"those who care for this place. "),
      "plaque" : wrap("This place is dedicated to those who find true "+
	"companionship in this harsh world. Take care of the other "+
	"and all will be well...even in death. "),
      "vase" : "A pretty glass vase of red tulips. \n",
      "flowers" : "pretty red tulips \n",
      "tulips" : wrap("Tulips obviously bred with a patient hand, deep red "+
	"petals with light green patterns on them which look suspiciously "+
	"like fractals. ")
    ]) );
}
