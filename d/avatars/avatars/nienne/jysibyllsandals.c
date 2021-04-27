#include <std.h>
inherit "/d/common/obj/clothing/shoes";

int activefeat;

void create() {
   ::create();
   set_name("sandals");
   set_id(({"sandals","delicate sandals","vined sandals","black vined sandals","delicate black-vined sandals","footfalls","Feytouched Footfalls","feytouched footfalls"}));
   set_short("%^BOLD%^%^BLACK%^Fe%^RESET%^yt%^BOLD%^%^WHITE%^ou%^RESET%^ch%^BOLD%^%^BLACK%^ed F%^RESET%^oo%^BOLD%^%^WHITE%^tf%^RESET%^al%^BOLD%^%^BLACK%^ls%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^delicate b%^RESET%^l%^BOLD%^%^WHITE%^a%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^-%^BOLD%^%^BLACK%^v%^RESET%^i%^BOLD%^%^WHITE%^n%^RESET%^e%^BOLD%^%^BLACK%^d sandals%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^These sandals appear infinitely fragile, somehow a pair of %^RESET%^%^GREEN%^liv%^BOLD%^%^GREEN%^i"
"%^RESET%^%^GREEN%^ng en%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^it%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^es %^BOLD%^%^WHITE%^grown and "
"shaped to be worn as a garment. Soft but surprisingly sturdy leaves have been layered to form the soles, their broad outlines "
"%^BOLD%^%^BLACK%^darkened %^RESET%^almost to a shade of black. From their edges rise tendrils of a similarly "
"%^BOLD%^%^BLACK%^ashen %^BOLD%^%^WHITE%^hue, writhing and coiling about each other as much smaller leaves branch away here and "
"there, and likely long enough to ensnare almost to the wearer's knees. In stark contrast to the dark leaves and vines, tiny "
"%^RESET%^snowy-white %^BOLD%^%^WHITE%^blossoms spread their petals in %^RESET%^%^MAGENTA%^delicate %^BOLD%^%^WHITE%^whorls at "
"intervals along their length. They are quite dainty and lovely, and look quite light and comfortable.\n");
    while ((int)TO->query_property("enchantment") != 5) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
    }
    set_lore("%^BOLD%^%^WHITE%^Such an item as this, still-living even while it is worn, could only bear the touch of the fey. "
"Such is both their command of, and their bond to, the natural living world that even their possessions and equipment may be "
"drawn straight from the wilderness. As such, they are often imbued with traits of the wilderness, whether that may be a garment "
"that is never snagged by thorn or branch, or shoes that can walk without leaving a trail.");
    set_value(7500);
    set_item_bonus("survival",4);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    if((string)ETO->query_name() != "jysibyll" && !avatarp(ETO)) {
      tell_object(ETO,"You can't figure out how to wrap the vines about your feet and legs.");
      tell_room(EETO,""+ETO->QCN+" can't seem to figure out how to wrap the vines about "+ETO->QP+" feet and legs.",ETO);
      return 0;
    }
    tell_object(ETO,"%^GREEN%^You set your foot upon the leafy soles, and the dark v%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^nes creep "
"their way up your legs like liv%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng creatures.%^RESET%^");
    tell_room(EETO,"%^GREEN%^"+ETO->QCN+" sets "+ETO->QP+" feet upon the leafy soles, and the dark v%^BOLD%^%^GREEN%^i%^RESET%^"
"%^GREEN%^nes creep their way up "+ETO->QP+" legs like liv%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng creatures.%^RESET%^",ETO);
    if(member_array("tracklessstep",(string*)ETO->query_temporary_feats()) == -1) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^Your footfalls feel as light as air! See <help tracklessstep> for syntax.%^RESET%^");
      ETO->add_temporary_feat("tracklessstep");
      activefeat = 1;
    }
    return 1;
}

int removeme() {
    tell_object(ETO,"%^GREEN%^The vines uncoil themselves from about your calves and feet.%^RESET%^");
    if(activefeat) ETO->remove_temporary_feat("tracklessstep");
    activefeat = 0;
    return 1;
}
