#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
 	seteuid(getuid());
  set( "light", 1 );
  set( "short" , "Donnie's House of Sex Toys");
  set( "long" , @EndText
  You have stepped into a shop containing nothing but sexual devices.
  Racks of Porn magazines line the walls, and through the middle of
  the shop, are rows of Porn videos. You can see a small sign behind
  the desk. On top of the desk are small toys and other gadgets.

EndText
  );
  set( "exits", ([
    "south" : STREET+"street4.c",
  ]) );
  set("item_desc" , ([
    "sign" : "\n"+
    "                         -={     Donnie's Sex Shop     }=-\n"+
    "\n"+
    "          Inflatable Pig.............................1000 coins\n"+
    "          Inflatable Sheep...........................1000 coins\n"+
    "          Magazine...................................200 coins\n"+
    "          Video......................................300 coins\n"+
    "          Ticket for Hookers R Us....................250 coins\n"+
    "\n"+
    "                                  No Refunds.\n",
    "video" : "A wide selection of videos.\n",
    "videos" : "A wide selection of videos.\n",
    "magazine" : "Everything from Hustler to Playboy.\n",
    "magazines" : "Everything from Hustler to Playboy.\n",
    "toys" : "Various things, ranging from Ben Wa balls to Inflatable\n"+
    "camels.\n",
    "gadgets" : "Vibrators that look like fists, and mouths catch\n"+
    "your eye. You wonder about them.\n",
    "vibrators" : "Umm. Vibrators.\n",
    "sheep" : "Inflatable sheep. Hey, whatever floats your boat.\n",
    "pigs" : "Inflatable pigs. Hey whatever floats your boat.\n",
    "camels" : "You're amazed by the camels? What about the pigs\n"+
    "and sheep?\n",
  ]));
  set("exit_msg", ([
    "south" : "$N has enough porn, so he leaves south.\n",
  ]) );
}
void init(){
  add_action("buy_toy" , "buy");
}
int buy_toy(string str){
  object ob;
  if(!str){
    write("What would you like to buy?\n");
    return 1;
  }
      switch (str) {
      case "pig":
    write("You buy an inflatable pig.\n");
    ob = clone_object("/d/Prime/Dagaard/dilligaf/obj/pig.c");
    ob->move(this_player());
    say(TPN+" buys an inflatable pig.\n");
  break;
  	case "sheep":
    write("You buy an inflatable sheep.\n");
    ob = clone_object("/u/d/dilligaf/obj/sheep.c");
    ob->move(this_player());
 say(TPN+" buys an inflatable sheep.\n");
  break;
 	case "magazine":
    write("You buy a magazine.\n");
    ob = clone_object("/u/d/dilligaf/obj/magazine.c");
    ob->move(this_player());
    say(TPN+" buys a magazine.\n");
   break;
   case "ticket":
    write("You buy a ticket.\n");
    ob = clone_object("/u/d/dilligaf/obj/ticket.c");
    ob->move(this_player());
 say(TPN+" buys a ticket.\n");
 break;
 case "video":
    write("You buy a video.\n");
    ob = clone_object("/u/d/dilligaf/obj/video.c");
    ob->move(this_player());
    say(TPN+" buys a video.\n");
 default:
return 1;
    }
    return 1;
    }

