//Coded by ~Circe~ 7/24/13

#include <std.h>
#include <move.h>
#include "aunuit.h"
#include <daemons.h>

inherit AUNUIT;

string* owners = ({ "silesse", "vicdaerrysn", "circe" });
string* owners2 = ({ "silesse", "vicdaerrysn", "aunuit", "ryzan", "circe" });
string* invited = SAVE_D->query_array("vic_guest_list");

int help_em(string str);
void update();

int red, white, black, bpants, gpants, dress, clothing, wine;
object* dest;
void failure();
void wine_failure();
int move_uninvited(object obj);
int move_owner(object obj);

void create()
{
    ::create();
    set_name("An obsidian bedchamber");
    set_short("%^BOLD%^%^BLACK%^An ob%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^idi" +
              "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n bedchamber%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Crafted from carved ob%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^idi" +
             "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n walls, this bedchamber might seem oppressive " +
             "and dreary if it were not for the sophisticated furnishings and subtle lighting.  " +
             "A permanent spell of %^MAGENTA%^f%^RESET%^%^MAGENTA%^a%^BOLD%^er%^YELLOW%^i%^MAGENTA%^e "
             "f%^RED%^i%^MAGENTA%^re %^BLACK%^webs across the ceiling, " +
             "twinkling like %^CYAN%^stars %^BLACK%^in shades of %^RESET%^%^MAGENTA%^pur%^BOLD%^" +
             "p%^RESET%^%^MAGENTA%^le%^BOLD%^%^BLACK%^, %^MAGENTA%^pink%^BLACK%^, and %^YELLOW%^" +
             "yellow%^BLACK%^, with occasional hints of deeper %^RED%^red%^BLACK%^.  Centered " +
             "beneath the faux stars is an imposing bed with carved %^WHITE%^ivory posts " +
             "%^BLACK%^and %^RED%^crimson sp%^RESET%^%^RED%^i%^BOLD%^der%^RESET%^%^RED%^s" +
             "%^BOLD%^ilk sheets%^BLACK%^.  On the eastern end of the room are a beautiful " +
             "%^WHITE%^ivory %^BLACK%^and %^RESET%^%^RED%^teakwood %^BOLD%^%^BLACK%^wardrobe " +
             "and a coordinating %^RESET%^%^RED%^teak %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^" +
             "copper %^BOLD%^%^BLACK%^washstand, which supports a flawless %^CYAN%^mirror " +
             "%^BLACK%^and a delicate %^WHITE%^ivory vase %^BLACK%^filled with %^RED%^wil" +
             "%^RESET%^%^MAGENTA%^d%^BOLD%^%^RED%^fl%^RESET%^%^RED%^o%^BOLD%^wers%^BLACK%^.  " +
             "%^RESET%^%^ORANGE%^Dark paneling %^BOLD%^%^BLACK%^covers the base of the walls "
             "while overhead in the space between the furniture is an intricate %^RESET%^frieze " +
             "%^BOLD%^%^BLACK%^that encompasses the entirety of the room and seems to tell a " +
             "progressive story, beginning with the southern scene.  The western wall continues " +
             "the artistic theme, showcasing a pictorial carving of dark elves with their arms " +
             "raised high, calling forth powerful %^RESET%^%^RED%^demons %^BOLD%^%^BLACK%^to " +
             "combat a horde.  The end of the frieze occurs on the eastern wall, incorporating the "
             "door to the hallway in its motif. The southwestern corner of the frieze is obscured slightly by " +
             "a %^RESET%^%^RED%^teakwood bookcase %^BOLD%^%^BLACK%^piled high with %^RESET%^" +
             "%^ORANGE%^books%^BOLD%^%^BLACK%^, clearly meant to be enjoyed in front of the " +
             "massive %^WHITE%^ivory fireplace %^BLACK%^set into the western wall.  In the " +
             "northwestern corner are two sleek leather armchairs, positioned so that " +
             "the occupants could comfortably converse.  Between them, an unusual " +
             "%^RESET%^circle %^BOLD%^%^BLACK%^has been carved into the stone floor and embellished with " +
             "the %^RED%^house sigil%^BLACK%^.%^RESET%^\n");
    set_smell("default", "The sultry scent of incense and wine permeates the air.");
    set_listen("default", "The utter silence of the room is broken only by " +
               "the occasional crackle of the fireplace.");
    set_items(([
                   ({ "wall", "walls" }) : "%^BOLD%^%^BLACK%^The walls gl%^RESET%^i%^BOLD%^%^BLACK%^"
                   "tt%^WHITE%^e%^BLACK%^r darkly, seemingly carved from vast sheets of "
                   "ob%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^idi%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n. "
                   "The gemstone has been finished to a muted m%^RESET%^i%^BOLD%^%^BLACK%^rr%^CYAN%^"
                   "o%^BLACK%^r-like sheen that seems to writhe with the shadows of the occupants "
                   "as they move. A slender band that looks to be a continuous length of %^RESET%^"
                   "%^RED%^ruby%^BOLD%^%^BLACK%^ borders the ceiling where it meets the walls.%^RESET%^",
                   ({ "faerie fire", "ceiling", "lights", "stars" }) : "%^BOLD%^%^BLACK%^The ob%^RESET%^"
                   "%^RED%^s%^BOLD%^%^BLACK%^idi%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n ceiling shimmers "
                   "with the muted reflections of %^MAGENTA%^f%^RESET%^%^MAGENTA%^a%^BOLD%^er"
                   "%^YELLOW%^i%^MAGENTA%^e f%^RED%^i%^MAGENTA%^re%^BLACK%^. The magical lights twinkle "
                   "faintly like stars, their shifting light creating an enchanting atmosphere.%^RESET%^",
                   ({ "bed", "posts", "ivory posts", "ivory bed", "sheets", "spidersilk sheets" }) : "A picture of "
                   "opulence, this four poster bed has been carved from %^BOLD%^ivory %^RESET%^worn as "
                   "smooth as satin. Each post seems to have come from a single, monstrous %^RED%^"
                   "beast%^RESET%^, though the mind boggles at wondering what could have tusks so "
                   "large. Each post spirals upward before coming to a fanciful point, mimicking "
                   "stylized stalagmites. The plump mattress is covered with sleek %^BOLD%^%^RED%^crimson "
                   "sp%^RESET%^%^RED%^i%^BOLD%^der%^RESET%^%^RED%^s%^BOLD%^ilk sheets%^RESET%^, and a "
                   "lightweight %^BOLD%^%^BLACK%^black duvet %^RESET%^crafted from the same material "
                   "and filled with %^BOLD%^down %^RESET%^is folded neatly at the base of the bed, "
                   "balancing the matching %^BOLD%^%^BLACK%^black spi%^WHITE%^d%^BLACK%^er%^RESET%^s"
                   "%^BOLD%^%^BLACK%^ilk pillows %^RESET%^at the head.",
                   "wardrobe" : "This imposing wardrobe was crafted from %^RED%^teakwood %^RESET%^and "
                   "embellished with %^BOLD%^ivory accents%^RESET%^. In the center of each of the "
                   "two doors is a stylized %^BOLD%^spider %^RESET%^crafted from %^BOLD%^ivory "
                   "%^RESET%^panels%^RESET%^. Matching %^BOLD%^ivory pulls %^RESET%^sharpened on "
                   "each end complete the look, allowing the owner to open the doors and %^BOLD%^"
                   "<%^RESET%^peruse%^BOLD%^>%^RESET%^ the contents, %^BOLD%^<%^RESET%^select%^BOLD%^>"
                   "%^RESET%^ an item, or %^BOLD%^<%^RESET%^hang%^BOLD%^>%^RESET%^ an item up again.",
                   ({ "washstand", "wash stand", "stand", "basin" }) : "%^RED%^Constructed from solid, sleek "
                   "%^BOLD%^teakwood%^RESET%^%^RED%^, this wash stand features a smooth "
                   "%^BOLD%^%^WHITE%^ivory basin%^RESET%^%^RED%^. Unlike most such washstands, "
                   "this one has no pitcher but instead is fitted with an arching %^ORANGE%^copper "
                   "spout %^RED%^braced by a matching %^ORANGE%^handle %^RED%^on either side. The "
                   "handles can be turned to fill the basin with hot or cold water. Soap and towels "
                   "are kept close at hand, while a flawless %^BOLD%^%^CYAN%^mirror %^RESET%^%^RED%^"
                   "bound in %^ORANGE%^copper %^RED%^rises just over the stand, reflecting the "
                   "bountiful %^BOLD%^%^RED%^wil%^RESET%^%^MAGENTA%^d%^BOLD%^%^RED%^fl%^RESET%^"
                   "%^RED%^o%^BOLD%^wers %^RESET%^%^RED%^sprouting from a slender %^BOLD%^"
                   "%^WHITE%^ivory vase %^RESET%^%^RED%^on the washstand's shelf. You could use "
                   "the basin to <wash> yourself if required.%^RESET%^",
                   ({ "flowers", "wildflowers" }) : "Slender %^GREEN%^green stalks %^RESET%^rise "
                   "from the %^BOLD%^ivory vase %^RESET%^to support a riot of %^BOLD%^%^RED%^wil"
                   "%^RESET%^%^MAGENTA%^d%^BOLD%^%^RED%^fl%^RESET%^%^RED%^o%^BOLD%^wers %^RESET%^"
                   "that blossom in shades of %^RED%^red %^RESET%^and %^MAGENTA%^purple %^RESET%^"
                   "with hints of %^BOLD%^white%^RESET%^ thrown in.",
                   ({ "frieze", "scene", "carving", "walls", "wall" }) : "The intricately carved frieze "
                   "covers the exposed %^BOLD%^%^BLACK%^ob%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^idi" +
                   "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n walls %^RESET%^above the %^ORANGE%^dark "
                   "wooden paneling%^RESET%^. Should you wish to take a closer look, you could "
                   "%^BOLD%^%^RED%^<%^RESET%^observe frieze%^BOLD%^%^RED%^>%^RESET%^.",
                   ({ "books", "bookcase", "teakwood bookcase" }) : "The lofty %^RED%^teakwood bookcase"
                   "%^RESET%^ in the southwestern corner supports tomes covering various subjects "
                   "from histories of the Realm's races to volumes of arcane knowledge "
                   "interspersed with books on obscure subjects such as the flora of Moonstone "
                   "Vale. The books are meticulously arranged, allowing for the room's occupant "
                   "to retrieve any given volume with ease.",
                   ({ "fireplace", "ivory fireplace" }) : "Echoing the elegance of the bed and "
                   "brightening the room is a wide fireplace crafted of %^BOLD%^ivory %^RESET%^"
                   "and set into the western wall. The ivory has been carved with simple parallel "
                   "lines, balancing the intricate carving of the frieze that covers the walls. "
                   "Magical %^ORANGE%^logs %^RESET%^rest within the fireplace, ever burning with "
                   "%^RED%^fi%^BOLD%^r%^RESET%^%^RED%^e %^RESET%^that produces just the right "
                   "amount of heat while gracing the room with its pleasing light.",
                   ({ "chair", "chairs", "armchair", "armchairs" }) : "A pair of armchairs rests in the "
                   "northwestern corner, spaced so that those sitting can enjoy both the fire and "
                   "each other's company. Each chair is constructed to curve around the occupant, "
                   "encouraging him to relax into the supple %^BOLD%^%^BLACK%^charcoal leather%^RESET%^.",
                   ({ "floor", "circle", "sigil" }) : "Set within the %^BOLD%^%^BLACK%^ob%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^idi" +
                   "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^n floor %^RESET%^is a burnished %^BOLD%^mi%^CYAN%^t"
                   "%^WHITE%^hr%^RESET%^i%^BOLD%^l circle %^RESET%^enamelled with the sigil of %^RED%^"
                   "House Rilynath%^RESET%^, a %^BOLD%^%^BLACK%^bla%^RESET%^c%^BOLD%^%^BLACK%^k dragon "
                   "%^RESET%^formed from %^BOLD%^%^BLACK%^sh%^BLUE%^a%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w "
                   "%^RESET%^itself, rising from the %^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^rkn"
                   "%^WHITE%^e%^RESET%^s%^BOLD%^%^BLACK%^s %^RESET%^with outstretched %^BOLD%^%^BLACK%^cl"
                   "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ws %^RESET%^and a gaping %^BOLD%^%^RED%^maw "
                   "%^RESET%^to %^BOLD%^%^BLACK%^r%^RED%^e%^BLACK%^nd %^RESET%^whatever foe lay in "
                   "its path. The glittering %^RED%^ru%^BOLD%^b%^RESET%^%^RED%^y e%^BOLD%^y%^RESET%^"
                   "%^RED%^es%^RESET%^ of the dragon seem eerily alive, watching and waiting for the "
                   "room's owner to %^BOLD%^%^RED%^<%^RESET%^retrieve wine%^BOLD%^%^RED%^>%^RESET%^."
               ]));
    set_search("fireplace", "The flames are mesmerizing, and you feel a strange urge to immolate yourself.");
    set_search("default", "If you are looking for a way out, you may <leave> if you were uninvited or <present> your sigil if you have one.");
    red = 1;
    white = 1;
    black = 1;
    bpants = 1;
    gpants = 1;
    dress = 1;
    clothing = 6;
    wine = 0;
    set_property("silent update", 1);
    set_exits(([
                   "east" : ROOMS "chamber_of_reckoning"
               ]));
    set_door("door", ROOMS "chamber_of_reckoning", "east", "vic_key", "runes");
    set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                         "door, the entryway is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^ "
                         "that has been worked into the frieze that adorns the room. In place of a "
                         "typical doorframe, there is a cave-like opening surrounding the "
                         "%^RESET%^shadowy opening%^BOLD%^%^BLACK%^ that has been enchanted "
                         "to show a vision of countless Drow ascending from the Underdark to "
                         "venture into the surface world once more.%^RESET%^");
    set_open("door", 0);
    set_locked("door", 1, "runes");
    lock_difficulty("door",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "runes");
    set_lock_description("door", "runes",
                         "%^BOLD%^%^BLACK%^Hovering within the %^RESET%^shadowy "
                         "depths %^BOLD%^%^BLACK%^of the door are various %^CYAN%^r"
                         "%^WHITE%^u%^CYAN%^nes %^BLACK%^of unknown origin.%^RESET%^");
