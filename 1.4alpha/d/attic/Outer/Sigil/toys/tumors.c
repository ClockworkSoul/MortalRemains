// Tumors.c - created by Cyanide as a hobby of sorts
// (12-19-98) Touched up by Chronos.  Added a couple id's and whatnot.

#include <mudlib.h>

#define TOYS "/u/c/cyanide/toys"

#define NAME this_player()->query("cap_name")
#define POSS possessive(this_player()->query("gender"))

int closed, smokes;

inherit OBJECT;

void create() {
    seteuid(getuid());
    smokes = 20;
    closed = 1;
    set ("author", "Cyanide");
    set ("id", ({ "pack", "cigs", "smokes", "butts",  
      "cigarettes", "cancer sticks", "tumors" "tumors lite"}) );
    set ("short", "a pack of cigarettes");
    set ("long", @EndText
A black pack of cigarettes with a prominant white skull on
the front. The words "Tumors Lite" are printed on the pack
in large, bold red lettering.
EndText
    );
}

void init () {
    if (closed==1) {
	set ("short", "a closed pack of cigarettes"); }
    else
    if (smokes==1) {
	set("short","an open pack of cigarettes ("+
	  smokes+" cigarette)"); }
    else
	set ("short", "an open pack of cigarettes ("+
	  smokes+" cigarettes)");
    add_action ("open_func", "open");
    add_action ("close_func", "close");
    add_action ("butts", "pull");
}

int open_func (string ophen) {
    if (ophen != "pack" ) {
	return 0; }
    if (closed == 0) {
	write ("Your pack is already open.\n");
	return 1;  }

    write ("You flip open your pack of Tumors Lite.\n");
    write ("Now you can \"pull\" a butt from the pack.\n");
    say (NAME+" flips open "+POSS+" pack of cigarettes.\n");
    closed = 0;
    if (smokes == 1) {
	set ("short", "an open pack of cigarettes ("+
	  smokes+" cigarette)"); }
    else {
	if (smokes == 0) {
	    set ("short", "an empty pack of butts"); }
	else {
	    set ("short", "an open pack of cigarettes ("+
	      smokes+" cigarettes)"); }
    }
    return 1;
}

int close_func (string kloze) {
    if (kloze != "pack") {
	return 0; }
    if (closed == 1) {
	write ("Your pack is already closed.\n");
	return 1;  }

    write ("You flip your pack closed.\n");
    say (NAME+" flips "+POSS+" pack of cigarettes closed.\n");
    closed = 1;
    set ("short", "a closed pack of cigarettes");
    return 1;
}

int butts (string str) {
    object pack, butt;
    string str2;

    if (!str) return 0;
    sscanf (str, "%s from %s", str, str2);
    if (str2 != "pack") {
	write ("Pull what from where?\n"); return 1; }
    if (str != "cigarette" && str != "butt") {
	write ("Pull what from where?\n"); return 1; }
    if (closed == 1) {
	write ("The pack is closed.\n");
	return 1; }
    if (smokes == 0) {
	write ("You're all out of butts.\n");
	return 1;  }

    write ("You pull a butt from the pack of Tumors Lite.\n");
    say (NAME+" pulls a cigarette from a pack of Tumors Lite.\n");
    butt=clone_object(TOYS+"/butt.c");
    butt->move(this_player());
    smokes--;
    if (smokes == 1) {
	set ("short", "an open pack of cigarettes ("+
	  smokes+" cigarettes)"); }
    else {

	set ("short", "an open pack of cigarettes ("+
	  smokes+" cigarettes)"); }
    if (smokes == 0) {
	set ("short", "an empty pack of butts");
    }
    return 1;
}

/* EOF */



