//commbadge.c
//as modified from glowstone.c
//created by Shadrach
//(c) 1994 R. Voss
//all rights reserved
//this code may not be distributed in public or private
//without the express permission of it's creator.
//permission was granted by Shadrach/R. Voss to Aurora/A. Cail
//to use commbadge.c code for a similar object of similar
//intent.

// Debugging by beans@circle_of_ourobouros

//for a full listing of credits see /wizards/shadrach/misc/glowstone.c

#include <std.h>

inherit OBJECT;
 
      mixed *query_auto_load(){
          return({"/wizards/aurora/obj/brose", ({}) });
      }
 
void create() {
  ::create();
      seteuid(getuid());
      set_name("brose");
      set_id( ({ "brose", "rose", "black rose", "blackrose", }) );
      set_short("A Stunning Black Rose");
      set_long("You gaze upon this stunning black rose.\n"
      "It's petals are soft, and black as chaos.\n"
      "\nType 'help brose' for a list of commands.\n"
      "\n");
      set_weight(10);
      set_value(0);

}


     int arrival() {
          int x;
          object group;

     for(x=0;x<sizeof(users());x++){
          group = users()[x];
       if(present("brose", group) && (string)this_player()->query_cap_name() != "Someone"){
       tell_player(group, "*** "+(string)this_player()->query_cap_name()+" has Entered Circle ***\n");

     }
     }
}
      int quit() {
       int x;
       object group;
       
       for(x=0;x<sizeof(users());x++){
          group = users()[x];
      
      if(present("brose", group)){
      tell_player(group, "*** "+(string)this_player()->query_cap_name()+"  has Left Circle. ***.\n");
     }
     }

      return 0;
     }

   int drop() {
	write("You cannot drop your black rose.");
	return 1;
}
   int give() {
	write("You cannot give your black rose away.");
	return 1;
}


    void init() {

      add_action("quit","quit");
      add_action("cmd_who","scan");
      add_action("stonecry","br");
      add_action("stonecryemote","bre");
      add_action("updatestone","udbrose");
      add_action("whostone","whorose");
      add_action("stonehelp","help");
      add_action("dest","dest");
      arrival();

}

      int dest(string str) {
      if(str == "brose"){
          write("You cannot do that!");
          return 1;
          }
      if(str == "rose") {
          write("You cannot do that!");
          return 1;
          }
      if(str == "black rose"){
          write("You cannot do that!");
          return 1;
          }
      return 0;
      }

     int stonehelp(string str) {
      if(str == "brose"){
          write(
"                         BLACK ROSE HELP\n"+
"|====================|====================|====================|\n"+
"|COMMAND             |ARGUMENT            |DESCRIPTION         |\n"+
"|====================|====================|====================|\n"+
"|help                |brose               |This help screen.   |\n"+
"|br                  |<message>           |Private chat channel|\n"+
"|                    |                    |                    |\n"+
"|bre                 |<emote message>     |Emote over the rose |\n"+
"|                    |                    |channel.            |\n"+
"|whorose             |                    |Shows all who have  |\n"+
"|                    |                    |a black rose        |\n"+
"|==============================================================|\n"+
"Black Rose Version 1.2                                   1122.95\n"+
"\n");
     return 1;
     return 0;
      }
}
      int whostone() {
          int x;
          object group;

      write("The following people have a Black Rose:");
      for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("brose", group)){
      write(" "+group->query_true_name());
      }
    }
      return 1;
   }

     int stonecry(string str) {

int y, x;
object group;

  if(!str){
    if(!present("nobrose", this_player())){
      write("You are now blocking Black Rose messages.\n");
      set_id( ({"rose", "brose", "black rose", "blackrose", "nocomm"}) );
    }
    else{
      set_id( ({"rose", "brose", "black rose", "blackrose"}) );
      write("You are no longer blocking Black Rose Messages.\n");
    }
  }
  else {
    if(present("nobrose", this_player())){
      write("You are no longer blocking Black Rose messages.\n");
      y=1;   
    }
    set_id( ({"rose", "brose", "black rose", "blackrose"}) );
    for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("brose", group)){
        if(!present("nobrose", group)){
       tell_player(group, "*&* "+(string)this_player()->query_cap_name()+" sends: "+str+" *&*\n");
        }
      }
    }
    return 1;
  }
}
int stonecryemote(string str) {
  int x;
  object group;
    for(x=0;x<sizeof(users());x++){
    group = users()[x];
    if(present("brose", group) && (!present("nobrose", group))){
       tell_player(group, "*&* "+(string)this_player()->query_cap_name()+" "+str+" *&*\n");
    }
  }
  return 1;
}

      int updatebrose() {

       write("A new Black Rose is presented to you.");
      new("/wizards/aurora/obj/brose.c")->move(this_player());
      this_object()->remove();
      return 1;
   }
 
 
