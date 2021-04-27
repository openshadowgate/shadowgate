#include <std.h>
inherit "/d/common/obj/weapon/rapier";

void create(){
	::create();
	set_name("%^RESET%^%^BLUE%^Q%^ORANGE%^u%^BLUE%^i%^ORANGE%^l%^BLUE%^l%^BOLD%^%^BLUE%^sword%^RESET%^%^MAGENTA%^ of %^BOLD%^%^WHITE%^Piercing%^RESET%^");
	set_id(({ "rapier", "quill", "quillsword", "quillsword of piercing", "rapier of piercing" }));
	set_short("%^RESET%^%^BLUE%^Q%^ORANGE%^u%^BLUE%^i%^ORANGE%^l%^BLUE%^l%^BOLD%^%^BLUE%^sword%^RESET%^%^MAGENTA%^ of %^BOLD%^%^WHITE%^Piercing%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^sturdy %^BLUE%^f%^ORANGE%^e%^BLUE%^a%^ORANGE%^t%^BLUE%^h%^ORANGE%^e%^BLUE%^r%^ORANGE%^e%^BLUE%^d %^BOLD%^quill%^RESET%^");
	set_long("%^MAGENTA%^This quill is formed from mithril. Odd though that may seem, the feathers themselves are formed of adamantium. This strange quill does not seem very well equipped to write anything down at "
	"all. The very last quill near the base is bent all the way back to the shaft itself. You realize that when you grasp it and press down on that feather, a thin blade shoots out of the back end of the f"
	"eathers and the feathers themselves snap down horizontal to the sword to form a rather formidable hilt. This quill would be a perfect weapon for those who look as if they are defenseless, but giving t"
	"hem that extra edge.%^RESET%^
"
	);
	set_value(5000);
	set_lore("%^GREEN%^These Quillswords, as the priesthood of Oghma have tagged them, were created in order to give scribes an added defense should their perspective businesses or employers run afoul of trouble. T"
	"he church of Oghma decided to make them enmasse in order to turn a small profit with specific merchants in mind. Some have even been known to be enchanted to offer extra offensive power.%^RESET%^
"
	);
    set_property("lore difficulty",8);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" grasps the shaft of the quill and presses the lowest feather. You hear a metallic *shirk* as a thin blade shoots forward from the quill.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You grasp the shaft of the quill and press the feather, hearing a satisfying *click* as the thin blade shoots forward.%^RESET%^");
	ETO->add_damage_bonus(1);
	ETO->add_skill_bonus("stealth",1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" presses the feather again and the thin blade slides back into the quill.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You press the feather again, watching as the thin blade slides back into the quill.%^RESET%^");
	ETO->add_damage_bonus(-1);
	ETO->add_skill_bonus("stealth",-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 80){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" plunges the rapier's tip deep into "+targ->QCN+"%^BOLD%^%^WHITE%^'s knee, causing it to buckle beneath them.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You plunge the rapier's tip deep into "+targ->QCN+"%^BOLD%^%^WHITE%^'s knee, causing it to buckle beneath them.%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" plunges the rapier's tip deep into your knee, causing it to buckle beneath you.%^RESET%^");
		targ->set_paralyzed(roll_dice(3,0)+0);
return 0;	}

}