//functions to add: phase door when presenting a sigil and being on a list,
//vic_guest_list (ability to add, remove, and list). If uninvited, the door casts a targeted dispel.
}

void reset()
{
    ::reset();
    if (!present("fireplace_emoter")) {
        new(SILOBJ "vic_emoter")->move(TO);
    }
}

void init()
{
    ::init();
    add_action("retrieve_wine", "retrieve"); //opens the wine bar
    add_action("pour_em", "pour"); //allows the owners to pour wine
    add_action("return_em", "return"); //returns the wine
    add_action("read_list", "read"); //presents a list of wine
    add_action("peruse_clothes", "peruse"); //shows what clothes are there
    add_action("retrieve_clothes", "select"); //retrieves a clothing item
    add_action("return_clothes", "hang"); //returns an article of clothing to the closet
    add_action("observe_frieze", "observe"); //begins the frieze description
    add_action("immolate_self", "immolate"); //passage to Vic's lab in Silesse's house
    add_action("wash_em", "wash"); //Use the basin to clean up
    add_action("add_em", "add");
    add_action("erase_em", "erase");
    add_action("list_em", "list");
    add_action("help_em", "help");
//These functions control the guest list for the room
    add_action("present_em", "present");
    add_action("leave_em", "leave");
//"Leave" is for use by uninvited guests
    add_action("welcome_em", "welcome");
//"Welcome" allows owners to open the door to allow guests to enter or leave
    add_action("seal_em", "seal");
}

