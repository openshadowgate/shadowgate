//  Girruuth's shop key

inherit  "/std/Object";
void create() {
  ::create();
  set_name("gir_key");
  set_id(({"key", "iron key", "Girruuth shop key", "shop key" }));
  set_short("%^RESET%^%^ORANGE%^bronze key%^RESET%^");
  set("long", "%^ORANGE%^This bronze skeleton key is ornately carved and the head is shaped like a double bladed axe.  Thankfully it isn't highly sharpened, lest it cut you badly in handling and use.");
  set_weight(1);
  set("value", 1);
}