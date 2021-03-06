/*
** File: /std/shop.c
** Purpose: Basic inheritable shop code.
** Credits:
**   09 Jul 97  Cyanide began the file - but had problems,
**   08 Sep 97  Cyanide overhauled the file to have the room use a 
**              storage container...
**   16 Sep 97  Cyanide fixed the problem with runaway shelves with
**              '0' as their native shop...
**              On the same day, Cyanide also fixed a buggy "appraise".
**  26 sept 97  Ilzarion made it so the shop dont reset
**   25 Nov 97  Cyanide fixed appraise (again) and tweaked get_val().
**              Also, if the shelf can't hold the thing sold, it just gets
**              removed.
**   27 Jan 98  Cyanide added set_start_items().
**   30 Jan 98  Ilz made it so prevent_drop also prevent_sells
**   11 Feb 98  Cyanide added ONE_SHELF ability and "flux".
*/

#include <mudlib.h>
#include <config.h>
#include <move.h>


// The flux is a random value that beocme the random 
// in value of items.  It represents inflation and local
// supply/demand.  It varies at each reboot, and can go 
// from -FLUX to +FLUX.
#define FLUX 0
#define SHOP_SHELF "/std/shop/shelf.c"

// This is the max number of instances of a specific 
// item allowed to exist in a shelf/shop.
#define MAX_SHOP_NUMBER 3

// When ONE_SHELF is set, a common shelf is used by all
// the shops.
#define ONE_SHELF 1

inherit ROOM;

string *num_names = ({ "zeroth", "first", "second", "third", "fourth",
"fifth", "sixth", "seventh", "eighth", "ninth", "tenth" });
object shelf=0;

// Prototypes -
object find_shelf();
int get_val (int, int, string);
int sell_func(object, object);
int s_appraise(string);
int s_buy(string);
int s_list(string);
int s_sell(string);
void set_start_items(mapping);

int flux;

void create() {
    shelf = 0;
    seteuid(getuid());
    ::create();

    flux = random(FLUX * 2) - FLUX;

    set("short", "A generic shop");
    set("long", "Ye olde generic shoppe.\n");
    shelf = find_shelf();

    // It's better if we don't actually put the shelf IN the room. It's
    // safer for the shelf...
    // shelf->move( this_object() );
}

void init() {
    add_action("s_list", "list");
    add_action("s_sell", "sell");
    add_action("s_buy", "buy");
    add_action("s_appraise", "appraise");
}

// Ilzrion puts in the no reset thing.
void reset() {
    return 0;
}

// This function finds the shop's respective shelf - and assigns it one
// if it has none.

object find_shelf() {
    object *obs, shelf;
    int i, sizeobs, flag = 0;
    string tmp, name;

    obs = children(SHOP_SHELF);
    sizeobs = sizeof(obs);

    name = file_name(this_object());
    sscanf(name, "%s#%d", name, i);
    if (!name || name=="/std/shop") return 0;

    for (i=0;i<sizeobs;i++) { 

#ifndef ONE_SHELF
	tmp = (string)obs[i]->query("native_shop");
	if (tmp==name) {
	    shelf = obs[i];
	    flag=1;
	}
#else
	if (obs[i]->query("native_shop")) {
	    shelf = obs[i];
	    flag = 1;
	    i = sizeobs;  // I know - it's bad code...
	}               // So kill me.  -Cy.
#endif
    }

    if (!flag) {
	shelf = clone_object(SHOP_SHELF);
	shelf->set("native_shop", name);
    }

    return shelf;
}


