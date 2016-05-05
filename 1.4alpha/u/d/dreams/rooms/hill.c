inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set("author", "dreams");
  set( "light", 4 );
  set("short", "Hill towards the sea");
  set( "long", @EndText
You are standing in a hill that leads to the sea.
As you close your eyes, you hear the wonderful and soothing
music of the blue sea. Each sound refreshes and purifies your soul.
The ground is a bright green grass, decorated by beautiful wildflowers.
There is no way out of this place, only the same way you came in.
Still, this place invites you to stay, forever...
EndText
);
  set("exits", ([
  "southeast" : "/u/d/dreams/rooms/statues.c",
  "portal" : "u/d/dreams/workroom.c",
]) );
}
