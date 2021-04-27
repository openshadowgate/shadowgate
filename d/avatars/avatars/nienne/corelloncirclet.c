#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("mithril circlet");
   set_id(({"circlet","mithril circlet","delicate circlet","delicate mithril circlet","mark","mark of the feywarden"}));
   set_short("%^BOLD%^%^GREEN%^Ma%^BOLD%^%^CYAN%^r%^BOLD%^%^GREEN%^k of the Fe%^BOLD%^%^YELLOW%^y%^BOLD%^%^GREEN%^war%^BOLD%^%^CYAN%^d%^BOLD%^%^GREEN%^en%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^delicate %^CYAN%^mith%^WHITE%^r%^CYAN%^il %^GREEN%^circlet%^RESET%^");
   set_long("%^ORANGE%^Shaped from %^BOLD%^%^WHITE%^mith%^YELLOW%^r%^WHITE%^il%^RESET%^%^ORANGE%^, this "
"delicate circlet has been treated and polished to give a %^BOLD%^%^WHITE%^br%^RESET%^il%^BOLD%^%^WHITE%^"
"liant %^RESET%^%^ORANGE%^shine that reflects its surroundings like a mirror.  It seems to have originally "
"consisted of several strands of the metal, which have been interwoven in a complex %^MAGENTA%^da%^RED%^nc"
"%^MAGENTA%^e %^ORANGE%^to form the resulting jewelry.  Each is made in the image of a %^GREEN%^vi%^ORANGE%^n"
"%^GREEN%^e%^ORANGE%^, with creeping tendrils winding their way around and snaking amidst the metallic "
"%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^eav%^BOLD%^es %^RESET%^%^ORANGE%^that occasionally reach outward from "
"shining stems.  No gemstones or decorations have been inset into the metal, but each leaf, vine and tendril "
"has been tinted with an odd glittering substance that adds a %^GREEN%^pale e%^BOLD%^m%^RESET%^%^GREEN%^erald "
"g%^YELLOW%^l%^RESET%^%^GREEN%^ow%^ORANGE%^, like a hint of life breathed into the otherwise %^RESET%^ine"
"%^BOLD%^%^BLACK%^r%^RESET%^t metal%^ORANGE%^.  Spots of %^BOLD%^%^WHITE%^sp%^RESET%^a%^BOLD%^%^WHITE%^rkl"
"%^RESET%^i%^BOLD%^%^WHITE%^ng w%^RESET%^h%^BOLD%^%^WHITE%^ite %^RESET%^%^ORANGE%^are revealed to be tiny "
"flowers, blossoming along the length of the vines.  At the front, the strands of the circlet ensnare the "
"greater outline of a crescent, with both tips pointed upwards.  A faint dusting of %^BOLD%^%^CYAN%^a%^RESET%^"
"%^CYAN%^z%^BOLD%^%^CYAN%^u%^BOLD%^%^BLUE%^r%^BOLD%^%^CYAN%^e %^RESET%^%^ORANGE%^glitters across its surface, "
"like the play of %^RESET%^moonlight %^ORANGE%^across rippling water.  The overall result is a subtle, but "
"stunning piece of artwork, and you wonder at the crafting that must have gone into such a piece.\n%^RESET%^");
   set_lore("Such an item could only be the result of magic, though it parallels a similar style to the "
"craftwork of elvenkind, who are renowned for their artistry in all of their craftwork.  While mithril is "
"usually the domain of the dwarves, it is less known that the elves are equally skilled at its working, they "
"only choose to use it differently.  The metal is often worked into armor and jewelry, and each piece is a "
"mastery of artwork and crafting, often taking years to make only a single piece.  They often echo natural "
"themes that the elves hold dear, such as animals and plants.  This unique piece is set with the elven symbol "
"of Corellon Larethian, a crescent moon, and tales tell that it was a blessing upon the priestess Ayvrileiya "
"Hlaettln, as a sign of favor for her faith and perseverence in aiding her kin.");
   set_property("lore",35);
   set_value(20000);
   set_property("enchantment",5);
   set_item_bonus("wisdom",2);
   set_item_bonus("influence",2);
   set_weight(5);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"head"}));
   set_size(-1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme() {
   if((string)ETO->query_name() != "ayvrileiya" && !avatarp(ETO)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The circlet is obviously not designed to fit one such as "
"you.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The circlet was obviously designed for someone other than "
+ETO->QCN+"%^BOLD%^%^WHITE%^, as it simply does not fit "+ETO->QO+".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The circlet sparkles as you settle it upon your brow, and you're sure "
"for a second that it seemed almost alive.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^The circlet sparkles as "+ETO->QCN+" %^BOLD%^%^WHITE%^settles it upon "
+ETO->QP+" brow, and you're sure for a second that it seemed almost alive.%^RESET%^",ETO);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You already miss the light touch of the beautiful circlet.%^RESET%^");
   return 1;
}
