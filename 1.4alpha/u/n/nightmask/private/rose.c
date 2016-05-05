/*
** File: rose.c
** Purpose: SHows how to code an object with an 'add_action'
** Credits:  Nightmask coded.  Don't know when.
*/

#include <mudlib.h>

inherit OBJECT ;

void create() {
    // Author is the person who coded this. It should be in 
    // every object or room you code.
    set("author", "nightmask");

    //the id makes it able to be examined in more than 1 way
    set ("id", ({ "rose", "flower", "long stemmed rose" }) );

    //the short is what you see in an inventory, or on the ground
    set ("short", "A long stemmed rose");

    //long is what is seen after the player examines it
    //the @EndText makes it a bit easier to code
    set ("long", @EndText
This is a long stemmed rose, It is sweet to the smell.
This is a very special rose tho. if you are in possession of it,
You may smell, and you will find yourself elsewhere.
EndText
    );

    //mass is how much it weighs
    set ("mass", 0);

    //this is how much you would get for it in the shop
    set ("value", 0);

    //the prevents are for those items you don't want passed out.
    set ("prevent_drop", 1);
    set ("prevent_insert", 1);
    set ("prevent_give", 1);
}

//this is a standard object add_action, what it basically does
//is give an extra somthing to the person who has it. In this case
//if you smell the rose, you are transported to my workroom.

void init () {
    add_action ("smell", "smell");
}

//not all actions will have a string str. This part of the code allows
//for more than one argument, smell is a global thing, if a wizard
//say coded a plant that you had to smell, this allows the player
//to also smell plant.

int smell(string str) {
    //a ! means not, what the if(!str) means is, if no string do this
    if (!str) {
	write ("Smell what?\n");
	return 1;
	//there are 2 types of returns, a return 1; will create a loop
	//when the action is executed, it will go back to the begining
	//the other is return 0;
    }
    if (str == "rose") {
	//write is what the object holder sees, a say is what the other people
	//see that are in that room
	write ("You inhale deeply as your head begins to feel light.\n");
	write ("You are no longer where you were.\n");
	say (this_player()->query("cap_name")+" smells a rose and dissappears from sight.\n");
	this_player()->move_player("/u/n/nightmask/workroom.c");
	return 1;
    }
    return 1;
}

/* End of File */
