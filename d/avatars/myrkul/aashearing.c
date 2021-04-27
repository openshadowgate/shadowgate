// enchant removed so he can continue to wear on the new equip system. N, 1/13.
#include <std.h>
inherit "/d/common/obj/jewelry/circlet";

void create(){
	::create();
	set_name("earing");
	set_id(({ "feathers", "thong", "cord" }));
	set_short("%^BOLD%^%^RED%^ph%^RESET%^%^RED%^o%^BOLD%^enix feathers%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^ph%^RESET%^%^RED%^o%^BOLD%^enix feathers%^RESET%^");
	set_long("%^BOLD%^%^RED%^A trio of fiery ph%^RESET%^%^RED%^o%^BOLD%^enix feathers have been lashed together by their quills with a %^RESET%^%^RED%^crimson%^BOLD%^ leather thong. They must be the tail feathers b"
	"ecause they are quite long and beautiful, mostly red but they have traces of %^CYAN%^blue%^RED%^ and %^YELLOW%^yellow%^RED%^ in each one. They aren't flaming anymore, but they are still quite beautifu"
	"l.%^RESET%^
"
	);
	set_value(2000);
	set_lore("%^BOLD%^%^GREEN%^The elf lord, %^YELLOW%^Aashaenael%^GREEN%^, crafted these once %^RESET%^%^RED%^burning%^BOLD%^%^GREEN%^ feathers of a %^RED%^phoenix%^GREEN%^, a creature of living %^RED%^f%^YELLOW%^"
	"l%^RED%^a%^YELLOW%^m%^RED%^e.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_heart_beat(1);
	set_size(2);
//	set_property("enchantment",1);
}

void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
         if(random(1000) > 998) 
	 {
		switch(random(1)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^CYAN%^The "+query_short()+" %^CYAN%^grows hot in your hair, and you feel the%^RED%^ fire%^CYAN%^ of the %^RED%^ph%^YELLOW%^o%^RED%^enix%^CYAN%^ in your heart.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^The "+query_short()+" %^BOLD%^%^CYAN%^worn in the hair of "+ETOQCN+" seems to %^RED%^glow%^CYAN%^ and %^RED%^f%^YELLOW%^l%^RED%^icker%^CYAN%^ with an inner %^RED%^f%^YELLOW%^i%^RED%^re!%^RESET%^", ({ETO}));
				break;
		}
	}
}
