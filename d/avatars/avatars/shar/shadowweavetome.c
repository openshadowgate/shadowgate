#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("a black libram");
	set_id(({ "book", "tome", "libram" }));
	set_short("%^BOLD%^%^BLACK%^Rudiments of the Shadow Weave%^RESET%^");
	set_obvious_short("A black leather libram");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Wraped in black leather, the front of this tome features an embossed image of small circle's across it's surface.  The book seems to have been padded giving the raised circles a squishy feeling.  Blackened iron reinforcements helps to add durability to the tome.  The craftsmanship looks very old and ancient, nothing that has been seen in the last hundred years.  A piece of jet forms the clasp that holds this book closed.  With the clasp open all that one can make out is countless pages in black, with nothing written on them.

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_lore(
@AVATAR
The Rudements of Shadow Weave is a libram written by a cabal of wizards dedicated to Shar.  Within the pages of this book one will be able to learn how to gain access to the shadow weave, if they can figure out how to allow the text to appear

AVATAR
	);
}