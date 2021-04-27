#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("goldegg");
	set_id(({ "egg", "gold egg" }));
	set_short("%^BOLD%^%^YELLOW%^Mys%^WHITE%^ti%^YELLOW%^c %^WHITE%^G%^YELLOW%^o%^WHITE%^ld%^YELLOW%^e%^WHITE%^n %^YELLOW%^E%^WHITE%^gg%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^BLACK%^petrified %^YELLOW%^egg%^RESET%^");
	set_long("
%^BOLD%^%^WHITE%^This is a hardened shell of an egg, %^BLACK%^petrified %^WHITE%^by time into a rock hard object and mounted lavishly as a trophy of sorts.  It is a %^YELLOW%^deep golden %^WHITE%^col"
	"or but has become slightly %^YELLOW%^m%^WHITE%^a%^YELLOW%^r%^WHITE%^b%^YELLOW%^l%^WHITE%^e%^YELLOW%^d %^WHITE%^as time has weathered it.  The %^YELLOW%^egg %^WHITE%^itself is quite large and looks lik"
	"e it would weigh quite a bit.  It is mounted on a wooden stand of %^RESET%^%^RED%^ma%^ORANGE%^h%^RED%^o%^ORANGE%^g%^RED%^an%^ORANGE%^y %^BOLD%^%^WHITE%^and has been fitted tightly into it in such a wa"
	"y to make you think the wood actually grew around the %^YELLOW%^egg%^WHITE%^.  There is a small plaque on the base of the wood.%^RESET%^ 
"
	);
	set_value(0);
	set_weight(10);
	set_lore("%^BOLD%^%^YELLOW%^....The twin princes of the ancient land battled for many years over who would succeed their dead father, King Ferrion II.  Each employed similar tactics even though their principals"
	" were so different.  After all, they had the same teachers and a like mind, no matter how their hearts were torn.  Each seeking the upper hand after a decade a battle, they sought council from the kin"
	"gdom's sage.  The evil sage watched eagerly hoping the two brothers would kill each other so as to allow him a possible coup to the throne.  He told each of the value of a dragon in battle and sent ea"
	"ch on a seperate quest to find an egg.  The sage had these eggs enchanted with the powers to call upon and control the lords of the air similar to their own desires.  A fierce battle ensued above the "
	"mountains between the twins and their dragons with no victor.  Both brothers were tossed from their winged mounts and were killed by the mountains below.  The eggs disappeared into the mountains with "
	"them.   The old sage soon claimed the throne and made attempts to retrieve his creations but to no avail.  He was killed in riots not many years later and the eggs were forgotten about, lost in those "
	"mountains.....%^RESET%^

                                 -%^BOLD%^%^GREEN%^Tales of Greed  Vol. 3  'Royalty'%^RESET%^
"
	);
    set_property("lore difficulty",20);
}
