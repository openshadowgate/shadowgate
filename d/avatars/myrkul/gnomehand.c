#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("gnomehand");
	set_id(({ "gnomish steampowered mechanical hand", "gnomish hand", "steampowered hand", "mechanical hand", "hand" }));
	set_short("%^RESET%^%^MAGENTA%^G%^BOLD%^n%^RED%^o%^MAGENTA%^m%^RESET%^%^MAGENTA%^i%^BOLD%^s%^RED%^h%^CYAN%^ S%^WHITE%^t%^CYAN%^eam%^WHITE%^p%^CYAN%^owered %^BLACK%^M%^RESET%^e%^BOLD%^%^BLACK%^chanical H%^RESET%^a%^BOLD%^%^BLACK%^nd%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^G%^BOLD%^n%^RED%^o%^MAGENTA%^m%^RESET%^%^MAGENTA%^i%^BOLD%^s%^RED%^h%^CYAN%^ S%^WHITE%^t%^CYAN%^eam%^WHITE%^p%^CYAN%^owered %^BLACK%^M%^RESET%^e%^BOLD%^%^BLACK%^chanical H%^RESET%^a%^BOLD%^%^BLACK%^nd%^RESET%^");
	set_long("%^BOLD%^%^CYAN%^This %^BLACK%^m%^RESET%^e%^BOLD%^%^BLACK%^chanical h%^RESET%^a%^BOLD%^%^BLACK%^nd%^CYAN%^ is a %^GREEN%^prosthetic%^CYAN%^ that fits on the forearm of an %^YELLOW%^amputee%^CYAN%^. It "
	"is a mechanical marvel of engineering, made entirely out of bright %^BLUE%^b%^RESET%^%^CYAN%^l%^BLUE%^u%^BOLD%^e %^RESET%^%^CYAN%^s%^BLUE%^t%^BOLD%^e%^RESET%^%^CYAN%^e%^BLUE%^l%^BOLD%^%^CYAN%^. Tiny m"
	"aintenance panels open to reveal intricate %^YELLOW%^g%^RESET%^%^ORANGE%^e%^YELLOW%^a%^RESET%^%^ORANGE%^r%^YELLOW%^s%^CYAN%^. Exhaust vents send out of puffs of %^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^a"
	"%^BOLD%^m%^CYAN%^, doubtless to cool the magical %^MAGENTA%^F%^RESET%^%^MAGENTA%^a%^CYAN%^e%^BLUE%^z%^CYAN%^r%^MAGENTA%^e%^BOLD%^s%^RESET%^%^MAGENTA%^s%^BOLD%^%^WHITE%^ crystal %^CYAN%^powerplant. The"
	" knuckles are fully articulated and quite dextrous. This is undoubtedly a work of art by a %^RESET%^%^MAGENTA%^G%^BOLD%^n%^RED%^o%^MAGENTA%^m%^RESET%^%^MAGENTA%^i%^BOLD%^s%^RED%^h%^CYAN%^ inventor of "
	"great genius.%^RESET%^  
"	);
	set_value(10000);
	set_lore("%^BOLD%^%^CYAN%^This is a %^BLUE%^steel hand%^CYAN%^ of the great gnomish %^BLUE%^skyship%^CYAN%^ captain Aleosnardishbur. He lost his arm in one of many battles with %^RED%^Orc %^RESET%^%^ORANGE%^Wyv"
	"ern-riders%^BOLD%^%^CYAN%^, and invented this hand as a replacement. It is said to be many times stronger than a normal hand, and allowed him to handle hold even the most dangerous of substances safel"
	"y.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("strength",2);
        set_item_bonus("damage resistance",1);
	set_item_bonus("perception",-1);
	set_heart_beat(1);
	set_size(1);
	set_property("enchantment",-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" is overjoyed after putting on the "+query_short()+". "+ETOQCN+" reaches out and %^RED%^crushes%^YELLOW%^ a mug just because, and says, %^WHITE%^-Groovy!-%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You feel like your hand is back as you wear the "+query_short()+". It feels so strong!! You reach out and %^RED%^crush%^YELLOW%^ a mug saying to yourself, %^WHITE%^-Groovy!-%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" is in agony after removing the "+query_short()+" and is left with nothing but a stump!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel agony as you remove the "+query_short()+" and are left with nothing but your stump!%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 500){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^"+ETOQCN+" easily %^CYAN%^deflects%^BLACK%^ the blow from "+who->QCN+" with a "+query_short()+".%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^You easily %^CYAN%^deflect%^BLACK%^ the blow from "+who->QCN+" with your %^BOLD%^%^BLUE%^steel hand.%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+" easily %^CYAN%^deflects%^BLACK%^ your blow with "+query_short()+".%^RESET%^");
return (damage*0)/100;	}

}


// since this can't be worn with a ring of protection anymore, giving it
// rop bonuses plus a couple other bonuses/penalties
void update_bonuses()
{
    int level;
    if(!objectp(ETO) || !living(ETO) || ETO->query_true_name() != "jimijuker") { return; }
    
    level = ETO->query_character_level();
    
    set_item_bonus("strength",level / 10);
    set_item_bonus("damage resistance",level / 10);
    set_item_bonus("perception",-1 * level / 10);
    remove_property("enchantment");
    set_property("enchantment",level / 7);
    return;
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
    update_bonuses();
    if(random(1000) > 998) 
    {
        switch(random(3)) 
        {
            case 0:
                tell_object(ETO, "%^YELLOW%^You flex your "+query_short()+" fingers and admire its strength.");
                tell_room(EETO, "%^YELLOW%^"+ETOQCN+" flexes "+ETO->QP+" "+query_short()+" fingers and admire their strength.", ({ETO}));
                break;
            case 1:
                tell_object(ETO, "%^YELLOW%^"+query_short()+" worn by "+ETOQCN+" vents exhaust %^CYAN%^s%^WHITE%^t%^CYAN%^eam%^YELLOW%^, %^BLACK%^w%^WHITE%^h%^BLACK%^istl%^WHITE%^i%^BLACK%^ng loudly!%^RESET%^");
                tell_room(EETO, "%^YELLOW%^"+query_short()+" worn by "+ETOQCN+" vents exhaust %^CYAN%^s%^WHITE%^t%^CYAN%^eam%^YELLOW%^, %^BLACK%^w%^WHITE%^h%^BLACK%^istl%^WHITE%^i%^BLACK%^ng loudly!%^RESET%^", ({ETO}));
                break;
            case 2:
                tell_object(ETO, "%^YELLOW%^Your missing hand %^GREEN%^itches%^YELLOW%^, and no matter how much you try, %^RED%^s%^RESET%^%^RED%^c%^BOLD%^%^RED%^r%^RESET%^%^RED%^a%^BOLD%^t%^RESET%^%^RED%^c%^BOLD%^h%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^YELLOW%^ the "+query_short()+" does not seem to help.%^RESET%^");
                tell_room(EETO, "%^YELLOW%^"+ETOQCN+" tries %^RED%^s%^RESET%^%^RED%^c%^BOLD%^%^RED%^r%^RESET%^%^RED%^a%^BOLD%^t%^RESET%^%^RED%^c%^BOLD%^h%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^YELLOW%^ the "+query_short()+", but this does not seem to help the %^CYAN%^phantom itching%^YELLOW%^ from "+ETO->QP+" amputated hand.%^RESET%^", ({ETO}));
                break;
        }
    }
}
