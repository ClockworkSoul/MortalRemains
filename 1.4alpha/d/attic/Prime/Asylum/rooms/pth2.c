#include <config.h>
#include <mudlib.h>
#include "/d/Prime/Asylum/asy.h",

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "ROOM NAME HERE" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The cobble stone drive way leads north twords Grey Stone Asylum. Each step creates the sound of impending doom
EndText
    );
    set( "exits", ([
"north" : "pth3.c",
"south" : "pth1.c",
    ]) );
}
