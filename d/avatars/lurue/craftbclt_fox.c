#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("woven bracelet");
	set_id(({ "bracelet", "woven bracelet", "multicolored bracelet", "fox bracelet" }));
	set_short("%^RESET%^%^CYAN%^Craft Bracelet of the %^BOLD%^%^BLACK%^Fox%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^a %^GREEN%^w%^WHITE%^o%^RED%^v%^WHITE%^e%^GREEN%^n %^CYAN%^bracelet%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^This simple hand braided bracelet appears to be little more then a fanciful piece of country craft.  %^GREEN%^Green%^CYAN%^, %^WHITE%^white %^CYAN%^and %^RED%^red %^CYAN%^threads have been tightly knotted together into a zig-zagging weave that alternates back and forth with perfect regularity.  Dotting its surface, in bright %^BOLD%^%^BLACK%^black thread%^RESET%^%^CYAN%^, images of foxes can be seen marching across the multicolored strands.  At either end of the bracelet, %^BOLD%^%^BLACK%^metal clasps %^RESET%^%^CYAN%^provide a means to both prevent fraying and to allow the bracelet to be closed around the wrist.  Though simple of design, it is clear that someone spent a great deal of time working on making this bracelet just right.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(300);
	set_lore(
@AVATAR
Life in the country is never predictable.  Some days it's calm and made for lazing in the sun, other days it's a fierce drive to stay ahead of the weather. One thing is for sure, those who live on the farms and orchards, tending the soil and harvesting the crops, have a bountiful life filled with many blessings.  To remember these blessings, in the evenings, after the sun is down and the crops are tended, many will turn to some form of hand craft.  Creating beautiful pieces of wearable art that they either wear themselves or give to special people who have touched their lives.  This is one such piece. 

AVATAR
	);
	set_property("lore difficulty",15);
	set("intbonus",1);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(2);
	set_property("enchantment",0);
}


