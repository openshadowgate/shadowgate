
//Coded by ~Circe~ 7/24/13
//Edited by Tsera 6/9/14


#include <std.h>
#include "aunuit.h"
#include <daemons.h>

inherit "/std/temple";

#define SCRY_D "/daemon/ic_scry_locate_d"
object blocker;


void create()
{
    ::create();


    set_travel(PAVED_ROAD);
    set_terrain(BUILT_TUNNEL);
    set_light(1);
    set_indoors(1);
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary")); //assuming lvl 40, casterlevel 46+ bonus of 20, +random 9

    set_name("Halls of Silver");
    set_short("%^BOLD%^%^WHITE%^Halls of Silver%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This magnificent chamber is not something you"
             " would expect to stumble upon in the bowels of the %^RESET%^%^ORANGE%^earth%^BOLD%^%^BLACK%^."
             " The stone walls are smooth and gla%^CYAN%^s%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^y climbing"
             " to a domed ceiling both of which display %^CYAN%^gl%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^wing"
             " celest%^ORANGE%^i%^CYAN%^al b%^WHITE%^o%^CYAN%^dies %^BLACK%^with the %^WHITE%^brilliance"
             " %^BLACK%^of a %^WHITE%^full m%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^o%^WHITE%^n %^BLACK%^at"
             " their center.  The outer circle of the room is made up of descending stone shelves, each"
             " ring adorned with thick %^WHITE%^cushions%^BLACK%^ for sitting and reclining. At the center"
             " of the room surrounded by a shallow moat of luminesce"
             " %^CYAN%^cr%^RESET%^%^CYAN%^y%^BOLD%^%^CYAN%^st%^WHITE%^a%^CYAN%^lline"
             " wat%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^r %^BLACK%^is a raised dais. Upon the dais,"
             "  surrounded by four stone columns and two drac%^WHITE%^o%^BLACK%^nic sentinels, is"
             " a black marble altar chased in %^RESET%^silver %^BOLD%^%^BLACK%^and dotted with"
             " m%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^o%^BLACK%^nst%^WHITE%^o%^BLACK%^nes. Presiding"
             " over the altar is a tall statue of a beautiful %^BLUE%^dark elven woman %^BLACK%^that"
             " appears to be in the midst of dance with a long %^RESET%^blade %^BOLD%^%^BLACK%^held"
             " over her head. Two paths of floating st%^RESET%^o%^BOLD%^%^BLACK%^nes cross the central"
             " %^CYAN%^moat %^BLACK%^one leading to a corridor that cuts through the raised seating to"
             " the east and the other to the stairs that ascend the various levels of shelving to the"
             " upper wings of the palace. %^RESET%^\n");

    set_smell("default", "%^RESET%^%^CYAN%^The air is thick with the heady scent of incense.%^RESET%^");
    set_listen("default", "%^BOLD%^%^BLACK%^Whispers seem to emanate from within the shadows.%^RESET%^");

    set_temple("lysara");
    set_items(([
                   ({ "walls", "ceiling", "moon" }) : "%^BOLD%^%^BLACK%^Looking on the surroundings is"
                   " truly awe inspiring as the walls are covered entirely by accurate depictions of the"
                   " %^CYAN%^celest%^ORANGE%^i%^CYAN%^al b%^WHITE%^o%^CYAN%^dies %^BLACK%^and"
                   " %^ORANGE%^constellations %^BLACK%^one would expect to see in the %^BLUE%^sky"
                   " %^BLACK%^above. All glow with a %^RESET%^%^CYAN%^soft blue light %^BOLD%^%^BLACK%^and"
                   " %^CYAN%^pul%^RESET%^%^CYAN%^s%^BOLD%^%^CYAN%^e %^BLACK%^much like the"
                   " %^WHITE%^t%^ORANGE%^w%^WHITE%^inkl%^CYAN%^i%^WHITE%^ng %^BLACK%^of true"
                   " %^ORANGE%^stars%^BLACK%^. At the center of the domed ceiling shedding its brilliant"
                   " %^RESET%^silver light %^BOLD%^%^BLACK%^on the room is a depiction of the %^WHITE%^full"
                   " m%^CYAN%^o%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^n %^BLACK%^in all its splendor. Looking upon"
                   " it one cannot help but feel a sense of %^BLUE%^deep comfort %^BLACK%^wash over them.%^RESET%^",
                   ({ "shelves", "seating", "cushions" }) : "%^BOLD%^%^BLACK%^The descending platforms of"
                   " seating around the dais are fully ten feet wide and generously covered with thick"
                   " p%^CYAN%^a%^BLUE%^t%^BLACK%^t%^WHITE%^e%^RESET%^r%^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^"
                   "e%^BOLD%^%^BLACK%^d cushions of%^WHITE%^ white%^BLACK%^, black, %^BLUE%^blue %^BLACK%^and"
                   " %^RESET%^silver%^BOLD%^%^BLACK%^.%^RESET%^",
                   ({ "dais", "column", "dragon", "dragons", "sentinels" }) : "%^BOLD%^%^BLACK%^Rising out"
                   " of the %^CYAN%^water %^BLACK%^in the center of the chamber, this circular platform"
                   " houses four beautifully carved marble pillars set with large m%^RESET%^%^CYAN%^o%^BOLD%^"
                   "%^CYAN%^o%^BLACK%^nst%^WHITE%^o%^BLACK%^nes and inscribed with the charge of %^WHITE%^"
                   "Eilistraee%^BLACK%^. On opposite sides of the platform two draconic sentinels stand,"
                   " one carved of beautiful %^WHITE%^white m%^RESET%^a%^BOLD%^%^WHITE%^rble %^BLACK%^with"
                   " eyes of %^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by %^BLACK%^and horns capped in %^ORANGE%^"
                   "gold %^BLACK%^while the other is black marble with eyes of %^BLUE%^s%^CYAN%^a"
                   "%^RESET%^%^CYAN%^p%^BLUE%^p%^CYAN%^h%^BOLD%^%^CYAN%^i%^BLUE%^re %^BLACK%^and horns capped in"
                   " %^RESET%^silver%^BOLD%^%^BLACK%^. Both dragons heads are bowed toward the central"
                   " statue in a subservient manner.%^RESET%^",
                   ({ "altar", "statue", "eilistraee" }) : "%^BOLD%^%^BLACK%^The centerpiece of the room,"
                   " this beautiful altar is a smooth block of black marble framed in"
                   " %^RESET%^m%^BOLD%^%^CYAN%^o%^RESET%^lten sil%^BOLD%^%^BLACK%^v%^RESET%^er"
                   " %^BOLD%^%^BLACK%^that flows about it like ve%^RESET%^i%^BOLD%^%^BLACK%^ns on"
                   " a living thing. Brilliant m%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^o%^BLACK%^nst"
                   "%^WHITE%^o%^BLACK%^nes stand like %^BLUE%^islands %^BLACK%^within the streams"
                   " of %^RESET%^silver %^BOLD%^%^BLACK%^flowing about the altar and ring the bowl se"
                   "t in the top for offerings to be placed. Presiding over the altar itself stands a"
                   " glorious effigy of a tall nude female %^BLUE%^dark elf %^BLACK%^in the midst of"
                   " dance. One long leg is curved as if in mid leap while the other stretches to the"
                   " floor somehow balanced on the tips of its toes. Flowing down around her perfect form"
                   " are riv%^WHITE%^u%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^ts of liquid"
                   " %^RESET%^sil%^BOLD%^%^BLACK%^v%^RESET%^er h%^BOLD%^%^WHITE%^a%^RESET%^ir%^BOLD%^%^BLACK%^"
                   ", their light giving her dark body a %^CYAN%^radiant aura%^BLACK%^. One shapely arm is"
                   " held above her head and in its grasp is a bastard sword of finest"
                   " %^WHITE%^mithr%^CYAN%^i%^WHITE%^l%^BLACK%^, its blade seeming to %^CYAN%^glow"
                   " %^BLACK%^with the light of the m%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^o%^BLACK%^n.%^RESET%^"
               ]));
    set_exits(([
                   "up" : ROOMS "downward_spiral_2",
                   "east" : ROOMS "midnight_river"
               ]));
}

