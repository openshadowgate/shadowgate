#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^c%^BOLD%^r%^RESET%^%^GREEN%^o%^BOLD%^w%^RESET%^%^GREEN%^n of %^RESET%^%^RED%^w%^BOLD%^i%^YELLOW%^l%^RESET%^%^ORANGE%^d%^GREEN%^f%^BOLD%^%^GREEN%^l%^BLUE%^o%^RESET%^%^BLUE%^w%^CYAN%^e%^BOLD%^%^BLUE%^r%^MAGENTA%^s%^RESET%^");
	set_id(({ "crown", "wildflower crown" }));
	set_short("%^BOLD%^%^CYAN%^R%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^si's %^BOLD%^%^MAGENTA%^F%^RESET%^%^MAGENTA%^l%^RED%^o%^BOLD%^%^RED%^w%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^r%^RESET%^%^RED%^i%^MAGENTA%^n%^BOLD%^%^MAGENTA%^g %^CYAN%^C%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^n%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^c%^BOLD%^r%^RESET%^%^GREEN%^o%^BOLD%^w%^RESET%^%^GREEN%^n of %^RESET%^%^RED%^w%^BOLD%^i%^YELLOW%^l%^RESET%^%^ORANGE%^d%^GREEN%^f%^BOLD%^%^GREEN%^l%^BLUE%^o%^RESET%^%^BLUE%^w%^CYAN%^e%^BOLD%^r%^MAGENTA%^s%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^Many %^RESET%^%^RED%^c%^ORANGE%^o%^YELLOW%^l%^RESET%^%^GREEN%^o%^BLUE%^r%^CYAN%^s%^BOLD%^%^GREEN%^ and varieties of %^RESET%^%^RED%^w%^BOLD%^i%^YELLOW%^l%^RESET%^%^ORANGE%^d%^GREEN%^f%^BOLD%^%^GREEN%^l%^BLUE%^o%^RESET%^%^BLUE%^w%^CYAN%^e%^BOLD%^%^BLUE%^r%^MAGENTA%^s%^BOLD%^%^GREEN%^ have been weaved together to make this charming crown. I%^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^y adds a touch of green amongst the %^BOLD%^%^RED%^d%^RESET%^%^RED%^e%^BOLD%^%^RED%^ep r%^RESET%^%^RED%^ed%^BOLD%^%^RED%^s%^GREEN%^, %^BOLD%^%^BLUE%^p%^RESET%^al%^BOLD%^%^BLUE%^e b%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^s%^GREEN%^, %^YELLOW%^b%^RESET%^%^ORANGE%^r%^YELLOW%^ig%^RESET%^%^ORANGE%^h%^YELLOW%^t y%^RESET%^%^ORANGE%^el%^BOLD%^l%^RESET%^%^ORANGE%^ow%^YELLOW%^s%^GREEN%^ and %^RESET%^%^MAGENTA%^lo%^BOLD%^ve%^RESET%^%^MAGENTA%^ly %^BOLD%^la%^RESET%^%^MAGENTA%^v%^BOLD%^en%^RESET%^%^MAGENTA%^d%^BOLD%^%^MAGENTA%^er%^GREEN%^ tones. A few of the petals have been decorated with tiny %^RESET%^%^CYAN%^sa%^BOLD%^p%^BLUE%^p%^RESET%^%^BLUE%^h%^BOLD%^i%^CYAN%^r%^RESET%^%^CYAN%^es%^BOLD%^%^GREEN%^ and %^RESET%^o%^BOLD%^p%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^l%^RESET%^s%^BOLD%^%^GREEN%^ to add some sparkle to the crown. Preserved by magic, the flowers never wilt and always smell heavenly. A few ribbons have been entwined through the flowers and they fall down the back in a %^RED%^d%^ORANGE%^a%^GREEN%^z%^BLUE%^zl%^GREEN%^i%^ORANGE%^n%^RED%^g%^BOLD%^%^GREEN%^ array of color.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(4000);
	set_lore(
@AVATAR
%^BOLD%^Children enjoy spreading the tale of Resi the pixie. According to the myth of some civilizations, when the world was just beginning, Resi traveled far and wide, planting the seeds that would someday forever blossom into the beautiful flowers that we still find today. From these, she would pick the prettiest of all the flowers and joyfully adorn her closest friends in them.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^The wonderful scent of %^RESET%^%^RED%^w%^BOLD%^i%^YELLOW%^l%^RESET%^%^ORANGE%^d%^GREEN%^f%^BOLD%^%^GREEN%^l%^BLUE%^o%^RESET%^%^BLUE%^w%^CYAN%^e%^BOLD%^%^BLUE%^r%^MAGENTA%^s%^BOLD%^%^GREEN%^ fills the air!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^The wonderful scent of %^RESET%^%^RED%^w%^BOLD%^i%^YELLOW%^l%^RESET%^%^ORANGE%^d%^GREEN%^f%^BOLD%^%^GREEN%^l%^BLUE%^o%^RESET%^%^BLUE%^w%^CYAN%^e%^BOLD%^%^BLUE%^r%^MAGENTA%^s%^BOLD%^%^GREEN%^ fills the air!%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	ETO->add_stat_bonus("wisdom",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You feel a bit reluctant to remove this lovely crown.%^RESET%^");
	ETO->add_stat_bonus("charisma",-1);
	ETO->add_stat_bonus("wisdom",-1);
	return 1;
}
