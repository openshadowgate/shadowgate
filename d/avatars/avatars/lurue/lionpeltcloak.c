#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("golden cloak");
	set_id(({ "cloak", "tawny cloak", "cloak of the traveling hunter", "hunter cloak", "fur cloak" }));
	set_short("%^RESET%^%^ORANGE%^C%^BOLD%^%^BLACK%^l%^YELLOW%^o%^BLACK%^a%^RESET%^%^ORANGE%^k of the T%^BOLD%^%^BLACK%^r%^YELLOW%^a%^BLACK%^v%^RESET%^%^ORANGE%^eli%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^g H%^YELLOW%^u%^BLACK%^n%^RESET%^%^ORANGE%^ter%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a t%^BOLD%^%^BLACK%^a%^YELLOW%^w%^BLACK%^n%^RESET%^%^ORANGE%^y f%^BOLD%^%^BLACK%^u%^YELLOW%^r%^BLACK%^r%^RESET%^%^ORANGE%^ed l%^YELLOW%^e%^RESET%^%^ORANGE%^at%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^er c%^YELLOW%^l%^BLACK%^o%^RESET%^%^ORANGE%^ak%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^Sewn from several panels of golden lion's pelt, this cloak is exceptionally well made but quite heavy.  The thick pelt has been carefully tanned causing it to be supple despite the weight.   Hanging from the shoulders down to the ankle the cloak wraps the wearer fully except for the two side slits where arms can be slipped through. Small pockets have been sewn just inside these slits, providing a bit of space to hold a few personal effects.  A secondary half cape extends from the collar and through clever design, this half cape can be drawn up over the wearer's head to provide a wide hood and protection against the elements.  To secure the cloak closed, the tanned forearms of the lion have been left attached, complete with their claws extending from their paws.  These can be looped over one another to tie the garment closed.%^RESET%^

AVATAR
	);
	set_weight(8);
	set_value(1400);
	set_lore(
@AVATAR
Created by the Hunters of Malar, these leather crafted items are made from the training hunts that their Beastlord's clergy use to enhance their skills.  While the meat of the beast is often consumed or used to lure larger prey, the pelts themselves are transformed via a lengthy tanning and crafting process into exceptional clothing or armor.  These pieces are often used by the Hunters as rewards for those outside the faith who have proven themselves either in the hunt or by helping the Hunters directly.  Though they are never given to someone who doesn't actively engage in hunting in one manner or another.  Often referred to by the Beastlord's followers to be "traveling hunters" as they are those who are not of the faith but understand the ways of the hunt, these items have come to be known by a similar name. 

AVATAR
	);
	set_property("lore difficulty",17);
	set_max_internal_encumbrance(4);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" draws the thick hide of the "+query_short()+" %^YELLOW%^about their body and secures it with the lion's arms.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You draw the thick hide of the "+query_short()+" %^YELLOW%^about your body and secure it with the lion's arms.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^Untying the lion's arms, "+ETOQCN+" pulls the "+query_short()+" %^YELLOW%^free from their body.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^Untying the lion's arms, you pull the "+query_short()+" %^YELLOW%^free from your body.%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^YELLOW%^The thick leather of the "+ETOQCN+"'s cloak turns aside "+who->QCN+"'s attack!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^The thick leather of the cloak turns aside "+who->QCN+"'s attack!%^RESET%^");
	tell_object(who,"%^YELLOW%^The thick leather of the "+ETOQCN+"'s cloak turns aside your attack!%^RESET%^");
return (damage*0)/100;	}
}