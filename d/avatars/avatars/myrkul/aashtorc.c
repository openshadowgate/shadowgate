// enchant removed so he can continue to wear on the new equip system. N, 1/13.
#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
        ::create();
        set_name("%^RESET%^%^RED%^torc%^RESET%^");
        set_id(({ "torc" }));
        set_short("%^RESET%^%^RED%^ph%^BOLD%^o%^RESET%^%^RED%^enix torc%^RESET%^");
        set_obvious_short("%^RESET%^%^RED%^f%^BOLD%^i%^RESET%^%^RED%^ery r%^BOLD%^e%^RESET%^%^RED%^d torc%^RESET%^");
        set_long("%^RESET%^%^RED%^This masterfully crafted torc is a ring of %^YELLOW%^b%^RESET%^%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^s%^YELLOW%^s%^RESET%^%^RED%^ and %^BOLD%^red g%^YELLOW%^o%^RED%^ld%^RESET%^%^RED"
        "%^, twisted together, with only a small opening in the front. Each end of the torc bears the iconic head of a ph%^BOLD%^o%^RESET%^%^RED%^enix, the eyes small glittering %^BOLD%^rubies%^RESET%^%^RED%^,"
        " the eyes seeming to watch as if guarding the wearer.%^RESET%^
"
        );
        set_value(7500);
        set_lore("%^RESET%^%^RED%^The torc was a gift from %^YELLOW%^Elderthanal%^RESET%^%^RED%^ the elder of %^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^y%^BOLD%^n%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^a%^RESE"
        "T%^%^RED%^ to the %^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^l%^BOLD%^f %^YELLOW%^L%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^d%^RESET%^%^RED%^
A%^BOLD%^a%^RESET%^%^RED%^shaenael for his service in de"
        "fense of the town against %^MAGENTA%^murderous%^RED%^ thugs from the %^BOLD%^%^BLACK%^thieves guild%^RESET%^%^RED%^ of
%^BOLD%^%^BLACK%^S%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET"
        "%^w.%^RESET%^%^RED%^ The ph%^BOLD%^o%^RESET%^%^RED%^enix is a sign of rebirth, even as Synoria will be reborn, and a watchful guardian. Perhaps such a watchful eye might even aid the wearer of this to"
        "rc.%^RESET%^
"
        );
    set_property("lore difficulty",20);
        set_heart_beat(1);
        set_size(2);
//        set_property("enchantment",1);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
//		set_item_bonus("perception",1);
}

int wear_func(){
        tell_room(environment(ETO),"%^RESET%^%^RED%^"+query_short()+"%^RESET%^%^RED%^ blazes to life, casting a red light, as it is worn by  "+ETOQCN+"%^RESET%^.",ETO);
        tell_object(ETO,"%^RESET%^%^RED%^You feel a w%^BOLD%^%^RED%^a%^RESET%^%^RED%^tchful presence of the ph%^BOLD%^o%^RESET%^%^RED%^enix torc.%^RESET%^"); 
        return 1;
}

int remove_func(){
        tell_room(environment(ETO),"%^RESET%^"+ETOQCN+"%^RESET%^ seems a bit off after removing the "+query_short()+".%^RESET%^",ETO);
        tell_object(ETO,"Your senses feel duller as you remove the "+query_short()+".");
        return 1;
}


