#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit "/std/lab";

#define SCRY_D "/daemon/ic_scry_locate_d"
object blocker;

void create()
{
    ::create();
    setOwner("verbannon");
    setLabId("verbannon");
    set_property("indoors", 1);
    set_property("light", 2);
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_name("The work area of an underground laboratory");
    set_short("The work area of an underground %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^BOLD%^%^WHITE%^ora%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^ory%^RESET%^");
    set_long("This is clearly the %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b %^RESET%^proper. The %^BOLD%^%^BLACK%^w%^RED%^a%^RESET%^"
             "%^WHITE%^l%^BOLD%^%^BLUE%^l%^RESET%^ is dominated by a large %^BOLD%^%^MAGENTA%^mirror%^RESET%^ and in front of the "
             "%^BOLD%^%^MAGENTA%^mirror%^RESET%^ is a comfortable looking easy %^GREEN%^ch%^BLUE%^ai%^GREEN%^r%^RESET%^ with a footrest. "
             "All around the %^GREEN%^ch%^BLUE%^ai%^GREEN%^r%^RESET%^ are rows upon rows of %^BOLD%^%^BLACK%^tables%^RESET%^ covered with "
             "%^BOLD%^%^MAGENTA%^chemicals, components,%^WHITE%^ papers%^RESET%^ and%^BOLD%^%^WHITE%^ notes%^RESET%^ for the "
             "%^BOLD%^%^MAGENTA%^experiments%^RESET%^ conducted here. The %^ORANGE%^g%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^o%^ORANGE%^und"
             "%^RESET%^ is covered in a thick %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ and %^BOLD%^%^CYAN%^wi"
             "%^WHITE%^nd%^CYAN%^ow sl%^WHITE%^its%^RESET%^ are providing the sole source of light.\n");
    set_smell("default", "A powerful mix of chemicals.");
    set_listen("default", "Quiet bubbling, whispers, scrapings, screeching, moaning and humming.");

    set_items(([
                   ({ "lab", "laboratory", "bunker" }) : "It's a %^BOLD%^%^WHITE%^la%^RESET%^%^CYAN%^b%^RESET%^! It's a %^ORANGE%^b"
                   "%^BOLD%^%^BLACK%^u%^RESET%^%^WHITE%^n%^ORANGE%^ke%^WHITE%^r%^RESET%^! It's a %^ORANGE%^B%^BOLD%^%^BLACK%^U%^RESET%^%^WHITE%^N"
                   "%^ORANGE%^KE%^WHITE%^R%^RESET%^ %^BOLD%^%^WHITE%^LA%^RESET%^%^CYAN%^B%^BOLD%^%^WHITE%^ORA%^RESET%^%^CYAN%^T"
                   "%^BOLD%^%^WHITE%^ORY%^RESET%^!",
                   ({ "wall", "mirror", "chair" }) : "Whispers chime in, 'Well isn't that typical? An easy %^GREEN%^ch%^BLUE%^ai%^GREEN%^r"
                   "%^RESET%^ in front of the scrying %^BOLD%^%^MAGENTA%^mirror%^RESET%^. This mage probably just lounges about all day sipping "
                   "lime juice and chewing on jerky while spying on whomever he wishes without actually having to do anything. Isn't that just the "
                   "worst? In fact, he seemed to have left the %^BOLD%^%^MAGENTA%^mirror%^RESET%^ on. Let us see what oblivious soul he was spying "
                   "on. Hey! This is the New Azha Theater! Nobody ever gets to see them! Because there is a five year waiting list to every "
                   "performance. But this guy just has to tune in with his %^BOLD%^%^MAGENTA%^mirror%^RESET%^ and he gets to see the whole damn "
                   "show! For free! Man, it is good to be a mage.'",
                   ({ "tables", "experiments", "chemicals", "components", "papers" }) : "It seems that nearly all of these %^BOLD%^%^BLACK%^tables"
                   "%^RESET%^ are being used for one single massive %^BOLD%^%^MAGENTA%^experiment%^RESET%^. The %^BOLD%^%^MAGENTA%^components"
                   "%^RESET%^ for this %^BOLD%^%^MAGENTA%^experiment%^RESET%^ are all serious stuff, Divine Essence, Infernal Soul Fragments, true "
                   "threads of the weave and those are just the items whose labels don't wrack you with pain and agony to read. Looking through "
                   "the %^BOLD%^%^WHITE%^notes%^RESET%^ they are all so complex that only the most skilled of abjurationists could read them, "
                   "however one %^BOLD%^%^WHITE%^note%^RESET%^ seems written in plain speech.",
                   ({ "ground", "powder" }) : "The %^BOLD%^%^YELLOW%^po%^RESET%^%^CYAN%^wd%^BOLD%^%^WHITE%^er%^RESET%^ on the %^ORANGE%^g"
                   "%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^o%^ORANGE%^und%^RESET%^ here is very thick and actively crackling. The whispers say 'Wanna "
                   "<taste> this? I didn't think so.'",
                   ({ "windows", "window slits" }) : "With the %^BOLD%^%^CYAN%^win%^WHITE%^d%^CYAN%^ows%^RESET%^ providing the only source of "
                   "light here, how does the mage move around at night?",
                   "note" : ({ "There is a only one note among the papers that seems written in plain speech.", "'This will be my legacy. The "
                               "greatest of Abjurations. A shield for mankind! Wielded by mankind! Against the almighty horrors beyond this realm. For too "
                               "long we have remained weak, dependent on the gods for our protection. Before I pass on to the eternal battle we shall have "
                               "the strength to defend ourselves. No matter the cost.' Signed Verbannon , Arch-Abjurationist.", "common" }),
               ]));

    set_exits(([
                   "west"      : ROOMS "lab",
                   "north"     : ROOMS "cluttered",
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
    if (!present("fine mirror")) {
        new("/d/magic/obj/mirror")->move(TO);
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
        tell_object(TP, "Oddly enough you don't die, and the powder still tastes just salty. A whisper asks 'How did you survive past childhood?'");
        tell_room(ETP, "" + TP->QCN + " tastes the powder and makes a face, as a whisper asks 'How did you survive past childhood?'.", TP);
        return 1;
    }
    return 0;
}
