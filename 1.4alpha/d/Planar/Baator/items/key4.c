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

inherit OBJECT;

void create() {
	set("mass", 1);
	set("id", ({ "key", "4key4" }) );
	set("short", "key of the fourth pit");
	set("long", @LONG
An intricate key.
It burns to the touch and it's shape reminds you of
the burning flames of hell.
LONG
	);
 set("value", 40000); 
   }


