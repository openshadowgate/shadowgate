#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit INH+"memories";

int a,b,searched;

void create() {
   ::create();
   a = random(4);
   b = random(4);
   while (b == a) { b = random(4); }
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(BRANCHES);
   set_travel(LEDGE);
   set_name("A small semi-enclosed room");
   set_short("%^ORANGE%^A small semi-enclosed room%^RESET%^");
   set_smell("default","The sharp, crisp scent of the forest fills the air.");
   set_listen("default","You can hear the quiet rustle of wind through the trees.");
   set_long("%^CYAN%^This circular platform is set with archways at seven evenly-spaced intervals around "
"the room, that support a high-arched %^ORANGE%^wooden ceiling%^CYAN%^ above.  The floor is formed from "
"the same wood as the rest of the room, and supported by strong splayed branches beneath.  A few rays of "
"%^YELLOW%^su%^WHITE%^n%^YELLOW%^li%^WHITE%^g%^YELLOW%^ht%^RESET%^%^CYAN%^ filter through the leaves and "
"branches surrounding the room, shedding soft light within.  Near one of the archways, several of the "
"tree's branches have grown inward over the lip of the platform, interlacing to form what looks like a "
"small bed.  A soft mattress rests atop the enmeshed branches, and a %^BLUE%^pale blanket%^CYAN%^ is "
"folded off to one side.  At the far side of the room is a low %^ORANGE%^wooden table%^CYAN%^, with a few "
"bound %^RED%^books%^CYAN%^, %^WHITE%^papers%^CYAN%^, what appears to be a %^MAGENTA%^music box%^CYAN%^, "
"and various other items atop it, and a woven mat set before it on the floor.  From within the largest "
"archway, a spiralling staircase leads downwards.%^RESET%^\n");
   set("night long","%^CYAN%^This circular room is set with archways lined with "
"%^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie lights, at seven evenly-spaced intervals around the "
"room, supporting a high-arched %^ORANGE%^wooden ceiling%^CYAN%^ above.  The floor is formed from the "
"same wood as the rest of the room, and supported by strong splayed branches beneath.  Outside the room, "
"the forest is shrouded in the %^BLACK%^%^BOLD%^dark shades of night%^RESET%^%^CYAN%^, only revealing an "
"occasional %^WHITE%^tw%^BOLD%^i%^RESET%^%^WHITE%^nk%^BOLD%^l%^RESET%^%^WHITE%^e%^CYAN%^ of the stars "
"above between the leaves and branches.  Near one of the archways, several of the tree's branches have "
"grown inward over the lip of the platform, interlacing to form what looks like a small bed.  A soft "
"mattress rests atop the enmeshed branches, and a %^BLUE%^pale blanket%^CYAN%^ is folded off to one "
"side.  At the far side of the room is a low %^ORANGE%^wooden table%^CYAN%^, with a few bound %^RED%^"
"books%^CYAN%^, %^WHITE%^papers%^CYAN%^, what appears to be a %^MAGENTA%^music box%^CYAN%^, and various "
"other items atop it, and a mat set before it on the floor.  From within the largest archway, a spiralling "
"staircase leads downwards.%^RESET%^\n");
   set_items(([
     ({"archways","arches"}) : (:TO,"arches_desc":),
     "carvings" : "%^CYAN%^The three archways are patterned with what look like intricate carvings, of "
"leaves and vines with a few small flowers scattered among them.  Upon a closer inspection, no cuts or "
"sharp edges are visible within the wood, as though the patterns had somehow grown this way.%^RESET%^",
     "bed" : "%^CYAN%^Off to one side of the room, the tree's branches have grown inward through one arch "
"and become intertwined together, to form a simple bed set with a soft mattress.  It looks a little too "
"small for a normal-sized human.  A %^BLUE%^pale blanket%^CYAN%^ is folded, draped across one of the "
"branches.%^RESET%^",
     "blanket" : "%^CYAN%^A %^BLUE%^dark blue blanket%^CYAN%^ lies carefully folded on the edge of the "
"small bed.  It has been sewn from some unknown material, and is very soft.%^RESET%^",
     ({"box","music box"}) : "%^CYAN%^Unique among the personal effects scattered across the tabletop "
"is this small, carved wooden box.  To a first glance, it seems to be an %^MAGENTA%^ornate %^CYAN%^"
"version of a child's music box, etched with little birds and leaves around the outside, while the "
"opened lid reveals a %^RED%^velvet-lined %^CYAN%^inner space.  However, where normally there would "
"be a carved dancer or other amusement for the young, the box itself is quite empty.  Something "
"draws you to %^RESET%^touch %^CYAN%^the exquisite item.%^RESET%^",
     ({"floor","platform"}) : "%^CYAN%^The floor is formed entirely from %^ORANGE%^smooth wood%^CYAN%^, "
"of an identical shade and texture to the walls, and the tree supporting it.  Strong branches spread "
"beneath the platform support it, looking in some places like the room is part of the tree "
"itself.%^RESET%^",
     ({"table","desk"}) : "%^CYAN%^This long %^ORANGE%^wooden table%^CYAN%^ is low to the ground, only about "
"a foot high, with a %^ORANGE%^faded woven mat%^CYAN%^ set before it on the ground.  Upon the table are "
"several %^RED%^books%^CYAN%^ and %^WHITE%^papers%^CYAN%^, as well as quills, ink and a handful of smooth "
"multicoloured stones.  Amongst the little stones sits a little bundle of working tools, as well as a "
"delicate %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^mm%^BOLD%^e%^RESET%^%^WHITE%^ri%^BOLD%^n%^RESET%^%^WHITE%^g "
"%^CYAN%^circlet and a single %^BLACK%^%^BOLD%^black feather%^RESET%^%^CYAN%^.%^RESET%^",
     "mat" : "%^CYAN%^This simple mat has been woven from long reeds, dry and faded to a %^ORANGE%^soft "
"tan hue%^CYAN%^.  It is large enough to cover more than half of the floor.%^RESET%^",
     "circlet" : "%^CYAN%^Amongst the stones rests a delicate circlet of "
"%^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^mm%^BOLD%^e%^RESET%^%^WHITE%^ri%^BOLD%^n%^RESET%^%^WHITE%^g "
"%^CYAN%^silver, set with a single milky-white %^WHITE%^%^BOLD%^moonstone%^RESET%^%^CYAN%^ in the centre of "
"the brow.  It has an almost tangible %^BOLD%^aura%^RESET%^%^CYAN%^ of warmth around it.%^RESET%^",
     ({"books","papers"}) : "%^CYAN%^Several bound %^RED%^books%^CYAN%^ sit upon the desk here.  "
"A look at their covers reveals they are of varied topics, several to do with various forms of magicks "
"and magecraft.  One or two, set a little apart, have titles written in soft script, under which are a few "
"loose sheets of %^WHITE%^paper%^CYAN%^ also written in flowing calligraphy.  You could take a closer look "
"at some of them, or perhaps even try to %^RESET%^read %^CYAN%^a few if you wanted to.",
     ({"stones","rocks"}) : "%^CYAN%^A few small stones of various %^ORANGE%^h%^WHITE%^u%^BOLD%^e%^BLACK%^s"
" %^RESET%^%^CYAN%^ and %^BLACK%^%^BOLD%^t%^RESET%^%^ORANGE%^e%^WHITE%^x%^BLACK%^%^BOLD%^t%^RESET%^%^WHITE%^"
"ur%^BOLD%^e%^RESET%^%^ORANGE%^s%^CYAN%^ are sitting to the left of the books.  Beside them sits a small "
"bundle of tools, and amongst them rests a delicate %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^mm%^BOLD%^e"
"%^RESET%^%^WHITE%^ri%^BOLD%^n%^RESET%^%^WHITE%^g %^CYAN%^circlet, and a single %^BLACK%^%^BOLD%^black "
"feather%^RESET%^%^CYAN%^.%^RESET%^",
     "feather" : "%^CYAN%^Resting amongst the stones, beside the %^WHITE%^sh%^BOLD%^i%^RESET%^%^WHITE%^mm"
"%^BOLD%^e%^RESET%^%^WHITE%^ri%^BOLD%^n%^RESET%^%^WHITE%^g %^CYAN%^circlet, rests a single long feather.  It "
"is smooth and glossy, and of a %^BLACK%^%^BOLD%^jet-black hue%^RESET%^%^CYAN%^.  Judging from the size of "
"the feather, it probably came from a fairly large bird.%^RESET%^",
     ({"tools","working tools"}) : "%^CYAN%^A few small, %^BLACK%^%^BOLD%^metallic%^RESET%^%^CYAN%^ tools "
"sit in a little bundle, wrapped carefully in linen cloth.  A small bottle of oil sits beside them, carefully "
"stoppered.  They seem designed for any variety of tasks, none for any sort of heavy craft, but enough to "
"manage simple repairs on just about anything.%^RESET%^",
     "pendant" : ({"%^CYAN%^This small pendant has been crafted from %^WHITE%^%^BOLD%^bright electrum"
"%^RESET%^%^CYAN%^, threaded with faint veins of %^BOLD%^blue%^RESET%^%^CYAN%^ through the metal. A simple "
"%^ORANGE%^leather strap%^CYAN%^ holds it about the wearer's neck. The surface of the pendant is smooth and "
"unmarked, save for seven tiny stars crafted from flecks of fire opal that flash %^MAGENTA%^%^BOLD%^b"
"%^RESET%^%^MAGENTA%^r%^BLUE%^i%^BOLD%^g%^GREEN%^h%^RESET%^%^GREEN%^t%^RESET%^%^CYAN%^ colours as they catch "
"the light. On the underside of the pendant a few words have been etched in flowing elven script."
"%^RESET%^","\n\n%^WHITE%^%^BOLD%^~ May Selune guide your steps at night, and bring them to the new Dawn "
"~%^RESET%^","elven"}),
     ({"lights","faerie lights"}) : (:TO,"lights_desc":),
     "book" : "Which book do you want to look at?",
     "paper" : "Which paper do you want to look at?",
     "book 1" : ({"%^BLACK%^%^BOLD%^This book is sitting on top of the rest, and looks much older and a "
"little more worn than most of the others.  Upon opening the book, you find text upon the pages in "
"simple but carefully-written elven script.  A few of the pages are a little "
"%^RESET%^%^ORANGE%^ragg%^BLACK%^%^BOLD%^e%^RESET%^%^ORANGE%^d%^BLACK%^%^BOLD%^ around the edges, and "
"some look to be missing altogether.  Some of the writing is blurred and smudged in parts, probably from "
"exposure or simply the book's age.%^RESET%^","%^RESET%^\n\n...undays, 654 SG...\n"
"...with the most mysterious of events.  I'm guessing that this will be an ongoing story as I learn more "
"of my mysterious invisible companion.  He visits every now and then, to help me along with my common (I "
"don't think he speaks much elven, poor thing), or give me assistance of some sort.  He speaks strangely "
"with a slight lisp, an...\n"
"...e doesn't care much for questions about himself: he disappears if I ask, and hasn't revealed his "
"name to me.  And he certainly seems to have quite a knack for poetry, by wha...\n\n"
"%^BLACK%^%^BOLD%^Another folded sheet of paper is set between the page.  Upon unfolding it, you can "
"read in a more elegant style of elven script:%^RESET%^\n\n"
"%^GREEN%^The beauty of the fragile lilly sits upon the water still\n"
"%^GREEN%^But how lovlier the hardy fern who grows and thrives through winter's chill\n"
"%^GREEN%^To bring the greenness and the life\n"
"%^GREEN%^To summer, and you bring to mind\n"
"%^GREEN%^The hardy fern who will survive and thrive within my thoughts","elven"}),
     "book 2" : ({BOOKS1[a],BOOKS2[a],BOOKS3[a]}),
     "book 3" : ({BOOKS1[b],BOOKS2[b],BOOKS3[b]}),
     "paper 1" : "%^BLACK%^%^BOLD%^Upon the first sheet of paper is a rough drawing, of a "
"%^RESET%^%^GREEN%^grassy field%^BLACK%^%^BOLD%^ speckled with trees.  Beside one of these trees, a large "
"oak with widespread branches, is a small, open shrine built of %^RESET%^%^ORANGE%^faded "
"stone%^BLACK%^%^BOLD%^.  Within the shrine itself are visible only a handful of benches, and a simple "
"stone altar draped with an %^RESET%^%^WHITE%^embroidered%^BLACK%^%^BOLD%^ cloth.%^RESET%^",
     "paper 2" : "%^BLACK%^%^BOLD%^The sheet of parchment is painted with an image of inks and pastels, of "
"a dark and barren wasteland lit by a %^RESET%^%^RED%^dull red sky%^BOLD%^%^BLACK%^.  Upon the ground stands "
"an %^WHITE%^armorclad%^BLACK%^ elf, though the features of his face are hidden by %^RESET%^%^BLUE%^cast "
"shadows%^BLACK%^%^BOLD%^.  A %^YELLOW%^golden aura%^BLACK%^ is radiant around his figure, and within one "
"hand he holds a great hammer to the heavens, from whence a bolt of %^YELLOW%^li%^WHITE%^g%^YELLOW%^htn"
"%^WHITE%^i%^YELLOW%^ng%^BLACK%^ arcs forth to strike upon the top of the weapon.  At the bottom of the "
"parchment, a single %^YELLOW%^'S'%^BLACK%^ has been scribed in golden ink, probably as a signature."
"%^RESET%^",
     "paper 3" : ({"%^BLACK%^%^BOLD%^Off to one side sits a few more leaves of paper, all blank save for the "
"one on top.  Resting upon it is a small, %^WHITE%^bright%^BLACK%^ electrum pendant on a simple %^RESET%^"
"%^ORANGE%^leather%^BLACK%^%^BOLD%^ band.  The paper itself contains several verses of carefully-scripted "
"calligraphy which you could read.%^RESET%^","\n\n%^CYAN%^Close your eyes "
"child, lest the %^BLACK%^%^BOLD%^dark%^RESET%^%^CYAN%^ find you\n"
"%^CYAN%^those that seek you for what you have become\n"
"%^CYAN%^the shadows close around you, though they try to call you back\n"
"%^CYAN%^none can take from you the faith within.\n\n"
"%^CYAN%^Close your eyes child, lest the %^YELLOW%^light%^RESET%^%^CYAN%^ blind you\n"
"%^CYAN%^those who trust themselves to know the truth\n"
"%^CYAN%^they bring you harm for what you are, not who you are inside\n"
"%^CYAN%^what they 'know' within themselves could never be.\n\n"
"%^CYAN%^Close your eyes child, lest the %^RED%^pain%^CYAN%^ bind you\n"
"%^CYAN%^leave you helpless to your deepest fears\n"
"%^CYAN%^the impossible path to walk that now you tread, step by step\n"
"%^CYAN%^find resolve within yourself to carry on.\n\n"
"%^CYAN%^Close your eyes child, leave the %^MAGENTA%^past%^CYAN%^ behind you\n"
"%^CYAN%^though others have no strength to do the same\n"
"%^CYAN%^the hate they bring may leave you cold, but anger changes naught\n"
"%^CYAN%^close your eyes child, but never close your heart.\n\n"
"%^CYAN%^Close your eyes child, let the %^WHITE%^%^BOLD%^peace%^RESET%^%^CYAN%^ mind you\n"
"%^CYAN%^watch over you and leave your soul to rest\n"
"%^CYAN%^they cannot hurt you now, and the truth remains with me\n"
"%^CYAN%^let it all go, and simply %^WHITE%^close your eyes%^CYAN%^.%^RESET%^","drow"}),
   ]));
   set_exits(([
     "down" : ROOMS+"house2"
   ]));
}

