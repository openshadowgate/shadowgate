inherit  "/std/Object";
void create() {
  ::create();
  set_name("green key");
  set_id(({"key","green key"}));
  set_short("%^GREEN%^Green key%^RESET%^");
  set("long","This is a copper key that has corroded and now is completely "+
      "green.  Who knows what it is, or was, used for.\n"
     );
    set_weight(8);
    set("value", 10);
}
