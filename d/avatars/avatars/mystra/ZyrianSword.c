#include <std.h>
inherit "/d/common/obj/weapon/scimitar";

void create(){
	::create();
	set_name("scimitar");
	set_id(({ "sword", " scimitar" }));
	set_short("%^RESET%^%^BOLD%^%^WHITE%^Sw%^YELLOW%^o%^WHITE%^rd of %^YELLOW%^t%^WHITE%^he %^WHITE%^Zy%^YELLOW%^ri%^WHITE%^an Soc%^YELLOW%^i%^WHITE%^ety%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^%^WHITE%^brilliant curved sword%^RESET%^");
	set_long("%^BOLD%^The Zy%^YELLOW%^ri%^WHITE%^an Sci%^YELLOW%^mi%^WHITE%^tar is a very decorated sword with an impressive history in combat.  From pommel to point, the sword is painstakingly flawless in design.  The steel used to "
"forge the blade is of only the very finest quality.  Hand polished to a glaring shine, not the slightest imperfection can be found.  The crossguard of the weapon is made of solid %^YELLOW%^gold %^WHITE%^that has been purified by an unknown "
"process.  Just below the guard, the sword grip is custom made to fit perfectly to it's wielder by slow carving the ivory to the shape of his hand.  The pommel is ornately decorated with alternating %^GREEN%^emeralds %^WHITE%^and %^RED%^rubies "
"%^WHITE%^all around it's ball.  It truly looks more like a decoration piece than a weapon ready for battle, though the sharpness of the edge of the blade lets you know otherwise.%^RESET%^");
	set_value(100000);
	set_lore("%^BOLD%^%^WHITE%^The Zy%^YELLOW%^ri%^WHITE%^an Soc%^YELLOW%^i%^WHITE%^ety has a rich history of fighters with extraordinary accomplishments and deeds.  Among these, the %^BLUE%^Lord Erymon %^WHITE%^of %^BLUE%^Channuree "
"%^WHITE%^was well known for his courageousness in the face of overwhelming odds.  Against the orcish horde that invaded his lands from the underground caves near the %^BLACK%^Bentair Mountains%^WHITE%^, %^BLUE%^Erymon %^WHITE%^was "
"outnumbered with his troops 4 to 1.  Refusing to allow his lands to be overrun by such evil creatures, the lord duped the orcs into chasing him into the %^RED%^Canyon of M'uur%^WHITE%^.  Once in the canyon, %^BLUE%^Lord Erymon's %^WHITE%^"
"archers, high on the canyon ridge fired into the orc horde, evening the odds so he could turn and give chase.  The lord turned and charged hard into the remaining orcs, personally spilling enough orc-blood that the soil remained discolored "
"for 100 years.  It is said the sword he carried served to aid him in battle with special magic embued within it's metal, though noone really knows what use the magic was.  This replica of that sword serves to remind all Zyr%^YELLOW%^i%^WHITE%^"
"ans that no matter how bleak the odds, a way to victory can always be found.  A small inscription inset in this sword can be seen on the bottom of the pommel.%^RESET%^");
	set_property("lore difficulty",30);
	set("conbonus",2);
	set("dexbonus",-1);
	set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^A glint of fire radiates from the hilt of "+query_short()+" as "+ETOQCN+" wields it.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The "+query_short()+" burns in your hands as you wield it.%^RESET%^");
	ETO->add_attack_bonus(2);
	ETO->do_damage("torso",random(50));
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The flame that was encircling "+ETOQCN+" dissipates as the "+query_short()+" is let go.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^A cooling sensation overcomes your palms when you let go of "+query_short()+"%^RESET%^");
	ETO->add_attack_bonus(-2);
	ETO->do_damage("torso",random(50));
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 50){
		tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^A stunning blow is dealt as the flame around "+ETOQCN+" hand travels through the "+query_short()+" and into "+targ->QCN+".%^RESET%^",({ETO,targ}));
		tell_object(ETO,"%^BOLD%^%^RED%^The flame around your hands travels up through the blade of "+query_short()+" and into "+targ->QCN+".%^RESET%^");
		tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" blinds you with a burst of flame from the "+query_short()+".%^RESET%^");
		targ->set_paralyzed(roll_dice(2,4)+0);
	return 0;
	}
}
