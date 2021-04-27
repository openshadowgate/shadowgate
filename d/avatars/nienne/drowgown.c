#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("gown");
    set_id(({"gown","spidersilk gown","revealing gown","raiment","darkweaver's raiment"}));
    set_short("%^RESET%^%^MAGENTA%^Dark%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^eaver's Raim%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^nt%^RESET%^");
    set_obvious_short("%^RESET%^%^MAGENTA%^rev%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^aling spi%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^ersi%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^k go%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^n%^RESET%^");
    set_long("%^RESET%^%^BLUE%^This gown is soft and sheer, cut snugly to fit against the frame of the wearer.  It has been formed of several layers of the cloth known as spidersilk, prized for its durability and light weight.  Most of the spidersilk is of a %^BOLD%^%^BLACK%^pure jet-black hue%^RESET%^%^BLUE%^, so dark that it seems to soak in the light around it, although the color is broken in a few places by hints of %^MAGENTA%^violet %^BLUE%^intermingled with the rest of the ebon threads.  The gown itself is low-cut, clearly designed to better present the assets of a female wearer, and bears a none-too-modest slit down one side from hip to hemline.  The sleeves are long with sharply pointed tips to each cuff, designed to drape down past the hands in a style more for show than any sort of practical use.  The garment is most definitely a rare and probably expensive masterwork of tailoring.%^RESET%^");
    set_weight(5);
    set_value(3750);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_property("enchantment",4);
    set_item_bonus("influence",2);
}
