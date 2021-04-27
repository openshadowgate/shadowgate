#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("intricately carved emerald");
	set_id(({ "gem", "emerald", "intricately carved emerald", "intricately carved gem", "green gem", "emerald gem", "Bane's Star" }));
	set_short("%^BOLD%^%^GREEN%^intricately carved emerald with delicate protrusions%^RESET%^");
	set_obvious_short("%^BOLD%^%^GREEN%^intricately carved emerald with delicate protrusions%^RESET%^");
	set_long(
@AVATAR
An emerald gem with the main body approximately the size of a small bird egg and carved into a twelve faceted polyhedron. Each of the twenty points among the faces extends upwards in spindly protrusions that rise from the main body of the gem about a half inch. The whole piece appears to be carved from a much larger piece, the spindly protrusions having no visible seams forming to the main body. Each face has a different set of strange lines formed into a pattern. The etched lines vaguely resemble claw markings yet are carefully and meticulously set into the precious stone.

AVATAR
	);
	set("read",
@AVATAR
All glory held in my fist.

AVATAR
	);
     set("langage","kobold");	set_weight(0);
	set_value(2500);
	set_lore(
@AVATAR
%^BOLD%^The markings upon the gem are clearly Kobold religious symbols. A spattering of the symbols represent dominance and rigidity, while others appear to form a holy mantra written in the kobold's own language.

%^BOLD%^Though the symbols are obscure, their implications and the choice of gemstone clearly signifies the deity to which this gem is in adoration of:

%^BOLD%^%^GREEN%^Bane.

%^BOLD%^The spindly nature of the protrusions are not random and hint at a complex pattern. The entire structure implies the gem is an implement of channeling divine will in ritual worship.

AVATAR
	);
	set_property("lore difficulty",16);
}