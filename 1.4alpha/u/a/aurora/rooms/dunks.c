#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
  ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("pking",0);
    set_property("no castle", 1);
    set("short", "Dunks Coffee Shop");
    set("long",
     "Welcome to Dunks.\n"
     "     A small little coffee and donut shop.  Booths and tables fill "
     "most of the room.  "
     "Around the shop you see various people sipping coffee and munching on "
     "donuts.  There is a counter with straws and napkins on it.  Also, "
     "a waitress can usually be found tidying the place up while she "
     "waits on customers.  On the wall over the counter you see a menu.");
    set_items(
        ([
	  "restaurant" : "Dunks Coffee Shop",
          "shop" : "Dunks Coffee Shop",
          "booths" : "There is a booth over on the side.",
          "wall" : "The menu is posted there.",
          "tables" : "The tables are spaced around the shop.",
          "counter" : "Hmm...for some reason this counter makes you think of Electa.",
          "napkins" : "For those who aren't quite so neat.",
          "straws" : "Plastic straws with the paper on them, perfect for shooting.",
          "customers" : "Wow, there isn't a line at the moment.",
          "menu" : "You may read it if you like.",
          "people" : "There are many strange people here.",
          ]) );
    set_exits(
              ([
                "east" : "/wizards/aurora/rooms/sitting.c",
              ]) );
}

void reset() {
  ::reset();
    if(!present("flo"))
      new("/wizards/aurora/monsters/flo")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("flo");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    write("Welcome to Dunks Coffee Shop");

write("*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*");
    write("Powdered Donut\t\t\t"+ (int)ob->get_price("donut") + " silver");
    write("Honey Dipped Creula\t\t"+(int)ob->get_price("creula")+" silver");
     write("Blueberry Muffin\t\t"+(int)ob->get_price("muffin")+" silver");
    write("Munchkin Hole\t\t\t"+ (int)ob->get_price("munchkin")+" silver");
     write("Coffee\t\t\t\t"+ (int)ob->get_price("coffee")+" silver");
     write("Iced Coffee \(iced\)\t\t"+ (int)ob->get_price("iced")+" silver");
     write("Lemonaid\t\t\t"+ (int)ob->get_price("lemonaid")+" silver");
    write("*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*");
    write("<buy dish_name> will allow you to purchase these items.");
    return 1;
}

