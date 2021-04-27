#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("%^RESET%^%^CYAN%^tr%^BOLD%^a%^RESET%^%^CYAN%^pped%^MAGENTA%^ s%^BOLD%^o%^RESET%^%^MAGENTA%^ul%^CYAN%^ in a %^RESET%^%^ORANGE%^b%^YELLOW%^o%^RESET%^%^ORANGE%^ttle%^RESET%^");
	set_id(({ "soulbottle", "bottle", "soul" }));
	set_short("%^BOLD%^%^BLACK%^Ethius%^CYAN%^ s%^RED%^o%^CYAN%^ulb%^BLUE%^o%^CYAN%^tt%^BLACK%^l%^CYAN%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^tr%^BOLD%^a%^RESET%^%^CYAN%^pped%^MAGENTA%^ s%^BOLD%^o%^RESET%^%^MAGENTA%^ul%^CYAN%^ in a %^RESET%^%^ORANGE%^b%^YELLOW%^o%^RESET%^%^ORANGE%^ttle%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This wine bottle has a slightly %^BOLD%^%^GREEN%^greenish tint%^RESET%^%^ORANGE%^ and looks fairly normal. It has no label on it, and has a kind of cork stopper. Nevertheless, you f"
	"eel a sensation of %^MAGENTA%^sinister intent%^RESET%^%^ORANGE%^ emanating from the bottle. You feel if you removed the stopper, something %^BOLD%^%^RED%^terrible would happen.%^RESET%^%^ORANGE%^ From"
	" inside the bottle there appears to be some %^BOLD%^%^WHITE%^brilliant%^RESET%^%^ORANGE%^ glow that you feel at once can only be a persons %^BOLD%^%^WHITE%^soul!%^RESET%^%^ORANGE%^ A closer look revea"
	"ls that throughout the %^BOLD%^%^WHITE%^soul glow%^RESET%^%^ORANGE%^ are %^RED%^sickly%^ORANGE%^ and %^RED%^evil%^ORANGE%^ looking strands of pure %^GREEN%^malice%^ORANGE%^. Whatever soul is trapped i"
	"n the bottle it is clearly the %^RED%^heart%^RESET%^%^ORANGE%^ of a %^BOLD%^%^BLACK%^villain!%^RESET%^
"
	);
	set_value(10000);
	set_lore("%^BOLD%^%^CYAN%^These bottles are ancient tools of %^BLACK%^necromancers%^CYAN%^ used to trap souls. The %^RESET%^%^MAGENTA%^mystical design%^CYAN%^ of such bottles closely resembles the famous tools "
	"that summoners used to trap %^BLUE%^elementals and djinn%^CYAN%^. However, these bottles are not used for protection, but rather as ultimate %^BLACK%^weapons%^CYAN%^. It cannot be used against a foe w"
	"ho can resist. But against the unconscious or bound enemies, they can be used to trap souls for %^RED%^evil purposes.%^RESET%^

%^BOLD%^%^BLACK%^This bottle has been filled by the %^RESET%^%^MAGENTA%^"
	"Cyrist priest Alzar%^BOLD%^%^BLACK%^ to capture the soul of %^WHITE%^Ethius%^BLACK%^ who betrayed the faith of the mad god. Whoever possesses the bottle also possesses the powers of Ethius. The curse "
	"of %^RESET%^%^MAGENTA%^Cyric%^BOLD%^%^BLACK%^ has fallen on the corpse, turning it into a %^RED%^zombie%^BLACK%^ that tries to reclaim its soul from the confines of the bottle for all %^MAGENTA%^etern"
	"ity!%^RESET%^
"
	);
    set_property("lore difficulty",15);
	set_heart_beat(1);
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks full of strength wearing "+query_short()+".",ETO);
	tell_object(ETO,"You feel full of power wearing the soulbottle.");
	ETO->add_attack_bonus(1);
	ETO->add_damage_bonus(1);
	ETO->do_damage("torso",random(20));
	ETO->set_property("magic resistance",5);
	ETO->add_skill_bonus("stealth",1);
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" looks weaker without the "+query_short()+".",ETO);
	tell_object(ETO,"You feel weaker without the "+query_short()+".");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	ETO->do_damage("torso",random(20));
	ETO->set_property("magic resistance",-5);
	ETO->add_skill_bonus("stealth",-1);
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 1000){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The "+query_short()+"%^BOLD%^%^WHITE%^ glows and the blow from "+who->QCN+"%^BOLD%^%^WHITE%^ passes through "+ETOQCN+" harmlessly.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The "+query_short()+"%^BOLD%^%^WHITE%^ glows and the blow from "+who->QCN+"%^BOLD%^%^WHITE%^ passes through you harmlessly.%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^The "+query_short()+"%^BOLD%^%^WHITE%^ glows and the blow from you %^BOLD%^%^WHITE%^passes through "+ETOQCN+" harmlessly.%^RESET%^");
return (damage*0)/100;	}

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
	 if(random(1000) > 997) 
	 {
		switch(random(10)) 
		{
			case 0:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- LET ME OUT OF HERE!!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- LET ME OUT OF HERE!!%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- Could you at least pour some beer down here??%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- Could you at least pour some beer down here??%^RESET%^", ({ETO}));
				break;
			case 2:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^RED%^-- Blast %^BLACK%^Cyric%^RED%^ that worthless priest %^BLACK%^Alzar%^RED%^ and that two-faced thief %^BLACK%^Dorje!!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^RED%^-- Blast %^BLACK%^Cyric%^RED%^ that worthless priest %^BLACK%^Alzar%^RED%^ and that two-faced thief %^BLACK%^Dorje!!%^RESET%^", ({ETO}));
				break;
			case 3:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^RED%^ Curse those rotten %^GREEN%^elves!!%^RED%^ Tharis %^BLUE%^WILL%^RED%^ be mine!!%^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^RED%^ Curse those rotten %^GREEN%^elves!!%^RED%^ Tharis %^BLUE%^WILL%^RED%^ be mine!!%^RESET%^", ({ETO}));
				break;
			case 4:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^MAGENTA%^-- Belendithas%^RESET%^%^MAGENTA%^, my my hasnt he gone %^BOLD%^soft!%^RESET%^%^MAGENTA%^ I remember back when I %^GREEN%^poisoned%^MAGENTA%^ half of %^BOLD%^%^BLACK%^Shadow%^RESET%^%^MAGENTA%^ pinned it on him, and he did not even blink. %^BOLD%^%^MAGENTA%^Women!!%^RESET%^%^MAGENTA%^ make you weak and steal your gold, and dont you know it... %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^MAGENTA%^-- Belendithas%^RESET%^%^MAGENTA%^, my my hasnt he gone %^BOLD%^soft!%^RESET%^%^MAGENTA%^ I remember back when I %^GREEN%^poisoned%^MAGENTA%^ half of %^BOLD%^%^BLACK%^Shadow%^RESET%^%^MAGENTA%^ pinned it on him, and he did not even blink. %^BOLD%^%^MAGENTA%^Women!!%^RESET%^%^MAGENTA%^ make you weak and steal your gold, and dont you know it... %^RESET%^", ({ETO}));
				break;
			case 5:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^BLUE%^-- Take all that you can and leave nothing for friend or foe. %^RED%^Evil%^BLUE%^ is its own reward, and %^WHITE%^good%^BLUE%^ is for suckers. %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^BLUE%^-- Take all that you can and leave nothing for friend or foe. %^RED%^Evil%^BLUE%^ is its own reward, and %^WHITE%^good%^BLUE%^ is for suckers. %^RESET%^", ({ETO}));
				break;
			case 6:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^MAGENTA%^-- I dont suppose you could stuff a %^RED%^hot%^MAGENTA%^ S%^RED%^u%^MAGENTA%^n%^RED%^i%^MAGENTA%^t%^RED%^e%^RED%^ priestess%^MAGENTA%^ down here too? Its a little lonely!! %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^MAGENTA%^-- I dont suppose you could stuff a %^RED%^hot%^MAGENTA%^ S%^RED%^u%^MAGENTA%^n%^RED%^i%^MAGENTA%^t%^RED%^e%^RED%^ priestess%^MAGENTA%^ down here too? Its a little lonely!! %^RESET%^", ({ETO}));
				break;
			case 7:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^BLACK%^-- die! %^RESET%^%^RED%^Die! %^BOLD%^DIE!!! %^RESET%^%^CYAN%^Are we killing %^BOLD%^%^BLACK%^OR WHAT??? %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^BLACK%^-- die! %^RESET%^%^RED%^Die! %^BOLD%^DIE!!! %^RESET%^%^CYAN%^Are we killing %^BOLD%^%^BLACK%^OR WHAT??? %^RESET%^", ({ETO}));
				break;
			case 8:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- B-%^BLUE%^O-%^RED%^R-%^WHITE%^I-%^BLACK%^N-%^YELLOW%^G,%^RED%^ at least if I have to stay in this bottle do something entertaining like %^BLACK%^stealing, %^RESET%^%^MAGENTA%^death, or %^BOLD%^%^WHITE%^r%^CYAN%^a%^WHITE%^n%^CYAN%^d%^WHITE%^o%^CYAN%^m%^RED%^ m%^RESET%^%^RED%^a%^BOLD%^y%^RESET%^%^RED%^h%^BOLD%^e%^RESET%^%^RED%^m%^BOLD%^! %^RESET%^");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- B-%^BLUE%^O-%^RED%^R-%^WHITE%^I-%^BLACK%^N-%^YELLOW%^G,%^RED%^ at least if I have to stay in this bottle do something entertaining like %^BLACK%^stealing, %^RESET%^%^MAGENTA%^death, or %^BOLD%^%^WHITE%^r%^CYAN%^a%^WHITE%^n%^CYAN%^d%^WHITE%^o%^CYAN%^m%^RED%^ m%^RESET%^%^RED%^a%^BOLD%^y%^RESET%^%^RED%^h%^BOLD%^e%^RESET%^%^RED%^m%^BOLD%^! %^RESET%^", ({ETO}));
				break;
			case 9:
				tell_object(ETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- You know %^WHITE%^Synoria%^GREEN%^ near burnt to the ground by %^BLACK%^Shadow thieves%^GREEN%^. The river caught on %^RED%^fire%^GREEN%^ from all the %^RESET%^%^ORANGE%^crap%^BOLD%^%^GREEN%^ and %^BLACK%^dead bodies%^GREEN%^ floating in it. I wish I coulda %^MAGENTA%^seen%^GREEN%^ that!!%^RESET%^ ");
				tell_room(EETO, "%^BOLD%^%^CYAN%^A %^RESET%^%^ORANGE%^muffled voice%^BOLD%^%^CYAN%^ emanates from "+query_short()+" %^BOLD%^%^CYAN%^worn by "+ETOQCN+" %^BOLD%^%^GREEN%^-- You know %^WHITE%^Synoria%^GREEN%^ near burnt to the ground by %^BLACK%^Shadow thieves%^GREEN%^. The river caught on %^RED%^fire%^GREEN%^ from all the %^RESET%^%^ORANGE%^crap%^BOLD%^%^GREEN%^ and %^BLACK%^dead bodies%^GREEN%^ floating in it. I wish I coulda %^MAGENTA%^seen%^GREEN%^ that!!%^RESET%^ ", ({ETO}));
				break;
		}
	}
}