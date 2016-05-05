#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set( "short" , "The Angel of Death's Room");
  set( "long", @EndText
  You are standing in the entrance of a vast hall. Weapons on the
  walls and bones tossed haphazardly into the corners tell you that
  what ever creature lives here, isn't too keen on seeing visitors.
  Perhaps you should leave while you still can. Various machines of
  pain and destruction are abandoned around the room. You can see
  a catapault, a guillotine, an iron maiden, THE rack, and other
  forms of torture. In fact there are even some Rap albums near a
  stereo to place anguish on all who listen. This is truly the room
  of pain. Off to one side is a sign.


EndText
  );
  set( "exits", ([
    "city" : "/d/Prime/Dagaard/dilligaf/street/street1.c",
    "start" : START,
    "oblivion" : "/d/Prime/Dagaard/dilligaf/cellar.c",
  ]) );
  set("id" , ({ "beer" }) );
  set("item_desc" , ([
    "sign" : "          -={     Welcome to OBLIVION     }=-\n",
    "catapault" : "A large wooden spoon like contraption strapped\n"+
    "bent in order to produce a large enough spring.\n",
    "guillotine" : "The razor sharp edge of the blade has blood on it.\n",
    "iron maiden" : "Nails protruding from a sarcophogas...very\n"+
    "comforting.\n",
    "rack" : "This thing is fucking HUGE. The ropes themselves\n"+
    "must be a foot thick. You wonder what kind of beast could\n"+
    "be tortured on such a device.\n",
    "machines" : "Amonst the machines you see a canister laying on\n"+
    "its side.\n",
    "bones" : "Various bones from all kinds of creatures.\n",
    "albums" : "Oh shit. Rap. You double over an puke just thinking\n"+
    "about the pain that they bring.\n",
    "stereo" : "A large black stero.\n",
    "weapons" : "Everything under the sun, if its a weapon...its\n"+
    "in this room.\n",
    "canister" : "Its a KEG!\n",
    "keg" : "Of course there is a keg in this room, would you\n"+
            "expect less?\n",
  ]));
}
void init(){
  add_action("get_func" , "get");
  }
int get_func(string str){
  if(!str){
    write("Get what?\n");
    return 1;
  }
  if(str == "beer"){
    write("You pump the keg and pour your self a nice cup of beer and slam it down. AHHH! thats refreshing.\n");
    say(TPN+" pumps the keg a little and pours a beer, then slams it down with a satisfying 'AHHH!'\n");
    return 1;
  }
  return 0;
}
