#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dueler's coat");
	set_id(({ "coat", "long coat", "dueler's coat" }));
	set_short("%^RESET%^%^RED%^Du%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^ler's C%^BOLD%^%^WHITE%^o%^RESET%^%^RED%^at%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A fine quality long coat%^RESET%^");
	set_long(
@AVATAR
This is a long, finely made coat of %^RESET%^%^RED%^crimson silk%^RESET%^.  It appears as if it would come to the back of the wearers knees and is styled to be left undone in the front.  Fine, %^BOLD%^%^YELLOW%^golden embroidery %^RESET%^flows around the edges up to the collar and %^BOLD%^%^WHITE%^wh%^BLACK%^i%^WHITE%^te str%^BLACK%^i%^WHITE%^ped t%^BLACK%^i%^WHITE%^gers %^RESET%^have been embroidered along the sides.  It apperas as if it would provide little more than a hamper to its wearer in combat.

AVATAR
	);
	set("read",
@AVATAR
Stephen Deschain, Master Fencer

AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_struck((:TO,"strike_func":));
}


int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),""+ETOQCN+" twirls around wildly partially deflecting "+who->QCN+"'s blow.",({ETO,who}));
	tell_object(ETO,"You twirl around wildly and send "+who->QCN+"'s blow off target slightly.");
	tell_object(who,""+ETOQCN+" twirls around wildly partially deflecting your blow.");
return (damage*65)/100;	}
}