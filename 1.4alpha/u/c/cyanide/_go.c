// File: /cmds/std/_go.c
// Code to move a player from one room to another.
// This code used to be in the player object, which was wasteful because
// it meant the code was duplicated in each player. By adding the "go" verb
// to the movement command, it is possible to stick the code into a normal
// command, saving mucho RAM. It is wise to alias "n" to "go north", etc,
// for compatibility with people's expectations, and in fact this is done
// in the standard distribution.
// Written by Buddha in October 1992, probably. The lame-o didn't put a
// header on. This header was added by Mobydick on 11-11-92.
//
// 07 Nov 97  Cyanide@Nightfall's Keep added support for following 
//             creatures and support for "no_move", which prevents
//             movement.

#include "/u/c/cyanide/debug.h"
#include <mudlib.h>
#include <daemons.h>

void do_follow( object, string );

inherit DAEMON;

int fail(){
    write("You can't go that way!\n");
    return 1;
}

int cmd_go(string dir) {
    mapping exits, tmp, doors;     
    object env, ob, *obs;
    int i, sz, flag;
    string tstr;

    ob = this_player();
    if(!ob) ob = previous_object();
    env = environment(ob);
    if(!env) { 
	write("You are in the void.  There's no way out!\n");
	return 1;
    }
    if (!userp(TP) && TP->query("summoned")) {
	TP->force_me("headshake");
	return 1;
    }

    exits = env->query("exits");
    if(!mapp(exits) || member_array(dir, keys(exits)) == -1)
    {	
	return fail();
    } else {
	int lflag = 1;
	string fn;
	object to;

	fn = exits[dir];
	if (fn[<2..<1] != ".c") {
	    if (TPN=="Cyanide") write("Appending .c to filename\n");
	    fn += ".c";
	}
	if (TPN=="Cyanide") write("fn = "+fn+"\n");
	if (file_exists(fn)) {
	    to = find_object_or_load( exits[dir] );
	    if (!to) lflag = 0;
	    if (TPN=="Cyanide")
		write("Going to: "+base_name(to)+"\n");
	} else {
	    lflag = 0;
	}

	if (lflag == 0) {
	    write("The mists of creation are still active in that direction.\n");
	    return 1;
	}

	write("** CANNOT FIND TARG **\n");
    }

    if(this_player()->query("no_move") ) {
	write("You cannot even move!");
	return 1;
    }

    // Check to see if there is a door in that exit, and if so, is it closed
    // or locked. If it is, don't permit the move.
    doors = env->query("doors");
    if(doors && doors[dir]) {
	if(doors[dir]["status"] == "closed" ||
	  doors[dir]["status"] == "locked") {
	    notify_fail("The door is closed.\n");
	    return 0;
	}
    }
    // let's see if it's ok to move -- is there a pre-exit function to call?
    // if the preexit function returns 1, then the exit will be prevented!
    // otherwise the preexit function can be void or return 0, and the exit 
    // will occur after it's called.
    //	tmp = env->query("pre_exit_func");
    //	if(tmp && tmp[dir] && call_other(env, tmp[dir])) return 1;
    tmp = env->query("pre_exit_func/"+dir);
    if (tmp && call_other(env, tmp)) return 1;
    // Now we find out if there's a special message to use when they leave.
    // if there is, we'll use it instead of the default.
    //	tmp = env->query("exit_msg");
    //	if(tmp && mapp(tmp) && tmp[dir]) {
    tmp = env->query("exit_msg/"+dir);
    if (tmp) {
	tstr = replace_string(tmp, "$N", (string)ob->query("cap_name"));
	//		ob->move_player(exits[dir], tstr);
    } else {
	tstr = ob->query_mout(dir);
	//		ob->move_player(exits[dir], tstr);
    }

    //  do_follow(TP, dir);

    ob->move_player(exits[dir], tstr);
    // We check for a post-exit function. Note that the player is no longer
    // in the room, and this is also our last chance to do anything before
    // our control of the player is lost. It doesn't matter what the
    // post-exit function returns.
    //	tmp = env->query("post_exit_func");
    //	if(tmp && mapp(tmp) && tmp[dir]) call_other(env, tmp[dir]);
    tmp = env->query("post_exit_func/"+dir);
    if (tmp) call_other(env, tmp);


    // Finally we are finished.
    return 1;
}


// Function: do_follow
// Purpose: This func does all the follow stuff. It was pulled out
//     of the main function so that other stuff, such as 
//     /std/portal.c, can access it.
// Receives: ob = Object being followed.

void do_follow( object ob, string dir ) {
    mapping exits, tmp, doors;     
    object env, *obs;
    int i, sz, flag;
    string tstr;

    if(ob->query("followers")) {
	env = environment(ob);
	obs = (object *)ob->query("followers");
	if (!obs) return;
	sz = sizeof(obs);
	tmp = env->query("exits/"+dir);
	for(i = 0; i < sz; i++) {
	    if(!obs[i]) continue;

	    // At the moment, users cannot be followers. It would conflict
	    // with the partyd. When that conflict is resolved, this
	    // restriction can be lifted.
	    if (userp(obs[i])) continue;
	    if(environment(obs[i]) != env) {
		tell_object(obs[i], "Your leader moved without you.\n");
		continue;
	    }
	    tstr = obs[i]->query_mout(dir);
	    //			obs[i]->move_player(exits[dir], tstr);
	    if (!obs[i]->query("no_move"))
		obs[i]->move_player(tmp, tstr);
	    flag = 1;
	}
	obs = filter_array(obs, "filter_following", this_object(), ob);
	ob->set("followers", obs);
    }
    return;
}


int filter_following(object ob, object player) {
    int flag = 0;

    if (!ob || ob==0) return 0;

    if (environment(player) == environment(ob)) flag = 1;
    if (living(ob)) flag = 1;
    return flag;
}


string help() {
    return(@HELP
Syntax: go <direction>

The go command will move you in the direction
specified, ie: "go west" will move you through
the room's west exit. You can also type "west"
and that will work. For the standard directions,
"w" or other one-letter abbreviations will also
work.

See also: exits, glance
HELP
    );
}

