inherit  "/std/Object";
void create() {
  ::create();
  set_name("mithril key");
  set_id(({"key","mithril key"}));
  set_short("%^WHITE%^Mithril key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of "+
      "%^BOLD%^%^WHITE%^mithril%^RESET%^.  It is engraved with fancy designs and symbols "+
      "and looks to be expensive.\n"
     );
    set_weight(2);
    set("value", 10);
}
