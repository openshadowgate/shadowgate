#include <std.h>
#include "../kier.h"
inherit VAULT;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("An Antechamber");
   set_short("%^RESET%^%^ORANGE%^An Antechamber%^RESET%^");
   set_long("%^ORANGE%^This circular room serves as an antechamber for the "
"tower. The walls are lined in paintings and there is an %^BLACK%^%^BOLD%^"
"iron circular staircase%^RESET%^%^ORANGE%^ leading ascending the tower. "
"There are several %^RED%^small benches%^RESET%^%^ORANGE%^ in front of each "
"painting. The floors are %^BLACK%^%^BOLD%^t%^RESET%^i"
"%^BLACK%^%^BOLD%^l%^RESET%^e%^BLACK%^%^BOLD%^d%^RESET%^ "
"m%^BLACK%^%^BOLD%^a%^RESET%^r%^BLACK%^%^BOLD%^b%^RESET%^l%^BLACK%^%^BOLD%^e"
"%^RESET%^%^ORANGE%^. Obviously this room is not made for comfort, but merely "
"a stopping point.");
   set_smell("default","You smell nothing specific here.");
   set_listen("default","Nothing disturbs the silence here.");

   set_items(([
     ({"paintings","painting"}) : "%^RESET%^There are several paintings, "
"which one would you like to look at?",
     ({"painting 1","first painting"}) : "%^BLACK%^%^BOLD%^This painting has "
"a very dark feel to it. It is of a muscular half-elf crouched on the ground. "
"He is dressed in dark armor and cradles a helm that looks like a wolf's "
"head. He looks very tired, yet the artist has captured a look of grim "
"determination in his dark blue eyes. At his side is an enormous black wolf. "
"The painting is very sedate, and there is a sense of measured gloom to it. "
"It is entitled - '%^CYAN%^Kiervalan and Perrin%^BLACK%^'.%^RESET%^",
     ({"painting 2","second painting"}) : "%^BOLD%^%^CYAN%^This painting must "
"once have been beautiful, but is now just shredded and torn. It hangs "
"lopsidedly on the wall, shreds of canvas fluttering lightly in the breeze. "
"You can tell it once depicted a woman of dark hair, surrounded by "
"butterflies. Oddly, the woman's eyes remain unharmed - orbs of stunning "
"emerald that seem to darken as you examine the painting, as if there was a "
"storm behind them.",
     ({"painting 3","third painting"}) : "%^RESET%^%^BOLD%^This painting "
"stands apart from the rest for several reasons. Unlike the rest it has "
"curtains of velvet that are drawn to cover it. As well the quality of the "
"work is much lower then the others; as if an amateur had painted it. There "
"is however an unusual quality to it that draws your eye. The painting is of "
"a small child, standing in a forest blanketed in snow. She is very young, "
"perhaps five or six. Her long curly black hair drapes over her shoulders, a "
"single golden bell attached near her left shoulder. Her eyes are deep dark "
"blue. She wears a simple white dress decorated with black ribbons. There is "
"a sense of perfect innocence in her guileless smile. In her hands she holds "
"a wooden toy wolf and a small silver flute. It is entitled - '%^CYAN%^My "
"angel, in my dreams and my heart%^RESET%^%^BOLD%^'.%^RESET%^",
     ({"painting 4","fourth painting"}) : "%^RED%^%^BOLD%^The woman in this "
"painting seems to look back at you with a cold calculating stare. She is "
"beautiful, stunningly so, and has a sly smirk on her face. Her bright "
"sapphire eyes are framed by straight ebony hair. She wears a skintight "
"leather bodice and two sheaths hang loose at her side. The hilts of swords "
"extend from those and her hands rest on the pommels almost casually. The "
"artist has paid special attention to tattoo on her upper arm, and the glint "
"of amusement that seems to flicker in her sapphire eyes. It is entitled - "
"'%^CYAN%^Etarena%^RED%^%^BOLD%^'.%^RESET%^",
     ({"stairs"}) : "%^BLACK%^%^BOLD%^Formed out of black wrought iron, these "
"stairs spiral upwards to the next floor of the tower. The handrail is formed "
"into a shooting star, and the railings are filled with designs of "
"%^RESET%^%^BOLD%^m%^RESET%^o%^BOLD%^o%^RESET%^ns%^BLACK%^%^BOLD%^ and "
"%^RESET%^%^BOLD%^st%^CYAN%^a%^RESET%^r%^BOLD%^s%^BLACK%^%^BOLD%^. The stairs "
"are a work of beauty.%^RESET%^",
     ({"benches"}) : "%^RED%^Small benches circle the stairs, facing the "
"paintings. The cusions are red velvet and look quite comfortable%^RESET%^ ",
   ]));

   set_exits(([
     "up" : ROOMS+"bedroom",
     "out" : ROOMS+"path",
   ]));
   set_door("door",ROOMS+"path","out");
   set_locked("door",1);
   set_door_description("door","%^ORANGE%^This oak door is obviously heavy, "
"and large. It is free of design and is opened using a heavy %^BLACK%^%^BOLD%^"
"dark iron ring%^RESET%^%^ORANGE%^ to pull it open.%^RESET%^");
}
