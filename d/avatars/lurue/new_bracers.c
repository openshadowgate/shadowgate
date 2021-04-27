#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("bracers");
	set_id(({ "woven bracers", "cloth bracers", "bracers" }));
	set_short("%^RESET%^%^ORANGE%^W%^GREEN%^o%^RESET%^v%^ORANGE%^en B%^GREEN%^r%^WHITE%^a%^ORANGE%^ce%^GREEN%^r%^ORANGE%^s%^RESET%^");
	set_obvious_short("%^RESET%^a set of %^RESET%^%^ORANGE%^cl%^GREEN%^o%^ORANGE%^th b%^GREEN%^r%^RESET%^a%^ORANGE%^cers%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Several layers of thick padded cotton has been sewn together to create these arm protections.  Between the layers, thin ties of %^ORANGE%^leather %^RESET%^have been woven, providing extra strength for the bracers and giving the wearer a way to tie them on.  On the outer layer of the fabric someone has embroidered swirls of %^ORANGE%^orange %^RESET%^and %^GREEN%^green%^RESET%^, giving the otherwise plain bracers a bit of style.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(50);
	set_lore(
@AVATAR
Every trainer who takes on a student knows that eventually those students will graduate from blunted weapons to sharp ones.  However, in the meantime, one still needs to protect their student from the damaging bruises that can be caused by blunted swords.  These must be lighter weight then the heavier leather and metal, so that the student, unused to wearing such armors, can adapt well. The answer to this challenge is padded armor such as these bracers. 

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("bracer");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" strap the leather ties about their arm and admires the swirls of color upon their "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You strap the leather ties about your arm and admire the swirls of color upon your "+query_short()+".%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" looks satisfied as they take their "+query_short()+"%^RESET%^%^ORANGE%^ off.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^You unlace the "+query_short()+" %^RESET%^%^ORANGE%^and study your arms, happy to find there are no new bruises to be seen.%^RESET%^");
	return 1;
}
