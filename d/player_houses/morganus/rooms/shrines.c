#include <std.h>
#include "../morganus.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Room of Shrines");
   set_short("%^BOLD%^%^WHITE%^Room of Shrines%^RESET%^");
   set_long("This room seems to have love and care put into every inch of it. The candles "
"all about the room give a dim lighting. Seven different shrines lie around the majority "
"of the circumference of this room. Various patrons of different races linger about here, "
"some in prayer and meditation, others seeking advice of the soul.");
   set_smell("default","The smell of incense is heavy in this room as various shrines compete for the slight breeze.");
   set_listen("default","The murmurs of prayer in various languages fill these sacred chambers.");

   set_items(([
     ({"shrine","shrines"}) : "There are seven shrines here - which one do you want to "
"look at?%^RESET%^",
     ({"shrine one","shrine 1"}) : "%^BOLD%^%^BLUE%^This shrine at first appears to be a shrine for two "
"goddesses. However after careful study it appears that the shrine worships both Selune "
"and a drow goddess named Eilistraee as the same entity. On the left a symbol with two "
"female eyes surrounded by seven silver stars and on the right a symbol that shows a "
"graceful female drow with a secretive smile, entirely naked with a nimbus of long white "
"hair. She appears to be some sort of dance. The shrine is done in blue, silver and white "
"shades.%^RESET%^",
     ({"shrine two","shrine 2"}) : "%^BOLD%^%^BLACK%^This shrine has the symbol of a white cloud upon a "
"blue background. This would indicate that it is a shrine dedicated to Akadi. Along the "
"sides of it are etchings of birds and clouds. It would seem this particular shrine "
"focuses on the freedom aspect of Akadis domain. It is done in shades of white, blue and "
"gray.",
     ({"shrine three","shrine 3"}) : "%^YELLOW%^This shrine bears a collage of colors made to look like "
"a sunrise. This shows this would be a shrine of the sun god Lathander. Two beautiful "
"phoenix images adorn the shrine, joining together at the top. The shrine is decorated in "
"reds, yellows, and oranges.%^RESET%^",
     ({"shrine four","shrine 4"}) : "%^BLUE%^A circle of seven stars surround a cloud of red flowing "
"mist. This is the symbol of Mystra, Goddess of Magic and there is no mistaking this as a "
"shrine dedicated to the Lady of the Weave. Powerful looking silver dragons coil about "
"this shrine meeting at the apex to stare deeply in to each others eyes.%^RESET%^ ",
     ({"shrine five","shrine 5"}) : "%^MAGENTA%^The image of a blazing silver sword upon a blood red "
"shield adorns this practical looking shrine. Here patrons who live and die by the blade "
"make offerings to Tempus lord of Battle. The top of the shrine has a bust of a tiger's "
"head looking down at offerings.%^RESET%^",
     ({"shrine six","shrine 6"}) : "%^BOLD%^%^WHITE%^A female face surrounded by shamrocks upon a golden "
"coin adorn this shrine. The sides of the shrine are colored and shaped to appear like "
"large sized unicorn horns, however they are merely finely polished stone. The shrine "
"shows interesting smooth spots where people perhaps have rubbed at it for good luck. "
"Such is the way of Shrines of Tymora.%^RESET%^",
     ({"shrine seven","shrine 7"}) : "%^CYAN%^A set of scales balanced upon a war hammer show this to be "
"a shrine to Tyr. A shrine to the lord of Justice seems out of place here, but it seems "
"many of the patrons rely heavily on his wisdom to tell good from evil and right from "
"wrong. His scales keep confused creatures from other races on the path of the "
"righteous.%^RESET%^",
   ]));

   set_exits(([
     "west" : ROOMS"bar",
   ]));
}

void reset() {
   ::reset();
   switch(random(8)) {
     case 0..1:
     tell_room(TO,"%^GREEN%^A band of small humanoids obscuring their faces, make quick "
"offering and prayer to a few of the shrines, then quickly leave.%^RESET%^");
     break;
     case 2:
     tell_room(TO,"%^MAGENTA%^You think you see a pair of young drow dancing before one "
"of the shrines. They fade in to shadows with such attention.%^RESET%^");
     break;
     case 3:
     tell_room(TO,"%^ORANGE%^A small argument breaks out between those at the shrines of "
"Tymora and Tyr. A follower of Lathandar quickly heads it off.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^RED%^A band of tough orcs of questionable breeding, make a loud "
"offering at the shrine of Tempus and leave with an air of confidence.%^RESET%^");
     break;
     default: break;
   }
}
