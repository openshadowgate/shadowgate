#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("intricate golden armband");
	set_id(({ "armband", "golden armband", "band", "gold armband", "gold band", "anniversary armband" }));
	set_short("%^YELLOW%^intricate golden armband%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This fantastic armband is made of shimmering gold hammered to an amazing thinness that is meant to be worn on the bicep.  A relief carving on the armband seems to have been fashioned by a true master.  The carving depicts an %^BLACK%^ornate gate %^YELLOW%^standing open before a dank, dark %^BLACK%^dungeon%^YELLOW%^.  A lifelike depiction of a fearsome %^BLACK%^shadow dragon %^YELLOW%^flies forth from the dungeon, its colossal wings casting a shadow over its %^RED%^glittering eyes%^YELLOW%^.  Carved beneath the image is an inscription you could read.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^      Created in celebration of 

    %^BLACK%^ShadowGate's 10th anniversary
%^WHITE%^
             %^YELLOW%^ ~ %^WHITE%^and %^YELLOW%^~
%^RED%^
 Dungeons & Dragons' 30th anniversary!%^RESET%^

AVATAR
	);
     set("langage","wizish");	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
ShadowGate MUD was created ten years ago and remains a favorite of the players and immortal staff.  We are happy you were here to celebrate with us, and we thank you for your continued efforts in making this a wonderful place!

AVATAR
	);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "left arm" }));
	set_size(2);
	set_property("enchantment",0);
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" wears a golden armband with a smile.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^You slide the armband over your bicep and recall the good times you've had playing.%^RESET%^");
	return 1;
}

