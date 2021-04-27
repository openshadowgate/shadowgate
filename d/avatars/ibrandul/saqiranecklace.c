#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^MAGENTA%^amulet of the fe%^RESET%^%^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^te%^RESET%^%^WHITE%^r%^RESET%^%^MAGENTA%^ed %^RESET%^%^ORANGE%^s%^RESET%^%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^ar%^RESET%^%^WHITE%^r%^RESET%^%^ORANGE%^ow%^RESET%^");
	set_id(({ "amulet", "amulet of the fettered sparrow", "crystal amulet" }));
	set_short("%^RESET%^%^MAGENTA%^amulet of the fe%^RESET%^%^BOLD%^%^BLACK%^t%^RESET%^%^MAGENTA%^te%^RESET%^%^WHITE%^r%^RESET%^%^MAGENTA%^ed %^RESET%^%^ORANGE%^s%^RESET%^%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^ar%^RESET%^%^WHITE%^r%^RESET%^%^ORANGE%^ow%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^g%^RESET%^%^BOLD%^%^MAGENTA%^l%^RESET%^%^MAGENTA%^ow%^RESET%^%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng cr%^RESET%^%^BOLD%^%^WHITE%^y%^RESET%^%^MAGENTA%^stal amu%^RESET%^%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^et%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^MAGENTA%^suspended from a chain of c%^RESET%^%^WHITE%^u%^RESET%^%^MAGENTA%^t cr%^RESET%^%^WHITE%^y%^RESET%^%^MAGENTA%^sta%^RESET%^%^WHITE%^l%^RESET%^%^MAGENTA%^s that seem to suspend each other is a large %^RESET%^%^BOLD%^%^MAGENTA%^crystal shard%^RESET%^%^MAGENTA%^. As you look at the shard, you notice that its %^RESET%^%^BOLD%^%^BLACK%^vibrating%^RESET%^%^MAGENTA%^, %^RESET%^%^BOLD%^%^BLACK%^shaking %^RESET%^%^MAGENTA%^almost %^RESET%^%^RED%^violently %^RESET%^%^MAGENTA%^as if something wants to get out. A %^RESET%^%^BOLD%^%^WHITE%^bright light %^RESET%^%^MAGENTA%^ricochets back and forth inside, a small bright %^RESET%^%^BOLD%^%^RED%^flame %^RESET%^%^MAGENTA%^trapped%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^"+ETOQCN+" slips on the "+query_short()+", a look of %^RESET%^%^BOLD%^%^RED%^pain %^RESET%^%^MAGENTA%^crossing thier features as they do...%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^you slip the "+query_short()+" around your neck. You are struck by a sudden rush of %^RESET%^%^BOLD%^%^BLACK%^emotion%^RESET%^%^MAGENTA%^, and you hear a child %^RESET%^%^BOLD%^%^RED%^scream%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^"+ETOQCN+" closes thier eyes as they remove the "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^MAGENTA%^You still hear the %^RESET%^%^BOLD%^%^BLACK%^sobs %^RESET%^%^MAGENTA%^as you remove the "+query_short()+"...%^RESET%^");
	return 1;
}
