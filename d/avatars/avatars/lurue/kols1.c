#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("statue");
	set_id(({ "statue", "dragon statue", "moonstone statue" }));
	set_short("%^BOLD%^%^WHITE%^a small %^RESET%^m%^BOLD%^%^CYAN%^o%^WHITE%^o%^RESET%^ns%^BOLD%^%^CYAN%^t%^WHITE%^o%^RESET%^ne %^BOLD%^%^WHITE%^statue of a dragon%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a small %^RESET%^m%^BOLD%^%^CYAN%^o%^WHITE%^o%^RESET%^ns%^BOLD%^%^CYAN%^t%^WHITE%^o%^RESET%^ne %^BOLD%^%^WHITE%^statue of a dragon%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This heavy statue is in the shape of a dragon.  Small enough to sit in the palm of a hand, the statue is made out of a solid piece of %^RESET%^m%^BOLD%^%^CYAN%^o%^WHITE%^o%^RESET%^ns%^BOLD%^%^CYAN%^t%^WHITE%^o%^RESET%^ne%^BOLD%^%^WHITE%^.  The figure of the dragon sits on its hind legs, with its forelegs before it and the long serpentine tail curled around its legs, making for a very solid base. The dragon's head it tilted upward, as though looking toward the sky, and its wings are unfurled, rising up behind it and then curling outward toward the top.  Oddly, there are three small %^BLACK%^holes %^WHITE%^in the statue, one in each wing and one in the head.  The holes appear to be purposefully drilled, rather then a random type of damage.  Looking closely, you think they might even have been designed for something to fit within them, making you wonder what that could possibly be.%^RESET%^


AVATAR
	);
	set("read",
@AVATAR



%^BOLD%^%^CYAN%^         .
%^BOLD%^%^CYAN%^       \ | /
%^BOLD%^%^CYAN%^     '-%^WHITE%^.;;;.%^CYAN%^-'
%^BOLD%^%^CYAN%^    -==%^WHITE%^;;;;;%^CYAN%^==-
%^BOLD%^%^CYAN%^     .-%^WHITE%^';;;'%^CYAN%^-.
%^BOLD%^%^CYAN%^       / | \
%^BOLD%^%^CYAN%^         '
%^RESET%^


(This symbol appears on the base of the statue.)



AVATAR
	);
     set("langage","common");	set_weight(5);
	set_value(500);
	set_lore(
@AVATAR
What little references you can locate speak of an ancient civilization that followed the Lady of the Moon and studied the celestial objects.  The civilization is said to have been destroyed in a great flood and all traces but a few small artifacts, such as this one, have been lost.

AVATAR
	);
	set_property("lore difficulty",22);
}