#include <std.h>
#include <daemons.h>
#include <move.h>
#include "sil.h"
#include "/d/player_houses/defines.h"

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit "/std/lab";

int searched;
object* dest;
object blocker;
string* owners = ({ "silesse", "vicdaerrysn", "circe" });
string* owners2 = ({ "silesse", "vicdaerrysn", "aunuit", "ryzan", "circe" });

void create()
{
    object ob;
    ::create();
    set_name("Laboratory");
    set_short("Laboratory");
    set_long("%^BOLD%^%^BLACK%^Octagonal in shape, this underground room is large and expansive, and the stone walls are smooth and"
             " seamless.  Hanging from the center of the room is a large %^WHITE%^cry%^CYAN%^st%^WHITE%^al chandelier %^BLACK%^that"
             " %^CYAN%^illu%^RESET%^%^CYAN%^min%^BOLD%^%^CYAN%^ates %^BLACK%^the area with its %^RESET%^%^CYAN%^eerily s%^BOLD%^o%^RESET%^%^CYAN%^ft"
             " %^BOLD%^gl%^RESET%^%^CYAN%^o%^BOLD%^w%^BLACK%^.  In the %^RESET%^%^CYAN%^dim l%^BOLD%^i%^RESET%^%^CYAN%^ght%^BOLD%^%^BLACK%^,"
             " the large %^RESET%^si%^BOLD%^lv%^RESET%^er %^BOLD%^mi%^RESET%^rr%^BOLD%^or %^BLACK%^covering the entirety"
             " of the northern wall %^WHITE%^reflects %^BLACK%^the strange %^RESET%^blind arcade %^BOLD%^%^BLACK%^framing the %^RESET%^bare"
             " st%^BOLD%^%^BLACK%^o%^RESET%^ne %^BOLD%^%^BLACK%^of the southern wall, the unmoving %^RESET%^image %^BOLD%^%^BLACK%^within the"
             " %^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^r surface %^BLACK%^almost mocking its existence.  Upon the walls to either"
             " side of the %^WHITE%^mirror%^BLACK%^, strange %^RESET%^%^MAGENTA%^gl%^BOLD%^o%^RESET%^%^MAGENTA%^wing sy%^BOLD%^mb%^RESET%^%^MAGENTA%^ols"
             " %^BOLD%^%^BLACK%^constantly shift and move as they dance across the %^RESET%^st%^BOLD%^%^BLACK%^o%^RESET%^nes"
             " surfaces%^BOLD%^%^BLACK%^, sometimes forming %^RESET%^%^MAGENTA%^im%^BOLD%^a%^RESET%^%^MAGENTA%^ges %^BOLD%^%^BLACK%^just beyond"
             " your comprehension.  The east and west walls are both occupied by inset"
             " %^RESET%^%^ORANGE%^walnut shelves %^BOLD%^%^BLACK%^filled with %^RESET%^books %^BOLD%^%^BLACK%^covered in a thick layer of"
             " %^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^.  The southern wall is framed by the series of three"
             " %^RESET%^arches %^BOLD%^%^BLACK%^the %^BOLD%^mirror %^RESET%^reflects%^BOLD%^%^BLACK%^.  Sitting to the right of the"
             " three %^RESET%^ar%^BOLD%^%^BLACK%^ch%^RESET%^ways %^BOLD%^%^BLACK%^is a cage wedged beneath the stairway that curls around it before disappearing"
             " into the darkness above.  To the left of the %^RESET%^ar%^BOLD%^%^BLACK%^ch%^RESET%^ways%^BOLD%^%^BLACK%^, a massive brick"
             " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce %^BOLD%^%^BLACK%^is set back within the wall."
             "  On both the right and left side of the"
             " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce%^BOLD%^%^BLACK%^, %^RESET%^st%^BOLD%^o%^RESET%^ne"
             " she%^BOLD%^%^BLACK%^lv%^RESET%^ing %^BOLD%^%^BLACK%^displays various %^WHITE%^crystal beakers%^BLACK%^, most of which are"
             " %^RESET%^empty%^BOLD%^%^BLACK%^, and all of which are covered with dust.  If there ever was worktables or furnishings in this room,"
             " they are long gone now, as the smooth expanse of the bare floor between the walls is devoid of any such thing.%^RESET%^\n");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("teleport proof",  "/daemon/player_housing"->get_phouse_tp_proof("legendary"));//assuming lvl 40, casterlevel 46+ bonus of 20, +random 6 +items
    set_smell("default", "%^MAGENTA%^A strange, but sweet odor assaults your senses.%^RESET%^");
    set_listen("default", "The quiet murmur of bubbling substances and igniting gasses occassionally breaks the silence.");
    set_items(([
                   ({ "chandelier", "crystal chandelier" }) : "%^BOLD%^%^WHITE%^A large, handmade crystal chandelier hangs from the center of the room.  From down here,"
                   " you can only make out that the top canopy has fine %^RESET%^etchings %^BOLD%^of some sort, and while you cannot decipher what they are exactly,"
                   " the way it scatters the %^CYAN%^l%^RESET%^%^CYAN%^i%^BOLD%^ght %^WHITE%^is simply stunning.  Each crystal arm is %^RESET%^spider"
                   " si%^BOLD%^%^BLACK%^l%^RESET%^k %^BOLD%^thin and arranged in tiers that gradually radiate further from the center column the"
                   " further down they go.  Their delicate scrolling curves are balanced by chained beads and hanging pendalogues.  Oddly, there are no candles within"
                   " the candle cups, only small %^RESET%^%^CYAN%^gl%^BOLD%^ow%^RESET%^%^CYAN%^ing %^BOLD%^or%^RESET%^%^CYAN%^b%^BOLD%^s %^WHITE%^that match the"
                   " %^RESET%^%^CYAN%^gl%^BOLD%^ow%^RESET%^%^CYAN%^ing su%^BOLD%^bst%^RESET%^%^CYAN%^ance %^BOLD%^%^WHITE%^that makes the bottom"
                   " %^CYAN%^b%^RESET%^%^CYAN%^a%^BOLD%^ll%^WHITE%^.",
                   ({ "arcade", "blind arcade", "arches", "archways" }) : "%^BOLD%^%^BLACK%^This set of three %^RESET%^ar%^BOLD%^%^BLACK%^chw%^RESET%^ays %^BOLD%^%^BLACK%^spans the"
                   " distance of the entire southern wall, and are made of carved %^RESET%^gra%^BOLD%^ni%^RESET%^te pi%^BOLD%^ll%^RESET%^ars %^BOLD%^%^BLACK%^that support"
                   " dramatic, %^RESET%^c%^BOLD%^%^BLACK%^a%^RESET%^the%^BOLD%^%^BLACK%^%^dr%^RESET%^al%^BOLD%^%^BLACK%^ like %^RESET%^ar%^BOLD%^%^BLACK%^ch%^RESET%^es."
                   "  %^BOLD%^%^BLACK%^While the two outermost %^RESET%^arches %^BOLD%^%^BLACK%^house a single"
                   " %^RESET%^aumbry %^BOLD%^%^BLACK%^that each contain a large urn of some sort, the center %^RESET%^arch %^BOLD%^%^BLACK%^showcases nothing but"
                   " a carved %^WHITE%^g%^RESET%^a%^BOLD%^%^BLACK%^rg%^RESET%^o%^BOLD%^yle %^BLACK%^that claws at its %^RESET%^apex%^BOLD%^%^BLACK%^."
                   " The twisted depiction of the %^RESET%^dog headed creature %^BOLD%^%^BLACK%^with large %^RESET%^wings %^BOLD%^%^BLACK%^appears to be"
                   " climbing over the %^RESET%^ar%^BOLD%^%^BLACK%^ch%^RESET%^way %^BOLD%^%^BLACK%^to escape the wall itself.",
                   ({ "symbols", "glowing symbols" }) : "%^RESET%^%^MAGENTA%^These odd symbols %^BOLD%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^w %^RESET%^%^MAGENTA%^softly against "
                   "the walls on either side of the %^BOLD%^%^WHITE%^mirror%^RESET%^%^MAGENTA%^ gracing the northern wall.  They seem to constantly be moving and shifting "
                   "about in some sort of intricate dance that always hints at an image you can't quite make out.  If only you could reveal what it is they hide..",
                   ({ "walls", "stone walls" }) : "%^BOLD%^%^BLACK%^The stone walls are smooth and seamless, as if they had been carved from a single, giant rock.",
                   "shelves" : "%^BOLD%^%^BLACK%^There are %^RESET%^%^ORANGE%^walnut shelves %^BOLD%^%^BLACK%^on both the east and west walls,"
                   " and %^RESET%^st%^BOLD%^o%^RESET%^ne shelves %^BOLD%^%^BLACK%^on either side of the"
                   " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce.",
                   "walnut shelves" : "%^RESET%^%^ORANGE%^Floor to ceiling walnut shelves are set within both the east and west walls and are filled with hundreds of books"
                   " covered in dust.",
                   "books" : "%^RESET%^Hundreds of books pack the walnut shelves on the eastern and western walls, and appear to be quite old.  Vast amounts of knowledge must"
                   " be stored here",
                   "urns" : "%^RESET%^There are two urns, one in the left aumbry, and one in the right.",
                   "fire" : "%^BOLD%^%^RED%^A warm %^RESET%^%^RED%^f%^YELLOW%^i%^RESET%^%^RED%^re %^BOLD%^cr%^YELLOW%^a%^RED%^ckles in the"
                   " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce.",
                   ({ "left arch", "left archway" }) : "%^BOLD%^%^BLACK%^Slightly smaller than the center archway, this archway is on the left side of the southern wall and houses"
                   " a single aumbry holding a strange urn.",
                   ({ "statues", "angels" }) : "%^BOLD%^%^WHITE%^Large angelic %^RESET%^statues %^BOLD%^stand on either side of the"
                   " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce%^BOLD%^%^WHITE%^ with their %^RESET%^wings %^BOLD%^folded behind"
                   " their backs and their arms stretched towards the ceiling where their %^RESET%^upturned faces %^BOLD%^seem to be pleading with some unseen force.",
                   ({ "right arch", "right archway" }) : "%^BOLD%^%^BLACK%^Slightly smaller than the center archway, this archway is on the right side of the southern wall and"
                   " houses a single aumbry holding a strange urn.",
                   ({ "center arch", "middle arch", "center archway" }) : "%^BOLD%^%^BLACK%^This is the largest of the three %^RESET%^ar%^BOLD%^%^BLACK%^chw%^RESET%^ays"
                   " %^BOLD%^%^BLACK%^that grace the southern wall, but unlike the ones to the left and right of it, this one has no aumbry within it.  Instead, only the"
                   " smooth stone wall rests between its embrace, and a carved %^WHITE%^g%^RESET%^a%^BOLD%^%^BLACK%^rg%^RESET%^o%^BOLD%^yle %^BLACK%^that claws at its "
                   " %^RESET%^apex%^BOLD%^%^BLACK%^ is showcased atop its center.",
                   "left aumbry" : "%^BOLD%^%^BLACK%^The left aumbry is a relief in the center of the wall within the left"
                   " %^RESET%^ar%^BOLD%^%^BLACK%^chw%^RESET%^ay%^BOLD%^%^BLACK%^.  Upon the single shelf it creates, a long urn rests.",
                   "right aumbry" : "%^BOLD%^%^BLACK%^The right aumbry is a relief in the center of the wall within the right"
                   " %^RESET%^ar%^BOLD%^%^BLACK%^chw%^RESET%^ay%^BOLD%^%^BLACK%^.  Upon the single shelf it creates, a long urn rests.",
                   "left urn" : "%^BOLD%^%^WHITE%^Carved of solid ivory, this urn is housed within the left aumbry on the southern wall, and stands about three feet tall."
                   " A small inscription is carved in its surface.",
                   "right urn" : "%^BOLD%^%^WHITE%^Carved of solid ivory, this urn is housed within the right aumbry on the southern wall, and stands about three feet tall."
                   " A small inscription is carved in its surface.",
                   "apex" : "%^BOLD%^%^BLACK%^The apex of the archways is the center, and highest point of the arches.  Only the center archway has anything upon its apex"
                   ", but what it does have is quite strange.   carved %^WHITE%^g%^RESET%^a%^BOLD%^%^BLACK%^rg%^RESET%^o%^BOLD%^yle is showcased atop its center, and appears to"
                   " forever be clawing at it.",
                   ({ "gargoyle", "statue", "creature" }) : "%^BOLD%^With only the front half of the creature carved above the %^BLACK%^apex %^WHITE%^of the center"
                   " %^BLACK%^ar%^RESET%^chw%^BOLD%^%^BLACK%^ay%^WHITE%^, this %^BLACK%^dog-faced creature %^WHITE%^appears to be attempting to escape the wall itself."
                   "  Two of its four muscular arms seem to be grasping the %^RESET%^apex %^BOLD%^of the %^RESET%^ar%^BOLD%^%^BLACK%^c%^RESET%^h%^BOLD%^, while its"
                   " %^RESET%^ex%^BOLD%^%^BLACK%^pans%^RESET%^ive, %^BOLD%^%^BLACK%^ba%^RESET%^tl%^BOLD%^%^BLACK%^ike w%^RESET%^in%^BOLD%^%^BLACK%^gs %^WHITE%^unfurl"
                   " behind it.  Some might recognize this as a Nycaloth.",
                   "cage" : "%^BOLD%^%^BLACK%^Sitting in front of the southwestern wall is a large iron cage wedged beneath the staircase that curls around it."
                   " Five inch thick round bars surround the cage at six inch intervals and are reinforced with cross bars every two feet.  A single iron door stands in"
                   " the center of the cage with an intricate looking lock fastening it in place.",
                   ({ "stairway", "staircase" }) : "%^BOLD%^%^BLACK%^This stairway begins at the front of the iron cage on the southwestern wall, with its first step"
                   " right in front of the door.  It then curls around the cage and hugs the wall as it ascends into the darkness.",
                   "fireplace" : "%^BOLD%^%^BLACK%^A massive brick %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce"
                   " %^BOLD%^%^BLACK%^is set back within the southeastern wall, and is framed by two massive %^RESET%^st%^BOLD%^o%^RESET%^ne statues %^BOLD%^%^BLACK%^of"
                   " %^WHITE%^angels%^BLACK%^ that stand near the %^RESET%^st%^BOLD%^o%^RESET%^ne she%^BOLD%^%^BLACK%^lv%^RESET%^ing %^BOLD%^%^BLACK%^on either side.  Inside the %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce %^BOLD%^%^BLACK%^a heavy black"
                   " %^RESET%^cau%^BOLD%^%^BLACK%^ld%^RESET%^ron %^BOLD%^%^BLACK%^is suspended over the %^RED%^cra%^RESET%^%^RED%^ckl%^BOLD%^ing"
                   " f%^RESET%^%^RED%^i%^BOLD%^re %^BLACK%^by thick %^RESET%^cha%^BOLD%^%^BLACK%^i%^RESET%^ns%^BOLD%^%^BLACK%^, while a collection of"
                   " %^RESET%^candles flicker %^BOLD%^%^BLACK%^and burn on its hearth.",
                   "cauldron" : "A %^BOLD%^%^BLACK%^heavy black cauldron %^RESET%^is suspended over the %^BOLD%^%^RED%^cra%^RESET%^%^RED%^ckl%^BOLD%^ing"
                   " f%^RESET%^%^RED%^i%^BOLD%^re in the %^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce %^RESET%^by thick"
                   " cha%^BOLD%^%^BLACK%^i%^RESET%^ns.  Every once in a while, whatever substance is in there boils up.",
                   ({ "hearth", "candles" }) : "%^BOLD%^%^WHITE%^Around the hearth of the"
                   " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce%^BOLD%^%^WHITE%^, several candles are set out and seem to"
                   " continually burn.  Thick layers of wax pile on the smooth floor at their bases.",
                   "stone shelves" : "On either side of the %^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce%^RESET%^, stone shelves are"
                   " carved into the wall and display a variety of %^BOLD%^crystal beakers%^RESET%^.",
                   ({ "beakers", "crystal beakers" }) : "%^BOLD%^Several crystal beakers are set in the %^RESET%^st%^BOLD%^%^BLACK%^o%^RESET%^ne shelves %^BOLD%^on either side of the"
                   " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce%^BOLD%^%^WHITE%^, most, but not all, of which are empty.",
               ]));
    set_search("fireplace", "The flames are mesmerizing, and you feel a strange urge to immolate yourself.");
    set_door("cagedoor", SIL "cage", "cage", "ivory key");
    set_locked("cagedoor", 1, "lock");
    lock_difficulty("cagedoor",  "/daemon/player_housing"->get_phouse_lock_dc("rare"), "lock");
    set_lock_description("cagedoor", "lock", "The lock is intricate in design and probably not easily picked.");
    (SIL "cage")->set_locked("cagedoor", 1, "lock");
    set_door_description("cagedoor", "%^BOLD%^%^BLACK%^The door is made of the same cold iron as"
                         " the rest of the cage.  Try as you might, you cannot wiggle any of the bars free nor squeeze"
                         " between them.");
    set_string("cagedoor", "open", "%^BOLD%^%^BLACK%^The cage door creaks eerily as it swings open.%^RESET%^\n");
    set_search("urns", (: TO, "search_urns" :));
    searched = 1;
    set_exits(([
                   "cage" : SIL "cage",
                   "up" : SIL "ivorybuilding",
               ]));
    setOwner("vicdaerrysn");
    setLabId("SilHouse");
}

