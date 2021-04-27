inherit  "/std/Object";
void create() {
  ::create();
  set_name("brass key");
  set_id(({"key","brass key"}));
  set_short("%^ORANGE%^brass key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of "+
      "%^ORANGE%^brass%^RESET%^.  It is engraved with fancy designs and symbols "+
      "and looks to be sturdy and inexpensive.\n"
     );
    set_weight(1);
    set("value", 2);
}
