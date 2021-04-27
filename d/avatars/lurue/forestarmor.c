#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
	::create();
	set_name("forest armor");
	set_id(({ "armor", "forest armor", "armor of the forest", "leather", "cloth armor", "bark armor", "cloth and bark armor" }));
	set_short("%^RESET%^%^GREEN%^A%^ORANGE%^r%^BOLD%^%^BLACK%^m%^RESET%^%^GREEN%^or of the F%^ORANGE%^o%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^est%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^cloth %^ORANGE%^and %^BOLD%^%^BLACK%^bark %^RESET%^%^ORANGE%^armor%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Designed with %^GREEN%^ca%^ORANGE%^m%^GREEN%^o%^BOLD%^%^BLACK%^u%^RESET%^%^GREEN%^fl%^ORANGE%^a%^GREEN%^ge %^RESET%^in mind, these suits of armor are made from specially prepared pieces of %^ORANGE%^bark %^RESET%^cut into small diamond shaped panels and then attached onto a set of soft cotton backing dyed a deep shade of %^GREEN%^green%^RESET%^.  The effect of which provides an ever shifting pattern of %^GREEN%^green%^RESET%^, %^ORANGE%^brown %^RESET%^and %^BOLD%^%^BLACK%^gray %^RESET%^allowing th

AVATAR
	);
	set_weight(15);
	set_value(1500);
	set_lore(
@AVATAR
Despite the lack of ornate design work that is usually found within elven craft, this armor is clearly created by the fair folk.  Sylvan in design, and made to provide both protection and camouflage, the pieces are created from ironwood bark and each plate is hand shaped by the one who will wear it.  No two are exactly alike, though the basic nature of their design is simple.  Lore tells that this craft is handed down from generation to generation, just as is the magic rituals which imbue the armor with su

AVATAR
	);
	set_property("lore difficulty",13);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" slips the form fitting "+query_short()+" on.",ETO);
	tell_object(ETO,"The "+query_short()+" slips right on, forming snuggly to your body.");
	ETO->set_property("magic resistance",20);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes and carefully sets the "+query_short()+" aside.",ETO);
	tell_object(ETO,"You carefully slide the "+query_short()+" off and set it aside.");
	ETO->set_property("magic resistance",-20);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),""+ETOQCN+"'s "+query_short()+" shimmer %^GREEN%^green%^RESET%^, %^ORANGE%^brown %^RESET%^and %^BOLD%^%^BLACK%^black%^RESET%^ as the wooden plates deflect "+who->QCN+"'s attack.",({ETO,who}));
	tell_object(ETO,"The "+query_short()+" shimmer %^GREEN%^green%^RESET%^, %^ORANGE%^brown %^RESET%^and %^BOLD%^%^BLACK%^black%^RESET%^ as the wooden plates deflect "+who->QCN+"'s attack.");
	tell_object(who,""+ETOQCN+"'s "+query_short()+" shimmer %^GREEN%^green%^RESET%^, %^ORANGE%^brown %^RESET%^and %^BOLD%^%^BLACK%^black%^RESET%^ as the wooden plates deflect your attack.");
return (damage*75)/100;	}
}
