#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^RED%^Blo%^RESET%^%^BOLD%^%^BLACK%^ody mur%^RESET%^%^RED%^der%^RESET%^");
	set_id(({ "dagger", "Dagger" }));
	set_short("%^BOLD%^%^BLACK%^A%^RESET%^ %^RED%^bloodsoaked%^RESET%^ %^BOLD%^%^BLACK%^dagger%^RESET%^");
	set_obvious_short("Bhaals Dagger");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Made from an alien metal, this gruesome dagger is the things nightmares are made of. The blade of the dagger, almost as long as a short sword, is warped and contorted as if in agony. The edge is razor sharp, serrated and generally, the worst dream of unscarred flesh. The hilt is wrapped with dark leather, possibly demonskin. The pommel of this dagger is fashioned to look like a%^RESET%^ %^RED%^bloodshot%^RESET%^ %^BOLD%^%^WHITE%^eye%^RESET%^%^BLUE%^b%^RESET%^%^BOLD%^%^WHITE%^all%^RESET%^ %^BOLD%^%^BLACK%^and is constantly shifting, its pupil wide with terror. Most disturbingly,%^RESET%^ %^RED%^blood%^RESET%^ %^BOLD%^%^BLACK%^seems to endlessly leak from every inche of this blade.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^RED%^This PWNS noobs%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(5 pounds);
	set_value(0);
	set_type("slashing");
	set_prof_type("small blades");
	set_size(small);
	set_wc(10,20);
	set_large_wc(10,20);
	set_property("enchantment",30);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^RED%^Blood drips from "+ETOQCN+" hand as it grips%^RESET%^ "+query_short()+"",ETO);
	tell_object(ETO,""+query_short()+" %^RED%^slicks your palm with warm blood%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" stares at his hands, entranced by the blood after he sets $o aside%^RESET%^",ETO);
	tell_object(ETO,"%^RED%^Your hand is still bloody, even after releasing%^RESET%^ "+query_short()+"");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 1/5){
	tell_room(environment(query_wielded()),""+query_short()+" %^RED%^opens up "+targ->QCN+", spraying him with blood, causing "+ETOQCN+" to grin%^RESET%^",({ETO,targ}));
	tell_object(ETO,""+query_short()+" %^RED%^opens up "+targ->QCN+", spraying him with blood%^RESET%^");
	tell_object(targ,"%^RED%^"+ETOQCN+" get opened up, your blod being drained by "+query_short()+"%^RESET%^");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}
}