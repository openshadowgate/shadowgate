#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("Decorated Hilt");
	set_id(({ "hilt", "sword hilt", "decorated hilt", "two handed hilt" }));
	set_short("%^YELLOW%^Ma%^WHITE%^g%^YELLOW%^n%^WHITE%^i%^YELLOW%^fice%^WHITE%^nt%^YELLOW%^ D%^WHITE%^e%^YELLOW%^co%^WHITE%^rat%^YELLOW%^e%^WHITE%^d %^YELLOW%^Hi%^WHITE%^l%^YELLOW%^t%^RESET%^");
	set_obvious_short("%^YELLOW%^Tw%^WHITE%^o %^YELLOW%^Han%^WHITE%^d%^YELLOW%^ed Hilt%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This is the hilt of a two handed sword.  The hilt of this sword is all that remains but you can almost picture the excellent quality blade that must surely have once have graced it.  %^RED%^The hilt is bound with rich red ancient leather.  %^CYAN%^The guard itself is ornamented with %^YELLOW%^go%^WHITE%^ld an%^YELLOW%^d a%^WHITE%^d%^YELLOW%^aman%^WHITE%^ti%^YELLOW%^um%^WHITE%^ fil%^YELLOW%^igree %^RESET%^%^CYAN%^in gracefully curving lines.  The swirling lines are sometimes slender, sometimes broad, sometimes tapering, but always on a curve.  The artistry of the decoration has an air of antiquity.

AVATAR
	);
	set_weight(5);
	set_value(25000);
	set_lore(
@AVATAR
%^BOLD%^%^WHITE%^The decoration on the hilt is in the Urness style.  The interlacing continual curves on the hand guard are typical of this style of artwork which dates back to a time almost beyond remembering save for myths and legends...

%^BOLD%^%^CYAN%^One legend that refers to such a magnificently decorated hilt is that of the Colalliner Paladins.  Of a much later period than the Urness-style art, the tale of Colalliner fortress is one of bravery against insurmountable odds.  It was said that one of the many treasures and blessed items lost to the realms when the fortress was laid waste was a holy relic of the church of Torm.  The hilt of a two-handed sword once wielded by Torm himself.

AVATAR
	);
}