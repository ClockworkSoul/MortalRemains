
#include <mudlib.h>
#include <config.h>

inherit ROOM;

void create() {
	::create() ;
set("short", "default faction HQ.");
set ("light", 1) ;
set ("aligns", ([ "Athar" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Godsmen" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Bleakers" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Doomguard" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Dustmen" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Fated" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Guvners" : ({"lawful good", "lawful neutral", "lawful evil" }),
"Free league" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Harmonium" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Mercykillers" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Anarchists" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Signers" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Sensates" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Ciphers" : ({"lawful good", "lawful neutral", "lawful evil", "neutral good",
"true neutral", "neutral evil", "chaotic good", "chaotic neutral", "chaotic evil" }),
"Xaositics" : ({"chaotic good", "chaotic neutral", "chaotic evil" }) ]) );
}




void init(){
add_action("join", "join");
add_action("store", "store");
add_action("retrieve", "retrieve");
add_action("listing", "listing");
}

int join(string str){

int cash;
mapping aligns;
string *align, faction;
object chatob, sponsor;

cash = 10000;
if (str) sponsor = find_player(str);

if (!sponsor || !str){
sponsor = TP;
cash = 100;
}

//these are all the checks to see if you have the requirements.

align = this_object()->query("aligns/"+(this_object()->query("faction")));
if (member_array((this_player()->query_align()), align ) == -1){
	write("You are not of the proper alignment to join us.\n");
	return 1;
	}

if (this_player()->query_class("priest") && (this_object()->query("faction") == "Athar") ){
	write("You are not of the proper class to join us.\n");
	return;
	}

if (this_player()->query_class("thief") && (this_object()->query("faction") == "Guvners") ){
	write("You are not of the proper class to join us.\n");
	return;
	}
if (TP->query("faction")){
write("You already belong to a faction!\n");
return 1;
}

faction = this_object()->query("faction");

TP->set("faction",([ "Faction" : faction, "Rank" : "Namer", "Item1" : "none", "Item2" : "none", "Item3" : "none", "Item4" : "none" ]));

write ("Welcome to the ranks of the "+faction+".\n");

this_object()->do_ability(TP);

sponsor->add("sponsor", 1);

TP->credit(cash);
// put chat clone ob here.
chatob = clone_object("/u/i/ilzarion/fchatob.c");
chatob->move(TP);
return 1;
}

// faction retrieve fn

int retrieve(){
mapping factiondata;
object ob1, ob2, ob3, ob4;
string *stuff;

seteuid(getuid());

factiondata = TP->query("faction");
stuff = values(factiondata);

if (TP->query("faction/Item4") != "none"){
ob4 = clone_object(TP->query("faction/Item4"));
ob4->move(TP);
TP->set("faction/Item4", "none");
}
if (TP->query("faction/Item3") != "none"){
ob3 = clone_object(TP->query("faction/Item3"));
ob3->move(TP);
TP->set("faction/Item3", "none");
}
if (TP->query("faction/Item2") != "none"){
ob2 = clone_object(TP->query("faction/Item2"));
ob2->move(TP);
TP->set("faction/Item2", "none");
}
if (TP->query("faction/Item1") != "none"){
ob1 = clone_object(TP->query("faction/Item1"));
ob1->move(TP);
TP->set("faction/Item1", "none");
}

write ("You get your stuff.\n");
return 1;
}


//storage function

int store(string str){

object item;
string fname;
int rank;

if (!str){
write("Store what??\n");
return 1;
}

item = present(str, TP);

if (!item){
write ("You dont have one of those.\n");
return 1;
}

if (TP->query("faction/Faction") != this_object()->query("faction")){
write("You must belong to this faction before you can store anything!\n");
return 1;
}

if (item->query("prevent_give") || item->query_auto_load() || item->query("prevent_sell") || item->query("prevent_get") || item->query("dest_at_die")){
write ("You cant store that item.\n");
return 1;
}


//ok the item is storeable

fname = base_name(item);

if (TP->query("faction/Rank") == "Namer") rank = 0;
if (TP->query("faction/Rank") == "Factotum") rank = 1;
if (TP->query("faction/Rank") == "Factor") rank = 2;
if (TP->query("faction/Rank") == "Factol") rank = 3;

if (rank > 2 && (TP->query("faction/Item4") == "none")){
TP->set("faction/Item4", fname);
write("You store "+item->query("short")+".\n");
item->remove();
return 1;
}
if (rank > 1 && (TP->query("faction/Item3") == "none")){
TP->set("faction/Item3", fname);
write("You store "+item->query("short")+".\n");
item->remove();
return 1;
}
if (rank > 0 && (TP->query("faction/Item2") == "none")){
TP->set("faction/Item2", fname);
write("You store "+item->query("short")+".\n");
item->remove();
return 1;
}
if (rank > -1 && (TP->query("faction/Item1") == "none")){
TP->set("faction/Item1", fname);
write("You store "+item->query("short")+".\n");
item->remove();
return 1;
}
write("You have stored your maximum number of items already!\n");
return 1;
}



//the list command

int listing(){

object ob1, ob2, ob3, ob4;
int rank;

if (TP->query("faction/Faction") != this_object()->query("faction")){
write("You must belong to this faction before you can store anything!\n");
return 1;
}

if (TP->query("faction/Rank") == "Namer") rank = 0;
if (TP->query("faction/Rank") == "Factotum") rank = 1;
if (TP->query("faction/Rank") == "Factor") rank = 2;
if (TP->query("faction/Rank") == "Factol") rank = 3;

if (TP->query("faction/Item1") != "none"){
	ob1 = clone_object(TP->query("faction/Item1"));
	write ("Item : "+ob1->query("short")+"\n");
	ob1->remove();
}else{
write ("Item : nothing\n");
}

if (rank>0){
if (TP->query("faction/Item2") != "none"){
	ob2 = clone_object(TP->query("faction/Item2"));
	write ("Item 2 : "+ob2->query("short")+"\n");
	ob2->remove();
}else{
write ("Item 2 : nothing\n");
}
}

if (rank>1){
if (TP->query("faction/Item3") != "none"){
	ob3 = clone_object(TP->query("faction/Item3"));
write ("Item 3 : "+ob3->query("short")+"\n");
	ob3->remove();
}else{
write ("Item 3 : nothing\n");
}
}

if (rank>2){
if (TP->query("faction/Item4") != "none"){
	ob4 = clone_object(TP->query("faction/Item4"));
	write ("Item : "+ob4->query("short")+"\n");
		ob4->remove();
}else{
write ("Item : nothing\n");
}
}
return 1;
}
