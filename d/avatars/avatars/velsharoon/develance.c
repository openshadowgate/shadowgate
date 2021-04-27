#include <std.h>
inherit "/d/common/obj/weapon/hhlance";

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^Lance of the %^RED%^R%^RESET%^%^RED%^u%^BOLD%^%^b%^RESET%^%^RED%^y %^BOLD%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se%^RESET%^");
	set_id(({ "lance", "ruby rose", "ruby lance", "rose lance", "sune lance" }));
	set_short("%^BOLD%^%^WHITE%^Lance of the %^RED%^R%^RESET%^%^RED%^u%^BOLD%^%^b%^RESET%^%^RED%^y %^BOLD%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Lance of the %^RED%^R%^RESET%^%^RED%^u%^BOLD%^%^b%^RESET%^%^RED%^y %^BOLD%^R%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^The body of this lance has been crafted out of %^CYAN%^pure%^WHITE%^ ivory and polished to a high sh%^RESET%^ee%^BOLD%^%^WHITE%^n. A %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld%^RESET%^"
	"%^ORANGE%^e%^BOLD%^n%^WHITE%^ handle has been attached to the lance, allowing plenty of room for one to get a solid grip. The tip of the lance has been crafted from a %^RED%^r%^RESET%^%^RED%^u%^BOLD%^"
	"b%^RESET%^%^RED%^y%^BOLD%^%^WHITE%^ gem, honed to a fine point. On opposite sides, at the base of the lance, twin %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y red %^BOLD%^r%^RESET%^%^MAGENTA%^o"
	"%^BOLD%^%^RED%^ses%^WHITE%^ have been painted. In full bloom, the %^RESET%^%^BLUE%^deep %^RED%^cr%^BOLD%^i%^RESET%^%^RED%^ms%^BOLD%^o%^RESET%^%^RED%^n%^BOLD%^%^WHITE%^ petals of the %^RED%^r%^RESET%^%"
	"^MAGENTA%^o%^BOLD%^%^RED%^ses%^WHITE%^ unfold to display an aesthetically pleasing image. A %^CYAN%^pure%^YELLOW%^ g%^RESET%^%^ORANGE%^o%^BOLD%^ld band%^WHITE%^ wraps around the ivory base of the lanc"
	"e.%^RESET%^
"
	);
	set_value(0);
	set_lore("%^RESET%^%^MAGENTA%^The Lance of the Ruby Rose is considered by the faith of Sune Firehair as a holy relic amongst Her Knights, the Order of the Rose. It is bestowed upon the holiest and faithful of H"
	"er knights to bring love and beauty to the world by defeating those creatures who are aberrations to the very name of beauty.%^RESET%^
"
	);
    set_property("lore difficulty",18);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 75){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^The %^BOLD%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y tip of the lance %^BOLD%^%^YELLOW%^f%^WHITE%^l%^RED%^a%^RESET%^%^ORANGE%^r%^MAGENTA%^e%^RESET%^s%^RED%^ to life as "+ETOQCN+"%^RESET%^%^RED%^ ram the "+query_short()+" %^RESET%^%^RED%^into "+targ->QCN+"%^RESET%^%^RED%^!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^RED%^The %^BOLD%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y tip of the lance %^BOLD%^%^YELLOW%^f%^WHITE%^l%^RED%^a%^RESET%^%^ORANGE%^r%^MAGENTA%^e%^RESET%^s%^RED%^ to life as you ram the "+query_short()+" %^RESET%^%^RED%^into "+targ->QCN+"%^RESET%^%^RED%^!%^RESET%^");
	tell_object(targ,"%^RESET%^%^RED%^The %^BOLD%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y tip of the lance %^BOLD%^%^YELLOW%^f%^WHITE%^l%^RED%^a%^RESET%^%^ORANGE%^r%^MAGENTA%^e%^RESET%^s%^RED%^ to life as "+ETOQCN+"%^RESET%^%^RED%^ ram the "+query_short()+" %^RESET%^%^RED%^into you!%^RESET%^");
		return roll_dice(3,4)+0;	}

}
