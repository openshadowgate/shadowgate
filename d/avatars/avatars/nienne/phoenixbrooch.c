#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("phoenix brooch");
    set_short("%^YELLOW%^Sigil of %^RESET%^%^MAGENTA%^R%^BOLD%^%^MAGENTA%^e%^BOLD%^%^RED%^n%^RESET%^%^RED%^e%^ORANGE%^w%^YELLOW%^a%^RED%^l%^RESET%^");
    set_obvious_short("%^YELLOW%^ornate %^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^h%^BOLD%^%^RED%^o%^RESET%^%^RED%^e%^ORANGE%^n%^YELLOW%^i%^RED%^x %^YELLOW%^brooch%^RESET%^");
    set_id(({"brooch","phoenix brooch","ornate brooch","ornate phoenix brooch","sigil","sigil of renewal","Sigil of Renewal","kelemvor-rebirth-blessing999"}));
    set_long("%^GREEN%^Mounted upon a sturdy base and pin, this brooch would be the envy of many for its fine craftsmanship.  Shaped from the same "
"%^BOLD%^%^WHITE%^mi%^BOLD%^%^CYAN%^t%^BOLD%^%^WHITE%^hril %^RESET%^%^GREEN%^as its base, the brooch itself rises into the form of a %^YELLOW%^p"
"%^RESET%^%^ORANGE%^h%^RED%^o%^BOLD%^%^RED%^e%^YELLOW%^n%^BOLD%^%^WHITE%^i%^YELLOW%^x %^RESET%^%^GREEN%^with wings spread and head lifted, as though "
"it were taking flight.  Fine detail has been etched into the metal, showing %^MAGENTA%^delicate %^GREEN%^plumage and %^BOLD%^%^BLUE%^gleam"
"%^BOLD%^%^CYAN%^i%^BOLD%^%^BLUE%^ng %^RESET%^%^GREEN%^eyes.  No gemstones have been set within the piece, but some kind of glittering substance has "
"been imbued into the metal itself, lending a gleam of %^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^BOLD%^%^RED%^b%^RESET%^%^RED%^r%^ORANGE%^a%^YELLOW%^n%^RED%^t "
"%^RESET%^%^GREEN%^color to the spreading feathers whenever light catches its surface.%^RESET%^\n");
    set_lore("Jewelry such as this is rare, not only for its fine craftsmanship, but for what it symbolises.  The phoenix is revered by many "
"civilisations and faiths as a creature that dies in blaze of glory, only to be reborn from its own ashes.  A similar blessing of rebirth is "
"often imbued within such fine pieces, by those faiths who are able to call upon their patron to be spared from the afterlife.  But such is "
"the power needed that it can only be used once...");
    set_property("lore difficulty",25);
    set_property("id difficulty",25);
    set_weight(1);
    set_value(13410);
    set_type("ring");
    set_limbs(({"left hand","right hand"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    tell_object(ETO,"%^YELLOW%^You feel a gentle warmth settle over you as you pin the brooch.%^RESET%^");
    tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" looks calm and assured.%^RESET%^",ETO);
    ETO->set_property("rebirth",TO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^YELLOW%^The gentle warmth fades.%^RESET%^");
    tell_room(EETO,"%^YELLOW%^"+ETO->QCN+" loses "+ETO->QP+" air of assurance.%^RESET%^",ETO);
    if((object)ETO->query_property("rebirth") == TO) ETO->remove_property("rebirth");
    return 1;
}

int isMagic(){ return 1; }
int drop(){
   if(!objectp(ETO)) return 0;
   if(userp(ETO) && !avatarp(ETO)) return 1;
   return 0;
}
