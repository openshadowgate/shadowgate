#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("tree");
   set_id(({"tree","oak tree","dead tree","dead oak tree"}));
   set_short("%^RESET%^%^ORANGE%^A %^BOLD%^%^BLACK%^dead %^RESET%^%^ORANGE%^oak tree%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This oak tree is "
"%^BOLD%^%^BLACK%^dead%^RESET%^%^ORANGE%^. It is withered and bare of any "
"leaves. Even its roots are shriveled and the dirt around the tree "
"implies that whatever killed the tree happened rather recently, much "
"quicker than the time normally expected of a dying tree. It is almost as "
"if the %^CYAN%^life %^ORANGE%^had been sucked out of it. However, the "
"real disturbing nature lies within the branches of the tree. Scattered "
"among the various skinny branches are %^RED%^human body parts%^ORANGE%^. "
"A hand here, an arm there, it is horrific. Atop the highest branch, "
"there is a head showing a face of complete %^MAGENTA%^agony%^ORANGE%^. "
"From there, now dry, the flow of %^BOLD%^%^RED%^blood "
"%^RESET%^%^ORANGE%^can be seen falling all the way down the trunk of "
"tree.\n\n%^RESET%^%^GREEN%^At the bottom of the tree, words are written "
"%^BOLD%^'And so is the fate of all those who cross the Dark "
"Lord.'%^RESET%^\n");
   set_weight(99999);
   set_value(0);
}
