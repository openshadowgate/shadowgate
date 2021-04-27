#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("impaler's hook");
	set_id(({ "hook", "impaler's hook", "bloody hook" }));
	set_short("%^BOLD%^%^RED%^Imp%^RESET%^%^RED%^a%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^r's h%^RESET%^%^RED%^oo%^BOLD%^k%^RESET%^");
	set_obvious_short("%^BLACK%^A %^BOLD%^%^RED%^bloody %^BLACK%^adamantium hook%^RESET%^");
	set_long(
@AVATAR
This is an odd weapon indeed.  It is comprised of a semi-large %^BOLD%^%^BLACK%^adamantium hook %^RESET%^and a circular, round handguard.  However, the shaft of the hook extends beyond the handguard, leading you to believe it is mean to be implanted in the %^RESET%^%^ORANGE%^stump %^RESET%^of an arm.  The hook is %^BOLD%^%^RED%^wickedly serrated %^RESET%^and looks like it would rip through flesh like a %^BOLD%^%^RED%^hot knife %^RESET%^through %^YELLOW%^butter%^RESET%^.

AVATAR
	);
	set_weight(5);
	set_value(200);
	set_property("lore difficulty",0);
	set_type("slashing");
	set_prof_type("tool");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,4);
	set_property("enchantment",4);
	set_ac(1);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),""+ETOQCN+" manages to get their %^BOLD%^%^RED%^hook %^RESET%^behind the leg of "+targ->QCN+" and pulls them off balance.",({ETO,targ}));
	tell_object(ETO,"You deftly place your %^BOLD%^%^RED%^hook %^RESET%^behind your opponents leg and pull with extreme force, knocking them off their feet.");
	tell_object(targ,""+ETOQCN+" suddenly works their %^BOLD%^%^RED%^hook %^RESET%^behind your leg and pulls you off balance.");
		targ->set_paralyzed(roll_dice(1,10)+0);
return 0;	}
}