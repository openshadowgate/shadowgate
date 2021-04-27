#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^A severed head of a female elf on a %^BOLD%^%^WHITE%^silver platter%^RESET%^");
	set_id(({ "head", "elf head", "platter", "silver platter", "eliana's head" }));
	set_short("%^RESET%^%^RED%^A severed head of a female elf on a %^BOLD%^%^WHITE%^silver platter%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A severed head of a female elf on a %^BOLD%^%^WHITE%^silver platter%^RESET%^");
	set_long(
@AVATAR
%^RESET%^This %^RESET%^%^RED%^head %^RESET%^is a %^BOLD%^%^GREEN%^ghastly %^RESET%^sight indeed.  It is obviously that of a middle-aged, beautiful %^BOLD%^%^MAGENTA%^female %^RESET%^%^GREEN%^elf %^RESET%^with %^BOLD%^%^RED%^blood red hair %^RESET%^and %^GREEN%^deep emerald eyes%^RESET%^.  Oddly enough, a cruel, sarcastic %^BLUE%^smirk %^RESET%^plays upon her lips, as if she reviled those that killed her.  It appears the head was severed %^BOLD%^%^BLACK%^post mortem %^RESET%^by one swipe of an obviously sharp blade.  From the condition of the skin, it appears that this person has been dead for about a week, though some %^BOLD%^%^WHITE%^chemicals %^RESET%^have obviously been used to preserve it.  Much like the cliche, this head sits atop a %^BOLD%^%^WHITE%^silver platter %^RESET%^of highest quality.  Its obvious that whoever had this elf killed wanted to make a show of things.

AVATAR
	);
	set_weight(5);
	set_value(0);
}