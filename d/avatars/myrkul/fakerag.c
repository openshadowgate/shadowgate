#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^R%^RESET%^%^RED%^a%^BOLD%^%^RED%^g%^BLACK%^n%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^o%^BOLD%^k%^BLACK%^ Destroyer of Worlds%^RESET%^");
	set_id(({ "ragnarok", "sword", "long sword", "longsword" }));
	set_short("%^BOLD%^%^BLACK%^R%^RESET%^%^RED%^a%^BOLD%^%^RED%^g%^BLACK%^n%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^o%^BOLD%^k%^BLACK%^ Destroyer of Worlds%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^an %^RED%^ominous%^BLACK%^ sword as black as co%^RED%^a%^BLACK%^l%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^An %^RED%^a%^BLACK%^st%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^n%^RED%^i%^BLACK%^sh%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^RED%^a%^BOLD%^u%^RESET%^%^RED%^r%^BOLD%^a%^BLACK%^ of terri"
	"ble %^RED%^po%^RESET%^%^RED%^w%^BOLD%^er%^BLACK%^ radiates from this r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RED%^a%^BLACK%^rk%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^bl%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ sw%^R"
	"ED%^o%^BLACK%^rd. Its double-edged coal black blade is wrought with %^RED%^gl%^RESET%^%^RED%^o%^BOLD%^w%^RESET%^%^RED%^i%^BOLD%^ng %^RESET%^%^RED%^d%^BOLD%^e%^BLACK%^m%^RED%^o%^BLACK%^n%^RESET%^%^RED%"
	"^i%^BOLD%^c r%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^ that p%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^ls%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^te and cr%^RED%^a%^BLACK%^ckl%^RED%^e%^B"
	"LACK%^ as if in anticipation of %^RED%^violence%^BLACK%^. Traveling up the center of the blade is the %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n%^BLACK%^ line of the %^RESET%^%^RED"
	"%^blood%^BOLD%^%^BLACK%^ groove, ve%^RED%^i%^BLACK%^ns of it branching off throughout the flat on both sides. The blade flows smoothly into the j%^RED%^a%^BLACK%^gg%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d "
	"guard which has been forged in the semblance of a %^RESET%^%^RED%^l%^BOLD%^ee%^RESET%^%^RED%^r%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^o%^BOLD%^n%^RESET%"
	"^%^RED%^i%^BOLD%^%^BLACK%^c v%^RED%^i%^BLACK%^s%^RED%^a%^BLACK%^g%^RED%^e%^BLACK%^. A smoky black essence wafts from its empty eyes and fanged maw. Cool %^RESET%^%^RED%^d%^BOLD%^e%^RESET%^%^RED%^m%^BO"
	"LD%^o%^RESET%^%^RED%^nsk%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^ h%^RED%^i%^BLACK%^d%^RED%^e%^BLACK%^ wraps the hilt providing a comfortable grip. Resting at the bottom of the hilt, a fractured obs"
	"%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^an orb makes up the pommel, a faint %^RESET%^%^RED%^red l%^BOLD%^i%^RESET%^%^RED%^ght %^BOLD%^burning%^BOLD%^%^BLACK%^ from between the web of cracks.%^RESET%^
"
	);
	set_value(10000);
	set_lore("This is rumored to be the most destructive weapon ever created. The story goes the sword was born with the world and its destiny is linked with the end of the world. The exact metal or maker is not kn"
	"own, but the sword was first seen in the possession of a demon known as Qualtatoh. Rumors say Klauth banished the demon from the prime material plane and took the sword as trophy.
"
	);
    set_property("lore difficulty",10);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ muscles swell and his eyes flash red as he grips the hilt of the blade!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The power of the %^RED%^demonic%^BLACK%^ sword surges into your veins, swelling the muscles of your arm and filling you with an unnatural strength!                    %^RESET%^%^RED%^You can feel your eyes change and your vision is tinted a deep red as the essence of the lower planes seeps into your very soul!%^RESET%^");
	ETO->add_attack_bonus(-5);
	ETO->add_damage_bonus(-10);
	ETO->set_property("magic resistance",-50);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^Someone's muscles return to normal and the %^RED%^light%^GREEN%^ fades from his eyes as he releases the hilt of the sword.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The sword hums for a moment and then grows cool to the touch as you release the hilt.%^BOLD%^%^RED%^                                                                  You blink your eyes as the eerie red light seeps from your vision.%^RESET%^");
	ETO->add_attack_bonus(5);
	ETO->add_damage_bonus(10);
	ETO->set_property("magic resistance",50);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ strikes "+targ->QCN+"%^BOLD%^%^RED%^ valiantly with a %^GREEN%^mighty blow%^BOLD%^%^RED%^, but at the last moment, the blade goes all %^MAGENTA%^f%^YELLOW%^l%^RESET%^%^MAGENTA%^o%^BOLD%^p%^YELLOW%^p%^MAGENTA%^y%^CYAN%^!!!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You strike "+query_short()+"%^BOLD%^%^RED%^ valiantly with a %^GREEN%^mighty blow%^BOLD%^%^RED%^, but at the last moment, your blade goes all %^MAGENTA%^f%^YELLOW%^l%^RESET%^%^MAGENTA%^o%^BOLD%^p%^YELLOW%^p%^MAGENTA%^y%^CYAN%^!!!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"%^BOLD%^%^RED%^ strikes you%^BOLD%^%^RED%^ valiantly with a %^GREEN%^mighty blow%^BOLD%^%^RED%^, but at the last moment, the blade goes all %^MAGENTA%^f%^YELLOW%^l%^RESET%^%^MAGENTA%^o%^BOLD%^p%^YELLOW%^p%^MAGENTA%^y%^CYAN%^!!!%^RESET%^");
		return roll_dice(1,1)+-100;	}

}
