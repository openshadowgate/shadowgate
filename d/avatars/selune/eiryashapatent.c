#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("folio");
	set_id(({ "patent", "patent of nobility", "folio" }));
	set_short("%^BOLD%^%^RED%^Patent of Nobility%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^Patent of Nobility%^RESET%^");
	set_long(
@AVATAR
This folio is a single sheet of large %^YELLOW%^parchment%^RESET%^ folded in four and sealed in a thick glossy %^BOLD%^%^RED%^wax%^RESET%^ that adds a %^BOLD%^%^BLACK%^gray%^RESET%^ hue to document. The pages created from the folds stand thirty eight centimeters tall, the edges gilded in a %^BOLD%^silver%^RESET%^ sealing. The front cover bears large flowing lettering that %^RED%^s%^BLUE%^p%^CYAN%^a%^YELLOW%^r%^GREEN%^k%^MAGENTA%^l%^BOLD%^e%^RESET%^ as if %^BOLD%^diamonds%^RESET%^ were mixed into the ink. The lettering cleary reads, %^BLUE%^"Lady Eiryasha Shdednei, Knight of %^CYAN%^Auril."%^RESET%^ Beneathe the name frost imprints the wax in the shape of luscious %^BOLD%^%^RED%^lips%^RESET%^, too large for any human to bear. Upon the back lies a seal of %^BOLD%^silver%^RESET%^ foil, the symbol of House Shdednei: An %^BLUE%^tear drop%^RESET%^ centered, a double tailed %^BOLD%^%^BLACK%^panther%^RESET%^ with raised head resting upon a line just above the %^BLUE%^tear drop%^RESET%^. Within the folio reading the document clearly states the woman's patent of nobility, as well as rights to the lands of Nereis.

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^CYAN%^Lady Eiryasha Shdednei, born the 21st of Autumnstime within the year six-hundred fourteen is fully afforded the rights of a woman of noble standing. By blood of the father Baldwir Shdednei and the mother Callendieria Shdednei her station is secured. Upon her brow falls the duty of the Barony of Nereis, to those people she holds the Noblisse Oblige. To her mouth rests the Seat of House Shdednei, her words bring honor to house and family. The blessings of Knighthood fall upon her houlders, may her hands deliver Justice and Order in the name of Auril.%^RESET%^ 

Sealed in faith and honor the twenty third of Colddays within the year six-hundred thirty, Talox III, Reaper of the Northlands, Templar-General of the Order of Algid Wrath.

AVATAR
	);
     set("langage","common");	set_weight(1);
	set_value(0);
}