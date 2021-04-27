#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create(){
	::create();
	set_name("Hammer of raining Storm");
	set_id(({ "hammer" }));
	set_short("%^BOLD%^%^BLACK%^solid %^RESET%^%^RED%^red-%^ORANGE%^g%^RED%^r%^ORANGE%^a%^RED%^n%^ORANGE%^i%^RED%^t%^ORANGE%^e%^BOLD%^%^WHITE%^ %^BLACK%^hammer%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Large hammer%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^The shaft of this hammer is made entirely from %^BLACK%^solid %^RESET%^%^RED%^red-%^ORANGE%^g%^RED%^r%^ORANGE%^a%^RED%^n%^ORANGE%^i%^RED%^t%^ORANGE%^e%^BOLD%^%^WHITE%^. The %^CYAN%^cr"
	"ystal flakes%^WHITE%^ in the %^RESET%^%^RED%^g%^ORANGE%^r%^RED%^a%^ORANGE%^n%^RED%^i%^ORANGE%^t%^RED%^e%^BOLD%^%^WHITE%^ seem to %^CYAN%^s%^WHITE%^h%^CYAN%^i%^WHITE%^m%^CYAN%^m%^WHITE%^e%^CYAN%^r%^WHI"
	"TE%^ with the %^RESET%^%^CYAN%^power%^BOLD%^%^WHITE%^ embedded within. The %^RESET%^%^ORANGE%^g%^RED%^r%^ORANGE%^a%^RED%^n%^ORANGE%^i%^RED%^t%^ORANGE%^e%^BOLD%^%^WHITE%^ is very %^BLACK%^rough%^WHITE%"
	"^ to the touch, and you would need glove to wield such weapon without it tearing your skin to %^RED%^blood%^WHITE%^. The massive head of this hammer is made from one solid piece of %^YELLOW%^yellow %^"
	"CYAN%^c%^WHITE%^r%^CYAN%^y%^WHITE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l%^WHITE%^. A hole has been drilled in the middle of the massive %^CYAN%^c%^WHITE%^r%^CYAN%^y%^WHITE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l%^WHIT"
	"E%^ and is held in place by bands of %^BLACK%^m%^RESET%^i%^BOLD%^%^BLACK%^t%^RESET%^h%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^. The %^BLACK%^bands%^WHITE%^ are covered with %^RED%^glowin"
	"g %^RESET%^%^RED%^red %^BOLD%^r%^RESET%^%^RED%^u%^BOLD%^n%^RESET%^%^RED%^e%^BOLD%^s%^WHITE%^. Within the %^CYAN%^c%^WHITE%^r%^CYAN%^y%^WHITE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l%^WHITE%^ %^RESET%^%^CYAN%^he"
	"ad, %^YELLOW%^runes%^WHITE%^ can be seen %^RESET%^%^CYAN%^f%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^w%^RESET%^%^CYAN%^i%^BOLD%^%^BLUE%^n%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ around in the very"
	" %^CYAN%^c%^WHITE%^r%^CYAN%^y%^WHITE%^s%^CYAN%^t%^WHITE%^a%^CYAN%^l%^WHITE%^ as if they were made of %^BLUE%^water%^WHITE%^. At the other end of the shaft, a large ball of %^CYAN%^cold%^WHITE%^-%^BLAC"
	"K%^iron%^WHITE%^ has been added as counterweight. Small %^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^r%^YELLOW%^i%^WHITE%^c%^YELLOW%^a%^WHITE%^l %^YELLOW%^charges%^WHITE%^ runs along "
	"the surface of the counterweight.
"	);
	set_value(15000);
	set_item_bonus("damage bonus",damage bonus 3);
	set_item_bonus("attack bonus",3);
	set_property("enchantment",6);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+query_short()+" %^BOLD%^%^WHITE%^A %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e %^WHITE%^of %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ surrounds "+ETOQCN+" hand as he wield the %^CYAN%^m%^YELLOW%^%^CYAN%^a%^YELLOW%^s%^CYAN%^s%^YELLOW%^i%^CYAN%^v%^YELLOW%^e%^WHITE%^ hammer",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^A %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e %^WHITE%^of %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ surrounds name hand as he wield the %^CYAN%^m%^YELLOW%^%^CYAN%^a%^YELLOW%^s%^CYAN%^s%^YELLOW%^i%^CYAN%^v%^YELLOW%^e%^WHITE%^ hammer");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+query_short()+" %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e %^WHITE%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ as the hilt is removed from "+ETOQCN+" hands",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The hammer %^BOLD%^%^BLACK%^c%^BLUE%^r%^BOLD%^%^BLACK%^a%^BLUE%^c%^BOLD%^%^BLACK%^k%^BLUE%^l%^BOLD%^%^BLACK%^e %^WHITE%^with %^BLUE%^l%^YELLOW%^i%^BLUE%^ghtn%^YELLOW%^i%^BLUE%^ng%^WHITE%^ as the hilt is removed from your hands");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 800){
	tell_room(environment(query_wielded()),"As the hammer connects an electrial charge is released into him.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^brilliant $white light before you strike Test Dummy.");
	tell_object(targ,"");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}

}
