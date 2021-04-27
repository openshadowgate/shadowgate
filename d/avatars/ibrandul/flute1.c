#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RESET%^%^GREEN%^m%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^l%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^BOLD%^%^GREEN%^dy%^RESET%^%^GREEN%^ o%^RESET%^%^WHITE%^f%^RESET%^%^BOLD%^%^GREEN%^ a %^RESET%^%^GREEN%^th%^RESET%^%^BOLD%^%^GREEN%^ou%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^nd no%^RESET%^%^BOLD%^%^GREEN%^t%^RESET%^%^WHITE%^e%^RESET%^%^GREEN%^s%^RESET%^");
	set_id(({ "flute", "thousand notes", "jade flute" }));
	set_short("%^RESET%^%^GREEN%^m%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^l%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^BOLD%^%^GREEN%^dy%^RESET%^%^GREEN%^ o%^RESET%^%^WHITE%^f%^RESET%^%^BOLD%^%^GREEN%^ a %^RESET%^%^GREEN%^th%^RESET%^%^BOLD%^%^GREEN%^ou%^RESET%^%^WHITE%^s%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^nd no%^RESET%^%^BOLD%^%^GREEN%^t%^RESET%^%^WHITE%^e%^RESET%^%^GREEN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^ja%^RESET%^%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^g%^RESET%^%^WHITE%^e%^RESET%^%^GREEN%^d %^RESET%^%^BOLD%^%^GREEN%^ja%^RESET%^%^WHITE%^d%^RESET%^%^GREEN%^e fl%^RESET%^%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^te%^RESET%^");
	set_long("%^RESET%^%^GREEN%^Formed from a single piece of %^BOLD%^raw jade %^RESET%^%^GREEN%^that has been carved into a tube, this flute is an amazing piece of craftsmanship. As the %^ORANGE%^l%^YELLOW%^ig%^WHITE%^h%^YELLOW%^t %^RESET%^%^GREEN%^travels through the flute, it reflects and refracts the light into a th%^BOLD%^ou%^RESET%^%^GREEN%^s%^BOLD%^%^WHITE%^a%^GREEN%^n%^RESET%^%^GREEN%^d "
"sh%^BOLD%^a%^RESET%^%^GREEN%^r%^RESET%^d%^GREEN%^s. The mouthpiece has been carved and smoothed, and each finger hole is meticulously %^BOLD%^%^BLACK%^carved%^RESET%^%^GREEN%^. The flute extends farther then it should however, and a thin strip of%^MAGENTA%^ silk %^GREEN%^has been tied to the end, as if you could hold it. All along the length of the flute are %^BOLD%^%^BLACK%^engravings %^RESET%^%^GREEN%^and %^BOLD%^%^BLACK%^pictographs%^RESET%^%^GREEN%^.%^RESET%^\n");
	set_weight(3);
	set_value(10000);
	set_lore("%^CYAN%^The melody of a thousand notes was crafted by an elven artificer a thousand years ago. It is said that an avatar of Oghma inhabited the elfs body during its creation, filling the elfs head with every song known to the planes. The artifact moved from bard to bard, and any who held it seemed to become the most renowned and famous, always creating masterpieces. "
"The flute fell into obscurity when it fell into the hands of a young man during a competition in the city of Asgard. To everyones shock the man lost the competition to another bard with a mundane harp. He swore he would find the most complete and perfect music and disappeared.%^RESET%^");
	set_property("lore difficulty",15);
	set_type("bludgeoning");
	set_prof_type("instrument");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^As "+ETOQCN+"%^RESET%^%^CYAN%^ wraps their hands around the "+query_short()+"%^RESET%^%^CYAN%^, it %^BOLD%^glows%^RESET%^%^CYAN%^ softly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You wrap your hands around the "+query_short()+"%^RESET%^%^CYAN%^, your head filling with a soft melody.%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+"%^RESET%^%^CYAN%^ sets the flute aside, looking around with a smile.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You set the "+query_short()+"%^RESET%^%^CYAN%^ aside, the world becomes silent again, but you can still remember the melody.%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^"+ETOQCN+"%^RESET%^%^CYAN%^ steps back and places the "+query_short()+"%^RESET%^%^CYAN%^ to their lips, you hear nothing, but "+targ->QCN+"%^RESET%^%^CYAN%^ shudders %^RED%^%^BOLD%^violently%^RESET%^%^CYAN%^.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^CYAN%^Stepping away from the battle, you place the "+query_short()+"%^RESET%^%^CYAN%^ to your lips and play a %^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^e%^BOLD%^l%^CYAN%^o%^RESET%^%^CYAN%^d%^BOLD%^%^MAGENTA%^y%^RESET%^%^CYAN%^, "+targ->QCN+"%^RESET%^%^CYAN%^ shudders violently.%^RESET%^");
	tell_object(targ,"%^RESET%^%^CYAN%^"+ETOQCN+"%^RESET%^%^CYAN%^ steps back and as they place the "+query_short()+"%^RESET%^%^CYAN%^ to their lips, your head is filled with a %^MAGENTA%^t%^BOLD%^h%^CYAN%^u%^RESET%^%^MAGENTA%^n%^BOLD%^d%^RESET%^%^MAGENTA%^e%^BOLD%^ri%^RESET%^%^CYAN%^n%^BOLD%^%^MAGENTA%^g m%^RESET%^%^MAGENTA%^e%^BOLD%^l%^CYAN%^o%^RESET%^%^CYAN%^d%^BOLD%^%^MAGENTA%^y%^RESET%^%^CYAN%^, your ears ring and you %^BLACK%^%^BOLD%^black out%^RESET%^%^CYAN%^ for a moment.%^RESET%^");
	targ->set_paralyzed(roll_dice(1,6)+3,"You're trying to regain your senses!");
	return 0;	}
}

int is_instrument(){return 1;}