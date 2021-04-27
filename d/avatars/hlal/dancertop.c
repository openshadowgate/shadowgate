#include <std.h>
inherit "/d/common/obj/clothing/shirt";

void create(){
	::create();
	set_name("a heavily embellished halter top");
	set_id(({ "top", "halter top", "heavily embellished halter top", "dancer's top", "dance top", "halter" }));
	set_short("%^ORANGE%^a heavily %^BOLD%^embellished %^RESET%^%^ORANGE%^halter top%^RESET%^");
	set_obvious_short("%^ORANGE%^a heavily %^BOLD%^embellished %^RESET%^%^ORANGE%^dance top%^RESET%^");
	set_long("%^RESET%^Tailored with the taste of the most demanding of dancers in mind, this %^RED%^halter styled %^RESET%^top is a work of art all its own. Softly shimmering silk of %^ORANGE%^d%^RED%^e%^ORANGE%^e"
	"p v%^BOLD%^e%^RESET%^%^ORANGE%^rmillion %^RESET%^creates the foundation of this garment, while it is the addition of rich, %^BOLD%^%^ORANGE%^golden brocade %^RESET%^embellishments and %^BOLD%^jingling"
	" coins %^RESET%^which make it so spectacular. Light dances across the ornate gold brocade which create the straps that wrap about the neck of the wearer. %^MAGENTA%^Heavy padding %^RESET%^within the c"
	"ups of the garment provide amble lift and security to not only provide the ideal silhouette for the wearer, but also the strength to hold up to even the most vigorous of dances.%^RESET%^
"	);
	set_value(6000);
	set_item_bonus("influence",2);
	set_item_bonus("charisma",2);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^The %^WHITE%^coins %^YELLOW%^of the "+query_short()+" %^WHITE%^j%^YELLOW%^i%^WHITE%^ngle %^YELLOW%^lightly as "+ETOQCN+" %^YELLOW%^fastens the straps around their neck.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^The %^WHITE%^coins %^YELLOW%^of the "+query_short()+" %^WHITE%^j%^YELLOW%^i%^WHITE%^ngle %^YELLOW%^lightly as you fasten the straps around your neck.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" %^CYAN%^exposes %^YELLOW%^their torso to you %^YELLOW%^as they remove "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel %^CYAN%^exposed %^YELLOW%^as you remove "+query_short()+"%^RESET%^");
	return 1;
}

