//  Dungeon key to Silesse's house

inherit  "/std/Object";

void create() {
  ::create();
   set_name("%^BOLD%^%^WHITE%^Small %^RESET%^iv%^BOLD%^o%^RESET%^ry %^BOLD%^key%^RESET%^");
  set_id(({"key", "ivory key", "dungeon key" }));
  set_short("%^BOLD%^%^WHITE%^Small %^RESET%^iv%^BOLD%^o%^RESET%^ry %^BOLD%^key%^RESET%^");
  set("long", "%^BOLD%^%^WHITE%^This small %^RESET%^iv%^BOLD%^o%^RESET%^ry %^BOLD%^key is quite %^RESET%^o%^BOLD%^%^BLACK%^rn%^RESET%^a%^BOLD%^t%^RESET%^e%^BOLD%^, and has a simple inscription written on it%^RESET%^.");
  set_weight(1);
  set("value", 1);
   set_read("%^BOLD%^%^WHITE%^Of%^BLACK%^fer%^RESET%^in%^BOLD%^ngs%^RESET%^");

}
