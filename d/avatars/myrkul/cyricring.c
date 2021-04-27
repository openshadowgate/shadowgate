#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("%^BOLD%^%%^RED%^b%^RESET%^%^RED%^l%^MAGENTA%^o%^RED%^o%^BOLD%^d%^RESET%^%^RED%^s%^MAGENTA%^t%^RED%^o%^BOLD%^n%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^ring %^MAGENTA%^g%^RESET%^%^MAGENTA%^l%^BOLD%^owi%^RESET%^%^MAGENTA%^n%^BOLD%^g %^BLACK%^with %^RED%^p%^RESET%^%^RED%^u%^BOLD%^re %^RESET%^%^MAGENTA%^e%^RED%^v%^BOLD%^i%^RESET%^%^MAGENTA%^l%^RESET%^");
	set_id(({ "bloodstone ring", "ring", "ring of cyrics chosen" }));
	set_short("%^BOLD%^%^BLACK%^R%^RESET%^i%^BOLD%^%^BLACK%^ng %^RESET%^o%^BOLD%^%^BLACK%^f C%^CYAN%^y%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^cs C%^CYAN%^h%^BLACK%^os%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^n%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^MAGENTA%^o%^RED%^o%^BOLD%^d%^RESET%^%^RED%^s%^MAGENTA%^t%^RED%^o%^BOLD%^n%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^ring %^MAGENTA%^g%^RESET%^%^MAGENTA%^l%^BOLD%^owi%^RESET%^%^MAGENTA%^n%^BOLD%^g %^BLACK%^with %^RED%^p%^RESET%^%^RED%^u%^BOLD%^re %^RESET%^%^MAGENTA%^e%^RED%^v%^BOLD%^i%^RESET%^%^MAGENTA%^l%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This ring is made out of %^BOLD%^%^RED%^b%^RESET%^%^RED%^l%^MAGENTA%^o%^RED%^o%^BOLD%^d%^RESET%^%^RED%^s%^MAGENTA%^t%^RED%^o%^BOLD%^n%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ in the shape of"
	" a simple band. The material itself is not a rare or fancy mineral, just some black rock with flecks of %^RED%^red%^BOLD%^%^BLACK%^. What is different here, is that it appears to have absorbed huge qu"
	"antites of %^BOLD%^%^RED%^blood%^BLACK%^ and it seems to even %^RESET%^%^MAGENTA%^s%^BOLD%^w%^RED%^e%^RESET%^%^MAGENTA%^a%^RED%^t%^BOLD%^%^RED%^ blood%^BLACK%^ so that it looks moist. What is truly %^"
	"WHITE%^frightening%^BLACK%^ however is the %^RESET%^%^MAGENTA%^a%^RED%^u%^BOLD%^r%^RESET%^%^MAGENTA%^a %^BOLD%^%^BLACK%^of %^RED%^p%^RESET%^%^RED%^u%^BOLD%^re %^RESET%^%^MAGENTA%^e%^RED%^v%^BOLD%^i%^R"
	"ESET%^%^MAGENTA%^l%^RESET%^ %^BOLD%^%^BLACK%^that shines from within the ring. %^RESET%^%^MAGENTA%^Pity the poor creature that would wear it willingly -- %^CYAN%^and %^BOLD%^%^BLACK%^fear%^RESET%^%^CY"
	"AN%^ it greatly!.%^RESET%^
"	);
	set_value(100000);
	set_lore("%^YELLOW%^Some say that this ring was forged by %^BOLD%^%^BLACK%^M%^CYAN%^y%^BLACK%^rkul%^YELLOW%^ long ago as a gift to a wayward cleric on the brink of death who wished all the power of hell to vanq"
	"uish church enemies. %^BOLD%^%^BLACK%^M%^CYAN%^y%^BLACK%^rkul's%^YELLOW%^ appreciation of %^BLACK%^irony%^YELLOW%^ is legend -- for the cleric was gifted a ring which did in fact open a gate to hell. "
	"The cleric unleashed terrible fiends which promptly slaughtered everything -- including the cleric. Afterwards, the ring was lost in time, until the rise of %^BLACK%^C%^CYAN%^y%^BLACK%^r%^RESET%^%^MAG"
	"ENTA%^i%^BOLD%^%^BLACK%^c%^YELLOW%^ who appreciated such a valuable %^RESET%^%^MAGENTA%^doomsday device%^YELLOW%^. A common difficulty in the priesthood of %^BOLD%^%^BLACK%^C%^CYAN%^y%^BLACK%^r%^RESET"
	"%^%^MAGENTA%^i%^BOLD%^%^BLACK%^c%^YELLOW%^ is the longevity of the high priest. Being a god murder, strife, insanity, and illusion does not make it easy to retain good help. Thus the ring is now worn "
	"by %^BOLD%^%^BLACK%^C%^CYAN%^y%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^cs C%^CYAN%^h%^BLACK%^os%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^n%^YELLOW%^. The ring is the ultimate insurance policy again"
	"st the stupidity of overreaching underpriests. The ring is a guarantee of mutually assured dectruction for would-be attackers by all the powers of %^BOLD%^%^RED%^hell!%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("influence",1);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" is wreathed in flames upon wearing the "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You are wreathed in flames as you wear the "+query_short()+".%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" looks less evil when the "+query_short()+" is removed.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel less evil as you remove "+query_short()+"%^RESET%^");
	return 1;
}

