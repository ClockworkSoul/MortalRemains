
inherit ROOM;
int feather_here;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
feather_here=1;
set( "author", "sophia");
set("objects", (["feather" : "/u/s/sophia/feather.c"]) );
reset();
set( "short", "The Playground" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
A shower of rainbow coloured leaves as you enter let 
you know that you have entered a place of play. All sorts of creatures 
swing from branch to branch and birds sing happily.
EndText );
  set( "exits", ([
"north" : "/u/s/sophia/workroom2.c",
  ]) );
}
void init() {
add_action("get", "get");
add_action("enter_veil", "enter");
}

int get (string str) {
object feather ;   
if (str=="bird") {
if (feather_here) {
feather=clone_object("/u/s/sophia/feather.c");
feather->move("/u/s/sophia/bedroom.c");
write("You try to catch the bird, but it escapes, leaving only a"+
" feather behind. An image of Sophia runs in and grabs the feather,"+
" then takes off with it.\n");
say(TPN+"tries to catch a bird, but it escapes, leaving only a feather"+
" behind. An image of Sophia runs in and grabs the feather, then takes"+
" off with it.\n");
feather_here=0;
return 1;
}
return 0;
}
}
int enter_veil(string str) {
write("if you enter you may never come back\n");
say(TPN+" disappears into the vines\n");
this_player()->move_player("/u/s/sophia/kitchen.c");
say(TPN+" enters leaving the vines swinging\n");
return 1;
}
