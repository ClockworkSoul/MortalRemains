inherit ROOM;


void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 1);
set ("area_type", ([
  "green" : 2,
  "black" : 2
  ]) );
  set ("short", "Enchanted Garden" );
  set( "long", @EndText
  A generic room in the Obscene Garden of Thylassa
EndText
  );
  set( "exits", ([
"west" : "/u/c/cyanide/wkrms/craproom.c",
  ]) );
}
