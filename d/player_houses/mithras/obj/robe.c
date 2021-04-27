#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

void create(){
        int placeholder, *placeholder2;
        ::create();
        set_property("creator","mithras");
        set_property("quality",18);
        set_size(2);
        set_name("robe");
        set_id(({ "robe", "contoured robe", "wool robe", "green robe", "green wool robe", "contoured green wool robe", "robe" }));
        set_short("%^RESET%^%^GREEN%^con%^BOLD%^t%^RESET%^%^GREEN%^oured g%^BOLD%^r%^RESET%^%^GREEN%^een wool r%^ORANGE%^o%^GREEN%^be%^RESET%^");
        set_long("%^RESET%^%^GREEN%^This robe is fashioned from very soft wool of moderate thickness.  The wool is dyed a deep, rich, uniform green.  In fashion, most robes are formless, saggy "
"garments, but this one seems to have been made by a very skilled tailor with an eye for form in unity with function.  The robe is created with a short collar that sweeps down in front a few "
"inches, but not so much as to be immodest.  The sleeves are long, ending with a gentle flare allowing free use of the hands, and have a pair of straps with a hidden button that could be used "
"to roll them up to just below the elbow.  At the torso, it becomes obvious that this robe was created with a woman in mind.  Gentle contouring allows the wearer's form to be embraced, yet is "
"not so tight as to seem pretentious.  From the hips downward, the robe falls in gentle ripples, the extra material would certainly allow mobility while not becoming a shapeless mass.  The "
"collar, sleeves, and hem of the garment are embr%^BOLD%^o%^RESET%^%^GREEN%^idered with a delicate %^BOLD%^v%^RESET%^%^ORANGE%^i%^GREEN%^n%^BOLD%^e %^RESET%^%^GREEN%^pattern.  Each %^BOLD%^le"
"%^RESET%^%^GREEN%^a%^BOLD%^f %^RESET%^%^GREEN%^is indi%^BOLD%^v%^RESET%^%^GREEN%^idu%^BOLD%^a%^RESET%^%^GREEN%^lly designed, and the %^ORANGE%^vines %^GREEN%^are textured.  Inside, the robe is "
"lined with an extremely %^RESET%^soft white silk %^GREEN%^for comfort, and a pair of pockets are placed in such a way that any items placed within would not easily fall out.%^RESET%^"
"\n\nMastercrafted");
        set_lore("%^BOLD%^%^WHITE%^This robe was made by the elf Mithras Silvertree, for his human lover Marie, to be worn to the Springtime Festival of Synoria in 701SG.  Too fond of it to set "
"it aside thereafter, she instead had it blessed by her temple and continued to wear it ever since.%^RESET%^");
        set_property("lore difficulty",35);
        set_max_internal_encumbrance(21);
}