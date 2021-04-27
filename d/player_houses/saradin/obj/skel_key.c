inherit  "/std/Object";
void create() {
  ::create();
  set_name("black skeleton key");
  set_id(({"black skeleton key","skeleton key","key"}));
  set_short("%^BOLD%^%^BLACK%^black skeleton key%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is an inexpensive looking iron key with a very "+
  		"irregular tooth pattern.  Surprisingly enough this skeleton "+
  		"key has a skull engraved into its headpiece.\n%^RESET%^");
  set_weight(1);
  set("value",0);
}
