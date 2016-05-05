inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
set("short", "A Train Stop" );
set( "long", wrap(
"The train jerks to a stop at a small platform. A very large man and his "+
"entourage stand there in the gaudiest clothing you have ever seen. "+
"The train conductor laughs at you and points to a gold lettered sign. "
) );
    set( "exits", ([
"platform" : "/u/s/sophia/pad5.c",
    ]) );
    set("item_desc", ([
"sign" : "All seats reserved for 1st class...which you are obviously not!\n",
"man" : "A huge man with very greasy hair and a purple.\n",
    ]) );
}
