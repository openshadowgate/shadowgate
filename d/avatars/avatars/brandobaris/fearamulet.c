#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

int WillDelay, PowerDelay, SteelDelay;

void create(){
	::create();
	set_name("Amulet of Fear");
	set_id(({ "amulet", "amulet of fear" }));
	set_short("%^BOLD%^%^BLACK%^A%^RESET%^m%^BOLD%^%^BLACK%^u%^GREEN%^l%^RESET%^e%^BOLD%^%^BLACK%^t of F%^RESET%^%^GREEN%^e%^BOLD%^a%^BLACK%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a %^RESET%^s%^BOLD%^trikin%^RESET%^g %^BOLD%^%^BLACK%^amulet of b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^%^BLACK%^l and %^GREEN%^e%^RESET%^%^GREEN%^m%^BOLD%^%^BLACK%^e%^GREEN%^r%^RESET%^%^GREEN%^a%^WHITE%^l%^BOLD%^%^GREEN%^d%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Upon an e%^RESET%^l%^GREEN%^a%^WHITE%^b%^BOLD%^%^BLACK%^o%^RESET%^r%^GREEN%^a%^WHITE%^t%^BOLD%^%^BLACK%^e, t%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^i%^WHITE%^n%^BLACK%^g %^WHITE%^chain"
	" %^BLACK%^hangs a %^RESET%^striking %^BOLD%^%^BLACK%^amulet wrought of %^RESET%^%^GREEN%^e%^BOLD%^m%^RESET%^%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^d %^BOLD%^%^BLACK%^and b%^R"
	"ESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^d %^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^e%^BOLD%^l%^BLACK%^, cast into a meticulously detail"
	"ed visage of a ferocious b%^GREEN%^l%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k d%^RESET%^r%^BOLD%^%^BLACK%^a%^GREEN%^g%^RESET%^o%^BOLD%^%^BLACK%^n. The wyrm's eyes glow a %^RESET%^%^RED%^m%^BOLD%^%^BLACK%"
	"^e%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^i%^RESET%^n%^RED%^g %^BOLD%^%^GREEN%^green%^BLACK%^, and its powerful jaws are open in a posessive snarl, baring long and sharp %"
	"^WHITE%^teeth %^BLACK%^that look unsettlingly realistic. The draconic figure coils around a large, ovular %^GREEN%^e%^RESET%^m%^BOLD%^e%^GREEN%^r%^RESET%^a%^BOLD%^%^GREEN%^ld %^BLACK%^that gives off a"
	" faint %^GREEN%^g%^RESET%^l%^BOLD%^%^GREEN%^ow%^BLACK%^, and almost seems to hold some hidden power. A d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^rk %^RESET%^%^RED%^a%^WHITE%^u%^BOLD%^r%^RESET%^%^RED%^a %^BOL"
	"D%^%^BLACK%^of %^RED%^power %^BLACK%^and %^RESET%^%^RED%^domination %^BOLD%^%^BLACK%^seems to emanate from the amulet, seeping into the air around it.%^RESET%^
"	);
	set_value(175000);
	set_lore("%^BOLD%^%^BLACK%^The %^RESET%^%^GREEN%^Amulet of Fear %^BOLD%^%^BLACK%^is an artifact of Bane given only to the most powerful and influential of the Black Hand, or to those who have pleased Bane in so"
	"me way. Empowered by a dark ritual known only to a select few of Bane's clergy, this amulet is capable of channeling an amount of divine power, and enchanted to bring out the wearer's natural presence"
	" and persuasiveness. Those capable of calling upon this amulet's true power may %^GREEN%^<%^RESET%^invoke%^BOLD%^%^GREEN%^> %^BLACK%^Bane's blessings of %^RED%^power%^BLACK%^, %^WHITE%^steel%^BLACK%^,"
	" and %^GREEN%^will%^BLACK%^.%^RESET%^

"	);
	set_property("lore difficulty",35);
	set_item_bonus("charisma",2);
	set_item_bonus("influence",4);
	set_size(2);
	set_property("enchantment",5);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_heart_beat(1);
    WillDelay = 0;
    PowerDelay = 0;
    SteelDelay = 0;
}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("invoke_em","invoke");
    }
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!PowerDelay && !WillDelay && !SteelDelay) return;
    
    if(PowerDelay) 
    {
        PowerDelay--;
        if(PowerDelay < 0) PowerDelay = 0;
    }
    if(WillDelay) 
    {
        WillDelay--;
        if(WillDelay < 0) WillDelay = 0;
    }
    if(SteelDelay) 
    {
        SteelDelay--;
        if(SteelDelay < 0) SteelDelay = 0;
    }
    return;
}


