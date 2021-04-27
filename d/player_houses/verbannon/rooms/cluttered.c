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
    set_name("A very cluttered section of an underground laboratory");
    set_short("A very cluttered section of an underground %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^");
    set_long("This section of the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory"
             "%^RESET%^ looks like it was originally intended for storage but it has been completely overtaken by various "
             "%^BOLD%^%^MAGENTA%^experiments%^RESET%^. Crates full of %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^m%^RESET%^"
             "%^MAGENTA%^p%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^t%^RESET%^"
             "%^MAGENTA%^s%^RESET%^ lay buried beneath %^BOLD%^%^MAGENTA%^experiments%^RESET%^. %^BOLD%^%^BLACK%^Bales of various metal"
             "%^RESET%^ are stacked against the %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^. And one must walk "
             "through a maze of crates here to traverse this section. How whoever uses this %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b"
             "%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ ever reaches his supplies is a mystery. The "
             "%^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ on the %^ORANGE%^g%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^o"
             "%^ORANGE%^und%^RESET%^ here is exceptionally thick. As for the %^BOLD%^%^MAGENTA%^experiments%^RESET%^ themselves they seem to "
             "be the dangerous kind.%^BOLD%^%^BLACK%^ Various items, weapons and equipment%^RESET%^ that just ebb wrongness are scattered "
             "about and %^BOLD%^%^CYAN%^jars%^RESET%^ with screaming %^BOLD%^%^RED%^fa%^YELLOW%^c%^RED%^es%^RESET%^ are stacked into small "
             "mountains. %^BOLD%^%^CYAN%^Wi%^WHITE%^nd%^CYAN%^ow %^CYAN%^sl%^WHITE%^i%^CYAN%^ts%^RESET%^ are set high on the wall providing "
             "the best light.\n");
    set_smell("default", "A powerful mix of chemicals.");
    set_listen("default", "Quiet bubbling, whispers, scrapings, screeching, moaning and humming.");

    set_items(([
                   ({ "lab", "laboratory", "bunker" }) : "You look at the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^"
                   "%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ but the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t"
                   "%^BOLD%^%^WHITE%^ory%^RESET%^ looks at you. Technically, its all the creatures the laboratory.",
                   "experiments" : "Lots of the bubbling chemical type of %^BOLD%^%^MAGENTA%^experiments%^RESET%^, but two "
                   "%^BOLD%^%^MAGENTA%^experiments%^RESET%^ that stand out are piles of %^BOLD%^%^CYAN%^jars%^RESET%^ with %^BOLD%^%^RED%^fa"
                   "%^YELLOW%^c%^RED%^es%^RESET%^ floating inside them and some sort of %^BOLD%^%^MAGENTA%^experiments%^RESET%^ on scattered "
                   "%^BOLD%^%^BLACK%^objects.%^RESET%^",
                   ({ "crates", "bales", "metal", "bales of metal", "components", "wall" }) : "This is mostly a storage area it seems. Crates "
                   "filled with smelly %^BOLD%^%^MAGENTA%^experiments%^RESET%^. Crates full of %^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o"
                   "%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^n"
                   "%^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^s%^RESET%^ and chemicals are stacked everywhere forming a maze of sorts that you need "
                   "to traverse and for some reason bales of both mundane and exotic metals are stacked against the wall.",
                   ({ "powder", "ground" }) : "The %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ on the %^ORANGE%^g"
                   "%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^o%^ORANGE%^und%^RESET%^ here is very thick and has an odd color to it. It seems "
                   "brighter here then otherwhere and darker at the same time. You could probably <taste> it if you dared.",
                   ({ "items", "weapons", "equipment", "objects" }) : "All sorts of %^BOLD%^%^BLACK%^items%^RESET%^ are scattered around here "
                   "with notes attached and many are accompanied by various %^BOLD%^%^MAGENTA%^experiments%^RESET%^. Crates full of "
                   "%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^m%^RESET%^%^MAGENTA%^p%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^n"
                   "%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^s%^RESET%^. You probably can�t understand the "
                   "mumbo jumbo written on the notes but you get the idea that these %^BOLD%^%^BLACK%^objects%^RESET%^ are all cursed and some "
                   "with pretty serious curses that could kill you just for being this close. And they are here simply so the owner of this "
                   "%^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^ can practice removing "
                   "said curses.",
                   "jars" : "At first you think these%^BOLD%^%^CYAN%^ jars%^RESET%^ might be filled with undead but as you gather your "
                   "courage you begin reading the labels attached to them. You find they are actually demons, angels, devils, elementals, fey, "
                   "shadows, abberants and others. You may begin to realize that these are all outsiders stripped of their bodies and imprisoned "
                   "in these %^BOLD%^%^CYAN%^jars%^RESET%^ for some unknown reason. You notice some of the %^BOLD%^%^CYAN%^jars%^RESET%^ have "
                   "multiple entities inside them. One is labeled to have a devil, an angel and a demon within. In this jar and others like it the "
                   "outsiders are clearly in conflict with each other. Occasionally a bolt of light, fire or lightning will shoot out and "
                   "appear to be torn to shreds by an invisible force in the air before said bolt can damage anything. The label on this one "
                   "reads 'Experiment 666777: Attempt to obtain a sustainable controlled conflict between opposed outsiders'.",
                   ({ "window slits", "windows", "slits" }) : "The roughhewn %^BOLD%^%^CYAN%^win%^WHITE%^d%^CYAN%^ows%^RESET%^ are here as well.",
               ]));

    set_exits(([
                   "southwest" : ROOMS "lab",
                   "northwest" : ROOMS "kitchen",
                   "south"     : ROOMS "workarea",
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
        tell_object(TP, "Tasting the %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ your body is suddenly wracked with a sense of both good and evil in conflict.");
        tell_room(ETP, "" + TP->QCN + " tastes the powder and makes a face.", TP);
        return 1;
    }
    return 0;
}
