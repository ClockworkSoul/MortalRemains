/*
** I decided to give coding a pub a try. How fun. =)
** Credit to Heron@Shadow's Edge, from whom I took the purchasing format
** for the pub. (Though not the code itself, that's mine. :)
** I also included some stuff from /std/living/healing.c,
** because that file needed to be modified for use in the pub.
** Balkalarre, Wednesday, July 10th, 1996.
// (09-21-96) Chronos fixed a bug.. Drinking alcohol when they were in
//            hangover land would make it so they never got their hit
//            points back, which made healing difficult, considering
//            it's a -4hp every time you hit hangover land. :o
//            Chronos also capped spell point healing.. max sp.
*/


inherit ROOM;

#define ITEM_SHORT                      0
#define ITEM_USER_MSG                   1
#define ITEM_HP_HEAL                    2
#define ITEM_SP_HEAL                    3
#define ITEM_STRENGTH                   4
#define ITEM_COST                       5
#define ITEM_FOOD_FLAG			6
#define ITEM_SIZE                       7
#define FOOD_SIZE_MULTIPLIER		2


private static nomask mapping items;
private static nomask string *itemize;
private static nomask int dSize;
private static nomask string sorryBud;

int eat_foodstuffs (int Lead);
int drink_alcohol (int Proof);

void set_items (mapping Map)
{
    if (mapp(Map))
    {
	dSize = sizeof(itemize = keys(Map));
	items = Map;
    }
}

mapping query_items() { return items; }

string set_non_item_msg (string str)
{
    if (stringp(str))
	return sorryBud = wrap(str);
}

string query_non_item_msg() { return sorryBud; }

int List()
{
    int i;
    mixed ret;
    if (!dSize)
	return (int)
	notify_fail(
	  sprintf(
	    "%s has nothing for sale.\n",
	    query("short")));
    ret = sprintf(
      "\n    %30-s %15-s %15-s\n"
      "    %30-s %15-s %15-s\n",
 "Item", "Item Type", "Price",
 "----", "---------", "-----"
    );
    for (i = 0; i < dSize; i++)
    {
	if (sizeof(items[itemize[i]]) != ITEM_SIZE ||
	  !stringp(items[itemize[i]][ITEM_SHORT]))
	    continue;
	ret += sprintf(
	  "%3-s %30-s %15-s %15-d\n",
	  (string) (i + 1) + ".",
	  items[itemize[i]][ITEM_SHORT],
	  (items[itemize[i]][ITEM_FOOD_FLAG] >= 1) ?
	  "Food" :    
	  ((intp(items[itemize[i]][ITEM_STRENGTH]) &&
	      items[itemize[i]][ITEM_STRENGTH] > 0) ?
 "Alcoholic" : "Drink"),
	  (intp(items[itemize[i]][ITEM_COST]) ?
	    items[itemize[i]][ITEM_COST] : 0));
    }
    tell_object(this_player(), ret);
    return 1;
}

int Buy (string arg)
{
    int i, j;
    if (this_player()->query_ghost())
	return (int)
	notify_fail(
	  "You could try, but I doubt anything would stay inside.\n"
	);
    if (!dSize)
	return (int)
	notify_fail(
	  sprintf(
	    "%s has nothing for sale.\n",
	    query("short"))
	);
    if (j = atoi(arg))
    {
	j--;
	if (j < 0 || j >= dSize)
	    return (int)
	    notify_fail(sorryBud);
    }
    else
    {
	j = -1;
	for (i = 0; i < dSize; i++)
	{
	    if (sizeof(items[itemize[i]]) != ITEM_SIZE)
		continue;
	    if (itemize[i] == arg ||
	      lower_case(
		items[itemize[i]][ITEM_SHORT]) == arg)
	    {
		j = i;
		break;
	    }
	}
	if (j == -1 ||
	  (!stringp(items[itemize[j]][ITEM_SHORT])))
	    return (int)
	    notify_fail(sorryBud);
    }
    if (!this_player()->debit(items[itemize[j]][ITEM_COST]))
	return (int)
	notify_fail(
	  wrap(
	    sprintf(
	      "You don't have %d coins to purchase %s %s.",
	      items[itemize[j]][ITEM_COST],
	      article(items[itemize[j]][ITEM_SHORT]),
	      items[itemize[j]][ITEM_SHORT])));
    if (intp(items[itemize[j]][ITEM_FOOD_FLAG]) &&
      items[itemize[j]][ITEM_FOOD_FLAG])
    {
	if (!eat_foodstuffs(
	    items[itemize[j]][ITEM_STRENGTH]))
	{
	    this_player()->credit(
	      items[itemize[j]][ITEM_COST]);
	    return 1;
	}
    }
    else
    if (intp(items[itemize[j]][ITEM_STRENGTH]) &&
      items[itemize[j]][ITEM_STRENGTH])
    { 
	if (!drink_alcohol(
	    items[itemize[j]][ITEM_STRENGTH]))
	{
	    this_player()->credit(
	      items[itemize[j]][ITEM_COST]);
	    return 1;
	}
    }
    write(
      wrap(
	sprintf(
	  "You pay %d coins for %s %s.",
	  items[itemize[j]][ITEM_COST],
	  article(items[itemize[j]][ITEM_SHORT]),
	  items[itemize[j]][ITEM_SHORT])));
    if (intp(items[itemize[j]][ITEM_FOOD_FLAG]) &&
      items[itemize[j]][ITEM_FOOD_FLAG] == 2)
	call_out("Finish_Eating", 
	  (items[itemize[j]][ITEM_STRENGTH] *
	    FOOD_SIZE_MULTIPLIER), 
	  items[itemize[j]][ITEM_USER_MSG],
	  items[itemize[j]][ITEM_HP_HEAL],
	  items[itemize[j]][ITEM_SP_HEAL]);
    else
    {
	write(
	  wrap(
	    items[itemize[j]][ITEM_USER_MSG]));
	this_player()->receive_healing(
	  items[itemize[j]][ITEM_HP_HEAL]);
	this_player()->add("spell_points",
	  items[itemize[j]][ITEM_SP_HEAL]);
    if ((int)TP->query("spell_points")>(int)TP->query("max_sp")) 
      TP->set("spell_points", (int)TP->query("max_sp")) ;
    } 
    return 1;
}

