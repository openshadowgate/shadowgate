#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("jeweled armor");
	set_id(({ "platemail", "plate mail", "plate", "armor", "jeweled armor", "seraphim armor", "jeweled seraphim armor" }));
	set_short("%^BOLD%^%^BLUE%^Jeweled %^BLACK%^Se%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ap%^RESET%^h%^GREEN%^i%^BOLD%^%^BLACK%^m %^BLUE%^Armor %^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a suit of %^RESET%^%^MAGENTA%^j%^WHITE%^e%^GREEN%^w%^MAGENTA%^e%^GREEN%^l%^WHITE%^e%^MAGENTA%^d %^BOLD%^%^BLUE%^platemail%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^BLUE%^This gothic styled armor is made fromblue steel, forged for protection of the torso and upper legs.  The metal is a dark metallic blue in coloring, with %^RESET%^silvery swirls%^BOLD%^%^BLUE%^ and %^BLACK%^etchings %^BLUE%^placed across the majority of the metal.  The etchings are mostly swirls and coils that could be anything from wisps of vapor to coiling vines, depending on the viewer's perspective.  On the breast plate though, two figures face inward toward the center.  Mirror images of one another, one is done in %^RESET%^moonstone %^BOLD%^%^BLUE%^with %^RESET%^%^GREEN%^emerald %^BOLD%^%^BLUE%^highlights, while the other is done is %^BLACK%^onyx %^BLUE%^with %^RESET%^%^MAGENTA%^amethyst%^BOLD%^%^BLUE%^ highlights.  The figures appear angelic, complete with folded wings and flowing garments.  Clutched in their hands in a two handed style stance are %^BLACK%^dark %^BLUE%^and %^RESET%^light %^BOLD%^%^BLUE%^swords, crossing mid way at the blade as though locked in eternal combat.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(12000);
	set_lore(
@AVATAR

Knights and warriors have been known throughout the ages to wear armor that is both ornate and functional.  Many have been known to hire armorsmiths as part of their personal staff to help maintain and build new armor as needed.  This typically resulted in very personalized displays engraved upon the armor over the course of time.  The symbols upon this armor date back to the Daggerdale region from around the third century SG.  The household's name was Sertangee and their heraldic symbols often featured crossed swords held by a heavenly figure (often imagined to symbolize the matriarch of the family).  Toward the end of the third century the figure had taken on wings (believed to have happened at her death) and split into two, to represent the division of the household and the departure of the youngest son. 

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(9);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^The clang of swords sounds near "+ETOQCN+" and you see "+who->QCN+" looking shocked.%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^The clang of swords sounds and "+who->QCN+"'s attack is blocked by the %^BLACK%^Se%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ap%^RESET%^h%^GREEN%^i%^BOLD%^%^BLACK%^m's %^BOLD%^%^BLUE%^sword!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLUE%^You watch in surprise as the %^BLACK%^Se%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ap%^RESET%^h%^GREEN%^i%^BOLD%^%^BLACK%^m %^BOLD%^%^BLUE%^on "+ETOQCN+"'s armor block your attack!%^RESET%^");
return (damage*-80)/100;	}

}
