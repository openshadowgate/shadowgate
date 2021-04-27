#include <std.h>
inherit OBJECT;
int Delay;

void create(){
	::create();
	set_name("Black Opal of the Wretched Soul");
	set_id(({ "opal", "black opal", "glittering black opal" }));
	set_short("%^BOLD%^%^BLACK%^B%^GREEN%^l%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^ck O%^RESET%^%^GREEN%^p%^BOLD%^a%^BLACK%^l of the W%^RESET%^%^GREEN%^r%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^c%^GREEN%^h%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d S%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^h%^RESET%^%^GREEN%^o%^BOLD%^l%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a large g%^RESET%^l%^BOLD%^%^GREEN%^i%^BLACK%^t%^GREEN%^t%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^GREEN%^n%^BLACK%^g b%^GREEN%^l%^RESET%^%^GREEN%^a%^WHITE%^c%^BOLD%^%^BLACK%^k o%^RESET%^%^GREEN%^p%^BOLD%^a%^BLACK%^l%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This smooth b%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^k o%^RESET%^%^GREEN%^p%^BOLD%^%^BLACK%^al is about the size of a human fist, and is cool to the t"
	"ouch. Its d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^rk, %^RESET%^%^GREEN%^g%^WHITE%^l%^BOLD%^o%^GREEN%^s%^RESET%^s%^GREEN%^y %^BOLD%^%^BLACK%^depths are flecked with %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^"
	"%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^d %^BOLD%^%^BLACK%^flashes of %^GREEN%^green %^BLACK%^and %^RED%^red %^BLACK%^that seem to %^RESET%^%^RED%^b%^ORANGE%^u%^RED%^rn %^BOLD%^%^BLACK%^within the co"
	"nfines of the gem. Though it is difficult to put your finger on it, a cold and forlorn %^RESET%^presence %^BOLD%^%^BLACK%^seems to hang in the air around this gemstone.%^RESET%^
"	);
	set_value(0);
	set_weight(5);
	set_lore("%^BOLD%^%^GREEN%^Faskal Harricksson %^BLACK%^was once amongst the brightest of Oghma's faithful, a young man blessed with the ability to recall just about any fact he had ever heard before, and to puz"
	"zle out mysteries that had eluded some of the brightest minds of his time in the span of minutes. Unfortunately, Fate had plans for Faskal beyond the prosperous future his friends and family were expe"
	"cting. After falling deeply into debt, he was forced into indentured servitude to pay back his creditors, and soon found himself the personal scribe and tactician of the High Priest of Bane. Here, his"
	" keen mind was put all to well to use, and Faskal's deductions were key to a five-year-long string of victories for Bane's forces that conquered and enslaved thousands. Just before his debt was fully "
	"paid and Faskal went free, the High Priest offered him up as the subject of a magi's 'experiment', ripping the young man's soul from his body and condemning it to eternal agony within one of the Nine "
	"Hells. The church of Bane still calls upon Faskal's insights to this day, using specially enchanted black opals like this one to %^GREEN%^<%^RESET%^wrest%^BOLD%^%^GREEN%^> %^BLACK%^the knowledge of an"
	"y %^GREEN%^[%^RESET%^item%^BOLD%^%^GREEN%^] %^BLACK%^from the depths of the scribe's tortured mind.%^RESET%^");
	set_property("lore difficulty",30);
    Delay = 0;
    set_heart_beat(1);
}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("wrest_em","wrest");
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


int wrest_em(string str)
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
        tell_object(ETO,"Wrest what?\n");
        return 1;
    }	

    if(Delay) 
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The spirit of the opal writhes and "+
        "screams in agony. It might be a short time before you can demand more "+
        "knowledge.%^RESET%^");
        if(avatarp(ETO))
        {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You are an immortal: The delay is still "+Delay+" heartbeats. "+
            "A heartbeat is supposed to occur every 2 seconds, approximately. Please note "+
            "that Saide coded this slightly differently in that the user must be logged in for the "+
            "delay to tick down.%^RESET%^");
        }
        return 1;
    }
    
    if(!objectp(targ = present(str, ETO))) 
    {
        if(!objectp(targ = present(str, EETO)))
        {
            tell_object(ETO, "%^BOLD%^%^BLACK%^You find no "+str+" here.%^RESET%^");
            return 1;
        }
    }
    
    tell_object(ETO, "%^BOLD%^%^BLACK%^You gaze into the o%^RESET%^%^GREEN%^p"+
    "%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^l's depths, demanding knowledge "+
    "from the spirit enslaved within. A tortured %^BOLD%^%^GREEN%^s%^BOLD%^%^WHITE%^"+
    "c%^BOLD%^%^GREEN%^re%^BOLD%^%^WHITE%^a%^BOLD%^%^GREEN%^m %^BOLD%^%^BLACK%^pierces "+
    "the air as a sudden burst of insight fills you, words rising unbidden to your lips...%^RESET%^");
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ gazes into the depths of the bl%^BOLD%^%^GREEN%^"+
    "a%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^k o%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^a%^BOLD%^%^BLACK%^l, "+
    "looking distant. A tortured %^BOLD%^%^GREEN%^s%^BOLD%^%^WHITE%^"+
    "c%^BOLD%^%^GREEN%^re%^BOLD%^%^WHITE%^a%^BOLD%^%^GREEN%^m%^BOLD%^%^BLACK%^ suddenly "+
    "pierces the air, and "+ETO->QS+" begins to speak...%^RESET%^", ETO);
    
    Delay = 150;
    new("/cmds/spells/l/_legend_lore.c")->use_spell(ETO, str , 35, 1000, "bard");   
        
    return 1;
}



