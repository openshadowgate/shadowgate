//Ryzan and Aunuit's House
//Coded by ~Circe~ 4/29/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

int OPEN;
void set_auto_closed();

void create()
{
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(STONE_BUILDING);
    set_name("Dragons Landing");
    set_short("Dragons Landing");
    set_long("%^BOLD%^%^BLACK%^A massive, well-tended %^RESET%^co"
             "%^BOLD%^%^BLACK%^u%^RESET%^rty%^BOLD%^%^WHITE%^a%^RESET%^rd "
             "%^BOLD%^%^BLACK%^sprawls before you surround by a palatial "
             "estate whose sp%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^res rise "
             "toward what appears to be a beautiful %^BLUE%^twi%^BLACK%^l"
             "%^WHITE%^i%^BLACK%^g%^BLUE%^ht s%^WHITE%^k%^BLUE%^y%^BLACK%^. "
             "The path leading from the gate is paved with v%^RESET%^o%^BOLD%^"
             "%^BLACK%^lcan%^WHITE%^i%^BLACK%^c gl%^WHITE%^a%^RESET%^s%^BOLD%^"
             "%^BLACK%^s and leads to a large central circle occupied by a "
             "dr%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^con%^RESET%^i%^BOLD%^"
             "%^BLACK%^c statue. Flanking the path are %^RESET%^%^RED%^br"
             "%^BOLD%^%^RED%^i%^RESET%^%^RED%^ll%^BOLD%^%^RED%^i%^RESET%^"
             "%^MAGENTA%^a%^RED%^nt %^BOLD%^%^BLACK%^l%^RED%^a%^BLACK%^mp "
             "p%^MAGENTA%^o%^BOLD%^%^BLACK%^sts with fl%^RED%^o%^BLACK%^wing "
             "%^RED%^s%^RESET%^%^RED%^c%^BOLD%^%^RED%^arl%^RESET%^%^RED%^e"
             "%^BOLD%^%^RED%^t %^BOLD%^%^BLACK%^drag%^RESET%^o%^BOLD%^%^BLACK%^"
             "n-emblazoned %^RED%^b%^RESET%^%^RED%^a%^BOLD%^%^RED%^nn%^RESET%^"
             "%^RED%^e%^BOLD%^%^RED%^rs%^BLACK%^. %^RESET%^%^ORANGE%^Darkwood "
             "benches %^BOLD%^%^BLACK%^face the statue and provide a perfect "
             "view of the immaculate f%^RESET%^i%^BOLD%^%^WHITE%^e%^BLACK%^lds "
             "on either side of the p%^RESET%^a%^BOLD%^%^BLACK%^th. The field "
             "to the west is occupied by what appears to be a large barracks "
             "and the sound of training can be heard at all hours from behind "
             "the military structure. To the east the field is populated with "
             "well-groomed %^GREEN%^t%^RESET%^%^GREEN%^r%^BOLD%^%^CYAN%^e"
             "%^ORANGE%^e%^GREEN%^s %^BLACK%^that surround a free-standing, "
             "multi-level building that appears to be %^RESET%^%^RED%^residential "
             "apartments%^BOLD%^%^BLACK%^. A c%^WHITE%^o%^BLACK%^bbl%^RESET%^e"
             "%^BOLD%^%^BLACK%^st%^WHITE%^o%^BLACK%^ne walkway leads from the "
             "main path to the living quarters. Behind the apartments the field "
             "gently sl%^RESET%^o%^BOLD%^%^BLACK%^pes down toward a small ca"
             "%^WHITE%^v%^BLACK%^e entrance. The walls of the cavern are lined "
             "with c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^tw%^WHITE%^a%^BLACK%^lks "
             "that travel between elevated %^RESET%^bunkers %^BOLD%^%^BLACK%^that "
             "overlook the yard on all sides. The only entrance to this massive "
             "cavern is barred by great ad%^RESET%^a%^BOLD%^%^BLACK%^man%^WHITE%^t"
             "%^RESET%^i%^BOLD%^%^BLACK%^ne g%^RESET%^a%^BOLD%^%^BLACK%^tes and "
             "under heavy guard.%^RESET%^\n");
    set_smell("default", "%^RESET%^%^CYAN%^The cool air is fresh and clean despite "
              "the subterranean locale.%^RESET%^");
    set_listen("default", "%^BOLD%^%^BLACK%^The sound of metal on metal rings "
               "occasionally to the subtle backdrop of flowing water.%^RESET%^");
    set_exits(([
                   "cave" : ROOMS "pool",
                   "gates" : ROOMS "gates",
                   "north" : ROOMS "maw"
               ]));
    set_door("gates", ROOMS "gates", "gates", "aunuit_key_xyz", "runes"); //There is no key
    set_open("gates", 0);
    set_locked("gates", 1, "runes");
    lock_difficulty("gates",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "runes");
    set_door_description("gates", "%^BOLD%^%^BLACK%^Massive adamantine "
                         "gates have been built into the sheer cavern wall. The %^RESET%^"
                         "%^RED%^maw %^BOLD%^%^BLACK%^of the cavern has been smoothed and "
                         "shaped by humanoid hands so that the man-made m%^WHITE%^e%^BLACK%^"
                         "tal structures that are the gat%^RESET%^e%^BOLD%^%^BLACK%^s fill "
                         "the opening seamlessly. Despite their mammoth size the metal gates "
                         "have been buffed until they sh%^WHITE%^o%^BLACK%^ne like the surface "
                         "of a mi%^RESET%^r%^BOLD%^%^WHITE%^r%^BLACK%^or and a beautiful "
                         "%^RESET%^mural %^BOLD%^%^BLACK%^has been carved into their r%^RESET%^"
                         "e%^BOLD%^%^BLACK%^flect%^WHITE%^i%^RESET%^v%^BOLD%^%^BLACK%^e surfa"
                         "%^WHITE%^c%^BLACK%^e.%^BOLD%^%^WHITE%^ From this side, it looks like "
                         "you could simply <leave> whenver you are ready.%^RESET%^");
    set_lock_description("gates", "runes",
                         "%^BOLD%^%^BLACK%^Inscribed upon the door are various %^CYAN%^r"
                         "%^WHITE%^u%^CYAN%^nes %^BLACK%^of unknown origin.%^RESET%^");
    set_string("gates", "open", "%^BOLD%^%^BLACK%^The great adamantine gates "
               "shriek and groan in protest as they slide slowly open.%^RESET%^");
    set_string("gates", "close", "%^BOLD%^%^BLACK%^The great adamantine gates "
               "shriek and groan in protest as they slide slowly closed.%^RESET%^");
    set_door("palace doors", ROOMS "maw", "north", "aunuit_key_xyz", "runes"); //There is no key
    set_open("palace doors", 0);
    set_locked("palace doors", 1, "lock");
    lock_difficulty("palace doors",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "lock");
    set_door_description("palace doors", "%^BOLD%^%^BLACK%^The entryway of "
                         "the palace is somewhat like entering the %^RED%^maw %^BLACK%^of a "
                         "giant b%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^ast with the doors resting "
                         "at the end of a hall beneath the subsequent floors of the structure. "
                         "Beautiful %^RESET%^%^ORANGE%^Darkwood doors %^BOLD%^%^BLACK%^are "
                         "flanked by elegant p%^RESET%^i%^BOLD%^%^BLACK%^ll%^WHITE%^a%^BLACK%^rs "
                         "that support the massive sp%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^res "
                         "of the pala%^RESET%^c%^BOLD%^%^BLACK%^e. Delicate scr%^RESET%^o%^BOLD%^"
                         "%^BLACK%^llw%^WHITE%^o%^RESET%^r%^BOLD%^%^BLACK%^k has been carved "
                         "around the perimeter of the doors and filled with a %^RESET%^s%^BOLD%^"
                         "%^WHITE%^i%^CYAN%^l%^BLACK%^v%^WHITE%^e%^RESET%^r metal %^BOLD%^"
                         "%^BLACK%^that causes them to appear %^WHITE%^luminescent%^BLACK%^. "
                         "The surface of the rich %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^gleams "
                         "from constant polishing and s%^WHITE%^e%^BLACK%^rpe%^WHITE%^n%^BLACK%^"
                         "t%^RESET%^i%^BOLD%^%^BLACK%^ne ad%^WHITE%^a%^BLACK%^mant%^RESET%^i"
                         "%^BOLD%^%^BLACK%^um %^RESET%^handles %^BOLD%^%^BLACK%^have been "
                         "crafted for each of the %^RESET%^%^ORANGE%^double doors %^BOLD%^"
                         "%^BLACK%^but vigilant %^BLUE%^guards %^BLACK%^patrolling the length "
                         "of the entryway indicate that access to the palace is not a simple thing.%^RESET%^");
    set_search("default", "Whenever you are ready, it looks like you "
               "could simply <leave> through the gates.");
    set_items(([
                   ({ "palace", "estate", "mansion" }) : "%^BOLD%^%^BLACK%^Grand sp%^RESET%^"
                   "i%^BOLD%^%^BLACK%^res rising into the ill%^BLACK%^u%^BLACK%^s"
                   "%^RESET%^o%^BOLD%^%^BLACK%^ry s%^WHITE%^t%^ORANGE%^a%^WHITE%^r"
                   "%^BLUE%^r%^BLACK%^y expanse of the heavens create an intimidating "
                   "silhouette for this palace. Crafted of black st%^RESET%^o%^BOLD%^"
                   "%^BLACK%^ne and %^RESET%^%^ORANGE%^dark wood%^BOLD%^%^BLACK%^, the "
                   "curving architecture is clearly a hybrid of %^RESET%^%^BLUE%^drow"
                   "%^BOLD%^ %^BLACK%^and %^RESET%^%^GREEN%^el%^CYAN%^v%^GREEN%^en "
                   "%^BOLD%^%^BLACK%^designs. Fl%^WHITE%^o%^BLACK%^w%^RESET%^i%^BOLD%^"
                   "%^BLACK%^ng a%^RESET%^r%^BOLD%^%^BLACK%^ch%^WHITE%^e%^BLACK%^s and "
                   "elegant %^RESET%^%^RED%^wind%^MAGENTA%^o%^RED%^ws %^BOLD%^%^BLACK%^"
                   "are prevalent all across its surface with ad%^RESET%^a%^BOLD%^"
                   "%^BLACK%^mant%^WHITE%^i%^BLACK%^ne railed balc%^WHITE%^o%^BLACK%^n"
                   "%^RESET%^i%^BOLD%^%^WHITE%^e%^BLACK%^s set high above overlooking "
                   "the yard. A %^RESET%^wide staircase %^BOLD%^%^BLACK%^leads to the "
                   "front landing where tw%^RESET%^i%^BOLD%^%^BLACK%^n p%^WHITE%^i"
                   "%^BLACK%^ll%^RESET%^a%^BOLD%^%^BLACK%^rs flank a hall leading to "
                   "large %^RESET%^%^ORANGE%^double doors %^BOLD%^%^BLACK%^that serve "
                   "as the main entrance.%^RESET%^",
                   ({ "sky", "ceiling" }) : "%^RESET%^%^BLUE%^Where there should be a ceiling "
                   "of %^ORANGE%^dirt%^BLUE%^ and %^BOLD%^%^BLACK%^stone %^RESET%^%^BLUE%^"
                   "instead is a vast %^BOLD%^%^BLUE%^illusory tapestry %^RESET%^%^BLUE%^of "
                   "the n%^BOLD%^%^WHITE%^i%^BLACK%^g%^RESET%^%^BLUE%^ht s%^BOLD%^%^ORANGE%^k"
                   "%^RESET%^%^BLUE%^y, gl%^WHITE%^i%^BLUE%^tt%^BOLD%^%^ORANGE%^e%^WHITE%^r"
                   "%^ORANGE%^i%^BLUE%^ng with thousands upon thousands of %^WHITE%^s%^BOLD%^"
                   "%^WHITE%^t%^ORANGE%^a%^CYAN%^r%^RESET%^s%^BLUE%^. The %^BOLD%^%^BLACK%^st"
                   "%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^%^BLUE%^walls rise up on all sides "
                   "and disappear into the image as if being swallowed by the%^BOLD%^%^BLACK%^ "
                   "night %^RESET%^%^BLUE%^itself.%^RESET%^",
                   ({ "barracks", "western field" }) : "%^RESET%^%^ORANGE%^The barracks occupy the "
                   "western field and are surrounded by a high %^BOLD%^%^BLACK%^ir%^RESET%^o"
                   "%^BOLD%^%^BLACK%^n fen%^RESET%^c%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^and "
                   "well-manicured %^BOLD%^%^BLACK%^gr%^WHITE%^a%^RESET%^s%^BOLD%^%^BLACK%^s"
                   "%^RESET%^%^ORANGE%^. %^RED%^B%^BOLD%^%^RED%^a%^RESET%^%^RED%^nne%^BOLD%^"
                   "%^RED%^r%^RESET%^%^RED%^s %^ORANGE%^flying the %^RED%^c%^BOLD%^%^BLACK%^o"
                   "%^WHITE%^l%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^r%^WHITE%^s %^RESET%^%^ORANGE%^"
                   "of %^BOLD%^%^RED%^House Rilynath %^RESET%^%^ORANGE%^hang across the large "
                   "gates leading into the %^BOLD%^%^BLACK%^military facility%^RESET%^%^ORANGE%^. "
                   "Beyond the fence can be seen the many training grounds and obstacle courses "
                   "used by %^BLUE%^d%^BOLD%^"
                   "%^BLUE%^a%^RESET%^%^BLUE%^rk el%^BOLD%^%^BLUE%^v%^RESET%^%^BLUE%^en "
                   "%^ORANGE%^soldiers.%^RESET%^",
                   ({ "trees", "eastern field" }) : "%^BOLD%^%^BLACK%^The eastern field is a "
                   "%^WHITE%^stark contrast %^BLACK%^to the utilitarian landscape on the "
                   "western side. While sharing the in%^RESET%^k%^BOLD%^%^BLACK%^y gr"
                   "%^RESET%^a%^BOLD%^%^WHITE%^s%^BLACK%^s carpet the ground slopes and "
                   "rises in r%^WHITE%^o%^BLACK%^ll%^RESET%^i%^BOLD%^%^BLACK%^ng hills with "
                   "unnatural t%^CYAN%^r%^GREEN%^e%^BLUE%^e%^BLACK%^s dotting its landscape. "
                   "The leaves of the trees p%^CYAN%^u%^BLACK%^ls%^GREEN%^a%^BLACK%^te with "
                   "a strange %^BLUE%^ph%^CYAN%^o%^RESET%^%^CYAN%^s%^BOLD%^%^GREEN%^p%^BLUE%^"
                   "h%^RESET%^%^GREEN%^o%^BOLD%^%^CYAN%^r%^ORANGE%^e%^GREEN%^s%^RESET%^%^CYAN%^"
                   "c%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^nt l%^BOLD%^%^WHITE%^i%^CYAN%^g%^RESET%^"
                   "%^GREEN%^ht %^BOLD%^%^BLACK%^that cast flowing s%^WHITE%^ha%^RESET%^d"
                   "%^BOLD%^%^WHITE%^ow%^BLACK%^s across the ground. The dominant feature "
                   "of the field though is the elegant st%^RESET%^o%^BOLD%^%^BLACK%^ne "
                   "building that houses %^RESET%^%^RED%^apartments %^BOLD%^%^BLACK%^for "
                   "well-to-do residents. Behind the tall building is the narrow entrance "
                   "to another cave.%^RESET%^",
                   ({ "banners", "banner" }) : "%^BOLD%^%^BLACK%^The %^RED%^crims%^RESET%^%^RED%^"
                   "o%^BOLD%^%^RED%^n b%^RESET%^%^RED%^a%^BOLD%^%^RED%^nners %^BLACK%^bear "
                   "the crest of %^RESET%^%^RED%^House Rilynath%^BOLD%^%^BLACK%^, which is "
                   "a bla%^RESET%^c%^BOLD%^%^BLACK%^k dragon formed from sh%^BLUE%^a%^BLACK%^"
                   "d%^RESET%^o%^BOLD%^%^BLACK%^w itself, rising from the d%^RESET%^a%^BOLD%^"
                   "%^BLACK%^rkn%^WHITE%^e%^RESET%^s%^BOLD%^%^BLACK%^s with outstretched cl"
                   "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ws and a gaping %^RED%^maw %^BLACK%^to "
                   "r%^RED%^e%^BLACK%^nd whatever foe lay in its path.%^RESET%^",
                   ({ "bunkers", "catwalk" }) : "%^BOLD%^%^BLACK%^Metal c%^RESET%^%^ORANGE%^a"
                   "%^BOLD%^%^BLACK%^tw%^RESET%^a%^BOLD%^%^BLACK%^lks have been secured to "
                   "the ro%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^k w%^RESET%^a%^BOLD%^%^BLACK%^"
                   "lls and allow access to a %^RESET%^pulley system %^BOLD%^%^BLACK%^that "
                   "operates the g%^WHITE%^a%^BLACK%^tes as well as span the distance between "
                   "several%^RESET%^ bunkers %^BOLD%^%^BLACK%^that have been built from the "
                   "st%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^ "
                   "itself. The bunkers provide a secure location for %^RESET%^%^BLUE%^"
                   "archers %^BOLD%^%^BLACK%^to take aim at any insurgents below.%^RESET%^",
                   ({ "statue", "dragon" }) : "%^RESET%^The center of the square is dominated by "
                   "a large %^BOLD%^%^BLACK%^obs%^RESET%^i%^BOLD%^%^BLACK%^d%^WHITE%^i"
                   "%^RESET%^a%^BOLD%^%^BLACK%^n stat%^WHITE%^u%^BLACK%^e %^RESET%^of a "
                   "%^BOLD%^%^BLACK%^dragon %^RESET%^about to take %^CYAN%^flight%^WHITE%^. "
                   "The lower portion of its body is %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^"
                   "%^WHITE%^i%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^d%^RESET%^, its powerful "
                   "%^BOLD%^%^BLACK%^mus%^RESET%^c%^BOLD%^%^BLACK%^les fle%^RESET%^x%^BOLD%^"
                   "%^BLACK%^ed %^RESET%^with the effort of take-off, and its %^BOLD%^%^BLACK%^"
                   "wings %^RESET%^are arched as they gather %^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^"
                   "%^CYAN%^nd %^WHITE%^beneath them. One of its %^RED%^claws %^WHITE%^"
                   "just barely grazes the ground and the other is suspended in the %^BOLD%^"
                   "%^CYAN%^air %^RESET%^before it. The dragon's %^BOLD%^%^BLACK%^h%^RESET%^o"
                   "%^BOLD%^%^BLACK%^rned head %^RESET%^and n%^BOLD%^%^BLACK%^e%^RESET%^ck are "
                   "arched no less elegantly than a %^BOLD%^%^WHITE%^swan's %^RESET%^and its "
                   "sharp %^BOLD%^%^BLACK%^black scales gl%^WHITE%^e%^RESET%^a%^BOLD%^%^BLACK%^m "
                   "%^RESET%^danger%^BOLD%^%^RED%^o%^RESET%^usly. Its open mouth is lined with "
                   "countless ra%^BOLD%^%^WHITE%^z%^RED%^o%^WHITE%^r%^RESET%^-sh%^BOLD%^%^WHITE%^"
                   "a%^RESET%^rp teeth and the statue's skilled craftsman has even detailed a "
                   "%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ptil%^CYAN%^i%^BOLD%^%^GREEN%^"
                   "a%^RESET%^%^GREEN%^n t%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^ng%^CYAN%^u%^GREEN%^"
                   "e %^RESET%^that licks restlessly at the air. At the base of the statue a "
                   "polished %^BOLD%^mithril plaque %^RESET%^is inscribed with elegant elven script.%^RESET%^",
               ]));
    OPEN = 0;
}

