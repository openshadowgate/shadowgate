//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"
#include <daemons.h>

inherit AUNUIT;

string* invited = SAVE_D->query_array("vic_guest_list");

void create()
{
    ::create();
    set_name("Chamber of Reckoning");
    set_short("%^BOLD%^%^BLACK%^Chamber of Reckoning%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This sparsely furnished room "
             "functions as little more than a vestibule. The southern "
             "wall is dominated by an archway and a narrow walkway "
             "borders the perimeter of the room, a pair of shallow steps "
             "descending to a sunken foyer. %^WHITE%^Scr%^RESET%^i%^BOLD%^"
             "%^WHITE%^ms%^RESET%^h%^BOLD%^%^ORANGE%^a%^BOLD%^%^WHITE%^w "
             "p%^RESET%^i%^BOLD%^%^WHITE%^ll%^ORANGE%^a%^WHITE%^rs "
             "%^BLACK%^span floor to ceiling at the four interior "
             "corners of the walkway. The walls and ceiling are lined "
             "with rich, %^RESET%^%^ORANGE%^darkwood paneling %^BOLD%^"
             "%^BLACK%^while the floor is a gl%^WHITE%^o%^RESET%^s%^BOLD%^"
             "%^BLACK%^sy black m%^RESET%^a%^BOLD%^%^BLACK%^rble. An "
             "oval-shaped woven rug, its fabric dyed a vibrant %^RESET%^"
             "%^MAGENTA%^m%^RED%^a%^BOLD%^%^MAGENTA%^u%^RESET%^%^RED%^"
             "v%^MAGENTA%^e%^BOLD%^%^BLACK%^, protects the floor. In "
             "the center of the rug sits a beautiful %^RESET%^%^ORANGE%^"
             "table %^BOLD%^%^BLACK%^carved in the likeness of a sh"
             "%^RESET%^a%^BOLD%^%^BLACK%^d%^BLUE%^o%^BLACK%^w drag"
             "%^RESET%^o%^BOLD%^%^BLACK%^n, a bowl of %^ORANGE%^pe"
             "%^RESET%^%^RED%^a%^BOLD%^%^ORANGE%^ches %^BLACK%^its "
             "only passenger. Two sleek %^WHITE%^white leather couches "
             "%^BLACK%^flank the table. The center of the vaulted "
             "ceiling sports a magnificent cluster of jagged %^MAGENTA%^"
             "am%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^t%^BLACK%^h"
             "%^MAGENTA%^yst cr%^RESET%^%^MAGENTA%^y%^BOLD%^%^MAGENTA%^st"
             "%^WHITE%^a%^MAGENTA%^ls %^BLACK%^that hangs from the ceiling "
             "like a chandelier casting a pale %^MAGENTA%^v%^WHITE%^i"
             "%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^let l%^WHITE%^i"
             "%^RESET%^%^MAGENTA%^g%^BOLD%^%^MAGENTA%^ht%^BLACK%^. A "
             "large %^CYAN%^s%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^al "
             "%^BLACK%^occupies the northern wall. Imposing %^RESET%^"
             "statues %^BOLD%^%^BLACK%^stand at the southern and "
             "northern ends of the room and a second door is set in "
             "the eastern wall.%^RESET%^\n");
    set_smell("default", "%^RESET%^%^CYAN%^The cloying scent of peaches competes with the rich scent of leather.%^RESET%^");
    set_listen("default", "%^BOLD%^%^BLACK%^This room is as silent as a tomb.%^RESET%^");
    set_items(([
                   ({ "table", "couches", "couch" }) : "%^BOLD%^%^BLACK%^This sleek "
                   "%^RESET%^%^ORANGE%^darkwood table %^BOLD%^%^BLACK%^is "
                   "elaborately carved to resemble a dr%^RESET%^a%^BOLD%^%^BLACK%^"
                   "g%^BLUE%^o%^BLACK%^n stalking on four legs. Its neck is curled "
                   "in an 'S' shape, its chin touching its chest. Its wings are "
                   "folded at its side and the beasts back has been sanded until "
                   "it is a flat plain. A solid on%^RESET%^y%^BOLD%^%^BLACK%^x "
                   "b%^WHITE%^o%^BLACK%^wl sits on the dragon's back with several "
                   "sweet smelling %^ORANGE%^pe%^RESET%^%^RED%^a%^BOLD%^%^ORANGE%^"
                   "ches %^BLACK%^piled within. Armed with dangerous-looking barbs "
                   "the tail of the dragon is stretched out behind it for balance. "
                   "Two slender %^WHITE%^couches %^BLACK%^rest on either side of "
                   "the table. They are upholstered with supple %^WHITE%^white "
                   "leather %^BLACK%^that emits an intoxicating %^RESET%^%^ORANGE%^"
                   "scent%^BOLD%^%^BLACK%^. A %^RESET%^sl%^BOLD%^%^BLACK%^a%^RESET%^te "
                   "gr%^BOLD%^%^BLACK%^e%^RESET%^y velv%^BOLD%^%^WHITE%^e%^RESET%^t "
                   "p%^BOLD%^%^BLACK%^i%^RESET%^llow %^BOLD%^%^BLACK%^rests in the "
                   "niche of each arm.%^RESET%^",
                   ({ "ceiling", "amethyst", "chandelier" }) : "%^BOLD%^%^BLACK%^An "
                   "enormous cluster of brilliant %^MAGENTA%^am%^RESET%^%^MAGENTA%^e"
                   "%^BOLD%^%^MAGENTA%^t%^BLACK%^h%^MAGENTA%^yst q%^RESET%^%^MAGENTA%^u"
                   "%^BOLD%^%^BLACK%^a%^WHITE%^r%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^z "
                   "%^BLACK%^protrudes from the center of the ceiling. Its %^MAGENTA%^m"
                   "%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^lt%^RESET%^i%^BOLD%^%^BLACK%^"
                   "surface %^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^ls%^RESET%^"
                   "%^MAGENTA%^a%^BOLD%^%^MAGENTA%^tes%^BLACK%^, bathing the features "
                   "of the room in a %^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^i%^WHITE%^"
                   "o%^MAGENTA%^l%^RESET%^%^MAGENTA%^et l%^BOLD%^%^WHITE%^i%^MAGENTA%^g"
                   "%^RESET%^%^MAGENTA%^ht%^BOLD%^%^BLACK%^.%^RESET%^",
                   "floor" : "%^BOLD%^%^BLACK%^The floor is black marble buffed to "
                   "a m%^WHITE%^i%^RESET%^r%^BOLD%^%^BLACK%^r%^WHITE%^o%^BLACK%^r-"
                   "like %^WHITE%^sheen%^BLACK%^ lending this room a vast, %^RESET%^"
                   "%^BLUE%^void%^BOLD%^%^BLACK%^-like quality. It is as if one is "
                   "taking uncertain steps on the surface of a black pool, never "
                   "knowing when the bottom might recede.%^RESET%^",
                   ({ "statue", "statues" }) : "%^BOLD%^%^BLACK%^These %^RESET%^adamatium "
                   "statues %^BOLD%^%^BLACK%^are realistic and raw renderings of the "
                   "%^RESET%^%^MAGENTA%^female%^BOLD%^%^BLACK%^ and %^BLUE%^male "
                   "%^BLACK%^form. Both %^RESET%^nude %^BOLD%^%^BLACK%^except for the "
                   "weapons they wield their %^RESET%^%^CYAN%^ga%^BOLD%^%^CYAN%^z"
                   "%^RESET%^%^CYAN%^es %^BOLD%^%^BLACK%^meet across the room. One "
                   "could take a closer look at them individually.%^RESET%^",
                   "female statue" : "%^BOLD%^%^BLACK%^She stands nearly six feet "
                   "tall, slim and composed of sinuous muscle. Her sleek, smooth "
                   "form gleams as if %^CYAN%^w%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^t"
                   "%^BLACK%^, the metal buffed to a high %^WHITE%^sh%^RESET%^i"
                   "%^BOLD%^%^WHITE%^ne%^BLACK%^. Though taller than any common in "
                   "nature, her facial features are those of a %^RESET%^%^GREEN%^f"
                   "%^CYAN%^e%^GREEN%^y%^BOLD%^%^BLACK%^ creature; prominent cheek "
                   "bones, %^RESET%^%^ORANGE%^alm%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^"
                   "nd%^BOLD%^%^BLACK%^-shaped eyes and tapered ears. Her statuesque "
                   "figure is that of a %^MAGENTA%^volupt%^RESET%^%^MAGENTA%^u%^BOLD%^"
                   "%^MAGENTA%^ous w%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^man "
                   "%^BLACK%^in full bloom with full breasts and a smooth mound "
                   "between her thighs. Long h%^WHITE%^a%^RESET%^i%^BOLD%^%^BLACK%^r "
                   "cascades down around her shoulders and back, the rendering of the "
                   "individual strands impressive. In her hand she wields a sharp "
                   "d%^RED%^a%^BLACK%^gg%^RESET%^e%^BOLD%^%^BLACK%^r and wrapped "
                   "about her ample hips like a belt is a %^RESET%^%^RED%^b%^BOLD%^"
                   "%^RED%^a%^RESET%^%^RED%^rb%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^d "
                   "wh%^BOLD%^%^RED%^i%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^.%^RESET%^",
                   "male statue" : "%^BOLD%^%^BLACK%^He stands well over six feet "
                   "tall and has a powerful body composed of corded muscles. His "
                   "s%^RESET%^i%^BOLD%^%^BLACK%^lv%^WHITE%^e%^BLACK%^ry 'skin' "
                   "has been buffed until it %^WHITE%^sh%^RESET%^i%^BOLD%^%^WHITE%^"
                   "nes %^BLACK%^and gives him an %^RESET%^%^ORANGE%^oil%^BOLD%^"
                   "%^ORANGE%^e%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^appearance. "
                   "Though taller than any common in nature, his facial features "
                   "are those of a %^RESET%^%^GREEN%^f%^CYAN%^e%^GREEN%^y%^BOLD%^"
                   "%^BLACK%^ creature; prominent cheek bones, %^RESET%^%^ORANGE%^alm"
                   "%^BOLD%^%^ORANGE%^o%^RESET%^%^ORANGE%^nd%^BOLD%^%^BLACK%^-shaped "
                   "eyes and tapered ears. His head and body are devoid or hair and "
                   "the artist that rendered him missed not a hill or valley of his "
                   "well-toned body including a sizable %^RESET%^%^RED%^member "
                   "%^BOLD%^%^BLACK%^which languishes against his thigh. In his "
                   "large hands he carries two %^RESET%^w%^BOLD%^%^RED%^i%^RESET%^"
                   "ck%^RED%^e%^RESET%^d %^BOLD%^%^BLACK%^looking %^RESET%^a%^RED%^"
                   "x%^BOLD%^%^RED%^e%^RESET%^s%^BOLD%^%^BLACK%^.%^RESET%^"
               ]));
    set_exits(([
                   "west" : ROOMS "vic_room",
                   "north" : ROOMS "bedroom",
                   "south" : ROOMS "upper_landing"
               ]));
    set_door("seal", "/d/player_houses/aunuit/bedroom", "north", 0);
    set_door_description("seal", "%^BOLD%^%^BLACK%^Nearly six feet in diameter "
                         "this inlaid circular %^RESET%^adamatium ring %^BOLD%^"
                         "%^BLACK%^occupies a majority of the northern wall. The "
                         "metal has an ethereal, %^RESET%^%^CYAN%^a%^BOLD%^%^CYAN%^"
                         "z%^WHITE%^u%^CYAN%^r%^RESET%^%^CYAN%^e h%^BOLD%^%^CYAN%^u"
                         "%^RESET%^%^CYAN%^e %^BOLD%^%^BLACK%^and is without visible "
                         "streaks or folds, its forging truly a work of master "
                         "craftsmanship. Et%^CYAN%^c%^BLACK%^hed into the surface of "
                         "the metal itself, which is about two feet wide, is an "
                         "intricate l%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ne design; "
                         "dr%^CYAN%^a%^BLACK%^g%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^ns "
                         "curled round one another, their m%^RESET%^%^CYAN%^o%^BOLD%^"
                         "%^CYAN%^u%^BLACK%^ths consuming the ta%^CYAN%^i%^BLACK%^l "
                         "of the next in an %^RESET%^%^CYAN%^infinite%^BOLD%^%^BLACK%^ "
                         "d%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^n%^CYAN%^c%^BLACK%^e.%^RESET%^");
    set_door("door", ROOMS "vic_room", "west", "vic_key", "runes");
    set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                         "door, the opening to the west is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^.%^RESET%^");
    set_open("door", 0);
    set_locked("door", 1, "runes");
    lock_difficulty("door",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "runes");
    set_lock_description("door", "runes",
                         "%^BOLD%^%^BLACK%^Hovering within the %^RESET%^shadowy "
                         "depths %^BOLD%^%^BLACK%^of the door are various %^CYAN%^r"
                         "%^WHITE%^u%^CYAN%^nes %^BLACK%^of unknown origin.%^RESET%^");
}

