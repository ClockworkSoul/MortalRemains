
inherit "inherit/weapon.c";

void reset (status arg) {
  ::reset (arg);
  if(!arg) {
        set_name("hand axe");
        set_alias("axe");
        set_short("A small hand axe");
        set_long (
" At first glance, this appears to be a fine hand axe. It is light enough\n"+
" to be wielded one handed, but make no mistake it is quite deadly. The head\n"+
" is made of a strange metal not of this world. This weapon may have come from\n
"+
" the underworld itself. It will surely bring a fine price at the shop.\n");
        set_value(300);
        set_weight(3);
        set_wc(8);
        set_length(24);
	set_type("hack");
  }
}
