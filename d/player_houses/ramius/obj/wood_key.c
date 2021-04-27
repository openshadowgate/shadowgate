inherit  "/std/Object";

void create() {
  ::create();
  set_name("wood_key");
  set_id(({"key","wood key"}));
  set_short("wood key");
  set("long","%^RESET%^%^GREEN%^This is a small, carefully carved %^ORANGE%^wooden key%^RESET%^.
\n");
  set_weight(2);
  set("value", 10);
}