int s_appraise(string item) {
    object *inventory, ob;
    int num=1, counter, i;
    string *names;

    if (!item) {
	write("Appraise what?\n");
	return 1;
    }

    if (item=="all") {
	write("One item at a time, please!\n");
	return 1;
    }

    inventory = all_inventory(this_player());

    /* Support for "appraise sword 2" */
    sscanf(item, "%s %d", item, num);

    if (!num) num = 1;
    if (num < 1) {
	write("Only philosophers can stipulate"+
	  " as to the nature of negative quantity.\n");
	return 1;
    }

    if (!present(item, this_player())) {
	write("You have no "+item+" to appraise!\n");
	return 1;
    }

    counter = 1;
    for (i=0; i<sizeof(inventory)&&counter<=num; i++) {
	names = (string *)inventory[i]->query("id");
	if (member_array(item,names)!=-1) {
	    if (counter=num) ob = inventory[i];
	    counter++;
	}
    }

    if (ob->query("prevent_sell") || ob->query_auto_load()) {
	write("You cannot sell that.\n");
	return 1;
    }

    num = (int)TP->query("stat/charisma");
    i = (int)ob->query("value");            //Reusing these - Sorry.
    if (!i) i=0;
    i = get_val(i, num, "SELL");

    if (!i)
	write("The shop would never buy such a worthless item!\n");
    else
	write("The shop will give you "+i+" credits for "+
	  ob->query("short")+".\n");
    return 1;
}


int s_buy(string item) {
    string tmp, pathname, *tmp_list;
    object *inventory;
    int num=1, i=-1, count, cha, val;

    if (!item) {
	write("Buy what?\n");
	return 1;
    }

    if ((item=="all") || (sscanf(item, "all %s", item, tmp)==2)) {
	write("One item at a time, please!\n");
	return 1;
    }

    shelf = find_shelf();
    inventory = all_inventory(shelf);

    /* Support for "buy sword 2" */
    sscanf(item, "%s %d", item, num);

    if (num < 1) {
	write("Only philosophers can stipulate"+
	  " as to the nature of negative quantity.\n");
	return 1;
    }

    if (!present(item, shelf)) {
	write("Sorry, the shop has no "+item+"s in stock.\n");
	return 1;
    }

    i = 0;
    count = 0;
    tmp_list = ({});

    while (i<sizeof(inventory) && (count<num)) {

	cha = (int)this_player()->query("stat/charisma");

	if (inventory[i]->id(item)) {
	    pathname = file_name(inventory[i]);
	    sscanf(pathname, "%s#%d", pathname, val);
	    if (member_array(pathname, tmp_list) == -1){
		tmp_list += ({ pathname });
		count++;
	    }
	}

	if ((count==num) && inventory[i]->id(item))  {
	    val = (int)inventory[i]->query("value");
	    val = get_val(val, cha, "BUY");
	    if (!this_player()->debit(val)) {
		write("You do not have enough credits!\n");
		return 1;
	    } else {
		write(wrap("You purchase "+inventory[i]->query("short")+
		    " for "+val+" credits."));
		inventory[i]->move(TP);
		return 1;
	    }
	}
	i++;

    }

    if (num>1) 
	write("There is no "+item+" "+num+" for you to buy.\n");
    else
	write("There is no "+item+" for you to buy.\n");

    return 1;
}

