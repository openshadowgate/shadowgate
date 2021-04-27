#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("necklace");
	set_id(({ "skull", "necklace", "amulet", "gold-plated skull", "gold-plated rat skull", "rat skull", "skull of the rat lord" }));
	set_short("%^YELLOW%^Sk%^WHITE%^u%^YELLOW%^ll of the R%^WHITE%^a%^YELLOW%^t L%^WHITE%^o%^YELLOW%^rd%^RESET%^");
	set_obvious_short("%^RESET%^a %^YELLOW%^gold-plated %^RESET%^rat skull ");
	set_long(
@AVATAR

%^YELLOW%^The elongated form of this %^WHITE%^rat skull %^YELLOW%^is plated in a thin layer of gold as though the skull had been quickly dipped within a pool of the yellowy liquid and then hung to dry. %^RED%^Tiny rubies %^YELLOW%^have been set within the eye sockets while the incisors appear to have been replaced with long, polished bands of %^BLACK%^black diamond%^YELLOW%^. Appearing to be meant as a piece of jewelry, a hoop of gold has been set through the back of the skull where the jaw connects to the mandible, serving to keep the two halves of the skull in place.  Through this, a chain made of linked finger bones has been drawn, each of the oblong bones connected by golden links. %^RESET%^ 


AVATAR
	);
	set_weight(5);
	set_value(1500);
	set_lore(
@AVATAR

In some cultures and societies jewelry made from the remains of an animal. Said to grant anything from luck and power to the ability to ward off spirits, these symbols, or totems as they are sometimes called, often have great personal meaning to the wearer and can often be seen decorated with precious jewels and arcane symbols to further enhance the meaning and value behind these sacred items. 


AVATAR
	);
	set_property("lore difficulty",6);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^Air currents shift and you notice a %^BOLD%^%^BLACK%^rotten%^RESET%^%^CYAN%^, %^RED%^coppery %^CYAN%^smell coming from "+ETOQCN+"'s direction.%^RESET%^",ETO);
	tell_object(ETO,"%^WHITE%^%^BOLD%^You hear the click of tiny teeth coming from the %^YELLOW%^golden rat skull %^WHITE%^tied about your neck.%^RESET%^ ");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^The air seems to clear a little around "+ETOQCN+" as they take their %^RESET%^"+query_short()+"%^RESET%^%^CYAN%^off.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^YELLOW%^gold%^WHITE%^, %^BLACK%^diamonds%^WHITE%^ and %^RED%^rubies%^WHITE%^ glitter as you take the necklace off.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^dark red gleam%^BOLD%^%^BLACK%^ can be seen in the eyes of "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^ as "+who->QCN+" strikes "+ETOQCN+".%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^dark red gleam %^BOLD%^%^BLACK%^glows within the eyes of your %^YELLOW%^golden rat skull%^BLACK%^ and you could almost swear the thing gnashed its teeth in a repulsive smile at "+who->QCN+"'s last attack.%^RESET%^ ");
	tell_object(who,"%^BOLD%^%^BLACK%^You strike "+ETOQCN+" soundly and think you've gotten away with your attack when you realize that the %^RESET%^%^RED%^gleaming red eyes %^BOLD%^%^BLACK%^of the %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^around "+ETOQCN+"'s neck have turned your way.  Pain spills through your head and causes your spine to bow as every nerve in your body lights up with %^RESET%^%^RED%^agony%^BOLD%^%^BLACK%^!%^RESET%^");
		who->do_damage("torso",roll_dice(2,6));
return damage;	}

}
