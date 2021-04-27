#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";

void create(){
	::create();
	set_name("Tee Silver Dragon");
	set_id(({ "word", "twohanded sword", "two-handed sword", "dragon" }));
	set_short("%^BOLD%^%^WHITE%^T%^BLACK%^h%^BOLD%^%^WHITE%^e %^BLACK%^S%^BOLD%^%^WHITE%^i%^BLACK%^l%^BOLD%^%^WHITE%^v%^BLACK%^e%^BOLD%^%^WHITE%^r %^BLACK%^D%^BOLD%^%^WHITE%^r%^BLACK%^a%^BOLD%^%^WHITE%^g%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^BLACK%^m%^BOLD%^%^WHITE%^a%^BLACK%^g%^BOLD%^%^WHITE%^n%^BLACK%^i%^BOLD%^%^WHITE%^f%^BLACK%^i%^BOLD%^%^WHITE%^c%^BLACK%^e%^BOLD%^%^WHITE%^n%^BLACK%^t %^BOLD%^%^WHITE%^s%^BLACK%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^BOLD%^%^WHITE%^e%^BLACK%^r%^BOLD%^%^WHITE%^e%^BLACK%^d %^BOLD%^%^WHITE%^b%^BLACK%^l%^BOLD%^%^WHITE%^a%^BLACK%^d%^BOLD%^%^WHITE%^e%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This blade is a true %^CYAN%^marvel%^BOLD%^%^WHITE%^. The hilt is shaped like the %^BLUE%^tail%^BOLD%^%^WHITE%^ of a %^BLACK%^d%^WHITE%^r%^BLACK%^a%^WHITE%^g%^BLACK%^o%^WHITE%^n and t"
	"wirls its way up the blade, with the outstretched wings acting as the crossbar. The blade seems to extend from the jaws of the %^BOLD%^%^WHITE%^s%^BLACK%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^BOLD%^%^WHITE%^"
	"e%^BLACK%^r %^BLACK%^d%^WHITE%^r%^BLACK%^a%^WHITE%^g%^BLACK%^o%^WHITE%^n, and looks like it is part of the %^BLACK%^d%^WHITE%^r%^BLACK%^a%^WHITE%^g%^BLACK%^o%^WHITE%^n%^BOLD%^%^WHITE%^s %^BOLD%^%^WHIT"
	"E%^s%^BLACK%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^BOLD%^%^WHITE%^e%^BLACK%^r%^BOLD%^%^WHITE%^y breath weapon. The entire sword is made of the purest shining metal, perhaps %^BLACK%^m%^BOLD%^%^WHITE%^i%^BLAC"
	"K%^t%^BOLD%^%^WHITE%^h%^BLACK%^r%^BOLD%^%^WHITE%^i%^BLACK%^l%^BOLD%^%^WHITE%^ and looks deadly sharp. On the pefect polished blade three words have been carved in common. %^CYAN%^Duty%^WHITE%^, %^YELL"
	"OW%^Obedience%^WHITE%^, %^RED%^Loyalty%^WHITE%^.%^RESET%^
"	);
	set_value(15000);
	set_lore("%^BOLD%^%^WHITE%^The Silver dragon was created by a Tormish wizard to his best friend, Sir Kay Mordellion, a righteous Paladin whom wanted to slay an evil black dragon. The paladin killed the dragon a"
	"nd went on to become one of the grandest Paladins in Torms service. The blade he carried is said to be burried with him.
"	);
	set_property("lore difficulty",15);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" wields the "+query_short()+" %^BOLD%^%^WHITE%^and a %^CYAN%^divine %^YELLOW%^aura %^BOLD%^%^WHITE%^seems to pulse from "+ETOQCN+"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you wield the "+query_short()+" %^BOLD%^%^WHITE%^you can feel the precence of %^YELLOW%^Torm");
	return 1;
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" points the blade at "+targ->QCN+" %^BOLD%^%^WHITE%^and a %^RESET%^%^WHITE%^c%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^n%^BOLD%^%^WHITE%^e of %^BOLD%^%^WHITE%^s%^BLACK%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^BOLD%^%^WHITE%^e%^BLACK%^r%^BOLD%^%^WHITE%^y fr%^CYAN%^o%^BOLD%^%^WHITE%^st %^CYAN%^fr%^BOLD%^%^WHITE%^e%^CYAN%^e%^BOLD%^%^WHITE%^z%^CYAN%^e%^BOLD%^%^WHITE%^s "+targ->QCN+" in place",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You point the blade at "+targ->QCN+" %^BOLD%^%^WHITE%^and a %^RESET%^%^WHITE%^c%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^n%^BOLD%^%^WHITE%^e of %^BOLD%^%^WHITE%^s%^BLACK%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^BOLD%^%^WHITE%^e%^BLACK%^r%^BOLD%^%^WHITE%^y fr%^CYAN%^o%^BOLD%^%^WHITE%^st %^CYAN%^fr%^BOLD%^%^WHITE%^e%^CYAN%^e%^BOLD%^%^WHITE%^z%^CYAN%^e%^BOLD%^%^WHITE%^s "+targ->QCN+" in place");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" points the blade at you and a %^RESET%^%^WHITE%^c%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^n%^BOLD%^%^WHITE%^e of %^BOLD%^%^WHITE%^s%^BLACK%^i%^BOLD%^%^WHITE%^l%^BLACK%^v%^BOLD%^%^WHITE%^e%^BLACK%^r%^BOLD%^%^WHITE%^y fr%^CYAN%^o%^BOLD%^%^WHITE%^st %^CYAN%^fr%^BOLD%^%^WHITE%^e%^CYAN%^e%^BOLD%^%^WHITE%^z%^CYAN%^e%^BOLD%^%^WHITE%^s you in place");
		targ->set_paralyzed(roll_dice(13,0)+0);
return 0;	}

}