int s_sell (string str) {
    mapping credits;
    object *inv, ob, env;
    int res, amount, capac, i, money, sold;
    string short, *types, type, word, tmp;

    if (!str) {
	write("Sell what?\n");
	return 1;
    }
    if (!(env = environment(this_player()))) {
	notify_fail("You can't sell anything in the void!\n");
	return 0;
    }

    /* Check for "sell all" */
    if(str == "all") {
	inv = all_inventory(this_player());
	if(sizeof(inv) < 1) {
	    notify_fail("You are not carrying anything.\n");
	    return 0;
	}
	for(i = 0; i < sizeof(inv); i++) {
	    if(!inv[i] || inv[i]->query("prevent_sell") || inv[i]->query("prevent_drop") )  continue;
	    if(inv[i])
		short = (string)inv[i]->query("short");
	    if(!short) continue;
	    res = sell_func(inv[i], TP);
	    if(res != 1) continue;
	    say(TPN+" sells "+short+".\n");
	    sold++;
	}
	if(sold) {
	    write("You sell your entire inventory.\n");
	    return 1;
	} else
	    notify_fail("You are not carrying anything you wish to part with.\n");
	return 0;
    } 

    if(str == "all unused") {
	inv = all_inventory(this_player());
	if(sizeof(inv) < 1) {
	    notify_fail("You are not carrying anything.\n");
	    return 0;
	}
	for(i = 0; i < sizeof(inv); i++) {
	    if(!inv[i] || inv[i]->query("prevent_sell") || inv[i]->query("prevent_drop"))  continue;
	    if(inv[i]->query("wielded")) continue;
	    if(inv[i]->query("equipped")) continue;
	    if(inv[i])
		short = (string)inv[i]->query("short");
	    if(!short) continue;
	    res = sell_func(inv[i], TP);
	    if(res != 1) continue;
	    say(TPN+" sells "+short+".\n");
	    sold++;
	}
	if(sold) {
	    write("You sell your unused inventory.\n");
	    return 1;
	} else
	    notify_fail("You are not carrying anything you wish to part with.\n");
	return 0;
    } 

    if (sscanf(str,"all %s", type) == 1) {
	if (environment(TP)) {
	    inv = all_inventory(TP);
	    inv = filter_array(inv,"filter_short");
	    inv = filter_array(inv, "filter_sellable");
	}
	if (sizeof(inv)<=0) {
	    write("There is nothing of that type to sell.\n");
	    return 1;
	}
	money = 0;    // Using as a counter...
	for (i=(sizeof(inv)-1);i>=0;i--) {
	    if (!inv[i]->id(type)) continue;
	    if (inv[i]->query("prevent_sell") || inv[i]->query("prevent_drop")) continue;
	    short = inv[i]->query("short");
	    if (!short) continue;
	    res = sell_func(inv[i], TP);
	    if (res==1) {
		/*
			    say(TPN+" sells "+short+".\n");
		*/
		money++;
	    }
	}   
	if (!money)
	    write("There's nothing of that type to sell.\n");
	else
	    write(money+" items sold.\n");
	return 1;
    }

    /* Check for format "sell sword 3"*/
    if (sscanf(str,"%s %d", str, amount) == 2) {
	if (amount < 1) {
	    write("Only philosophers can stipulate"+
	      " as to the nature of negative quantity.\n");
	    return 1;
	}
	inv = all_inventory(this_player());
	res = 0; i = 0;    // Initializing variables...
	while ((res!=amount)&&(sizeof(inv)>0)&&(i<sizeof(inv))) {
	    ob = inv[i];
	    if (member_array(str, (string)ob->query("id")) != -1 )
		res++;
	    i++;
	}
	if ((res==0) || (i<amount)) {
	    if ((amount<=10) && (amount>=0))
		write("There is no "+num_names[amount]+" "+
		  str+" in your inventory.\n");
	    else 
		write("There is no "+amount+"th "+str+
		  " in your inventory.\n");
	    return 1;
	}
    } else {
	ob = present(str, this_player());
    }

    if(!ob) {
	notify_fail("You don't have that on you.\n");
	return 0;
    }

    if(ob->query("prevent_sell") || ob->query("prevent_drop")) {
	notify_fail("You can't sell that object.\n");
	return 0;
    }

    short = (string)ob->query("short");
    res = sell_func(ob, TP);
    if(res != 1) {
	notify_fail("You can't sell that.\n");
	return 0;
    }
    if(!short) short = "something";
    write("You sell "+short+".\n");
    say(TPN+" sells "+short+".\n");
    return 1;
}

static int filter_short(object ob) {return (ob->query("short")!=0);}

static int filter_sellable(object ob) {
    return !(ob->query("prevent_sell") || ob->query("prevent_drop")); 
} 


