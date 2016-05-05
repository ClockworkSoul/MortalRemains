/*
** This is the last room in the spidey caves
** Coded by Tyran on 7/18/2000 (with help from Nsd)
*/

#include <mudlib.h>
#include <config.h>
#include "spider.h"
int spid_flag=0;
int sword_flag=0;

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "tyran");
    set("short", "Inside the spider caves");
    set( "long", @EndText
This is a room in the spider caves.  There are webs all over
the room, covering the grey walls.
EndText
    );
    set( "exits", ([
      "east" : SPD_ROOM+"spcave19.c",
    ]) );
    spid_flag = 0;
    sword_flag = 0;
    set("item_desc", ([
      "walls" : "These walls are covered in spiderwebs.\n",
      "wall" : "These walls are covered in spiderwebs.\n",
      "floor" : "The grey floor can just barely be seen through\n"+
      "the mass of spiderwebs.\n",
      "ceiling" : "The grey rocky ceiling can not be seen through the webs.\n",
      "webs" : "These webs cover everything  There's something wrapped in\n"+
      "spidersilk on the webs.  It looks suspiciously like a humanoid body\n",
      "spiderwebs" : "These webs cover everything  There's something wrapped in\n"+
      "spidersilk on the webs.  It looks suspiciously like a humanoid body\n",
      "body" : "This is what appears to be a six foot long humanoid body\n"+
      "wrapped in spidersilk.  The body is wriggiling, and you think\n"+
      "that if you 'cut' the 'spidersilk' you could free this tortured\n"+
      "soul from his captivity.\n",
    ]) );
    set("objects", ([
    ]) );    
    reset();
}

void init() {
    add_action("cut_spidersilk", "cut");
}

int cut_spidersilk() {
    object babyspid;
    object spsword;
    if (!spid_flag) {
        for(int i = 0; i<3; i++) { 

            babyspid = clone_object(SPD_MON+"babywid.c");
                        // Cyanide added this error checking
            if (!babyspid) {
                write("Object isn't locading! Contact Tyran!\n");
                return 1;
            }
            babyspid->move(this_object());
            babyspid->kill_ob(this_player());
        }
        write("As you cut the spidersilk, spiders rush out and attack you.\n");
        say("A bunch of spiders jump over "+TPN+" and bite "+POSS+"!\n");
        spid_flag = 1;
    }
    else 
      if (!sword_flag) {
        write("With the spiders dead, you look into the spidersilk and see\n"+
        "the Spider Sword.\n");
            spsword = clone_object(SPD_OBJ"spsword.c");
            spsword->move(this_object());
        say(TPN+" looks through the corpses of the spiders into the spidersilk.\n");
        sword_flag = 1;
        }
      else
        write("You look into the spidersilk and see nothing.\n.");
        say(TPN+" looks through the corpses of the spiders into the spidersilk.\n");
    return 1;
}
// This is VERY important:
int reset() {
    spid_flag = 0;
    sword_flag = 0;
    return ::reset();
}

/* EOF */