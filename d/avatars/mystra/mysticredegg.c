#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("redegg");
	set_id(({ "egg" }));
	set_short("%^RESET%^%^RED%^Mys%^BOLD%^%^WHITE%^ti%^RESET%^%^RED%^c %^BOLD%^%^WHITE%^G%^RESET%^%^RED%^o%^BOLD%^%^WHITE%^ld%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^n %^RESET%^%^RED%^E%^BOLD%^%^WHITE%^gg%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a %^BLACK%^petrified %^RESET%^%^RED%^egg%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This is a hardened shell of an egg, %^BLACK%^petrified %^WHITE%^by time into a rock hard object and mounted lavishly as a trophy of sorts.  It is a %^RESET%^%^RED%^deep red %^BOLD%^%^"
	"WHITE%^in color but has become slightly %^RESET%^%^RED%^m%^BOLD%^%^WHITE%^a%^RESET%^%^RED%^r%^BOLD%^%^WHITE%^b%^RESET%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^d %^BOLD%^%^WHITE%^as time has weathere"
	"d it.  The %^RESET%^%^RED%^egg %^BOLD%^%^WHITE%^itself is quite large and looks like it would weigh quite a bit.  It is mounted on a wooden stand of %^RESET%^%^RED%^ma%^ORANGE%^h%^RESET%^%^RED%^o%^ORA"
	"NGE%^g%^RESET%^%^RED%^an%^ORANGE%^y %^BOLD%^%^BOLD%^%^WHITE%^and has been fitted tightly into it in such a way to make you think the wood actually grew around the %^RESET%^%^RED%^egg%^BOLD%^%^WHITE%^."
	"  There is a small plaque on the base of the wood.%^RESET%^ 
"
	);
	set_value(0);
	set_weight(10);
	set_lore("%^BOLD%^%^RED%^....The twin princes of the ancient land battled for many years over who would succeed their dead father, King Ferrion II.  Each employed similar tactics even though their principals we"
	"re so different.  After all, they had the same teachers and a like mind, no matter how their hearts were torn.  Each seeking the upper hand after a decade a battle, they sought council from the kingdo"
	"m's sage.  The evil sage watched eagerly hoping the two brothers would kill each other so as to allow him a possible coup to the throne.  He told each of the value of a dragon in battle and sent each "
	"on a seperate quest to find an egg.  The sage had these eggs enchanted with the powers to call upon and control the lords of the air similar to their own desires.  A fierce battle ensued above the mou"
	"ntains between the twins and their dragons with no victor.  Both brothers were tossed from their winged mounts and were killed by the mountains below.  The eggs disappeared into the mountains with the"
	"m.   The old sage soon claimed the throne and made attempts to retrieve his creations but to no avail.  He was killed in riots not many years later and the eggs were forgotten about, lost in those mou"
	"ntains.....%^RESET%^

                                 -%^BOLD%^%^GREEN%^Tales of Greed  Vol. 3  'Royalty'%^RESET%^
"
	);
    set_property("lore difficulty",30);
}
