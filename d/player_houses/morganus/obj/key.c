#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("blue key");
   set_id(({"key","blue key","morg key"}));
   set_short("%^BOLD%^%^CYAN%^a blue key%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^This blue key has a finely engraved 'O' with the letter 'M' in it.%^RESET%^\n");
   set_weight(1);
   set_value(0);
}
