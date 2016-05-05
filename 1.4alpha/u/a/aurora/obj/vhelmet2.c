
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
          return({"/wizards/aurora/obj/vhelmet2.c", ({}) });
      }
 
void create() {
  ::create();
      seteuid(getuid());
      set_name("vhelmet2");
      set_id( ({ "vhelmet2", "helmet", "castle helmet", "castlehelmet", }) );
      set_short("A Viking Helmet");
      set_long(
      "\nType 'help vhelmet2' for a list of commands.\n"
      "\n");
      set_weight(10);
      set_value(0);

}


     int arrival() {
          int x;
          object group;

     for(x=0;x<sizeof(users());x++){
          group = users()[x];
       if(present("vhelmet2", group) && (string)this_player()->query_cap_name() != "Someone"){
         tell_player(group, ">>> "+(string)this_player()->query_cap_name()+" has Arrived!!! <<<\n");

     }
     }
}
      int quit() {
       int x;
       object group;
       
       for(x=0;x<sizeof(users());x++){
          group = users()[x];
      
      if(present("vhelmet2", group)){
       tell_player(group, ">>> "+(string)this_player()->query_cap_name()+" is Gone. <<<\n");
     }
     }

      return 0;
     }

    void init() {

      add_action("quit","quit");
      add_action("drop","drop");
      add_action("stonecry","cc");
      add_action("stonecryemote","cce");
      add_action("updatestone","udvhelmet2");
      add_action("whostone","whohelmet");
      add_action("stonehelp","help");
      add_action("dest","dest");
        add_action("wear","wear");
        add_action("vitilize","vitilize");
      arrival();

}

      int drop(string str) {
      if(str == "vhelmet2"){
      write("That is your black rose, why would you want to drop it?");
          return 1;
          }
      if(str == "black rose"){
      write("I'm sorry, but Annette wouldn't like that!");
          write("You cannot drop it.");
          return 1; 
          }
      }

      int dest(string str) {
      if(str == "vhelmet2"){
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
      if(str == "vhelmet2"){
          write(
"                         BLACK ROSE HELP\n"+
"|====================|====================|====================|\n"+
"|COMMAND             |ARGUMENT            |DESCRIPTION         |\n"+
"|====================|====================|====================|\n"+
"|help                |vhelmet2               |This help screen.   |\n"+
"|cc                  |<message>           |Private chat channel|\n"+
"|                    |                    |                    |\n"+
"|cce                 |<emote message>     |Emote over the rose |\n"+
"|                    |                    |channel.            |\n"+
"|whorose            |                    |Shows all who have  |\n"+
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
      if(present("vhelmet2", group)){
      write(" "+group->query_cap_name());
      }
    }
      return 1;
   }

     int stonecry(string str) {

int y, x;
object group;

  if(!str){
    if(!present("novhelmet2", this_player())){
      write("You are now blocking Black Rose messages.\n");
      set_id( ({"rose", "vhelmet2", "black rose", "blackrose", "nocomm"}) );
    }
    else{
      set_id( ({"rose", "vhelmet2", "black rose", "blackrose"}) );
      write("You are no longer blocking Black Rose Messages.\n");
    }
  }
  else {
    if(present("novhelmet2", this_player())){
      write("You are no longer blocking Black Rose messages.\n");
      y=1;   
    }
    set_id( ({"rose", "vhelmet2", "black rose", "blackrose"}) );
    for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("vhelmet2", group)){
        if(!present("novhelmet2", group)){
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
    if(present("vhelmet2", group) && (!present("novhelmet2", group))){
       tell_player(group, "*&* "+(string)this_player()->query_cap_name()+" "+str+" *&*\n");
    }
  }
  return 1;
}

      int updatevhelmet2() {

       write("A new Black Rose is presented to you.");
      new("/wizards/aurora/obj/vhelmet2.c")->move(this_player());
      this_object()->remove();
      return 1;
   }
 
 
