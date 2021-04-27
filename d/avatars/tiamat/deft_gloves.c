#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^Fine leather gloves%^RESET%^");
	set_id(({ "glove", "gloves" }));
	set_short("%^RESET%^%^ORANGE%^Deft Gloves%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Fine leather gloves%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a pair of gloves made from high quality leather, the origins of which are unknown.  The gloves are short, just barely covering the wrist, but the insides are lined with soft fur to protect the wearer from exposure to outside elements.  The most unusual feature of these gloves are the long fingers, which seem about an inch too long and are studded with a %^RED%^red garnet%^ORANGE%^ over each knuckle.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1300);
	set_lore(
@AVATAR
Deft gloves are any of a multitude of magical gloves crafted by an obscure magician and part-time bank robber known only as Slips Tharview.  He was not particularly famous for either of his profession but his namesake lives on in association with these gloves he made for his guild.  Rumor has it that Deft Gloves provide some protection, but also increase one's natural grace.

AVATAR
	);
	set_property("lore difficulty",10);
	set("dexbonus",1);
	set_type("clothing");
	set_limbs(({ "left hand", "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^RESET%^%^ORANGE%^'s gloves conform perfectly to the hand.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^ The fingers on the "+query_short()+" %^RESET%^%^ORANGE%^shrink to fit your hand perfectly.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" %^BOLD%^%^BLACK%^takes off their gloves%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^%^ORANGE%^"+query_short()+" %^RESET%^%^BOLD%^%^BLACK%^go limp when removed.%^RESET%^");
	return 1;
}
