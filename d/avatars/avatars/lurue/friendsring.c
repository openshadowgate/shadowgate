#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silver ring");
	set_id(({ "ring", "friendship's light", "friendships light", "silver ring" }));
	set_short("%^BOLD%^%^WHITE%^Friendship's Light%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A silver band covered in etchings%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This silver band is very plain indeed, no fancy jewels, no special settings, just a plain silver band covered in dozens of tiny etchings.  The etching each seem to be of something different.  There are images of charms, flowers, roses, rings, balls of light and balls of darkness.  There are little bracelets and gemstones, a staff and shield covered in something. There is a lantern and a card, a couple sheets of paper and a tunic of sorts, and last is a little quill and aster blossom, all finely detailed into the surface.  Though there is no color what so ever, each etching seems vibrant in its own way.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^WHITE%^Friends are our joy and our light, and by being friends they bring us light and joy.%^RESET%^

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR

%^BOLD%^%^WHITE%^A token of friendship and the love that many felt for a single priestess, this ring is said to hold the essence of all that was given for the one who wears it.%^RESET%^


AVATAR
	);
	set_property("lore difficulty",0);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",0);
}


