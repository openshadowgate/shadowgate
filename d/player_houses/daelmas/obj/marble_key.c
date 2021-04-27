inherit  "/std/Object";
void create() {
  ::create();
  set_name("marble key");
  set_id(({"key","marble key"}));
  set_short("%^WHITE%^Marble key%^RESET%^");
  set("long","This is a shiney stone key that is apparently made out of "+
      "%^BOLD%^%^WHITE%^marble%^RESET%^.  It is engraved with fancy designs and symbols "+
      "and looks to be expensive.\n"
     );
    set_weight(2);
    set("value", 10);
}
