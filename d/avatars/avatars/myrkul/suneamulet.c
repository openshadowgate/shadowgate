#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("%^RESET%^%^ORANGE%^ancient amulet%^RESET%^");
	set_id(({ "amulet", "amulet of sune" }));
	set_short("%^YELLOW%^A%^RESET%^%^ORANGE%^m%^YELLOW%^u%^RESET%^%^ORANGE%^l%^YELLOW%^e%^RESET%^%^ORANGE%^t%^MAGENTA%^ of %^ORANGE%^S%^CYAN%^t%^ORANGE%^ea%^CYAN%^d%^ORANGE%^fa%^CYAN%^s%^ORANGE%^t%^BOLD%^%^RED%^ L%^MAGENTA%^o%^RED%^ve%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a%^CYAN%^n%^ORANGE%^ci%^CYAN%^e%^ORANGE%^nt a%^CYAN%^m%^ORANGE%^ulet%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This amulet is not much to look at. It is made of %^ORANGE%^copper%^CYAN%^, slightly %^GREEN%^green with age%^CYAN%^, with many scratches. The round medallion itself is a %^YELLOW%^lo"
	"cket%^RESET%^%^CYAN%^, and inside the locket is an engraved portrait of a %^BOLD%^young couple%^RESET%^%^CYAN%^ in old-fashioned clothing. Overall, the medallion is small, round, and embellished with "
	"a %^BOLD%^%^RED%^crimson rose%^RESET%^%^CYAN%^. The chain is a simple link. Although rather meager in terms of jewelry, the amulet seems to radiate %^RED%^warmth.%^RESET%^
"
	);
	set_value(10);
	set_lore("%^BOLD%^%^MAGENTA%^It is said that %^RED%^Sune%^MAGENTA%^ herself once wore this very amulet and blessed it. Originally the medallion was made for a young woman by her husband. Separated by accident, "
	"the woman waited steadfastly for years for her husband, who then wore it in her honor. Then it was the husbands turn to wait steadfastly for years when the wife became separated during a mishap. The d"
	"etails of these events have been lost to time, however, it is known that %^RED%^Sune%^MAGENTA%^ herself honored their love and imbued this amulet with power as a relic for her church.%^RESET%^
"
	);
    set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",6);
}



