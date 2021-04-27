//shry_twig_key.c - Shrydelhi's house key
inherit  "/std/Object";

void create() {
  ::create();
  set_name("twig_key");
  set_id(({"key","wooden key","twig key","house key","shrydelhi's key","twig_key"}));
  set_short("small wooden key");
  set_long("The twisting wood of this twig is left partially in the rough, with bark appearing "+
     "in sporadic places.  Despite the rustic appearance, there is no doubt "+
     "this is a key of some kind.");
  set_weight(1);
  set_value(1);
}
