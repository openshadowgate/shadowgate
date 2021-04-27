#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^A gr%^RESET%^a%^BOLD%^%^BLACK%^y leather blazer%^RESET%^");
	set_id(({ "blazer", "coat", "coat of the stormy skies", "jacket" }));
	set_short("%^BOLD%^%^BLACK%^C%^RESET%^o%^CYAN%^a%^BOLD%^%^CYAN%^t %^BOLD%^%^BLACK%^of the %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^o%^RESET%^r%^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^y %^BOLD%^%^BLACK%^S%^RESET%^k%^CYAN%^i%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A gr%^RESET%^a%^BOLD%^%^BLACK%^y leather blazer%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This is a fitted lightweight leather blazer dyed a deep shade of %^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^or%^BOLD%^%^BLACK%^m%^RESET%^y%^BOLD%^%^BLACK%^ gray with a matching lapel. Three %^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^y%^BOLD%^%^BLACK%^ buttons form a striking contrast against the smooth leather. The stylish plain waistline and sleeves have been masterfully tailored to allow freedom of movement. The inside is lined with %^BOLD%^%^BLUE%^s%^RESET%^%^BLUE%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g%^BOLD%^%^BLACK%^ shades of %^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^l%^BLUE%^u%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^, adding extra comfort to the blazer. Sewn into the soft silk are deep pockets.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(5600);
	set_lore(
@AVATAR
%^RESET%^%^CYAN%^Appealing due to their sensible style while also affording the wearer freedom of movement and decent protection, these coats are highly desired by people from all walks of life. Unfortunately, they are far from common in these lands and are owned only by either important or very lucky individuals. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",10);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
    if(lower_case((string)ETO->query_true_name()) != "cyclone")
    {
        tell_object(ETO,"The magic of the blazer refuses you!");
        return 0;
    }
    ETO->set_property("magic resistance",10);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slip on the coat, amazed at how %^RESET%^light%^BOLD%^%^CYAN%^ it feels.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
    ETO->set_property("magic resistance",-10);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The jacket feels %^BLUE%^cool%^CYAN%^ to the touch as you remove it.%^RESET%^");
	return 1;
}
