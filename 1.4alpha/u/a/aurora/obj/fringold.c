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
	set("read", "And Friends are friends forever, \n"+
	"If the Lord's the Lord of them, \n"+
	"And a friend will not say never, \n"+
	"Cuz the welcome will not end. \n"+
	"Though it's hard to let you go, \n"+
	"In the Father's hands we know, \n"+
	"That a lifetime's not too long, \n"+
	"To live as friends... \n");
}
