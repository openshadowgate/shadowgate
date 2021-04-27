#include <std.h>
inherit "/d/common/obj/armour/leather_plate";

void create() {
   ::create();
    set_id(({"armor","leather","leather plate","leather breastplate","breastplate","plate","guard","luckbringers guard","luckbringer's guard"}));
   set_short("%^BOLD%^%^WHITE%^Lu%^CYAN%^ck%^BLUE%^b%^WHITE%^ri%^CYAN%^nge%^WHITE%^r's G%^BLUE%^ua%^CYAN%^r%^WHITE%^d%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A %^RESET%^si%^BOLD%^lv%^RESET%^er-li%^BOLD%^ne%^RESET%^d %^ORANGE%^leather breastplate%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This little breastplate is made of tanned "
"leather that is still rather supple and fits close to the wearer's body, "
"moving as they do.  For added protection, %^RESET%^si%^BOLD%^lve"
"%^RESET%^ry %^ORANGE%^rivets have been added at intervals so as not to "
"hamper movement.  Around the edges, the leather has been decorated with "
"images of tiny birds in some kind of %^RESET%^si%^BOLD%^lv%^RESET%^er "
"%^ORANGE%^ink, that sparkle brightly as %^YELLOW%^lig%^WHITE%^h%^YELLOW%^"
"t %^RESET%^%^ORANGE%^catches their forms.%^RESET%^");
   set_size(1);
   set_property("enchantment",3);
}