void search_urns()
{
    if (searched <= 0) {
        tell_object(TP, "%^BOLD%^%^BLACK%^You carefully search through both of the urns but find nothing.");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^BLACK%^You carefully move each of the urns before finding a key beneath the left one.");
    tell_room(ETP, "%^BOLD%^%^BLACK%^" + TPQCN + " carefully moves each of the %^RESET%^urns %^BOLD%^%^BLACK%^before finding an %^WHITE%^i%^RESET%^v%^BOLD%^o%^RESET%^r%^BOLD%^y %^RESET%^key %^BOLD%^%^BLACK%^hidden beneath the left one.", TP);
    new(OBJ "ivorykey.c")->move(TO);
    searched--;
    return 1;
}

void reset()
{
    object ob;
    object scry_object;
    ::reset();
    searched = 1;
    if (!present("CageListener")) {
        scry_object = new(OBJ "cagelistener");
        scry_object->set_caster("/d/player_houses/silesse/dungeon.c");
        scry_object->set_target("/d/player_houses/silesse/cage.c");
        scry_object->move(TO);
    }
    if (!present("blockerx111")) {
        blocker = SCRY_D->add_block_scrying(TO);
        if (!objectp(blocker)) {
            tell_room(TO, "%^BOLD%^RED%^Something has gone wrong with "
                      "the scry protection! Please tell Circe.%^RESET%^");
            return;
        }
        blocker->set_block_power("/daemon/player_housing"->get_phouse_scry_proof("legendary"));
    }
    if (!present("fine mirror")) {
        ob = new("/d/magic/obj/mirror");
        ob->set_short("%^BOLD%^%^BLACK%^An %^RESET%^or%^BOLD%^n%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^e %^BOLD%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^r %^RESET%^mi%^BOLD%^%^BLACK%^rr%^RESET%^or");
        ob->set_long("%^BOLD%^%^BLACK%^Spanning the distance from floor to ceiling upon the northern wall, this %^RESET%^mirror %^BOLD%^%^BLACK%^is one of"
                     " the largest you have ever seen.  It's %^RESET%^smooth surface %^BOLD%^%^BLACK%^has been %^WHITE%^polished %^BLACK%^to a %^WHITE%^gle%^RESET%^am%^BOLD%^ing"
                     " she%^RESET%^e%^BOLD%^n %^BLACK%^that allows your %^RESET%^re%^BOLD%^%^BLACK%^fle%^RESET%^ct%^BOLD%^%^BLACK%^i%^RESET%^on %^BOLD%^%^BLACK%^to stare back at"
                     " you in perfect clarity.  Around the %^WHITE%^mi%^RESET%^rr%^BOLD%^or %^BLACK%^is an %^RESET%^intricate si%^BOLD%^lv%^RESET%^er"
                     " %^BOLD%^fra%^RESET%^m%^BOLD%^e %^BLACK%^whose scrolling designs twist into the forms of %^RESET%^de%^BOLD%^%^BLACK%^vi%^RESET%^ls%^BOLD%^%^BLACK%^,"
                     " %^WHITE%^de%^RESET%^m%^BOLD%^%^BLACK%^o%^WHITE%^ns%^BLACK%^, %^WHITE%^d%^BLACK%^r%^WHITE%^a%^RESET%^g%^BOLD%^%^BLACK%^o%^WHITE%^ns%^BLACK%^,"
                     " gna%^RESET%^rl%^BOLD%^%^BLACK%^ed %^RESET%^fo%^BOLD%^%^BLACK%^re%^RESET%^sts%^BOLD%^%^BLACK%^, and %^WHITE%^el%^RESET%^v%^BOLD%^es%^BLACK%^."
                     "  %^RED%^Gl%^RESET%^%^RED%^i%^BOLD%^tt%^RESET%^%^RED%^er%^BOLD%^ing r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^i%^BOLD%^es %^BLACK%^have been inset into the"
                     " %^RESET%^si%^BOLD%^%^BLACK%^lv%^RESET%^er %^BOLD%^%^BLACK%^as the %^RED%^e%^RESET%^%^RED%^ye%^BOLD%^s %^BLACK%^of the"
                     " %^RESET%^de%^BOLD%^%^BLACK%^vi%^RESET%^ls%^BOLD%^%^BLACK%^ and %^WHITE%^de%^RESET%^m%^BOLD%^%^BLACK%^o%^WHITE%^ns%^BLACK%^, whereas"
                     " %^YELLOW%^to%^RESET%^%^ORANGE%^p%^BOLD%^az %^BLACK%^has been used for the %^WHITE%^d%^BLACK%^r%^WHITE%^a%^RESET%^g%^BOLD%^%^BLACK%^o%^WHITE%^ns%^BLACK%^,"
                     " and %^GREEN%^eme%^RESET%^%^GREEN%^ra%^BOLD%^lds %^BLACK%^have been used for the %^GREEN%^e%^RESET%^%^GREEN%^ye%^BOLD%^s %^BLACK%^of the"
                     " %^WHITE%^el%^RESET%^v%^BOLD%^es%^BLACK%^.%^RESET%^");
        ob->move(TO);
    }
    switch (random(6)) {
    case 0:
        tell_room(TO, "%^RESET%^%^CYAN%^The %^BOLD%^s%^RESET%^%^CYAN%^o%^BOLD%^ft gl%^RESET%^%^CYAN%^o%^BOLD%^w %^RESET%^%^CYAN%^of the"
                  " %^BOLD%^%^WHITE%^cry%^CYAN%^st%^WHITE%^al chandelier %^RESET%^%^CYAN%^briefly %^BOLD%^intensifies%^RESET%^%^CYAN%^ to %^BOLD%^b%^RESET%^%^CYAN%^a%^BOLD%^the"
                  " %^RESET%^%^CYAN%^the room in its %^BOLD%^ra%^RESET%^%^CYAN%^dia%^BOLD%^nce%^RESET%^%^CYAN%^.%^RESET%^");
        break;

    case 1:
        tell_room(TO, "%^BOLD%^%^WHITE%^The %^RESET%^mi%^BOLD%^%^BLACK%^rr%^RESET%^or %^BOLD%^catches the movement of the"
                  " %^RESET%^ga%^BOLD%^%^BLACK%^rgo%^RESET%^yle %^BOLD%^in its %^RESET%^re%^BOLD%^fle%^RESET%^ct%^BOLD%^i%^RESET%^on%^BOLD%^.%^RESET%^");
        break;

    case 2:
        tell_room(TO, "%^RESET%^%^RED%^F%^BOLD%^i%^RESET%^%^RED%^re %^BOLD%^spu%^YELLOW%^tt%^RED%^ers %^BOLD%^%^BLACK%^as something"
                  " %^RESET%^bu%^BOLD%^bb%^RESET%^les %^BOLD%^%^BLACK%^over from the heavy cauldron in the"
                  " %^RESET%^%^RED%^f%^RESET%^i%^RED%^re%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^l%^RESET%^a%^RED%^ce%^BOLD%^%^BLACK%^.%^RESET%^");
        break;

    case 3:
        tell_room(TO, "%^RESET%^%^MAGENTA%^The %^BOLD%^gl%^RESET%^%^MAGENTA%^ow%^BOLD%^ing symb%^RESET%^%^MAGENTA%^o%^BOLD%^ls%^RESET%^%^MAGENTA%^ on the walls"
                  " lazily %^BOLD%^sw%^%^RESET%^%^MAGENTA%^i%^BOLD%^rl %^RESET%^%^MAGENTA%^into your own %^RESET%^reflection %^MAGENTA%^before dispersing into meaningless"
                  " trails of %^BOLD%^glo%^RESET%^%^MAGENTA%^w%^BOLD%^ing l%^RESET%^%^MAGENTA%^i%^BOLD%^ght%^RESET%^%^MAGENTA%^.%^RESET%^");
        break;

    case 4..5:
        tell_room(TO, "%^RESET%^%^MAGENTA%^Upon the northeastern wall, the %^BOLD%^im%^RESET%^%^MAGENTA%^a%^BOLD%^ge %^RESET%^%^MAGENTA%^of a"
                  " %^RESET%^do%^BOLD%^%^BLACK%^gfa%^RESET%^ced %^BOLD%^%^BLACK%^de%^RESET%^m%^BOLD%^%^BLACK%^on %^RESET%^%^MAGENTA%^is briefly formed by the"
                  " %^BOLD%^gl%^RESET%^%^MAGENTA%^ow%^BOLD%^ing symb%^RESET%^%^MAGENTA%^o%^BOLD%^ls%^RESET%^%^MAGENTA%^.");
        break;
    }
}

void init()
{
    string myname, myadj;
    ::init();
    add_action("reveal_it", "reveal");
    add_action("abolish_it", "abolish");
    add_action("read", "read");
    add_action("immolate_self", "immolate"); //passage to Vic's room in Aunuit's house
    if (!objectp(TP)) {
        return;
    }
    if (!userp(TP)) {
        return;
    }
    if (TP->query_invis()) {
        return;
    }
    if (sscanf((string)TP->query_short(), "%s, %s", myname, myadj) != 2) {
        myadj = (string)TP->query_short();
    }
    if (member_array(myadj, (string*)SAVE_D->query_array("vic_lab")) == -1) {
        if ((string)TP->query_name() != "vicdaerrysn") {
            SAVE_D->set_value("vic_lab", myadj);
        }
    }
}

int read(string str)
{
    if (!str) {
        return 0;
    }
    if (str == "right urn") {
        write("%^RESET%^%^RED%^Gurlynx");
        return 1;
    } else if (str == "left urn") {
        write("%^RESET%^%^BLUE%^Xynl");
        return 1;
    }
}

int reveal_it(string str)
{
    string* observed, mymessage;
    int i;
    if (!str) {
        return 0;
    }
    if (str != "images") {
        return 0;
    }
    if (!avatarp(TP) && (string)TP->query_name() != "vicdaerrysn") {
        tell_object(TP, "%^BOLD%^%^BLACK%^You try to make sense of the %^CYAN%^gl%^RESET%^%^CYAN%^ow%^BOLD%^ing %^RESET%^%^CYAN%^symbols %^BOLD%^%^BLACK%^on the wall, but cannot%^RESET%^.");
        tell_room(TO, "%^RESET%^%^CYAN%^" + TP->QCN + " turns " + TP->QP + " gaze towards the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and concentrates briefly.", TP);
        return 1;
    }
    observed = ({});
    observed += (string*)SAVE_D->query_array("vic_lab");
    if (!sizeof(observed)) {
        tell_object(TP, "%^RESET%^%^CYAN%^You concentrate upon the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and realize there are no new images to reveal.");
        tell_room(TO, "%^RESET%^%^CYAN%^" + TP->QCN + " turns " + TP->QP + " gaze towards the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and concentrates briefly.", TP);
        return 1;
    }
    mymessage = observed[i];
    for (i = 1; i < sizeof(observed); i++) {
        mymessage += ", ";
        mymessage += observed[i];
    }
    tell_object(TP, "%^RESET%^%^CYAN%^You turn your gaze towards the %^MAGENTA%^symb%^BOLD%^o%^RESET%^%^MAGENTA%^ls %^CYAN%^on the wall and bend the %^MAGENTA%^magic %^CYAN%^to your"
                " will. The %^MAGENTA%^symb%^BOLD%^o%^RESET%^%^MAGENTA%^ls %^RESET%^%^CYAN%^slowly form a series of pictures revealing the images of " + mymessage + ", \nYou know without a second thought that if you wished"
                " to abolish the images from within the %^MAGENTA%^symb%^BOLD%^o%^RESET%^%^MAGENTA%^ls%^CYAN%^, you need only think it.");
    tell_room(TO, "%^RESET%^%^CYAN%^" + TP->QCN + " turns " + TP->QP + " gaze towards the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and concentrates briefly", TP);
    return 1;
}

int abolish_it(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "images") {
        return 0;
    }
    if (!avatarp(TP) && (string)TP->query_name() != "vicdaerrysn") {
        tell_object(TP, "%^RESET%^%^MAGENTA%^There are no images to abolish.");
        tell_room(TO, "%^RESET%^%^CYAN%^" + TP->QCN + " turns " + TP->QP + " gaze towards the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and concentrates briefly", TP);
        return 1;
    }
    if (!sizeof((string*)SAVE_D->query_array("vic_lab"))) {
        tell_object(TP, "%^RESET%^%^MAGENTA%^There are no images to abolish.%^RESET%^");
        tell_room(TO, "%^RESET%^%^CYAN%^" + TP->QCN + " turns " + TP->QP + " gaze towards the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and concentrates briefly.", TP);
        return 1;
    }
    tell_object(TP, "%^RESET%^%^CYAN%^You turn your gaze to the list upon the wall and bend the %^MAGENTA%^magic %^CYAN%^to your will, abolishing all the images it has remembered.");
    tell_room(TO, "%^RESET%^%^CYAN%^" + TP->QCN + " turns " + TP->QP + " gaze towards the %^BOLD%^symbols %^RESET%^%^CYAN%^on the wall and concentrates until they fade.", TP);
    SAVE_D->remove_array("vic_lab");
    return 1;
}

