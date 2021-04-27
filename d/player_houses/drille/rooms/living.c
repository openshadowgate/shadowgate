#include <std.h>
#include "../drille.h"
inherit "/std/library.c";

void create() {
    ::create();
  set_public_library(0);
  set_library_name("drille_library");
  set_deposit(0);
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A cosy living room");
    set_short("%^BOLD%^%^GREEN%^A cosy living room%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^On the far side of this cozy living room is "
"a large %^BOLD%^%^RED%^fireplace %^RESET%^%^ORANGE%^in which a blazing "
"%^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^ %^ORANGE%^roars, "
"filling the room with a %^MAGENTA%^comfortable %^RESET%^%^ORANGE%^warmth. "
"Large %^BOLD%^%^CYAN%^windows %^RESET%^%^ORANGE%^are set in the white brick "
"walls, overlooking the %^GREEN%^nature %^ORANGE%^outside. Two plush "
"%^RED%^armchairs %^RESET%^%^ORANGE%^are set beside each other opposite a "
"big, comfortable %^RED%^sofa %^RESET%^%^ORANGE%^near the fire. A sturdy "
"wooden table is set between the furniture and an impressive "
"%^BOLD%^%^BLACK%^bookshelf %^RESET%^%^ORANGE%^stands against the wall. "
"Beside the kitchen door is a nice looking desk. Several "
"colourful %^BOLD%^%^MAGENTA%^rugs %^RESET%^%^ORANGE%^cover the dark wooden "
"floor, and on the walls hang paintings in %^BOLD%^%^YELLOW%^gilded "
"%^RESET%^%^ORANGE%^frames.%^RESET%^");
    set_smell("default","%^BOLD%^%^BLACK%^The faint scent of fine pipe weed "
"lingers in the air.%^RESET%^");
    set_listen("default","%^BOLD%^%^RED%^The fire crackles merrily in the "
"fireplace.%^RESET%^");
    set_items(([
    ({"painting","paintings"}) : "Which painting do you want to look at?",
    ({"drawing","drawings"}) : "Which drawing do you want to look at?",
      ({"bookshelf","shelf"}) : "%^ORANGE%^Standing about eight feet tall and "
"four feet wide, this bookshelf is made of blackened, artistic ornate oak. "
"Carved into the wood along the top frame of the bookshelf are tiny beautiful "
"images of %^RESET%^sparrows%^ORANGE%^ and %^RESET%^%^GREEN%^"
"shamrocks%^RESET%^%^ORANGE%^. This exquisite piece of furniture holds "
"several %^CYAN%^books %^ORANGE%^of various colours. They all seem very well "
"kept, giving silent testimony of the love with which the owner has tended to "
"them. Alongside the books are various little items such as a pair of "
"candleholders, two tiny sculptures, one of a %^RESET%^sparrow%^ORANGE%^ and "
"one of a %^RESET%^%^MAGENTA%^butterfly%^RESET%^%^ORANGE%^, and a few small "
"%^BOLD%^%^WHITE%^silver-framed%^RESET%^ drawings%^ORANGE%^.%^RESET%^",
      "fireplace" : "%^RESET%^The fireplace is an excellent work of "
"masonry, and like the walls it is made of white bricks. Heavy %^BOLD%^"
"%^BLACK%^iron doors %^RESET%^hang on finely crafted %^BOLD%^%^BLACK%^iron "
"hinges %^RESET%^which have been studded fast to the brick. An "
"%^BOLD%^%^BLACK%^iron hook %^RESET%^has been set inside the oven itself, "
"from which a pot or a pan can be suspended. A number of lucky "
"%^BOLD%^%^MAGENTA%^charms %^RESET%^have been placed on the ornate "
"mantelpiece. A wonderfully woven %^BOLD%^%^BLUE%^long pile rug %^RESET%^"
"hangs on the wall above the fireplace, depicting a flying "
"%^BOLD%^%^GREEN%^sparrow %^RESET%^in extraordinary detail.%^RESET%^",
      ({"chair","chairs"}) : "%^MAGENTA%^The chairs appears to be very "
"sturdy. The solid oak frames hold up the thick and plushly cushioned seats "
"which look very comfortable. The armrests are bound with soft, purple "
"velvet.%^RESET%^",
      ({"couch","sofa"}) : "%^ORANGE%^The sofa stands securely on four feet "
"which hold up the solid oak frame. Both the thick cushioned seat and "
"backrest are bound with soft %^RESET%^%^MAGENTA%^purple velvet%^RESET%^"
"%^ORANGE%^. Many plush pillows are scattered around the sofa. It has a "
"roomy and cosy look, very suitable for curling up in under a warm "
"blanket.%^RESET%^",
      "table" : "%^ORANGE%^This is a simple yet well made table, fashioned "
"out of reliable oak. Its four legs are all ornate. A picture of a "
"%^BOLD%^%^MAGENTA%^knave %^RESET%^%^ORANGE%^has been carved into the board. "
"The knave appears to be holding a pair of %^BOLD%^%^BLUE%^dice "
"%^RESET%^%^ORANGE%^in one hand, and a deck of %^BOLD%^%^GREEN%^cards "
"%^RESET%^%^ORANGE%^in the other.%^RESET%^",
      "desk" : "%^ORANGE%^The desk is made of blackened oak. A small shelf "
"runs along the length of the surface. A cup containing %^BOLD%^%^WHITE%^"
"quill pens %^RESET%^%^ORANGE%^is set upon the shelf beside a jar of "
"%^BOLD%^%^BLUE%^ink%^RESET%^%^ORANGE%^. Placed upon the desk itself is a "
"nice bouquet of %^RESET%^%^GREEN%^wildflowers%^RESET%^%^ORANGE%^ in a pale "
"blue vase. The desk has two locked drawers in which %^RESET%^sheets of "
"parchment %^ORANGE%^can be stored. A plush chair is set in front of the "
"desk.%^RESET%^",
      "painting 1" : "%^RESET%^%^CYAN%^In this painting, two men stand "
"%^WHITE%^facing %^CYAN%^each other. It is as if they are both in a "
"%^GREEN%^meditative %^CYAN%^state. One of them, a young, %^BOLD%^%^YELLOW%^"
"suntanned human %^RESET%^%^CYAN%^with shoulder-length %^ORANGE%^blonde hair "
"%^CYAN%^has a deep %^BOLD%^calm %^RESET%^%^CYAN%^about himself that offers a "
"%^WHITE%^softness %^CYAN%^to his otherwise %^BOLD%^%^BLACK%^rugged "
"%^RESET%^%^CYAN%^features. The other man, shows almost %^RESET%^no emotion "
"%^CYAN%^at all. The %^MAGENTA%^artist %^CYAN%^captures him brushing his "
"%^BOLD%^%^BLACK%^long black hair %^RESET%^%^CYAN%^away from his face, giving "
"a %^BOLD%^%^YELLOW%^spectacular view %^RESET%^%^CYAN%^of his %^BOLD%^icy "
"blue eyes%^RESET%^%^CYAN%^. A %^ORANGE%^wolf-head visor %^CYAN%^is cradled "
"at his side while his other hand rests on the %^RED%^pommel %^CYAN%^of his "
"sword. It is as if both men have a certain %^BOLD%^%^RED%^respect "
"%^RESET%^%^CYAN%^for each other that needs no words. Hidden in the bottom "
"corner of the painting is a tiny pink butterfly, the only thing in the "
"painting that hints at a signature.%^RESET%^",
     "painting 2" : "%^RESET%^%^CYAN%^An old, %^WHITE%^bald man %^CYAN%^"
"stands leaning on a sword in front of his %^ORANGE%^home%^CYAN%^. He is "
"burly and well-built with %^GREEN%^chiseled features %^CYAN%^that make it "
"seem like he has had a very %^BOLD%^%^YELLOW%^adventurous life"
"%^RESET%^%^CYAN%^. Despite that, his gaze is %^MAGENTA%^soft %^CYAN%^and "
"seems to look right at you not matter where you view the painting "
"from.%^RESET%^",
     "painting 3" : "%^BOLD%^%^BLACK%^This scene is set high in the air, atop "
"a %^RESET%^%^MAGENTA%^black stone tower%^RESET%^%^BOLD%^%^BLACK%^. The night "
"is dark and in the distance a bolt of ligh%^YELLOW%^t%^BLACK%^ning cracks "
"the sky, casting its fractured, treacherous %^WHITE%^light%^BLACK%^ upon the scene. On the edge of the tower is the figure of a %^RESET%^%^MAGENTA%^"
"breathtaking young woman%^RESET%^%^BOLD%^%^BLACK%^, captured in profile "
"amidst a graceful %^WHITE%^twirl%^BLACK%^. The toes of one delicate foot "
"barely touch the ground while the other is already airborne, bent at the hip "
"and knee. One arm follows parallel with her slender hip in the twirl. The "
"other one reaches up towards the dark, stormy skies above. Her back and neck "
"are arched, the gaze of her enthralling %^RESET%^%^GREEN%^e%^RESET%^"
"%^BOLD%^%^GREEN%^m%^RESET%^%^BOLD%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^r"
"%^RESET%^%^GREEN%^a%^RESET%^%^BOLD%^%^GREEN%^l%^RESET%^%^BOLD%^%^WHITE%^d "
"%^RESET%^%^GREEN%^e%^RESET%^%^BOLD%^%^GREEN%^y%^RESET%^%^GREEN%^es%^RESET%^"
"%^BOLD%^%^BLACK%^ lifted. A %^CYAN%^dreamy%^BOLD%^%^BLACK%^ little smile "
"plays with the corners of her soft lips adding warmth to her dark, "
"%^RESET%^%^MAGENTA%^fey-like%^RESET%^%^BOLD%^%^BLACK%^ features. Her thick "
"ebony hair dances chaotically about her slender shoulders in the strong "
"wind. She wears a thin black si%^RESET%^l%^BOLD%^%^BLACK%^k dress that "
"clings to the delightful curves of her youthful body. The wind tears and "
"pulls at it, threatening to rip it of. The artist has put much care into "
"every detail of this amazing painting.%^RESET%^",
    "drawing 1" : "%^ORANGE%^The scene of this small %^RESET%^drawing"
"%^ORANGE%^ is set in the ruins of what seems to be a room at the very top of "
"a worn down old wooden building. Four people are in this picture. Sitting on "
"a wooden bunk, is an %^RESET%^%^YELLOW%^old man%^RESET%^%^ORANGE%^ with "
"wrinkled, leathery skin. He has his eyes closed and a %^RESET%^%^RED%^warm "
"smile%^RESET%^%^ORANGE%^ plays on his lips as he amply handles his lute. "
"Sitting by his feet, playing the harmonica, is a skinny %^RESET%^%^YELLOW%^"
"young boy%^RESET%^%^ORANGE%^, no older than 10. His clothes are ragged and "
"dirty. A pair of smiling, %^RESET%^%^BOLD%^%^BLUE%^blue eyes%^RESET%^"
"%^ORANGE%^ sparkle beneath is straw-brimmed hat. He seems to be watching the "
"%^RESET%^%^BOLD%^%^MAGENTA%^little girl%^RESET%^%^ORANGE%^ with some "
"amusement. %^RESET%^%^BOLD%^%^MAGENTA%^The girl%^RESET%^%^ORANGE%^ is "
"pictured in a playful %^RESET%^%^MAGENTA%^twirl%^RESET%^%^ORANGE%^ with only "
"the toes of one foot touching the wooden bench shes standing on. Both her "
"%^RESET%^%^YELLOW%^c%^RESET%^%^BOLD%^%^MAGENTA%^o%^RESET%^%^YELLOW%^l"
"%^RESET%^%^BOLD%^%^GREEN%^o%^RESET%^%^YELLOW%^rf%^RESET%^%^BOLD%^%^MAGENTA%^"
"u%^RESET%^%^YELLOW%^l%^RESET%^%^ORANGE%^ skirt and her %^RESET%^%^BOLD%^"
"%^BLACK%^messy, ebony hair%^RESET%^%^ORANGE%^ flow about her and she appears "
"to be %^RESET%^%^GREEN%^laughing merrily%^RESET%^%^ORANGE%^. In the back, "
"just inside the doorway, stands a %^BOLD%^%^BLACK%^black-haired"
"%^RESET%^%^ORANGE%^ young man, perhaps in his early twenties. His "
"t%^RESET%^%^YELLOW%^a%^RESET%^%^ORANGE%^nned features are soft, yet there is "
"a hardness about him. He is watching the scene with a mild glint in his "
"otherwise determined %^RESET%^%^BLUE%^d%^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^"
"%^BLUE%^rk-bl%^RESET%^%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e%^RESET%^%^ORANGE%^ "
"eyes. The others do not seem to be aware of him yet.\n"
"%^RESET%^%^ORANGE%^Written on the back of the silver frame are the "
"words:%^BOLD%^%^ORANGE%^ Mira Rose, 671 SG: Childhood Memories%^RESET%^",
    "drawing 2" : "%^GREEN%^This is a small drawing of a beautiful, lush "
"%^RESET%^%^BOLD%^%^GREEN%^meadow%^RESET%^%^GREEN%^. The scene is peaceful "
"and a slightly %^RESET%^foggy%^GREEN%^, like when the first ray of sun warms "
"the meadows in the morning. Colorful %^RESET%^%^MAGENTA%^butterflies"
"%^RESET%^%^GREEN%^ flutter among the flowers. %^RESET%^%^ORANGE%^Sparrows"
"%^RESET%^%^GREEN%^ play among the branches of the %^BOLD%^%^GREEN%^"
"magnificent tree%^RESET%^%^GREEN%^ in the center of the drawing.%^RESET%^\n"
"%^ORANGE%^Written on the back of the silver frame are the words: "
"%^YELLOW%^Mira Rose, 671 SG: To my sparrow%^RESET%^%^ORANGE%^.%^RESET%^",
    ]));
    set_exits(([
      "antechamber" : ROOMS"foyer",
      "kitchen" : ROOMS"kitchen",
    ]));
    set_door("oak door",ROOMS"foyer","antechamber",0);
    set_door_description("oak door", "%^ORANGE%^This is a standard oak door, "
"made of heavy oaken planks bound together with iron rivets.%^RESET%^");
    set_door("kitchen door",ROOMS"kitchen","kitchen",0);
    set_door_description("kitchen door", "%^ORANGE%^This is a standard oak "
"door, made of heavy oaken planks bound together with iron rivets.%^RESET%^");
}
