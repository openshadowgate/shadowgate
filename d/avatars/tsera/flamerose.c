#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("%^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^YELLOW%^a%^RESET%^%^RED%^m%^BOLD%^eR%^RESET%^%^MAGENTA%^o%^RED%^s%^BOLD%^e%^RESET%^%^RED%^");
        set_id(({ "flamerose","pin","brooch","rose","flame","clasp","cloak clasp" }));
        set_short("%^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^YELLOW%^a%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^%^MAGENTA%^o%^RED%^s%^BOLD%^e%^RESET%^%^RED%^");
        set_obvious_short("%^RESET%^%^MAGENTA%^A perfectly carved %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^%^RED%^r%^BOLD%^%^MAGENTA%^o%^RED%^s%^RESET%^%^RED%^e%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^A %^BOLD%^%^RED%^r%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se"
        " %^RESET%^%^ORANGE%^carved perfectly from a single %^BOLD%^%^RED%^r"
        "%^RESET%^%^RED%^u%^BOLD%^by %^RESET%^%^ORANGE%^is forever trapped in time as it"
        " first starts to %^MAGENTA%^bloom%^ORANGE%^.  Thick %^BOLD%^%^WHITE%^iv%^RESET%^o%^BOLD%^ry"
        " %^RESET%^%^ORANGE%^makes up the pin of this piece, from which two carved pieces of "
        " %^BOLD%^%^RED%^fl%^YELLOW%^a%^RED%^m%^RESET%^%^RED%^e%^BOLD%^d%^YELLOW%^a%^RED%^"
        "n%^RESET%^%^RED%^c%^BOLD%^e %^RESET%^%^ORANGE%^serve as %^RED%^delicate"
        " %^BOLD%^l%^RESET%^%^RED%^e%^ORANGE%^a%^YELLOW%^v%^RED%^e%^RESET%^%^RED%^s"
        "%^ORANGE%^, poetically shaped such that they look as though they were"
        " %^BOLD%^%^RED%^fl%^YELLOW%^a%^RED%^mes %^RESET%^%^ORANGE%^reaching up to "
        "%^RED%^engulf %^ORANGE%^the %^RED%^l%^BOLD%^a%^RESET%^%^RED%^rge"
        " %^BOLD%^pe%^RESET%^%^RED%^t%^BOLD%^a%^RESET%^%^RED%^l%^BOLD%^s"
        " %^RESET%^%^ORANGE%^trapped unfurling above them.  This piece looks as though it"
        " would serve as an %^CYAN%^exquisite %^ORANGE%^piece of %^CYAN%^art "
        "%^ORANGE%^that can be worn either as a pin, a brooch, or even as a clasp for"
        " ones cloak.\n%^RESET%^");
        set_weight(1);
        set_value(1000);
        set_lore(
@AVATAR
  	%^RESET%^%^RED%^This pin is known as the %^BOLD%^%^RED%^F%^RESET%^%^RED%^l%^YELLOW%^a%^RED%^m%^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^%^MAGENTA%^o%^RED%^s%^BOLD%^e%^RESET%^%^RED%^ and was said to have been given out to attendees of the %^MAGENTA%^festival %^RED%^hosted by the temples of %^BOLD%^Kossuth %^RESET%^%^RED%^and %^BOLD%^Sune %^RESET%^%^RED%^in the city of %^CYAN%^Torm %^RED%^on %^GREEN%^12 Growingdays, 712 SG  %^RED%^It is said that the %^BOLD%^f%^YELLOW%^i%^RED%^res %^RESET%^%^RED%^of %^BOLD%^passion %^RESET%^%^RED%^will protect the bearer of the %^BOLD%^r%^MAGENTA%^o%^RED%^se %^RESET%^%^RED%^from the %^CYAN%^c%^BOLD%^%^WHITE%^o%^RESET%^%^CYAN%^ld%^RED%^.%^RESET%^

AVATAR
        );
        set_type("ring");
        set_limbs(({ "torso" }));
  	  set_wear((:TO,"wearme":));
        set_item_bonus("cold resistance",5);

}
int wearme(string str){
   tell_object(ETO,"%^RESET%^%^RED%^The ruby pin feels warm against your chest, and you feel emboldened by its protection.%^RESET%^");
   return 1;
}







