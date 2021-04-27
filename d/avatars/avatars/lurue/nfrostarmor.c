#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dragonscale armor");
	set_id(({ "dragonscale", "scaled armor", "dragonscale of the night's frost", "frost armor", "dragonsclae of the nights frost", "frosted armor", "armor" }));
	set_short("%^BOLD%^%^BLACK%^Dr%^WHITE%^a%^RESET%^g%^BOLD%^%^WHITE%^o%^BLACK%^ns%^WHITE%^c%^RESET%^a%^BOLD%^%^WHITE%^l%^BLACK%^e of the Night's F%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a suit of f%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^d scaled armor%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This suit of platemail has been crafted from the hide of a dragon.  The scales are darker then night yet their edges appear lined with a rim of frost.  A mesh of small, neatly layered scales have been affixed to a tunic of black leather, making the armor comfortable and light to wear.  Over this mesh, following the line of the sternum, five large scales form the front plate of the armor.  This theme is repeated on the back via a set of wide plates over each shoulder blade that taper in smaller and smaller scales till the design ends in long narrow tips.  This creates the illusion of furled wings against the back.  Protecting the shoulders are several medium sized plates, while the lower forearms are covered in a mesh of smaller scales.  The elbows joints, hips and collar guards are made from blackened titanium, their shape and coloring blending well with the rest of this dark armor.%^RESET%^

AVATAR
	);
	set_weight(40);
	set_value(6000);
	set_lore(
@AVATAR
In 648 SG a small band of hunters set off into the arctic wilds of the Krakus Mountains.  Their quarry the White Dragon, Qurell.  Said to have a taste for elven flesh, but being rather lazy, Qurell took up a form of husbandry.  Taking elven slaves from the Tonovi area as well as random elves foolish enough to catch her attention in the Kilkean Forest.   After a recent attack upon the Tonvoi jail, a Malarite Hunter named Thorghreg stepped forward to track and destroy this difficult game.  Taking with him a Priest of the Nightsinger and a Priestess of the Stormlord, the three trekked across a wide glacier, fighting foes and nature alike in their quest.  Eventually arriving at Qurell's cave.  Here they fought and destroyed the dragon as well as her cave, before fleeing back to the Hunter's Temple.  There, Malar is said to have been so pleased by their hunt that he took from them the scales from the dragon and forged them into a set of armor.  A suit of scaled plate, a mighty winged helm and an great axe, each of which was imbued with the cold frost of the dragon's chilling breath. 

AVATAR
	);
	set_property("lore difficulty",23);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(8);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
      if((string)ETO->query_name() != "belendithas" && (string)ETO->query_name() != "thorghreg" && (string)ETO->query_name() != "amaya") {
	tell_object(ETO,"%^BOLD%^%^BLACK%^This armor does not fit you.%^RESET%^");
	return 0;
      }
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" shivers as though suddenly cold as they don their "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You shiver with the cold as you don the "+query_short()+"%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" regains some of their color as they remove their "+query_short()+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Warmth floods back into your body as you remove your "+query_short()+"%^RESET%^");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^"+ETOQCN+" opens their mouth as though to cry out as "+who->QCN+"'s weapon lands a blow against "+ETOQCN+"'s "+query_short()+"%^BOLD%^%^WHITE%^.  Instead of a scream, a blast of freezing cold air explodes from between "+ETOQCN+"'s blue tinged lips!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^An arctic wind swirls around you as "+who->QCN+"'s weapon clangs against your "+query_short()+"%^BOLD%^%^WHITE%^.  You open your mouth as though to cry out and instead a blast of freezing air escapes your lips!%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^Your weapon strikes against "+ETOQCN+"'s "+query_short()+"%^BOLD%^%^WHITE%^ and you feel confident you've done some damage.  You notice that "+ETOQCN+" has opened their mouth to let out a cry of pain, and instead of sound a torrent of freezing cold air blasts against you!%^RESET%^");
		who->do_damage("torso",random(40));
return damage;	}
}