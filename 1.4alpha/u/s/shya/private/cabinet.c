#include <mudlib.h>

inherit CONTAINER ;

object g1, g2, vodka, whiskey, rum, tequila;

void create()
{
    ::create();
    seteuid(getuid());
    set("author", "shya");
    set("id", ({"liquor", "cabinet", "liquor cabinet"}));
    set("short", "Liquor cabinet");
    set_open_long (wrap(
    "A cabinet full of different kinds of drinks. Two goblets sit on the door.\n"));
    set ("capacity", 300) ;
    vodka = clone_object("/u/s/shya/private/vodka.c");
    vodka->move(this_object());
    g1 = clone_object("/u/s/shya/private/goblet.c");
    g1->move(this_object());
    g2 = clone_object("/u/s/shya/private/goblet.c");
    g2->move(this_object());
    whiskey = clone_object("/u/s/shya/private/whiskey.c");
    whiskey->move(this_object());
    tequila = clone_object("/u/s/shya/private/tequila.c");    
    tequila->move(this_object());
    rum =clone_object("/u/s/shya/private/rum.c");
    rum->move(this_object());

}


