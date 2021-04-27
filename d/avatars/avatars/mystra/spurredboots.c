#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create(){
	::create();
	set_name("spurredboots");
	set_id(({ "boots", "spurred boots" }));
	set_short("%^ORANGE%^B%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^ts %^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^f th%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^R%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^RESET%^");
	set_obvious_short("%^ORANGE%^a pair of spurred boots%^RESET%^");
	set_long("%^ORANGE%^This is a pair of tall, tan boots made specifically for the purpose of riding a mount.  They climb up the wearers calf stopping just short of the knee where a lavish %^BOLD%^%^WHITE%^sca%^RE"
	"SET%^%^RED%^ll%^BOLD%^%^WHITE%^op %^RESET%^%^ORANGE%^awaits the foots entry.  The %^BOLD%^%^BLACK%^tube %^RESET%^%^ORANGE%^of the boot is intrically designed with %^BOLD%^%^WHITE%^spir%^CYAN%^a%^WHITE"
	"%^ls %^RESET%^%^ORANGE%^and %^BOLD%^%^WHITE%^st%^CYAN%^a%^WHITE%^rs %^RESET%^%^ORANGE%^as the focal point of the %^BLUE%^inky %^ORANGE%^fashion.  The %^BOLD%^%^WHITE%^p%^BLUE%^i%^WHITE%^p%^BLUE%^i%^WH"
	"ITE%^ng %^RESET%^%^ORANGE%^runs the back of the calf as opposed the the traditional sides from the heel to the top of the %^BOLD%^%^BLACK%^tube%^RESET%^%^ORANGE%^.  The heels are studded and about 3 i"
	"nches in heighth.  On the back of the heels, %^WHITE%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r %^ORANGE%^spurs just out with their sharp points reflecting even the smallest bit of light.%^RESET%^
"
	);
	set_value(2500);
	set_lore("");
    set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" pulls on the "+query_short()+" quite easily.%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^Equestrian confidence overwhelms you as you slip into your "+query_short()+"%^RESET%^");
	ETO->add_skill_bonus("athletics",2);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" takes a deep sigh while taking off "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^Balance and stability recede from your body along with the "+query_short()+".%^RESET%^");
	ETO->add_skill_bonus("athletics",-2);
	return 1;
}

