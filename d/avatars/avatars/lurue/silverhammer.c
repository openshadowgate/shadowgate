#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("silver hammer");
	set_id(({ "hammer", "silver hammer", "silvery hammer" }));
	set_short("%^BOLD%^%^WHITE%^S%^RESET%^%^RED%^i%^BOLD%^%^WHITE%^lver Ham%^RESET%^%^RED%^m%^BOLD%^%^WHITE%^er%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a hammer made of silver%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This small hammer appears to be something meant for delicate craft work rather then fighting, however the inner %^RESET%^%^CYAN%^titanium %^BOLD%^%^WHITE%^core gives it some weight and durability that the otherwise silver exterior would not.  One end of the hammer is wide and flat, a perfect oval pebbled with a hash like grid.  While the other side tapers to a sharp point, which is slightly curved, allowing it to pry or pick as needed.  The handle is wrapped in %^RED%^blood red %^WHITE%^leather and is held fast with bands of %^RESET%^%^CYAN%^titanium%^BOLD%^%^WHITE%^.  No further adornment can be seen.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^You can %^RED%^bash%^WHITE%^ something, %^RED%^hit%^WHITE%^ something, %^RED%^pry%^WHITE%^ something and even %^RED%^stabbit%^WHITE%^ something with this hammer.%^RESET%^

AVATAR
	);
     set("langage","kobold");	set_weight(4);
	set_value(3000);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^Toward the end of 687 SG, a masquerade was held in order to raise funds for the restoration of the Rhapsody, a well known Inn that was destroyed earlier that year by a group of drunken adventurers.  At the end of the night, after all the stories were told and the dances were danced, the judges gathered to pick two costumes.  One of those costumes, a puppet like creation of a yaun-ti was deemed as the winner of the most original costume and this silver hammer, said to be a playful prop, was awarded to Adderlash. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",12);
	set_type("bludgeoning");
	set_prof_type("hammer");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^A blood red glint comes into "+ETOQCN+"'s eyes as they take hold of the %^RESET%^"+query_short()+"%^BOLD%^%^RED%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Your hand takes firm grip upon the blood red handle and you feel an insatiable urge to strike something... dead.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" polishes the %^RESET%^"+query_short()+" %^BOLD%^%^RED%^before putting it away.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You wipe the head of your hammer clean and grin with murderous thoughts as you put the hammer aside.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" slips around behind "+targ->QCN+" and strikes them in the head with their %^RESET%^"+query_short()+"%BOLD%^%^WHITE%^.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^BANG BANG%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^You hear a noise from behind and then suddenly feel a blow to your head!%^RESET%^");
		return roll_dice(2,4)+1;	}

}
