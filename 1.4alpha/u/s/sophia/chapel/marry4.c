inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
set("short", "A pretty courtyard" );
set("long", wrap(
"Climbing roses and other flowers colour this sunny courtyard. "+
"A monk quietly tends the thorny beauties. "
) );
    set( "exits", ([
      "north" : "/u/s/sophia/herbgarden.c",
"arch" : "/u/s/sophia/chapel/marry.c",
    ]) );
    set("item_desc", ([
"roses" : "beautiful old blaze climbing roses.\n",
"flowers" : "little purple velvet vals \n",
    ]) );
}
