#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create() {
   ::create();
   set_name("bracelets");
   set_id(({"bracelets","cyric bracelets","bands of the sworn faithful","bands","silver bracelets","bands of the sworn","silver bands"}));
   set_short("%^BLACK%^%^BOLD%^Ba%^RESET%^%^WHITE%^nd%^BOLD%^s of t%^RESET%^%^WHITE%^he %^BLACK%^%^BOLD%^Sw%^RESET%^%^WHITE%^or%^BOLD%^n Fait%^RESET%^%^WHITE%^hf%^BLACK%^%^BOLD%^ul%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^si%^RESET%^%^WHITE%^lv%^BOLD%^er brace%^RESET%^%^WHITE%^le%^BLACK%^%^BOLD%^ts%^RESET%^");
   set_long("%^CYAN%^These pair of bracelets are perfectly matched, each a mirror image of thick "
"%^BLACK%^%^BOLD%^s%^RESET%^%^WHITE%^i%^BOLD%^lv%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^r%^RESET%^%^CYAN%^ "
"shaped to rest around the lower arms.  The surface of each is covered in wraithlike etchings of snarling "
"monsters, intertwined with claws and fangs outstretched.  Upon the underside has been rendered an image "
"lined in some %^BLACK%^%^BOLD%^jet-black substance%^RESET%^%^CYAN%^, of a jawless skull upon a backdrop of "
"a %^MAGENTA%^starburst shape%^CYAN%^.  The image would be rendered invisible while the bracelets were worn, but the lines of "
"the etching could be felt against the wearer's skin.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Rumours abound concerning this jewelry and the clergy of the Dark Sun.  "
"The most common tells that the bracelets are only ever granted to those that uphold the One True Way, as an "
"symbolic reminder of their servitude to the Prince of Lies.");
   set_property("lore difficulty",18);
   set_property("enchantment",3);
   set_remove("%^WHITE%^%^BOLD%^You feel the power of the True God recede as you remove the bracelets.");
   set_item_bonus("dexterity",2);
}
