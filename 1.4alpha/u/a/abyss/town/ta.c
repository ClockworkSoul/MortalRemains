#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Welcome to the Town of Tantallon" );
    set( "long", @EndText
WW    WWW    WW  EEEEE   LL      CCCCC   OOOO  MMMM       MMMM  EEEEE
WW   WW WW   WW  EE      LL    CCC      OO  OO MM MM     MM MM  EE
WW  WW   WW  WW  EEE     LL   CCC       OO  OO MM  MM   MM  MM  EEE
WW WW     WW WW  EE      LL    CCC      OO  OO MM   MM MM   MM  EE
WWWW       WWWW  EEEEE   LLLLL   CCCCC   OOOO  MM    MMM    MM  EEEEE
 
 
to the town of Tantallon.  Here you will find a pub, bank, some shops,
and eventually you will be able to buy your own rooms.  So make yourself
at home.  Hope you enjoy your visit!
EndText
    );
    set( "exits", ([
"south"  :  "/u/a/abyss/town/t1.c.c",
     "north"  :  "/u/a/abyss/town/nexit.c",
    ]) );
}