int present_em(string str)
{
    object sigil, dest;
    if (!str || str != "sigil") {
        tell_object(TP, "What are you trying to present?");
        return 1;
    }
    sigil = present("rilynath_sigil", TP);
    dest = find_object_or_load("/d/player_houses/aunuit/chamber_of_reckoning.c");
    if (!sigil) {
        tell_object(TP, "You don't have any sigil!");
        return 1;
    }
    if (member_array(TP->query_name(), invited) == -1) {
        tell_object(TP, "That only works if you were invited to the chamber.");
        return 1;
    }
    tell_object(TP, "%^RESET%^%^RED%^As you walk toward the %^BOLD%^%^BLACK%^"
                "shadowy doorway%^RESET%^%^RED%^, your sigil seems to hum against "
                "your skin. In response, the %^BOLD%^%^BLACK%^shadows %^RESET%^%^RED%^"
                "part, letting you walk through effortlessly.%^RESET%^");
    tell_room(TO, "%^RESET%^%^RED%^As " + TPQCN + " walks toward the %^BOLD%^%^BLACK%^"
              "shadowy doorway%^RESET%^%^RED%^, the %^BOLD%^%^BLACK%^shadows %^RESET%^%^RED%^"
              "part, letting " + TP->QO + " walk through effortlessly.%^RESET%^", TP);
    tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^shadows%^RESET%^%^RED%^ to the "
              "west part as " + TPQCN + " walks through.%^RESET%^", TP);
    TP->clear_followers();
    TP->move_player(dest);
    return 1;
}

