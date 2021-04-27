#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create() {
   ::create();
   set_name("coiffe");
   set_id(({"coiffe","headdress","gem studded coiffe","gem-studded coiffe","delicate coiffe","veil","umbral veil"}));
   set_short("%^RESET%^%^MAGENTA%^U%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^br%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^l V%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^il%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^delicate g%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^m-st%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^dd%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^d coiffe%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This finely crafted mesh of metal and gemstones is known as a coiffe. Somewhat akin to a headdress, but "
"much more subtle, this one is formed of %^RESET%^%^CYAN%^delicate %^BOLD%^%^WHITE%^chains of metal that have been somehow blackened, "
"affording them a beautiful %^RESET%^%^BLUE%^dark %^BOLD%^%^WHITE%^gleam. The chains criss-cross each other to form an open mesh of "
"diamond shapes, and at each junction have been set alternating pieces of %^BOLD%^%^BLACK%^on%^RESET%^y%^BOLD%^%^BLACK%^x "
"%^BOLD%^%^WHITE%^and %^RESET%^%^MAGENTA%^am%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^th%^BOLD%^%^MAGENTA%^y%^RESET%^%^MAGENTA%^st"
"%^BOLD%^%^WHITE%^. Along its lower edge fall short lengths of the dark chain, each bearing similarly alternating %^RESET%^%^MAGENTA%^ge"
"%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^st%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^nes %^BOLD%^%^WHITE%^at their ends that have been shaped "
"like tiny teardrops. Subtle dark clasps along the upper edge and the sides would allow it to be secured in place, creating an unusually "
"striking effect without obscuring the wearer's hair from view.%^RESET%^\n");
    while ((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_lore("%^BOLD%^%^WHITE%^Such a distinctive piece of jewelry is seen as the mark of a favored servant of the Nightsinger. It would "
"usually be blessed specifically as a reward for service in Her name, to those women possessed of the jet-black hair seen as a sign of "
"Her favor. Worn over such hair, the gemstones are stylised to represent a night sky darkened by Her will, blotting out the light of the "
"stars so that they shine instead with the dark radiance of Her power. The teardrops along the lower edge are said to represent sorrow "
"and loss, offered up to the Dark Sister's embrace.");
    set_value(7500);
    set_type("ring");
    set_item_bonus("influence",4);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO,"strikeme":));
}

int wearme() {
    if((string)ETO->query_name() != "saturnina" && !avatarp(ETO)) {
      tell_object(ETO,"You can't figure out how to settle the fine mesh into place.");
      tell_room(EETO,""+ETO->QCN+" can't seem to figure out how to settle the fine mesh into place.",ETO);
      return 0;
    }
    tell_object(ETO,"%^MAGENTA%^You carefully drape the fine mesh over your hair and secure it in place.%^RESET%^");
    tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" secures the delicate mesh in place, and the gemstones glint like t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ny da%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^k st%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^rs against the %^BOLD%^%^BLACK%^black night %^RESET%^%^MAGENTA%^of "+ETO->QP+" hair.%^RESET%^",ETO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^MAGENTA%^You carefully lift the fragile mesh from your hair.%^RESET%^");
    return 1;
}

int strikeme(int damage, object what, object who) {
   if(!random(3)) {
     tell_object(who,"%^MAGENTA%^As your blow lands, a retributive jolt of %^RED%^pain %^MAGENTA%^arcs through your body!%^RESET%^");
     tell_object(ETO,"%^MAGENTA%^As "+who->QCN+" strikes you, %^BLUE%^dark power %^MAGENTA%^thrums through your body and "+who->QS+" recoils back in %^RED%^pain%^MAGENTA%^!%^RESET%^");
     tell_room(EETO,"%^MAGENTA%^As "+who->QCN+" strikes "+ETO->QCN+", "+who->QS+" recoils back in %^RED%^pain%^MAGENTA%^!%^RESET%^",ETO);
     who->cause_typed_damage(who,"head",damage,"negative energy");
   }
   return 0;
}