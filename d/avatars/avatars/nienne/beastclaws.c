#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

object claw,glove;

void create() {
   ::create();
   set_name("bloodied claws");
   set_id(({"beastclaw","claw","claws","bloodied claws","talons","talon","bloodfury talons"}));
   set_short("%^RESET%^%^WHITE%^Bloo%^RED%^d%^WHITE%^fury T%^RED%^a%^WHITE%^lons%^RESET%^");
   set_obvious_short("%^RESET%^%^WHITE%^blo%^RED%^o%^WHITE%^died cla%^RED%^w%^WHITE%^s%^RESET%^");
   set_long("%^GREEN%^This set of claws consists of three prongs, each made of what appears to be%^WHITE%^ "
"bone%^GREEN%^.  All three are honed to be %^BLUE%^wickedly sharp%^GREEN%^, along the lower edge down to the "
"tip.  The centre talon of each is longer than the rest, easily nine or ten inches in length, and partnered on "
"either side by a slightly shorter, thicker prong.  They are attached to the %^ORANGE%^rugged gloves%^GREEN%^ "
"as though they were part of them, sliding forth just between the knuckles from seemingly nowhere.  The claws "
"are mostly the color of %^WHITE%^pale ivory%^GREEN%^, save for the tips and splashes along their length of a "
"%^RED%^dull crimson substance%^GREEN%^, possibly blood.%^RESET%^\n");
   set_weight(4);
   set_value(0);
   set_prof_type("magic weapons");
   set_property("enchantment",3);
   set_property("magic",1);
   set_hit((:TO,"hit_fun":));
}

void __ActuallyUnwield() {
   ::__ActuallyUnwield();
   if(objectp(claw)) { if((int)claw->query_wielded()) {
     claw->__ActuallyUnwield();
   }}
   if(objectp(glove)) {
     if((int)glove->query_status()) { 
       tell_room(ETO,"%^ORANGE%^The %^WHITE%^claws %^ORANGE%^slide smoothly back into the gloves.%^RESET%^");
       glove->do_reset();
     }
   }
   if(ETO->query_property("magic")) ETO->remove_property("magic");
   TO->remove();
}

void set_claw(object ob1) { claw = ob1; }
void set_glove(object ob1) { glove = ob1; }

int hit_fun(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(12)) {
      tell_object(ETO,"%^RESET%^%^RED%^A surge of adrenaline rushes through you as you feel "
"the claws sink deep into "+targ->QCN+"'s flesh, making you feel invigorated!%^RESET%^");
      tell_object(targ,"%^RESET%^%^RED%^"+ETO->QCN+" grins wildly as "+ETO->QP+" claws tear "
"into "+targ->QCN+"'s flesh!%^RESET%^");
      tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+" grins wildly as "+ETO->QP+" claws tear "
"painfully into "+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));

      dam = random(5)+6;
      ETO->do_damage("torso",(-1)*dam);
      targ->do_damage(targ->return_target_limb(),dam);
      return roll_dice(1,4)+4;
      return 1;
   }

   if(!random(8)) {
      ETO->execute_attack();
      tell_object(ETO,"%^MAGENTA%^A furious rage comes over you, as you lash out wildly at "
"your foe!%^RESET%^");
      tell_object(targ,"%^MAGENTA%^A furious rage comes over "+ETO->QCN+" and "+ETO->QS+
" lashes out wildly at "+targ->QCN+"!%^RESET%^");
      tell_room(EETO,"%^MAGENTA%^A furious rage comes over "+ETO->QCN+" and "+ETO->QS+
" lashes out wildly at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      targ->do_damage(targ->return_target_limb(),random(4)+6);
      return 1;
   }

   if(!random(10)) {
      tell_object(ETO,"%^ORANGE%^You snarl viciously at "+targ->QCN+" as your claws shred "
"through "+targ->QP+" skin!%^RESET%^");
      tell_object(targ,"%^ORANGE%^"+ETO->QCN+" snarls viciously at you as "+ETO->QP+" claws "
"shred through your skin!%^RESET%^");
      tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" snarls viciously at "+targ->QCN+" as "+ETO->QP+
" claws shred through "+targ->QP+" skin!%^RESET%^",({ETO,targ}));
      targ->do_damage(targ->return_target_limb(),random(6)+4);
      return 1;
   }
}
