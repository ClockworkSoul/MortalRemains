string type;
int number;

inherit OBJECT;

void create() {
    type = ".44";
    number = 100;
    seteuid(getuid());
    set("short", "an Ammo Maker");
    set("id", ({ "maker" }) );
}

void init() {
    add_action("push", "push");
}

int push(string str) {
    object ammo;

    if (str!= "button") return 0;

    ammo = clone_object("/std/ammo.c");
    ammo->set_type(type);
    ammo->set_number(number);
    ammo->move(environment(TP));
    return 1;
}
