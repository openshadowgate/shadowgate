#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("azure diamond");
	set_id(({ "diamond", "crystal", "gem", "azure diamond", "azure crystal", "azure gem" }));
	set_short("%^YELLOW%^Glowing %^CYAN%^Azure Diamond%^RESET%^");
	set_obvious_short("%^CYAN%^glowing azure diamond%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This diamond is a %^YELLOW%^brilliant%^RESET%^%^CYAN%^ azure.  It is completely translucent and continually glows a darker %^RESET%^%^BLUE%^blue%^RESET%^%^CYAN%^.  Perhaps the most bizarre oddity of this diamond though, is it's shape, it is in the form of a perfect %^RED%^octagon%^CYAN%^.  On top of it's odd shape, is it's small size, it would easily fit into the hands of an infant.  This diamond doesn't look like it would have much value, unless one was a collector of rare gems.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^CYAN%^Great peril shall befall the one who possesses the Azure Blade... you have been warned mortal...%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(25);
	set_lore(
@AVATAR
%^CYAN%^Legends say that in order for the Azure Dragon to protect his keep after his spirit diminished, he erected a warrior who would wield the dreaded Azure Blade.  In time, the dreaded Lich Zar sieged the keep with mighty magics and after an intense battle which almost destroyed him, defeated the warrior who wielded the dreaded azure blade.  With the last of his energy he wove a message upon the crystal and hurled it into the prime material plane, killing himself and destroying the keep.  

%^CYAN%^Centuries later a demon imp was forced to reveal it's location to a probing mage who eventually retrieved it, in an attempt to forge the azure blade.  His attempt went horribly wrong and he was destroyed during the process, his soul sent to eternal torment...  

%^CYAN%^The last of the known possesors of the diamond mysteriously died, after what witnesses say was a battle like no other, that shook the very world...  %^RESET%^

AVATAR
	);
}