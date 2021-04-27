#include <std.h>
inherit "/d/common/obj/clothing/breeches";

void create(){
	::create();
	set_name("harem pants");
	set_id(({ "harem pants", "dance pants", "pants", "fancy pants", "fancy harem pants", "fancy dance pants" }));
	set_short("%^YELLOW%^h%^RESET%^a%^ORANGE%^r%^YELLOW%^e%^RESET%^%^ORANGE%^m p%^YELLOW%^a%^RESET%^%^ORANGE%^nts%^RESET%^");
	set_obvious_short("%^YELLOW%^f%^RESET%^%^ORANGE%^an%^YELLOW%^cy %^RESET%^%^ORANGE%^dancer p%^YELLOW%^a%^RESET%^%^ORANGE%^nts%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^Tailored with the taste of the most exacting belly dancer in mind, silk has been collected from some of the rarest %^WHITE%^s%^BOLD%^p%^BLACK%^i%^WHITE%^d%^WHITE%^ers %^RESET%^%^ORA"
	"NGE%^of the realms to create the sheer, shimmering textile which makes up the garment. Subjected to a meticulous dye process by a true master of the craft, the high quality silk of these leggings is a"
	" %^BOLD%^deep amber hue %^RESET%^%^ORANGE%^which has a subtle liquid sheen, yet still remains transparent enough to allow the shapely curves of the wearer's legs to be seen just beneath. Each leg has "
	"a single slit from the thigh to the ankle. The slit is edged with beads and %^BOLD%^shiny paillettes %^RESET%^%^ORANGE%^arranged into a %^BOLD%^%^BLACK%^floral pattern. %^RESET%^%^ORANGE%^Gathered abo"
	"ut each ankle, these %^CYAN%^billowing %^ORANGE%^leggings are reminiscent of something one would expect to see worn by a sheik's most sought after courtesan.%^RESET%^
"	);
	set_value(7000);
	set_item_bonus("armor bonus",1);
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^You spy a glimpse of thigh as "+ETOQCN+" %^RESET%^%^ORANGE%^wears "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^A glimpse of your legs can be seen through the leggings as you put them on.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The leggings slip off with ease as "+ETOQCN+" %^RESET%^%^ORANGE%^tugs at the strings.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^ORANGE%^The leggings slip off with ease as $N %^RESET%^%^ORANGE%^tugs at the strings.%^RESET%^");
	return 1;
}

