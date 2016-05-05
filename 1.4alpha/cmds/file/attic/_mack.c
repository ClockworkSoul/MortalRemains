#include "/u/z/zur/priests/pr.h"
int cmd_mack()
{
  string *sp, *sh;
  int i, col, lvl;
  object d;
  mixed s;
  sp = get_dir(SPELLS);
  if(!sp)
  {
    return (int) notify_fail("Could not locate "+SPELLS+".\n");
   }
  i = sizeof(sp);
  d = load_object(REL_D);
  printf("%d\n", i);
  s = "";
  while(i--)
  {
    if(col > 2)
    {
      col = 0;
      write("\n");
    }
    sh = call_other(SPELLS+sp[i], "query_spheres");
    lvl = call_other(SPELLS+sp[i], "query_level");
    if(d->check_sphere(this_player(), sh, lvl))
    {
      if(d->level_check(
          (wizardp(this_player())) ? -1 : this_player()->query_level(),
          lvl))
        {
          s += sp[i];
         }
    }
    s = explode(s, ".c")[0];
    printf("%s", (s) ? capitalize(s)+"    " : "No spells availible.\n");
    col++;
   }
   write("\n");
   return 1;
 }
