inherit  "/std/Object";
void create() {
  ::create();
  set_name("ruby key");
  set_id(({"ruby key","key"}));
  set_short("%^BOLD%^%^RED%^ruby key%^RESET%^");
  set_long("%^BOLD%^%^RED%^This key is made from an unknown metal "+
  	"and encrusted with ruby chips.\n%^RESET%^");
  set_weight(1);
  set("value",0);
}
