#include <std.h>
inherit "/d/common/obj/jewelry/ring";
int Delay;

void create(){
	::create();
	set_name("Seeker's Ring");
	set_id(({ "ring", "silver ring", "moonstone ring", "thin ring" }));
	set_short("%^RESET%^%^BOLD%^S%^RESET%^%^CYAN%^e%^BOLD%^e%^WHITE%^k%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^r's R%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^a thin ring of m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^nst%^RESET%^%^CYAN%^o%^WHITE%^n%^BOLD%^e and s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^%^CYAN%^e%^WHITE%^r%^RESET%^");
	set_long("%^BOLD%^This wide, d%^RESET%^i%^BOLD%^%^CYAN%^a%^RESET%^m%^BOLD%^%^CYAN%^o%^RESET%^n%^BOLD%^d-c%^RESET%^u%^BOLD%^t m%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^o%^CYAN%^n%^WHITE%^s%^RESET%^%^CYAN%^t%^BOLD%^%^W"
	"HITE%^o%^CYAN%^n%^WHITE%^e readily catches the eye, its c%^RESET%^l%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^u%^WHITE%^d%^BOLD%^y patches of %^RESET%^%^CYAN%^l%^WHITE%^i%^BOLD%^g%^RESET%^%^CYAN%^ht b%^WHITE%^"
	"l%^BOLD%^u%^RESET%^%^CYAN%^e %^BOLD%^%^WHITE%^intermingling with the milky op%^CYAN%^a%^WHITE%^les%^RESET%^%^CYAN%^c%^BOLD%^%^WHITE%^en%^CYAN%^c%^WHITE%^e of the gem to invoke the impression of a %^CY"
	"AN%^m%^WHITE%^i%^RESET%^s%^BOLD%^t%^CYAN%^y s%^WHITE%^k%^CYAN%^y%^WHITE%^, and it has been cut in such a way that the eye is drawn naturally to its center. The s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^r"
	" r%^RESET%^i%^BOLD%^ng it is set into is simplistic in its design, but cast to naturally compliment the gem, holding it in place with a simple set of prongs and t%^RESET%^wi%^BOLD%^s%^RESET%^tin%^BOLD"
	"%^g subtly as it wraps around the finger.%^RESET%^
"	);
	set_value(10000);
	set_lore("%^BOLD%^Often found in the possession of knights of Selune, the %^CYAN%^Seeker's Ring %^WHITE%^is a mixed blessing to the one who carries it, granting its wearer both the gift and curse that is divina"
	"tion. This ability manifests itself in several obvious ways, allowing the wearer to better predict and react to attacks in combat, and to %^RESET%^%^CYAN%^<%^BOLD%^glimpse%^RESET%^%^CYAN%^> %^BOLD%^%^"
	"WHITE%^the location of any ally or enemy they would seek out. However, this foresight comes at a price, as the wearer will also be able to foretell their own demise, though never clearly enough to all"
	"ow for a true acceptance of it. Weighing always on one's mind, it takes a strong will indeed to make use of this ring without slipping into some degree of insanity.%^RESET%^
"	);
	set_property("lore difficulty",30);
	set_item_bonus("armor bonus",2);
	set_item_bonus("will",-1);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_heart_beat(1);
    Delay = 0;
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips on the m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t%^RESET%^o%^CYAN%^n%^BOLD%^%^WHITE%^e ring, taking on a distant look.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You feel the full weight of the future settle over you, as the diamond-shaped m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t%^RESET%^o%^CYAN%^n%^BOLD%^%^WHITE%^e s%^CYAN%^p%^WHITE%^ar%^CYAN%^k%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips off the m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t%^RESET%^o%^CYAN%^n%^BOLD%^%^WHITE%^e ring, letting out a %^RESET%^sigh%^BOLD%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^Your awareness of the future %^RESET%^%^CYAN%^wanes %^BOLD%^%^WHITE%^as the ring comes off, yet you feel a great %^BLACK%^weight %^WHITE%^lifting from your shoulders.%^RESET%^");
	return 1;
}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("glimpse_em", "glimpse");
    }
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!Delay) return;
    Delay--;
    if(Delay < 0) Delay = 0;
    return;
}
int glimpse_em(string str)
{
	object targ;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
 	if (ETO->query_bound() || EETO->query_unconscious() 
    || EETO->query_paralyzed()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
   	if(!stringp(str) && !(query_worn())) return 0;
    
    if(!stringp(str))
    {
        tell_object(ETO, "%^BOLD%^Glimpse who?%^RESET%^");
        return 1;
    }
    
    if(!(query_worn()))
    {
        tell_object(ETO,"%^BOLD%^You gaze into the m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^"+
        "n%^RESET%^s%^BOLD%^t%^RESET%^o%^CYAN%^n%^BOLD%^%^WHITE%^e for a time, to no "+
        "effect. Perhaps you need to be wearing it.%^RESET%^");
        return 1;
    }
    
    if(Delay) 
    {
        tell_object(ETO,"%^BOLD%^You consider gazing into the m%^RESET%^"+
        "%^CYAN%^o%^WHITE%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t"+
        "%^RESET%^o%^CYAN%^n%^BOLD%^%^WHITE%^e once more. Somehow, you know "+
        "that you must wait a short while longer.%^RESET%^");
        
        if(avatarp(ETO))
        {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You are an immortal: The delay is still "+Delay+" heartbeats. "+
            "A heartbeat is supposed to occur every 2 seconds, approximately. Please note "+
            "that Saide coded this slightly differently in that the user must be logged in for the "+
            "delay to tick down.%^RESET%^");
        }
        return 1;
    }    
    
    tell_object(ETO, "%^BOLD%^Your gaze drawn into the cloudy surface of the "+
    "m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t%^RESET%^"+
    "o%^CYAN%^n%^BOLD%^%^WHITE%^e, you focus on bringing a particular face to the "+
    "forefront of your thoughts...%^RESET%^");
    
    tell_room(EETO, ETOQCN+"%^BOLD%^ idly gazes into "+ETO->QP+
    " m%^RESET%^%^CYAN%^o%^WHITE%^o%^BOLD%^n%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^t"+
    "%^RESET%^o%^CYAN%^n%^BOLD%^%^WHITE%^e.%^RESET%^", ETO);
    
    Delay = 150;
    new("/cmds/spells/c/_clairvoyance.c")->use_spell(ETO, str, 30, 1000, "mage");   
        
    return 1;
}
