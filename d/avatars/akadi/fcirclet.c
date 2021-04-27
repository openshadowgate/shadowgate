#include <std.h>
inherit "/d/common/obj/jewelry/circlet";

void create(){
	::create();
	set_name("Circlet of Flowers");
	set_id(({ "circlet", "flower circlet", "circlet of flowers", "crown" }));
	set_short("%^BOLD%^%^YELLOW%^a g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n circlet%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Dainty%^RESET%^ and %^BOLD%^feminine%^RESET%^, this %^BOLD%^circlet%^RESET%^ is a lovely addition to any lady's wardrobe. While it is rather simple in design, it is also quite %^BOLD%"
	"^pretty%^RESET%^. The %^BOLD%^delicate%^RESET%^ %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n band%^RESET%^ has been carefully etched into a pattern of small flowers, each"
	" flower being lightly %^BOLD%^glazed%^RESET%^ to add a %^BOLD%^s%^RESET%^hi%^BOLD%^m%^RESET%^m%^BOLD%^er%^RESET%^ and touch of %^BOLD%^%^RED%^c%^RESET%^%^RED%^olo%^BOLD%^%^RED%^r%^RESET%^ to the circl"
	"et, creating a %^BOLD%^lovely%^RESET%^ effect.%^RESET%^
"
	);
	set_value(100);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The circlet feels quite light.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"");
	return 1;
}

