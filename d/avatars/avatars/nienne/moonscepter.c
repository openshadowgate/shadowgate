#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("mithril scepter");
   set_id(({"scepter","mithril scepter","rod","rod of lunar radiance","ornate scepter","ornate mithril scepter"}));
   set_short("%^RESET%^%^CYAN%^Rod of %^BOLD%^%^WHITE%^L%^CYAN%^u%^WHITE%^nar Radi%^YELLOW%^a%^WHITE%^nce%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^an ornate %^BOLD%^%^WHITE%^mith%^CYAN%^r%^WHITE%^il %^RESET%^%^CYAN%^scepter%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A fine haft of %^WHITE%^sil%^RESET%^ve%^BOLD%^%^WHITE%^ry mi%^CYAN%^t%^WHITE%^"
"hril %^BLACK%^forms the basis of this scepter, perhaps half an inch thick and a little over a foot in length"
".  Along its length, fine scrollwork etches out an abstract swirling pattern, throughout which several "
"%^RESET%^%^GREEN%^r%^BOLD%^u%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s %^BOLD%^%^BLACK%^are interwoven"
".  At the base, four tines of %^WHITE%^mi%^CYAN%^t%^WHITE%^hril %^BLACK%^branch out from the main shaft to "
"form a small cage, within is supported a raw cut of %^RESET%^mi%^BOLD%^l%^RESET%^ky o%^CYAN%^p%^RESET%^al"
"%^BOLD%^%^BLACK%^, its pale color shot through with iridescent %^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^n"
"%^BLACK%^, %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n %^BLACK%^and %^CYAN%^a%^RESET%^"
"%^CYAN%^z%^BOLD%^ure %^BLACK%^pinfire.  Its edges remain jagged and unpolished, as though it has been set in "
"exactly the same shape as it had been found.  At the opposite end, forming the head of the scepter, several "
"%^WHITE%^mi%^CYAN%^t%^WHITE%^hril ridges %^BLACK%^encircle the shaft, moving upwards and outwards to form a "
"flat support base.  Upon this base rests a sizeable orb of %^BOLD%^%^WHITE%^gl%^YELLOW%^e%^WHITE%^aming "
"moons%^RESET%^to%^BOLD%^ne%^BLACK%^, clasped by a single metal claw that reaches up from the haft to secure "
"it in place.  The gemstone has been polished to perfection, revealing its distinct %^RESET%^%^CYAN%^bl"
"%^BOLD%^u%^RESET%^%^CYAN%^e cha%^BOLD%^t%^RESET%^%^CYAN%^oya%^BOLD%^n%^RESET%^%^CYAN%^cy %^BOLD%^%^BLACK%^"
"under light.  Considering the settings of these two stones, and the %^RESET%^%^MAGENTA%^o%^RED%^rn%^MAGENTA%^"
"at%^RED%^e %^BOLD%^%^BLACK%^patterning that marks the haft, you're sure this scepter must not have been "
"designed for combat.%^RESET%^");
   set_value(6800);
   set_lore("%^WHITE%^%^BOLD%^Many years ago, so the tales tell, a village existed on the outlying northern "
"borders of the Tsarven empire, near the city known as Azha.  The village, once peaceful, came under the "
"ravaging plague of an undead horde, and as one the villagers cried out for aid.  And aid came to them, "
"through the hands of a simple priest of Selune.  Alainn Daross was a young man, only recently arrived in the "
"village as a missionary, spreading the word of his Lady across the lands.  As night fell and the undead "
"descended upon the town, he cried out for the aid of the Moon Maiden, and she offered her blessings upon him "
"in the form of a scepter.  It appeared in his hands as he stood in the moonlight, and filled with hope, he "
"raised it against the monsters before him.  A brilliant light burst forth from the weapon, falling upon "
"undead and human alike, and the undead were shattered and fell to the ground.  Yet the villagers were "
"miraculously infused with healing, the slain among them returning to life, and the injured to wholeness.  "
"Never again did the creatures of darkness torment the village, and only the next day Alainn moved on with his "
"journey, and his tale is lost to history's pages.  But he left the scepter behind, and so it stayed within "
"the village, protected as a precious reminder of their salvation that night.%^RESET%^");
   set_property("lore difficulty",22);
}