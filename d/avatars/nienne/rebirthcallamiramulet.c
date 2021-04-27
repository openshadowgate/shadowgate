#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("lucky rabbit's foot");
    set_short("%^BOLD%^%^WHITE%^Lu%^YELLOW%^ck%^BOLD%^%^WHITE%^y Ra%^YELLOW%^b%^BOLD%^%^WHITE%^bit's F%^YELLOW%^oo%^BOLD%^%^WHITE%^t%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^a small %^RESET%^furry %^ORANGE%^amulet on a %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^ORANGE%^chain%^RESET%^");
    set_id(({"amulet","furry amulet","chain","silver chain","foot","lucky rabbit's foot","rabbit foot","kelemvor-rebirth-blessing999"}));
    set_long("%^RESET%^%^CYAN%^A fine %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r "
"%^RESET%^%^CYAN%^chain supports this small and simple amulet, perhaps an inch in length.  It has the narrow form "
"and %^RESET%^soft white fur %^CYAN%^of a rabbit's foot, with soft leathery toe-pads beneath.  You're not sure if "
"it is actually a real foot, somehow preserved, or whether fur and hide have simply been crafted into a convincing "
"facsimile.  A gleaming %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^RESET%^r"
"%^BOLD%^%^BLACK%^y %^RESET%^%^CYAN%^loop secures the ankle of the paw to the amulet.  Perhaps not overly valuable, "
"the jewelry nonetheless bears a %^ORANGE%^ru%^RESET%^s%^ORANGE%^tic charm %^CYAN%^to its simple design.%^RESET%^\n");
    set_lore("The rabbit's foot is seen by many as a sign of good fortune, and was prized particularly by the faithful "
"of Tymora before her disappearance during the Silence of 738SG.  Her successor was said to similarly favor the rabbit "
"as a creature of clever wit and trickery.  Some wear amulets such as this in the belief that they will help the "
"bearer escape otherwise unwinnable situations.");
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
    tell_object(ETO,"%^RESET%^%^ORANGE%^You feel a little bit lucky!%^RESET%^");
    tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" takes on a look of confidence.%^RESET%^",ETO);
    ETO->set_property("rebirth",TO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^RESET%^%^ORANGE%^The amulet's protection leaves you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" loses "+ETO->QP+" air of assurance.%^RESET%^",ETO);
    if(ETO->query_property("rebirth")) ETO->remove_property("rebirth");
    return 1;
}

int isMagic(){ return 1; }
int drop(){ return 1;}