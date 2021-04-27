#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("devilish longsword");
	set_id(({ "sword", "devilish longsword", "longsword", "long sword", "devilishly wicked longsword", "Asmordian's Eye" }));
	set_short("%^BOLD%^%^RED%^A%^YELLOW%^s%^RESET%^%^RED%^m%^WHITE%^o%^ORANGE%^r%^BOLD%^%^RED%^d%^RESET%^%^RED%^i%^YELLOW%^a%^RED%^n%^RESET%^%^WHITE%^'%^RED%^%^BOLD%^s E%^RESET%^%^ORANGE%^y%^BOLD%^%^RED%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^a devilishly wicked looking longsword%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This %^BLACK%^s%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^BLACK%^ery%^WHITE%^ blade is a gorgeous example of craftsmanship and design.  The blade is nearly six-feet long and tapers from the wide base down to a %^RED%^wickedly %^WHITE%^sharp point.  The entire length of which is covered in ornate %^YELLOW%^scrollwork %^WHITE%^and ever moving %^RED%^pictograms%^WHITE%^.  The gilded hilt is designed as twin %^BLACK%^h%^WHITE%^o%^RESET%^r%^BOLD%^%^WHITE%^n%^BLACK%^s %^WHITE%^that curl outward from the %^RESET%^ivory grip%^BOLD%^%^WHITE%^, their tapered tips pointed toward the middle of the blade, almost touching the razor like edge.  Each spiraled curve of the horns is edged in ancient glyphs that pulsates with a constant, deep %^RESET%^%^RED%^burgundy %^BOLD%^%^WHITE%^glow, one which ignites the blade's silver with a dark %^RED%^ruby aura%^WHITE%^.  Upon the pommel, two half-moon %^RED%^f%^YELLOW%^i%^RESET%^%^ORANGE%^r%^RED%^e %^BOLD%^o%^YELLOW%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^RED%^l%^RESET%^%^RED%^s %^BOLD%^%^WHITE%^have been set around a diamond shaped piece of %^BLACK%^onyx%^WHITE%^, the effect of which creates an ever gazing %^RED%^eye%^WHITE%^, one that you swear blinked just as you looked away.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR


%^BOLD%^%^RED%^Let the darkness unleash the soul that does reach,
%^BOLD%^%^RED%^a thousand times the innocent's blood shed.%^RESET%^



AVATAR
	);
     set("langage","common");	set_weight(10);
	set_value(30000);
	set_lore(
@AVATAR
%^RED%^From an ancient journal recently unearthed: %^BLACK%^%^BOLD%^I do not know if it is true or not, whether this weapon is truly the forged remains of the dark lord or not.  If it is, then it is my sacred duty to carry it to the temple of the fallen and lay it there for He to raise.  If such a creature can be raised.  How this could have happened, I do not know.  I can only recount what I witnessed.  One moment, our Lord stood proud and strong, his dark spells glowing ruby around him.  His powers arcing between razor sharp claws.  The skin mantle which he had forged from the hides of a thousand innocents all screaming out in the ready, and then the brilliant cloying cloud of silver light rose like mist from the earth and surrounded us all.  I heard screaming and sounds of terror all about me.  And I, found myself caught in the grasp of a most horrid nightmare.  And when the mists lifted and our terrors abated, all that lay upon the earth where our Lord once stood was this silvered blade.  A blade, whose crystalline eye and curled horns, reminds me of our Lord and his ever watchful presence.  I fear what has done this, and I fear what will come of me to carry such an artifact.  %^RESET%^

AVATAR
	);
	set_property("lore difficulty",30);
	set_type("slashing");
	set_prof_type("medium blades");
	set_size(2);
	set_wc(1,8);
	set_large_wc(1,10);
	set_property("enchantment",4);
	set_wield((:TO,"wield_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Your mind is gripped with a powerful urge, a presence that demands your servitude and surrender.  Bow before it and become stronger, fight it and your soul shall be as rended as your flesh.%^RESET%^");
	return 1;
}

