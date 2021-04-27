#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("Strand of the Weave");
	set_id(({ "ring", "strand", "strand of the weave" }));
	set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^t%^YELLOW%^r%^RESET%^%^ORANGE%^a%^YELLOW%^n%^RESET%^%^ORANGE%^d%^BOLD%^%^BLUE%^ of the %^MAGENTA%^W%^RESET%^%^MAGENTA%^e%^CYAN%^a%^BOLD%^%^MAGENTA%^v%^RESET%^%^MAGENTA%^e%^RESET%^");
	set_obvious_short("%^YELLOW%^R%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^BLUE%^ of %^MAGENTA%^P%^RESET%^%^MAGENTA%^u%^CYAN%^r%^BOLD%^%^MAGENTA%^e %^RESET%^%^MAGENTA%^M%^CYAN%^a%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^i%^CYAN%^c%^RESET%^");
	set_long("%^YELLOW%^When observed directly, the ring seems to %^CYAN%^s%^RESET%^%^CYAN%^h%^BOLD%^i%^RESET%^%^CYAN%^m%^BOLD%^m%^RESET%^%^CYAN%^e%^BOLD%^r%^YELLOW%^ and move with %^MAGENTA%^s%^RESET%^%^MAGENTA%^h"
	"%^CYAN%^i%^BLUE%^f%^BOLD%^t%^CYAN%^i%^MAGENTA%^n%^RESET%^%^MAGENTA%^g%^YELLOW%^ colors. It is totally %^WHITE%^ethereal%^YELLOW%^. Nevertheless, the magic of the ring is unmistakable. It is entirely m"
	"ade of %^RESET%^%^MAGENTA%^m%^CYAN%^a%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^i%^CYAN%^c%^YELLOW%^, which is obvious to even the most untrained eye. It holds raw magical potential.%^RESET%^
"	);
	set_value(100000);
	set_lore("%^YELLOW%^The historical roots of this ring are lost in time to all but the %^RED%^greatest%^YELLOW%^ keepers of lore. The ring itself is a testament to the horrible %^CYAN%^truth%^YELLOW%^ of the %^R"
	"ED%^Godswar%^YELLOW%^. During this terrible time, the Gods rose up against themselves in full power and nearly cracked the world with their battles. One of the greatest clashes was the battle of %^MAG"
	"ENTA%^M%^RESET%^%^MAGENTA%^y%^BOLD%^stra%^YELLOW%^ and the god of dead, %^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^YELLOW%^. It is said that the %^BLACK%^Scythe of %^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^YELLOW%^ cut "
	"a single locke of hair from %^MAGENTA%^M%^RESET%^%^MAGENTA%^y%^BOLD%^stra's%^YELLOW%^ head during that battle, though in the end it was %^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^YELLOW%^ who perished. And yet "
	"that single strand of hair now lies in the palm of your hand, a single strand of the %^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^CYAN%^a%^BOLD%^%^MAGENTA%^v%^RESET%^%^MAGENTA%^e%^YELLOW%^ that cannot ever be r"
	"estored. Born of %^RESET%^%^MAGENTA%^M%^CYAN%^a%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^i%^CYAN%^c%^YELLOW%^ and shorn by %^BLACK%^D%^CYAN%^e%^BLACK%^ath%^YELLOW%^ itself, the locke is now linked to bo"
	"th forever.%^RESET%^ 
"	);
	set_property("lore difficulty",50);
	set_item_bonus("caster level",1);
	set_item_bonus("spellcraft",4);
	set_item_bonus("perception",-4);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",7);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^The %^RED%^rush%^YELLOW%^ of %^RESET%^%^MAGENTA%^m%^CYAN%^a%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^i%^CYAN%^c%^YELLOW%^ nearly overwhelms your senses as "+ETOQCN+" %^YELLOW%^slips the "+query_short()+" %^YELLOW%^on a finger.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^The %^RED%^rush%^YELLOW%^ of %^RESET%^%^MAGENTA%^m%^CYAN%^a%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^i%^CYAN%^c%^YELLOW%^nearly overhwelms your senses as you slip the "+query_short()+" %^YELLOW%^on your finger.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" starts to look sharper eyed again as the magic subsides as the "+query_short()+" is removed.",ETO);
	tell_object(ETO,"Your senses get sharper again as the magic subsides when you remove "+query_short()+".");
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
		switch(random(4)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^BLACK%^the dead god %^BOLD%^%^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^BLACK%^ whispers to you:%^CYAN%^ Death is but a doorway. %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^BLACK%^the dead god %^BOLD%^%^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^BLACK%^ whispers to you:%^CYAN%^ Death is but a doorway. %^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^BLACK%^the dead god %^BOLD%^%^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^BLACK%^ whispers to you:%^CYAN%^ Know me and fear me. My embrace is for all and is patient but sure. The dead can always find you. My hand is everywhere - there is no door I cannot pass, nor guardian who can withstand me.%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^BLACK%^the dead god %^BOLD%^%^CYAN%^M%^BLACK%^y%^CYAN%^rkul%^BLACK%^ whispers to you:%^CYAN%^ Know me and fear me. My embrace is for all and is patient but sure. The dead can always find you. My hand is everywhere - there is no door I cannot pass, nor guardian who can withstand me.%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^RESET%^%^CYAN%^the goddess of magic, %^BOLD%^%^MAGENTA%^M%^RESET%^%^MAGENTA%^y%^BOLD%^stra%^RESET%^%^CYAN%^ whispers to you: %^BOLD%^%^BLUE%^Remember always that magic is an %^YELLOW%^Art%^BLUE%^, the Gift of the Lady, and that those who can wield it are %^YELLOW%^privileged%^BLUE%^ in the extreme.  Conduct yourself %^YELLOW%^humbly%^BLUE%^, not proudly, while being mindful of this.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^CYAN%^the goddess of magic, %^BOLD%^%^MAGENTA%^M%^RESET%^%^MAGENTA%^y%^BOLD%^stra%^RESET%^%^CYAN%^ whispers to you: %^BOLD%^%^BLUE%^Remember always that magic is an %^YELLOW%^Art%^BLUE%^, the Gift of the Lady, and that those who can wield it are %^YELLOW%^privileged%^BLUE%^ in the extreme.  Conduct yourself %^YELLOW%^humbly%^BLUE%^, not proudly, while being mindful of this.%^RESET%^", ({ETO}));
				break;
			case 3:
				tell_object(ETO, "%^RESET%^%^CYAN%^the goddess of magic, %^BOLD%^%^MAGENTA%^M%^RESET%^%^MAGENTA%^y%^BOLD%^stra%^RESET%^%^CYAN%^ whispers to you: %^BOLD%^%^BLUE%^When magic %^MAGENTA%^imperils%^BLUE%^ you, %^BLACK%^hide it%^BLUE%^ or hurl it away into other %^GREEN%^planes%^BLUE%^ rather than destroy it, for any %^RED%^destruction%^BLUE%^ of %^YELLOW%^Art%^BLUE%^ is a %^RED%^sin%^BLUE%^.%^RESET%^");
				tell_room(EETO, "%^RESET%^%^CYAN%^the goddess of magic, %^BOLD%^%^MAGENTA%^M%^RESET%^%^MAGENTA%^y%^BOLD%^stra%^RESET%^%^CYAN%^ whispers to you: %^BOLD%^%^BLUE%^When magic %^MAGENTA%^imperils%^BLUE%^ you, %^BLACK%^hide it%^BLUE%^ or hurl it away into other %^GREEN%^planes%^BLUE%^ rather than destroy it, for any %^RED%^destruction%^BLUE%^ of %^YELLOW%^Art%^BLUE%^ is a %^RED%^sin%^BLUE%^.%^RESET%^", ({ETO}));
				break;
		}
	}
}