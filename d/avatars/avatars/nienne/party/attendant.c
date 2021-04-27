#include <std.h>
inherit BARKEEP;
// Masquerade Ball Bar-Keep
// Nienne Installed-Fixed, Lurue Wrote - November 2008

void create() {
::create();
set_property("no bump", 1);
set_name("attendant");
set_id( ({"ghost","ghostly waiter","Ghostly Waiter","waiter"}) );
set_short("Ghostly Waiter");
set_long("%^BOLD%^%^WHITE%^The ghostly humanoid form before you seems to fade in and out of sight even as you watch him. Humanoid in form, his features are as misty as the rest of him, though you get a distinct impression that his eyes are a depthless blue that, in life, was filled with kindness and acceptance. Wisps of platinum blonde hair curl about his face and float on an unfelt wind, just as the immaculate garments he wears seem to be tugged upon by the slight wind. Standing at the ready to conjure up your favorite treat, he waits patiently for orders behind the bar.%^RESET%^");
set_gender("male");
set_alignment(5);
set("race","ghost");
set_level(15);
set("aggressive", 0);
set_hd(12,2);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
set_mp(random(400));
set_max_mp(query_mp());
add_money("copper", random(20));
set_exp(1);
set_body_type("human");
set_currency("silver");
set_spoken("wizish");
command("speech whisper quietly");

set_menu(
({"dragonblood","tortured toddy","witch brew","spiced mist","pumpkin seed brittle","yummy mummy","spider bites"}),
({"alcoholic","alcoholic","soft drink","soft drink","food","food","food"}),
({30,20,15,15,5,20,30})
);
set_my_mess(({
"%^RESET%^%^RED%^The thick, heady liquid slides down your throat just like blood, and leaves an invigorated feeling behind.%^RESET%^",
"%^RESET%^%^ORANGE%^The zest of lemon, orange, clove and cinnamon blends with punch of dark rum, leaving your taste buds tortured and you wanting more!%^RESET%^",
"%^RESET%^%^GREEN%^The globs of colored gelatin slither wetly along your tongue like living snakes as you down this warm apple flavored drink.%^RESET%^",
"%^BOLD%^%^WHITE%^You barely notice the faint blackberry flavor of the effervescent steamed milk.%^RESET%^",
"%^RESET%^%^ORANGE%^The large square of brittle has a distinct pumpkin flavor to it.",
"%^RESET%^%^ORANGE%^The crispy texture of the pastry bandages crumble and flake as you bite into the delicious cheese and meat center.%^RESET%^",
"%^BOLD%^%^BLACK%^These small round balls of spicy meat trail their noodle legs all the way down!%^RESET%^",
}));

set_your_mess(({
"looks bright eyed as a drop of %^RESET%^blood red%^RESET%^ liquid trickles down from the corner of their mouth.",
"gasps with near pain, eyes bulging out as they smack their lips after downing their drink.",
"shudders and looks almost repulsed as they swallow the last of their %^RESET%^%^GREEN%^pale green %^RESET%^drink.",
"closes their eyes and inhales, savoring the misty liquid they drink.",
"crunches away at the brittle.",
"tears apart the pastry bandages to get at the filling inside!",
"pops each little black meatball into their mouth slurping up the trailing noodles afterward."
}));

set_menu_short(({
"Dragonblood",
"Tortured Toddy",
"Witch Brew",
"Spiced Mist",
"Pumpkin Seed Brittle",
"Yummy Mummy",
"Spider Bites"
}));

set_menu_long(({
"%^BOLD%^%^RED%^This deep red liquid is served warm in a clay cup. Thick and slow moving, it appears to have a thin solidified crust over the top. A heady smell of smoke and brandy rise from the cup making your eyes water with the vapors. %^RESET%^",
"%^RESET%^%^ORANGE%^A pale amber liquid, the mixture is served in a wide mouthed glass that has had its rim dipped in red colored sugar making the rim look broken and dangerous. The smell of rum, citrus, clove and cinnamon drift from the glass causing the hairs on the back of your neck to stand on end.%^RESET%^",
"%^RESET%^%^GREEN%^Pale green, this liquid is provided in a tube of glass and bubbles constantly. Floating within the apple flavored mix are several slivers of slimy looking dark green gelatin making you think of snakes and worms and less settling things.%^RESET%^",
"%^BOLD%^%^WHITE%^Little more then foam served in a heated mug, the steamed milk has a faint scent of blackberries and something tarter. %^RESET%^",
"%^RESET%^%^ORANGE%^A large square of sweet brittle, this orange caramel is filled with dozens of small white pumpkin seeds that give the snack a rich pumpkin flavor.%^RESET%^",
"%^BOLD%^%^WHITE%^A mixture of tart prosciutto, mild cream cheese and slivers of onion, bell pepper and olives are blended together inside a humanoid shaped, pastry wrapped figure served with blended red pepper sauce.%^RESET%^",
"%^BOLD%^%^BLACK%^Little spicy balls of meat are served up with eight slender strings of wiggling noodles extending from their centers. Placed upon a bowl covered with strips of pale white cream, it looks almost like a group of little spiders lounging on a web."
}));

}