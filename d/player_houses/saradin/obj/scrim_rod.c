inherit  "/std/Object";
void create() {
  	::create();
	set_name("scrimshaw rod");
  	set_id(({"rod","scrimshaw rod","scrimshaw"}));
  	set_short("%^BOLD%^scrimshaw rod%^RESET%^");
  	set_long("%^BOLD%^This is a piece of whale bone that is about one "+
  		"inch in diameter and has a scene of a drowning man carved into "+
  		"the side.  The carving is primitive, but looks skillfully done.\n%^RESET%^");
  set_weight(2);
  set("value",5);
}
