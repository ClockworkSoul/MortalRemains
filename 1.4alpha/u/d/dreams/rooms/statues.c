inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set("author", "dreams");
  set( "light", 2 );
  set("short", "Mythical statues entrance");
  set("long", @EndText
As you step forward a sense of peace envelopes you.
You are standing on sacred ground. This place is filled with angelic statues.
At this distance you can hardly identify each of them, 
but there is one thing that you are totally sure... they are beautiful
and you feel an urge to take a closer look.
Each exit leads to a different statue, which to start is up to you.
Just realize, that you are the judge of your own actions,
and remember... this is sacred ground.
EndText
);
  set( "exits", ([
  "northwest" : "/u/d/dreams/rooms/hill.c",
   "west" : "u/d/dreams/statue1.c",
   "east" : "u/d/dreams/statue2.c",
   "south" : "u/d/dreams/statue3.c",
]) );
}
