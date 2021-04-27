#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit "/std/library";

#define SCRY_D "/daemon/ic_scry_locate_d"
object blocker;

void create()
{
    ::create();
    set_public_library(0);
    set_library_name("verbannon_library");
    set_deposit(0);
    set_property("indoors", 1);
    set_property("light", 2);
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_name("A makeshift library within a fortified laboratory ");
    set_short("A makeshift %^ORANGE%^l%^RED%^i%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^r%^RED%^a%^BOLD%^%^BLACK%^r%^RESET%^"
              "%^ORANGE%^y%^RESET%^ within a fortified %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^CYAN%^t"
              "%^BOLD%^WHITE%^ory%^RESET%^");
    set_long("Against the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^ of this area is a "
             "%^BOLD%^%^BLACK%^desk %^RESET%^littered with stacks of %^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^a%^BOLD%^p%^RESET%^%^WHITE%^e"
             "%^BOLD%^r%^RESET%^, %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ and writing materials. On the %^BOLD%^%^BLACK%^desk%^RESET%^ "
             "is a strange %^BOLD%^%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^YELLOW%^m%^RESET%^%^RED%^p%^RESET%^ providing light to read by in "
             "addition to the light provided by the %^BOLD%^%^CYAN%^wi%^WHITE%^nd%^CYAN%^ow%^RESET%^ %^BOLD%^%^CYAN%^sl%^WHITE%^i%^CYAN%^ts"
             "%^RESET%^. Cutting the %^BOLD%^%^BLACK%^desk %^RESET%^off from the rest of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b"
             "%^BOLD%^%^WHITE%^ora%^CYAN%^t%^BOLD%^WHITE%^ory%^RESET%^ are numerous overflowing %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^o"
             "%^BOLD%^%^BLACK%^ok%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^he%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ve%^RESET%^%^ORANGE%^s%^RESET%^ "
             "arranged in a semicircle between the %^BOLD%^%^BLACK%^desk%^RESET%^ and the rest of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b"
             "%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ with only walking room at the two ends of the wall of "
             "%^ORANGE%^sh%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^lv%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^ allowing people through. "
             "Large stacks of %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ that could not fit on the %^ORANGE%^sh%^BOLD%^%^BLACK%^e%^RESET%^"
             "%^ORANGE%^lv%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^ are piled everywhere making it hard to walk through. Multiple "
             "%^RED%^r%^ORANGE%^u%^RED%^g%^ORANGE%^s%^RESET%^ cover the %^RED%^g%^ORANGE%^r%^RED%^o%^ORANGE%^u%^RED%^n%^ORANGE%^d%^RESET%^ "
             "and large %^BOLD%^%^YELLOW%^maps%^RESET%^ are placed on the wall with pins sticking out of them. At first there seems to be no "
             "%^BOLD%^%^MAGENTA%^experiments%^RESET%^ in this section but then you notice some of the %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks"
             "%^RESET%^ are open and the pages are turning themselves.\n");
    set_smell("default", "A chemical odor muted by the smell of ink and paper.");
    set_listen("default", "Oddly enough only the rustling of pages.");

    set_items(([
                   ({ "wall", "maps" }) : "Various topographical %^BOLD%^%^YELLOW%^maps%^RESET%^ are pinned on the %^BOLD%^%^BLACK%^w%^RED%^a"
                   "%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^. These are %^BOLD%^%^YELLOW%^maps%^RESET%^ of just about everything, more "
                   "%^BOLD%^%^YELLOW%^maps%^RESET%^ than should be able to fit here really. Cities, buildings, regions, even houses. A "
                   "%^BOLD%^%^BLACK%^whisper%^RESET%^ exclaims 'Hey look! EVEN YOUR MOM'S! That one is labeled -conquered-'.",
                   "desk" : "This iron %^BOLD%^%^BLACK%^desk%^RESET%^ is fitted with three drawers crammed with %^BOLD%^%^WHITE%^p%^RESET%^"
                   "%^WHITE%^a%^BOLD%^p%^RESET%^%^WHITE%^e%^BOLD%^rs%^RESET%^, a hard iron seat and a desk %^BOLD%^%^YELLOW%^l%^RESET%^%^RED%^a"
                   "%^BOLD%^%^YELLOW%^m%^RESET%^%^RED%^p%^RESET%^. More %^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^a%^BOLD%^p%^RESET%^%^WHITE%^e%^BOLD%^r"
                   "%^RESET%^ covered the surface as well as stacks of %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^. A note stuck to the side of "
                   "the %^BOLD%^%^BLACK%^desk%^RESET%^ catches your eye 'Note to self: MUST GET A FILING SPELL!'",
                   "books" : "%^ORANGE%^B%^WHITE%^oo%^ORANGE%^ks%^RESET%^ on the ground, %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ on the "
                   "%^BOLD%^%^BLACK%^desk %^RESET%^and %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ on the %^ORANGE%^sh%^BOLD%^%^BLACK%^e%^RESET%^"
                   "%^ORANGE%^lv%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^. These %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ seem to cover "
                   "mostly the topics of war or magic. There seem to be a lot of %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ on the different "
                   "systems of magic and their workings. All of these magical %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ however seem to have "
                   "been written in and on with strange riddles. With their accompanying answer, though the answers don't make sense. 'If north is "
                   "north and south is south which direction is west? Answer: North is south, east is west, west is west and there is no south.' "
                   "Less weird but more terrifying is that some of the %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ seem to be locked in cases, but "
                   "even though the cases you can feel their evil pulsing. Four such cases have labels that read 'Attempt to copy the Book of "
                   "Planar Travels'.",
                   ({ "paper", "papers" }) : "Searching through the %^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^a%^BOLD%^p%^RESET%^%^WHITE%^e%^BOLD%^rs"
                   "%^RESET%^ you see letters, encoded documents, notes, blank pages, and diagrams of impossible shapes. The thought crosses your "
                   "mind even as a whisper comes that 'you could spend the next ten hours making %^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^a%^BOLD%^p"
                   "%^RESET%^%^WHITE%^e%^BOLD%^r%^RESET%^ gliders out of these. Just <fold paper glider>. Or not. Your choice.'",
                   "lamp" : "This strange oil %^BOLD%^%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^YELLOW%^m%^RESET%^%^RED%^p%^RESET%^ is covered "
                   "with runes and putting off a strange fire that keeps twisting into odd shapes. Staring at it for a while you notice that the "
                   "fire is twisting into shapes that resemble the runes on the %^BOLD%^%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^YELLOW%^m%^RESET%^"
                   "%^RED%^p%^RESET%^. You have an odd urge to <touch> it.",
                   ({ "bunker", "lab", "laboratory" }) : "The whispers sarcastically inform you that thanks to the eyes in the back and side of "
                   "your head you are able to view the whole %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^CYAN%^t%^BOLD%^WHITE%^ory"
                   "%^RESET%^ at once. Or you could if those damn %^ORANGE%^sh%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^lv%^BOLD%^%^BLACK%^e%^RESET%^"
                   "%^ORANGE%^s%^RESET%^ weren't in the way.",
                   ({ "bookshelves", "shelves" }) : "Many, many %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ok%^RESET%^%^RESET%^s"
                   "%^BOLD%^%^BLACK%^he%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ve%^RESET%^%^ORANGE%^s%^RESET%^ line up to form a semi-circle semi-"
                   "isolating this area from the rest of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^CYAN%^t%^BOLD%^%^WHITE%^ory"
                   "%^RESET%^. The shelves are all made of iron and covered with runes. And try as you might you can't turn them, move them or "
                   "push them over. There goes the possibility of playing %^ORANGE%^l%^RED%^i%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^r%^RED%^a"
                   "%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^y%^RESET%^ dominoes.",
                   ({ "rugs", "ground", "floor" }) : "Covering every inch of the %^RED%^g%^ORANGE%^r%^RED%^o%^ORANGE%^u%^RED%^n%^ORANGE%^d"
                   "%^RESET%^ here are %^RED%^r%^ORANGE%^u%^RED%^g%^ORANGE%^s%^RESET%^. Boring plain cheap %^RED%^r%^ORANGE%^u%^RED%^g%^ORANGE%^s"
                   "%^RESET%^. They are probably here to protect the %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ from the powder. A "
                   "%^BOLD%^%^BLACK%^whisper%^RESET%^ reaches your ears, 'Don't fear, if you lift the corner of one of these %^RED%^r%^ORANGE%^u"
                   "%^RED%^g%^ORANGE%^s%^RESET%^ you can reach the powder for all your tasting needs. See, we're helpful spirits!'",
                   "experiments" : "Creepily you see that the pages of some %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks%^RESET%^ are turning "
                   "themselves. When you look closer, you see a ghostly face in the air reading the %^ORANGE%^b%^WHITE%^oo%^ORANGE%^k%^RESET%^. It "
                   "looks at you, annoyed, and then just as the desire to shriek 'GHOST!' might be coming upon you, you notice that the face is in "
                   "a clear, almost invisible container set before the %^ORANGE%^b%^WHITE%^oo%^ORANGE%^k%^RESET%^. You also see a label on top of "
                   "the container that reads 'Outsider 75464: Fey Spirit'.",
                   ({ "windows", "slits", "window slits" }) : "The whispers announce 'Yep, they're here as well.' It seems that despite being "
                   "little more than holes in the wall, that no rain water comes through them to spoil the %^ORANGE%^b%^WHITE%^oo%^ORANGE%^ks"
                   "%^RESET%^. The whispers ask 'Wonder why? Clearly the only way to solve this mystery is to head outside and pee right into the "
                   "%^BOLD%^%^CYAN%^wi%^WHITE%^nd%^CYAN%^ow%^RESET%^ here to see what happens. Trust us, there is no chance of your crotch "
                   "exploding... Okay you got us. It totally will. Still worth watching happen!'",
               ]));

    set_exits(([
                   "northeast" : ROOMS "kitchen",
                   "southeast" : ROOMS "lab",
                   "south"     : ROOMS "sleeping",
               ]));
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
}

