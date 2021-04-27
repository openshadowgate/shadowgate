#include <std.h>
inherit PARMOUR;

void create(){
    ::create();
    set_name("dark robes");
    set_id(({ "robes","vestments","vestments of loviatar","dark robes" }));
    set_short("%^BOLD%^%^BLACK%^Vestments of %^RED%^L%^RESET%^%^RED%^ov%^BOLD%^ia%^RESET%^%^RED%^ta%^BOLD%^r%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^dark robes lined with %^RED%^c%^RESET%^%^RED%^ri%^BOLD%^m%^RESET%^%^RED%^so%^BOLD%^n%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These robes have been fashioned from a "
"high grade of linen.  They have been dyed a rich deep shade of black.  "
"Inside the robes is a brilliant %^RED%^crimson satin %^BLACK%^lining.  "
"Stitched into the linen are nine strands of a whip.  You can see that "
"the deail on the whip strands are immaculate.  You can make out each "
"barb on the whips in the %^RESET%^%^RED%^deep blood red thread"
"%^BOLD%^%^BLACK%^.  The whips run from bottom to top, so that the the "
"ends of the whip details end about mid chest.  Slits and tears in the "
"cloth around the skirt area reveal the brilliant %^RED%^crimson satin "
"%^BLACK%^underneath the robes, showing a flash in intense %^RED%^red "
"%^BLACK%^as one walks.%^RESET%^\n");
    set_weight(5);
    set_value(200);
    set_ac(2);
    set_property("enchantment",3);
    set_max_internal_encumbrance(35);
    set_type("clothing");
    set_limbs(({ "torso" }));
    set_size(2);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set("chabonus",2);
    set("intbonus",1);
}

int wearme(){
    if(!avatarp(ETO)) {
      tell_object(ETO,"The robes simply refuse to conform to your body.");
      return 0;
    }
    ETO->set_property("magic resistance",20);
    return 1;
}

int removeme() {
    ETO->set_property("magic resistance",-20);
    return 1;
}
