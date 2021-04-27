#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("award ribbon");
	set_id(({ "award ribbon", "ribbon", "pin" }));
	set_short("%^RESET%^a %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^RESET%^%^GREEN%^r%^BOLD%^%^CYAN%^f%^BLUE%^u%^RESET%^%^MAGENTA%^l %^RESET%^award ribbon");
	set_obvious_short("%^RESET%^a %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^RESET%^%^GREEN%^r%^BOLD%^%^CYAN%^f%^BLUE%^u%^RESET%^%^MAGENTA%^l %^RESET%^award ribbon");
	set_long(
@AVATAR

%^RESET%^This slender piece of pressed %^CYAN%^steel %^RESET%^is formed into a radiant starburst with sixteen rays extending from a circular center.  Set into the middle of the disk is a piece of polished %^BOLD%^%^MAGENTA%^rose quartz %^RESET%^with words etched in a %^BOLD%^%^WHITE%^bold white script %^RESET%^proclaiming the wearer a winner of something.  On the back, a piece of thick %^ORANGE%^brown leather %^RESET%^has been applied to help protect the wear's clothing from the metal.  Through this leather, an %^BOLD%^%^WHITE%^ivory tipped stickpin%^RESET%^ has been attached which allows the disk to be hung on the wearer's lapel.  Several %^BOLD%^%^RED%^co%^RESET%^%^ORANGE%^lo%^YELLOW%^rf%^GREEN%^ul %^RESET%^%^GREEN%^r%^BOLD%^%^CYAN%^ib%^BLUE%^bo%^RESET%^%^MAGENTA%^ns %^RESET%^extend from the bottom and add a bit of pizzazz to the already fanciful award ribbon. %^RESET%^


AVATAR
	);
	set("read",
@AVATAR

%^BOLD%^%^WHITE%^         Spring is Blooming
%^BOLD%^%^WHITE%^Song, Story and Poetry Telling Contest
%^BOLD%^%^WHITE%^      Honorable Mention Winner!


AVATAR
	);
     set("langage","common");	set_weight(0);
	set_value(10);
	set_lore(
@AVATAR
This prize ribbon was awarded during the First Annual Spring is Blooming Contest during which dozens of storytellers, songwriters and poem crafters all gathered to bring forth tales of love, romance and devotion.

AVATAR
	);
	set_property("lore difficulty",10);
	set_type("ring");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",0);
}


