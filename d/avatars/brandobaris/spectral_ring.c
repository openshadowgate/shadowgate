#include <std.h>
inherit "/d/common/obj/jewelry/ring";
int Delay, FeatFlag;

void create(){
	::create();
	set_name("spectral ring");
	set_id(({ "ring", "hazy ring", "gray ring", "spectral ring" }));
	set_short("%^BOLD%^%^BLACK%^Ring of S%^RESET%^p%^BOLD%^%^BLACK%^e%^RESET%^c%^BOLD%^t%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^l T%^RESET%^r%^BOLD%^a%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a h%^RESET%^a%^BOLD%^z%^BLACK%^y g%^RESET%^r%^BOLD%^a%^BLACK%^y r%^RESET%^i%^BOLD%^%^BLACK%^ng%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This %^RESET%^dark gray %^BOLD%^%^BLACK%^ring is solid and %^RESET%^%^CYAN%^deathly cold %^BOLD%^%^BLACK%^to the touch, but possesses a %^RESET%^translucent %^BOLD%^%^BLACK%^and %^RES"
	"ET%^i%^BOLD%^n%^RESET%^t%^BOLD%^a%^RESET%^ng%^BOLD%^i%^RESET%^b%^BOLD%^l%^RESET%^e %^BOLD%^%^BLACK%^appearance, looking like little more than a band of h%^RESET%^a%^CYAN%^z%^BOLD%^%^BLACK%^y s%^RESET%"
	"^m%^CYAN%^o%^WHITE%^k%^BOLD%^%^BLACK%^e. It casts no shadow, and it seems to emanate an aura of %^RESET%^solemnity%^BOLD%^%^BLACK%^.%^RESET%^
"	);
	set_value(10000);
	set_lore("%^BOLD%^Rangers in service to the %^RESET%^Lord of the Dead %^BOLD%^often make use of this ring in the course of their duties, where stealth and speed are often of paramount importance. This ordinary "
	"iron ring bears a blessing of Kelemvor that attunes its wearer with the %^BLACK%^Fugue Plane%^WHITE%^, bolstering them with the various attributes of its essence - no trace of their passing will be le"
	"ft where they go, and they may %^BLACK%^<%^RESET%^beckon%^BOLD%^%^BLACK%^> %^WHITE%^to an unseen ally beyond the veil in order to move swiftly over long and open distances.%^RESET%^
"	);
	set_property("lore difficulty",30);
	set_item_bonus("stealth",2);
	set_item_bonus("damage resistance",2);
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_heart_beat(1);
    Delay = 0;
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A faint %^RESET%^%^CYAN%^chill %^BOLD%^%^BLACK%^settles in the air around "+ETOQCN+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a %^RESET%^%^CYAN%^cold %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^solemn %^BOLD%^%^BLACK%^aura overcome you as you slip on the ring, your body feeling lighter.%^RESET%^");
    if(member_array("tracklessstep",(string*)ETO->query_temporary_feats()) == -1) 
    {
        ETO->add_temporary_feat("tracklessstep");
        FeatFlag = 1;
    }
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the h%^RESET%^a%^BOLD%^z%^BLACK%^y ring, and the air around them grows %^RESET%^%^GREEN%^warmer%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel your %^RESET%^s%^BOLD%^p%^RESET%^e%^BOLD%^c%^BLACK%^t%^RESET%^r%^BOLD%^a%^RESET%^l %^BOLD%^%^BLACK%^protection fade, as you remove the ring.%^RESET%^");
    
    if(FeatFlag) 
    {
        ETO->remove_temporary_feat("tracklessstep");
        FeatFlag = 0;
    }
    
	return 1;
}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("beckon_em", "beckon");
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
int beckon_em(string str)
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
    if(str) return 0;
    
    if(!(query_worn()))
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You cannot sense beyond the veil without "+
        "wearing the ring.%^RESET%^ ");
        return 1;
    }
    
    if(Delay) 
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^Your spectral ally requires some rest before you "+
        "may call upon it once more.%^RESET%^ ");
        
        if(avatarp(ETO))
        {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You are an immortal: The delay is still "+Delay+" heartbeats. "+
            "A heartbeat is supposed to occur every 2 seconds, approximately. Please note "+
            "that Saide coded this slightly differently in that the user must be logged in for the "+
            "delay to tick down.%^RESET%^");
        }
        return 1;
    }    
    
    tell_object(ETO, "%^BOLD%^%^BLACK%^You lift your hand, and the gray ring "+
    "grows fainter as you %^RESET%^beckon %^BOLD%^%^BLACK%^to a presence "+
    "beyond the %^RESET%^veil%^BOLD%^%^BLACK%^.%^RESET%^");
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ lifts "+ETO->QP+" hand, %^RESET%^beckoning "+
    "%^BOLD%^%^BLACK%^to something only "+ETO->QS+" seems to see.%^RESET%^", ETO);
    
    Delay = 300;
    new("/cmds/spells/p/_phantom_steed.c")->use_spell(ETO, 0, 30, 1000, "cleric");   
        
    return 1;
}
