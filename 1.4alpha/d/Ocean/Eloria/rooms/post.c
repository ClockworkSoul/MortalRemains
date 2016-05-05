/*
** File:  /u/n/nemar/water/city/rooms/post.c
** Author Lord Nemar of the Shadoweir
** Original code from /d/Prime/Central/room/post_office.c
*/

#include "/d/Prime/Central/room/central.h"
#include <mailer.h>
#include <mudlib.h>
#include "eloria.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid() );
    set("short", "Eloria's Post Office");
    set("long", @EndText
You are in Eloria's post office.  You can send and recieve mail from
here.  There is a sign on the wall that you could read also.
EndText
    );
    set("light", 1);
    set("safe", 1);
    set("exits", ([
      "north" : eloria+"central1b.c",
    ]) );
    set("pre_exit_func", (["north" : "dest_mailer"]) );
    set("item_fuc", (["sign" : "read_sign"]) );
}

void init(){
    add_action("mail", "mail");
    add_action("help", "help");
    add_action("read_sign", "read");
}

int mail(string arg) {

    object ob;

    seteuid("TEMP");

    ob = new(MAILER);
    ob->move(this_player() );
    ob->start_mail(arg);
    return 1;
}

int help(string str) {
    if(str == "mail") {
	this_player()->more(MAILER_LONG);
	return 1;
    } else return 0;
}

int read_sign (string str) {
    if (str && str!="sign") return 0;
    write (
      "type 'mail' to read your mail and 'mail <name>' to send mail.\n");
    return 1;
}

int dest_mail(){

    object ob;

    ob = present("MAILER", this_player() );
    if (ob) ob->remove();
    return 0;
}
