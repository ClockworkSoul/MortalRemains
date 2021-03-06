/*
** FILE: obsword.c
** PURPOSE: Example of set_bonus() function.
** CREATOR: Cyanide@Nightfall's Keep
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
**   18 Jun 97    Cyanide    Updated the weapon to include the new
**                           set_weapon_type function.
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
	set_bonus(3);
        set_weapon_type("dagger");
set("value",   1500);
	set("id", ({ "dagger" }) );
	set("short", "enchanted dagger");
	set("long", @LONG
A fine, enchanted blade.
LONG
	);
        set("name", "magic dagger");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
}
