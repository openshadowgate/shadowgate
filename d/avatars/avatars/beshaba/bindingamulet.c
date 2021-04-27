#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("an amulet");
	set_id(({ "amulet", "amulet of binding" }));
	set_short("%^BOLD%^%^WHITE%^A%^YELLOW%^m%^RESET%^%^ORANGE%^u%^WHITE%^%^BOLD%^l%^YELLOW%^e%^RESET%^%^ORANGE%^t %^BOLD%^%^BLACK%^of %^RED%^B%^RESET%^%^ORANGE%^i%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^i%^ORANGE%^n%^BOLD%^%^RED%^g%^RESET%^");
	set_obvious_short("%^RESET%^An intricate %^BOLD%^%^WHITE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^u%^BOLD%^%^WHITE%^l%^YELLOW%^e%^RESET%^%^ORANGE%^t%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This amulet is a small sphere crafted of smooth %^YELLOW%^go%^WHITE%^l%^YELLOW%^d%^RESET%^%^CYAN%^, while threads of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r"
	" %^RESET%^%^CYAN%^twist about and interweave along the circumference. Along those silver bands are minute glyphs and sigils which seem to twist and move before your eyes. A fine silver chain keeps the"
	" amulet in place, suspended near the bearer's heart.%^RESET%^
"
	);
	set_value(5000);
	set_lore("%^BOLD%^%^BLACK%^This is one of many types of temporary vessels for non-corporeal demons, such as the cacodemon. Either bound through ritual magic or inhabited by necessity when a living vessel cannot"
	" be located, these devices allow the demon easier access to the soul of the bearer. These are often used to force a demonic possession, as opposed to a being a willing participant as the demon's avata"
	"r.%^RESET%^
"
	);
    set_property("lore difficulty",30);
    set("chabonus",-2);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",0);
    set_property("empowered",2);
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
		switch(random(2)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^WHITE%^Your vis%^RESET%^ion goe%^BOLD%^%^BLACK%^s blurry... and then %^CYAN%^-%^WHITE%^snaps%^CYAN%^- %^RESET%^back into focus.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+"%^RESET%^%^CYAN%^%^ seems to stare off at something unseen, "+ETO->QP+" eyes taking on an %^RED%^in%^BOLD%^n%^YELLOW%^e%^WHITE%^r %^YELLOW%^f%^RED%^i%^RESET%^%^RED%^re %^CYAN%^as his irises shift between %^GREEN%^c%^BOLD%^o%^CYAN%^l%^RESET%^%^CYAN%^o%^MAGENTA%^r%^RED%^s%^CYAN%^...%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^RESET%^%^RED%^Is it %^BOLD%^hot %^RESET%^%^RED%^here?  You can feel %^RESET%^s%^BOLD%^w%^CYAN%^e%^WHITE%^a%^RESET%^t %^RED%^beading along your brow.%^RESET%^");
				tell_room(EETO, ""+ETOQCN+"%^BOLD%^%^BLACK%^ has a weird %^RESET%^%^MAGENTA%^she%^RED%^e%^MAGENTA%^n %^BOLD%^%^BLACK%^to "+ETO->QP+" skin.. as if subtly %^RESET%^%^BLUE%^ch%^CYAN%^a%^BLUE%^ng%^CYAN%^i%^BLUE%^ng %^BOLD%^%^BLACK%^every time you look away.%^RESET%^", ({ETO}));
				break;
		}
	}
}
