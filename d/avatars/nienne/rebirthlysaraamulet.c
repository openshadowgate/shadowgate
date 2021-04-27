#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("jade amulet");
    set_short("%^RESET%^%^ORANGE%^F%^GREEN%^a%^ORANGE%^te's Reprieve%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^simple sca%^GREEN%^ra%^ORANGE%^b amulet%^RESET%^");
    set_id(({"scarab amulet","amulet","simple amulet","simple scarab amulet","kelemvor's reprieve","reprieve","kelemvor-rebirth-blessing999"}));
    set_long("%^RESET%^%^CYAN%^A fine %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r "
"%^RESET%^%^CYAN%^chain supports this small and simple amulet, perhaps an inch across in size.  It is cut in the shape of "
"a %^GREEN%^sc%^ORANGE%^ar%^GREEN%^ab be%^ORANGE%^et%^GREEN%^le%^CYAN%^, with paired wings folded across its back and its "
"six legs curled about itself to either side.  The insect is carved from a solid piece of %^ORANGE%^to%^RED%^m%^ORANGE%^b "
"jade%^CYAN%^, chalky brown in appearance and fairly unimpressive compared to the usual vibrant green of jade stones.  "
"Perhaps not overly valuable, the jewelry nonetheless bears a %^ORANGE%^ru%^RESET%^s%^ORANGE%^tic charm %^CYAN%^to its "
"simple design.%^RESET%^\n");
    set_lore("The scarab is one of several symbols that are sacred to the church of Kelemvor, Lord of the Dead, and "
"is similarly favored by that of his successor.  Such jewelry as this is as precious as it is rare, and only ever "
"held by those who have enacted some task of considerable worth to their service.  As a sign of favor, it is said to "
"grant the wearer reprieve even from the jaws of death, that they might be spared the wall and the afterlife to live "
"again, if they so wish.  But only one such chance is given, for the natural order of life and death cannot be denied "
"save in the rarest of circumstances.");
    set_property("lore difficulty",15);
    set_property("id difficulty",15);
    set_weight(1);
    set_value(0);
    set_type("ring");
    set_limbs(({"neck"}));
    set_ac(0);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    tell_object(ETO,"%^RESET%^%^ORANGE%^You feel a shroud of the protection settle upon you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" looks calm and assured.%^RESET%^",ETO);
    ETO->set_property("rebirth",TO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^RESET%^%^ORANGE%^The feeling of protection leaves you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" loses "+ETO->QP+" air of assurance.%^RESET%^",ETO);
    if(ETO->query_property("rebirth")) ETO->remove_property("rebirth");
    return 1;
}

int isMagic(){ return 1; }
int drop(){ return 1;}