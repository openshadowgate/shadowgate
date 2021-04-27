#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create() {
   ::create();
   set_name("bracers");
   set_short("%^BOLD%^%^BLACK%^Shackles of the %^BOLD%^%^RED%^D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^o%^BOLD%^%^RED%^n%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^Black steel bracers%^RESET%^");
   set_id(({"bracer","bracers","black bracers","steel bracers","shackles"}));
   set_long("%^BOLD%^%^BLACK%^At first glance, this appear to be a pair "
"of%^RESET%^ %^WHITE%^solid steel %^BOLD%^%^BLACK%^bracers that have been "
"covered with ash or coal dust, but on closer inspection, there are numerous "
"jagged cracks within the metal, forming a chaotic, though noticable pattern. "
"The inside of the bracers are lined with torn and ancient cloth. The metal "
"is%^RESET%^ %^CYAN%^cold %^BOLD%^%^BLACK%^to the touch, though feels as "
"though there is something deeper to it... Something "
"%^YELLOW%^dangerous%^BOLD%^%^BLACK%^. Something "
"%^BOLD%^%^GREEN%^vol%^RESET%^%^GREEN%^at%^BOLD%^%^GREEN%^ile%^BOLD%^%^BLACK%^"
". Something %^BOLD%^%^RED%^po%^RESET%^%^RED%^werf"
"%^BOLD%^%^RED%^ul%^BOLD%^%^BLACK%^.%^RESET%^\n");
   set_weight(5);
   set_value(1025);
   set_ac(1);
   while((int)TO->query_property("enchantment") < 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
}

int check() {
   ::check();
/*   if((string)TP->query_diety() != "talos") {
     tell_object(ETO,"The bracers don't seem to fit you.");
     tell_room(EETO,"The bracers don't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   } */
   tell_object(ETO,"%^BOLD%^%^RED%^Demonic %^BOLD%^%^BLACK%^power seethes "
"through your veins, giving you %^BOLD%^%^GREEN%^unholy "
"%^BOLD%^%^BLACK%^power.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" wears the bracers, jagged "
"%^BOLD%^%^RED%^red %^BOLD%^%^BLACK%^bolts of %^YELLOW%^power "
"%^BOLD%^%^WHITE%^flashing %^BOLD%^%^BLACK%^along "+ETO->QP+
" arms.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
     tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the bracers, feeling "
"substantially %^BOLD%^%^GREEN%^weaker%^BOLD%^%^BLACK%^.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" removes the bracers, the "
"power in "+ETO->QP+" arms%^RESET%^ "
"%^WHITE%^fading%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"%^RED%^You feel a surge of %^YELLOW%^power%^RESET%^ "
"%^RED%^course through you, before unleashing its fury on your "
"prey!%^RESET%^");
     tell_object(target,"%^RED%^A surge of demonic %^YELLOW%^power%^RESET%^ "
"%^RED%^jumps from "+ETO->QCN+" to you, scorching your flesh!%^RESET%^");
     tell_room(EETO,"%^RED%^A surge of%^RESET%^ %^YELLOW%^energy%^RESET%^ "
"%^RED%^streaks across "+ETO->QCN+", sending the temperature "
"soaring!%^RESET%^",({ETO,target}));
     target->do_damage(target->return_target_limb(),random(4)+6);
   }
   return 1;
}