string arches_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^The branches of the trees nearby brush lightly against the %^ORANGE%^wooden "
"arches%^CYAN%^, of which there are seven spaced evenly around the room's perimeter.  Small, "
"%^WHITE%^%^BOLD%^bright%^RESET%^%^CYAN%^ faerie lights illuminate the edges of each arch, shedding a "
"little light into the semi-enclosed room.  The archways are patterned with what look like intricate "
"carvings.  They are all identical save for one, larger than the others, from which a staircase curls "
"down around the tree's trunk to meet with another closed-in room further down the tree, lit with more "
"%^WHITE%^fl%^YELLOW%^i%^RESET%^%^WHITE%^cke%^BOLD%^r%^RESET%^%^WHITE%^ing%^CYAN%^ lights.%^RESET%^");
   }
   return("%^CYAN%^The branches of the trees nearby brush lightly against the %^ORANGE%^wooden "
"arches%^CYAN%^, of which there are seven spaced evenly around the room's perimeter.  The archways are "
"patterned with what look like intricate carvings.  They are all identical save for one, larger than the "
"others, from which a staircase curls down around the tree's trunk to meet with another closed-in room "
"further down the tree.%^RESET%^");
}

string lights_desc() {
   if((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^CYAN%^Small %^WHITE%^%^BOLD%^sp%^RESET%^%^WHITE%^a%^BOLD%^rkl%^YELLOW%^i%^WHITE%^ng "
"lig%^RESET%^%^WHITE%^h%^BOLD%^ts%^RESET%^%^CYAN%^ line the edges of the arches, showing them up from the "
"%^BLACK%^%^BOLD%^dark night%^RESET%^%^CYAN%^ beyond and shedding a little light into the room.%^RESET%^");
   }
   return("You do not notice that here.");
}
