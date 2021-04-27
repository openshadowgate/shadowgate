#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("tattoo");
   set_id(({"tattoo","star tattoo","blue tattoo","sparkling tattoo","sparkling star tattoo","star sigil","sigil","Star Sigil"}));
   set_short("%^BLUE%^%^BOLD%^S%^CYAN%^ta%^BLUE%^r S%^CYAN%^i%^WHITE%^g%^CYAN%^i%^BLUE%^l%^RESET%^");
   set_obvious_short("%^CYAN%^%^BOLD%^sparkling star tattoo%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This marking shows up in a distinct contrast against the skin.  It forms the "
"outline of a five-pointed star in a clear shade of %^BLUE%^bri%^CYAN%^l%^BLUE%^liant sapp%^CYAN%^h%^BLUE%^ire"
"%^WHITE%^, that ripples with faint hints of %^RESET%^%^WHITE%^ivory %^BOLD%^in a constant change of hue.  "
"Tiny flecks of what seems like %^BLUE%^gl%^CYAN%^i%^BLUE%^tter%^WHITE%^ cause it to sparkle in the light, "
"although they are too small to discern separately within the tattoo's outline.  The marking %^CYAN%^glows "
"%^WHITE%^ever so faintly of its own accord, probably through some unknown enchantment.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^These rare markings are only ever gifted to the Stars of Mystra, as a sign of "
"their status within the faith.  Rather than being tattooed upon the skin by normal means, they are imbued "
"upon the skin's surface by a form of spellcraft only known to the highest ranked of the faith.  Many say they "
"hold the very essence of the Weave within them, carried by the wearers wherever they go.%^RESET%^");
   set_property("lore difficulty",15);
   set_weight(0);
   set_value(0);
   set_type("ring");
   set_limbs(({"head"}));
   set_ac(1);
   set_property("enchantment",-1);
   set_property("no steal",1);
   set_property("no offer",1);
   set_property("no animate",1);
}

int drop(){ return 1; }
