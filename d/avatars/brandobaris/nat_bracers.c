#include <std.h>
inherit "/d/common/obj/armour/bracers";
int Delay;

void create(){
	::create();
	set_name("Nature's Blessing");
	set_id(({ "bracers", "leather bracers", "bedraggled bracers", "blessing", "nature's blessing" }));
	set_short("%^RESET%^%^ORANGE%^N%^GREEN%^a%^BOLD%^t%^RESET%^%^ORANGE%^u%^GREEN%^r%^ORANGE%^e's B%^GREEN%^l%^ORANGE%^e%^GREEN%^s%^ORANGE%^s%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^n%^ORANGE%^g%^WHITE%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a p%^GREEN%^a%^ORANGE%^ir of b%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d%^GREEN%^r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^g%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d l%^WHITE%^e%^GREEN%^a%^ORANGE%^th%^WHITE%^e%^ORANGE%^r b%^WHITE%^r%^BOLD%^%^BLACK%^a%^RESET%^c%^GREEN%^e%^WHITE%^r%^ORANGE%^s%^WHITE%^");
	set_long("%^ORANGE%^This plain pair of leather bracers isn't much to look it, %^BOLD%^%^BLACK%^t%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^rn %^RESET%^%^ORANGE%^in several places and caked in %^BOLD%^%^BLACK%^m%^RESET%^"
	"%^GREEN%^u%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^. Despite this, the bracers appear tough and durable, and perfectly serviceable despite the many tears. They look as if they might be rather %^CYAN%^comf"
	"ortable %^ORANGE%^to wear, too, lined with s%^CYAN%^o%^ORANGE%^ft, p%^CYAN%^a%^WHITE%^d%^ORANGE%^d%^CYAN%^e%^ORANGE%^d h%^WHITE%^i%^CYAN%^d%^ORANGE%^e on the inside of each. A dirty w%^GREEN%^o%^ORANG"
	"E%^o%^BOLD%^%^GREEN%^d%^RESET%^%^GREEN%^e%^ORANGE%^n b%^GREEN%^a%^ORANGE%^nd wraps around the upper portion of the bracer, e%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^a"
	"%^WHITE%^v%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d with a %^WHITE%^f%^BOLD%^%^GREEN%^a%^RESET%^ded s%^BOLD%^%^RED%^y%^RESET%^mb%^BOLD%^%^CYAN%^o%^RESET%^ls %^ORANGE%^that represent the five natural elem"
	"ents: %^BOLD%^%^RED%^fire%^RESET%^%^ORANGE%^, %^BOLD%^%^BLUE%^water%^RESET%^%^ORANGE%^, %^BOLD%^earth%^RESET%^%^ORANGE%^, %^BOLD%^%^CYAN%^air%^RESET%^%^ORANGE%^, and %^BOLD%^%^GREEN%^life%^RESET%^%^OR"
	"ANGE%^.%^WHITE%^
"	);
	set_value(75000);
	set_lore("%^ORANGE%^These bracers, or at least bracers like these, are said to have once belonged to the elven %^BOLD%^%^GREEN%^Grand Druid Arishalla Coppergloam%^RESET%^%^ORANGE%^, some time during the second "
	"century SG, and her tale is as much a cautionary one as it is a testament to the power of druidic magic. Widely known by her followers to have been a druid of exceptional skill, she displayed a unique"
	" talent for weaving the natural magics into objects of wood and leather, enchanting them much as a mage might. These artifacts aided her flock greatly in their efforts to guard the wilds from the encr"
	"oaching civilization, and Arishalla eventually crafted her masterpiece: a pair of leather bracers that called upon the energies of the four elemental planes, and upon the life energies of the feywild."
	" Wearing these bracers upon her arms, she was able to exist partly upon each of these planes at once, lending her a considerable resistance to damage upon the Prime. The bracers also allowed her the a"
	"bility to %^BOLD%^%^GREEN%^<%^RESET%^%^GREEN%^beseech%^BOLD%^> %^RESET%^%^ORANGE%^the elements for aid, and they would stand at her defense in times of need.%^WHITE%^

%^ORANGE%^Sadly, it is believed "
	"that Arishalla's own talent was her own downfall. Delving ever deeper into the mysteries of the natural world, she gradually drew herself further into the inner planes in search of truth, and bit by b"
	"it, her presence upon the Prime waned. One day, she simply vanished entirely, never to be seen again. Whatever Arishalla's ultimate fate, her story stands as a warning to young druids to accept and ch"
	"erish the mysteries of nature as they are - vast and unknowable.%^WHITE%^
"	);
	set_property("lore difficulty",35);
	set_item_bonus("damage resistance",5);
	set_item_bonus("spell damage resistance",10);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    metal = 0;
    set_heart_beat(1);
}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("beseech_em", "beseech");
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
int beseech_em(string str)
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
        tell_object(ETO,"%^RESET%^%^ORANGE%^The elements will not heed your call unless "+
        "you are wearing the bracers.%^RESET%^");
        return 1;
    }
    
    if(Delay) 
    {
        tell_object(ETO,"%^RESET%^%^ORANGE%^The elements will not heed your call again so soon.%^RESET%^");
        if(avatarp(ETO))
        {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You are an immortal: The delay is still "+Delay+" heartbeats. "+
            "A heartbeat is supposed to occur every 2 seconds, approximately. Please note "+
            "that Saide coded this slightly differently in that the user must be logged in for the "+
            "delay to tick down.%^RESET%^");
        }
        return 1;
    }    
    
    tell_object(ETO, "%^RESET%^%^ORANGE%^Placing one hand to the rough surface of your bracer, "+
    "you call out to the %^BOLD%^%^RED%^el%^YELLOW%^em%^GREEN%^e%^CYAN%^n%^BLUE%^ts%^RESET%^"+
    "%^ORANGE%^ for aid!%^RESET%^");
    
    tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ places a hand to the surface of "+ETO->QP+" bracer, "+
    "and calls out to the %^BOLD%^%^RED%^el%^YELLOW%^em%^GREEN%^e%^CYAN%^n%^BLUE%^ts%^RESET%^"+
    "%^ORANGE%^ for aid!%^RESET%^", ETO);
    
    Delay = 750;
    new("/cmds/spells/s/_summon_natures_ally_9.c")->use_spell(ETO, 0, 30, 1000, "druid");   
        
    return 1;
}


int wear_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" fastens the unassuming leather bracers.",ETO);
	tell_object(ETO,"%^ORANGE%^The bracers grow %^RED%^warm %^ORANGE%^as you fasten them to your arms, and your feel the protective influence of the %^BOLD%^%^RED%^el%^ORANGE%^em%^GREEN%^e%^CYAN%^n%^BLUE%^ts %^RESET%^%^ORANGE%^draw nearer to you.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" unfastens the unassuming leather bracers.",ETO);
	tell_object(ETO,"%^ORANGE%^You feel the %^GREEN%^protective %^ORANGE%^influence of the %^BOLD%^%^RED%^el%^ORANGE%^em%^GREEN%^e%^CYAN%^n%^BLUE%^ts %^RESET%^%^ORANGE%^wane as you unfasten the bracers.");
	return 1;
}

