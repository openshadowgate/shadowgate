#include <std.h>
inherit "/d/common/obj/armour/chain";

void create(){
	::create();
	set_name("bubbles");
	set_id(({ "chain", "chain mail", "mail" }));
	set_short("pro chain mail");
	set_obvious_short("Pro Leet Chainmailz0r");
	set_long("This is an awesome desc, we're checking it for truncation. This is an awesome desc, we're checking it for truncation. This is an awesome desc, we're checking it for truncation. This is an awesome desc"
	", we're checking it for truncation. This is an awesome desc, we're checking it for truncation. This is an awesome desc, we're checking it for truncation. This is an awesome desc, we're checking it for"
	" truncation. This is an awesome desc, we're checking it for truncation. This is an awesome desc, we're checking it for truncation. This is an awesome desc, we're checking it for truncation.
"
	);
	set_value(3);
	set_lore("This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore"
	", we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for"
	" truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an"
	" awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation. This is an awesome lore, we're checking it for truncation.
"
	);
    set_property("lore difficulty",23);
}
