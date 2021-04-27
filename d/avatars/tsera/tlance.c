//Istishia wanted an altered lance for Trydos.  Changed it to accept him only as its master so that Istishia could alter it
#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bane lance");
	set_id(({ "lance", "bane lance" }));
	set_short("%^BOLD%^%^GREEN%^ Lance of the %^BOLD%^%^BLACK%^Black Hand%^RESET%^");
	set_obvious_short("A medium green lance");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This lance has been colored a rich emerald green color, making the metal hard to determine exactly what it is. The slender medium lance is polished to a bright shimmer, further adding to the majesty of such a weapon. The tip of the lance is curious though, as a %^BLACK%^black hand%^GREEN%^ made of jet has been set in place of the usual point. The hand is clenched into a tight fist and looks to be wearing a spiked gauntlet.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Bane used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
    set_weight(15);
    set("value",0);
    set_wc(1,12);
    set_large_wc(1,21);
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
    set_size(1);
    set_type("piercing");
    set_prof_type("lance");
    set_property("lance",1);
    set_wield((:TO,"wield":));
    set_unwield("You feel the power of your deity leave you as you sheath your lance.");
    set_hit((:TO,"check":));
}
int wield() {
        if((string)TP->query_name() != "trydos") {
                tell_object(ETO,"%^BOLD%^%^RED%^The lance refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the lance.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You grasp the lance and feel the power of your deity flowing through it.");
        return 1;
}

int query_size() {
    if(objectp(ETO)&&living(ETO))
        return(int)ETO->query_size()  ;
    return ::query_size();
}

int check(object targ) {
    if(!objectp(ETO)) return 0;
    if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle()))
        ETO->force_me("drop lance");
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^GREEN%^You can't help but get grin as the black "+
          "gauntleted hand tears into "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" gives you a cruel smirk as "+
          "the spiked gauntlet fist on "+ETO->QP+" lance tears into you.");
       tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" smirks to "+ETO->QO+"self as "+
          ""+ETO->QP+" lance tears into "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
