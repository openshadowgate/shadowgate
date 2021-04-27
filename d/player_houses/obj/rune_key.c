//rune_key.c - Stefano's house key
inherit  "/std/Object";

void create() {
  ::create();
  set_name("rune_key");
  set_id(({"key","black key","rune key","iron key"}));
  set_short("small iron key");
  set_long("This ornate iron key is quite intricate.  It is made "+
     "of numerous mysterious runes that flicker blue-black and seem "+
     "to shift and twist as you look at them.");
  set_weight(1);
  set_value(1);
}
