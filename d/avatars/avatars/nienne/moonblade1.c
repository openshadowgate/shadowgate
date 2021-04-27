#include <std.h>
inherit "/d/common/obj/weapon/rapier.c";

void create(){
   ::create();
   set_name("mithril rapier");
   set_id(({"rapier","mithril rapier","blade","ornate rapier","kintiar evaliir","alu'evaliir","Alu'evaliir","song of the oceans","Song of the Oceans"}));
   set_short("%^BOLD%^%^WHITE%^A%^YELLOW%^lu %^WHITE%^E%^YELLOW%^va%^WHITE%^l%^YELLOW%^ii%^WHITE%^r - %^BOLD%^%^BLUE%^S%^WHITE%^o%^CYAN%^n%^BLUE%^g of t%^CYAN%^h%^BLUE%^e O%^RESET%^%^BLUE%^ce%^CYAN%^a%^BOLD%^%^BLUE%^ns%^RESET%^");
   set_obvious_short("%^RESET%^a %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^rapier with an %^BOLD%^%^BLUE%^or%^CYAN%^na%^BLUE%^te %^RESET%^swept hilt");
   set_long("This weapon is known as a rapier, characterised by the long and "
"narrow blade and its complex, protective hilt.  The blade itself is made of "
"%^BOLD%^%^WHITE%^gle%^CYAN%^a%^WHITE%^ming mith%^CYAN%^r%^WHITE%^il%^RESET%^, "
"barely broad enough to cut, and only sharpened from the midpoint to the tip, "
"leaving its true potency in thrusting attacks.  However, the portion of the "
"weapon that has been sharpened, has been done so to a %^BOLD%^%^BLACK%^ra"
"%^WHITE%^z%^YELLOW%^o%^BLACK%^r's edge%^RESET%^.  A series of %^GREEN%^e"
"%^BOLD%^l%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^n %^BOLD%^r%^RESET%^"
"%^GREEN%^u%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^thread their way down "
"the slender blade to the %^BOLD%^%^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^n"
"%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^d crosspiece, decorated along its length "
"with receding %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^rings that "
"finish in a small knob on either side.  This meets with the thick pommel of "
"the weapon, finished with a similar style of rings to form a %^ORANGE%^"
"comfortable grip %^RESET%^for the wielder, and finished in an identical knob "
"of %^BOLD%^%^WHITE%^pol%^CYAN%^i%^WHITE%^shed mith%^CYAN%^r%^WHITE%^il%^RESET%^"
".  Around this sweeps a contour of shining metal strands like a %^BOLD%^"
"%^BLUE%^ri%^CYAN%^si%^BLUE%^ng w%^WHITE%^a%^BLUE%^ve %^RESET%^of the ocean, "
"swirling in a decorative arc that actually serves as a sturdy guard.  It flows "
"down over the crosspiece and ricasso in ornate fashion, and back across the "
"hilt to protect the wielder's hand. The entire effect is given of a "
"masterworked weapon of unparalleled craftsmanship, light and elegant but "
"potentially %^RED%^da%^MAGENTA%^ng%^RED%^e%^MAGENTA%^ro%^RED%^us %^RESET%^in "
"the hands of an experienced user.\n");
   set_value(23200);
   set_property("enchantment",5);
}
