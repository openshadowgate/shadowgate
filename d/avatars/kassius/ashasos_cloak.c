#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/clothing/cloak.c";

void create()
{
    ::create();
    set_name("cloak of the winds");
    set_id(({"cloak of the winds","silk cloak","cloak"}));

   set_obvious_short("%^RESET%^%^CYAN%^A silk cloak%^RESET%^");

   set_short("%^RESET%^%^BOLD%^%^CYAN%^silk c%^WHITE%^l%^CYAN%^o%^WHITE%^a%^CYAN%^k %^R"
   "ESET%^%^CYAN%^of the %^BOLD%^w%^WHITE%^i%^CYAN%^n%^WHITE%^d%^CYAN%^s%^RESET%^");

   set_long("%^RESET%^%^CYAN%^This %^BOLD%^cloak %^RESET%^%^CYAN%^is made of the finest %^BO"
   "LD%^silk %^RESET%^%^CYAN%^and skill.  At least you assume it is made of %^BOLD%^silk %^R"
   "ESET%^%^CYAN%^because it looks as %^BOLD%^%^WHITE%^light %^RESET%^%^CYAN%^as a %^BOLD%^f"
   "%^WHITE%^e%^CYAN%^ath%^WHITE%^e%^CYAN%^r %^RESET%^%^CYAN%^and so thin you can see through"
   " it like looking through thick %^BOLD%^b%^WHITE%^o%^CYAN%^%^WHITE%^t%^CYAN%^le g%^WHITE%^"
   "l%^CYAN%^a%^WHITE%^s%^CYAN%^s%^RESET%^%^CYAN%^.  The %^BOLD%^c%^WHITE%^l%^CYAN%^o%^WHITE%"
   "^a%^CYAN%^k %^RESET%^%^CYAN%^moves about as if it is always being caressed by unfelt gust"
   "s of %^BOLD%^air%^RESET%^%^CYAN%^, but never seems to impede the wearer in any way.  The "
   "%^BOLD%^c%^WHITE%^l%^CYAN%^o%^WHITE%^a%^CYAN%^k %^RESET%^%^CYAN%^is very %^BOLD%^%^MAGENTA"
   "%^soft %^RESET%^%^CYAN%^to the touch and has a faint %^BOLD%^blue %^RESET%^%^CYAN%^tint an"
   "d gives the impression of a %^BOLD%^%^WHITE%^cloudless %^CYAN%^sky%^RESET%^%^CYAN%^.%^RESET%^" );

   set_lore("%^CYAN%^This garment was crafted by the genasi Ashasos eben Alriah.  It is unknown "
   "what his last name really is as he most likely took the last name 'eben Alriah' with a nod t"
   "o his air genasi heritage and means only 'son of the wind.'  Being of noble birth he would b"
   "e loathe to admit to this work, but secretly he is very proud." );

    set_weight(2);


    set_property("enchantment",7);

    set_item_bonus("magic resistance",2);
    set_item_bonus("fortitude",6);

    set_value(27500);

    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));


}


int wear_me()
{
tell_object(ETO,"%^BOLD%^%^RESET%^The cloak slips around your shoulders weightlessly, the soft silk gently rustling around you.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^RESET%^"+ETOQCN+"%^BOLD%^%^BLACK%^ ties a long dark cloak around "+ETO->QP+" %^BOLD%^%^BLACK%^shoulders,"
    "the soft silk gently rustling%^RESET%^.",ETO);
                  ETO->add_temporary_feat("blindfight");
   return 1;
}


int remove_me()
{
   tell_object(ETO,"%^BOLD%^%^CYAN%^You miss the softness  of the silk.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" %^BOLD%^%^CYAN%^removes the cloak and sets "+ETO->QP+"  it aside.%^RESET%^",ETO);
   ETO->remove_temporary_feat("blindfight");
   return 1;
}

