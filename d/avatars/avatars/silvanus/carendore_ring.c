#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silver ring");
	set_id(({ "ring", "silver ring", "transparent silver ring" }));
	set_short("%^BOLD%^%^WHITE%^silver ring%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^silver ring%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This ring is made from a thin band of pure silver but is strangely %^BLUE%^cold%^RESET%^%^BOLD%^%^WHITE%^ to the touch.  Engraved into the underside of the band are markings, which appear to be some sort of writing.%^RESET%^
AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^With my might I have constructed this ring so that I may always be reminded of the warmth of Alysssa's love.  I shall scar the world and destroy that dreaded witch Li'Linmai.  She will pay for the pain she has caused me, for the coldness that now dwells within me.  Someday when I sit as king over all things I shall give this ring to my firstborn and he shall take over rule, all while remembering Alysssa.

%^BOLD%^%^WHITE%^Nimmi Carendore%^RESET%^

AVATAR
	);
       set("langage","str");	
	set_weight(1);
	set_value(100);
	set_type("ring");
	set_limbs(({ "left hand", "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+"'s%^BOLD%^%^WHITE%^ "+query_short()+" begins %^YELLOW%^glowing%^BOLD%^%^WHITE%^!%^RESET%^",TP);
	tell_object(TP,"%^BOLD%^%^WHITE%^Your "+query_short()+"%^BOLD%^%^WHITE%^ begins %^YELLOW%^glowing%^BOLD%^%^WHITE%^, a warmth encompassing your hand.%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This ring is made from a thin band of "
	   "pure, %^YELLOW%^glowing%^BOLD%^%^WHITE%^ silver, it is oddly "
	   "%^RED%^warm%^RESET%^%^BOLD%^%^WHITE%^ to the touch.  Engraved "
	   "into the underside of the band are markings, which appear to be "
	   "some sort of writing.%^RESET%^");
	set_short("%^YELLOW%^glowing %^WHITE%^silver ring%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^YELLOW%^"+ETO->query_cap_name()+"'s%^YELLOW%^ "+query_short()+"%^YELLOW%^ suddenly stops glowing!%^RESET%^",TP);
	tell_object(TP,"%^YELLOW%^Your "+query_short()+"%^YELLOW%^ stops its glow, leaving your hand feeling strangely %^BLUE%^cold%^YELLOW%^.%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This ring is made from a thin band of pure "
	   "silver but is strangely %^BLUE%^cold%^RESET%^%^BOLD%^%^WHITE%^ to "
	   "the touch.  Engraved into the underside of the band are markings, "
	   "which appear to be some sort of writing.%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^silver ring%^RESET%^");
	return 1;
}
