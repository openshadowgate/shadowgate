#include <std.h>
inherit "/std/armour";

string owner;
int OWNED;

void create() {
    ::create();
    set_name("bracelets");
    set_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
    set_id(({"bracelets","twin bracelets","platinum bracelets","twin platinum bracelets"}));
    set_long("Fine strands of pristine %^BOLD%^%^WHITE%^pl%^CYAN%^a%^WHITE%^tin"
"%^CYAN%^u%^WHITE%^m %^RESET%^metal shapes these twin bracelets, each a perfect "
"%^BOLD%^%^CYAN%^mir%^WHITE%^r%^CYAN%^or %^RESET%^image of the other. The "
"strands themselves appear to be interwoven along the upper surface of each, "
"though underneath they form a flat, melded surface that sits %^RED%^co"
"%^MAGENTA%^mf%^RED%^or%^MAGENTA%^ta%^RED%^bl%^MAGENTA%^y %^RESET%^upon the arm"
". In amongst the strands are tiny flecks of %^BOLD%^%^BLUE%^sa%^CYAN%^p%^BLUE%^"
"phi%^CYAN%^r%^BLUE%^e%^RESET%^, cut to catch and refract light in %^GREEN%^ex"
"%^CYAN%^qu%^GREEN%^is%^CYAN%^it%^GREEN%^e %^RESET%^patterns. Upon the underside "
"of the bracelet are etched runes in some ornate, unfamiliar script that forms "
"flowing whorls across the %^BOLD%^%^WHITE%^br%^CYAN%^i%^WHITE%^ght %^RESET%^"
"metal.\n");
    set_lore("These pristine bracelets are known throughout history's pages as a "
"highly prized artifact of ancient high-elven make. Crafted by the unparalleled "
"magics that have long since been lost to the centuries after the Crown Wars, "
"they were said to be so skillfully made that they would adapt to any person "
"that wore them, enhancing and empowering the magical capacity of any kind of "
"spellcaster.");
    set_property("lore",11);
    set_weight(5);
    set_value(2000);
    set_type("clothing");
    set_limbs(({"right arm"}));
    set_ac(0);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    if(!ETO->is_class("cleric") && !ETO->is_class("mage") && !ETO->is_class("psion")) {
      tell_object(ETO,"You cannot seem to focus clearly enough to wear the bracelets.");
      return 0;
    }
    if(ETO->query_lowest_level() < 30 && !avatarp(ETO)) {
      tell_object(ETO,"You are not experienced enough to use these bracelets.");
      return 0;
    }
    if(OWNED && owner != (string)TP->query_name() && !avatarp(TP)) {
      tell_object(ETO,"These bracelets do not belong to you!");
      return 0;
    }
    if(!OWNED && !avatarp(TP)) {
      OWNED = 1;
      owner = (string)TP->query_name();
    }
    tell_object(ETO,"%^RESET%^%^CYAN%^You feel your concentration %^BOLD%^"
"sharpen %^RESET%^%^CYAN%^as you slide the bracelets over each wrist, and they "
"begin to %^ORANGE%^glow%^CYAN%^ with a soft magical aura.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^CYAN%^"+ETO->QCN+" slides the bracelets over each "
"wrist, and they begin to %^ORANGE%^glow%^CYAN%^ with a soft magical aura."
"%^RESET%^",ETO);
    if(ETO->is_class("cleric"))
      TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^MAGENTA%^Di%^RED%^vi%^MAGENTA%^ne %^RED%^Fo%^MAGENTA%^cu%^RED%^s%^RESET%^");
    if(ETO->is_class("psion"))
      TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^ORANGE%^Me%^YELLOW%^nt%^RESET%^%^ORANGE%^al %^YELLOW%^Cl%^RESET%^%^ORANGE%^ar%^YELLOW%^it%^RESET%^%^ORANGE%^y%^RESET%^");
    if(ETO->is_class("mage"))
      TO->set_short("%^BOLD%^%^WHITE%^Bracelets of %^RESET%^%^CYAN%^Ar%^GREEN%^ca%^CYAN%^ne %^GREEN%^Pr%^CYAN%^ec%^GREEN%^is%^CYAN%^io%^GREEN%^n%^RESET%^");
    while((int)TO->query_property("enchantment") != 1) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",1);
    }
    ETO->set_property("spell penetration",10);
    ETO->set_property("empowered",2);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^RESET%^%^CYAN%^Your mental focus wanes as you remove the "
"twin bracelets, and they cease %^ORANGE%^glowing%^CYAN%^.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^CYAN%^The twin bracelets cease %^ORANGE%^glowing"
"%^CYAN%^ as "+ETO->QCN+" removes them.%^RESET%^",ETO);

    TO->set_short("%^BOLD%^%^WHITE%^twin pl%^CYAN%^a%^WHITE%^tin%^CYAN%^u%^WHITE%^m bracelets%^RESET%^");
    TO->remove_property("enchantment");
    ETO->set_property("spell penetration",-10);
    ETO->set_property("empowered",-3);
    return 1;
}

int set_bound_me(string str) {
   OWNED = 1;
   owner = str;
   return 1;
}
