#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("skullofamidor");
	set_id(({ "skull" }));
	set_short("%^BOLD%^%^WHITE%^S%^BLACK%^k%^WHITE%^u%^BLACK%^l%^WHITE%^l %^BLACK%^o%^WHITE%^f %^BLACK%^A%^WHITE%^m%^BLACK%^i%^WHITE%^d%^BLACK%^o%^WHITE%^r%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a dwarvish skull%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This skull is smaller than that of a human.  It has several cracks around the top and appears to be severly worn and weathered.  Oddly, from within the sockets that once held the poor"
	" souls eyes, a dim light gathers glowing a faint %^BLUE%^blue%^WHITE%^.%^RESET%^
"
	);
	set_value(0);
	set_weight(4);
	set_lore("%^BOLD%^.oO %^CYAN%^'Hmm, this reminds me of a bards limrick.' %^WHITE%^Oo.%^RESET%^

     %^BOLD%^%^WHITE%^'%^MAGENTA%^Adventurers o%^WHITE%^'%^MAGENTA%^ plenty %^WHITE%^'%^MAGENTA%^ave risked it all"
	"%^WHITE%^'
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Many with success yet many more fall%^WHITE%^'
     %^BOLD%^%^WHITE%^'%^YELLOW%^%^Gold %^MAGENTA%^and %^RESET%^%^CYAN%^j%^BOLD%^%^BLUE%^e%^WHITE%^w%^GREEN%"
	"^e%^RED%^l%^YELLOW%^s %^MAGENTA%^and treasures they find%^WHITE%^'
     %^BOLD%^%^WHITE%^'%^MAGENTA%^But one in particular springs into mind%^WHITE%^'

     %^BOLD%^%^WHITE%^'%^%^YELLOW%^%^Amidor %^MA"
	"GENTA%^the dwarf mighty in soul%^WHITE%^'
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Small in stature and large in goal%^WHITE%^'
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Wanted to live, %^BLACK%^rich and eternal%^WH"
	"ITE%^'
     %^BOLD%^%^WHITE%^'%^MAGENTA%^The first a chore, the last a hurdle%^WHITE%^'                                                                             

     %^BOLD%^%^WHITE%^'%^MAGENTA%^"
	"He went to a %^RESET%^%^RED%^witch %^BOLD%^%^MAGENTA%^and asked her for life%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^She granted his wish, but gave him strife%^WHITE%^'%^MAGENTA%^
     "
	"%^BOLD%^%^WHITE%^'%^MAGENTA%^Her hatred for dwarves was little known%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^But hate them she did, right to the %^WHITE%^bone%^WHITE%^'%^MAGENTA%^

    "
	" %^BOLD%^%^WHITE%^'%^MAGENTA%^Embued in his %^WHITE%^bones%^MAGENTA%^, ability to %^YELLOW%^heal%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Anyone but him, a very bad deal%^WHITE%^'%^MAGEN"
	"TA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Happy he was with his magical gift%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Thinking he now had power, his body to lift%^WHITE%^'%^MAGENTA%^

     "
	"%^BOLD%^%^WHITE%^'%^MAGENTA%^Confidence abound, the dwarf entered the lair%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Of mighty Klauth, as noone would dare%^WHITE%^'%^MAGENTA%^
     %^BOLD"
	"%^%^WHITE%^'%^MAGENTA%^Sure he was, if he fell he would raise%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^And once he did, so he offered a praise%^WHITE%^'%^MAGENTA%^

     %^BOLD%^%^WHITE%"
	"^'%^MAGENTA%^As the battle ensued, again he did fall%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^But this time the dwarf laid heaped and mauled%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%"
	"^MAGENTA%^Entered he did, with %^GREEN%^greed %^MAGENTA%^and pride%^WHITE%^'%^MAGENTA%^
     %^BOLD%^%^WHITE%^'%^MAGENTA%^Searching for treasures, %^YELLOW%^Amidor %^MAGENTA%^died%^WHITE%^'%^RESET%^
"
	);
    set_property("lore difficulty",15);
    set("chabonus",-1);
}
