// post_office.c
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
#include "sigil.h"

inherit ROOM ;

void create() {
    ::create();
	seteuid(getuid()) ;
  set("short", "The Festive Civic Festhall.") ;
	set ("exits", ([
		"east" : SIGIL+"hullst1.c",
		"south" : SIGIL+"festhall1.c",
        "west" : SIGIL+"festhall2.c" ])
    );       
    set("long", @EndMail
You are in The Civic Festhall. A place to relax.
It has been festively decorated for a change of pace.
You can send mail from here, and if other people send you mail, 
you can read it also.
There is a sign on the wall that you could read also.
EndMail
    );
	set("light",1) ;
	set ("pre_exit_func", ([ "east" : "dest_mailer",
		"south" : "dest_mailer",
		"west" : "dest_mailer",
	 ]) ) ;
	set ("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init() {
	add_action("mail", "mail") ;
    add_action("help", "help");
	add_action ("read_sign", "read") ;
}

int mail(string arg) {

   object ob;

   seteuid("TEMP");

   ob = new(MAILER);
   ob->move(this_player());
   ob->start_mail(arg);
   return 1;
}

int help(string str) {
    if (str == "mail") {
	this_player()->more(MAILER_LONG);
	return 1;
    } else return 0;
}

//Zur-ism's added by Cyanide.  :)   23 May 97
int read_sign (string str) {
	if (str && str!="sign") return 0 ;
	write (
"The sign on the wall reminds you that you can still send in a postcard\n"+
"saying whether you prefer the \"Old Zur\" stamp or the \"Young Zur\"\n"+
"stamp. It also says that you can type \"mail\" to read your mail, and you\n"+
"can type \"mail <name>\" to send mail to another player.\n") ;
	return 1 ;
}

int dest_mailer() {

	object ob ;

	ob = present("mailer",this_player()) ;
	if (ob) ob->remove() ;
	return 0 ;
}
