#include "main.h"

inherit MAIN+"/palacestd.c";

object workroom = find_object_or_load("/u/c/cyanide/workroom.c");

void create() {
    ::create();
    set("short", "Cyanide's Waiting Room");
    set("long", @EndText
You have find yourself in a warmly decorated waiting room tastefully
colored in medium grained woods and light earthtones. There is a comfy
couch against the west wall, next to which is a small table covered with
magazines. The door to the east is monitored by a very suspicious-looking
secretary.
EndText
    );
    set("item_desc", ([
      "secretary" : "She meets your gaze sternly, and you look away.\n",
      "magazines" : wrap("Among the numerous 4-year-old Readers' "+
	"Digests and Mudding Todays, you see an old, worn copy of "+
	"\"Evil Geniuses For Dummies\". How odd..."),
    ]) );
    set("exits", ([
      "east" : "/u/c/cyanide/workroom.c",
      "west" : MAIN+"/spire2.c",
    ]) );
    set("exit_msg", ([
      "east" : "$N enters Cyanide's office to the east.\n",
      "west" : "$N leaves the room to the west.\n",
    ]) );
    set("pre_exit_func", ([
      "east" : "office_func",
    ]) );

}

void init() {
    add_action("guest", "guest");
}

int guest() {
    write("Workroom functions have been disabled for this room.\n");
    return 1;
}

int receive_object (object ob) {
    call_out("secy_look", 1, ob);
    return 1;
}

int office_func() {
    int shields;
    workroom = find_object_or_load("/u/c/cyanide/workroom.c");

    shields = workroom->query_shields();

    if (TPN!="Cyanide") {
	if (shields==2 && !workroom->query_invited(TPN) ||
	  (shields>=0 && workroom->query_banned(TPN))) {
	    message("message", "The secretary blocks your way.\n", TP);
	    message("message", "The secretary blocks "+TPN+"'s way into "+
	      "the office.\n", all_inventory(TO), TP);
	    return 1;
	}
    }

    return 0;
}

void secy_look(object ob) {
    string tmpstr, obname;

    workroom = find_object_or_load("/u/c/cyanide/workroom.c");
    obname = ob->query("cap_name");

    if (userp(ob)) {
	if (obname == "Cyanide") {
	    tmpstr = "Welcome back, Mr. Cyanide!";
	} else {
	    if (workroom->query_invited(ob->query("name"))) {
		tmpstr = "Hello, "+obname+". Cyanide has been expecting you. Go "+
		"right in.";
	    } else {
		if (workroom->query_banned(ob->query("name"))) {
		    tmpstr = "Cyanide has requested you leave before he is "+
		    "forced to call security.";
		} else {
		    tmpstr = "Please take a seat. I will see if Cyanide is in.";
		}
	    }
	}
    } else {
	tmpstr = "Who let you in here?";
    }

    message("say", iwrap("The secretary says [to "+obname+"] "+tmpstr),
      all_inventory(TO), ob);
    message("say", iwrap("The secretary says [to you]: "+tmpstr),
      ob);
}

/* EOF */
