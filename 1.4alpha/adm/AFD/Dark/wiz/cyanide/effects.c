#include "cmds/_decay.c"
#include "_pull.c"
#include "_push.c"
#include "_iscan.c"

inherit OBJECT;

int query_auto_load() {return 1;}

void create() {
  set ("invisible", 2);
  set ("prevent_drop", 1);
  set ("prevent_get", 1);
  set ("id", ({ "personality", "effects" }) );
}

void init() {
  add_action ("cmd_decay", "decay");
  add_action ("cmd_pull", "pull");
  add_action ("cmd_push", "push");
  add_action ("iscan", "iscan");
}
