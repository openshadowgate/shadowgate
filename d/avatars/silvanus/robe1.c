//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("robe");
    set_id(({"armor","robe","robe","%^BOLD%^%^WHITE%^Robe of The %^RESET%^%^MAGENTA%^New Dawn%^RESET%^",}));
    set_short("%^BOLD%^%^WHITE%^Robe of The %^BOLD%^%^MAGENTA%^New Dawn%^RESET%^");
    set_long(
@ARMOR
%^BOLD%^%^WHITE%^This is a brilliant white priest robe made out of the finest silk. The long sleeves, hem and neck are bordered with tiny embroided %^RESET%^%^YELLOW%^golden suns%^RESET%^%^BOLD%^%^WHITE%^. On the back of the waist, is a fiery %^RESET%^%^YELLOW%^gold%^BOLD%^%^WHITE%^ and %^BOLD%^%^MAGENTA%^pink %^RESET%^%^YELLOW%^sun%^BOLD%^%^WHITE%^ whose rays reach up toward the sky, across the mid back and shoulder blades. A sash of %^RESET%^%^YELLOW%^golden%^RED%^ red%^BOLD%^%^WHITE%^ silk ties, through a %^RESET%^%^YELLOW%^gold%^BOLD%^%^WHITE%^ and %^BOLD%^%^MAGENTA%^rose quartz%^BOLD%^%^WHITE%^ clasp at the waist, its long tongues hanging down to tassel an inch before the hem in front of the robe.%^RESET%
ARMOR
        );
    set_weight(5);
    set_size(2);
    set_type("clothing");
    set_limbs(({"torso",}));
    set_ac(0);
    set_property("enchantment",0);
    set_value(1200);
}