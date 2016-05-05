/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/
#define ITEM "toga"
#define DAMAGE 5
#define TIMER 5

#include <mudlib.h>
#include "/u/d/dragoon/include/format.h"

inherit ROOM;


int water_on;
void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
   set( "short" , "Dragoon's workroom");
   set ( "long" , format(
       "This is a temporary workroom for those wizards who do not have one of "
       "IT IS EASY TO ADD STUFF IN THE CENTER "
       "their own that will load.  This is also a test of my format command "
       "to see if it will work here."
       ));
  set( "exits", ([
       "start" : "/d/Ancients/rooms/wizrm.c",
       "void" : "/d/std/void.c",
  ]) );
   water_on=0;
}
void turn_on() {
   if (water_on==1) return;
   call_out("drown",TIMER);
   water_on=1;
   return;
}
void drown() {
   int flag;
   object inv;
   flag=0;
   inv=first_inventory( this_object() );
   while (inv!=0) {
       if (!present(ITEM,inv) && interactive(inv)) {
           inv->receive_damage( DAMAGE );
           tell_object( inv , "You swallow a lung full of air.\n");
           flag=1;
           }
       inv=next_inventory(inv);
       }
   if (flag==1) {
       call_out( "drown" , TIMER );
       water_on=0;
       }
}
void init() {
   turn_on();
}
