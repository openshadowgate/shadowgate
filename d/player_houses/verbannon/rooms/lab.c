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
    set_name("Bunker Laboratory");
    set_short("%^BOLD%^%^BLACK%^B%^WHITE%^u%^BLACK%^nker Lab%^WHITE%^o%^BLACK%^ratory%^RESET%^ ");
    set_long("As you descend the %^ORANGE%^ladder%^RESET%^ the chemical odors are extremely strong however you almost don't "
             "notice it as a strong sense of wrongness washes over you. As your eyes adjust to the dimmer light you get a hint as to "
             "the source of the wrongness. This %^ORANGE%^m%^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^s%^ORANGE%^si%^WHITE%^v%^ORANGE%^e "
             "b%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^n%^ORANGE%^ker%^RESET%^ conceals an even more %^CYAN%^massive %^BOLD%^%^WHITE%^la"
             "%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^. This %^BOLD%^%^WHITE%^la%^RESET%^"
             "%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ was clearly not created by anyone who knew "
             "what they were doing. It looks like someone just blasted a giant hole in the mountainside and called it a day. The "
             "%^ORANGE%^g%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^o%^ORANGE%^und%^RESET%^ is covered in an inch of %^BOLD%^%^WHITE%^mu"
             "%^RESET%^%^ORANGE%^lt%^BOLD%^i%^RESET%^%^CYAN%^co%^BOLD%^%^WHITE%^lor%^RESET%^%^ORANGE%^ed %^BOLD%^po%^RESET%^%^CYAN%^wd"
             "%^BOLD%^%^WHITE%^er%^RESET%^ and the %^BOLD%^%^BLACK%^w%^RED%^a%^BLUE%^l%^WHITE%^ls%^RESET%^ are irregular, scorched but "
             "solid, and share the same warped twisted properties of the terrain outside. %^BOLD%^%^CYAN%^Sl%^WHITE%^i%^CYAN%^ts%^RESET%^ "
             "near the ceiling provide light and ventilation. A %^ORANGE%^ladder%^RESET%^ is against the wall and leads back topside and "
             "various %^BOLD%^%^MAGENTA%^experiments%^RESET%^ lay scattered throughout the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b"
             "%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^. There is nothing else of note in this section "
             "of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^. To "
             "the west looks to be some sort of large rectangular cube. To the northwest looks to be some sort of makeshift study "
             "and library. To the north hanging meat suggests a kitchen area. To the northeast and east seems to be the lab proper "
             "though %^BOLD%^%^MAGENTA%^experiments%^RESET%^ are spread throughout the whole %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b"
             "%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^, making the distinction a little moot.\n");
    set_smell("default", "A powerful mix of chemicals.");
    set_listen("default", "Quiet bubbling, whispers, scrapings, screeching, moaning and humming.");

    set_items(([
                   "ladder" : "This %^ORANGE%^ladder%^RESET%^ is bolted to the southern wall and leads up to a trapdoor that leads outside. "
                   "The trapdoor could be easily moved, if you wished to <lift trapdoor> or <lower trapdoor>. A winch and pulley system hangs near "
                   "the ladder so that large items may be raised and lowered in and out of the lab.",
                   ({ "bunker", "lab", "laboratory" }) : "You�re standing in it.",
                   ({ "ground", "powder" }) : "The %^ORANGE%^g%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^o%^ORANGE%^und%^RESET%^ is carpeted in a "
                   "thick layer of %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^. The %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd"
                   "%^BOLD%^%^WHITE%^er%^RESET%^ glistens with many %^MAGENTA%^c%^ORANGE%^o%^BOLD%^%^WHITE%^l%^RESET%^%^CYAN%^o%^BOLD%^%^YELLOW%^r"
                   "%^WHITE%^s%^RESET%^ suggesting that the %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ may be made up of "
                   "a number of different things. %^BOLD%^%^BLACK%^Whispers%^RESET%^ reach you, saying 'You should taste it and find out exactly "
                   "what. Really, what's the worst that could happen? Instant death?'",
                   ({ "walls", "wall" }) : "Rough, jagged and in some places glassy as if dug by hot explosions. It shares the property of "
                   "discoloration and warping as the trees and ground outside.",
                   ({ "slits", "windows" }) : "These rough ventilation %^BOLD%^%^CYAN%^win%^WHITE%^d%^CYAN%^ows%^RESET%^ look to have been "
                   "quite literally punched out. The edges are so jagged that trying to climb out them even if you were small enough to "
                   "would surely eviscerate anyone. That�s not a good thing. Also runes drawn around each %^BOLD%^%^CYAN%^win%^WHITE%^d"
                   "%^CYAN%^ow%^RESET%^ suggests there may be additional defenses to prevent entry that way.",
                   "experiments" : "%^BOLD%^%^MAGENTA%^Experiments%^RESET%^ cover the whole of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b"
                   "%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ though this particular section seems to be kept "
                   "purposefully clean and clear. With only a single cracked broken %^BOLD%^%^BLACK%^ca%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^ld"
                   "%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^on%^RESET%^ off the side waiting for removal.",
                   "cauldron" : "The %^BOLD%^%^BLACK%^ca%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^ld%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^on%^RESET%^ "
                   "has a crack running down its side. And whispers seem to echo from within, listening you can barely make out 'Why... is six... "
                   "afraid of seven? Because seven... eight... nine. Ha ha... ha.'",
               ]));

    set_exits(([
                   "west"      : ROOMS "sleeping",
                   "northwest" : ROOMS "library",
                   "north"     : ROOMS "kitchen",
                   "northeast" : ROOMS "cluttered",
                   "east"      : ROOMS "workarea",
               ]));
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary")); // same strength from Aunuit's house
}

