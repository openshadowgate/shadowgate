#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("leather pants");
   set_id(({"pants","leather pants"}));
   set_short("%^BOLD%^%^BLACK%^form-fitted leather pants%^RESET%^");
   set_long("%^ORANGE%^Made from strong, yet tough leather is this pair of "
"%^BOLD%^%^BLACK%^dark pants%^RESET%^%^ORANGE%^, obviously form-fitted for "
"a male's body.  The leather is thick enough to protect the body, but thin "
"enough to allow full freedom of movement. The pants fit %^RED%^tightly "
"%^ORANGE%^from waist to ankle, allowing no part to flare free and obstruct "
"the wearer's motions. No ornamentation marks their tanned surface, leaving "
"them far more practical than ornate, although they would certainly serve to "
"enhance an already well-built figure.%^RESET%^");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_property("enchantment",4);
   set_item_bonus("charisma",1);
   set_lore("Commonly used by travellers as well as more roguish adventurers, "
"these pants are commonly preferred for their functionality of movement, as "
"well as their relatively mundane appearance, leaving no distractions or "
"obstructions in combat or travel.");
   set_property("lore",6); 
   set_weight(2);
   set_size(2);
   set_value(1500);
   set_wear((:TO,"wearme":));
}

int wearme(){
   if((string)ETO->query_gender() != "male"){
     tell_object(ETO,"Try as you might, you just can't fit into the pants!");
     return 0;
   }
   if((int)ETO->query_level() < 25) {
    tell_object(ETO,"The pants don't fit you!");
        return 0;
   }
   tell_object(ETO,"%^BLUE%^The pants hug your legs like a second skin.%^RESET%^");
   tell_room(EETO,"%^BLUE%^The pants hug to "+ETOQCN+"'s legs like a second skin.%^RESET%^",ETO);
   return 1;
}