void init()
{
    ::init();
    add_action("present_em", "present");
    add_action("welcome_em", "welcome");
    add_action("seal_em", "seal");
}

int welcome_em(string str)
{
    object dest;
    if (!str || str != "guests") {
        tell_object(TP, "Who are you trying to welcome? Try <welcome guests>.");
        return 1;
    }
    dest = find_object_or_load("/d/player_houses/aunuit/vic_room.c");
    if ((string)TPQN != "vicdaerrysn" && !avatarp(TP)) {
        tell_object(TP, "That only works if you are the owner.");
        return 1;
    }
    if (TO->query_open("door")) {
        tell_object(TP, "The door is already open!");
        return 1;
    }
    tell_object(TP, "%^RESET%^%^RED%^With a wave of your hand, the %^BOLD%^%^BLACK%^"
                "shadows %^RESET%^%^RED%^part, allowing guests to enter the chamber. When you are ready, "
                "you may <seal> the door.%^RESET%^");
    tell_room(TO, "%^RESET%^%^RED%^With a wave of " + TPQCN + "'s hand, the %^BOLD%^%^BLACK%^"
              "shadows %^RESET%^%^RED%^part, allowing guests to enter the chamber.%^RESET%^", TP);
    tell_room(dest, "%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^shadows%^RESET%^%^RED%^ to the "
              "east part, opening the way to the room on the other side.%^RESET%^", TP);
    set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                         "door, the opening to the west is guarded by a pool of %^RESET%^shadow"
                         "%^BOLD%^%^BLACK%^. The shadows are currently parted, welcoming guests inside.%^RESET%^");
    dest->set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                               "door, the entryway is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^ "
                               "that has been worked into the frieze that adorns the room. In place of a "
                               "typical doorframe, there is a cave-like opening surrounding the "
                               "%^RESET%^shadowy opening%^BOLD%^%^BLACK%^ that has been enchanted "
                               "to show a vision of countless Drow ascending from the Underdark to "
                               "venture into the surface world once more. The %^RESET%^shadows %^BOLD%^"
                               "%^BLACK%^are currently parted, revealing the room on the other side.%^RESET%^");
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
    dest = find_object_or_load("/d/player_houses/aunuit/vic_room.c");
    if (member_array(TP->query_name(), invited) == -1 && (string)TPQN != "vicdaerrysn" && !avatarp(TP)) {
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
              "east coalesce, sealing the doorway.%^RESET%^", TP);
    set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                         "door, the opening to the west is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^.%^RESET%^");
    dest->set_door_description("door", "%^BOLD%^%^BLACK%^Rather than a simple "
                               "door, the entryway is guarded by a pool of %^RESET%^shadow%^BOLD%^%^BLACK%^ "
                               "that has been worked into the frieze that adorns the room. In place of a "
                               "typical doorframe, there is a cave-like opening surrounding the "
                               "%^RESET%^shadowy opening%^BOLD%^%^BLACK%^ that has been enchanted "
                               "to show a vision of countless Drow ascending from the Underdark to "
                               "venture into the surface world once more.%^RESET%^");
    TO->set_open("door", 0);
    dest->set_open("door", 0);
    return 1;
}

int present_em(string str)
{
    object sigil, dest;
    if (!str || str != "sigil") {
        tell_object(TP, "What are you trying to present?");
        return 1;
    }
    sigil = present("rilynath_sigil", TP);
    dest = find_object_or_load("/d/player_houses/aunuit/vic_room.c");
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