int leave_em()
{
    object dest;
    dest = find_object_or_load("/d/player_houses/aunuit/chamber_of_reckoning.c");
    if (member_array(TP->query_name(), invited) == -1 && member_array(TP->query_name(), owners) == -1) {
        tell_object(TP, "%^BOLD%^%^BLACK%^The %^RESET%^shadows%^BOLD%^%^BLACK%^ "
                    "s%^RESET%^w%^BOLD%^%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^l fitfully, "
                    "seeming to cling at your skin as you force your way through. As soon "
                    "as you break free, they coalesce, forming an impenetrable barrier "
                    "behind you.%^RESET%^");
        tell_room(TO, "%^BOLD%^%^BLACK%^The %^RESET%^shadows%^BOLD%^%^BLACK%^ "
                  "s%^RESET%^w%^BOLD%^%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^l fitfully, "
                  "seeming to cling at " + TPQCN + "'s skin as " + TP->QS + " forces " + TP->QP + " way through. As soon "
                  "as " + TPQCN + " passes through, the %^RESET%^shadows %^BOLD%^%^BLACK%^coalesce, "
                  "forming an impenetrable barrier.%^RESET%^");
        tell_room(dest, "%^BOLD%^%^BLACK%^The %^RESET%^shadows%^BOLD%^%^BLACK%^ to the west "
                  "s%^RESET%^w%^BOLD%^%^BLACK%^i%^RESET%^r%^BOLD%^%^BLACK%^l fitfully and "
                  "" + TPQCN + " steps through.%^RESET%^");
        TP->clear_followers();
        TP->move_player(dest);
        return 1;
    }
    tell_object(TP, "%^RESET%^%^RED%^As you walk toward the %^BOLD%^%^BLACK%^"
                "shadowy doorway%^RESET%^%^RED%^, the %^BOLD%^%^BLACK%^shadows %^RESET%^%^RED%^"
                "part, letting you walk through effortlessly.%^RESET%^");
    tell_room(TO, "%^RESET%^%^RED%^As " + TPQCN + " walks toward the %^BOLD%^%^BLACK%^"
              "shadowy doorway%^RESET%^%^RED%^, the %^BOLD%^%^BLACK%^shadows %^RESET%^%^RED%^"
              "part, letting " + TP->QO + " walk through effortlessly.%^RESET%^", TP);
    tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^shadows%^RESET%^%^RED%^ to the "
              "east part as " + TPQCN + " walks through.%^RESET%^", TP);
    TP->clear_followers();
    TP->move_player(dest);
    return 1;
}

int welcome_em(string str)
{
    object dest;
    if (!str || str != "guests") {
        tell_object(TP, "Who are you trying to welcome? Try <welcome guests>.");
        return 1;
    }
    dest = find_object_or_load("/d/player_houses/aunuit/chamber_of_reckoning.c");
    if (member_array(TP->query_name(), invited) == -1 && member_array(TP->query_name(), owners) == -1) {
        tell_object(TP, "That only works if you are the owner or were invited to the chamber.");
        return 1;
    }
    if (TO->query_open("door")) {
        tell_object(TP, "The door is already open!");
        return 1;
    }
    tell_object(TP, "%^RESET%^%^RED%^With a wave of your hand, the %^BOLD%^%^BLACK%^"
                "shadows %^RESET%^%^RED%^part, welcoming those on the other side. When you are ready, "
                "you may <seal> the door.%^RESET%^");
    tell_room(TO, "%^RESET%^%^RED%^With a wave of " + TPQCN + "'s hand, the %^BOLD%^%^BLACK%^"
              "shadows %^RESET%^%^RED%^part, welcoming those on the other side.%^RESET%^", TP);
    tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^shadows%^RESET%^%^RED%^ to the "
              "west part, opening the way to the room on the other side.%^RESET%^", TP);
    set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                         "door, the entryway is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^ "
                         "that has been worked into the frieze that adorns the room. In place of a "
                         "typical doorframe, there is a cave-like opening surrounding the "
                         "%^RESET%^shadowy opening%^BOLD%^%^BLACK%^ that has been enchanted "
                         "to show a vision of countless Drow ascending from the Underdark to "
                         "venture into the surface world once more. The %^RESET%^shadows %^BOLD%^"
                         "%^BLACK%^are currently parted, revealing the room on the other side.%^RESET%^");
    dest->set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                               "door, the opening to the west is guarded by a pool of %^RESET%^shadow"
                               "%^BOLD%^%^BLACK%^. The shadows are currently parted, welcoming guests inside.%^RESET%^");
    TO->set_open("door", 1);
    dest->set_open("door", 1);
    return 1;
}

