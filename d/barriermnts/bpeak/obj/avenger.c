#include <std.h>

inherit "/d/common/obj/weapon/double_bladed_sword.c";

create() {
    ::create();
   set_id(({ "sword","giant sword","double bladed sword","avenger","pole" }));
   set_name("%^BOLD%^%^RED%^The avenger%^RESET%^");
   set_short("%^BOLD%^%^RED%^The avenger%^RESET%^");
   set_obvious_short("%^RESET%^A massive double bladed sword");
   set_long("%^RESET%^This large weapon is quite impressive to look at.  A huge, %^BOLD%^shining blade%^RESET%^"
" is attached to either side of a long %^ORANGE%^shaft %^RESET%^that has been wrapped in %^ORANGE%^leather"
" %^RESET%^for added grip.  The %^ORANGE%^leather %^RESET%^appears to be well worn from excess use, giving"
" you sight of the material that lies beneath in a few of the more worn places.  Instead of a"
" %^ORANGE%^wooden shaft %^RESET%^like one might expect, the shaft is made of %^BOLD%^%^BLACK%^dark obsidian."
"  %^RESET%^Glimpses of %^CYAN%^shifting runes %^RESET%^can be seen running up and down the parts of the"
" %^BOLD%^%^BLACK%^shaft %^RESET%^that peek through the wearing %^ORANGE%^leather.  %^RESET%^Upon the"
" right %^BOLD%^blade, %^RESET%^the word %^BOLD%^%^RED%^Avenger %^RESET%^has been etched in, and has somehow"
" been dyed %^RED%^blood red%^RESET%^.");
   set_lore("It is said that this type of weapon was once used by great warriors of Tempus during heated battles back in the gladitorial days.  Ones bearing the name '%^BOLD%^%^RED%^Avenger%^RESET%^' were only awarded to great warriors who won many battles, and managed to prove their worth.");
   set("value",1000);
   set_cointype("gold");
   set_property("enchantment",2);
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",2);
      set_wield((:this_object(),"wield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((int)ETO->query_level() < 15) {
      tell_object(ETO,"%^RESET%^%^RED%^You do not have the power to wield such an awesome weapon yet!%^RESET%^");
                return 0;
   }
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" grips the shaft of the weapon and quickly slashes one end to the right and the other to the left.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^You grip the shaft of the weapon and quickly slash one blade to the right and the other to the left.%^RESET%^");
      return 1;
}

int hit_func(object target) {
   if(!objectp(target)) return 0;
    if(random(1000) < 325){
      switch(random(5)){
         case 0:
  	      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" lunges forward and smashes the center of the shaft straight into "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You lunge forward and smash the center of the shaft straight into  "+target->query_cap_name()+"!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" lunges towards you and smashes the center of the shaft right into you!%^RESET%^");
             target->set_paralyzed(20,"Damn damn damn that hurt for a blunt blow!");
            target->do_damage("torso",random(5)+1);
         break ;
           case 1..3:
           ETO->execute_attack();
tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" stabs one blade of "+ETO->query_possessive()+" into "+target->query_cap_name()+" with primal savagery before flipping the sword to strike again with the other!%^RESET%^",({target,ETO}));
       tell_object(ETO,"%^RESET%^%^RED%^You stab one blade of your weapon into "+target->query_cap_name()+" primal savagery before expertly flipping the sword to strike again with the other!%^RESET%^");
tell_object(target,"%^RESET%^%^RED%^"+ETO->query_cap_name()+" stabs one blade of "+ETO->query_possessive()+" into "+ETO->query_possessive()+" with primal savagery before expertly flipping the sword to strike again with the other!%^RESET%^");
            target->do_damage("torso",random(10)+1);
      }
   }
}
