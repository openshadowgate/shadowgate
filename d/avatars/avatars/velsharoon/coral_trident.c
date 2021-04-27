#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("trident");
	set_id(({ "trident", "coral", "coral trident" }));
	set_short("%^BOLD%^%^MAGENTA%^C%^WHITE%^o%^MAGENTA%^ral %^YELLOW%^Tri%^RESET%^%^ORANGE%^d%^BOLD%^ent%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^c%^WHITE%^o%^MAGENTA%^ral%^RESET%^-shaped %^ORANGE%^trident%^RESET%^");
	set_long(
@AVATAR
%^MAGENTA%^This trident has been fashioned from a single piece of %^BOLD%^c%^WHITE%^o%^MAGENTA%^ral%^RESET%^%^MAGENTA%^. The shaft has been smoothed down so as not to inadvertantly harm the wielder. The tines of the trident are wickedly %^BOLD%^%^BLUE%^serrated%^RESET%^%^MAGENTA%^ by the addition of %^BLUE%^sh%^RESET%^a%^BLUE%^rk %^BOLD%^%^WHITE%^teeth%^RESET%^%^MAGENTA%^. The tips are, of course, hooked and look as if would cause significant damage if removed from someones skin. The weapon is lightweight and seems extremely durable despite its makeup.%^RESET%^ 

AVATAR
	);
	set_weight(3);
	set_value(1600);
	set_lore(
@AVATAR
The Sahuagin clerics venerate Sekolah, the devil shark. Their primary weapon of choice, besides their formidable spells, is a trident. The coral tridents are fashioned magically from coral, obviously. Shark teeth can then be affixed to these weapons to make them deadlier, as well as making it more favored in the eyes of Sekolah.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("piercing");
	set_prof_type("spear");
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,8);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^You notice "+ETOQCN+" grin devilishly as they take up the wicked trident.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You grin evilly as you think of all the flesh you will rend with this weapon.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^Gobbets of flesh fall from "+ETOQCN+"'s trident as they set it aside.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You reluctantly set the trident away, flicking gobbets of flesh off of its tines as you do.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^"+ETOQCN+" %^BOLD%^%^BLUE%^savagely %^RESET%^%^BLUE%^rips%^RED%^ gobbets of flesh from "+targ->QCN+" as they pull the trident free!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^RED%^You feel the tines of the trident %^BLUE%^grip%^RED%^ into "+targ->QCN+" and you viciously %^BOLD%^rip%^RESET%^%^RED%^ the trident out of them!%^RESET%^");
	tell_object(targ,"%^RESET%^%^RED%^You grimace in agony as the trident is %^BLUE%^ripped%^RED%^ from your skin, gobbets of flesh still on its tines!%^RESET%^");
		return roll_dice(2,4)+0;	}

}