int seal_em(string str)
{
    object dest;
    if (!str || str != "door") {
        tell_object(TP, "Who are you trying to seal? Try <seal door>.");
        return 1;
    }
    dest = find_object_or_load("/d/player_houses/aunuit/chamber_of_reckoning.c");
    if (member_array(TP->query_name(), invited) == -1 && member_array(TP->query_name(), owners) == -1) {
        tell_object(TP, "That only works if you are the owner or were invited to the chamber.");
        return 1;
    }
    if (!TO->query_open("door")) {
        tell_object(TP, "The door is already closed!");
        return 1;
    }
    tell_object(TP, "%^RESET%^%^RED%^With a wave of your hand, the %^BOLD%^%^BLACK%^"
                "shadows %^RESET%^%^RED%^coalesce, sealing the doorway.%^RESET%^");
    tell_room(TO, "%^RESET%^%^RED%^With a wave of " + TPQCN + "'s hand, the %^BOLD%^%^BLACK%^"
              "shadows %^RESET%^%^RED%^coalesce, sealing the doorway.%^RESET%^", TP);
    tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^shadows%^RESET%^%^RED%^ to the "
              "west coalesce, sealing the doorway.%^RESET%^", TP);
    set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                         "door, the entryway is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^ "
                         "that has been worked into the frieze that adorns the room. In place of a "
                         "typical doorframe, there is a cave-like opening surrounding the "
                         "%^RESET%^shadowy opening%^BOLD%^%^BLACK%^ that has been enchanted "
                         "to show a vision of countless Drow ascending from the Underdark to "
                         "venture into the surface world once more.%^RESET%^");
    dest->set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                               "door, the opening to the west is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^.%^RESET%^");
    TO->set_open("door", 0);
    dest->set_open("door", 0);
    return 1;
}

int wash_em(string str)
{
    if (!str) {
        tell_object(TP, "You might want to try washing in the basin.");
        return 1;
    }
    if (str == "in basin" || str == "in the basin" || str == "in the washstand" || str == "at the washstand") {
        tell_object(TP, "You turn the copper handles until the water temperature "
                    "is just right before using the %^BOLD%^soap %^RESET%^to clean your "
                    "face and hands. Ahh...much better.");
        tell_room(ETP, "" + TPQCN + " adjusts the water at the washstand before washing " + TP->QP + " face and hands in " +
                  "the basin.", TP);
        TP->set("long");
        return 1;
    }
    tell_object(TP, "Where do you want to wash? Try washing in the basin.");
    return 1;
}

int observe_frieze(string str)
{
    if (!str) {
        tell_object(TP, "What are you trying to observe?");
        return 1;
    }
    if (str != "frieze") {
        tell_object(TP, "What are you trying to observe? Try <observe frieze>.");
        return 1;
    }
    tell_object(TP, "Circe sucks and hasn't gotten around to this yet. Try again soon.");
    return 1;
}

int peruse_clothes(string str)
{
    string avail = "";
    if (!str) {
        tell_object(TP, "Try to <peruse clothes> to see what's in the closet.");
        return 1;
    }
    if (str != "clothes" && str != "closet" && str != "wardrobe") {
        tell_object(TP, "Try to <peruse clothes> to see what's in the closet.");
        return 1;
    }
    if (member_array(TP->query_name(), owners) == -1 && !wizardp(TP)) {
        tell_object(TP, "You try to open the wardrobe to peer inside, but the doors won't budge.");
        if (!TP->query_invis()) {
            tell_room(TO, "" + TPQCN + " tugs at the doors of the wardrobe, but they won't budge.", TP);
        }
        return 1;
    }
    if (red) {
        avail += "red shirt\n";
    }
    if (white) {
        avail += "white shirt\n";
    }
    if (black) {
        avail += "black shirt\n";
    }
    if (bpants) {
        avail += "black pants\n";
    }
    if (gpants) {
        avail += "green pants\n";
    }
    if (dress) {
        avail += "green dress\n";
    }
    if (clothing < 1) {
        tell_object(TP, "You open the wardrobe, but find it's empty!");
        tell_room(TO, "" + TPQCN + " opens the wardobe, but it is empty.", TP);
        return 1;
    }
    tell_object(TP, "You open the wardrobe and peruse the contents. You could "
                "<select> from the following items:\n" + avail + "");
    tell_room(TO, "" + TPQCN + " opens the doors of the wardrobe and studies the contents.", TP);
    return 1;
}

int retrieve_clothes(string str)
{
    string my_mess, your_mess, thing;
    object obj;
    if (!str) {
        tell_object(TP, "You can <select [item]> from whatever is available. If you don't remember, you can <peruse closet>.");
        return 1;
    }
    if (member_array(TP->query_name(), owners) == -1 && !wizardp(TP)) {
        tell_object(TP, "You try to open the wardrobe to peer inside, but the doors won't budge.");
        if (!TP->query_invis()) {
            tell_room(TO, "" + TPQCN + " tugs at the doors of the wardrobe, but they won't budge.", TP);
        }
        return 1;
    }
    switch (str) {
    case "red shirt": if (red > 0) {
            thing = "%^RED%^red shirt";
            obj = new(SILOBJ "vic_red_shirt");
            red = 0;
            clothing -= 1;
    }else {
            failure();
            return 1;
    }
        break;

    case "white shirt": if (white > 0) {
            thing = "%^BOLD%^white shirt";
            obj = new(SILOBJ "vic_white_shirt");
            white = 0;
            clothing -= 1;
    }else {
            failure();
            return 1;
    }
        break;

    case "black shirt": if (black > 0) {
            thing = "%^BOLD%^%^BLACK%^black shirt";
            obj = new(SILOBJ "vic_black_shirt");
            black = 0;
            clothing -= 1;
    }else {
            failure();
            return 1;
    }
        break;

    case "black pants": if (bpants > 0) {
            thing = "%^BOLD%^%^BLACK%^pair of black pants";
            obj = new(SILOBJ "vic_pants");
            bpants = 0;
            clothing -= 1;
    }else {
            failure();
            return 1;
    }
        break;

    case "green pants": if (gpants > 0) {
            thing = "%^GREEN%^pair of green pants";
            obj = new(SILOBJ "silesse_pants");
            gpants = 0;
            clothing -= 1;
    }else {
            failure();
            return 1;
    }
        break;

    case "green dress": if (dress > 0) {
            thing = "%^GREEN%^green dress";
            obj = new(SILOBJ "silesse_dress");
            dress = 0;
            clothing -= 1;
    }else {
            failure();
            return 1;
    }
        break;

    default: failure();
        return 1;
    }
    my_mess = "You pull a " + thing + " %^RESET%^from the wardrobe, taking it off the hanger.";
    your_mess = "" + TPQCN + " pulls a " + thing + " %^RESET%^from the wardrobe.";
    tell_object(TP, "" + my_mess + "");
    tell_room(TO, "" + your_mess + "", TP);
    if ((int)(obj->move(TP)) != MOVE_OK) {
        write("You drop the " + thing + " %^RESET%^as you cannot carry any more.");
        obj->move(ETP);
    }
    return 1;
}