void reset()
{
    object secondroom;
    ::reset();
    secondroom = find_object_or_load(ROOMS + "precipice");
    if (member_array("ladder", TO->query_exits()) != -1) {
        remove_exit("ladder");
        tell_room(TO, "The trap door slides closed.");
        if (member_array("ladder", secondroom->query_exits()) != -1) {
            secondroom->remove_exit("ladder");
            tell_room(secondroom, "The trap door slides closed.");
        }
    }
    if (!present("blockerx111")) { // again proof strength per Aunuit's
        blocker = SCRY_D->add_block_scrying(TO);
        if (!objectp(blocker)) {
            tell_room(TO, "Something has gone wrong with the scry protection! Please tell Circe or Nienne.");
            return;
        }
        blocker->set_block_power("/daemon/player_housing"-> "/daemon/player_housing"->get_phouse_scry_proof("legendary"));
    }
}

void init()
{
    ::init();
    add_action("lift_fun", "lift");
    add_action("lower_fun", "lower");
    add_action("taste_fun", "taste");
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
        tell_object(TP, "...It tastes very salty, among other things.");
        tell_room(ETP, "" + TP->QCN + " tastes the powder and makes a face.", TP);
        return 1;
    }
    return 0;
}

int lift_fun(string str)
{
    object secondroom;
    secondroom = find_object_or_load(ROOMS + "precipice");
    if (!str) {
        return notify_fail("What are you trying to lift?");
    }
    if (str != "trapdoor") {
        return notify_fail("You can't lift that.");
    }
    if (member_array("ladder", TO->query_exits()) != -1) {
        return notify_fail("It's already open!");
    }
    tell_object(TP, "You push the trap door up and open.");
    tell_room(ETP, "" + TP->QCN + " lifts the trap door up and open.", TP);
    add_exit(ROOMS + "precipice", "ladder");
    if (member_array("ladder", secondroom->query_exits()) == -1) {
        secondroom->add_exit(ROOMS + "lab", "ladder");
        tell_room(secondroom, "The trap door lifts, revealing a ladder into the bunker.");
    }
    return 1;
}

int lower_fun(string str)
{
    object secondroom;
    secondroom = find_object_or_load(ROOMS + "precipice");
    if (!str) {
        return notify_fail("What are you trying to lower?");
    }
    if (str != "trapdoor") {
        return notify_fail("You can't lower that.");
    }
    if (member_array("ladder", TO->query_exits()) == -1) {
        return notify_fail("It's already shut!");
    }
    tell_object(TP, "You pull the trap door back down.");
    tell_room(ETP, "" + TP->QCN + " pulls the trap back down.", TP);
    remove_exit("ladder");
    if (member_array("ladder", secondroom->query_exits()) != -1) {
        secondroom->remove_exit("ladder");
        tell_room(secondroom, "The trap door slides closed.");
    }
    return 1;
}
