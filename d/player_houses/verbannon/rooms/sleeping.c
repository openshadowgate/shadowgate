#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

#define SCRY_D "/daemon/ic_scry_locate_d"
object blocker;

void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_name("Sleeping area within a fortified laboratory");
    set_short("Sleeping area within a fortified %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^CYAN%^t%^BOLD%^WHITE%^ory%^RESET%^");
    set_long("This section of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^CYAN%^t%^BOLD%^%^WHITE%^ory"
             "%^RESET%^ is dominated by a large ten by four foot green rectangular %^GREEN%^c%^BOLD%^u%^RESET%^%^GREEN%^b%^BOLD%^e%^RESET%^. "
             "The %^GREEN%^c%^BOLD%^u%^RESET%^%^GREEN%^b%^BOLD%^e%^RESET%^ is hollow resembling a %^GREEN%^c%^BOLD%^%^GREEN%^o%^RESET%^"
             "%^GREEN%^f%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^RESET%^%^GREEN%^n%^RESET%^ of sorts. Inside is bedding suggesting someone "
             "sleeps here. At the foot of this '%^GREEN%^b%^BOLD%^e%^RESET%^%^GREEN%^d%^RESET%^' is a %^ORANGE%^c%^BOLD%^h%^RESET%^"
             "%^ORANGE%^e%^BOLD%^s%^RESET%^%^ORANGE%^t%^RESET%^. Along the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l"
             "%^RESET%^ here is a %^ORANGE%^w%^BOLD%^a%^RESET%^%^ORANGE%^r%^BOLD%^d%^RESET%^%^ORANGE%^r%^BOLD%^o%^RESET%^%^ORANGE%^b"
             "%^BOLD%^e%^RESET%^ and two %^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^a%^BLACK%^p%^RESET%^%^ORANGE%^o%^BOLD%^"
             "%^WHITE%^n %^BLACK%^r%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^%^ORANGE%^s%^RESET%^. A few "
             "%^BOLD%^%^MAGENTA%^experiments%^RESET%^ seem to be placed here as well. The %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l"
             "%^BOLD%^%^BLUE%^ls%^RESET%^ here are the same as elsewhere and the %^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^WHITE%^o%^ORANGE%^o"
             "%^BOLD%^%^BLACK%^r%^RESET%^ is covered in %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^. "
             "%^BOLD%^%^CYAN%^Wi%^WHITE%^nd%^CYAN%^ow sl%^WHITE%^i%^CYAN%^ts%^RESET%^ still provide the only light here. East of this "
             "sleeping area is a large empty space with a ladder. Roughly north is what may be a library or study area.\n");
    set_smell("default", "A powerful mix of chemicals.");
    set_listen("default", "Quiet bubbling, whispers, scrapings, screeching, moaning and humming.");

    set_items(([
                   ({ "bunker", "laboratory", "lab" }) : "A whisper asks 'What are you trying to do?'",
                   ({ "windows", "slits", "window slits" }) : "Outside of these jagged roughhewn %^BOLD%^CYAN%^win%^WHITE%^d%^CYAN%^ows"
                   "%^RESET%^ you see sky. Just a glimmer. The %^BOLD%^%^BLACK%^voice%^RESET%^ returns, 'It's almost like looking out of prison "
                   "bars. Suddenly things start to get claustrophobic! You can�t breathe! YOU�RE GOING TO DIE! You need to get out now! To "
                   "freedom! Or maybe you like it here. Weirdo.'",
                   ({ "bed", "cube", "coffin" }) : "This appears to be a %^GREEN%^b%^BOLD%^e%^RESET%^%^GREEN%^d%^RESET%^ of sorts. It has a lid "
                   "that closes and locks from the inside, and its walls seem to be filled with some sort of liquid.",
                   "wardrobe" : "It�s a large and plain looking wooden %^ORANGE%^w%^BOLD%^a%^RESET%^%^ORANGE%^r%^BOLD%^d%^RESET%^%^ORANGE%^r"
                   "%^BOLD%^o%^RESET%^%^ORANGE%^b%^BOLD%^e%^RESET%^, filled with suits of armor and robes. You see that there are many layers of "
                   "clothing and armor. Perhaps you should <enter wardrobe> and see how deep it goes?",
                   ({ "weapon racks", "racks", "weapons" }) : " These are mostly filled with training %^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^e"
                   "%^BOLD%^%^WHITE%^a%^BLACK%^p%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^ns%^RESET%^ of every type. Spears, swords, axes, crossbows, "
                   "bows and many others. Though there are a few real %^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^a%^BLACK%^p%^RESET%^"
                   "%^ORANGE%^o%^BOLD%^%^WHITE%^ns%^RESET%^ here; some axes, hammers, whips and bastard swords. %^BOLD%^%^BLACK%^A whisper "
                   "suggests that 'Maybe you could steal them. Ha ha, of course you can't. Just teasing.'%^RESET%^",
                   "experiments" : "Near the bed seem to be a few temperature sensitive chemical %^BOLD%^%^MAGENTA%^experiments%^RESET%^. "
                   "Boiling beakers and frozen beakers sit there doing strange things. There is also what looks to be some sort of shelled "
                   "creature in a box sitting there. Its shell looks to be regularly scraped.",
                   ({ "wall", "walls" }) : "This section of the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^ look "
                   "the same as elsewhere. Colorful and strange yet boring. %^BOLD%^%^BLACK%^A whisper in your ear says 'Think whoever lives here "
                   "would notice if you drew something on them?'%^RESET%^",
                   "chest" : "A plain %^ORANGE%^c%^BOLD%^h%^RESET%^%^ORANGE%^e%^BOLD%^s%^RESET%^%^ORANGE%^t%^RESET%^, little more than a "
                   "glorified foot locker. Inside is... OH THE HORROR! Codpieces! Other things as well, but CODPIECES! Quick shut it!",
                   ({ "ground", "powder" }) : "The %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ here looks the same as "
                   "everywhere else. A whisper chimes in, 'You probably don't need to <taste> it to be sure.'",
               ]));

    set_exits(([
                   "east"      : ROOMS "lab",
                   "north"     : ROOMS "library",
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
    add_action("taste_fun", "taste");
    add_action("wardrobe_fun", "enter");
    if (userp(TP) && !present("verbiewardxxx", TP)) {
        new(OBJ "verbieward")->move(TP);
    }
}

int taste_fun(string str)
{
    if (!str) {
        return notify_fail("Taste what?");
    }
    if (str == "powder") {
        tell_object(TP, "The whisper was right. Tastes the same as everywhere else. The whisper is also screaming at you, 'I SAID "
                    "YOU DIDN'T NEED TO TASTE IT!'");
        tell_room(ETP, "" + TP->QCN + " tastes the powder and a disembodied voice shouts 'I SAID YOU DIDN'T NEED TO TASTE IT!", TP);
        return 1;
    }
    return 0;
}

int wardrobe_fun(string str)
{
    if (!str) {
        return notify_fail("Enter what?");
    }
    if (str == "wardrobe") {
        tell_object(TP, "Stepping into the %^ORANGE%^w%^BOLD%^a%^RESET%^%^ORANGE%^r%^BOLD%^d%^RESET%^%^ORANGE%^r%^BOLD%^o%^RESET%^"
                    "%^ORANGE%^b%^BOLD%^e%^RESET%^, you notice it seems to be deeper than normal. In fact as you step into the %^ORANGE%^w%^BOLD%^a"
                    "%^RESET%^%^ORANGE%^r%^BOLD%^d%^RESET%^%^ORANGE%^r%^BOLD%^o%^RESET%^%^ORANGE%^b%^BOLD%^e%^RESET%^ you get the sense you are "
                    "entering another world as you pass through layer and layer of armor until... WHAM! You run smack into a wall. Looks like "
                    "whoever owns this %^ORANGE%^w%^BOLD%^a%^RESET%^%^ORANGE%^r%^BOLD%^d%^RESET%^%^ORANGE%^r%^BOLD%^o%^RESET%^%^ORANGE%^b%^BOLD%^e"
                    "%^RESET%^ simply removed and carved out the back to create a sort of walk in closet to fit all of his armor.");
        tell_room(ETP, "" + TP->QCN + " wanders into the surprisingly deep wardrobe, but a moment later you hear a THUMP as " + TP->QS +
                  " finds the back of it quite abruptly.", TP);
        return 1;
    }
    return 0;
}
