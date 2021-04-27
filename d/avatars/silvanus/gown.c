//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("dress");
    set_id(({"armor","dress","gown","%^BOLD%^%^WHITE%^Silk Wedding Gown%^RESET%^",}));
    set_short("%^BOLD%^%^WHITE%^Silk Wedding Gown%^RESET%^");
    set_long(
@ARMOR
%^BOLD%^%^YELLOW%^One look at this %^WHITE%^delicate silk%^YELLOW%^ gown and you can tell a great deal of %^RED%^emotion%^YELLOW%^ was behind its creation. A %^WHITE%^delicate%^YELLOW%^, intricate weaving of %^WHITE%^silken%^YELLOW%^ threads creates the %^CYAN%^overdress%^YELLOW%^ of this special gown. This dress recalls to mind %^CYAN%^dew%^YELLOW%^ drops on a spider web, the way the %^CYAN%^light%^YELLOW%^ catches it here and there. The silhouette of the dress is basic in that it fits the wearer through the bodice and then %^WHITE%^flows%^YELLOW%^ down to the ground. Voluminous sleeves drape from the shoulders, slit from the arm hole to the cap and held in place on each side with %^CYAN%^sapphire%^YELLOW%^ and %^MAGENTA%^p%^WHITE%^e%^MAGENTA%^a%^WHITE%^r%^MAGENTA%^l%^YELLOW%^ encrusted %^BLACK%^brooches%^YELLOW%^, with the %^BLUE%^marvelous%^YELLOW%^ underdress peaking through the %^CYAN%^airy%^YELLOW%^ overdress. The underdress is a sleeveless heavy %^WHITE%^white silk%^YELLOW%^ gown of similar silhouette. All in all the dress gives the wearer an added %^RED%^r%^BLUE%^e%^RED%^g%^BLUE%^a%^RED%^l%^YELLOW%^ grace%^RESET%^.
ARMOR
        );
    set_weight(4);
    set_size(2);
    set_type("clothing");
    set_limbs(({"torso",}));
    set_ac(0);
    set_property("enchantment",0);
    set_value(300);
}