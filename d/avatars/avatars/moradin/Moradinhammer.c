#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create(){
	::create();
	set_name("Soulhammer");
	set_id(({ "hammer", "soulhammer", "warhammer" }));
	set_short("%^BOLD%^%^RED%^S%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^l%^YELLOW%^h%^RESET%^%^ORANGE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^m%^YELLOW%^e%^RESET%^%^ORANGE%^r %^BOLD%^%^BLACK%^of %^RESET%^%^ORANGE%^M%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^d%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^S%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^l%^YELLOW%^h%^RESET%^%^ORANGE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^m%^YELLOW%^e%^RESET%^%^ORANGE%^r %^BOLD%^%^BLACK%^of %^RESET%^%^ORANGE%^M%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^d%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This massive two handed %^RESET%^%^CYAN%^hammer%^BOLD%^%^BLACK%^ is the legendary %^BOLD%^%^RED%^S%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^RED%^l%^YELLOW%^h%^RESET%^%^ORANGE%^"
	"a%^YELLOW%^m%^RESET%^%^ORANGE%^m%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^, which %^RESET%^%^ORANGE%^M%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^d%^YELLOW%^i%^RESET%^%^ORANGE%^"
	"n%^BOLD%^%^BLACK%^ used to forge the %^RESET%^%^ORANGE%^world%^BOLD%^%^BLACK%^ and the race of %^RESET%^%^WHITE%^dwarves%^BOLD%^%^BLACK%^. The long %^BOLD%^%^WHITE%^diamond%^BOLD%^%^BLACK%^ handle of "
	"the hammer is wrapped in leather from the wings of a %^RESET%^%^WHITE%^d%^BOLD%^%^BLACK%^ee%^RESET%^%^WHITE%^p %^BOLD%^%^BLACK%^d%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^g%^BOLD%^%^BLACK"
	"%^o%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^, and the glistening and massive head of the hammer is made of the purest %^BOLD%^%^WHITE%^m%^BOLD%^%^BLACK%^i%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^h%^BOLD%^%^BLAC"
	"K%^r%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^l %^BOLD%^%^BLACK%^and inscribed with dwarven %^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s%^BOLD%^%^BLACK%^ of %^MAGENTA%^p%^"
	"RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r%^BOLD%^%^BLACK%^.%^RESET%^

"	);
	set_value(100000);
	set_lore("This hammer was used by the dwarven God Moradin to forge the world and the dwarven race. It is said each blow of the hammer can fell a dragon.

");
	set_property("lore difficulty",25);
	set_item_bonus("wisdom",5);
	set_item_bonus("constitution",5);
	set_item_bonus("healing",50);
	set_item_bonus("caster level",10);
	set_property("enchantment",30);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^Dwarven %^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s%^BOLD%^%^BLACK%^ of %^MAGENTA%^p%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ glows brightly as "+ETOQCN+" wields the "+query_short()+"",ETO);
	tell_object(ETO,"owner:  %^BOLD%^%^BLACK%^Powerfull %^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s%^BOLD%^%^BLACK%^ glows with raw %^MAGENTA%^p%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ of %^WHITE%^creation%^BOLD%^%^BLACK%^ as you wield the "+query_short()+"");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The %^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s%^BOLD%^%^BLACK%^ of %^MAGENTA%^p%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r %^YELLOW%^dims%^BOLD%^%^BLACK%^ on "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLACK%^as he sets it aside.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s%^BOLD%^%^BLACK%^ of %^MAGENTA%^p%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r %^YELLOW%^dim %^BOLD%^%^BLACK%^as you set the "+query_short()+" %^BOLD%^%^BLACK%^aside");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^ORANGE%^"+ETOQCN+" %^BOLD%^%^CYAN%^slam%^RESET%^%^ORANGE%^ the "+query_short()+" %^RESET%^%^ORANGE%^into the e%^BOLD%^%^BLACK%^a%^RESET%%^ORANGE%^rth and a %^BOLD%^%^BLACK%^massive %^YELLOW%^e%^BOLD%^%^BLACK%^a%^YELLOW%^r%^BOLD%^%^BLACK%^t%^YELLOW%^h%^BOLD%^%^BLACK%^q%^YELLOW%^u%^YELLOW%^a%^BOLD%^%^BLACK%^k%^YELLOW%^e %^RESET%^%^WHITE%^throws%^RESET%^%^ORANGE%^ "+targ->QCN+" to the ground",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^ORANGE%^You %^BOLD%^%^CYAN%^slam%^RESET%^%^ORANGE%^ the "+query_short()+" %^RESET%^%^ORANGE%^into the e%^BOLD%^%^BLACK%^a%^RESET%%^ORANGE%^rth and a %^BOLD%^%^BLACK%^massive %^YELLOW%^e%^BOLD%^%^BLACK%^a%^YELLOW%^r%^BOLD%^%^BLACK%^t%^YELLOW%^h%^BOLD%^%^BLACK%^q%^YELLOW%^u%^YELLOW%^a%^BOLD%^%^BLACK%^k%^YELLOW%^e %^RESET%^%^WHITE%^throws%^RESET%^%^ORANGE%^ your foe to the ground");
	tell_object(targ,"%^RESET%^%^ORANGE%^"+ETOQCN+" %^BOLD%^%^CYAN%^slam%^RESET%^%^ORANGE%^ the "+query_short()+" %^RESET%^%^ORANGE%^into the e%^BOLD%^%^BLACK%^a%^RESET%%^ORANGE%^rth and a %^BOLD%^%^BLACK%^massive %^YELLOW%^e%^BOLD%^%^BLACK%^a%^YELLOW%^r%^BOLD%^%^BLACK%^t%^YELLOW%^h%^BOLD%^%^BLACK%^q%^YELLOW%^u%^YELLOW%^a%^BOLD%^%^BLACK%^k%^YELLOW%^e %^RESET%^%^WHITE%^throws%^RESET%^%^ORANGE%^ you to the ground");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}

}
