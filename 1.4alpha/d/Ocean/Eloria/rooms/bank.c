/*
** File:  /u/n/nemar/water/city/rooms/bank.c
** Author:  Lord Nemar of the Shadoweir
*/
#include <money.h>
#include <move.h>
#include "eloria.h"

inherit "/std/bank";

void create()
{
    ::create();
    set("shrot", "1st Bank of Eloria");
    set("long",@EndText
Welcome to the 1st Bank of Eloria.  Here you may open an account
and store your extra credits, just in case.  There is a small sign on the
cashiers counter.
EndText
    );
    set("light", 1);
    set("exits", ([
      "south" : eloria+"central1b.c",
    ]) );
    set("item_desc", ([
      "sign" : sign(),
    ]) );
}
