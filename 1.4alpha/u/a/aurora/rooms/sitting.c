//  Room created using generator 
//  Created Wed Feb 15 00:25:31 1995 by aurora

inherit "std/room";

  object ob;

void create()   {
  ::create();
  set_short("Aurora's Sitting Room.");
  set_property("indoors",1);
  set_property("light",2);
  set_long(
@TEXT
This is Aurora's sitting room, and entrance to her workroom.  Please feel free to enter here and read the board.  If Aurora isn't online and you would like to leave a message, feel free to post a note and she will try to get back to you as soon as possible.
TEXT
  ); 
  set_exits(([
    "east" : "/d/desert/hotel/corridor8w.c",
     "north" : "/wizards/aurora/workroom.c",
     "west" : "/wizards/aurora/rooms/dunks.c",
  ]));
     ob=new("/std/bboard");
     ob->set_name("board");
     ob->set_id(({"board","machine","bulletin"}));
     ob->set_board_id("Aurora");
ob->set_edit_ok( ({ "aurora" }) );
     ob->set_short("Aurora's Answering Machine");
     ob->set_long("Hi, you have reached Aurora's answering machine"
     ".  She's unable to be here at the moment, but if you would like"
     " to leave a message here, she'll try to get back to you as soon "
     "as possible.  Thanks!\n");
     ob->set_max_posts(100);
     ob->set_location("/wizards/aurora/rooms/sitting.c");
     ob->set_property("no steal",1);
     ob->set_peroperty("no attack",1);
  set_items(([
  ]));
 }
