#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("disc of obsidian");
    set_short("%^RESET%^%^MAGENTA%^Shar's Abs%^BOLD%^%^BLACK%^ol%^RESET%^%^MAGENTA%^ution%^RESET%^");
    set_obvious_short("%^RESET%^%^MAGENTA%^simple disc of ob%^BOLD%^%^BLACK%^si%^RESET%^%^MAGENTA%^dian%^RESET%^");
    set_id(({"disc","simple disc","disc of obsidian","simple disc of obsidian","shar's absolution","absolution","kelemvor-rebirth-blessing999"}));
    set_long("%^RESET%^%^CYAN%^A simple cord of %^BOLD%^%^BLACK%^black leather %^RESET%^%^CYAN%^supports this small and "
"simple amulet, less than two inches across.  It shapes a perfect sphere of %^BOLD%^%^BLACK%^jet-black ob%^RESET%^%^BLUE%^"
"si%^BOLD%^%^BLACK%^dian%^RESET%^%^CYAN%^, reflective as glass and slightly thicker in the middle than at the extremities"
".  It is bordered by an infinitely narrow circle of %^MAGENTA%^pu%^RESET%^r%^MAGENTA%^ple jade%^CYAN%^, the edges worn "
"smooth as though by the caress of a million hands.  Perhaps not overly valuable, the jewelry nonetheless bears something "
"of a %^MAGENTA%^seduc%^RED%^ti%^MAGENTA%^ve attraction %^CYAN%^that you can't quite shake.%^RESET%^\n");
    set_lore("Jewelry such as this oft serve as the symbol of Shar, borne by her servants in her name.  Judging by the "
"crafting of this one, however, it transcends such pieces as a mark of her extreme favor, granted only to a rare handful "
"of her most faithful servants.  It retains a powerful investment of her own divine essence, strong enough to pull the "
"servant who bears it free of Kelemvor's grasp even in death, and bestow to them another chance at life.  But such is the "
"power needed that it can only be used once...");
    set_property("lore difficulty",15);
    set_property("id difficulty",15);
    set_weight(1);
    set_value(13410);
    set_type("ring");
    set_limbs(({"neck"}));
    set_ac(1);
    while((int)query_property("enchantment") != -1) {
      remove_property("enchantment");
      set_property("enchantment",-1);
    }
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    tell_object(ETO,"%^RESET%^%^MAGENTA%^You feel the protection of Shar upon you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" looks calm and assured.%^RESET%^",ETO);
    ETO->set_property("rebirth",TO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^RESET%^%^MAGENTA%^Shar's protection leaves you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETO->QCN+" loses "+ETO->QP+" air of assurance.%^RESET%^",ETO);
    if(ETO->query_property("rebirth")) ETO->remove_property("rebirth");
    return 1;
}

int isMagic(){ return 1; }
int drop(){ return 1;}