void failure()
{
    tell_object(TP, "That object doesn't seem to be in the wardrobe! "
                "Please <peruse closet> to see the clothes you can choose.");
    tell_room(TO, "" + TPQCN + " looks into the wardrobe, but doesn't seem "
              "to find what " + TP->QS + " wants.", TP);
    return;
}

int return_clothes(string str)
{
    string thing;
    object obj;
    if (!str) {
        tell_object(TP, "You can <hang [item]> to return it to the wardrobe. Only clothes that "
                    "belong in the wardrobe can be returned in this way.");
        return 1;
    }
    if (member_array(TP->query_name(), owners) == -1 && !wizardp(TP)) {
        tell_object(TP, "You try to open the wardrobe to peer inside, but the doors won't budge.");
        if (!TP->query_invis()) {
            tell_room(TO, "" + TPQCN + " tugs at the doors of the wardrobe, but they won't budge.", TP);
        }
        return 1;
    }
    if (!present(str, TP)) {
        tell_object(TP, "You don't have any " + str + "!");
        return 1;
    }
    obj = present(str, TP);
    if (!obj->id("vicdaerrysn clothing")) {
        tell_object(TP, "The wardrobe will hold only those clothes it is meant to hold. You'll have to keep that " + str + " elsewhere.");
        tell_room(TO, "" + TPQCN + " can't seem to find a place to hang the " + str + ".", TP);
        return 1;
    }
    if (obj->id("vic red shirt")) {
        thing = "%^RED%^red shirt";
        red++;
        tell_object(TP, "You return the " + thing + " %^RESET%^to the wardrobe.");
        tell_room(TO, "" + TPQCN + " returns the " + thing + " %^RESET%^to the wardrobe.", TP);
        obj->remove();
        clothing++;
        return 1;
    }else if (obj->id("vic black shirt")) {
        thing = "%^BOLD%^%^BLACK%^black shirt";
        black++;
        tell_object(TP, "You return the " + thing + " %^RESET%^to the wardrobe.");
        tell_room(TO, "" + TPQCN + " returns the " + thing + " %^RESET%^to the wardrobe.", TP);
        obj->remove();
        clothing++;
        return 1;
    }else if (obj->id("vic white shirt")) {
        thing = "%^BOLD%^white shirt";
        white++;
        tell_object(TP, "You return the " + thing + " %^RESET%^to the wardrobe.");
        tell_room(TO, "" + TPQCN + " returns the " + thing + " %^RESET%^to the wardrobe.", TP);
        obj->remove();
        clothing++;
        return 1;
    }else if (obj->id("vic black pants")) {
        thing = "%^BOLD%^%^BLACK%^pair of black pants";
        bpants++;
        tell_object(TP, "You return the " + thing + " %^RESET%^to the wardrobe.");
        tell_room(TO, "" + TPQCN + " returns the " + thing + " %^RESET%^to the wardrobe.", TP);
        obj->remove();
        clothing++;
        return 1;
    }else if (obj->id("vic green pants")) {
        thing = "%^GREEN%^pair of green pants";
        gpants++;
        tell_object(TP, "You return the " + thing + " %^RESET%^to the wardrobe.");
        tell_room(TO, "" + TPQCN + " returns the " + thing + " %^RESET%^to the wardrobe.", TP);
        obj->remove();
        clothing++;
        return 1;
    }else if (obj->id("vic green dress")) {
        thing = "%^GREEN%^green dress";
        dress++;
        tell_object(TP, "You return the " + thing + " %^RESET%^to the wardrobe.");
        tell_room(TO, "" + TPQCN + " returns the " + thing + " %^RESET%^to the wardrobe.", TP);
        obj->remove();
        clothing++;
        return 1;
    }else {
        tell_object(TP, "The wardrobe will hold only those clothes it is meant to hold. You'll have to keep that " + str + " elsewhere.");
        tell_room(TO, "" + TPQCN + " can't seem to find a place to hang the " + str + ".", TP);
        return 1;
    }
}

