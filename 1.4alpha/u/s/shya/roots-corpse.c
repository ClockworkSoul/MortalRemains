inherit "/std/object.c";

void init()
{
environment(this_object())->on_roots_die();
dest_me();
}