void init()
{
    ::init();
    add_action("read_em", "read");
    add_action("leave_em", "leave");
}

int read_em(string str)
{
    if (!str) {
        return 0;
    }
    if (str == "plaque") {
        tell_object(TP, "The plaque reads:\n"
                    "%^BOLD%^%^BLACK%^Out of the depths of despair we have "
                    "risen to reclaim the glory that is ours.%^RESET%^");
        if (!TP->query_invis() && !TP->query_hidden()) {
            tell_room(TO, "" + TPQCN + " seems to be studying the plaque.");
        }
        return 1;
    }
}

int leave_em()
{
    object dest = find_object_or_load("/d/player_houses/aunuit/gates.c");
    tell_object(TP, "As you walk toward the gates, they begin to open.");
    tell_room(TO, "%^RESET%^The mural of the %^BOLD%^%^BLACK%^gate "
              "%^RESET%^begins to %^CYAN%^s%^BOLD%^%^CYAN%^h%^WHITE%^i"
              "%^CYAN%^f%^RESET%^%^CYAN%^t %^RESET%^as the sigil is "
              "presented, the %^BOLD%^%^GREEN%^el%^RESET%^%^GREEN%^v"
              "%^BOLD%^%^GREEN%^en %^RESET%^figures turning to gaze at "
              "you as the %^BOLD%^%^BLACK%^dragon %^RESET%^lowers its "
              "head and opens its great %^RED%^m%^BOLD%^%^RED%^a%^RESET%^"
              "%^RED%^w%^WHITE%^. Within the mouth the surface of the gate "
              "%^CYAN%^r%^BOLD%^%^CYAN%^i%^WHITE%^p%^CYAN%^p%^RESET%^"
              "%^CYAN%^les %^WHITE%^and seems to melt away leaving a "
              "%^BOLD%^%^BLACK%^shadowed path %^RESET%^through the thick "
              "adamantine doors open before you.%^RESET%^");
    set_locked("gates", 0, "runes");
    set_open("gates", 1);
    tell_room(dest, "%^RESET%^The mural of the %^BOLD%^%^BLACK%^gate "
              "%^RESET%^begins to %^CYAN%^s%^BOLD%^%^CYAN%^h%^WHITE%^i"
              "%^CYAN%^f%^RESET%^%^CYAN%^t %^RESET%^as the sigil is "
              "presented, the %^BOLD%^%^GREEN%^el%^RESET%^%^GREEN%^v"
              "%^BOLD%^%^GREEN%^en %^RESET%^figures turning to gaze at "
              "you as the %^BOLD%^%^BLACK%^dragon %^RESET%^lowers its "
              "head and opens its great %^RED%^m%^BOLD%^%^RED%^a%^RESET%^"
              "%^RED%^w%^WHITE%^. Within the mouth the surface of the gate "
              "%^CYAN%^r%^BOLD%^%^CYAN%^i%^WHITE%^p%^CYAN%^p%^RESET%^"
              "%^CYAN%^les %^WHITE%^and seems to melt away leaving a "
              "%^BOLD%^%^BLACK%^shadowed path %^RESET%^through the thick "
              "adamantine doors open before you.%^RESET%^");
    dest->set_locked("gates", 0, "runes");
    dest->set_open("gates", 1);
    call_out("set_auto_closed", 15);
    OPEN = 1;
    return 1;
}

