#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
   ::create();
   set_name("ragged gloves");
   set_id(({"ragged gloves","gloves"}));
   set_short("%^RESET%^%^BLUE%^a hazy pair of ragged gloves%^RESET%^");
   set_long("%^RESET%^Nothing more than %^CYAN%^air %^RESET%^and %^BLUE%^shadows %^RESET%^make up these gloves, barely holding together.  They look like the tattered remains of what might have once been an expensive garment, showing traces of %^YELLOW%^golden embroidery %^RESET%^and patterning over finely-woven cloth.  Now, though, even through their misty substance "
"you can see %^BOLD%^%^BLACK%^raggedly torn edges %^RESET%^and %^ORANGE%^smudges %^RESET%^of insubstancial dirt.  You can't tell if they are truly real or not, but either way they seem not to hold value as they once might have done.\n");
   set_property("enchantment",1);
   set_size(3);
   set_weight(4);
   set_value(0);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

void init() {
   ::init();
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !avatarp(TP)) {
     tell_object(TP,"The gloves disintegrate into a fine mist, falling free of your hands.");
     TO->remove();
   }
}

int wield_fun() {
   if(!avatarp(ETO)) {
     tell_object(ETO,"The robe disintegrates into a fine mist, falling free of your hands.");
     TO->remove();
     return 0;
   }
   ETO->add_hit_bonus(20);
   ETO->set_property("spell penetration",20);
   return 1;
}

int remove_fun() {
   ETO->add_hit_bonus(-20);
   ETO->set_property("spell penetration",-20);
   return 1;
}

int hit_fun(object targ) {
   int mydam;
   targ = ETO->query_current_attacker();
   if(random(3)) {
     switch(random(10)) {
       case 0..1:
       new("/cmds/wizard/_cone_of_cold")->use_spell(ETO,targ,25);
       return 1;
       break;
       case 2..4:
       new("/cmds/priest/_spectral_touch")->use_spell(ETO,targ,25);
       return 1;
       break;
       case 5..6:
       new("/cmds/priest/_frost_breath")->use_spell(ETO,targ,25);
       return 1;
       break;
       case 7..9:
       tell_room(EETO,"%^RESET%^%^BLUE%^"+ETOQCN+" reaches out a grasping hand "
"towards you, and where he touches skin you feel your life draining "
"away!%^RESET%^");
       mydam = roll_dice(10,10);
       targ->do_damage(targ->return_target_limb(),mydam);
       ETO->do_damage("head",(-1)*mydam);
       return 1;
       break;
     }
   }
}
