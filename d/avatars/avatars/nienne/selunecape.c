#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
 set_name("sparkling cape");
   set_obvious_short("%^BOLD%^%^BLACK%^A %^WHITE%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^RESET%^%^WHITE%^i%^BOLD%^ng %^BLACK%^cape%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Cape of the %^WHITE%^S%^RESET%^%^WHITE%^t%^BOLD%^a%^RESET%^%^WHITE%^r%^BOLD%^s%^RESET%^");
   set_id(({"cape","sparkling cape","cape of the stars"}));
   set_long("%^GREEN%^This stunning cape is extremely lightweight, cut into a short half-cape that would "
"only just covers the wearer's back.  Interwoven into the %^BLACK%^%^BOLD%^midnight-black silk "
"%^RESET%^%^GREEN%^are tiny, metallic threads of %^WHITE%^%^BOLD%^pure silver%^RESET%^%^GREEN%^, that give "
"the impression of a multitude of stars, and make the cape sparkle whenever it moves.  A delicate "
"%^WHITE%^%^BOLD%^silver chain%^RESET%^%^GREEN%^ holds the cape closed across the wearer's neck, and from it "
"hang two small pendants of %^WHITE%^cle%^CYAN%^%^BOLD%^a%^RESET%^%^WHITE%^r cr%^CYAN%^%^BOLD%^y%^RESET%^"
"%^WHITE%^stal%^GREEN%^.  One is shaped as a crescent moon, and the other is a five-pointed "
"%^YELLOW%^st%^WHITE%^a%^YELLOW%^r%^RESET%^%^GREEN%^.%^RESET%^\n");
   set_lore("Capes like this are prized by people from all walks of life.  They "
"are only considered to be minor magical works, as even lesser enchanters can "
"usually manage to imbue illusions such as this into a garment.  However, to "
"the lay person, it is often seen as a prize of great value, and they are "
"usually treasured when found, or sold for vast sums of gold.");
   set_property("lore difficulty",4);
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(540);
   set_property("enchantment",2);
   set_wear("%^BOLD%^%^WHITE%^You carefully fasten the chain around your neck, holding the sparkling cape in "
"place.");
   set_remove("%^BOLD%^%^WHITE%^You undo the chain and slip off the sparkling cape.");
}

