#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wagon");
	set_id(({ "wagon" }));
	set_short("A collapsed wagon");
	set_obvious_short("A collapsed wagon");
	set_long(
@AVATAR
This is a large wooden wagon. It has obviously been destroyed by someone. Burn marks are all about it and three bodies are strewn about, quite dead. There is a note stuck in a crack near the edge, somehow surviving the attack. 

"Hint: read wagon"

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^RED%^Dear Jones,

%^BOLD%^%^RED%^I am going to get this shipment to you as soon as possible. I know that the contents of this chest are incredibly valuable, so take kindly that it is handled with care. The power is unmeasurable. Lord Welkanar's robe was found, we hear, and perhaps he may be involved some how. Be wary of all you can. 

Forrin

AVATAR
	);
     set("langage","str");	set_weight(500);
	set_value(0);
}