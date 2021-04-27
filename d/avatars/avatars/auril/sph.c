#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("sphere");
	set_id(({ "sphere" }));
	set_short("%^BOLD%^%^CYAN%^A crys%^BOLD%^%^WHITE%^tal %^BOLD%^%^GREEN%^sphere%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^A crys%^BOLD%^%^WHITE%^tal %^BOLD%^%^GREEN%^sphere%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This sphere seems to have captured an image. In a %^BOLD%^%^BLACK%^dark %^BOLD%^%^WHITE%^room there is a massive %^RESET%^%^ORANGE%^table %^BOLD%^%^WHITE%^with a half-elven male strapped to it. The male is missing on %^BOLD%^%^BLUE%^eye %^BOLD%^%^WHITE%^and is screaming, his back arched. He is missing his left hand and his torso has been opened up, his %^BOLD%^%^MAGENTA%^entrails %^BOLD%^%^WHITE%^showing. All around him %^BOLD%^%^RED%^fire %^BOLD%^%^WHITE%^licks up. And the walls are covered with %^BOLD%^%^YELLOW%^numerous %^BOLD%^%^RED%^torture %^BOLD%^%^WHITE%^devices. You see a single %^BOLD%^%^CYAN%^tear %^BOLD%^%^WHITE%^rolling down his sheek and utter anguish on his face. Hovered over him is a %^RESET%^white-haired %^BOLD%^%^BLACK%^drow elf %^BOLD%^%^WHITE%^who is cutting him carefully with a knife.

AVATAR
	);
	set_weight(1);
	set_value(0);
}