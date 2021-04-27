#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("white robes");
	set_id(({ "robes" }));
	set_short("%^BOLD%^%^WHITE%^Vestments of %^BLUE%^Torm%^RESET%^");
	set_obvious_short("white robes");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^A long flowing robe made of a fine cotton.  The cotton is a brilliant shade of white that seems to resist any dirt or grim.  Stitched across the back of the robes is a detailed image of a %^YELLOW%^golden lion%^WHITE%^.  %^BLUE%^Blue silk%^WHITE%^ accents finish the hem and cuff of the robes.  Woven into the fabric is the image of Torm the True's holy symbol, over the left breast.  Deep pockets lined in %^BLUE%^blue silk%^WHITE%^ finish off the details of this robe.

AVATAR
	);
	set_weight(5);
	set_value(300);
	set_lore(
@AVATAR
These are the typical vestment of Torm's faith.

AVATAR
	);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" %^BOLD%^%^WHITE%^slips on their "+query_short()+" %^BOLD%^%^WHITE%^and smiles softly",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip on the robes and feel the blessings of Torm on you.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" %^BOLD%^%^WHITE%^carefully slips off their "+query_short()+"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You carefully slip off the robes, as to avoid wrinkling or ripping them");
	return 1;
}
