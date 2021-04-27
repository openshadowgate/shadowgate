#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
        ::create();
        set_name("Heavenly Sunlight");
        set_id(({ "sword", "heavenly sunlight", "longsword", "long sword", "sunlight" }));
        set_short("%^BOLD%^%^YELLOW%^He%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^v%^BOLD%^%^WHITE%^en%^BOLD%^%^YELLOW%^ly S%^BOLD%^%^WHITE%^u%^BOLD%^%^YELLOW%^nlight%^RESET%^");
        set_obvious_short("longsword");
        set_long("%^BOLD%^%^YELLOW%^The blade of the sword is forged from %^BOLD%^%^WHITE%^dwarven mithril%^BOLD%^%^YELLOW%^, mined near Kinaro"+
                 " The blade is smooth, even where the sun design is etched into the blade."+
                 " The hilt is made of steel and wrapped in to %^RESET%^%^ORANGE%^wolf hide%^BOLD%^%^YELLOW%^, so that a firm"+
                 " yet comfortable grip can be maintained."
        );
        set_weight(5);
        set_value(1000);
        set_lore("These swords are forged by a gold dragon, who's name remains unknown."+
                 " He forges them for the purpose of providing hope to promising warriors"+
                 " of the light. He finds his own way to deliver them, without revealing himself."
        );
        set_property("enchantment",2);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
        set_hit((:TO,"hit_func":));
}
int wield_func(){
        tell_object(ETO,"%^BOLD%^%^YELLOW%^You are overwhelmed with the feeling of hope.");
    ETO->add_attack_bonus(2);
    ETO->add_sight_bonus(2);
        return 1;
}
int unwield_func(){
        tell_object(ETO,"%^BOLD%^%^YELLOW%^The feeling of hope stays with you...");
    ETO->add_attack_bonus(-2);
    ETO->add_sight_bonus(-2);
        return 1;
}

int hit_func(object targ){
        if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
        if(random(1000) < 300){
      switch(random(3)){         
         case 0:
            tell_room(environment(query_wielded()),"%^BOLD%^%^YELLOW%^"+ETOQCN+"'s sword shines like the %^BOLD%^%^WHITE%^new dawn%^BOLD%^%^YELLOW%^ as "+ETO->subjective()+" lands a blow!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^YELLOW%^Your sword shines like the %^BOLD%^%^WHITE%^new dawn%^BOLD%^%^YELLOW%^ as you land a blow!");
            tell_object(targ,"%^BOLD%^%^YELLOW%^%^"+ETOQCN+"'s sword shines like the %^BOLD%^%^WHITE%^new dawn%^BOLD%^%^YELLOW%^ as "+ETOQCN+" strikes you!");
            targ->do_damage("torso",roll_dice(3,6));
            break;
         case 1:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+"'s sword cuts "+targ->QCN+" deeply!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLUE%^You cut "+targ->QCN+" deeply!");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" cuts you deeply!");
            targ->do_damage("torso",roll_dice(3,6));
            break;
         case 2:
            set_property("magic",1);
            tell_room(environment(query_wielded()),"%^BOLD%^%^YELLOW%^The sun design on "+ETOQCN+"'s mithril blade spins then stops!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^YELLOW%^The sun design on your mithril blade spins then stops!");
            tell_object(targ,"%^BOLD%^%^YELLOW%^The sun design on "+ETOQCN+"'s mithril blade spins then stops!");
            targ->do_damage("torso",roll_dice(3,6));
            remove_property("magic");
            break;
}
}
}
