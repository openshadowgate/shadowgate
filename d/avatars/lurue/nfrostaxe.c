#include <std.h>
inherit "/d/common/obj/weapon/large_battle_axe";

void create(){
	::create();
	set_name("dragonscale axe");
	set_id(({ "axe", "frosted axe", "biting axe", "biting axe of the night's frost", "biting axe of the nights frost" }));
	set_short("%^BOLD%^%^BLACK%^B%^WHITE%^i%^RESET%^t%^BOLD%^%^BLACK%^i%^WHITE%^n%^BLACK%^g A%^RESET%^x%^BOLD%^%^BLACK%^e of the Night's F%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^an axe covered in f%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^d scales%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This giant axe is a chilling weapon to be faced with.  Forged from the large neck plates and smaller neck scales of a large dragon it is not only frightening to behold but dangerous in the right set of hands. Six %^WHITE%^diamond shaped %^BLACK%^plates have been forged together to create this uniquely designed axe head, the result of which produces a very sharp serrated top with six slicing %^WHITE%^spikes %^BLACK%^extending out in a fan shape, leaving the cutting edge smooth and sharp. The haft of the weapon is made from blackened titanium wrapped in a fine mesh of the smaller scales, giving the item a secure and functional grip.  Each scale is blacker then a moonless night and appears to be rimmed in a crust of %^WHITE%^frost%^BLACK%^.%^RESET%^ 

AVATAR
	);
	set_value(5000);
	set_lore(
@AVATAR
In 648 SG a small band of hunters set off into the arctic wilds of the Krakus Mountains.  Their quarry the White Dragon, Qurell.  Said to have a taste for elven flesh, but being rather lazy, Qurell took up a form of husbandry.  Taking elven slaves from the Tonovi area as well as random elves foolish enough to catch her attention in the Kilkean Forest.   After a recent attack upon the Tonvoi jail, a Malarite Hunter named Thorghreg stepped forward to track and destroy this difficult game.  Taking with him a Priest of the Nightsinger and a Priestess of the Stormlord, the three trekked across a wide glacier, fighting foes and nature alike in their quest.  Eventually arriving at Qurell's cave.  Here they fought and destroyed the dragon as well as her cave, before fleeing back to the Hunter's Temple.  There, Malar is said to have been so pleased by their hunt that he took from them the scales from the dragon and forged them into a set of armor.  A suit of scaled plate, a mighty winged helm and an great axe, each of which was imbued with the cold frost of the dragon's chilling breath. 

AVATAR
	);
	set_property("lore difficulty",23);
	set_property("enchantment",4);
      set("dexbonus",-1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
      if((string)ETO->query_name() != "belendithas" && (string)ETO->query_name() != "thorghreg" && (string)ETO->query_name() != "amaya") {
	tell_object(ETO,"%^BOLD%^%^BLACK%^You cannot wield this.%^RESET%^");
	return 0;
      }
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" shudders as they take hold of their "+query_short()+"%^BOLD%^%^BLACK%^ as a frosting of ice rims their hair.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Taking the "+query_short()+"%^BOLD%^%^BLACK%^ in hand, you shudder as a chill settles in your bones.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A crackling sound of breaking ice reaches your ears as "+ETOQCN+" unwields their "+query_short()+"%^BLACK%^%^BOLD%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^With an immense force of will you pry your hand to open from its frozen grip upon "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 150){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^An arctic wind blows in from no where and freezes the blade of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^just before it bites into "+targ->QCN+"'s body!  As the weapon makes contact a spray of ice explodes adding extra damage to an already brutal blow!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^An arctic wind blows in from no where and freezes the blade of your "+query_short()+" %^BOLD%^%^WHITE%^just before it bites into "+targ->QCN+"'s body!  As the weapon makes contact a spray of ice explodes adding extra damage to an already brutal blow!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^An arctic wind blows in from no where and freezes the blade of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^just before it bites into your body!  As the weapon makes contact a spray of ice explodes adding extra damage to an already brutal blow!%^RESET%^");
		return roll_dice(3,4)+1;	}
}