#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
      set_name("gown of white and gold");
      set_id(({"gown","gold gown","white gown","goldheart's gown","Goldheart's Gown"}));
      set_short("%^RESET%^%^ORANGE%^G%^YELLOW%^ol%^RESET%^%^ORANGE%^dh%^YELLOW%^ear%^RESET%^%^ORANGE%^t's G%^YELLOW%^ow%^RESET%^%^ORANGE%^n%^RESET%^");
      set_obvious_short("%^RESET%^%^MAGENTA%^gown of %^BOLD%^%^WHITE%^white %^RESET%^%^MAGENTA%^and %^ORANGE%^g%^YELLOW%^ol%^RESET%^%^ORANGE%^d%^RESET%^");
      set_long("%^RESET%^This is a beautiful long and flowing gown, "
"obviously cut to fit a curvaceous figure.  It has been crafted from "
"fine, soft %^BOLD%^%^WHITE%^i%^YELLOW%^v%^RESET%^%^WHITE%^ory%^RESET%^ "
"silk that shimmers with flecks of %^ORANGE%^go%^YELLOW%^l%^RESET%^"
"%^ORANGE%^d%^RESET%^.  %^YELLOW%^Go%^RESET%^%^ORANGE%^ld%^YELLOW%^en "
"%^RESET%^embroidery traces its way around the cuffs, hem and high collar"
".  Together with the long fitted sleeves, it would leave plenty to the "
"imagination, were the dress not so well fitted and figure-hugging.  It "
"tapers down to a narrow waistline, then flares out to cascade almost to "
"the floor in this pretty %^MAGENTA%^princess %^RESET%^design.  A small "
"split parts the dress to mid-thigh, showing flashes of %^ORANGE%^go"
"%^YELLOW%^ld%^RESET%^%^ORANGE%^en %^RESET%^lining beneath when the wearer "
"moves.\n%^RESET%^");
        set_lore("This was once said to have been a Gown of Leaves, "
"transformed by the hand of Hanali Celanil for her faithful priestess "
"Ygdra'salia. Together with a gathering of elvenkind, a ritual was "
"enacted to beseech the Seldarine to restore the drow allies of "
"Rilynath, once elves, to their rightful forms following a curse "
"put upon them by the sun elves of Selu'havessthyr. With the combined "
"strength of the elves, Ygdra'salia aided in the ritual's success, and "
"was blessed by the touch of Hanali for her efforts.");
    set_property("lore difficulty",25);
    set_weight(5);
    set_value(0);
    set_ac(0);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_size(-1);
    set_property("enchantment",2);
    set_item_bonus("charisma",1);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"unwearme":));
}

int wearme(string str){
    if((string)ETO->query_name() != "ygdrasalia" && !avatarp(ETO)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The beautiful gown seems not to fit you.%^RESET%^");
      return 0;
    }
    tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" smiles softly as "+ETO->QS+" slips into the gown.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^You slip into the gown and can't help but smile, you know it makes you look gorgeous.%^RESET%^");
    return 1;
}

int unwearme(string str){
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" reluctantly removes the gown.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^You already miss the touch of the silken gown.%^RESET%^");
    return 1;
}