int retrieve_wine(string str)
{
    if (!str) {
        tell_object(TP, "What are you trying to retrieve?");
        return 1;
    }
    if (str != "wine" && str != "wine list" && str != "list" && str != "wine rack") {
        tell_object(TP, "Try <retrieve wine>.");
        return 1;
    }
    if (wine) {
        tell_object(TP, "The wine rack is already up!");
        return 1;
    }
    if ((string)TP->query_name() == "vicdaerrysn") {
        tell_object(TP, "You wave your hand indolently, and the %^BOLD%^%^RED%^"
                    "eyes%^RESET%^ of the %^BOLD%^%^BLACK%^dragon%^RESET%^ on the house "
                    "seal glow in response to your silent command.");
        tell_room(TO, "" + TPQCN + " waves " + TP->QP + " hand indolently, and the %^BOLD%^%^RED%^"
                  "eyes%^RESET%^ of the %^BOLD%^%^BLACK%^dragon%^RESET%^ on the house "
                  "seal glow in response to " + TP->QP + " silent command.", TP);
    }else {
        tell_object(TP, "You lean forward, waving your hand in front of the seal on "
                    "the floor. After a moment, the %^BOLD%^%^BLACK%^dragon's %^RED%^eyes "
                    "%^RESET%^glow dully.");
        tell_room(TO, "" + TPQCN + " leans forward, waving " + TP->QP + " hand in front of the seal on "
                  "the floor. After a moment, the %^BOLD%^%^BLACK%^dragon's %^RED%^eyes "
                  "%^RESET%^glow dully.", TP);
    }
    tell_room(TO, "With a faint hiss, the %^BOLD%^mi%^CYAN%^t"
              "%^WHITE%^hr%^RESET%^i%^BOLD%^l circle%^RESET%^ spins "
              "once and then lifts into the air, revealing a round "
              "%^RED%^teakwood %^RESET%^wine rack that rises from the floor.");
    tell_object(TP, "To see what wines are available today, you should simply, <read list>. "
                "When you are finished, you may <return wine> to put the rack away.");
    add_item(({ "wine rack", "rack of wine" }), "A slender wine rack carved from "
             "%^RED%^teakwood%^RESET%^ stands between the two %^BOLD%^%^BLACK%^"
             "armchairs%^RESET%^. It is topped by the %^BOLD%^mi%^CYAN%^t"
             "%^WHITE%^hr%^RESET%^i%^BOLD%^l circle%^RESET%^ bearing the sigil of "
             "%^RED%^House Rilynath%^RESET%^ and bears a framed %^BOLD%^wine list"
             "%^RESET%^ you could <read>. You may select and <pour> any wine "
             "available, and you can <return> the rack when you are finished.");
    wine = 1;
    return 1;
}

int read_list(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "list" && str != "wine list" && str != "list of wine") {
        return 0;
    }
    if (!wine) {
        tell_object(TP, "You must <retrieve> the wine rack before you can read the list.");
        return 1;
    }
    tell_object(TP, "Reading over the list of wines, you find:\n"
                "          %^BOLD%^%^WHITE%^Chardonnay%^RESET%^\n"
                "          %^BOLD%^%^BLACK%^Pinot Noir%^RESET%^\n"
                "          %^BOLD%^%^MAGENTA%^Feywine%^RESET%^\n"
                "          %^RED%^Shiraz%^RESET%^\n"
                "          %^GREEN%^Ul%^BOLD%^a%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^r%^RESET%^\n"
                "          %^RESET%^%^RED%^Bl%^BOLD%^o%^RESET%^%^RED%^od%^BOLD%^w%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^e%^RESET%^\n\n"
                "If you would like any of these, you may <pour> a glass for yourself or a guest. "
                "When you are finished, you can <return wine> to put the rack away.");
    tell_room(TO, "" + TPQCN + " reads over a list of wines.", TP);
    return 1;
}

int pour_em(string str)
{
    string type;
    object obj;
    if (!wine) {
        tell_object(TP, "You must <retrieve> the wine rack before you can read the list.");
        return 1;
    }
    if (!str) {
        tell_object(TP, "What would you like to pour? If you are not "
                    "sure what is available, you can <read list>.");
        return 1;
    }
    switch (str) {
    case "chardonnay":
    case "Chardonnay":
    case "glass of chardonnay": type = "%^BOLD%^%^WHITE%^chardonnay%^RESET%^";
        obj = new(SILOBJ "vic_chardonnay");
        break;

    case "pinot noir":
    case "Pinot Noir":
    case "glass of pinot noir": type = "%^BOLD%^%^BLACK%^pinot noir%^RESET%^";
        obj = new(SILOBJ "vic_noir");
        break;

    case "feywine":
    case "Feywine":
    case "glass of feywine": type = "%^BOLD%^%^MAGENTA%^feywine%^RESET%^";
        obj = new(SILOBJ "vic_feywine");
        break;

    case "shiraz":
    case "Shiraz":
    case "glass of shiraz": type = "%^RED%^shiraz%^RESET%^";
        obj = new(SILOBJ "vic_shiraz");
        break;

    case "ulaver":
    case "Ulaver":
    case "glass of ulaver": type = "%^GREEN%^ul%^BOLD%^a%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^r%^RESET%^";
        obj = new(SILOBJ "vic_ulaver");
        break;

    case "bloodwine":
    case "Bloodwine":
    case "glass of bloodwine": type = "%^RESET%^%^RED%^bl%^BOLD%^o%^RESET%^%^RED%^od%^BOLD%^w%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^e%^RESET%^";
        obj = new(SILOBJ "vic_bloodwine");
        break;

    default: wine_failure();
        return 1;
    }
    tell_object(TP, "You pour a glass of " + type + " before returning the bottle to the rack.");
    if ((int)(obj->move(TP)) != MOVE_OK) {
        write("You drop the glass of " + type + " as you cannot carry any more.");
        obj->move(ETP);
    }
    tell_room(TO, "" + TPQCN + " pours a glass of " + type + " before returning the bottle to the rack.", TP);
    return 1;
}

void wine_failure()
{
    tell_object(TP, "That type of wine doesn't seem to be available. "
                "Please <read list> to see what types are available.");
    return;
}

