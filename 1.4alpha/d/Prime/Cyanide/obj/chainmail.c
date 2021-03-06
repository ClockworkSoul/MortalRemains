#include <mudlib.h>

inherit ARMOR ;

void create() {
        set ("id", ({ "chain", "chainmail" }) ) ;
        set ("short", "a suit of chainmail") ;
        set ("long", "The mail mesh would cover your torso and upper arms.\n") ;
        set ("bulk", 100) ;
        set ("mass", 1200) ;
        set ("value", ([ "gold":50 ]) ) ;
// All armor objects need to set a "type", ie suit, shield, helmet, boots,
// whatever. The player can wear only one of each type of armor.
        set ("type", "suit") ;
// "armor" is the armor class of the armor. Anything with "armor" 0 is not
// a piece of armor and cannot be equipped. Things with positive values of
// "armor" are armor; higher numbers are better protection against attacks
// (which is the reverse of the D&D method.)
        set ("armor", 6) ;
}