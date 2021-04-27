#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("platinum hilted dagger");
	set_id(({ "diamond slicer", "platinum hilted dagger", "dagger", "platinum dagger", "diamond dagger", "slicing dagger", "slicing diamond", "slicing diamond dagger" }));
	set_short("%^BOLD%^%^WHITE%^Sl%^BLACK%^i%^WHITE%^c%^BLACK%^i%^WHITE%^ng Di%^BLACK%^a%^WHITE%^m%^BLACK%^o%^WHITE%^nd D%^BLACK%^a%^WHITE%^gg%^BLACK%^e%^WHITE%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A pl%^BLACK%^a%^WHITE%^tin%^BLACK%^u%^WHITE%^m h%^BLACK%^i%^WHITE%^lt%^BLACK%^e%^WHITE%^d d%^BLACK%^a%^WHITE%^gg%^BLACK%^e%^WHITE%^r%^RESET%^");
	set_long(
@AVATAR
%^RESET%^The blade of this dagger at first looks to be made from %^BOLD%^%^WHITE%^quartz%^RESET%^, clear %^YELLOW%^calcite%^RESET%^ or some other semi precious stone due to the slight %^BOLD%^%^BLACK%^haze%^RESET%^ apparent in the blade.  On closer inspection however, it can be seen that the %^BOLD%^%^BLACK%^haze%^RESET%^ comes from having several razor thin slices of cut %^BOLD%^%^WHITE%^di%^BLACK%^a%^WHITE%^m%^BLACK%^o%^WHITE%^nd %^RESET%^overlapping one another.  Each sliver of %^BOLD%^%^WHITE%^di%^BLACK%^a%^WHITE%^m%^BLACK%^o%^WHITE%^nd %^RESET%^is beveled so that it tapers to a deadly edge that cuts deep and precise, making this a very deadly weapon indeed.  Bound with %^BOLD%^%^WHITE%^platinum %^RESET%^wire, the hilt and cross guard of this blade is heavy and neatly balanced so it is comfortable in the grip, even when slippery with %^RED%^blood%^RESET%^. 

AVATAR
	);
	set_weight(2);
	set_value(2000);
	set_lore(
@AVATAR
Diamonds have long been praised for their strength and ability to cut almost anything.  The ability to shape them requires a master artisan with years of practice.  Such is the skill that was needed to craft this dagger and its' many layers of diamond slivers.  Made by the halfling smith Aelkin Shadowtoes, a retired Maskarian thief, each gem is carefully selected for its purity and then sliver by sliver cut into over a dozen layers which are each shaped till their edges are razor thin.  After this, they are set together with clever twists of a strong metal that keep the slivers just loose enough so that when they draw blood the whole blade seems to turn red as the life blood becomes trapped between the slivers.   

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^The diamond blade of the "+query_short()+"%^RESET%^%^CYAN%^ glints as it is drawn by "+ETOQCN+".%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The diamond blade of the "+query_short()+"%^RESET%^%^CYAN%^ glints as you draw it.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^With a deft flip of the wrist "+ETOQCN+" sheaths the "+query_short()+"%^RESET%^%^CYAN%^.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^With a deft flip of the wrist you sheath the "+query_short()+"%^RESET%^%^CYAN%^.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^"+ETOQCN+"'s "+query_short()+"%^RESET%^%^CYAN%^ catches the %^YELLOW%^light %^RESET%^%^CYAN%^and reflects a gleaming %^RED%^crimson %^CYAN%^as "+targ->QCN+" gasps in pain from a dangerous cut!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^CYAN%^The "+query_short()+"%^RESET%^%^CYAN%^ catches the %^YELLOW%^light %^RESET%^%^CYAN%^and reflects a gleaming %^RED%^crimson %^CYAN%^as "+targ->QCN+" gasps in pain from a dangerous cut!%^RESET%^");
	tell_object(targ,"%^RESET%^%^CYAN%^"+ETOQCN+"'s "+query_short()+"%^RESET%^%^CYAN%^ catches the %^YELLOW%^light %^RESET%^%^CYAN%^and reflects a gleaming %^RED%^crimson %^CYAN%^as you gasp in pain from a dangerous cut!%^RESET%^");
		return roll_dice(2,4)+-1;	}
}