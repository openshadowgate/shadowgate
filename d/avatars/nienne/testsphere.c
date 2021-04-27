#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("sphere");
   set_id(({"dull sphere","crystal sphere","sphere","crystalline sphere","dull crystalline sphere"}));
   set_short("%^RESET%^%^RED%^a dull crystalline sphere%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^%^This small sphere is perfectly shaped, with an absolutely%^RESET%^%^CYAN%^ "
"flawless %^BLACK%^%^BOLD%^surface.  It is made up of some unknown crystalline substance with a perfectly "
"%^RESET%^%^WHITE%^translucent %^BLACK%^%^BOLD%^interior, that glows with faint hints of %^RESET%^%^RED%^pale "
"crimson%^BLACK%^%^BOLD%^.  Oddly enough, instead of catching and reflecting light as most crystals do, it "
"seems to %^RESET%^%^BLUE%^absorb %^BLACK%^%^BOLD%^any light that touches its surface.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This is Nienne's test object!  Don't eat it!%^RESET%^");
   set_property("lore difficulty",5);
   set_weight(0);
   set_value(0);
   set_property("no steal",1);
   set_property("no offer",1);
   set_property("no animate",1);
}

int drop(){ return 1;}
