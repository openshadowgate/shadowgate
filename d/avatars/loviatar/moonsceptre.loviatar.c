#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("%^YELLOW%^Moon Sceptre%^RESET%^");
	set_id(({ "sceptre", " moon sceptre" }));
	set_short("%^YELLOW%^An elaborate sceptre seemingly made out of gold.%^RESET%^");
	set_obvious_short("elaborate golden sceptre");
	set_long(
@AVATAR
This beautifully made sceptre inset with %^YELLOW%^yellow diamonds%^RESET%^ and %^RED%^rubies%^RESET%^ has a two foot long handle and a heavy head in a form of four beautifull winged women wearing shimmering robes.  One of them has her hands parted as if holding an object that is not there.  The next one is holding a half moon in form of new moon.  Third is holding a full moon.  The final statuette is holding a half moon in form of old moon.  The sceptre is a wonder of craftsmanship and would fetch a good price from the markets.  It also seems to vibrate slightly.

AVATAR
	);
	set_weight(35);
	set_value(1000);
	set_lore(
@AVATAR
Used by angels of old goddess,
Made to give the faithfull hope,
Golden sceptre was created,
At the dawn of times by Her.

AVATAR
	);
	set_type("bludgeoning");
	set_prof_type("Religious Artifact of Selune");
	set_size(2);
	set_wc(2,6);
	set_large_wc(2,6);
	set_property("enchantment",5);
	set_ac(1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(ETP,""+query_short()+"",TP);
	tell_object(TP,"%^YELLOW%^You feel steely resolve to smite those who would use moonlit shadows to bring harm into the world.%^RESET%^");
	TP->add_damage_bonus(5);
	return 1;
}
int unwield_func(){
	tell_room(ETP,""+query_short()+"",TP);
	tell_object(TP,"%^YELLOW%^You regretfully let go of the sceptre, longing for closeness with the spirit of the moon filling the very core of your being.%^RESET%^");
	TP->add_damage_bonus(-5);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"",({ETO,targ}));
	tell_object(ETO,"You score another blow against the enemies of MoonMaiden!");
	tell_object(targ,"Your body is battered by terrible force of the sceptre.");
		return roll_dice(1,6)+4;	}
}