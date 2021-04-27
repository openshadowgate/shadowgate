#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("redeemers testament");
	set_id(({ "statue", "statuette", "figurine", "phoenix statuette", "phoenix", "testament", "redeemers testament", "redeemer's testament" }));
	set_short("%^BOLD%^%^MAGENTA%^R%^ORANGE%^e%^RED%^d%^WHITE%^e%^RESET%^e%^BOLD%^%^RED%^m%^ORANGE%^e%^MAGENTA%^r's T%^RED%^e%^ORANGE%^s%^RED%^t%^WHITE%^a%^RED%^m%^ORANGE%^e%^RED%^n%^MAGENTA%^t%^RESET%^");
	set_obvious_short("%^YELLOW%^a %^RED%^p%^RESET%^%^RED%^h%^BOLD%^o%^RESET%^%^RED%^e%^BOLD%^n%^RESET%^%^RED%^i%^BOLD%^x %^ORANGE%^statuette %^WHITE%^w%^RESET%^r%^BOLD%^e%^RESET%^at%^BOLD%^he%^RESET%^d %^YELLOW%^in %^WHITE%^f%^RED%^l%^MAGENTA%^a%^RED%^m%^WHITE%^e%^RESET%^");
	set_long("%^YELLOW%^Taking on the unmistakable form of a %^RED%^phoenix %^ORANGE%^in flight, this small statuette is cast from flawless %^RESET%^%^ORANGE%^r%^MAGENTA%^o%^BOLD%^%^RED%^s%^RESET%^%^ORANGE%^e g%^BO"
	"LD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^l%^ORANGE%^d%^BOLD%^, detailed so meticulously that each of the bird's %^RED%^c%^WHITE%^o%^MAGENTA%^r%^ORANGE%^u%^GREEN%^s%^WHITE%^c%^GREEN%^a%^ORANGE%^t%^MAGENTA%^"
	"i%^WHITE%^n%^RED%^g f%^WHITE%^e%^ORANGE%^a%^GREEN%^t%^WHITE%^h%^ORANGE%^e%^WHITE%^r%^RED%^s %^ORANGE%^looks so real as to be plucked away with ease, and its penetrating eyes of %^RED%^r%^MAGENTA%^u%^R"
	"ED%^by %^ORANGE%^seem to hold a startling wisdom within. The phoenix is wreathed in an aura of %^WHITE%^holy flame%^ORANGE%^, utterly harmless but for its %^RESET%^%^MAGENTA%^faint%^YELLOW%^, %^RESET%"
	"^%^MAGENTA%^comforting %^RED%^w%^BOLD%^a%^RESET%^%^MAGENTA%^r%^BOLD%^%^RED%^mt%^RESET%^%^RED%^h%^YELLOW%^, and flickering at the edges with brilliant %^RESET%^%^ORANGE%^golds%^BOLD%^, %^RED%^reds%^ORA"
	"NGE%^, and %^MAGENTA%^pinks%^ORANGE%^. This symbol instills a feeling of %^CYAN%^divine watchfulness%^ORANGE%^, and the sensations that come with it: of %^WHITE%^light%^ORANGE%^, %^GREEN%^renewal%^ORA"
	"NGE%^, and %^MAGENTA%^redemption%^ORANGE%^.%^RESET%^
"	);
	set_value(0);
	set_weight(1);
	set_lore("%^YELLOW%^These blazing statuettes, cast in the likeness of a phoenix, have long been found in the possession of Lathander's faithful, but their exact origin remains unclear. Though unconfirmed, one o"
	"f the most popular stories claims that the metal used in their creation once belonged to the armor of Lathander himself. It is said that in one of his many battles during the Godswar, a particularly f"
	"earsome opponent sundered a portion of his brilliant golden armor with a mighty blow. Cast to the ground, the blood of the Morninglord infused the metal with newfound strength and purpose, granting it"
	"s rosy hue and unmistakable divine energy. Whether or not there is any truth to this story, these divine artifacts are often granted to fallen knights of the Morninglord's church as lights to guide th"
	"eir way back to a path of goodness, and as symbols of Lathander's confidence in their ability to achieve redemption.%^RESET%^
"	);
	set_property("lore difficulty",15);
}
