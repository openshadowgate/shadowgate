#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("circlet");
        set_id(({ "circlet", "white circlet", "moon circlet" }));
        set_short("%^BOLD%^%^WHITE%^A delicate little circlet%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This finely woven circlet shines with a light as though it were made"
" from the moonlight itself.  The crown is delicate and wreath like, with complex lines that weave around each"
" other much like intricate, moonlit vines.  Within each of the tiny strands, small illuminations of"
" %^CYAN%^aqua moons %^BOLD%^%^WHITE%^shimmer into view and then disappear.\n");
        set_weight(0);
        set_value(2500);
        set_lore(
@AVATAR
%^BOLD%^%^WHITE%^This circlet is said to have been carved out of the glowing white substance known as moonfire, by the priestess Shrydelhi herself during a healing ceremony.  Moonfire is known to have many wonderful qualities and is often treasured by the followers of Selune.

AVATAR
        );
        set_type("leather");
        set_limbs(({ "head" }));
        set_size(1);
    set_property("enchantment",2);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   set_heart_beat(5);
}
int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^A soft silvery glow encompasses "+ETOQCN+".%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^A soft silvery glow bathes you as you wear the circlet.%^RESET%^");
   ETO->set_property("spell penetration",5);
   ETO->set_property("empowered",1);
   return 1;
}
int unwearme(string str){
   ETO->set_property("spell penetration",-5);
   ETO->set_property("empowered",-1);
   return 1;
}
void heart_beat(){
  if(ETO && living(ETO)){
    if(TO->query_worn()){
      if((int)ETO->query_hp() >= (int)ETO->query_max_hp()){
          return;
      }
    ETO->add_hp(roll_dice(1,5));
    tell_room(ETO,"%^BOLD%^%^WHITE%^A milky white glow envelopes you as the power of Selune's healing begins to mend your wounds.");
    } 
   }
}
