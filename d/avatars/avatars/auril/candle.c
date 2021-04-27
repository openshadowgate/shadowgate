#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("candle");
	set_id(({ "candlestick" }));
	set_short("An ornate candlestick");
	set_obvious_short("%^BOLD%^%^YELLOW%^Holy Candlestick%^RESET%^");
	set_long(
@AVATAR
This beautifully crafted candlestick has the holy symbol of %^BOLD%^%^YELLOW%^Tyr %^RESET%^enscribed on its side. It is adorned with numerous %^BOLD%^%^RED%^jewels%^RESET%^.

AVATAR
	);
	set_weight(5);
	set_value(5000);
}