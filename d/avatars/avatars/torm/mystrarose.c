#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Mystra's Rose");
	set_id(({ "rose", "flower", "shimmering rose", "beautiful rose" }));
	set_short("%^RESET%^%^GREEN%^A shimmering long-ste%^BOLD%^%^WHITE%^m%^CYAN%^m%^BOLD%^%^WHITE%^ed R%^MAGENTA%^o%^BOLD%^%^WHITE%^se%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A beautiful %^BOLD%^%^WHITE%^rose%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is %^RESET%^%^GREEN%^a%^BOLD%^%^WHITE%^n exqu%^GREEN%^i%^WHITE%^site lon%^GREEN%^g%^WHITE%^-st%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^m%^RESET%^%^RED%^m%^BOLD%^%^WHITE%^ed rose.  The r%^GREEN%^i%^WHITE%^ch gr%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^en of the ste%^RESET%^%^RED%^m%^BOLD%^%^WHITE%^ and leave%^GREEN%^s %^WHITE%^complements the amazing shimmering colours of the petals.  Each p%^CYAN%^e%^BOLD%^%^WHITE%^tal a%^MAGENTA%^p%^BOLD%^%^WHITE%^pe%^YELLOW%^a%^BOLD%^%^WHITE%^rs to be a slightly %^BLUE%^d%^BOLD%^%^WHITE%^ifferent shade of whit%^YELLOW%^e%^WHITE%^.  Hints of pink, ye%^CYAN%^l%^BOLD%^%^WHITE%^low and %^YELLOW%^b%^WHITE%^lue in myriad hues can be seen in t%^CYAN%^h%^WHITE%^is beautiful f%^MAGENTA%^l%^WHITE%^ower.  T%^BLUE%^h%^WHITE%^e flower has an unus%^CYAN%^u%^WHITE%^al au%^MAGENTA%^r%^WHITE%^a that gives it the fee%^YELLOW%^l%^WHITE%^ing of a still growing flo%^CYAN%^w%^WHITE%^e%^MAGENTA%^r%^WHITE%^.%^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(5000);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^There are many flowers associated in myth and legend with different deities.  The shimmering long-stemmed rose is one that has always been associated closely with Mystra due to its seemingly enchanted petals.  Only those truly favoured of the Lady of Mysteries have been blessed with such a gift.%^RESET%^

AVATAR
	);
}