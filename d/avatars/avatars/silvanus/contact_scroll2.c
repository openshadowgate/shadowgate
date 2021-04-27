#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("scroll");
	set_id(({ "scroll", "rolled up scroll" }));
	set_short("%^YELLOW%^plain scroll%^RESET%^");
	set_obvious_short("%^YELLOW%^plain scroll%^RESET%^");
	set_long(
@AVATAR
%^YELLOW%^This scroll is rolled up and upon inspection it is easy to discern it has some type of beautiful and unique writing upon it's surface.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^YELLOW%^That truth is not what others believe it to be, but that shall come later.  The information must never get further than this mithras and the one he wishes to help with the sword, if so, it must only be in part.  If that condition can be agreed upon, then I wish three things for the information. Those things are this, a key which has the ability to open a rift in reality
a red gem, which contains a unique power of its own
and an azure diamond, the most rare diamond that exist, it's existence long forgotten and it's location carefully hidden.  I have been told that the one who seeks knowledge of elfshine shall know of its location.

%^YELLOW%^If this is not possible, then my business with Mithras is at an end.  If we are in agreement, then when these items are located and in my possession, I shall provide the information.  I shall provide the accurate and complete truth behind elfshine.  

%^BLUE%^      Ikalian Dolsy%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(10);
	set_lore(
@AVATAR
l
s

AVATAR
	);
}