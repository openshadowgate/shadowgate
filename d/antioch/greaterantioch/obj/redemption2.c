#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create(){
	int placeholder, *placeholder2;
	::create();
	set_property("creator","saradin");
	set_property("quality",29);
	set_name("%^BOLD%^%^YELLOW%^Red%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^mption%^RESET%^");
	set_id(({ "hammer", "large hammer", "redemption", "%^BOLD%^%^YELLOW%^Red%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^mption%^RESET%^" }));
	set_short("%^BOLD%^%^BLACK%^A %^BOLD%^%^CYAN%^rune-engraved %^BOLD%^%^WHITE%^titanium %^BOLD%^%^YELLOW%^large hammer%^RESET%^");
	set_long("%^RESET%^This beautifully %^BOLD%^%^CYAN%^rune-engraved %^RESET%^hammer is finely crafted, with a holy of symbol of %^BOLD%^%^YELLOW%^Lathander%^RESET%^ etch
ed in the side of the hammer head. One sid"
	"e of the head protrudes %^BOLD%^%^RED%^viciously %^RESET%^with a spike and the other is the flat surface of the hammer
. The face of the flat hammer has an etching on it, depicting a man alone, surrou"
	"nded by %^BOLD%^%^BLACK%^darkness %^RESET%^with a thin line of %^BOLD%^%^YELLOW%^light %^RESET%^creating a path ahead. The entire hammer is %^BOLD%^%^WHITE%^polished titanium %^RESET%^and has engravin"
	"gs along the entire length of the grip i
n the languages %^BOLD%^%^GREEN%^elven, %^BOLD%^%^BLUE%^common, and  %^BOLD%^%^BLACK%^drow%^RESET%^ with the inscription 'There is no forgiveness for the wicke"
	"d save that of His grace.'  

Mastercrafted"
	);
	set_lore("This hammer was created by the famous paladin, %^BOLD%^%^WHITE%^Sir Saradin Torvall%^RESET%^, soon after gaining the status of paladinship from the church of %^BOLD%^%^YELLOW%^Lathander%^RESET%^. Sir "
	"Saradin, after living the life of nearly fourty years as a %^BOLD%^%^RED%^villainous assassin-warlord %^RESET%^ who k
ililed thousands of innocents, gave up the life and all his wealth in search of 
r"
	"edemption. After fourty years of faithful service to%^BOLD%^%^YELLOW%^Lathander
 %^RESET%^, he was granted knighthood by the %^BOLD%^%^WHITE%^King of Antioch 
%^RESET%^for honorable service to the cro"
	"wn. Soon after, after having proved his faith to his god, Saradin Torvall became a full fledge paladin, seeking to aid others in changing from the %^BOLD%^%^BLACK%^darkness of the world %^RESET%^and b"
	"ack to the %^BOLD%^%^YELLOW%^light%^RESET%^.

"
	);
	set_property("lore difficulty",29);
}