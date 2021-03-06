/*
// autoload.c: adapted from 2.4.5 code by Truilkan@TMI
// inherited by /std/user.c
//
// This version stores the filenames to be autoloaded in an array
// named auto_load.
// (2-10-92) A potential problem caused by objects using the old
// style query_auto_load() { return 1; } fixed by Buddha
*/

#include "/u/c/cyanide/debug.h"
#include <uid.h>

private mixed *auto_load;

/*
// load_autoload_obj: clones each object in the auto_load array into
// the player's inventory at login time.  Sends any stored data to
// the init_arg method
*/

void load_autoload_obj()
{
    string file;
    mixed item, argument;
    object ob;
    int j, limit;

    DEBUG("    Loading autoload in "+TO->query("cap_name")+"\n");
    limit = (auto_load) ? sizeof(auto_load) : 0;
    for (j = 0; j < limit; j++) {
	item = auto_load[j];
	argument = 0;
	if (stringp(item))
	    sscanf(item, "%s:%s", file, argument);
	else if (pointerp(item) && (sizeof(item) == 2)) {
	    file = (string)item[0];
	    argument = (mixed *)item[1];
	}
	else
	    continue;
	if (file) {
	    if (file_size(file + ".c") <= 0 ||
	      catch(call_other(file, "?")) ||
	      catch(ob=clone_object(file))) {
		ob = 0;
		write("Unable to autoload: " + file + "\n");
	    }
	    if (ob) {
		if (argument)
		    call_other(ob, "init_arg", argument);
		ob->move(this_object());
	    }
	}
    }
}

/*
   compute_autoload_array: this method is called by ./save.c prior to each
   time the player is saved.
*/

void compute_autoload_array()
{
    object *inv, ob;
    mixed item;
    int j, ok;
    string auto_str;

    auto_load = ({});
    inv = all_inventory(this_object());
    for (j = 0; j < sizeof(inv); j++) {
	ob = inv[j];
	auto_str = "";
	item = (mixed)call_other(ob, "query_auto_load");
	ok = 0;
	if (pointerp(item)) {
	    if ((sizeof(item) == 2) && stringp(item[0]))
		ok = 1;
	}
	else if (stringp(item))
	    ok = 1;
	if (!ok && item) {
	    sscanf(file_name(ob), "%s#%*d", auto_str, ok);
	    auto_str += ":";
	}
	if (auto_str)
	    auto_load += ({ auto_str });
    }
}

/* destroy_autoload_obj: this is called at logout time */

void destroy_autoload_obj()
{
    object *inv;
    int j;

    inv = all_inventory(this_object());
    for (j = 0; j < sizeof(inv); j++)
	if (inv[j]->query_auto_load())
	    inv[j]->remove();
}

mixed *query_autoload_array() {
    if(!adminp(geteuid(previous_object())) &&
      geteuid(previous_object()) != ROOT_UID)  return 0;

    return auto_load;  }

