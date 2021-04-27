#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("dragonscale crown");
	set_id(({ "crown", "dragonscale crown", "crown of the night's frost", "crown of the nights frost", "scaled crown" }));
	set_short("%^BOLD%^%^BLACK%^C%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^w%^BLACK%^n of the Night's F%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a crown of f%^WHITE%^r%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^d scales%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A band of blackened titanium has been forged to create the base of this dark crown.  The metal has been masterfully etched with intricate images of a dragon being hunted by the forces of nature.  %^YELLOW%^Lightning%^BLACK%^, %^CYAN%^wind%^BLACK%^, %^BLUE%^storms %^BLACK%^and %^RESET%^%^ORANGE%^earthquakes %^BOLD%^%^BLACK%^all plague the draconic figure as though the world itself is rising against the creature.  Extending from this crown, to surround the head, is a veil of scaled mesh.  Made from the scales of a dragon, the mesh is as dark as the night and yet each tiny scale is lined in a crust of %^WHITE%^frost%^BLACK%^.  The mesh extends around the front, to form a half veil that attaches to the nose guard.  This allows the wearer to see, yet protects the face from harm. Extending from disks of ebony on each side of the crown are a set of larger scales that form the shape of wings, arching back from the brows and rising over the head in a majestic, intimidating, display.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_lore(
@AVATAR
In 648 SG a small band of hunters set off into the arctic wilds of the Krakus Mountains.  Their quarry the White Dragon, Qurell.  Said to have a taste for elven flesh, but being rather lazy, Qurell took up a form of husbandry.  Taking elven slaves from the Tonovi area as well as random elves foolish enough to catch her attention in the Kilkean Forest.   After a recent attack upon the Tonvoi jail, a Malarite Hunter named Thorghreg stepped forward to track and destroy this difficult game.  Taking with him a Priest of the Nightsinger and a Priestess of the Stormlord, the three trekked across a wide glacier, fighting foes and nature alike in their quest.  Eventually arriving at Qurell's cave.  Here they fought and destroyed the dragon as well as her cave, before fleeing back to the Hunter's Temple.  There, Malar is said to have been so pleased by their hunt that he took from them the scales from the dragon and forged them into a set of armor.  A suit of scaled plate, a mighty winged helm and an great axe, each of which was imbued with the cold frost of the dragon's chilling breath. 

AVATAR
	);
	set_property("lore difficulty",23);
	set_type("chain");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
      if((string)ETO->query_name() != "belendithas" && (string)ETO->query_name() != "thorghreg" && (string)ETO->query_name() != "amaya") {
	tell_object(ETO,"%^BOLD%^%^BLACK%^This armor does not fit you.%^RESET%^");
	return 0;
      }
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" draws on their "+query_short()+" %^BOLD%^%^BLACK%^and shivers as though a cold %^WHITE%^arctic %^BLACK%^wind blows against them.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The freezing cold of the %^WHITE%^arctic%^BLACK%^ stills around you as you place "+query_short()+" %^BOLD%^%^BLACK%^upon your brow, clarifying and hardening your body against the turmoils of the world.%^RESET%^");
	ETO->set_property("magic resistance",10);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes their "+query_short()+"%^BOLD%^%^BLACK%^ and seems to regain a bit of lost color.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Taking your "+query_short()+" %^BOLD%^%^BLACK%^off, you suddenly remember what it is like to be warm again.%^RESET%^");
	ETO->set_property("magic resistance",-10);
	return 1;
}
