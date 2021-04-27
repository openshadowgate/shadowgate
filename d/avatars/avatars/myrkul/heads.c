#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("shrunkenheads");
	set_id(({ "shrunken heads", "heads", "necklace", "shrunken heads necklace" }));
	set_short("%^RESET%^%^ORANGE%^N%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^cklace%^RESET%^%^ORANGE%^ %^BOLD%^%^RED%^o%^RESET%^%^ORANGE%^f %^BOLD%^%^MAGENTA%^S%^RED%^h%^RESET%^%^RED%^r%^MAGENTA%^u%^BOLD%^n%^RED%^k%^RESET%^%^RED%^e%^MAGENTA%^n%^RESET%^%^ORANGE%^ H%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^ads%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^N%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^cklace%^RESET%^%^ORANGE%^ %^BOLD%^%^RED%^o%^RESET%^%^ORANGE%^f %^BOLD%^%^MAGENTA%^S%^RED%^h%^RESET%^%^RED%^r%^MAGENTA%^u%^BOLD%^n%^RED%^k%^RESET%^%^RED%^e%^MAGENTA%^n%^RESET%^%^ORANGE%^ H%^BOLD%^%^RED%^e%^RESET%^%^ORANGE%^ads%^RESET%^");
	set_long("The necklace is a %^RESET%^%^ORANGE%^sturdy leather cord%^RESET%^ upon which %^YELLOW%^three %^RED%^shrunken heads%^RESET%^ have been attached. Each head is about the size of a %^BOLD%^%^MAGENTA%^grap"
	"efruit%^RESET%^. Although withered with age, and also warped from shrinking, the faces are still recognizable.                                                                                          "
	"                                %^RESET%^ The first head is of a %^BOLD%^%^BLACK%^d%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLACK%^in%^BOLD%^%^BLACK%^g%^RESET%^%^CYAN%^u%^BOLD%^"
	"%^BLACK%^i%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^d s%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^ble %^RESET%^%^ORANGE%^haired %^RESET%^male%^ORANGE%^ human.%^RESET%^ The second "
	"head is of a %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^ery%^RESET%^ haired%^BOLD%^%^GREEN%^ human%^RESET%^ with %^BOLD%^%^WHITE%^sil%^RESET%^v%^BOLD%^er%^RESET%^ eyes. The alst head is of an %^YELLOW%^a%^RESE"
	"T%^%^ORANGE%^r%^YELLOW%^i%^RESET%^%^ORANGE%^s%^YELLOW%^t%^RESET%^%^ORANGE%^o%^YELLOW%^c%^RESET%^%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^t%^YELLOW%^i%^RESET%^%^ORANGE%^c%^RESET%^, middle-aged human ma"
	"n with %^BOLD%^%^BLACK%^midnight black%^RESET%^ hair. %^BOLD%^%^MAGENTA%^What is truly %^BLACK%^hideous%^MAGENTA%^ is that it seems that the heads can still %^YELLOW%^talk!%^RESET%^
"	);
	set_value(1);
	set_lore("%^YELLOW%^Once upon a time there was a disgusting %^GREEN%^goblin%^YELLOW%^ named %^BLACK%^Tuurghol%^YELLOW%^ who was also a mighty sorceror. He defeated many enemies. But some enemies were deserving "
	"of a fate worse than death. He cut off the heads of his foes and shrunk their heads, thus trapping the spirits. %^BLACK%^Tuurghol%^YELLOW%^ now wears the necklace as a warning to others of ever crossi"
	"ng him. The heads on the necklace are: %^BLACK%^Zathery%^YELLOW%^ a distinguished sable haired male human, %^RED%^Teroai%^YELLOW%^ a fiery haired human with silver eyes, and %^CYAN%^Bentalf%^YELLOW%^ "
	"an aristocratic, middle-aged human with midnight black hair.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_heart_beat(1);
	set_size(1);
	set_property("enchantment",7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^All the heads on "+query_short()+" scream in horror and "+ETOQCN+" puts on the necklace!%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^All the heads on "+query_short()+" scream in horror!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^The heads on "+query_short()+" quit bitching as "+ETOQCN+" removes the necklace.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^The heads on "+query_short()+" quit bitching as the necklace is removed.%^RESET%^");
	return 1;
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
		switch(random(3)) 
		{
			case 0:
				tell_object(ETO, "%^YELLOW%^The %^BLACK%^Z%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^h%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^y%^RED%^ head%^YELLOW%^ on "+query_short()+" worn by "+ETOQCN+" says:%^BOLD%^%^CYAN%^ Release me foul creature, by %^YELLOW%^Tyr%^CYAN%^ I shall bring you to justice!%^RESET%^");
				tell_room(EETO, "%^YELLOW%^The %^BLACK%^Z%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^h%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^y%^RED%^ head%^YELLOW%^ on "+query_short()+" worn by "+ETOQCN+" says:%^BOLD%^%^CYAN%^ Release me foul creature, by %^YELLOW%^Tyr%^CYAN%^ I shall bring you to justice!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^YELLOW%^The %^RESET%^%^ORANGE%^B%^YELLOW%^e%^RESET%^%^ORANGE%^n%^YELLOW%^t%^RESET%^%^ORANGE%^a%^YELLOW%^l%^RESET%^%^ORANGE%^f%^BOLD%^ %^RED%^head%^YELLOW%^ on "+query_short()+" worn by "+ETOQCN+" says:%^BOLD%^%^CYAN%^ Thou foul %^BLACK%^villain%^CYAN%^, release me or feel the %^WHITE%^c%^CYAN%^h%^BLUE%^i%^WHITE%^l%^CYAN%^l of %^WHITE%^A%^CYAN%^u%^BLUE%^r%^WHITE%^i%^CYAN%^l%^BLUE%^'s%^CYAN%^ f%^WHITE%^u%^BLUE%^r%^CYAN%^y!!%^RESET%^");
				tell_room(EETO, "%^YELLOW%^The %^RESET%^%^ORANGE%^B%^YELLOW%^e%^RESET%^%^ORANGE%^n%^YELLOW%^t%^RESET%^%^ORANGE%^a%^YELLOW%^l%^RESET%^%^ORANGE%^f%^BOLD%^ %^RED%^head%^YELLOW%^ on "+query_short()+" worn by "+ETOQCN+" says:%^BOLD%^%^CYAN%^ Thou foul %^BLACK%^villain%^CYAN%^, release me or feel the %^WHITE%^c%^CYAN%^h%^BLUE%^i%^WHITE%^l%^CYAN%^l of %^WHITE%^A%^CYAN%^u%^BLUE%^r%^WHITE%^i%^CYAN%^l%^BLUE%^'s%^CYAN%^ f%^WHITE%^u%^BLUE%^r%^CYAN%^y!!%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^YELLOW%^The %^RED%^T%^YELLOW%^e%^RED%^r%^RESET%^%^RED%^o%^BOLD%^a%^YELLOW%^i %^RED%^head%^YELLOW%^ on "+query_short()+" worn by "+ETOQCN+" says:%^BOLD%^%^CYAN%^ Let me go, or you shall burn in %^RED%^K%^RESET%^%^RED%^o%^BOLD%^%^RED%^s%^RESET%^%^RED%^s%^BOLD%^u%^RESET%^%^RED%^t%^BOLD%^h'%^RESET%^%^RED%^s%^BOLD%^%^CYAN%^ eternal %^RESET%^%^RED%^f%^MAGENTA%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RED%^!!!%^RESET%^");
				tell_room(EETO, "%^YELLOW%^The %^RED%^T%^YELLOW%^e%^RED%^r%^RESET%^%^RED%^o%^BOLD%^a%^YELLOW%^i %^RED%^head%^YELLOW%^ on "+query_short()+" worn by "+ETOQCN+" says:%^BOLD%^%^CYAN%^ Let me go, or you shall burn in %^RED%^K%^RESET%^%^RED%^o%^BOLD%^%^RED%^s%^RESET%^%^RED%^s%^BOLD%^u%^RESET%^%^RED%^t%^BOLD%^h'%^RESET%^%^RED%^s%^BOLD%^%^CYAN%^ eternal %^RESET%^%^RED%^f%^MAGENTA%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RED%^!!!%^RESET%^", ({ETO}));
				break;
		}
	}
}