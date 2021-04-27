inherit  "/std/Object";

void create() {
  ::create();
  set_name("wood key");
  set_id(({"key","wood key"}));
  set_short("%^RESET%^%^ORANGE%^wood key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of a strange resilent "+
      "%^RESET%^%^ORANGE%^wood%^RESET%^.\n"
     );
    set_weight(2);
    set("value", 10);
}