int sell_func (object ob, object player) {
    object *contents = ({});
    string pathname, tmp_name;
    int pos, val, cha;

    if (!ob) {
	write("No ob!\n");
	return 0;
    }

    if (!shelf) shelf = find_shelf();
    if (!shelf) {
	write("The storeroom seems to be locked!\nTry again later.\n");
	return 1;
    }

    if (ob->query("prevent_sell") || ob->query("prevent_drop")) return 0;
    if (!ob->query("short")) return 0;
    if (ob->query("keep")) return 0;

    if (!ob->query("value") || (ob->query("value")==0)) {
	write("That item is worthless.\n");
	return 1;
    }

    pathname = file_name(ob);
    sscanf(pathname, "%s#%d", pathname, pos);

    contents = all_inventory(shelf);
    pos = 0;

    if (sizeof(contents))
	for (val=sizeof(contents)-1;val>=0;val--) {
	    tmp_name = base_name(contents[val]);
	    if (tmp_name==pathname)
		pos++;
	}
    val = (int)ob->query("value");

    if (!val || val<1) val = 0;
    cha = player->query("stat/charisma");
    val = get_val(val, cha, "SELL");
    if (val<1) val = 1;
    if (val>50000){ 
	val = 50000;
	tell_object(player,"The shop doesn't have all that cash.\n");
    }

    player->credit(val);
    tell_object(player, sprintf("%-40s   :   %-10d\n", 
	capitalize(ob->query("short")), val));

    /*
      tell_object(player, wrap(capitalize(ob->query("short"))+": You sell "+
	ob->query("short")+" for "+val+" credits.\n"));
    */

    val = 0;   // If val is 0, the item is NOT dested.

    if (ob->query("dest_at_sell")) val = 1;
    if (pos >= MAX_SHOP_NUMBER) val = 1;

    if (ob->move(shelf) != MOVE_OK) {
	ob->move(VOID);
	val = 1;
    }

    if (val) ob->remove();

    return 1;
}

int s_list(string str) {
    string *pathnames=({}), tmp_name, name;
    int i, char, val;
    object *obs=({});

    char = (int)TP->query("stat/charisma");
    obs = all_inventory(find_shelf());

    if (sizeof(obs) < 1) {
	write("The shop is empty!\n");
	return 1;
    }

    write(sprintf("%-25s   :   %-40s\n", "Items", "Costs"));
    if (!str) {
	for(i=0;i<sizeof(obs);i++) {
	    name = obs[i]->query("short");
	    if (name) name = capitalize(name);
	    tmp_name =  file_name(obs[i]);
	    sscanf(tmp_name, "%s#%d", tmp_name, val);
	    if (member_array(tmp_name, pathnames)==-1) {
		val = obs[i]->query("value");
		val = get_val(val, char, "BUY");
		pathnames += ({ tmp_name });
		write(sprintf("%-25s   :   %-40d\n", name, val));
	    } 
	}
    } else {
	for(i=0;i<sizeof(obs);i++) {
	    string *ids = (string *)obs[i]->query("id");
	    if (member_array(str, ids)!=-1) {
		name = obs[i]->query("short");
		if (name) name = capitalize(name);
		tmp_name =  file_name(obs[i]);
		sscanf(tmp_name, "%s#%d", tmp_name, val);
		if (member_array(tmp_name, pathnames)==-1) {
		    val = obs[i]->query("value");
		    val = get_val(val, char, "BUY");
		    pathnames += ({ tmp_name });
		    write(sprintf("%-25s   :   %-40d\n", name, val));
		}
	    } 
	}
    }
    return 1;
}  //end list_shop()                             


int get_val (int val, int char, string bysell) {
    if (char>25) char = 25;
    if (char<3) char = 3;

    if (bysell=="SELL")
	char = 50+char;
    else
	char = 151+char;

    char += flux;

    val = (val*char)/100;
    return val;
}

// This function adds starting items to a shop.
// Cyanide added on 27 Jan 98

void set_start_items( mapping items ) {
    int x, y, *num_items;
    string *item_paths;
    object tmp_shelf = find_shelf(), it;

    item_paths = keys(items);
    num_items = values(items);

    for (x = 0; x < sizeof(item_paths); x++) {
	if (!file_exists(item_paths[x])) continue;

	for (y=0; y<num_items[x]; y++) {
	    it = clone_object(item_paths[x]);
	    it->move(tmp_shelf);
	}
    }

    return;
}

/* EOF */
