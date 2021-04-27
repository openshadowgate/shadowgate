#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("double axe");
	set_id(({ "axe", "double axe", "doubleaxe", "spinning axe", "onyx axe", "ironwood axe", "onyx and ironwood double axe" }));
	set_short("%^BOLD%^%^BLACK%^S%^RESET%^%^CYAN%^p%^RESET%^i%^CYAN%^n%^BOLD%^%^BLACK%^ni%^RESET%^%^CYAN%^n%^BOLD%^%^BLACK%^g A%^RESET%^%^CYAN%^x%^BOLD%^%^BLACK%^e%^RESET%^");
	set_obvious_short("%^RESET%^an %^BOLD%^%^BLACK%^onyx%^RESET%^ and %^CYAN%^ironwood %^RESET%^double axe%^RESET%^");
	set_long(
@AVATAR
This double axe beings with a length of beautifully carved %^CYAN%^ironwood%^RESET%^ designed in the form of four interwoven %^GREEN%^vines%^RESET%^ that appear to wrap around one another in a sturdy shaft.  At either end of the shaft, a pair of %^BOLD%^%^BLACK%^onyx blades%^RESET%^ extend.  Shaped like axe head, they are etched with fine ornamentation done in %^BOLD%^%^WHITE%^silvery wire%^RESET%^.

AVATAR
	);
	set_weight(15);
	set_value(100);
	set_lore(
@AVATAR
Weapons such as this are begun from the moment the seeds begin to grow into a young tree.  Twisting and weaving the small seeds together, four trees are bound around one another until they form a strong and sturdy shaft of wood.  From here, the branches are likewise woven until four become one.  It is from the branches that these weapons are crafted, blending the essence of four forms together into one powerful hilt, handle or staff.  Whatever the final weapon calls for. 

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("slashing");
	set_prof_type("double axe");
	set_size(3);
	set_wc(1,12);
	set_large_wc(1,12);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^The %^WHITE%^silver wires%^BLACK%^ on "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLACK%^blades flash as they catch the light!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^WHITE%^silver wires%^BLACK%^ on the "+query_short()+" %^BOLD%^%^BLACK%^blades flash as they catch the light!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLACK%^The %^WHITE%^silver wires%^BLACK%^ on "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLACK%^blades flash as they catch the light, distracting you for a moment with the design's beauty!%^RESET%^");
		targ->set_paralyzed(roll_dice(4,0)+0);
return 0;	}
}