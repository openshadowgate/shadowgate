#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed animal pig");
	set_id(({ "pig", "stuffed toy", "stuffed animal", "stuffed pig toy", "stuffed animal pig", "piggy", "pigglet" }));
	set_short("%^BOLD%^%^WHITE%^a stuffed %^MAGENTA%^piggy%^WHITE%^ toy%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a stuffed %^MAGENTA%^piggy%^WHITE%^ toy%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Made from soft velvet material dyed a %^MAGENTA%^bright pink %^WHITE%^color, this little stuffed animal is in the shaped like a cute little %^MAGENTA%^pigglet%^WHITE%^.  Standing on all fours, this porky little guy is filled to bursting with cotton padding that makes him look roly-poly.  A curly little corkscrew tail made of stiffened %^MAGENTA%^pink yarn %^WHITE%^juts from his rear end while two lopsided triangles of %^MAGENTA%^pink felt %^WHITE%^extend from the top of his head.  %^BLACK%^Black buttons %^WHITE%^have been used for eyes and nose, while %^RED%^red yarn %^WHITE%^has been used to fashion his mouth.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(400);
}