void init()
{
    ::init();
    add_action("read_charge", "read");
}

int read_charge(string str)
{
    if (!str || str != "charge") {
        return 0;
    }
    if (TP->query_blind()) {
        tell_object(TP, "You are blind and cannot read that.");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^CYAN%^Aid the weak, strong, grateful, and churlish alike; be always kind, save in battle with evil. Encourage happiness everywhere; lift hearts with kind words, jests, songs, and merriment. %^BOLD%^%^CYAN%^Learn how to cook game and how best to hunt it. Learn new songs, dances, and ways with weapons, and spices, and recipes, and pass this learning on whenever possible.\n \nLearn how to play, make, and repair musical instruments. Practice music and sword-work. Defend and aid all folk, promoting harmony between the races.\n \n%^BOLD%^%^CYAN%^Strangers are your friends. The homeless must be given shelter from storms, under your own roof if need be. Repay rudeness with kindness. Repay violence with swift violence so that the fewest may be hurt and danger fast removed from the land. \n \n%^BOLD%^%^CYAN%^The faithful must aid Drow who are in distress. If the distressed are fighting with other Drow, the combat is to be stopped with as little bloodshed as possible. So long as the Drow met with are not working evil on others, they are to be aided and given the message of Eilistraee:\n\n%^BOLD%^%^WHITE%^'A rightful place awaits you in the Realms Above, in the Land of the Great Light. Come in peace, and live beneath the sun again, where trees and flowers grow.'%^RESET%^");
    if ((string)TP->query_diety() == "selune" || avatarp(TP)) {
        write("==========================================================================\n%^BOLD%^%^WHITE%^As a follower of Eilistraee ...\n%^RESET%^%^RED%^allied deities are: %^RESET%^ Seldarine and Mystra%^\n%^RESET%^%^RED%^enemy deities are: %^RESET%^Lolth, Vhaeraun, Selvetarm, Kiaransalee, Ghaunadaur\nThis is information only followers of Eilistraee should know.");
        return 1;
    }

    if (!TP->query_invis()) {
        tell_room(TO, "" + TPQCN + " reads the charge.");
    }
    return 1;
}

void reset()
{
    ::reset();
    if (!present("blockerx111")) {
        blocker = SCRY_D->add_block_scrying(TO);
        if (!objectp(blocker)) {
            tell_room(TO, "Something has gone wrong with "
                      "the scry protection! Please tell Circe.");
            return;
        }
        blocker->set_block_power("/daemon/player_housing"->get_phouse_scry_proof("legendary"));
    }
}