int immolate_self()
{
    int dmg;
    dest = find_object_or_load("/d/player_houses/aunuit/vic_room.c");
    if (!objectp(dest)) {
        return 1;
    }
    if (TP->query_paralyzed() || TP->query_bound() || TP->query_tripped()) {
        tell_object(TP, "You cannot move to get to the fireplace!");
        return 1;
    }
    if (member_array(TP->query_name(), owners2) == -1 && !wizardp(TP)) {
        tell_object(TP, "Gathering your courage, you step into the fireplace "
                    "and feel a moment of panic as your flesh begins to burn!\n"
                    "Your horror grows as your muscles seize at once, leaving you paralyzed!");
        tell_room(TO, "" + TPQCN + " steps into the fire and looks panicked "
                  "as " + TP->QP + " flesh begins to burn!", TP);
        TP->set_paralyzed(100, "The flames consume your flesh as you stand helpless!");
        dmg = (int)TP->query_hp() / 4;
        TP->cause_typed_damage(TP, TP->return_target_limb(), dmg, "fire");
        call_out("move_uninvited", 5 + random(6), TP);
        tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^fl%^YELLOW%^a%^RED%^m"
                  "%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^%^RED%^ in the fireplace "
                  "flare suddenly, dancing fitfully. A %^BOLD%^%^BLACK%^sh%^RESET%^"
                  "%^RED%^a%^BOLD%^%^BLACK%^dow %^RESET%^%^RED%^begins to appear, "
                  "its shape obscured.%^RESET%^");
        return 1;
    }
    tell_object(TP, "%^ORANGE%^You step confidently into the %^RED%^fl%^YELLOW%^"
                "a%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^, which lick at "
                "you harmlessly. With an unspoken command, you feel the world begin to shift.%^RESET%^");
    tell_room(TO, "%^ORANGE%^" + TPQCN + " steps confidently into the %^RED%^fl%^YELLOW%^"
              "a%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^, which lick at " + TP->QO + " "
              "harmlessly. As you watch, the %^RED%^fl%^YELLOW%^"
              "a%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^ flare, "
              "blinding you. When you can see again, " + TPQCN + " is gone!%^RESET%^", TP);
    call_out("move_owner", 1, TP);
    return 1;
}

