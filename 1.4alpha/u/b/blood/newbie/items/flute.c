/*
** FILE:    flute.c
** CREDITS:
**      24 January 2000
**      Concept and design:   Blood@Mortal Remains
**      Code assisatnce:    Valkyrie and Cyanide (@MR)
*/

#include <config.h>
#include <mudlib.h>

inherit OBJECT ;

int charges;

void create() {
    seteuid(getuid());

    charges = 24;

    set ("id", ({ "flute", "flute of home" }) );
    set ("short", "a beautifully made flute");
    set ("long", "@@query_long");

    set ("value", 3000);
    set ("prevent_drop", 1);
    set ("prevent_insert", 1);
    set ("prevent_give", 1);
}   

void init () {
    add_action("play_flute", "play");
}

string query_long() {
    string str = (@EndText
This flute was originally designed to bring apprentice magi back from a
miscast teleportation spell. However another use for the flute was 
discovered during the Three Great Wars. If a critical leader or a king 
were trapped in a battle that was lost, they could be transported out. 
Now, this flute is yours, you can use it to get to certain places, but
they can not be changed. This flute is made of a solid piece of peach
with a mouth piece made of the beak of a crow, known for their long
journies.
EndText
    );
    if (wizardp(TP))
	str += "[WizInfo] This item had "+charges+" charges remaining.\n";

    return str;
}

int play_flute(string str) {
    string vmessage, pmessage;
    int number;

    if (!str || str=="flute") {
	write("WHat number song do you want to play?\n");
	return 1;
    }

    if (str=="song") {
	write("You can't figure out how to play that.\n");
	return 1;
    }

    if (sscanf(str, "%s %d", str, number)==2) {

	vmessage = TPN+" plays a haunting melody on "+
	possessive(TP->query("gender"))+
	" flute and slowly fades from view.";

	switch(number) {
	case 1 : str = START;
	    pmessage = (@EndFlute
Beautiful notes resound from the flute and begin to surround your mind.   sunshine
glittering off of its graceful movements. As the bird circles above you,
it looks down, and notices you. As it does you find yourself in another
place.
EndFlute
	    );
	    break;

	case 2 : str = START;
	    pmessage = (@EndSong
As the magical flute plays this next tune, one that rises up and down in
pitch, tone, and volume, the smell of aged books and dust fills your nose,
sitting in front of you with his back turned is an elder mage.  Soft white
hair, and thick blue robes are the most noticible features that you can 
see from here.  suddenly he turns, and you are captivated by his eyes, 
deep secrets lay behind these orbs, which seem to see past your own eyes,
and into your very core. You blink, and you find yourself elsewhere.
EndSong
	    );
	    break;

	case 3: str = VOID;
	    pmessage = (@EndSong
Surprisingly deep notes come from the flute this time. They seem to take
on a life of their own, as though the notes  themselves were joining with
your heart, and mind. As the notes continue to play, the world as you know
it fades away, to be replaced by an extremely large waterfall, which you 
are rushing for. Ice cold water slams against your body as you get closer
and closer to the water, the sound is unbelievably loud! As you scream in
terror your body is cought by the water and dropped hundreds of feat, you
close your eyes, waiting for death... You find yourself elsewhere.
EndSong
	    );
	    break;

	case 4: str = "/u/v/valkyrie/workroom.c";
	    pmessage = (@EndSong        
Intricate patterns of sound flow from the flute, creating an almost divine
composition, made up of short, loud notes. A field of wild herbs which lay
below you assaults your senses, and causes you to breathe deeply. As you 
do, you find yourself elsewhere.
EndSong
	    );
	    break;

	case 5: str = "/u/v/valkyrie/workroom.c";
	    pmessage = (@EndSong
One long, powerful note is the only sound you are able to hear as the power
of the flute has been requested once again. swirls of blue, red, and green
flicker about your vision causing you to see spots, one of them moves 
closer and you can see its the form of a lonely, dying star. it shoots 
across your vision, blinding you, and then it's gone, along with you, you
find yourself elsewhere.
EndSong
	    );
	    break;

	case 6: str = "/u/v/valkyrie/workroom.c";
	    pmessage = (@EndSong
A blazingly fast set of notes rip through your consciousness and begin 
your journy. Silvery light embraces your form, sending a warmth pulsing
through your body. Lazy pools of water fill your vision, and in one of them
rests a water nymph. Graceful and beautiful she lays with her face to the
sky. As she notices you, your vision fades and the only words you hear are
"bless you". You find yourself elsewhere.
EndSong
	    );
	    break;

	default : str = START;
	}

	if (str!="") {
	    write(pmessage);
	    TP->move_player(str, vmessage);

	    if (charges-- < 1) {
		write("Your flute suddenly rusts, and crumbles into dust.\n");
		say(TPN+"'s flute suddenly rusts, and crumbles into dust.\n");
		remove();
	    }

	} else {
	    write("You try to play the flute, but you get "+
	      "terrible noise!\n");

	    say(TPN+" plays the flute, and gets terrible noise!\n");
	}
    } else {
	write("You can't figure out how to play that.\n");
    }

    return 1;
}

/* EOF */
