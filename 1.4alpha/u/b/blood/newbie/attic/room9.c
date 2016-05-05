/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit ROOM;


void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "House of Mage");
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
This room is composed of hundreds and hundreds of 
platinum blocks. The value of the construction of this 
room is incalcuable, nevermind what else lays here.
Three orbs, each containing a beast of a different color
float around in the room guarding its valuable construction,
and its place in the hall of the mage.
The first orb, has the form of a twin headed cat. One head
has the beautiful eyes of a human woman. As you look
into them you can see compassion and a willingness to
serve for a deep love. The other head is one of a lion.
Hard angry eyes look deep into your soul, obtaining all it 
needs to know about your weaknesses and strengths.
The second orb contains the form of a beautiful red,
platinum dragon. The dragon is simply there, confident in 
all its age and battles, that no enemy could ever crush its 
mortal form, but if such a thing were to happen.
It has a powerful spirit which no mortal can touch, but it 
has the power to influence things here. Better get out of 
here, eh?
The third orb simply radiates power, as you look into the 
orb, a voice whispers, i am the one who sleeps, a soul at 
rest, leave me at peace, and no harm shall come.  wake me,
and i shall destroy you without hesitation.
EndText
);
    set( "exits", ([
"northeast" : "room8.c",
    ]) );
    set( "item_desc", ([

]) );

}


