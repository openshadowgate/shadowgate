#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

object ob,*names;
int i;

void create() {
   ::create();
   set_id(({"hairpin","pin","Hairpin","Pin","ebony hairpin","dagger","Dagger","ebony dagger","black talon","talon","hairpin dagger","black talon dagger"}));
   set_name("black talon");
   set_obvious_short("%^BLACK%^%^BOLD%^ebony hairpin%^RESET%^");
   set_short("%^BLACK%^%^BOLD%^Black Talon%^RESET%^");
   set_long("%^MAGENTA%^This elegant hairpin is crafted from a single piece of "
"%^BLACK%^%^BOLD%^flawless ebony%^RESET%^%^MAGENTA%^.  The handle is shaped to fit "
"comfortably within one's hand, and is carved in an ornate fashion, set with tiny "
"chips of %^BOLD%^%^MAGENTA%^am%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^th%^WHITE%^y%^MAGENTA%^st%^RESET%^%^MAGENTA%^ "
"and %^BOLD%^%^WHITE%^di%^CYAN%^a%^WHITE%^mond%^RESET%^%^MAGENTA%^, that glitter darkly in any reflected "
"light.  A smooth, slender point extends from this handle, to be placed through the hair, "
"though this hairpin seems uncharacteristically sharp - you could probably use it as quite "
"an effective weapon.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^A particularly distinct accessory created by crafters hired "
"by the temple of the Black Hand, and gifted to the reknowned assassin Tatsu'ei, as a "
"reward for her service in the temple's name.  Some rumours tell it to be more than simply "
"a pretty hairpiece, but quite dangerous in her hands also.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_weight(3);
   set_property("enchantment",3);
   set_value(1025);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   set_heart_beat(1);
}

int wield_fun() {
   if(!avatarp(ETO)) return 0;
   if(!ETO->query_invis()) {
     tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" grasps the smooth-handled hairpin in one hand... suddenly the "
"sharpened point of the hairpiece looks a good deal more dangerous!%^RESET%^",ETO);
   }
   tell_object(ETO,"%^MAGENTA%^You grasp the smooth-handled hairpin within your hand, realising the "
"sharpened point would be quite an effective weapon!%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" releases "+ETO->QP+" grip on the sharpened "
"hairpin.%^RESET%^",ETO);
   tell_object(ETO,"%^MAGENTA%^You release your grip on the sharpened hairpin.%^RESET%^");
   return 1;
}

void __ActuallyUnwield() {
   ::__ActuallyUnwield();
   ob = new("/d/avatars/nienne/hairpin.c");
   ob->move(ETO);
   while((int)ob->query_property("enchantment") != 1) {
     ob->remove_property("enchantment");
     ob->set_property("enchantment",1);
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob->add_identified(names[i]);
     }
   }
   TO->remove();
}

int hit_fun(object target) {
   if(!random(5)) {
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" stabs at "+target->QCN+" with the sharpened point of "
"the hairpin!%^RESET%^",({ETO,target}));
     tell_object(ETO,"%^WHITE%^%^BOLD%^You quickly stab at "+target->QCN+" with the sharpened point of "
"the hairpin!%^RESET%^");
     tell_object(target,"%^WHITE%^%^BOLD%^"+ETOQCN+" stabs quickly at you with the sharpened point of "
"the hairpin!%^RESET%^");
     target->do_damage(target->return_target_limb(),roll_dice(1,6)+6);
   }
}
