inherit  "/std/Object";
void create() {
  ::create();
  set_name("gold key");
  set_id(({"key","gold key"}));
  set_short("%^BOLD%^%^YELLOW%^gold key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of "+
      "%^BOLD%^%^YELLOW%^gold%^RESET%^.  It is engraved with tiny designs and symbols "+
      "and looks to be delicate and inexpensive.\n"
     );
    set_weight(1);
    set("value", 2);
}
