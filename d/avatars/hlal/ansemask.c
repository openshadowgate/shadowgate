#include <std.h>
inherit "/d/common/obj/clothing/hat";

void create(){
	::create();
	set_name("golden velvet mask");
	set_id(({ "golden velvet mask", "golden mask", "velvet mask", "mask" }));
	set_short("%^YELLOW%^a golden velvet mask with %^RESET%^%^ORANGE%^topaz accents%^RESET%^");
	set_obvious_short("%^YELLOW%^a hawk-like mask of golden velvet%^RESET%^");
	set_long("%^ORANGE%^Fashioned from plush %^BOLD%^golden velvet%^RESET%^%^ORANGE%^, this full mask covers the wearer's face. Attached to a flexible headband of %^BLUE%^blue silk%^ORANGE%^, the mask is allowed to"
	" drape freely. The eye slits are surrounded by small %^YELLOW%^topaz droplets %^RESET%^%^ORANGE%^in such a way to appear as hawk eyes. The nose is beak-like and unadorned. The mouth, like the eyes is "
	"decorated with the same yellow gems that sparkle and allow a large enough opening to speak through.%^RESET%^
"	);
	set_value(10000);
	set_lore("%^ORANGE%^Masks like this one are popular for festivals and other special events. This one has been made at the hands of a master craftsman named Rygor Mintisli. It is known that he likes to sign his "
	"pieces with a few subtle stitches inside the ties of his masks.%^RESET%^
"	);
	set_property("lore difficulty",10);
	set_item_bonus("damage resistance",2);
	set_heart_beat(1);
	set_size(1);
	set_property("enchantment",3);
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
	 if(random(1000) > 998) 
	 {
		switch(random(1)) 
		{
			case 0:
				tell_object(ETO, "%^YELLOW%^A strange glow brightens the topaz droplets on the mask "+ETOQCN+" wears%^RESET%^ ");
				tell_room(EETO, "%^YELLOW%^A strange glow brightens the topaz droplets on the "+query_short()+" that "+ETOQCN+" wears%^RESET%^ ", ({ETO}));
				break;
		}
	}
}