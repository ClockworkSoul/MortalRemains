// Updated by Aurora 10/24/95
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
	set("read", "I once held you in my arms \n"+
	"I once declaired that you were mine \n"+
	"I held you close and kissed your lips \n"+
	"But that was a different place and time. \n"+
	"\n"+
	"My actions and words were thoughtless \n"+
	"They struck you hard, they struck you fast \n"+
	"Hurting you was never intended \n"+
	"I don't want to repeat our past. \n"+
	"\n"+
	"The friendly talks we now share \n"+
	"Bring back memories, sun filled days \n"+
	"The sound of your voice and your smile \n"+
	"I still care for you in many ways. \n"+
	"\n"+
	"I want to tell you right now \n"+
	"I am glad we making amends \n"+
	"One thing we need to keep in mind \n"+
         "Please, let us at least remain friends. \n");
}
