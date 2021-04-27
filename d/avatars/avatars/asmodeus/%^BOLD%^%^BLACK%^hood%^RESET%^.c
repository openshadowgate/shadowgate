#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^E%^CYAN%^x%^BLACK%^e%^CYAN%^c%^BLACK%^u%^CYAN%^t%^BLACK%^i%^CYAN%^o%^BLACK%^n%^CYAN%^e%^BLACK%^r%^CYAN%^s %^BLUE%^hood%^RESET%^");
	set_id(({ "%^BOLD%^%^BLACK%^E%^CYAN%^x%^BLACK%^e%^CYAN%^c%^BLACK%^u%^CYAN%^t%^BLACK%^i%^CYAN%^o%^BLACK%^n%^CYAN%^e%^BLACK%^r%^CYAN%^s %^BLUE%^hood%^RESET%^" }));
	set_short("%^BOLD%^%^BLACK%^E%^CYAN%^x%^BLACK%^e%^CYAN%^c%^BLACK%^u%^CYAN%^t%^BLACK%^i%^CYAN%^o%^BLACK%^n%^CYAN%^e%^BLACK%^r%^CYAN%^s %^BLUE%^hood%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^Thick fabric drapes over the wearers head heavily, casting %^BLACK%^shadows %^BLUE%^over the person beneath. The inside of the hood is lined by the smoothest %^BLACK%^dark %^RESET%^%^C"
	"YAN%^blue %^BLUE%^silks%^BOLD%^%^BLUE%^, absorbing any %^WHITE%^light %^BLUE%^that makes it beneath the hoods shape. Thin %^CYAN%^s%^RESET%^%^CYAN%^c%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^l%^BOLD%^%^CYAN%^"
	"e%^RESET%^%^CYAN%^s %^BOLD%^%^BLUE%^of %^BLACK%^m%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^h%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^l %^WHITE%^metal %^BLUE%^line the outside"
	" of the hood, but suprisingly they bend and shift like fabric upon closer inspection. %^YELLOW%^R%^RESET%^%^ORANGE%^e%^YELLOW%^f%^RESET%^%^ORANGE%^l%^YELLOW%^e%^RESET%^%^ORANGE%^c%^YELLOW%^t%^RESET%^%"
	"^ORANGE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^g %^BOLD%^%^CYAN%^light %^BLUE%^about the hood in a %^WHITE%^s%^RESET%^%^WHITE%^h%^BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^m%^BOLD%^%^WHITE%^m%^RESET%^%^WHITE%^e%^BOL"
	"D%^%^WHITE%^r%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^g%^BOLD%^%^BLUE%^, %^CYAN%^m%^BLUE%^a%^CYAN%^g%^BLUE%^i%^CYAN%^c%^BLUE%^a%^CYAN%^l %^BLUE%^display. The hood itself is meant to link"
	" with armor or other clothing, draping over the wearers shoulders with small hooks on the outside, meant to be worn beneath armor and dig and hold onto it.
"
	);
	set_value(1000);
	set_lore("%^BOLD%^%^WHITE%^The executioners hood, as its more infamously known, is not as grim as one would expect from its ill reputed name. First worn by Salamesh the bold, one of the first faithful of Tyr to"
	" employ magic rather than divine powers in his quest to bring justice to the world. He specialized in finding dark magi, those whom used the weave to commit their crimes, and after many duties accompl"
	"ished his face became known far and wide, his deep scar that cut out one eye, leaving a jagged mess, made him to easy to recognize. And the justicar favored a hood to conceal his features so he could "
	"roam the slums and wilds in his pursuits. As he faced countless battles with those whom used magic his fortitude against it grew to the point where his own clothing would aid him in repelling the onsl"
	"aught of offensive magic. And even attracted the more fine metals known to hold such properties and molded them into the fabric itself.
%^BOLD%^%^WHITE%^His final act, the destruction of a enclave of "
	"Sharran magi deep in the Tsarven empire earned him the title 'The executioner' as he beheaded every last cultist, interupting one of their dark rituals of high magic. Shortly thereafter, the execution"
	"er was slain in a bloody, ruthless ambush, some claim a black dragon in the employ of Shar herself came for him, but such tales are often exagerated. His legend has since then fallen into myth and for"
	"gotten, his armor and arnaments lost to time, but his hood, which you now hold, seems to have been found.
"
	);
    set_property("lore difficulty",30);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^Slipping the %^BLACK%^hood %^BLUE%^beneath %^RESET%^%^CYAN%^his %^BOLD%^%^WHITE%^armor%^BLUE%^,  as they secures the %^BLACK%^hood %^BLUE%^in place.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Slipping the %^BLACK%^hood %^BLUE%^beneath %^RESET%^%^CYAN%^his %^BOLD%^%^WHITE%^armor%^BLUE%^,  as they secures the %^BLACK%^hood %^BLUE%^in place.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^Carefully unhooking the %^BLACK%^hood%^BLUE%^, %^WHITE%^they %^BLUE%^pulls it from beneath %^RESET%^%^CYAN%^his %^BOLD%^%^BLUE%^armor.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^Carefully unhooking the %^BLACK%^hood%^BLUE%^, %^WHITE%^they %^BLUE%^pulls it from beneath %^RESET%^%^CYAN%^his %^BOLD%^%^BLUE%^armor.");
	return 1;
}

