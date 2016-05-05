
#include <std.h>

inherit OBJECT;
inherit "/adm/cmds/creator/_xwho.c";
 
      mixed *query_auto_load(){
          return({"/wizards/aurora/obj/bheart.c", ({}) });
      }
 
void create() {
  ::create();
      seteuid(getuid());
      set_name("bheart");
      set_id( ({ "bheart", "heart", "bleeding heart", "bleedingheart", }) );
      set_short("A Bleeding Heart");
      set_long("A sad, lonely looking heart.\n"
      "Blood drips from it's wounds slowly.\n"
      "\nType 'help bheart' for a list of commands.\n"
      "\n");
      set_weight(10);
      set_value(0);

}


     int arrival() {
          int x;
          object group;

     for(x=0;x<sizeof(users());x++){
          group = users()[x];
      if(present("bheart", group) && (string)this_player()->query_cap_name() 
!= "Someone"){
      tell_player(group, "*&*"+(string)this_player()->query_cap_name()+" 
has Entered Circle *&*\n");� 1;
     }


      int quit() {
       int x;
       object group;
       
       for(x=0;x<sizeof(users());x++){
          group = users()[x];
      
      if(present("bheart", group)){
      tell_player(group, "*&* "+(string)this_player()->query_cap_name()+"  has Left Circle.*&*\n");
     }
     }

      return 0;
     }

    void init() {

      add_action("quit","quit");
      add_action("cmd_who","scan");
      add_action("drop","drop");
      add_action("stonecry","bh");
      add_action("stonecryemote","bhe");
      add_action("updatestone","udbheart");
      add_action("whostone","whoheart");
      add_action("stonehelp","help");
      add_action("dest","dest");
      arrival();

}

      int drop(string str) {
      if(str == "bheart"){
      write("That is your bleeding heart, why would you want to drop it?");
          return 1;
          }
      if(str == "bleeding heart"){
      write("I'm sorry, but you are stuck with that bleeding heart.");
          write("You cannot drop it.");
          return 1;� heart"){
          write("You cannot do that!");
          return 1;
          }
      return 0;
      }

     int stonehelp(string str) {
      if(str == "bheart"){
          write(
"                         BLEEDING HEART HELP SCREEN\n"+
"|====================|====================|=�===================|\n"+
"|COMMAND             |ARGUMENT            |DESCRIPTION         |\n"+
"|====================|====================|=�===================|\n"+
"|help                |bheart              |This help screen.   |\n"+
"|bh                  |<message>           |Private chat channel|\n"+
"|                    |                    |                    |\n"+
"|bhe                 |<emote message>     |Emote over the heart|\n"+
"|                    |                    |channel.            |\n"+
"|udbheart            |                    |Updates your heart  |\n"+
"|                    |                    |to the most recent  |\n"+
"|                    |                    |version.            |\n"+
"|whobheart           |                    |Shows all who have  |\n"+
"|                    |                    |a bleeding heart    |\n"+
"|scan                |                    |An advanced form of |\n"+
"|                    |                    |the basic who       |\n"+
"|                    |                    |command.            |\n"+�                   1115.95\n"+
"\n");
     return 1;
     }
     return 0;
�  write("You are no longer blocking Bleeding Heart messages.\n");
      }
     }
      else{
      if(present("nobheart", this_player())){
      write("You are no longer blocking Bleeding Heart messages.\n");
         y=1;
         }
      set_id( ({"heart", "bheart", "bleeding heart", "bleedingheart"}) );
      for(x=0;x<sizeof(users());x++){
      group = users()[x];
      if(present("bheart", group)){
      if(!present("nobheart", group)){
      tell_player(group, "*#*"+(string)this_player()->query_cap_name()+" 
sends: "+str+"*#*\n");
      }
      }
      }
       }
      return 1;
      }

�{

       write("A new version of the Bleeding Heart is presented to you.");
      new("/wizards/aurora/obj/bheart.c")->move(this_player());
      this_object()->remove();
      return 1;
   }
 
 