int return_em(string str)
{
    if (!str) {
        tell_object(TP, "What are you trying to return? Try <return wine>.");
        return 1;
    }
    if (str != "wine" && str != "wine rack" && str != "the wine rack" && str != "rack") {
        tell_object(TP, "What are you trying to return? Try <return wine>.");
        return 1;
    }
    if (!wine) {
        tell_object(TP, "The wine rack is not currently open.");
        return 1;
    }
    tell_object(TP, "You press lightly on the %^BOLD%^mi%^CYAN%^t"
                "%^WHITE%^hr%^RESET%^i%^BOLD%^l circle%^RESET%^, and the "
                "%^RED%^wine rack %^RESET%^begins to descend. You hear a faint "
                "click as it seals with the floor.");
    tell_room(TO, "" + TPQCN + " presses lightly on the %^BOLD%^mi%^CYAN%^t"
              "%^WHITE%^hr%^RESET%^i%^BOLD%^l circle%^RESET%^, and the %^RED%^wine "
              "rack %^RESET%^begins to descend. You hear a faint click as it "
              "seals with the floor.", TP);
    wine = 0;
    remove_item("wine rack");
    remove_item("rack of wine");
    return 1;
}

int immolate_self()
{
    int dmg;
    dest = find_object_or_load("/d/player_houses/silesse/dungeon.c");
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
    dest = find_object_or_load("/d/player_houses/silesse/dungeon.c");
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
    dest = find_object_or_load("/d/player_houses/silesse/dungeon.c");
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
                "yourself in a dungeon.%^RESET%^");
    tell_room(dest, "%^BOLD%^%^BLACK%^From the flickering %^RED%^fl%^YELLOW%^a%^RED%^m"
              "%^RESET%^%^RED%^e%^BOLD%^s%^BLACK%^, " + obj->QCN + " appears, "
              "landing on the floor with a thump!", obj);
    obj->move_player(dest);
    obj->set_paralyzed(0, "You are free from the strange paralysis.");
    flame = new(SILOBJ "flame.c");
    flame->move(TP);
    return 1;
}

int add_em(string str)
{
    string name, position, real;
    if (!str) {
        help_em("here");
        return 1;
    }
    if (sscanf(str, "%s to %s", name, position) != 2) {
        help_em("here");
        return 1;
    }
    if (position != "guests") {
        help_em("here");
        return 1;
    }
    if (member_array(TP->query_name(), owners) == -1) {
        tell_object(TP, "You don't have the authority to invite anyone to this chamber!");
        return 1;
    }
    if (TP->isKnown(name)) {
        real = name;
    }else {
        real = (string)TP->realName(name);
    }
    if (real == "") {
        tell_object(TP, "You don't seem to know anyone named " + name + ".");
        return 1;
    }
    if (member_array(real, invited) != -1) {
        tell_object(TP, "" + capitalize(name) + " is already a guest in this chamber!");
    }else {
        SAVE_D->set_value("vic_guest_list", real);
        tell_object(TP, "" + capitalize(name) + " has been added to the list of House members.");
    }
    update();
    return 1;
}

int erase_em(string str)
{
    string name, position, real;
    if (!str) {
        help_em("here");
        return 1;
    }
    if (sscanf(str, "%s from %s", name, position) != 2) {
        help_em("here");
        return 1;
    }
    if (position != "guests") {
        help_em("here");
        return 1;
    }
    if (member_array(TP->query_name(), owners) == -1) {
        tell_object(TP, "You don't have the authority to invite anyone to this chamber!");
        return 1;
    }
    if (TP->isKnown(name)) {
        real = name;
    }else {
        real = (string)TP->realName(name);
    }
    if (real == "") {
        tell_object(TP, "You don't seem to know anyone named " + name + ".");
        return 1;
    }
    if (member_array(real, invited) == -1) {
        tell_object(TP, "" + capitalize(name) + " is not on the guest list for this chamber!");
    }else {
        SAVE_D->remove_name_from_array("vic_guest_list", real);
        tell_object(TP, "" + capitalize(name) + " has been removed from the list of guests.");
    }
    update();
    return 1;
}

int list_em(string str)
{
    string listtext, name;
    mapping list;
    int i;

    list = ([]);

    if (!str) {
        help_em("here");
        return 1;
    }
    if (str != "guests") {
        help_em("here");
        return 1;
    }
    if (member_array(TP->query_name(), owners) == -1) {
        tell_object(TP, "You don't have the authority to list the guests to this chamber!");
        return 1;
    }
    list = SAVE_D->query_array("vic_guest_list");
    listtext = "The following individuals are guests of this chamber.\n";
    listtext += ""
                "%^BOLD%^%^BLACK%^====================================================================%^RESET%^\n";

    if (!list || list == "") {
        tell_object(TP, "There are no names on the guest list!");
        return 1;
    }
    for (i = 0; i < sizeof(list); i++) {
        name = list[i];
        if (TP->isKnown(name)) {
            name = TP->knownAs(name);
        }else {
            name = name;
        }
        if (name == "circe") {
            continue;
        }
        if (name == "vicdaerrysn") {
            continue;
        }
        listtext += "" + capitalize(name) + "\n";
    }
    listtext += ""
                "%^BOLD%^%^BLACK%^====================================================================%^RESET%^\n";
    TP->more(explode(listtext, "\n"));
    return 1;
}

void update()
{
    "/cmds/system/_update.c"->cmd_update();
    return 1;
}

int help_em(string str)
{
    if (!str || str == "here") {
        write("The owner of this chamber may:\n"
              "   add [name] to [guests]\n"
              "   erase [name] from [guests]\n"
              "   list [guests]\n");
        return 1;
    }
    return 0;
}
