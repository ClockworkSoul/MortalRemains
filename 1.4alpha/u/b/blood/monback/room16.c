#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit DOORS;

inherit ROOM;
int aring_here;
int ring_here;

void create()
{   
    
    ::create();

    seteuid( getuid() );
    aring_here = 1;
    ring_here = 1;
    set( "light", 1 );
    set("author","blood");
    set( "short", "Hall of the Wizards" );
    set( "long", @EndText
Walking into this room makes you feel insignificant because of the 6
increbibly detailed statues arranged in a hectagramic pattern facing each
other. Each statue is a memorial to a noble wizard who died in the war
against the Lords of the Abyss. Each one died alongside their lover who
also aided in the war.
EndText
    );
    set("item_desc", ([
"statues" : "There are 6 statues, which would you like to look at? \n"+
"First, Second, Third, Fourth, Fifth, or Sixth?\n",
"first statue" : (@EndFirst
The first statue is of a beautiful elven woman named Toura. Raven tresses
fall just to her waist and help to define her wonderful figure. Dark
ageless eyes look straight across from the statue in front of her. In her
left hand, she holds a silver sphere, which contains the twisted and
pained soul of a demon lord. In her right hand, she holds a sapphire wand
embellished with runes of power. The statue looks as though you might be
able to move it.
EndFirst
),

"second statue" : (@EndSecond
The second statue is of the Elven Lord Istragous. He is a tall, thin elf  
with short, close-cut hair, which helps to  define the distinctive pointed
ears and intense eyes of one who commands authority. He gazes lovingly at
his wife, across from him. In his left hand, he holds a lens of demon
sight, which allows its  user to see a demon for what it really is even if
it changes form. In his right hand, he holds a magnificent bow, which is 
crafted from the famed iron wood. It is also etched with powerful magical
scripts, which aid the arrows in their flight in combat. The statue looks
as though you might be able to move it.
EndSecond
),

"third statue" : (@EndThird
The third statue is of a somewhat thin human woman, named Amy. She is
wearing silvered robes, made of a gossamer material, which eccentuates her
delicate features. In her left hand, she holds a flask filled with the
blood of Grok, the demon lord. In her right hand, she holds the rod of
forgotten light. This rod shifts the lines of power that the demons use to
create the domains of the abyss to form light. Light, as we all know, is
very damaging to the dark ones. The statue looks as though you might be
able to move it.
EndThird
),

"fourth statue" : (@EndFourth
The fourth statue is of a short, almost dwarf-like human, named Carl. His
robes are black, with gold trim around the sleeves and head. Bulging
muscles can be seen standing out from his arms as they are slightly bent
with his hands facing upward. On the palms of both hands, he holds 2
pigeons made of mythril, which were used to escape from the abyss as the
demons attempted to trap them. He also gazes at his lover across the way.
The statue looks as though you might be able to move it.
EndFourth
),

"fifth statue" : (@EndFifth
The fifth statue is of a female gnome named Gnome-girl. Tiny, quick and
delicate, are the most striking features of this statue. The artist has
used some form of magic to maintain the well known trait of the invisible
gnome. However, as gnomes are known for using magic, the twin rubies of
angel-fire are very prominent floating just above the fingertips of her
small delicate hands. Whenever one or the other of these rubies touch a
demon, the flesh of the creature is immediately burned away followed by a
brilliant flash of light. The statue looks as though you might be able to
move it.
EndFifth
),

"sixth statue" : (@EndSixth
The last statue is of Gnome-girl's companion, Gnome-boy. The same style
was used to depict this gnome, save for the masculine features, which can
occasionally be glimpsed as the gnome shifts from invisible reality to
visible reality. As before, the weapons of power are always visible. He
chooses to wear nemesis armor. This armor allows him to receive devine 
powers when fighting particular demons. These powers may consist of
specific spells or words of power that can damage his enemy. The statue  
looks as though you might be able to move it.
EndSixth
),

    ]) );

    set( "exits", ([
"down" : N_ROOM+"room7.c",
"up" : N_ROOM+"attic1.c",
    ]) );

create_door("up", "down", "A strong wooden door "+
"which forms another complex spell of magic within its "+
"framework.", "locked", "magic key", 25);

}

void init() {
  add_action("move", "move");
}

  int move(string str) {
      object aring;
      object ring;
  if(str=="first statue") {
  if(aring_here) {
    aring=clone_object("/u/b/blood/newbie/items/acidring.c");
    aring->move(TP);
    write("You find a ring beneath the statue and grab it quickly!\n");
    say(TPN+" moves the first statue.\n");
    aring_here=0;
    return 1;
}
return 0;
} 
  if(str=="second statue"){  
    write("You move this statue and find.. nothing!\n");
    say(TPN+" moves the second statue.\n");
    return 0;
} 
  if(str=="third statue"){
    write("You move this statue and find.. nothing!\n");
    say(TPN+" moves the third statue.\n");
    return 0;
} 
  if(str=="fourth statue"){
    write("You move this statue and find.. nothing!\n");
    say(TPN+" moves the fourth statue.\n");
    return 0;
}
  if(str=="fifth statue"){
    write("You move this statue and find.. nothing!\n");
    say(TPN+" moves the fifth statue.\n");
    return 0;
} 
  if(str=="sixth statue"){
  if(ring_here) {
    ring=clone_object("/u/b/blood/newbie/items/slashring.c");
    ring->move(TP);
    write("You find a ring beneath the statue and grab it quickly!\n");
    say(TPN+" moves the first statue.\n");
    ring_here=0;
    return 1;
}
return 0;
} 
} 
