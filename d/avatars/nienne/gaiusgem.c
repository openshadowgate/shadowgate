#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create() {
   ::create();
   set_name("brow-gem");
   set_id(({"gem","browgem","brow-gem","asymmetrical brow-gem","jewel","Jewel of Insight","jewel of insight"}));
   set_short("%^RESET%^%^MAGENTA%^Jewel of I%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^si%^CYAN%^g%^MAGENTA%^ht%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^as%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^mmet%^CYAN%^r%^MAGENTA%^ical br%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^w-gem%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This brow-gem is quite unique in appearance, given its distinctive coloration and asymmetrical design. "
"It is primarily formed of a single oval amethyst jewel with a rose-cut finish, displaying the %^RESET%^%^MAGENTA%^de%^BOLD%^%^MAGENTA%^e"
"%^RESET%^%^MAGENTA%^p vi%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^let %^BOLD%^%^WHITE%^aspect of the gem to its full potential. The "
"amethyst is outlined on one side by an arc of abalone pearl, like an i%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^ide%^BOLD%^%^MAGENTA%^s"
"%^BOLD%^%^WHITE%^c%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^nt crescent moon that reflects a rainbow of hues from different angles. The back of "
"the ornament is completely smooth, with no pin or clasp to secure it anywhere, leaving you to wonder what purpose it may serve.%^RESET%^\n");
    while ((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_lore("%^BOLD%^%^WHITE%^Such gemstones are worn upon the brow, and are commonly a mark of prestige or power, or both. They are "
"favored by those of the psychic arts, as much for the innate properties of the gemstones themselves, as for their representation of "
"the third eye. Emerald and amethyst gemstones are generally preferred, for their capacity to enhance the latent psionic abilities "
"of the wearer. The abalone pearl is likely an addition for its properties in mental harmony and increased sensitivity. Such gemstones "
"are usually bound to one particular wearer only, and it is the attunement to their particular power that keeps them in place upon the "
"brow.");
    set_value(7500);
    set_type("ring");
    set_item_bonus("spellcraft",4);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO,"strikeme":));
}

int wearme() {
    if((string)ETO->query_name() != "gaius" && !avatarp(ETO)) {
      tell_object(ETO,"You're not quite sure how to get the gem to stay in place.");
      tell_room(EETO,""+ETO->QCN+" doesn't seem to know how to get the gem to stay in place.",ETO);
      return 0;
    }
    tell_object(ETO,"%^CYAN%^As you lift the gem to your brow, it attunes to your power and settles into place of its own volition.%^RESET%^");
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+" lifts the gem to "+ETO->QP+" brow, and it seems to adhere there all on its own.%^RESET%^",ETO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^CYAN%^The gem detaches from your brow and your senses feel suddenly dulled.%^RESET%^");
    return 1;
}

void init() {
   ::init();
   add_action("cast_fun","cast");
   add_action("cast_fun","chant");
   add_action("cast_fun","manifest");
}

int cast_fun() {
   if(!objectp(TO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_worn()) return 0;
   if(random(1000) < 150) {
     tell_object(ETO,"%^CYAN%^The gem upon your brow %^BOLD%^%^CYAN%^flares %^RESET%^%^CYAN%^with a second's incandescence.%^RESET%^");
     tell_room(EETO,"%^CYAN%^The gem upon "+ETO->QCN+"'s brow %^BOLD%^%^CYAN%^flares %^RESET%^%^CYAN%^with a second's incandescence.%^RESET%^",ETO);
     ETO->set_property("clearcasting",1);
   }
   return 0;
}