void create()
{
    ::create();
    items = ([ ]);
    sorryBud =
    wrap(
      "The pub does not seem to sell that."
    );
    set("short", "The pub");
}

void init()
{
    add_action("List", "list");
    add_action("Buy", "buy");
    add_action("Buy", "order");
}

void Finish_Eating (string Message, int hpHeal, int spHeal)
{
    write(
      wrap(
	Message));
    this_player()->add("spell_points",
      spHeal);
   TP->receive_healing(hpHeal) ;
}

int drink_alcohol (int Proof)
{
    int Vitals, Drunk;
    Drunk = this_player()->query("drunk");
/*
    Vitals = ((this_player()->query("stat/constitution")
	<= 1) ? 2 : this_player()->query("stat/constitution") 
      + (this_player()->query("stat/spirit") <= 1) ? 2 :
    this_player()->query("stat/spirit")) / 2 ;
*/
  Vitals = ((int)TP->query("stat/constitution") +
            (int)TP->query("stat/spirit")) / 2 ;
  if (Vitals<4) Vitals = 4 ;
  if ((int)TP->query("soaked")>Vitals*2) {
     write("You couldn't possibly drink more liquids right now.\n") ;
    return 0 ;
  }
   if (Drunk + Proof > Vitals ) 
    {
	write("You fail to reach the drink with your mouth.\n");
	return 0;
    }
   if (Proof>0 && Proof > Vitals) {
	write("This stuff is just too strong for you!\n");
	return 0;
    }
    if (Drunk<0) {
      write("Your headache seems to fade away.\n");
      TP->add("hit_points", -1 * Drunk) ;
    }
    Drunk += Proof;
    if (Drunk == 0)
	write("You are completely sober.\n");
    if (Drunk < 0)
    {
	write("You have a headache.\n");
	Drunk = 0;
    }
    this_player()->set("drunk", Drunk);
   TP->add("soaked", 1 ) ;
    return 1;
}

int eat_foodstuffs (int Lead)
{
    int Vitals, Stuffed;
    Stuffed = this_player()->query("stuffed");
/*
    Vitals = ((this_player()->query("stat/constitution")
	<= 1) ? 2 : this_player()->query("stat/constitution") 
      + (this_player()->query("stat/spirit") <= 1) ? 2 :
      this_player()->query("stat/spirit")) / 2;
*/
   Vitals = (int)TP->query("stat/constitution") + 
            (int)TP->query("stat/spirit") ;
   Vitals = Vitals / 2 ;
   if (Vitals<4) Vitals = 4 ;
    if (Stuffed + Lead > Vitals) {
	write("You couldn't eat another bite!\n");
	return 0;
    }
    if (Lead > Vitals)
    {
	write("This looks way too big for you to eat.\n");
	return 0;
    }
    Stuffed += Lead;
    if (Stuffed < 1)
    {
	write("Your stomach makes a rumbling sound.\n");
	Stuffed = 0;
    }
    this_player()->set("stuffed", Stuffed);
    return 1;
}
