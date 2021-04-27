#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("a symbol covered amulet");
	set_id(({ "amulet", "strange amulet", "wooden amulet", "amulet with symbols", "wooden amulet with symbols", "taurina amir" }));
	set_short("%^BOLD%^%^GREEN%^a t%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^u%^RESET%^%^GREEN%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n%^GREEN%^a a%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^i%^GREEN%^r%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a wood amulet with %^GREEN%^elven symbols %^ORANGE%^on it%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This wooden amulet is made of dark grained %^BOLD%^%^BLACK%^oak wood %^RESET%^%^ORANGE%^with an outer band of lighter grained %^WHITE%^birch wood%^ORANGE%^.  Etched into the dark oak are two %^BOLD%^%^BLACK%^s%^RESET%^i%^WHITE%^%^BOLD%^l%^RESET%^v%^BOLD%^%^BLACK%^er %^RESET%^%^ORANGE%^colored symbols written in the elven language.  One resting above the other with a rippling line intersecting the space between the two.  Into the outer band of birch are seven %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld %^RESET%^%^ORANGE%^colored symbols fanned around the outside of the amulet.  Each symbol is small and delicately inscribed.  Extending from the top of the disk is a small %^CYAN%^metal loop %^ORANGE%^through which a leather thong has been run to allow the amulet to hang about the wearer's neck. %^RESET%^

AVATAR
	);
	set("read",
@AVATAR

                     %^YELLOW%^E%^RESET%^%^ORANGE%^a%^YELLOW%^r%^RESET%^%^ORANGE%^t%^YELLOW%^h%^RESET%^

         %^YELLOW%^W%^RESET%^%^ORANGE%^a%^YELLOW%^t%^RESET%^%^ORANGE%^e%^YELLOW%^r                    A%^RESET%^%^ORANGE%^i%^YELLOW%^r%^RESET%^

                     %^BOLD%^%^WHITE%^L%^RESET%^%^I%^BOLD%^%^BLACK%^%^F%^WHITE%^E%^RESET%^

                %^BOLD%^%^WHITE%^~~~~~~~~~~~~~~~~%^RESET%^
       %^YELLOW%^P%^RESET%^%^ORANGE%^e%^YELLOW%^a%^RESET%^%^ORANGE%^c%^YELLOW%^e                         %^YELLOW%^C%^RESET%^%^ORANGE%^a%^YELLOW%^lm%^RESET%^

                     %^BOLD%^%^WHITE%^D%^RESET%^E%^BOLD%^%^BLACK%^A%^WHITE%^TH%^RESET%^

               %^YELLOW%^F%^%^RESET%^ORANGE%^i%^YELLOW%^re          S%^%^RESET%^ORANGE%^o%^YELLOW%^ul%^RESET%^            


AVATAR
	);
     set("langage","elven");	set_weight(1);
	set_value(75);
	set_lore(
@AVATAR

Taurina Amir literally means wooden amulet in the elven tongue.  Though made out of any type of wood and fashioned in several different styles, they all feature elven words that have a certain meaning for the wearer or maker.  Some claim these disks of wood hold woodland powers.  Others claim there are elven powers imbued in them.  Others still say they're nothing more then decorations that have been given mystery and lore simply because they are elven craft. 


AVATAR
	);
	set_property("lore difficulty",18);
	set_type("ring");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",0);
}


