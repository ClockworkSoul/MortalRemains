//#include config.h
//#include mudlib.h


inherit ROOM;
object fuckstick;

void create()
{
  ::create();
  seteuid(getuid());
  seteuid(getuid());
  set( "light", 1 );
  set("short", "Porn Palace");
  set( "long", @EndText
   This is a rather coszy room just south of DarkGoth's
work-room. there are plenty of couches and soft pillows
that line the room. all over the room are magazines and
pictures of nude celebrity and child pronogrify.
In one of the corners is a Family size jug of Vitamen E Lotion.
EndText
  );
  set("exits", ([
      "north" : "/u/d/darkgoth/workroom.c",
     "east" : "/u/d/darkgoth/room/sexden.c",
  ]) );
  set("item_desc", ([
 ]) );
}