int move_owner(object obj)
{
    dest = find_object_or_load("/d/player_houses/aunuit/vic_room.c");
    if (!dest) {
        return 1;
    }
    if (!objectp(obj)) {
        return 1;
    }
    tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^fl%^YELLOW%^a%^RED%^m"
              "%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^%^RED%^ in the fireplace flare, "
              "and a shape takes form within before " + TPQCN + " calmly steps out.%^RESET%^", TP);
    TP->move_player(dest);
    tell_object(TP, "%^RESET%^%^RED%^The world stills and the %^BOLD%^fl%^YELLOW%^a%^RED%^m"
                "%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^%^RED%^ dim before you step calmly from "
                "the fireplace.%^RESET%^");
    return 1;
}

int move_uninvited(object obj)
{
    object flame;
    dest = find_object_or_load("/d/player_houses/aunuit/vic_room.c");
    if (!dest) {
        return 1;
    }
    if (!objectp(obj)) {
        return 1;
    }
    tell_object(obj, "%^BOLD%^%^BLACK%^The %^RED%^fl%^YELLOW%^a%^RED%^m"
                "%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^ blind you, and you feel "
                "yourself spinning out of control!%^RESET%^");
    tell_room(TO, "%^BOLD%^%^BLACK%^The %^RED%^fl%^YELLOW%^a%^RED%^m"
              "%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^ flare and dance fitfully, "
              "obscuring " + TPQCN + " from view! When they calm once more, "
              "" + TP->QS + " is gone!%^RESET%^", obj);
    tell_object(obj, "%^RESET%^%^GREEN%^A sickening feeling grows in your "
                "belly as the spinning grows faster.\n%^BOLD%^%^BLACK%^Suddenly, "
                "you land on a solid surface with a thump, looking up to find "
                "yourself in an immaculate bedroom.%^RESET%^");
    tell_room(dest, "%^BOLD%^%^BLACK%^From the flickering %^RED%^fl%^YELLOW%^a%^RED%^m"
              "%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^, " + obj->QCN + " appears, "
              "landing on the floor with a thump!", obj);
    obj->move_player(dest);
    obj->set_paralyzed(0, "You are free from the strange paralysis.");
    flame = new(OBJ "flame.c");
    flame->move(TP);
    return 1;
}
