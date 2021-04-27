#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("The Master Bedroom");
    set_short("%^BOLD%^%^MAGENTA%^The Master Bedroom%^RESET%^");
    set_long("%^RESET%^%^GREEN%^A large %^ORANGE%^bed %^GREEN%^dominates "
"this very spacious chamber. Two nightstands are placed on either side of it, "
"and atop one of them stands a small music box. A painting hangs on the wall above the head of the bed. Across the room "
"from the %^CYAN%^platform %^RESET%^%^GREEN%^is a windowed door, which leads "
"out to what appears to be a balcony. On the left of the windowed door stands "
"a magnificient %^BOLD%^%^BLACK%^armoire%^RESET%^%^GREEN%^, and on the right a "
"beautifully ornate %^BOLD%^%^WHITE%^mirror%^RESET%^%^GREEN%^. A beautiful "
"%^BOLD%^%^CYAN%^crystal chandelier %^RESET%^%^GREEN%^hangs from the ceiling, "
"providing soft %^BOLD%^%^YELLOW%^lighting %^RESET%^%^GREEN%^to the room. The "
"floor is completely covered by a thick, blue%^BOLD%^%^BLUE%^ "
"carpet%^RESET%^%^GREEN%^, into which images of various kinds and colours "
"have been expertly woven.%^RESET%^");
    set_smell("default","%^MAGENTA%^The scented candles fill the room with a sensual aroma.%^RESET%^");
    set_listen("default","%^CYAN%^The soft, gentle tones of a soothing melody wafts through the room.%^RESET%^");
    set_items(([
      "chandelier" : "%^BOLD%^%^CYAN%^The crystals of this chandelier are bound together by delicate "
"%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r %^BOLD%^%^CYAN%^chains. "
"Each of its seven arms end in a %^YELLOW%^gilded %^CYAN%^cup, holding a scented candle.%^RESET%^",
      "bed" : "%^ORANGE%^The ornate frame of this huge bed is made of finest "
"mahogony wood. The mattress is very thick and soft, covered by sheer "
"%^BOLD%^%^WHITE%^silken %^RESET%^%^ORANGE%^sheets. Numerous "
"%^BOLD%^%^MAGENTA%^plush %^RESET%^%^ORANGE%^pillows litter the bed. The "
"%^BOLD%^luscious %^RESET%^%^ORANGE%^blanket is covered by a colorful "
"bedspread. Thin, almost transluscent %^BOLD%^%^BLUE%^veils%^RESET%^%^ORANGE%^"
" hang down from the upper framework, providing a comfortable "
"%^BOLD%^BLACK%^twi%^WHITE%^light %^RESET%^%^ORANGE%^within.%^RESET%^",
      "carpet" : "%^BOLD%^%^BLUE%^The carpet is very thick and comfortable to "
"walk on. It is coloured in a deep shade of blue. Intricate patterns "
"depicting all kinds of %^RED%^creatures %^BLUE%^and %^GREEN%^symbols "
"%^BLUE%^are woven into the fabric.%^RESET%^",
      "armoire" : "%^ORANGE%^This piece of mahogany furniture is simply "
"magnificent. Its framework is beautifully ornate, bearing witness of "
"excellent artistic skill. Carved into the wood along the top frame of the "
"armoire are tiny beautiful images of %^RESET%^sparrows%^ORANGE%^ and "
"%^GREEN%^shamrocks%^ORANGE%^. Two large doors hang on polished brass hinges. "
"The armoire contains both male and female clothes, as well as equipment and "
"material for tailoring.%^RESET%^",
      "painting" : "%^RESET%^%^CYAN%^There is exquisite detail in this "
"painting. A %^MAGENTA%^young%^CYAN%^, %^BOLD%^%^BLACK%^da%^MAGENTA%^r"
"%^BLACK%^kly clad %^RESET%^woman %^CYAN%^holds her lover close. He is a "
"%^BOLD%^%^BLACK%^well-built %^CYAN%^human %^RESET%^%^CYAN%^with %^BOLD%^"
"%^YELLOW%^blonde %^RESET%^%^CYAN%^shoulder-length hair and %^ORANGE%^brown "
"eyes %^CYAN%^as warm as %^ORANGE%^c%^BOLD%^o%^RESET%^%^ORANGE%^ffee%^CYAN%^. "
"The woman's own eyes are a %^GREEN%^mesmerizing shade of %^GREEN%^e"
"%^BOLD%^m%^WHITE%^e%^BLACK%^r%^RESET%^%^GREEN%^a%^BOLD%^l%^RESET%^%^GREEN%^d"
"%^CYAN%^, s%^GREEN%^p%^CYAN%^a%^GREEN%^r%^CYAN%^k%^GREEN%^l%^CYAN%^i%^GREEN%^"
"n%^CYAN%^g brightly as she looks into the %^ORANGE%^face %^CYAN%^of the man "
"she %^RED%^loves%^CYAN%^. They both seem to hover above a %^BOLD%^clear "
"pool%^RESET%^%^CYAN%^, which %^BOLD%^%^YELLOW%^shimmers %^RESET%^%^CYAN%^"
"with the light of many %^ORANGE%^golden %^CYAN%^and %^RESET%^silver "
"%^CYAN%^coins that have been tossed into it for %^MAGENTA%^luck %^CYAN%^or "
"perhaps in %^RESET%^hopes %^CYAN%^of a %^BOLD%^%^GREEN%^wish "
"%^RESET%^%^CYAN%^come true.%^RESET%^",
    ]));
    set_exits(([
      "balcony" : ROOMS"balcony",
      "bathroom" : ROOMS"bathroom",
      "platform" : ROOMS"platform",
    ]));
    set_door("balcony door",ROOMS"balcony","balcony",0);
    set_door_description("balcony door", "%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets. It has a "
"small window set into it.%^RESET%^");
    set_door("bath door",ROOMS"bathroom","bathroom",0);
    set_door_description("bath door", "%^ORANGE%^This is a standard oak door, "
"made of heavy oaken planks bound together with iron rivets.%^RESET%^");
    set_door("bedroom door",ROOMS"platform","platform",0);
    set_door_description("bedroom door", "%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets.%^RESET%^");	
    set_locked("bedroom door",1);
    new(OBJ+"mirror")->move(TO);
}
