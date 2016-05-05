#include <mudlib.h>

inherit MONSTER ;

void create () {
  object potion, tmp;
object key, temp;
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "blood");
    set("short", "Apprentice Mage");
    set ("long", @EndText
Long black hair frames the face of this student of magic. He sits here in
this room studying intently everything he has learned from the master of
the house.
EndText
);  
    set("id", ({ "monster", "mage", "apprentice", "apprentice mage" }) );
    set_size(6);
    set_name("apprentice") ;
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
set("damage", ({ 6,11 }) );
    set("weapon_name", "fists") ;
    set_verbs( ({ "attack", "swing at" }) ) ;
    set("natt", 4);
    set_level(11);

    potion = clone_object("/d/Prime/Magehouse/items/potion.c");
    potion->move(TO);

    key = clone_object("/d/Prime/Magehouse/mk.c");
    key->move(TO);

}
