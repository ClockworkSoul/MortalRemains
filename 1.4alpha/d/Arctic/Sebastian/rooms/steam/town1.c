#include <mudlib.h>
#include <steamtown.h>

inherit ROOM;
void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("light", 1);
	set("short", "The Great Doors to "+CITY_NAME);
	set("long", @Foo
	Twin doors greet you as you walk up the entrance to Steam Town
 Surounded by a buzzing, hissing noise, the doors swing open silently.
A few guards, mounted on odd looking towers, with arcane looking weapons
patrol the area below.  The citizens of Steam Town are bustling about,
keeping to themselves.  As you walk, you see the huge walls surrounding
this small town.  Thick, steel plated walls with large rivets securing
then to each other.  From every vent, little puffs of steam escape.  
There is a brightly painted sign bolted to the wall near the entrance.
Foo
);
	set("item_desc",([
	"doors":"Massive steel doors, that keep the town safe at night.\n",
	"entrance":"A huge archway, with heavy doors set in it.\n",
	"guards":"Well built men, wearing simple armor, and wielding"+
	"odd weapons.\n",
	"towers":"Huge steel buildings, with turrets on top.\n",
	"turrets":"Cannon-like tops of the towers.\n",
	"weapons":"They look like firehoses, hooked to steam generators.\n",
	"citizens":"The people around you look busy, but proud of it.\n",
	"walls":"Upon inspection, they seem quite thick, and very sturdy.\n",
	"rivets":"They look to be as big around as an orc's fist!\n",
	"vents":"Billowing clouds of steam emanate from them all.\n",
	"sign":"The sign reads: Welcome to Steam Town, a safe place"+
	"to live!\n",
	]));
	set("safe", 1);
	set("exits",([
	"north":"/d/Arctic/Sebastian/rooms/waste_4.c",
	"west":M_ROOM+"town2.c",
	"east":M_ROOM+"town4.c"
	]));
	set("listen", "You can hear the hissing steam, mingle with conversations.\n");
	set("smell", "It smells like oil and sweat, mixing with other scents.\n");
}
