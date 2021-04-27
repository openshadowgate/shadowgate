#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("%^YELLOW%^o%^CYAN%^a%^YELLOW%^t%^CYAN%^h%^BOLD%^%^BLACK%^ r%^WHITE%^i%^BLACK%^ng%^RESET%^");
	set_id(({ "ring", "oath ring" }));
	set_short("%^YELLOW%^o%^CYAN%^a%^YELLOW%^t%^CYAN%^h%^BOLD%^%^BLACK%^ r%^WHITE%^i%^BLACK%^ng%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^r%^RED%^u%^MAGENTA%^n%^RED%^e%^MAGENTA%^d%^BOLD%^%^BLACK%^ t%^WHITE%^i%^BLACK%^tan%^WHITE%^i%^BLACK%^um r%^WHITE%^i%^BLACK%^ng%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This ring is covered in tiny %^YELLOW%^r%^CYAN%^u%^YELLOW%^n%^CYAN%^e%^YELLOW%^s%^BLACK%^ and is made out of t%^WHITE%^i%^BLACK%^tan%^WHITE%^i%^BLACK%^um%^BLACK%^. It is clearly magic"
	"al and gives off a faint %^RESET%^%^MAGENTA%^g%^RED%^l%^MAGENTA%^o%^RED%^w%^BOLD%^%^BLACK%^. It is otherwise plain, and therefore seems rather to serve the purpose of %^YELLOW%^marking%^BLACK%^ like a"
	" signet ring rather than any kind of decorative fashion.%^RESET%^
"
	);
	set_value(500);
	set_lore("This is an %^YELLOW%^o%^CYAN%^a%^YELLOW%^t%^CYAN%^h%^BOLD%^%^BLACK%^ r%^WHITE%^i%^BLACK%^ng%^RESET%^ that a magus gives an apprentice to represent the bargain that an apprentice makes in return for kn"
	"owledge. It is said that the most cautious and formal magi proceed with this ritual, and more commonly by the most cruel masters. It serves a purpose to mark those that keep their vows in good faith a"
	"nd also to mark those that don't. The ring cannot be removed under normal circumstances, and thus a ring worn by an apprentice that breaks those vows suddenly finds himself rather permanently marked a"
	"s an oathbreaker.
"
	);
    set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^The ring slips off you finger for your %^CYAN%^oath%^YELLOW%^ has been fulfilled.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel the %^CYAN%^oath%^YELLOW%^ in your mind as the ring slips comfortably on your finger, and yet you know that it has bound you stronger than any %^BLACK%^manacle.%^RESET%^");
	ETO->set_property("magic resistance",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^YELLOW%^The ring slips off you finger for your %^CYAN%^oath%^YELLOW%^ has been fulfilled.%^RESET%^");
	ETO->set_property("magic resistance",-5);
	return 1;
}

