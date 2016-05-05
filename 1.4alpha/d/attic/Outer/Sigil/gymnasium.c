// Sigil's gymnaisium.
// Originally coded by Ilzarion.
// Lots of chrome by Cyanide, Oce 18 98.

#include <config.h>
#include <mudlib.h>
#include <skills.h>
#include <language.h>
#include "sigil.h"

inherit "/std/profroom.c";

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("short", "The Great Gymnasium of Sigil.") ;
    set("long", wrap("This great hall is dedicated to the "+
	"pursiut of all manners of knowledge. Here you can "+
	"learn anything from the speech of modrons to how "+ 
	"to brew your own beer.\n\nThe commands are: list, "+
	"select <letter>") );
    set( "exits", ([
      "up" : SIGIL+"wproom.c",
      "south" : SIGIL+"mainst5.c",
    ]) );
    set("skills", SK_GENERAL + ([ "Language" : 1 ]) );
    set("min_levels", ([
      "Signature Item" : 20,
    ]) );		
    set("reselectable", ({ "Language", "Signature Item" }) );
}

string skills_function( string skill ) {

    if (skill == "Signature Item")
    {
	call_out("get_signature_item", 1);
	return("You have selected Signature Item.\n");
    }

    if (skill == "Language")
    {
	call_out("get_language", 1);
	return("You have selected Language.\n");
    }

    return "";
}

void get_signature_item() {
    write("What would you like to make your signature item?: ");
    input_to("get_signature_item2", 1);
    return ;
}

void get_signature_item2(string str) {
    object ob;
    int i;

    ob = present(str, TP);
    write("\n");

    if (!ob) 
    {
	write("You don't have that!\n");
	return;
    }

    if (ob->query("prevent_drop") ||
      ob->query("prevent_sig") ||
      ob->query("prevent_get") ||
      ob->query("prevent_sell") ||
      ob->query("unique") ||
      ob->query_auto_load() )
    {
	write("You cannot make that object a signature item!\n");
	return;
    }

    str = base_name(ob);
    write("You select "+(ob->query("short"))+" as your signature item!\n");
    ob->set("short", ((TP->query("cap_name"))+
	"'s "+(ob->query("short"))) );
    ob->set("prevent_sell", 1);
    ob->set("prevent_drop", 1); 
    TP->set("signature_item", str);
    TP->add("nwp_free", -2);
    i = TP->query_skill("Signature Item");
    TP->set_skill("Signature Item", (i+2));

    return 1;
}

int get_language() {
    string str, *langs;
    int i, num;

    langs = get_dir("/adm/daemons/languages/");
    num = sizeof(langs);

    if (!num) {
	write("There are no languages for you to choose at this time.\n");
	return 1;
    }

    write("You may choose from the following languages:\n\n");
    str = "     ";
    for (i=0; i<num; i++) {
	if (i) str += ", ";
	langs[i]=capitalize(replace_string(langs[i], ".c", ""));
	if (TP->query("languages/"+lower_case(langs[i])))
	    str+="*";
	str += langs[i];
	if (langs[i]=="Modron") str+=" (2 slots)";
    }
    write(iwrap(str) + wrap("\nNote: Any entry with a * means you have "+
	"already selected it as a language. You may select a language "+
	"again to become more proficient."));

    write("\nChoose your language: ");  
    input_to("get_language2", 1, langs);
    return 1;
}

void get_language2(string lang, string *langs) {
    int cost = 1, val;
    mapping lang_map;

    if (!lang) {
	write("You must choose a language!\n");
	return ;
    }

    lang = capitalize(lang);
    if (member_array(lang, langs)==-1) {
	write("You cannot choose that language!\n");
	return ;
    }

    if (lang=="Modron") cost = 2;

    // Let's double check the free slots.
    val = TP->query("nwp_free");
    if (val<cost) {
	write("You don't seem to have enough slots for that tongue.\n");
	return ;
    }

    lang_map = TP->query("languages");
    if (!lang_map) lang_map = ([]);

    lang = lower_case(lang);

    val = lang_map[ lang ];
    if (!val) val = 0;

    if (val>=85) {
	write("You cannot become any more skilled in that tongue.\n");
	return ;
    }

    if (!val) val = random(TP->query("base_stat/intelligence"));
    val += LANGUAGE_DEFAULT_SCORE;
    lang_map[lang] = val;

    val = TP->query_skill("Language");
    val += cost;

    TP->add("nwp_free", (cost*-1));
    TP->set_skill("Language", val, "intelligence");
    TP->set("languages", lang_map);

    write("You now know a bit more "+capitalize(lang)+".\n");
    return 1;			
}


/* EOF */
