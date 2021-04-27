#include <std.h>
inherit "/d/common/obj/armour/coif";

void create(){
	::create();
	set_name("%^BOLD%^%^MAGENTA%^F%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^e%^BOLD%^%^MAGENTA%^s %^WHITE%^E%^BLACK%^m%^WHITE%^b%^BLACK%^r%^WHITE%^a%^BLACK%^c%^WHITE%^e%^RESET%^");
	set_id(({ "coif", "fates embrace", "fates coif" }));
	set_short("%^BOLD%^%^MAGENTA%^F%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^e%^BOLD%^%^MAGENTA%^s %^WHITE%^E%^BLACK%^m%^WHITE%^b%^BLACK%^r%^WHITE%^a%^BLACK%^c%^WHITE%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^r%^ORANGE%^u%^RED%^st%^ORANGE%^e%^RED%^d %^CYAN%^j%^RESET%^e%^MAGENTA%^w%^RESET%^e%^CYAN%^l%^RESET%^e%^MAGENTA%^d %^BLUE%^coif%^RESET%^");
	set_long("This coif must have once been regal in it's hay-day. The metal itself, which is formed of interconnected concentric circles, is of %^BLUE%^pitted%^RESET%^ and %^RED%^r%^ORANGE%^u%^RED%^st%^ORANGE%^e%^"
	"RED%^d %^BOLD%^%^BLUE%^ir%^RESET%^o%^BOLD%^%^BLUE%^n%^RESET%^. A picture of antlers has been formed by various gems. %^RED%^Rh%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^n%^BO"
	"LD%^%^BLACK%^i%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^e%^RESET%^, %^BOLD%^%^RED%^red %^RESET%^%^RED%^b%^BOLD%^e%^RESET%^%^RED%^r%^BOLD%^y%^RESET%^%^RED%^l%^RESET%^ and %^BOLD%^%^WHITE%^sn%^BLACK%^o%^WHITE%^"
	"wfl%^BLACK%^a%^WHITE%^k%^BLACK%^e obsidian%^RESET%^ are interspensed to form the antlers and still glimmer against the pitiful metal.
"
	);
	set_value(0);
	set_lore("%^RESET%^%^RED%^Although this coif once looked as if it was once regal, it's appearance is how it has ever been seen. The coif was crafted and imbued with magical powers by a traveling priest of Besha"
	"ba who's martial prowess was undermined by her magical aptitude. It is speculated that she twisted the fates themselves and instilled them into the gemstones on the coif.
%^RESET%^
"
	);
    set_property("lore difficulty",16);
    set("dexbonus",-1);
    set("intbonus",1);
    set("conbonus",-1);
    set("wisbonus",1);
	set_size(1);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Various %^BLACK%^g%^RED%^e%^WHITE%^m%^BLACK%^s%^RED%^t%^WHITE%^o%^BLACK%^n%^RED%^e%^WHITE%^s on "+ETOQCN+"%^BOLD%^%^WHITE%^'s coif flash %^YELLOW%^brightly%^WHITE%^ while others %^RESET%^dull%^BOLD%^%^WHITE%^ in luster as it is pulled on.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Various %^BLACK%^g%^RED%^e%^WHITE%^m%^BLACK%^s%^RED%^t%^WHITE%^o%^BLACK%^n%^RED%^e%^WHITE%^s on the coif flash %^YELLOW%^brightly%^WHITE%^ while others %^RESET%^dull%^BOLD%^%^WHITE%^ in luster as you pull it on.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The %^BLACK%^g%^RED%^e%^WHITE%^m%^BLACK%^s%^RED%^t%^WHITE%^o%^BLACK%^n%^RED%^e%^WHITE%^s on the coif revert to their normal hues as "+ETOQCN+" %^BOLD%^%^WHITE%^sets it aside.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BLACK%^g%^RED%^e%^WHITE%^m%^BLACK%^s%^RED%^t%^WHITE%^o%^BLACK%^n%^RED%^e%^WHITE%^s on the coif revert to their normal hues as you set it aside.%^RESET%^");
       return 1;
}

