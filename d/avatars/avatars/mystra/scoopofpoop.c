#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("rabbitcrap");
	set_id(({ "poop", "shit", "caca", "crap", "terds", "pellets", "logs", "mess" }));
	set_short("%^RED%^Scattered Pellets of %^BOLD%^%^WHITE%^Rabbit %^BLACK%^Crap%^RESET%^");
	set_obvious_short("%^GREEN%^a mess%^RESET%^");
	set_long("%^ORANGE%^These pellets are partially made up of %^RED%^dead bacteria%^ORANGE%^. These microcorpses come from the intestinal %^GREEN%^garden %^ORANGE%^of microorganisms that assist us in the digestion"
	" of our food.  Another part of the %^BOLD%^%^BLACK%^turd mass %^RESET%^%^ORANGE%^is made of stuff that we find indigestible, like %^WHITE%^cellulose%^ORANGE%^, for instance. This indigestible material"
	" is called %^YELLOW%^fiber, %^RESET%^%^ORANGE%^and is useful in getting the turd to move along through the intestine, perhaps because it provides traction. The remaining portion is a %^MAGENTA%^mixtur"
	"e of fats %^ORANGE%^such as cholesterol, inorganic salts like phosphates, live bacteria, dead cells and mucus from the lining of the intestine, and protein.%^RESET%^
"
	);
	set_value(0);
	set_weight(1);
	set_lore("%^BOLD%^%^BLACK%^Amorphous deposit, anal butter, ass apple, black banana, butt nut, crapola, crusty critters, doodie, dookie, dung, excrement, fecal matter, keester cakes, sewer trout, poop....whateve"
	"r you wanna call it.  These mudbunnies came FROM the bunnies left in the room and need to be cleaned up.  They are made up of whatever it is bunnies eat.  And really, who the hell studies a piece of s"
	"hit anyway?%^RESET%^
"
	);
    set_property("lore difficulty",0);
    set("chabonus",-10);
	set_heart_beat(1);
}

void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
	 if(random(500) > 495) 
	 {
		switch(random(2)) 
		{
			case 0:
				tell_object(ETO, "%^ORANGE%^Flies start buzzing around the "+query_short()+" in your hands%^RESET%^");
				tell_room(EETO, "%^ORANGE%^A pack of flies starts gathering around "+ETOQCN+"%^RESET%^", ({ETO}));
				break;
			case 1:
				tell_object(ETO, "%^BOLD%^The odor "+ETOQCN+" emits while holding "+query_short()+" is immense%^RESET%^");
				tell_room(EETO, "%^BOLD%^A strong odor is coming from "+query_short()+"%^RESET%^", ({ETO}));
				break;
		}
	}
}