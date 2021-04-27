#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create() {
    ::create();
    set_name("MFGA cap");
    set_id(({"cap","MFGA cap","mfga cap","red cap"}));
    set_short("%^BOLD%^%^RED%^a cap emblazoned with %^BOLD%^%^WHITE%^MFGA%^RESET%^");
    set_long("%^BOLD%^%^RED%^This distinctive red cap is the emblem of the soon-to-be-well-known campaign for %^BOLD%^%^WHITE%^MFGA "
"- Make Fighters Great Again%^BOLD%^%^RED%^.%^RESET%^\n");
    set_lore("%^BOLD%^%^WHITE%^'When Tharis are sending their people, they're not sending their best. They're bringing powder. "
"They're bringing theft. They're assassins. And some, we assume, are good people.'\n\n"
    "%^BOLD%^%^WHITE%^'We know swords. We have the best swords.'\n\n"
    "%^BOLD%^%^WHITE%^'Filthy mages, stealing our AC and our BAB, bringing 'simulated skills' of 'spells' as they're called on the "
"street.'\n\n"
    "%^BOLD%^%^WHITE%^'We will build a great, great wall on our southern border, and we will make the weretigers pay for that "
"wall.'\n\n"
    "%^BOLD%^%^WHITE%^'We could stand in the middle of Shadow and disintegrate someone, and we wouldn't lose supporters.'\n\n"
    "%^BOLD%^%^WHITE%^'DRAIN THE MUD.'\n");
    set_value(0);
    set_type("ring");
    set_item_bonus("influence",25);
    set_item_bonus("wisdom",-6);
    set_item_bonus("intelligence",-6);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    tell_object(ETO,"%^BOLD%^%^RED%^You settle the cap upon your head. You feel like you could run the realm and fix all of the things!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+" settles the cap upon "+ETO->QP+" head, and "+ETO->QP+" eyes glaze over as "+ETO->QS+" gives a stupid little smile.%^RESET%^",ETO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^RED%^You feel your intellect slowly seeping back in.%^RESET%^");
    return 1;
}