void set_auto_closed()
{
    object dest;
    dest = find_object_or_load("/d/player_houses/aunuit/gates.c");
    tell_room(TO, "%^BOLD%^%^BLACK%^The great %^RED%^j%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^ws %^BLACK%^of the dragon snap %^RESET%^shut "
              "%^BOLD%^%^BLACK%^closing the passage as though it never were. "
              "The creature raises itself up to its former position and the "
              "%^RESET%^%^GREEN%^el%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^en "
              "%^BOLD%^%^BLACK%^figures step back into place beneath its "
              "outstretched wings.%^RESET%^");
    set_locked("gates", 1, "runes");
    set_open("gates", 0);
    tell_room(dest, "%^BOLD%^%^BLACK%^The great %^RED%^j%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^ws %^BLACK%^of the dragon snap %^RESET%^shut "
              "%^BOLD%^%^BLACK%^closing the passage as though it never were. "
              "The creature raises itself up to its former position and the "
              "%^RESET%^%^GREEN%^el%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^en "
              "%^BOLD%^%^BLACK%^figures step back into place beneath its "
              "outstretched wings.%^RESET%^");
    dest->set_locked("gates", 1, "runes");
    dest->set_open("gates", 0);
    OPEN = 0;
    return;
}

void reset()
{
    ::reset();
    switch (random(3)) {
    case 0: tell_room(TO, "%^BOLD%^%^BLACK%^Shouts and the ring of "
                      "clashing metal erupt from a group of soldiers in "
                      "the training yard.%^RESET%^");
        break;

    case 1: tell_room(TO, "%^BOLD%^%^CYAN%^A sudden burst of bright "
                      "silvery light can be seen streaking across the illusory "
                      "night sky. Several elves stop to watch the shooting "
                      "star, letting out appreciative gasps.%^RESET%^");
        break;

    default: tell_room(TO, "%^BOLD%^%^BLUE%^A group of dark elven "
                       "children gallop through the courtyard and "
                       "across the grassy fields laughing and playing "
                       "joyfully.%^RESET%^");
        break;
    }
}
