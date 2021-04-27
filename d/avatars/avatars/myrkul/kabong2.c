#include <std.h>
inherit "/d/common/obj/weapon/mclub";

void create(){
	::create();
	set_name("shabby guitar");
	set_id(({ "guitar", "kabonger", "acoustic guitar" }));
	set_short("%^BOLD%^%^CYAN%^Kabonger%^RESET%^%^ORANGE%^, a s%^GREEN%^h%^ORANGE%^a%^BOLD%^%^BLUE%^b%^RESET%^%^ORANGE%^by "+
	"a%^CYAN%^c%^ORANGE%^ou%^MAGENTA%^s%^ORANGE%^tic g%^BOLD%^%^MAGENTA%^u%^RESET%^%^ORANGE%^it%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^s%^GREEN%^h%^ORANGE%^a%^BOLD%^%^BLUE%^b%^RESET%^%^ORANGE%^by a%^CYAN%^c%^ORANGE%^ou%^MAGENTA%^s%^ORANGE%^tic g%^BOLD%^%^MAGENTA%^u%^RESET%^%^ORANGE%^it%^BOLD%^%^CYAN%^a%^RESET%^%^ORANGE%^r%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^The old %^MAGENTA%^guitar%^ORANGE%^ has seen better days. Its made out of a %^YELLOW%^heavy oak%^RESET%^%^ORANGE%^ wood, but looks like it needs some %^GREEN%^varnish%^ORANGE%^. It "
	"also has a ridiculous number of %^BOLD%^%^BLACK%^dents%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^scratches%^RESET%^%^ORANGE%^. Nevertheless, its five strings seem to always be %^BOLD%^%^CYAN%^ in tune%^"
	"RESET%^%^ORANGE%^ and its %^RED%^deep resonance%^ORANGE%^ gives a full, %^BOLD%^%^RED%^b%^MAGENTA%^e%^YELLOW%^a%^CYAN%^u%^BLUE%^t%^BLACK%^i%^WHITE%^f%^CYAN%^u%^MAGENTA%^l%^RED%^ sound%^RESET%^%^ORANGE"
	"%^. Its resilience is extreme, and it is by far the most durable, best sounding instrument a traveling bard could ask for.%^RESET%^
"
	);
	set_value(100);
	set_lore("%^BOLD%^%^CYAN%^This guitar belonged to the famous bard %^GREEN%^Gunderson %^RED%^Five%^GREEN%^-Flagon%^CYAN%^. While clearly an excellent guitarist capable of %^WHITE%^serenading%^CYAN%^ fae folk int"
	"o dancing, he was better known for his %^RED%^epic drinking%^CYAN%^ and equally epic %^RED%^brawling%^CYAN%^. He was known to have a near %^WHITE%^indestructible%^CYAN%^ guitar which he would use to c"
	"lub his enemies into submission with one hand while drinking from a %^GREEN%^flagon%^CYAN%^ with the other. As far as %^BLUE%^improvised weapons%^CYAN%^ go, this one is fantastic in that it is sure to"
	" go unnoticed when %^MAGENTA%^playing%^CYAN%^ to the crowd, but always leaves an %^BOLD%^%^BLACK%^impression%^CYAN%^ on the way out.%^YELLOW%^ And best of all, it sounds great!!%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^YELLOW%^The "+query_short()+" sounds a thunderous %^RED%^KA%^GREEN%^B%^RED%^OOO%^CYAN%^N%^RED%^NNNG%^BLUE%^G%^RED%^GG%^YELLOW%^ as "+ETOQCN+" beats "+targ->QCN+" over the head!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The guitar sounds a thunderous %^RED%^KA%^GREEN%^B%^RED%^OOO%^CYAN%^N%^RED%^NNNG%^BLUE%^G%^RED%^GG%^YELLOW%^ as you beat your enemy over the head!!%^RESET%^");
	tell_object(targ,"%^YELLOW%^YOUR %^WHITE%^SKULL%^YELLOW%^ RINGS LIKE CRAZY as "+ETOQCN+" beats you over the head with a guitar!!%^RESET%^");
		return roll_dice(1,10)+20;	}

}