void reset()
{
    ::reset();
    if (!present("blockerx111")) {
        blocker = SCRY_D->add_block_scrying(TO);
        if (!objectp(blocker)) {
            tell_room(TO, "Something has gone wrong with the scry protection! Please tell Circe or Nienne.");
            return;
        }
        blocker->set_block_power("/daemon/player_housing"->get_phouse_scry_proof("legendary"));
    }
}

void init()
{
    ::init();
    add_action("lamp_fun", "touch");
    add_action("glider_fun", "fold");
    if (userp(TP) && !present("verbiewardxxx", TP)) {
        new(OBJ "verbieward")->move(TP);
    }
}

int lamp_fun(string str)
{
    if (!str) {
        return notify_fail("Touch what?");
    }
    if (str == "lamp") {
        tell_object(TP, "So you reach out and touch the fire. Because EVERYBODY knows that�s what you�re supposed to do in these "
                    "situations. You yelp in pain when you touch the fire, not because it's hot but because it's biting cold. Looks like luckily "
                    "your hand didn't freeze through. This time. You are urged on by a whisper to 'Touch it again!'");
        tell_room(ETP, "" + TP->QCN + " touches the lamp and yelps in pain! A whisper urges, 'Touch it again!'", TP);
        return 1;
    }
    return 0;
}

int glider_fun(string str)
{
    if (!str) {
        return notify_fail("Fold what?");
    }
    if (str == "paper glider") {
        tell_object(TP, "You spend some time fashioning one of these important-looking paper documents into a paper glider. The whispers shout 'Now throw it!'");
        tell_room(ETP, "" + TP->QCN + " spends some time fashioning one of the important-looking paper documents into a paper glider. The whispers shout 'Now throw it!'", TP);
        new(OBJ "paperglider")->move(TP);
        return 1;
    }
    return 0;
}
