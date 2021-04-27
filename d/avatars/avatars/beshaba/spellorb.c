#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("an orb");
	set_id(({ "orb", "spellorb" }));
	set_short("%^BOLD%^%^MAGENTA%^R%^RESET%^%^RED%^hys%^MAGENTA%^ull%^RED%^'%^MAGENTA%^s %^CYAN%^S%^BOLD%^p%^WHITE%^e%^CYAN%^l%^RESET%^%^CYAN%^l O%^BOLD%^r%^RESET%^%^CYAN%^b%^RESET%^");
	set_obvious_short("%^RESET%^A small crystal %^CYAN%^o%^BOLD%^r%^RESET%^%^CYAN%^b%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This small crystalline sphere is about the size of a man's fist. It has a %^BLUE%^de%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^p bl%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^e hue%^CYAN%^, which lets"
	" out an occasional pulse of l%^BOLD%^i%^WHITE%^g%^CYAN%^h%^RESET%^%^CYAN%^t flashing across the surface. Peering deeply into the orb, faint traceries of some manner of writing is apparent, though the "
	"meaning is %^MAGENTA%^elusive%^CYAN%^.%^RESET%^
"
	);
	set_value(500);
	set_weight(3);
	set_lore("%^RESET%^%^CYAN%^This is possibly one of a handful of spell orbs from ages past. Similar to a mage's spell book, these were the repositories of spells for a Great Master of the arcane. Unlike a typica"
	"l book, though, these were bound to its owner through many long lost rituals that caused their contents to be incomprehensible to any but their master. Little remains from those long ago times, and if"
	" there are any secrets residing in this orb, likely they are lost for good.%^RESET%^
"
	);
    set_property("lore difficulty",40);
	set_heart_beat(1);
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
				tell_object(ETO, "%^RESET%^%^MAGENTA%^A wave of %^CYAN%^l%^BOLD%^i%^WHITE%^g%^CYAN%^h%^RESET%^%^CYAN%^t %^MAGENTA%^passes from one side of the %^CYAN%^o%^BOLD%^r%^RESET%^%^CYAN%^b %^MAGENTA%^to the other.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^MAGENTA%^"+query_short()+"%^RESET%^%^MAGENTA%^'s %^CYAN%^o%^BOLD%^r%^RESET%^%^CYAN%^b %^MAGENTA%^emits a brief flash of %^CYAN%^l%^BOLD%^i%^WHITE%^g%^CYAN%^h%^RESET%^%^CYAN%^t%^MAGENTA%^.%^RESET%^", ({ETO}));
				break;
		}
	}
}