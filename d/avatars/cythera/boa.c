#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
   set_name("bracers");
   set_id(({"bracers","armor","bracers of armor"}));
   set_obvious_short("%^RESET%^%^CYAN%^steel plated bracers%^RESET%^");
   set_short("%^RESET%^%^RED%^B%^CYAN%^r%^RED%^a%^CYAN%^c%^RED%^e%^CYAN%^r%^RED%^s of the %^BLUE%^Guardian%^RESET%^");
   set_long(
      "%^CYAN%^These bracers are made from plates of steel. The plates have been curved"+
      " and pieced together to form these remarkably durable and heavy guards."+
	"  The edges of each plate has been stained %^RED%^dark red%^CYAN%^, "+
	"bringing out the orderly linear pattern engraved into them."+
      " The bracers are slightly longer than average bracers, covering the wearer's"+
      " wrist and running along the forearm all the way to the elbow.  On the "+
	"crest of each plate a small, but prominate, image of a right hand "+
	"steel gauntlet with a %^BOLD%^%^BLUE%^blue eye%^RESET%^%^CYAN%^ has been"+
	" painted.%^RESET%^\n" );
	set_lore("Though the priest of Helm typically favor heavy "+
		"suits of plate mail, there are a rare few who find they like "+
		"the feeling of bracers.  This desire came about due to one man, "+
		"Herend Steelleaf, a priest of Helm.  Herend was trained in a "+
		"foreign and strange form of combat, using his fists and feet "+
		"to defend those he watched over.  The Steel Monk of Helm was "+
		"first regarded as an oddity in the faith, something that is not"+
		" good for the orderly faith of The Watcher.  Though in time the"+
		" Steel Monk proved himself to be a dedicated follower of Helm, "+
		"and one of the best guardians in the lands.  It was rumored that "+
		"Helm himself ordered the priests of the temple to create a pair "+
		"of bracers of the monk, and provided them with the power to enchant"+
		" them.  Within the faith, there are a few who idolize the Steel "+
		"Monk, and strive to be like him.");
	set_property("lore",10);
   	set_weight(50);
   	set_value(10000);
   	set_type("armour");
   	set_limbs(({"torso"}));
	set_ac(7);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
   	if((string)ETO->query_diety() == "helm") {
      	tell_object(ETO,"%^CYAN%^As the bracers shine with a steady glow, you feel safe and protected.");
      return 1;
   	}else{
		tell_object(ETO,"%^BOLD%^The bracers refuse you!");
	return 0;
	}
}
int remove_func(){
		tell_object(ETO,"%^RED%^You feel the protection fade as you remove the bracers.");
		return 1;
}