#include <mudlib.h>
#include <central.h>

inherit ROOM;

void create() {
    seteuid(getuid());
    set("light", 1);
    set("short", "A small clearing within the rubble.");
    set("long", @ENDLONG
As you enter this small clearing within the rubble, you are greeted by an
awesome sight:  a massive red portal, pulsating with power, beckoning 
you to enter it.
ENDLONG
  );
    set("item_desc", ([
      "rubble" : "The mountain of trash is as high as a building.\n",
      "portal" : "You could 'enter' it, if you wished.\n",
    ]) );
    set("exits", ([
      "west"  : M_ROOM+"junkyard02",
    ]) );
    ::create();
   reset() ;
}                         

void init() {
    add_action("enter", "enter");
}

int enter ( string str ) {
    if (str!="portal") {
        write("Enter what?\n");
        return 1;
    }
   if (TP->query_level()<12) {
     write(@ENDLONG
The wind picks up.
You hear a voice whisper: You are not yet ready for such challenges, my child.
            Only Death lies before you.
ENDLONG
   ) ;
     say(TPN+" starts to enter the portal, but thinks better of it.\n") ;
     return 1;
   }
   write("You are momentarily blinded by a bright red flash!\n"+
          "When your vision returns, you find yourself.. elsewhere.\n");
   say(wrap("There is a bright red flash as "+TPN+
             " enters the portal and dissapears!"));
   TP->move("/d/Planar/Baator/avernus/plain4.c") ;
   message("movement", wrap("There is a great flash of red light, and "+TPN+
        " appears from somewhere else."), environment(TP),
         ({ TP }) ) ;
  call_out("realize", 4, TP) ;
    return 1;
}

int realize(object hero) {
  if (!hero) return 0 ;
  tell_object(hero,
    "You realize, with dismay, that you will not be able to return through\n"+
        "the portal you came through.  You will have to find another way home.\n") ;
   return 1;
}
