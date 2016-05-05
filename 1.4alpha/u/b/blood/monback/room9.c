#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "House of Mage");
    set("author", "blood");
    set( "long",@EndText
This room is composed of hundreds and hundreds of platinum blocks. The 
value of the construction of this room is incalcuable, nevermind what else
lays here. Three orbs, each containing a beast of a different color float
around in the room guarding its valuable construction, and its place in 
the hall of the mage.
EndText
    );
    set( "exits", ([
      "northeast" : N_ROOM+"room8.c",
    ]) );
    set( "item_desc", ([
      "orbs" : "There are three of them. Do you wish to examine the "+
      "first, second or \nthird orb?",
      "first orb" : (@EndOrb
The first orb, has the form of a twin headed cat. One head has the 
beautiful eyes of a human woman. As you look into them you can see
compassion and a willingness to serve for a deep love. The other head is
one of a lion. Hard angry eyes look deep into your soul, obtaining all it 
needs to know about your weaknesses and strengths.
EndOrb
      ),
      "second orb" : (@EndOrb
The second orb contains the form of a beautiful platinum dragon. The dragon
is simply there, confident in all its age and battles, that no enemy could
ever crush its mortal form, but if such a thing were to happen. It has a 
powerful spirit which no mortal can touch, but it has the power to 
influence things here.
EndOrb
      ),
      "third orb" : (@EndOrb
The third orb simply radiates power, as you look into the orb a voice
whispers, "I am the one who sleeps; a soul at rest. Leave me at peace, and
no harm shall come. Wake me, and I shall destroy you without hesitation."
EndOrb
      ),
    ]) );
}


