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
%^YELLOW%^Dear Zellion,

%^YELLOW%^I do hope the information I provided you those days ago was helpful.  It has been some time since our last communication, I am glad you are still in good health.  I do hope that my research shall eventually yield information that maybe used to help with your castle, in the meantime my dear friend, do not give up and do let me know if one of the others come up with something.

%^YELLOW%^I am not suprised that you acquire information about the elfshine.  I was told beforehand that one would seek it, I just did not know it would be from you.  I have information and requests that you shall need to pass along to the one who seeks the information about elfshine.

%^YELLOW%^The one, Mithras who you have said, I shall hold accountable for the information, if it becomes widely known I shall hold him accountable.  I wish for him to know that I know the truth behind elfshine, it's creator has told me the truth, those years ago I was told the truth, because of my intentions.
%^RESET%^

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(10);
}