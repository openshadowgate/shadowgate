#include <std.h>

inherit OBJECT;

void create()
{
  ::create();
  set_long("%^RED%^A severed %^BOLD%^%^WHITE%^un%^YELLOW%^i%^WHITE%^corn%^RESET%^%^RED%^ head has been impaled on top of a simple %^ORANGE%^wooden dummy%^RED%^. The head has been horribly disfigured. The skin has been stretched and then pierced with pieces of wood, to give the face an expression resembling a wicked grin. Instead of eyes, there are two eye-sized gems %^BOLD%^%^RED%^rammed%^RESET%^%^MAGENTA%^ v%^RED%^i%^MAGENTA%^olently %^RED%^into the eyesockets%^RESET%^%^RED%^ - one %^GREEN%^em%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^rald %^RED%^and one %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by%^RESET%^%^RED%^. A %^ORANGE%^rat%^RED%^ is impaled on the blood-covered %^BOLD%^%^YELLOW%^h%^WHITE%^o%^YELLOW%^rn%^RESET%^%^RED%^. The dummy is garbed in what looks like unicorn hide, but it has been poorly skinned and all %^BOLD%^bloody %^RESET%^%^RED%^and messy.%^RESET%^");
  set_short("%^RESET%^%^BOLD%^%^BLACK%^a %^RED%^horrible looking%^RESET%^%^RED%^ scarecrow%^RESET%^");
  set_value(4);
  set_id(({"scarecrow","dummy","horrible looking scarecrow", "horrible scarecrow"}));
  set_name("horrible scarecrow");
  set_weight(15);
}