int invoke_em(string str)
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
   	
  	if(!str) 
    {
        tell_object(ETO,"Invoke what?\n");
        return 1;
    }	

    str = lower_case(str);
    if(str != "will" && str != "steel" && str != "power")
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^Bane will not grant you that blessing.%^RESET%^\n");
        return 1;
    }
    
    if(!(query_worn()))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^Bane will not grant you that blessing if you are "+
        "not wearing the amulet.%^RESET%^");
        return 1;
    }
    
    if((str == "will" && WillDelay) || (str == "steel" && SteelDelay) || (str == "power" && PowerDelay))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You must wait before calling upon this blessing again.%^RESET%^");
        return 1;
    }
    
    tell_object(ETO, "%^RESET%^%^GREEN%^The e%^BOLD%^%^WHITE%^m%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^"+
    "r%^BOLD%^%^GREEN%^a%^RESET%^%^WHITE%^l%^RESET%^%^GREEN%^d hanging from your neck g%^BOLD%^%^GREEN%^l"+
    "%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^w%^RESET%^%^GREEN%^s brightly, and a "+
    "%^BOLD%^%^BLACK%^d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk a%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^"+
    "ra %^RESET%^%^GREEN%^of %^BOLD%^%^RED%^power%^RESET%^%^GREEN%^ surrounds you...%^RESET%^");
    
    tell_room(EETO, "%^RESET%^%^GREEN%^The e%^BOLD%^%^WHITE%^m%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^"+
    "r%^BOLD%^%^GREEN%^a%^RESET%^%^WHITE%^l%^RESET%^%^GREEN%^d hanging from "+ETOQCN+"%^RESET%^%^GREEN%^'s"+
    " neck g%^BOLD%^%^GREEN%^l"+
    "%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^w%^RESET%^%^GREEN%^s brightly, and a "+
    "%^BOLD%^%^BLACK%^d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk a%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^"+
    "ra %^RESET%^%^GREEN%^of %^BOLD%^%^RED%^power%^RESET%^%^GREEN%^ surrounds "+ETO->QO+"...%^RESET%^", ETO);
    
    if(str == "will")
    {
        WillDelay = 1350;
        new("/cmds/spells/o/_oppression.c")->use_spell(ETO, ETO->query_name(), 35, 1000, "cleric"); 
        return 1;
    }
    if(str == "power")
    {
        PowerDelay = 1350;
        new("/cmds/spells/b/_blight.c")->use_spell(ETO, ETO->query_name() , 35, 1000, "cleric"); 
        return 1;        
    }
    if(str == "steel")
    {
        SteelDelay = 1350;
        new("/cmds/spells/s/_seeking_sword.c")->use_spell(ETO, ETO->query_name() , 35, 1000, "cleric"); 
        return 1;        
    }    
    return 1;
}


int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The figure of the black dragon settles loosely around "+ETOQCN+"'s neck, and the %^RESET%^%^GREEN%^e%^BOLD%^m%^BLACK%^e%^GREEN%^r%^BLACK%^a%^RESET%^%^GREEN%^ld %^BOLD%^%^BLACK%^within its clutches %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^GREEN%^m%^RESET%^e%^BOLD%^r%^RESET%^s %^BOLD%^%^BLACK%^with a %^RESET%^%^RED%^malign %^GREEN%^g%^WHITE%^l%^BOLD%^%^GREEN%^e%^WHITE%^a%^RESET%^%^GREEN%^m%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The figure of the black dragon settles loosely around your neck, and the %^RESET%^%^GREEN%^e%^BOLD%^m%^BLACK%^e%^GREEN%^r%^BLACK%^a%^RESET%^%^GREEN%^ld %^BOLD%^%^BLACK%^within its clutches %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^GREEN%^m%^RESET%^e%^BOLD%^r%^RESET%^s %^BOLD%^%^BLACK%^with a %^RESET%^%^RED%^malign %^GREEN%^g%^WHITE%^l%^BOLD%^%^GREEN%^e%^WHITE%^a%^RESET%^%^GREEN%^m%^BOLD%^%^BLACK%^.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The black dragon's eyes %^RESET%^%^GREEN%^f%^BOLD%^l%^WHITE%^a%^GREEN%^s%^RESET%^%^GREEN%^h %^BOLD%^%^BLACK%^once before growing d%^RESET%^a%^BOLD%^%^BLACK%^rk and d%^RESET%^u%^BOLD%^%^BLACK%^ll as "+ETOQCN+" removes the amulet.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The black dragon's eyes %^RESET%^%^GREEN%^f%^BOLD%^l%^WHITE%^a%^GREEN%^s%^RESET%^%^GREEN%^h %^BOLD%^%^BLACK%^once before growing d%^RESET%^a%^BOLD%^%^BLACK%^rk and d%^RESET%^u%^BOLD%^%^BLACK%^ll. You feel a marked sense of %^RESET%^%^RED%^power %^BOLD%^%^BLACK%^leave you.%^RESET%^");
	return 1;
}