void heart_beat()
{
         if(!objectp(TO)) { return; }
         if(!objectp(ETO)) { return; }
         if(TO->is_weapon()) 
         { 
                if(!TO->query_wielded()) { return; } 
         } 
         if(TO->is_armor())
         { 
                if(!TO->query_worn()) { return; } 
         } 
         if(!interactive(ETO)) { return; } 
         if(random(1000) > 998) 
         {
                switch(random(4)) 
                {
                        case 0:
                                tell_object(ETO, "%^RESET%^%^RED%^You feel a %^YELLOW%^heightened awareness%^RESET%^%^RED%^, your %^GREEN%^gaze %^BOLD%^sharpened%^RESET%^%^RED%^, even as a birds eye.%^RESET%^");
                                tell_room(EETO, "%^RESET%^%^RED%^You feel the %^GREEN%^piercing %^BOLD%^gaze%^RESET%^%^RED%^ of "+ETOQCN+"%^RESET%^%^RED%^ upon you, watching like a %^CYAN%^h%^BOLD%^a%^RESET%^%^CYAN%^wk%^RED%^, missing nothing.%^RESET%^", ({ETO}));
                                break;
                        case 1:
                                tell_object(ETO, "%^RESET%^%^RED%^The "+query_short()+"%^RESET%^%^RED%^ seems to g%^BOLD%^%^RED%^l%^RESET%^%^RED%^itter with its own f%^BOLD%^i%^RESET%^%^RED%^ery light.%^RESET%^");
                                tell_room(EETO, "%^RESET%^%^RED%^The "+query_short()+"%^RESET%^%^RED%^ worn by "+ETOQCN+"%^RESET%^%^RED%^ seems to g%^BOLD%^%^RED%^l%^RESET%^%^RED%^itter with its own f%^BOLD%^i%^RESET%^%^RED%^ery light.%^RESET%^", ({ETO}));
                                break;
                        case 2:
                                tell_object(ETO, "%^RESET%^%^RED%^You feel the phoenix %^BOLD%^%^RED%^e%^RESET%^%^RED%^y%^BOLD%^e%^RESET%^%^RED%^s on "+query_short()+"%^RESET%^%^RED%^ shift and %^RESET%^%^CYAN%^w%^BOLD%^a%^RESET%^%^CYAN%^tch%^RESET%^%^RED%^ for you.%^RESET%^");
                                tell_room(EETO, "%^RESET%^%^RED%^The phoenix %^BOLD%^%^RED%^e%^RESET%^%^RED%^y%^BOLD%^e%^RESET%^%^RED%^s on "+query_short()+"%^RESET%^%^RED%^ worn by "+ETOQCN+"%^RESET%^%^RED%^ shift on their own and %^RESET%^%^CYAN%^w%^BOLD%^a%^RESET%^%^CYAN%^tch%^RESET%^%^RED%^ you.%^RESET%^", ({ETO}));
                                break;
                        case 3:
                                tell_object(ETO, "%^RESET%^%^RED%^The "+query_short()+"%^BOLD%^%^RED%^ b%^YELLOW%^u%^RED%^r%^YELLOW%^n%^RED%^s%^RESET%^%^RED%^ with an %^BOLD%^%^RED%^i%^MAGENTA%^n%^RED%^ner f%^MAGENTA%^l%^RED%^ame%^RESET%^%^RED%^, yearning for %^BOLD%^r%^YELLOW%^e%^RED%^b%^YELLOW%^i%^RED%^r%^YELLOW%^t%^RED%^h.%^RESET%^");
                                tell_room(EETO, "%^RESET%^%^RED%^The "+query_short()+"%^RESET%^%^RED%^ worn by "+ETOQCN+" %^BOLD%^%^RED%^ b%^YELLOW%^u%^RED%^r%^YELLOW%^n%^RED%^s%^RESET%^%^RED%^ brightly with an %^BOLD%^%^RED%^i%^MAGENTA%^n%^RED%^ner f%^MAGENTA%^l%^RED%^ame%^RESET%^%^RED%^, and you feel its yearning for %^BOLD%^r%^YELLOW%^e%^RED%^b%^YELLOW%^i%^RED%^r%^YELLOW%^t%^RED%^h%^RESET%^%^RED%^, in defiance of %^BOLD%^%^BLACK%^ashes%^RESET%^%^RED%^ and the %^BOLD%^%^BLACK%^void.%^RESET%^", ({ETO}));
                                break;
                }
        }
}
