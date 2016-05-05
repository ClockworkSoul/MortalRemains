#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("light", 1);
    set("short", "Jail");
    set( "long", @EndText
You are behind bars..you have been bad.
EndText
    );
    set( "exits", ([
    ]) );
}

void init() {
    if (!adminp(TP)) {
	add_action("help", "help");
	add_action("mudinfo", "mudinfo");
	add_action("event", "event");
	add_action("dref", "dref");
	add_action("gate", "gate");
	add_action("cp", "cp");
	add_action("localcmd", "localcmd");
	add_action("encrypt", "encrypt");
	add_action("vundercamel", "return");
	add_action("eval", "eval");
	add_action("cast", "cast");
	add_action("start", "start");
	add_action("wizhall", "wizhall");
	add_action ("kill", "kill");
	add_action ("call", "call");
	add_action ("sc", "sc");
	add_action ("trace", "trace");
	add_action ("tell", "tell");
	add_action ("goto", "goto");
	add_action ("wiz", "wiz");
	add_action ("shout", "shout");
	add_action ("quit", "quit");
	add_action ("gossip", "gossip");
	add_action ("home", "home");
	add_action ("clone", "clone");
	add_action ("dest", "dest");
	add_action ("ed", "ed");
	add_action ("update", "update");
	add_action ("move", "move");
	add_action ("gwiz", "gwiz");
	add_action ("doc", "doc");
	add_action ("code", "code");
	add_action ("question", "question");
	add_action ("driver", "driver");
	add_action ("mudlib", "mudlib");
	add_action ("dinosaur", "dinosaur");
	add_action ("more", "more");
	add_action ("who", "who");
	add_action ("people", "people");
	add_action ("foo", "ls");
	add_action ("camel", "cd");
    }
    add_action ("out_func", "toria");
}
int help(){
    say(TPN+" tried to get help.\n");
    write("You are far beyond help.\n");
    return 1;
}
int mudinfo(){
    say(TPN+" mudinfo'd.\n");
    write("You want info, read a book.\n");
    return 1;
}

int event(){
    say(TPN+" tried to use an event.\n");
    write("The only event you will se is Nightmask kicking your ass.\n");
    return 1;
}
int dref(){
    say(TPN+" derf'd stuffs.\n");
    write("There's not fred here, or Dref for that matter.\n");
    return 1;
}
int gate(){
    say(TPN+" tried to gate.\n");
    write("No gates little one, only bars.\n");
    return 1;
}
int cp(){
    say(TPN+" tried to copy a file.\n");
    write("That's cheating, your already in jail.\n");
    return 1;
}
int mv(){
    say(TPN+" tried to move somthing.\n");
    write("Move all you want, you can not escape.\n");
    return 1;

}
int localcmd(){
    say(TPN+" just tried a localcmd.\n");
    write("Bad nubian princess, no salsbury steak for you.\n");
    return 1;
}
int encrypt(){
    say(TPN+" typed that encrypt thingie.\n");
    write("Nightmask don't know what it is, but it bad.\n");
    return 1;
}
int vundercamel() {
    say(TPN+" tried to return.\n");
    write("You return to the jail, how sweet is that?\n");
    return 1;
}
int eval() {
    say(TPN+" just tried to eval.\n");
    write("Do you even know what that means?\n");
    return 1;
}
int cast(){
    say(TPN+" tried to cast a spell.\n");
    write("Shia, like they wouldn't break your hands?\n");
    return 1;
}
int wizhall() {
    say (TPN+" just tried to escape to the wizhall.\n");
    write("Foolish wizard, wizhalls are for good wizards.\n");
    return 1;
}

int start(){
    say(TPN+" just tried to leave start.\n");
    write("Infidel, you are trapped here.\n");
    return 1;
}
int tell() {
    say (TPN+" tried to send a tell.\n");
    write ("You are not permitted to send tells here.\n");
    return 1;
}

int goto() {
    say (TPN+" tried to leave the room.\n");
    write ("You bounce off the bars.\n");
    return 1;
}

int wiz() {
    say(TPN+" tried to use wiz chat.\n");
    write("You may not use chat-lines while in jail.\n");
    return 1;
}

int shout() {
    say (TPN+" tried to shout.\n");
    write ("You run out of air.\n");
    return 1;
}

int quit() {
    say (TPN+" tried to quit.\n");
    write ("You may not quit.\n");
    return 1;
}

int home() {
    say (TPN+" tried to go home.\n");
    write ("You may not teleport from here.\n");
    return 1;
}

int out_func() {
    this_player()->move_player("/u/n/nightmask/workroom.c");
    return 1;
}

int gossip() {
    say (TPN+" tried to use gossip.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int code() {
    say (TPN+" tried to use code.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int question() {
    say (TPN+" tried to use question.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int mudlib() {
    say (TPN+" tried to use mudlib.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int gwiz() {
    say (TPN+" tried to use gwiz.\n");
    write ("You may not use chat-lines in here.\n");
    return 1;
}

int dinosaur() {
    say (TPN+" tried to use dinosaur.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int doc() {
    say (TPN+" tried to use doc.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int ed() {
    say (TPN+" tried to edit a file.\n");
    write ("You may not edit here.\n");
    return 1;
}

int dest() {
    say (TPN+" tried to dest.\n");
    write ("You may not dest in the jail.\n");
    return 1;
}

int clone() {
    say (TPN+" tried to clone somthing.\n");
    write ("You may not clone anything to the jail.\n");
    return 1;
}

int move() {
    say (TPN+" tried to move.\n");
    write ("You may not move from here.\n");
    return 1;
}

int more() {
    say (TPN+" tried to more.\n");
    write ("You may not more in the jail.\n");
    return 1;
}

int driver() {
    say (TPN+" tried to use driver.\n");
    write ("You may not use chat-lines here.\n");
    return 1;
}

int who() {
    say (TPN+" tried to who.\n");
    write ("You can't who in the jail.\n");
    return 1;
}

int people() {
    say (TPN+" tried to people.\n");
    write ("Do you really care who's on?\n");
    return 1;
}

int camel() {
    say (TPN+" tried to change dir's.\n");
    write ("You may not change directories in the jail.\n");
    return 1;
}

int foo() {
    say (TPN+" tried to ls.\n");
    write ("You don't have to see what's in your home dir.\n");
    return 1;
}

int trace() {
    say (TPN+" tried to trace.\n");
    write ("You may not trace anything here.\n");
    return 1;
}

int sc() {
    say (TPN+" tried to deep scan.\n");
    write ("You may not scan here.\n");
    return 1;
}

int call() {
    say (TPN+" tried to call somthing.\n");
    write ("You are not allowed a phone call.\n");
    return 1;
}

int kill() {
    say (TPN+" tried to kill someone.\n");
    write ("Kill?? from behind bars?\n");
    write ("Two HUGE guards enter and kick your ass.\n");
    return 1;
}
