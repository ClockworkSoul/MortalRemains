//The Autocoder base obj.
// Zur, May 6, 1997

#define BASE "/u/z/zur/priv/AC1.0/"
#include "ac.h"
#include <mudlib.h>
inherit OBJECT;
inherit BASE+"make_room.c";
// Why the hell do I have to put this here????

int start_code();
int not_avail(){
  printf("That service is not availible at this time.\n");
  start_code();
  return 1;
  }

int finish_up(){
    file += "\t::create();\n}";
    write_file(fname, file);
    call_out("ud", 0);
    return 1;
    }
int ud(){
   call_other("/cmds/object/_update", "cmd_update", fname);
   return 1;
   }
   
void create(){
   seteuid(getuid(this_object()));
   set("short", "book entitled \"How to Build a Universe in a Day\"");
   set("long", @EndLong
Bob Villa's guide to building the universe is a detailed
program built for those wizards who wish to code an area
quickly and easily. Start by using the syntax [startcode].
EndLong);
  set("id", ({ "guide", "book" }));
}

void init(){
add_action("start_code", "startcode");
}
   
int start_code(){
  seteuid( getuid(this_player()) );
  write("<-------------------------AutoCoder 1.0--------------------------->\n"+
        "  Please choose a type of object to code from the below selections:\n");
  printf("\t%:-14s%:-14s%:-14s\n\t%:-14s%:-14s\n", "a) Room", "b) Monster", "c) Armor",
 										 "d) Weapon", "e) Object" );
 
  printf("Use the form [selection] [file name].\n");
  printf(PROMPT);
  input_to("begin_file");
  return 1;
  }
 
int begin_file(string str)
{
  string d, f;
  file = "";
  d = TP->query("cwd");

  if(sscanf(str, "%s %s", str, f) != 2)
  {
     printf(PROMPT);
     input_to("begin_file");
     return 1;
  }
   fname = d + "/" + f;
   fname +=  (extract(f, strlen(f)-2, strlen(f)-1) == ".c") ? "" : ".c";
   switch(str)
   {
     case "q": return 1;
     case "a":
     case "A": make_room(); break;
     case "b":
     case "B": not_avail();/*make_monster();*/ break;
     case "c":
     case "C": not_avail();/*make_armor();*/ break;
     case "d":
     case "D": not_avail();/*make_weapon();*/ break;
     case "e":
     case "E": not_avail();/*make_object();*/ break;
     default: start_code();
  }
  return 1;
}

  
  
  
  