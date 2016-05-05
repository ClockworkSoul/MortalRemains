#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Large, magestic tree" );
  set( "long", @EndText
A huge, breathtaking tree dominates this section of
the forest. Its bark is a warm, golden brown. The
leaves are the deepest emerald green anywhere in the
forest. A nest is cradled where the lowest branch 
joins the trunk, just above a small hollow which has
been carved into the tree.
EndText
  );
  set( "item_desc", ([
    "tree" : "This is an incredibly large, beautiful tree.\n",
    "forest" : "This is a pleasantly open forest. The trees are far enough apart to pass between easily.\n",
    "bark" : "The bark of the large tree is smooth and golden brown.\n",
    "leaves" : "The leaves of this tree are deep, emerald green.\n",
    "nest" : "A nest made from dried grass and leaves sits where a large branch joins the trunk of this tree.\n",
    "branch" : "A large branch leaves the tree trunk below any other branches.\n",
    "hollow" : "A small, round hole has been carved into the trunk of this tree.\n",
    "trunk" : "The trunk of this tree is very wide around and covered with smooth brown bark.\n",
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/lforest/forest15.c",
    "west" : "/u/r/rislyn/forest/lforest/forest13.c",
    "north" : "/u/r/rislyn/forest/lforest/forest6.c",
    "south" : "/u/r/rislyn/forest/lforest/forest24.c"
  ]) );
}



