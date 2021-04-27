#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create() {
    ::create();
    set_name("shortsword");
    set_id(({"sword","shortsword","short sword","light sword","light shortsword","light short sword","blade","blade of the maelstrom","maelstrom blade","maelstrom sword","maelstrom"}));
    set_short("%^WHITE%^%^BOLD%^Blade of the %^BLACK%^M%^WHITE%^a%^CYAN%^e%^WHITE%^l%^BLACK%^s%^WHITE%^t%^CYAN%^r%^WHITE%^o%^BLACK%^m%^RESET%^");
    set_obvious_short("%^WHITE%^%^BOLD%^A light shortsword%^RESET%^");
    set_long("%^CYAN%^This short sword is a smaller version of the standard blade, honed to a sharp edge and "
"uncharacteristically lightweight.  The blade carries rather an interesting pattern of gentle,%^WHITE%^%^BOLD%^"
" c%^CYAN%^h%^WHITE%^a%^BLACK%^o%^WHITE%^t%^CYAN%^i%^WHITE%^c%^RESET%^%^CYAN%^ whorls across its surface, "
"probably residual of the smithing technique used to create it.  It meets at a simple, upturned crosspiece, "
"below which %^ORANGE%^light leather straps%^CYAN%^ bind the hilt in a comfortable grip.%^RESET%^");
   set_value(550);
   set_weight(3);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_lore("%^WHITE%^%^BOLD%^Little is known of this weapon's origins, but many tales tell of the warrior who "
"carried it.  A half-elf by the name of Khar'hazt found the blade on one of his many travels, and was said to "
"have taken a distinct liking to the weapon's rather unique appearance.  For his efforts over the years to aid "
"the temple of Akadi, he was granted by the priesthood to have a blessing bestowed upon the blade for "
"sturdiness, a keen edge, and near supernatural speed.  By his own skills at magecraft, it is rumoured that he "
"later imbued the blade with another enchantment.  The enchantment was said to hide all but the smallest glow "
"of magic from the weapon, in order to make it look more nondescript to others.%^RESET%^\n");
   set_property("lore difficulty",16);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun(){
    tell_object(ETO,"%^WHITE%^%^BOLD%^You spin the shortsword once and grasp it by the hilt.%^RESET%^");
    tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" spins the shortsword deftly and grasps its leatherbound hilt."
"%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You release the lightweight shortsword.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" releases "+ETO->QP+" light shortsword.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   targ = ETO->query_current_attacker();
   if(random(25)<2){
     switch(random(20)){
       case 0..7:
       ETO->execute_attack();
       tell_object(ETO,"%^WHITE%^%^BOLD%^You whirl in a flurry of motion, slashing rapidly at "+targ->QCN+
"!%^RESET%^");
       tell_object(targ,"%^WHITE%^%^BOLD%^"+ETOQCN+" whirls in a flurry of motion, slashing repeatedly at "
"you!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" whirls in a flurry of motion, slashing repeatedly at "
+targ->QCN+"!%^RESET%^",({ETO,targ}));
       return 1;
       break;

       case 8..19:
       tell_object(ETO,"%^CYAN%^%^BOLD%^You lunge forward in an attack at "+targ->QCN+", your blade seeming to lend you unnatural speed!%^RESET%^");
       tell_object(targ,"%^CYAN%^%^BOLD%^"+ETOQCN+" lunges forward at you with almost supernatural "
"speed!%^RESET%^");
       tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" lunges forward at "+targ->QCN+" with almost supernatural "
"speed!%^RESET%^",({ETO,targ}));
       targ->do_damage(targ->return_target_limb(),random(8)+5);
       break;
     }
   }
   return 1;
}

int isMagic() { return 1; }
