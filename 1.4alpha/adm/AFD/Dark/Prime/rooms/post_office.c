
// Post1.c
// A room which allows access to Huthar's mailer.
// Written by Mobydick@TMI-2, 9-30-92
// Most of the code was taken from the _mail.c command, written by
// Huthar and Buddha.
// The room uses add_action() to define a mail command. If the player types
// that command, a clone of the portable mailer is give to him, and he
// enters the mailer. When he quits the mailer, it destructs itself: it
// also is destructed if he leaves the post office by going north, via
// the pre_exit_func property.

#include <mailer.h>
#include <mudlib.h>
#include "../Prime.h"

inherit ROOM ;

void create() {
        ::create();
seteuid(getuid()) ;
set("short", "The Post Office.");
  set("long", @ENDLONG
You are in the town's post office.  You can send mail from here, and
if other people send you mail you can read it here.
There is a sign on the wall that you could read also.
ENDLONG
  );
set("light",1) ;
set ("pre_exit_func", ([ "north" : "dest_mailer" ]) ) ;
  set("exits", ([
    "south" : D_PRIMER+"/road1'0.c",
  ]) );
set ("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init() {
add_action("mail", "mail") ;
add_action("from", "from");
        add_action("help", "help");
add_action ("read_sign", "read") ;
}

int from(string arg) {
  call_other("/cmds/wiz/_from", "cmd_from", arg);
  return 1;
}
int mail(string arg) {
/*   Commented out cuz Chronos thinks he can do it better..

   object ob;

   seteuid("TEMP");

   ob = new(MAILER);
   write("This room just tried to clone a mailer: " + identify(ob)+"\n");
   ob->move(this_player());
   ob->start_mail(arg);
*/
  call_other("/cmds/wiz/_mail", "cmd_mail", arg);
   return 1;
}

int help(string str) {
    if (str == "mail") {
this_player()->more(MAILER_LONG);
return 1;
    } else return 0;
}

int read_sign (string str) {
if (str && str!="sign") return 0 ;
write (
@ENDSIGN
The sign says:

   The following commands are valid here:

   mail <recipient>   -  Allows you to mail someone and read your mail.
   from [new]         -  Allows you to view who your mail is from.

ENDSIGN
  );
  say(TPN+ " reads the sign on the wall.\n") ;
return 1 ;
}

int dest_mailer() {

object ob ;

ob = present("mailer",this_player()) ;
if (ob) ob->remove() ;
return 0 ;
}
