#include <cave.h>

inherit OBJECT;

void create() {
    ::create();
     seteuid(getuid());
    set("name","temp-obj");
    set("id",({"temp-obj","obj","temp"}) );
    set("short","a temp object");
    set("long","This is a temp object of Entropy's.\n");
}

void init() {
    add_action("TestObj","test");
}

int TestObj(string str) {
    if(FOOL(str)) {
        write("There is an object: "+str+"\n");
        return 1;
    }
    else {
        write("There is no object: "+str+"\n");
        return 1;
    }
}
