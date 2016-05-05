// Coded by Aurora 11/11/94
// A friendship ring (autoloading)
// It might end up being sold but for now is just for Immortals

inherit "/std/armour";

	mixed *query_auto_load() {
		return ({"/wizards/aurora/obj/fring.c", ({}) });
	}

void create() {
   ::create();

	set_name("friendship ring");
	set("id", ({"ring","band","gold band"}) );
	set("short", "a beautiful Irish gold ring");
	set("long", "A beautiful ring made of Irish gold which forms "
	"two clasped hands.  The gold shines brightly with a reddish hue. "
	"You smile as you gaze at it's beauty, for you know your special "
	"friend cares so very much about you.  There seems to be "
	"something written on the inside of the band.  It is very tiny "
	"but you just might beable to read it if you tried.");
	set_type("ring");
	set_ac(2);
	set_limbs( ({ "right hand" }) );
	set_weight(45);
	set("value", 300);
	set("read", "Friendships house is made of Gold, \n"+
	"It's doors are open wide, \n"+
	"And Love and Trust and Happiness \n"+
	"Are ever found inside.  \n"+
	"It's in the city of the Heart, \n"+
	"Where stars shine all year through, \n"+
	"For Friendships house is built of Gold \n"+
	"By precious friends like You.\n");
}
