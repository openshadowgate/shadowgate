#include <std.h>
inherit "/d/common/obj/clothing/shirt";

void create(){
	::create();
	set_name("marishosvest");
	set_id(({ "vest", "marisho's vest" }));
	set_short("%^ORANGE%^M%^BOLD%^%^BLACK%^arisho'%^RESET%^%^ORANGE%^s %^BOLD%^%^BLACK%^V%^RESET%^%^ORANGE%^es%^BOLD%^%^BLACK%^t%^RESET%^");
	set_obvious_short("%^GREEN%^a %^RESET%^%^ORANGE%^un%^BOLD%^%^BLACK%^iq%^RESET%^%^ORANGE%^ue v%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^st%^RESET%^");
	set_long("%^ORANGE%^This vest is very %^BOLD%^%^BLACK%^smoo%^WHITE%^t%^BLACK%^h %^RESET%^%^ORANGE%^and %^BOLD%^%^BLACK%^sli%^WHITE%^c%^BLACK%^k%^ORANGE%^.  %^BOLD%^%^BLUE%^D%^CYAN%^ro%^BLUE%^p%^CYAN%^s %^RESET%"
	"^%^BLUE%^of %^BOLD%^%^CYAN%^wat%^BLUE%^e%^CYAN%^r %^RESET%^%^ORANGE%^roll right off of it instead of gathering and soaking into it's threads.  It is sleeveless and comes down the neck into a gently fo"
	"rmed, curved %^BOLD%^%^WHITE%^V %^RESET%^%^ORANGE%^shape.  It pulls over the wearers head like a sweater instead of buttoning on like a normal vest would.%^RESET%^
"
	);
	set_value(2000);
	set_lore("%^BOLD%^%^WHITE%^Marisho the Great - %^YELLOW%^En%^RED%^te%^BLUE%^rt%^MAGENTA%^ai%^YELLOW%^ne%^RED%^r a%^BLUE%^nd %^MAGENTA%^Es%^YELLOW%^ca%^RED%^pe %^BLUE%^Ar%^MAGENTA%^ti%^YELLOW%^st %^CYAN%^da%^WHI"
	"TE%^z%^CYAN%^zl%^WHITE%^ed %^BLACK%^peasants and aristocrats alike with his challenging shows and daring escapes from %^RESET%^%^RED%^death%^BOLD%^%^BLACK%^.  His talent seemed boundless and in time h"
	"e became cocky.  He owed his abilities to the magicians that sold him mystical items allowing his escapes and he gave thanks to %^MAGENTA%^Mys%^CYAN%^t%^MAGENTA%^ra %^BLACK%^with donations in her temp"
	"le from %^YELLOW%^gold %^BLACK%^earned in his successful shows for the use of such abilities.  As years went by, these donations faded away and he stopped giving his thanks for the ladies gifts.%^RESE"
	"T%^  

%^BOLD%^%^BLACK%^At a show for the citizens of %^WHITE%^Azha %^BLACK%^in the now destroyed theater, a priest of %^MAGENTA%^Mys%^CYAN%^t%^MAGENTA%^ra %^BLACK%^taught him a final lesson for his a"
	"rrogance.  %^WHITE%^Marisho %^BLACK%^was to escape from being hung upside down and wrapped with ropes while dangling over a pit of extremely starved %^RESET%^%^ORANGE%^lions%^BOLD%^%^BLACK%^.  The ves"
	"t he wore was blessed with the abilities to enhance his ability to escape the bonds.  However, the priest put a binding spell on all magic in the area, limiting it's effectiveness.  Without any natura"
	"l abilities to escape on his own, he ran out of time and his weight on the ropes eventually lowered him into the pit.  By the time the lions were secured, %^WHITE%^Marisho %^BLACK%^had lost his head, "
	"with his body only escaping being eaten by the packaging the heavy rope around him provided.%^RESET%^
"
	);
    set_property("lore difficulty",15);
    set("dexbonus",1);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" wiggles "+query_short()+" over the head quite easily%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^Pulling the "+query_short()+" over your head, you feel very %^BOLD%^%^BLACK%^sl%^WHITE%^i%^BLACK%^ppe%^WHITE%^r%^BLACK%^y%^RESET%^");
	ETO->add_skill_bonus("rope use",5);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" slides "+query_short()+" right over the head like butter%^RESET%^",ETO);
	tell_object(ETO,"%^ORANGE%^The "+query_short()+" slides right off without even pulling your hair.%^RESET%^");
	ETO->add_skill_bonus("rope use",-5);
	return 1;
}

