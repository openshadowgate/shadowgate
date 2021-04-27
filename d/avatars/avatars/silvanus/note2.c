#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("note");
	set_id(({ "note", " piece of paper", " parchment", " letter" }));
	set_short("note");
	set_obvious_short("note");
	set_long(
@AVATAR
%^YELLOW%^A quick glance over this note reveals that it was apparently written in haste, as it is very hard to make out.  It may be possible to %^RED%^read%^RESET%^%^YELLOW%^ though.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BLUE%^You struggle for a few minutes and finally with a bit of effort you manage to make out the following written on the piece of paper...%^RESET%^

%^YELLOW%^Sir,
%^YELLOW%^If you are Korath Carendore, son of the late Jerimiah Carendore, I am in urgent need to speak with you.  It is of utter importance and in regards to your family.
%^YELLOW%^You can locate me in the northern part of the city of daggerdale and I will be returning to shadow whenever possible to check in and see if Hettman has heard from you or if I can find you,
%^YELLOW%^Lezure Alcorin%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(1);
}