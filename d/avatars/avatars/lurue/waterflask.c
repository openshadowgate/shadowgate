#include <std.h>
inherit ARMOUR;

void create() {
	::create();
	set_name("glassteel flask");
	set_short("%^RESET%^%^CYAN%^G%^MAGENTA%^l%^WHITE%^as%^CYAN%^s %^WHITE%^o%^MAGENTA%^f %^WHITE%^t%^CYAN%^h%^WHITE%^e %^CYAN%^E%^MAGENTA%^n%^WHITE%^dle%^CYAN%^s%^WHITE%^s W%^CYAN%^a%^MAGENTA%^t%^WHITE%^er%^CYAN%^s%^RESET%^");
      set_obvious_short("%^RESET%^%^CYAN%^glassteel flask%^RESET%^");
	set_id(({"flask","container","glassteel flask","flask of the endless waters"}));
	set_long("%^RESET%^This %^CYAN%^glassteel %^RESET%^container is perfectly shaped to fit comfortably in "
"the palm of one's hand with its spout extending beyond the curled fingers. Formed from a pair of concave ovals"
", the %^CYAN%^glass %^RESET%^has been crafted with an %^CYAN%^i%^MAGENTA%^n%^WHITE%^tri%^CYAN%^c%^MAGENTA%^a"
"%^WHITE%^te %^CYAN%^d%^MAGENTA%^e%^WHITE%^si%^CYAN%^g%^WHITE%^n that is formed from metal itself, rather then "
"etched onto the surface. On one side of the flask an %^ORANGE%^old man %^RESET%^sits with his back against a "
"mature %^BOLD%^%^MAGENTA%^c%^RESET%^he%^BOLD%^%^MAGENTA%^r%^RESET%^ry t%^BOLD%^%^MAGENTA%^r%^RESET%^ee flush "
"with blooms. While the other side features a %^MAGENTA%^young child %^RESET%^standing on tip toe admiring the "
"first %^MAGENTA%^%^BOLD%^b%^RESET%^los%^BOLD%^%^MAGENTA%^s%^RESET%^om of a young sapling. The smooth ridges "
"of the design blur at the edges, fading away into the curve of the container with liquid precision, giving "
"them an %^ORANGE%^aged %^RESET%^appearance though the flask itself seems new. At the top, a %^BOLD%^%^WHITE%^"
"silver cap %^RESET%^adorned with a rounded bead of %^BOLD%^%^MAGENTA%^rose quartz%^RESET%^ affixes to the "
"spout, keeping the faintly %^BOLD%^%^MAGENTA%^t%^RESET%^ing%^BOLD%^%^MAGENTA%^e%^RESET%^d liquid secure "
"inside.%^RESET%^");
      set_lore("Ordered by Stanshar of the Seneca Restaurant, this flask was enchanted to hold an endless "
"supply of whatever liquid was first placed within it. A liquid which would be determined at the behest of the "
"one who would carry it. As a gift for the winner of the Adventurous Summer Contest, Stanshar had the flask "
"designed in remembrance of the story told by Kazi Sonnu who took the Honorable Mention prize with his "
"retelling of an ancient parable from his homelands.");
      set_property("lore difficulty",10);
	set_value(5000);
      set_weight(3);
      set_type("ring");
      set_limbs(({"waist"}));
      set_ac(0);
      set_wear("You slip the flask securely into a loop of your belt.");
}

void init() {
	::init();
	add_action("drink","drink");
}

void drink(string str) {
	if(!living(ETO)) {
		notify_fail("You must be holding the flask to be able to drink from it.\n");
		return 0;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the flask to be able to drink from it.\n");
		return 0;
	}
	if(str == "from flask") {
		if(!ETO->add_quenched(20)) {
			notify_fail("Your stomach is sloshing already!\n");
			return 0;
		}
		tell_object(ETO,"%^RESET%^You unscrew the cap and lift the %^CYAN%^f%^MAGENTA%^l%^WHITE%^a%^CYAN%^s"
"%^WHITE%^k to your lips, taking a long cool drink of the pure %^BOLD%^%^CYAN%^s%^BLUE%^p%^RESET%^ri%^BOLD%^"
"%^CYAN%^n%^RESET%^g w%^BOLD%^%^BLUE%^a%^RESET%^t%^CYAN%^e%^RESET%^r tinged with the faintest hint of %^BOLD%^"
"%^MAGENTA%^c%^RESET%^he%^BOLD%^%^MAGENTA%^r%^RESET%^ry %^MAGENTA%^%^BOLD%^b%^RESET%^los%^BOLD%^%^MAGENTA%^s"
"%^RESET%^oms.%^RESET%^");
		tell_room(EETO,""+ETOQCN+" takes a drink from "+ETO->QP+" flask.",ETO);
		ETO->add_quenched(20);
		return 1;
	}
}

int isMagic(){ return 1; }