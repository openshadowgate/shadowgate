#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("greatcoat");
	set_id(({ "coat", "greatcoat", "robe", "great coat" }));
	set_short("%^BOLD%^%^BLACK%^Coat of the %^RED%^L%^RESET%^%^RED%^id%^BOLD%^less E%^RESET%^%^RED%^y%^BOLD%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^BLACK%^a dark leather greatcoat%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This greatcoat is made from many folds of thick, darkly tanned hide.  It is probably made from cattle or some other powerful beast. It is designed to be worn over several layers of clothes.  The coat has a wide collar that may be turned up to protect the wearer's face against inclement weather, and a double cape across the shoulders for added warmth.  The sleeves of the coat have cuffs that are folded back and fastened with %^WHITE%^horn%^BLACK%^ buttons and chains, ready to be let down should the wearer's hands be cold.  Two large, deep pockets with %^RESET%^metal buttoned%^BOLD%^%^BLACK%^ flaps grace the front of the coat, adding not only decoration but also functionality.  The finishing touch of this coat is a series of metal reinforcements.  Steel plates protect the coat where it would fall over the thighs, forearms and breast.  Metal studs line the shoulders and seams.  Finally, a deep impression has been branded into the back of the coat, a %^RED%^lidless eye%^BLACK%^ with chaotic rays issuing forth.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(1200);
	set_max_internal_encumbrance(21);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_item_bonus("magic resistance",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" dons the coat, the branded eye symbol begins to %^RED%^glow%^BLACK%^!",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you don the coat, the eye %^BOLD%^%^RED%^begins to glow%^BLACK%^!");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" removes the coat, the eye symbol %^RED%^fades %^RESET%^%^RED%^to %^BOLD%^%^BLACK%^black%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel vulnerable and small without the greatcoat%^RESET%^");
	return 1;
}