/*
** File: jack_box.c
** Author: Lady Nsd
*/

#include <mudlib.h>
#include "fair.h"

int jack_flag, turn = 1;

inherit OBJECT ;

void create() {
    seteuid( getuid() );
    set("author", "nsd");
    set ("id", ({ "box", "toy", "wooden box" }) ) ;
    set ("short", "a small wooden box");
    set ("long", @EndLong
This box is a toy. It has letters of the alphabet finely
painted on each face of it. On top of the box is a lid
but it's closed and locked. One of the sides has a crank.
'turn' the 'crank' to see what happens :-)
EndLong
    );
    set ("bulk", 15) ;
    set("value", 2);
    jack_flag = 1;
}
void init() {
    add_action ("turn_crank", "turn");
    add_action ("open_lid", "open");
}
int turn_crank (string str) {
    say(TPN+" turns the box crank and a funny music starts to play.\n");
    write(@EndText
You turn the crank...
___________________________________________________________________
    HHHHH                      HH                           HH
  HH     HH                  HH H                         HH H
HH________HH___HH__________HH   H_______________________HH   H_____
          HH  HHHH         H    H                       H    H
          HH   HH          H   HH           HH          H   HH
__________HH_______________H  HHH__________HHH__________H__HHH_____
         HH    HH         HH   HH         HH H         HH   HH
        HH    HHHH       HHH                 H        HHH
_______HH______HH_________HH_________________H_________HH__________
      HH                                    HH
     HH                                    HHH
____HH______________________________________HH_____________________

The music stops followed by a loud CLICK!
Try to 'open' the 'lid' now.
EndText);
    return 1;
}
int open_lid (string str) {
    object jack;
    jack = clone_object(FAIR_MON+"clown_jack.c");
    if(jack && jack_flag) {
	turn = 0;
	say(TPN+" opens the box lid, and a Jack leaps out!\n");
	write("You open the lid, and a Jack jumps out of the box!\n");
	jack->move( environment( this_player() ) );
	jack->kill_ob( this_player() );
	jack_flag = 0;
    }else
	write("The lid is already open, and Jack is broken! :-(\n");
    return 1;
}
int reset() {
    turn = 0;
}
void fix_flag() { jack_flag = 1; }

/* EOF */
