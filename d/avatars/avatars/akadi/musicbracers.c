#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^s%^RESET%^il%^BOLD%^%^WHITE%^v%^RESET%^er%^BOLD%^%^BLACK%^y b%^BOLD%^%^WHITE%^ra%^RESET%^c%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^s%^RESET%^");
	set_id(({ "bracers" }));
	set_short("%^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^r br%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^rs of the %^BOLD%^%^BLACK%^M%^WHITE%^i%^RESET%^n%^CYAN%^st%^RESET%^r%^BOLD%^e%^BLACK%^l%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^s%^RESET%^il%^BOLD%^%^WHITE%^v%^RESET%^er%^BOLD%^%^BLACK%^y b%^BOLD%^%^WHITE%^ra%^RESET%^c%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^s%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Musical notes dance across the %^BOLD%^%^BLACK%^s%^WHITE%^il%^RESET%^v%^BOLD%^er%^BOLD%^%^BLACK%^y%^RESET%^ surface of these unusual bracers. The notes are imprinted on straight lines carefully etched into the %^BOLD%^%^WHITE%^sh%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^ng %^RESET%^metal, resembling pages of sheet music. The occasional note has been adorned with a highly polished %^BOLD%^di%^RESET%^a%^CYAN%^m%^RESET%^o%^BOLD%^nd%^RESET%^ with puts forth a %^BOLD%^%^RED%^p%^RESET%^%^RED%^r%^YELLOW%^i%^RESET%^%^ORANGE%^s%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^i%^BOLD%^%^CYAN%^c%^RESET%^ gl%^BOLD%^o%^RESET%^w when struck by light. Not only are the bracers quite stylish but they also offer a fair amount of protection. The insides have been lined with p%^BOLD%^al%^RESET%^e %^BOLD%^%^BLUE%^blue%^RESET%^ silk to give added comfort to the wearer.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(2500);
	set_lore(
@AVATAR
%^BOLD%^Long ago, a daughter of a king set off to make her own living as a traveling minstrel because her true love was singing and performing for others. Her father was not pleased with the decision but he loved his daughter and did not wish to see her disappointed, so he allowed her to leave his kingdom, granting her the bracers as a farewell gift. They are said to be enchanted with a powerful magic that can aid the owner in times of trouble. The bracers were eventually lost, although nobody knows exactly when or why. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",13);
	set_type("bracer");
	set_limbs(({ "right arm", "left arm" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+"'s bracers begin to %^BOLD%^hum%^RESET%^%^CYAN%^ softly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The bracers hum beautifully as you wear them.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The musical notes briefly %^BOLD%^glow%^RESET%^%^CYAN%^ and then dim as you remove the bracers.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 350){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The humming of "+ETOQCN+"'s%^BOLD%^%^WHITE%^ bracers mesmerizes "+who->QCN+"%^BOLD%^%^WHITE%^ into a daze!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The bracers begin to hum hypnotically, %^RESET%^%^MAGENTA%^mesmerizing%^BOLD%^%^WHITE%^ "+who->QCN+"%^RESET%^%^BOLD%^%^WHITE%^ into a daze!");
	tell_object(who,"%^BOLD%^%^WHITE%^A %^RESET%^%^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^a%^MAGENTA%^u%^BOLD%^%^BLACK%^nt%^RESET%^%^MAGENTA%^I%^CYAN%^n%^BOLD%^%^BLACK%^g%^BOLD%^%^WHITE%Y melody holds you momentarily captivated!%^RESET%^");
		who->set_paralyzed(random(3));
return damage;	}
}