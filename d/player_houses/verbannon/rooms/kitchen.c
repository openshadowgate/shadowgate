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
    set_property("light", 2);
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_name("Kitchen area within a fortified laboratory");
    set_short("%^RED%^K%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^c%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^n"
              "%^RESET%^ area within a fortified %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^");
    set_long("This northern section of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t"
             "%^BOLD%^%^WHITE%^ory%^RESET%^ is dominated by a large amount of hanging %^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a"
             "%^BOLD%^%^BLACK%^t%^RESET%^. You have to push aside %^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^ "
             "to walk anywhere in this section of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t"
             "%^BOLD%^%^WHITE%^ory%^RESET%^. %^ORANGE%^Cr%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s"
             "%^RESET%^ of other %^GREEN%^f%^RED%^o%^ORANGE%^o%^GREEN%^d%^RED%^s%^ORANGE%^t%^GREEN%^u%^RED%^f%^ORANGE%^f%^GREEN%^s%^RESET%^ "
             "are shoved against the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^. And an %^BOLD%^%^BLACK%^iron "
             "table%^RESET%^, covered with various %^BOLD%^%^BLACK%^ut%^WHITE%^e%^BLACK%^ns%^WHITE%^i%^BLACK%^ls%^RESET%^, sits in the very "
             "center devoid of any accompanying chairs. Positioned off to the side are three %^ORANGE%^barrels%^RESET%^ of %^BOLD%^%^BLUE%^d"
             "%^GREEN%^r%^MAGENTA%^i%^GREEN%^n%^BLUE%^k%^RESET%^. The %^ORANGE%^barrels%^RESET%^ sit on top of a small %^ORANGE%^cu%^BOLD%^p"
             "%^RESET%^%^ORANGE%^bo%^BOLD%^a%^RESET%^%^ORANGE%^rd%^RESET%^ that holds the %^BOLD%^%^WHITE%^di%^RESET%^%^ORANGE%^s"
             "%^BOLD%^%^WHITE%^hes%^RESET%^. Rolled up and tucked under the %^BOLD%^%^BLACK%^table%^RESET%^ is a large '%^BOLD%^%^BLUE%^w"
             "%^GREEN%^a%^RESET%^%^ORANGE%^r %^BOLD%^%^BLUE%^m%^GREEN%^a%^RESET%^%^ORANGE%^p%^RESET%^' and a %^RED%^c%^ORANGE%^h%^RED%^e"
             "%^ORANGE%^s%^RED%^t%^RESET%^ of %^BOLD%^%^YELLOW%^fi%^RESET%^%^RED%^g%^BOLD%^%^YELLOW%^ur%^RESET%^%^ORANGE%^i"
             "%^BOLD%^%^YELLOW%^ne%^BLACK%^s%^RESET%^. Tacked to the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^ "
             "is more %^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^ and some hanging starches. And for some reason "
             "there are %^BOLD%^%^MAGENTA%^experiments%^RESET%^ here in the %^RED%^k%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^c"
             "%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^n%^RESET%^ area, also something is peering in through the "
             "%^BOLD%^%^CYAN%^win%^WHITE%^d%^CYAN%^ows%^RESET%^ here.\n");
    set_smell("default", "The smell of meat overpowers all else.");
    set_listen("default", "Quiet bubbling, whispers, scrapings, screeching, moaning and humming.");

    set_items(([
                   ({ "lab", "laboratory", "bunker", "kitchen" }) : "%^BOLD%^%^BLACK%^Whispers %^RESET%^drift around you, 'There is nothing left "
                   "to look at! You've already looked at the whole thing when you walked in here! What do you want from me! I have given you all I "
                   "can! I can't take it anymore! Screw you! SCREW YOU TO HELL! Jerk!' The whispers seem to flee sobbing. Also you see nothing "
                   "previously unnoticed in the laboratory.",
                   ({ "meat", "hanging meat" }) : "All the %^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^ is either "
                   "dried, salted, smoked or a combination of those three. It looks like something you might find in an army ration. Great stuff, "
                   "you can either eat it yourself or use it to kill your enemy. If you are very hungry you might be able to <take jerky> and "
                   "munch on some of this %^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^t%^RESET%^.",
                   ({ "crates", "foodstuffs", "food", "wall" }) : "There are %^ORANGE%^cr%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e"
                   "%^RESET%^%^ORANGE%^s%^RESET%^ here full of salted, cracked and dry biscuits, dried vegetables, salted vegetables, smoked "
                   "vegetables, canned slop and other assorted goodies. Hanging on the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l"
                   "%^BOLD%^%^BLUE%^ls%^RESET%^ are strips of jerky and starches like potatoes as well as carrots and onions which can't be stored "
                   "in a %^ORANGE%^cr%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e%^RESET%^ for long. On the %^ORANGE%^cr"
                   "%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^ is the symbol of Tempus, no surprise "
                   "looks like everything here could have come straight from a Tempusian mess hall. Along the top of the %^ORANGE%^cr"
                   "%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^ are some magic runes that do who knows "
                   "what. If you are hungry you might be able to <produce rations> and get some of that military goodness.",
                   ({ "table", "iron table", "utensils" }) : "Here is a large and simple %^BOLD%^%^BLACK%^iron table%^RESET%^ with various "
                   "knives, forks, spoons and other %^BOLD%^%^BLACK%^ut%^WHITE%^e%^BLACK%^ns%^WHITE%^i%^BLACK%^ls%^RESET%^ scattered over it. "
                   "The %^BOLD%^%^BLACK%^table%^RESET%^ is slick and damp with something. Probably something very gross so I suppose that means "
                   "you are going to taste it. No?... that's disappointing.",
                   ({ "barrels", "drink" }) : "Here are three %^ORANGE%^barrels%^RESET%^ inscribed with both many magic runes and the symbols "
                   "of Tempus. Each is also labeled. First there is '%^BOLD%^%^BLUE%^water'%^RESET%^, always a crowd pleaser. Then there is '"
                   "%^BOLD%^%^GREEN%^concentrated lime juice%^RESET%^' well you know, a glass of lime a day keeps the scurvy away. And lastly "
                   "there is one simply titled '%^BOLD%^%^MAGENTA%^energy drink%^RESET%^'. Well that sounds boring. If you're thirsty I'm sure "
                   "whoever owns this %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ "
                   "won't mind if you pour yourself a %^BOLD%^%^BLUE%^d%^GREEN%^r%^MAGENTA%^i%^GREEN%^n%^BLUE%^k%^RESET%^.. Just <pour drink of "
                   "water/lime/energy>.",
                   ({ "cupboard", "dishes" }) : "A %^ORANGE%^cu%^BOLD%^p%^RESET%^%^ORANGE%^bo%^BOLD%^a%^RESET%^%^ORANGE%^rd%^RESET%^ full of "
                   "neatly stacked %^BOLD%^%^WHITE%^di%^RESET%^%^ORANGE%^s%^BOLD%^%^WHITE%^hes%^RESET%^! Quick blunt the knives and bend the forks"
                   "! Crack the cups and smash the plates! Cause that's what whoever lives here hates! No, you're right, he's probably a slob that "
                   "won't care.",
                   ({ "warmap", "map", "chest", "figurines" }) : "Apparently the %^RED%^k%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^c"
                   "%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^n%^RESET%^ can double as a war room in a pinch. There is a large "
                   "%^BOLD%^%^BLUE%^w%^GREEN%^a%^RESET%^%^ORANGE%^r %^BOLD%^%^BLUE%^m%^GREEN%^a%^RESET%^%^ORANGE%^p%^RESET%^ here of this entire "
                   "hemisphere stretching from the wildlands, all the way to and encompassing the continent of danger. South to the Tsarven "
                   "empire and north beyond the furthest explored reaches. On the back of this %^BOLD%^%^BLUE%^w%^GREEN%^a%^RESET%^%^ORANGE%^r "
                   "%^BOLD%^%^BLUE%^m%^GREEN%^a%^RESET%^%^ORANGE%^p%^RESET%^ lies even some rough maps of various planes that touch directly with "
                   "this one. Inside the %^RED%^c%^ORANGE%^h%^RED%^e%^ORANGE%^s%^RED%^t%^RESET%^ are numerous %^BOLD%^%^YELLOW%^fi%^RESET%^%^RED%^g"
                   "%^BOLD%^%^YELLOW%^ur%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ne%^BLACK%^s%^RESET%^ that represent light infantry, heavy infantry, "
                   "ranged infantry, mounted archers, cavalry, heavy cavalry, scouts, various artillery pieces, demons, devils, angels, and "
                   "assortment of other pieces to represent unique unit types possessed by various races. This is either meant for war planning or "
                   "this guy is a serious 'bard'.",
                   ({ "experiments" }) : "Along the ground and pushed to the side are various cauldrons and pots with bubbling fluids inside "
                   "and magic components sitting against them. Probably unfinished potion %^BOLD%^%^MAGENTA%^experiments%^RESET%^ or at least you "
                   "hope these are potion %^BOLD%^%^MAGENTA%^experiments%^RESET%^. Otherwise it means whoever lives here is seasoning soups with "
                   "bat guano. Ew.",
                   ({ "windows", "window slits", "window", "slits" }) : "A fox is smelling the %^RED%^m%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a"
                   "%^BOLD%^%^BLACK%^ts%^RESET%^ and pawing at the %^BOLD%^%^CYAN%^wi%^WHITE%^nd%^CYAN%^ow%^RESET%^ trying to get in. But it "
                   "looks like something is holding him back. If you can't guess that something is magic then... hello I have some beachfront "
                   "property in Tabor I would like to sell you. It's a real steal.",
                   ({ "powder", "ground", "floor" }) : "%^BOLD%^%^BLACK%^The whispers speak...%^RESET%^ 'All this food around here and you still "
                   "insist on trying to <lick> the mysterious %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ off the floor. "
                   "What is wrong with you!? Don't tell me you have no intention on eating this %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd"
                   "%^BOLD%^%^WHITE%^er%^RESET%^. I know you!'",
               ]));

    set_exits(([
                   "southwest" : ROOMS "library",
                   "south"     : ROOMS "lab",
                   "southeast" : ROOMS "cluttered",
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
        blocker->set_block_power("/daemon/player_housing"-> "/daemon/player_housing"->get_phouse_scry_proof("legendary"));
    }
}

void init()
{
    ::init();
    add_action("drinks_fun", "pour");
    add_action("food1_fun", "take");
    add_action("food2_fun", "produce");
    add_action("taste_fun", "lick");
    if (userp(TP) && !present("verbiewardxxx", TP)) {
        new(OBJ "verbieward")->move(TP);
    }
}

int taste_fun(string str)
{
    if (!str) {
        return notify_fail("Lick what?");
    }
    if (str == "powder") {
        tell_object(TP, "The same real saltiness as before mixed in with some chili powder, paprika, oregeno and a dash of horse raddish sauce. Yummy. Also some old meat and veggies, less yummy.");
        tell_room(ETP, "" + TP->QCN + " licks the powder and makes a face.", TP);
        return 1;
    }
    return 0;
}

int drinks_fun(string str)
{
    if (!str) {
        return notify_fail("Pour what?");
    }
    if (str == "drink of water") {
        tell_object(TP, "You reach over and pour yourself some water.");
        tell_room(ETP, "" + TP->QCN + " reaches over and pours a drink.", TP);
        new(OBJ "water")->move(TP);
        return 1;
    }
    if (str == "drink of lime") {
        tell_object(TP, "You reach over and pour yourself some lime juice.");
        tell_room(ETP, "" + TP->QCN + " reaches over and pours a drink.", TP);
        new(OBJ "limejuice")->move(TP);
        return 1;
    }
    if (str == "drink of energy") {
        tell_object(TP, "You reach over and pour yourself some energy drink.");
        tell_room(ETP, "" + TP->QCN + " reaches over and pours a drink.", TP);
        new(OBJ "energydrink")->move(TP);
        return 1;
    }
    return 0;
}

int food1_fun(string str)
{
    if (!str) {
        return notify_fail("Take what?");
    }
    if (str == "jerky") {
        tell_object(TP, "You take a piece of jerky.");
        tell_room(ETP, "" + TP->QCN + " takes a piece of jerky.", TP);
        new(OBJ "jerky")->move(TP);
        return 1;
    }
    return 0;
}

int food2_fun(string str)
{
    if (!str) {
        return notify_fail("Produce what?");
    }
    if (str == "rations") {
        tell_object(TP, "You produce some rations from a crate.");
        tell_room(ETP, "" + TP->QCN + " produces some rations from a crate.", TP);
        new(OBJ "rations")->move(TP);
        return 1;
    }
    return 0;
}
