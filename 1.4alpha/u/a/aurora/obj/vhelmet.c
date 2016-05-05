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
          return({"/wizards/aurora/obj/vhelmet", ({}) });
      }
 
void create() {
  ::create();
      seteuid(getuid());
      set_name("vhelmet");
      set_id( ({ "vhelmet", "helmet", "viking helmet", "castle helmet", }) );
      set_short("A Viking Helmet");
      set_long("This is a viking helmet, with horns and all.\n"
      "\nType 'help vhelmet' for a list of commands.\n"
      "\n");
      set_weight(10);
      set_value(0);

}


     int arrival() {
          int x;
          object group;

     for(x=0;x<sizeof(users());x++){
          group = users()[x];
       if(present("vhelmet", group) && (string)this_player()->query_cap_name() != "Someone"){
       tell_player(group, ">>> "+(string)this_player()->query_cap_name()+" has Arrived!!! <<<\n");

     }
     }
}
      int quit() {
       int x;
       object group;
       
       for(x=0;x<sizeof(users());x++){
          group = users()[x];
      
      if(present("vhelmet", group)){
      tell_player(group, ">>> "+(string)this_player()->query_cap_name()+" is Gone. <<<\n");
     }
     }

      return 0;
     }

   int drop() {
	write("Hey stupid, you can't drop your viking helmet.");
	return 1;
}
   int give() {
	write("It's not up to you who gets a viking helmet!!");
	return 1;
}


    void init() {

      add_action("quit","quit");
      add_action("cmd_who","scan");
      add_action("stonecry","cc");
      add_action("stonecryemote","cce");
      add_action("updatestone","udvhelmet");
      add_action("whostone","whocc");
      add_action("stonehelp","help");
      add_action("dest","dest");
      add_action("wear","wear");
      add_action("vitilize","vitilize");
      arrival();

}

      int dest(string str) {
      if(str == "vhelmet"){
          write("Nope, no can do.");
          return 1;
          }
      if(str == "helmet") {
          write("I'd talk to Aurora about this if I were you.");
          return 1;
          }
      if(str == "viking helmet"){
          write("You can't dest your helmet!");
          return 1;
          }
      return 0;
      }

     int stonehelp(string str) {
      if(str == "vhelmet"){
          write(
"                   VIKING HELMET HELP SCREEN\n"+
"|====================|====================|====================|\n"+
"|COMMAND             |ARGUMENT            |DESCRIPTION         |\n"+
"|====================|====================|====================|\n"+
"|help                |vhelmet             |This help screen.   |\n"+
"|cc                  |<message>           |Private castle chat.|\n"+
"|                    |                    |                    |\n"+
"|cce                 |<emote message>     |Emote over the line.|\n"+
"|                    |                    |                    |\n"+
"|whocc               |                    |Shows all who have  |\n"+
"|                    |                    |a viking helmet.    |\n"+
"|vitilize            |                    |In the works.       |\n"+
"|==============================================================|\n"+
"Viking Helmet Version 1.0                                1101.96\n"+
"\n");
     return 1;
     return 0;
      }
}
      int whostone() {
          int x;
          object group;

      write("Out of those logged on, the following have a Viking Helmet:");
      for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("vhelmet", group)){
      write(" "+group->query_cap_name());
      }
    }
      return 1;
   }

     int stonecry(string str) {

int y, x;
object group;

  if(!str){
    if(!present("novhelmet", this_player())){
      write("You are now blocking Viking Helmet messages.\n");
      set_id( ({"vhelmet", "helmet", "viking helmet", "castle helmet", "nocomm"}) );
    }
    else{
      set_id( ({"vhelmet", "helmet", "viking helmet", "castle helmet"}) );
      write("You are no longer blocking Viking Helmet Messages.\n");
    }
  }
  else {
    if(present("novhelmet", this_player())){
      write("You are no longer blocking Viking Helmet messages.\n");
      y=1;   
    }
    set_id( ({"vhelmet", "helmet", "viking helmet", "castle helmet"}) );
    for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("vhelmet", group)){
        if(!present("novhelmet", group)){
       tell_player(group, "==> "+(string)this_player()->query_cap_name()+" sends: "+str+" <==\n");
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
    if(present("vhelmet", group) && (!present("novhelmet", group))){
       tell_player(group, "==> "+(string)this_player()->query_cap_name()+" "+str+" <==\n");
    }
  }
  return 1;
}

      int updatebrose() {

       write("A new Viking Helmet is presented to you.");
      new("/wizards/aurora/obj/vhelmet.c")->move(this_player());
      this_object()->remove();
      return 1;
   }
 int vitilize() {
    int x;
    object group;
     write("Holding your viking helmet upside down, you rub "
     "it's horns.  Suddenly it's filled with mulled wine.  You tip "
     "back the helmet and chug it's contents.\n"
     "You belch loudly.\n"
	);
     say(this_player()->query_cap_name()+" rubs their viking helmet "
     "and it fills with liquid.  "+this_player()->query_cap_name()+" chugs it's contents.\n"
     ""+this_player()->query_cap_name()+" belches loudly."
	);

      return 1;
   }
 int wear(string str) {
    if(str =="helmet"){
     write("Hey stupid, you can't _wear_ this helmet. ");
     say(this_player()->query_cap_name()+" realizes they "
     "can't wear the viking helmet.\n");
      return 1;
       }
      return 0;
   }

