#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("Hammer of Filth");
	set_id(({ "hammer", "warhammer" }));
	set_short("%^RESET%^%^ORANGE%^Hammer of Filth%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a plain, dirty hammer%^RESET%^");
	set_long(
@AVATAR
(later on alterobj)

AVATAR
	);
	set("read",
@AVATAR
%^RESET%^%^ORANGE%^the power of the %^BOLD%^%^ORANGE%^Earthlord %^RESET%^%^ORANGE%^will fill you if you are worthy%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(15);
	set_value(2500);
	set_lore(
@AVATAR
This hammer appears mundane. The head is pockmarked, a clue to the many battles it has seen.  The handle is rough and would probably shred the hands of the lesser experienced that tried to wield it.  Priest from the temple of Grumbar maintain control of this hammer and only allow certain members of the faith to borrow it.  The member is tested on their faith and, if successful, are able to wield it and feel its powers.

AVATAR
	);
	set_property("lore difficulty",15);
	set("strbonus",1);
	set("chabonus",-1);
	set("dexbonus",-1);
	set("conbonus",1);
	set_type("bludgeoning");
	set_prof_type("medium hammer");
	set_size(2);
	set_wc(3,6);
	set_large_wc(4,6);
	set_property("enchantment",4);
	set_ac(0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 100){
	tell_room(environment(query_wielded()),"%^RESET%^%^BOLD%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^smashes %^BOLD%^%^BLACK%^"+targ->QCN+" %^RESET%^%^ORANGE%^smartly with the %^BOLD%^%^ORANGE%^"+query_short()+" %^RESET%^%^ORANGE%^knocking them backwards roughly%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^BOLD%^%^ORANGE%^"+query_short()+" %^RESET%^%^ORANGE%^strikes %^BOLD%^%^BLACK%^"+targ->QCN+" %^RESET%^%^ORANGE%^smartly knocking them backwards%^RESET%^");
	tell_object(targ,"%^RESET%^%^BOLD%^%^ORANGE%^"+ETOQCN+" %^RESET%^%^ORANGE%^smashes you with their %^BOLD%^%^ORANGE%^"+query_short()+" %^RESET%^%^ORANGE%^knocking you backwards nearly off your feet%^RESET%^");
		targ->set_paralyzed(roll_dice(1,4)+0);
return 0;	}
}