#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("skullstein");
	set_id(({ "stein", "beer stein made from a skull", "beer stein" }));
	set_short("%^RESET%^%^ORANGE%^beer %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^i%^BOLD%^n%^RESET%^%^ORANGE%^ made from a %^CYAN%^s%^BOLD%^k%^RESET%^%^CYAN%^ull%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^beer %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^i%^BOLD%^n%^RESET%^%^ORANGE%^ made from a %^CYAN%^s%^BOLD%^k%^RESET%^%^CYAN%^ull%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This beer stein is made from a %^BOLD%^%^BLACK%^human%^RESET%^%^CYAN%^ s%^BOLD%^k%^RESET%^%^CYAN%^ull%^ORANGE%^ as a kind of war trophy. The handle is attached to the back of the sk"
	"ull, and the top of the skull has been cut away to form the top of the mug. A ceramic insert has been placed inside the skull to hold the %^RESET%^%^MAGENTA%^beverage%^ORANGE%^. The face of the skull "
	"is facing away, opposite the handle, a macabre reminder of a %^RESET%^%^RED%^f%^BOLD%^a%^RESET%^%^RED%^llen %^MAGENTA%^e%^BOLD%^n%^RESET%^%^MAGENTA%^emy.%^RESET%^ 
"	);
	set_value(1000);
	set_weight(0);
	set_lore("%^YELLOW%^Five friends faced down a ferocious foe in a battle in %^WHITE%^Offestry.%^YELLOW%^ Alestair, Emelio, Siegfried, Piastol, and Maul fought an %^RED%^evil %^BLACK%^necromancer%^YELLOW%^ who wa"
	"s raising evil zombies to kill the villagers. After defeating the %^RESET%^%^CYAN%^r%^BOLD%^a%^RESET%^%^CYAN%^venous%^BOLD%^%^BLACK%^ zombies%^YELLOW%^, the necromancer attempted to purchase their loy"
	"alty. Rejecting the offer, they were nearly %^RED%^killed%^YELLOW%^ before driving away their enemy. Chasing him down, the group fought on until %^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^i%^YELLOW%^ deliver"
	"ed a %^RED%^terrific blow%^YELLOW%^ striking off the necromancers head. %^YELLOW%^The skull of the necromancer was made into a %^RESET%^%^ORANGE%^beer stein%^YELLOW%^ which you now hold in your hands."
	"%^RESET%^
"	);
	set_property("lore difficulty",0);
}
