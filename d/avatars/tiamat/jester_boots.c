#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("jester boots");
	set_id(({ "boots", "jester boots", "shoes", "boot", "shoe", "jester shoes" }));
	set_short("%^RESET%^%^BOLD%^%^RED%^J%^YELLOW%^e%^RED%^st%^YELLOW%^e%^RED%^r B%^YELLOW%^oo%^RED%^ts%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^RED%^curly boots%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BOLD%^%^RED%^This is a pair of boots that look like they belong on a court jester!  They're made primarily of flax linen but the outside is wrapped in silky, bright r%^YELLOW%^e%^RED%^d and %^YELLOW%^y%^RED%^e%^YELLOW%^ll%^RED%^o%^YELLOW%^w %^RED%^s%^YELLOW%^t%^RED%^r%^YELLOW%^i%^RED%^p%^YELLOW%^e%^RED%^s.  The boots tie all the way up the calves, providing some protection against tumbles, sprains and falls.  The tips of the boots curl upward, ending in shoddy %^RESET%^%^ORANGE%^brass%^BOLD%^%^RED%^ bells.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(2100);
	set_lore(
@AVATAR
In a golden age that feels so far away, the court jester was just as often magician and entertainer, using magic and agility to spellbind the crowd.  A few artifacts of these early jesters still remain, often being found in the personal collections of wealthy Antioch citizens.  Although you find no evidence of who the former owner is, they clearly had a sense of humor.

AVATAR
	);
	set_property("lore difficulty",5);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^BOLD%^%^RED%^When %^RESET%^"+ETOQCN+"%^RESET%^ %^BOLD%^%^RED%^puts on the jester boots, they jingle playfully!%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^The bells jingle playfully when you put on the boots!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^"+ETOQCN+" %^RESET%^%^BOLD%^%^RED%^takes off the jester boots and has less fun.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^You get a little more serious and take off the jester boots.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^RESET%^%^BOLD%^%^RED%^The jester boots worn by "+ETOQCN+" magically force them to tumble from this attack!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^Your jester boots leap out of the way of the attack!%^RESET%^");
	tell_object(who,"%^RESET%^%^BOLD%^%^RED%^"+ETOQCN+" tumbles from your attack, landing on their jester boots!%^RESET%^");
return (damage*100)/100;	}
}