#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("kobold statue");
	set_id(({ "statue", "kobold statue", "flesh of stone" }));
	set_short("%^RESET%^%^ORANGE%^F%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^esh of S%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^one%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a statue of a kobold%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This statue is incredibly detailed, though you wonder why anyone would create a statue of a kobold.  Still, the little beast appears to be captured in mid motion.  His scale covered paw held up as though warding off your stare, while his snout is turned just a little to the side as though he is turning his head away.  Thick robes of what appears to be some sort of pale hide decorate this little kobold's body with a realism that allows you to see almost every cell of the fabric. Large steel looking shoes adorn his feet and a curious dented pot tops his head, providing him with a comical look, if only his eyes didn't seem filled with fear.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(100);
	set_lore(
@AVATAR
No one makes kobold statues, they're just not popular enough, so this could only be a statue made from a real kobold.  Which would, come to think of it, make more sense then some random artist creating such an ugly little beast.  The vivid detail of the features and the attention to detail of the stone, also lead you to believe that either some mage must have taken annoyance with the little creature and polymorphed it from flesh to stone, or that a basilisk or medusa must have taken notice of the little trash digger.  Either way, it would seem the creature is dead and that his fancy protective gear didn't help one bit.

AVATAR
	);
	set_property("lore difficulty",18);
}