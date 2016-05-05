#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Crumple Street");
  set( "long" , @EndText
  You stand upon Crumple Street. On the north wall that runs along the
  street, is a plaque. There is a small statue just below the plaque
  that catches your attention.

EndText
  );
  set( "exits", ([
    "west" : STREET+"street17.c",
    "east" : STREET+"street19.c",
  ]) );
  set("item_desc" , ([
    "plaque" : "Something seems to be engraved in it.\n",
    "engraving" : "Maybe you should read it.\n",
    "statue" : "It is a statue of Mayor Crumple.\n",
  ]));
}
void init(){
  add_action("read_func" , "read");
}
int read_func(string str){
  if(!str){
    write("What would you like to read?\n");
  return 1 ; }
  if(str == "engraving"){
    write("'In dedication for years of service, we the people of the City of Dagaard donate this plaque and statue to Crumple, Mayor of the City.'\n");
  return 1; }
return 1;
}
