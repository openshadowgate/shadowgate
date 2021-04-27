#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
	::create();
	set_name("Motley of Fools");
	set_id(({ "motley of fools", "leather armor", "studded leather armor", "strange armor", "strange leather armor" }));
	set_short("%^BOLD%^%^CYAN%^M%^WHITE%^o%^BLACK%^t%^RESET%^%^CYAN%^l%^BOLD%^ey %^RESET%^of %^BOLD%^%^CYAN%^F%^RESET%^oo%^CYAN%^ls%^RESET%^");
	set_obvious_short("%^CYAN%^l%^RESET%^e%^BOLD%^a%^CYAN%^t%^RESET%^h%^CYAN%^e%^WHITE%^r %^BOLD%^armor %^RESET%^%^CYAN%^with a strange %^BOLD%^fluffed collar%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^The leather of this armor is very pale, almost white. The maker intended for this piece to be showy in nature. The collar itself is layer after layer of %^BLUE%^blue %^WHITE%^and s%^B"
	"LACK%^i%^RESET%^l%^BOLD%^ver m%^CYAN%^e%^WHITE%^sh and is designed in much the way as some jesters wear it. Down its front %^BLACK%^dark roses %^WHITE%^have been burnt into the leather, tangling to a "
	"stop around a %^RESET%^%^CYAN%^flute charm %^BOLD%^%^WHITE%^that has been added at the midriff. The back of the armor is decorated in panels of %^CYAN%^sky blue %^WHITE%^and %^BLUE%^s%^RESET%^%^BLUE%^"
	"a%^BOLD%^pp%^RESET%^%^BLUE%^hi%^BOLD%^re %^RESET%^%^BLUE%^leather. %^BOLD%^%^WHITE%^Between each of the panels are %^YELLOW%^charms %^WHITE%^of a musical nature that jingle as the wearer moves. While "
	"it does not at first appear very protective, closer inspection reveals it to be very well made.%^RESET%^
"	);
	set_value(20000);
	set_lore("%^CYAN%^Crafted by a true master of his field, Arnold Pelldum was asked to custom make a gift for a friend of the Duke of Tharis in the year 607. It is said the gift was for one of his favored guests "
	"and entertainers, Filantra Lockeheart. The only real proof of that were her lengthy stays at the Duke's special events.
"	);
	set_property("lore difficulty",20);
	set_item_bonus("magic resistance",2);
	set_size(2);
	set_property("enchantment",6);
}



