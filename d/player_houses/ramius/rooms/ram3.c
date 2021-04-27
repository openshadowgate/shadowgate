//ram1
#include <std.h>
#include "../ramius.h"
inherit VAULT;
int searched;
int taken;
int taken2;
int uses, uses2, uses3;


void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Tree House");
    set_short("%^RESET%^%^GREEN%^Tree House%^RESET%^");
    set_long("%^RESET%^You have walked into a modest sized %^RESET%^%^GREEN%^Elven %^RESET%^home."
             "  This perfectly round room appears to be around fifty feet in diameter and nine feet high."
             "  Round %^BOLD%^%^CYAN%^glass windows %^RESET%^are set into the walls at regular intervals around"
             " the room.  The ceiling is covered in %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e"
             "%^RESET%^%^GREEN%^s %^RESET%^but the floor has been left very much in its natural condition and the"
             " rings of the tree can be seen prominently along it.  Along one wall is a wet bar that seems to have"
             " been grown out of the tree itself.  Near the bar is a %^RESET%^%^ORANGE%^wooden table %^RESET%^and"
             " some matching %^RESET%^%^ORANGE%^chairs%^RESET%^.  Opposite the bar is a nice %^RESET%^%^WHITE%^hemp"
             " hammock %^RESET%^that is anchored to the walls of the tree.  Along the section opposite the door sits"
             " a large, %^RESET%^%^ORANGE%^leather chair %^RESET%^and a rack containing some"
             " %^BOLD%^%^BLUE%^mus%^WHITE%^i%^BLUE%^cal instr%^WHITE%^u%^BLUE%^ments%^RESET%^.  "
             "Keeping the room well lit are small globes of %^BOLD%^%^RED%^mag%^BLUE%^i%^RED%^cal"
             " %^YELLOW%^light %^RESET%^hanging from the ceiling by %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^"
             "%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s%^RESET%^.  Hanging on the backside of the door is a nice painting.\n");
    set_smell("default", "%^RESET%^The scents of %^ORANGE%^wood %^RESET%^and the fragrance of %^BOLD%^%^BLUE%^f%^RED%^l%^YELLOW%^o%^RESET%^%^GREEN%^w%^BOLD%^%^CYAN%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLUE%^s %^RESET%^are here.");
    set_listen("default", "%^RESET%^The sounds of the surrounding %^RESET%^%^GREEN%^forest %^RESET%^seem distant here.");
    set_items(([
                   ({ "bar", "wet bar" }) : "This nice bar has been grown right out of the tree itself."
                   "  A %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e %^RESET%^pattern has been inlaid"
                   " along its corners and it is adorned with several other wooden carvings.  Among these are"
                   " a %^YELLOW%^yellow %^MAGENTA%^s%^BOLD%^%^RED%^u%^MAGENTA%^n%^YELLOW%^r%^RESET%^"
                   "%^RED%^i%^ORANGE%^s%^YELLOW%^e%^RESET%^, an %^BOLD%^%^WHITE%^ivory %^RESET%^%^GREEN%^unicorn%^RESET%^,"
                   " and a %^BOLD%^%^WHITE%^silver crescent moon%^RESET%^.  Sitting atop it are some cups made of"
                   " %^BOLD%^%^GREEN%^oak leaves %^RESET%^and various drinks.  You can see a pitcher of"
                   " %^RESET%^%^MAGENTA%^rose colored tea%^RESET%^, a nice bottle of %^BOLD%^%^RED%^Feywine%^RESET%^,"
                   " and a bottle of some type of %^BOLD%^%^BLACK%^whiskey%^RESET%^.  A bucket full of"
                   " %^BOLD%^%^WHITE%^i%^BLUE%^c%^WHITE%^e %^RESET%^sits nearby along with a wooden scoop.",
                   "globes" : "Numerous %^BOLD%^%^CYAN%^glass globes %^RESET%^are suspended from the %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s %^RESET%^that run along the ceiling.  They emit a soft, magical %^BOLD%^%^WHITE%^gl%^YELLOW%^o%^WHITE%^w%^RESET%^.",
                   ({ "rack", "instrument rack" }) : "This wooden rack sits along the north wall of the tree house. It appears well used and currently holds two musical instruments: a guitar and a violin.  Perhaps you might be able to %^BOLD%^%^WHITE%^<retrieve> %^RESET%^one of them.",
                   ({ "windows", "window" }) : "Round, %^BOLD%^%^YELLOW%^porthole-styled %^CYAN%^windows %^RESET%^are set at various intervals around the room.  They allow clear vision into the surrounding %^GREEN%^forest%^RESET%^ and can be opened to let %^BOLD%^%^WHITE%^fresh %^BLUE%^a%^CYAN%^i%^BLUE%^r %^RESET%^into the room.",
                   ({ "leather chair", "chair" }) : "This massive, %^RESET%^%^ORANGE%^leather chair %^RESET%^sits near the north wall of the house and appears to get much use.  It is well stuffed and appears to be quite comfortable.",
                   "chairs" : "These are simple, yet elegant %^BOLD%^%^BLACK%^walnut %^RESET%^chairs that surround the matching table.  They have padded seats and look rather comfortable.",

                   "hammock" : "Anchored somewhat along the eastern wall of the house is this %^RESET%^%^GREEN%^hemp hammock%^RESET%^.  It appears to be woven quite carefully and includes two %^RESET%^%^ORANGE%^wooden stretcher bars %^RESET%^that keep it always open.  It appears a bit large, and would likely hold two comfortably.  In the hammock are a few pillows and blankets, leading you to believe that it is used as a bed and not just a place of relaxation%^RESET%^.",

                   "table" : "This is a nice square wooden table fashioned from what appears to be %^BOLD%^%^BLACK%^walnut%^RESET%^.  It sits roughly in the western side of the house and is surrounded by matching chairs.",

                   "ceiling" : "The ceiling is covered by a multitude of crisscrossing %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s %^RESET%^that grow along it and down parts of the walls in this room.  Most of them appear to be %^BOLD%^%^BLUE%^f%^RED%^l%^YELLOW%^o%^CYAN%^w%^MAGENTA%^e%^RESET%^%^ORANGE%^r%^RED%^i%^BLUE%^n%^CYAN%^g %^RESET%^%^GREEN%^plants%^RESET%^, which gives the room a nice scent and attractive appearance.  Not much of the wood of the tree can be seen here except one rather odd knot off to one side.",

                   "floor" : "Though the floor has been well sanded and polished, the innumerable rings of the tree can be seen here.",

                   "knot" : "This is a knot within the wood of the ceiling.  Upon closer inspection it appears to be a doorknob to a very well hidden trap door within the ceiling.",
                   "trap door" : "This well hidden trap door sits off to one side of the ceiling.  It is masked by the multitude of %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^%^GREEN%^s %^RESET%^that run along it.",

                   "painting" : "This oil painting, like most everything else in the room, appears to be %^RESET%^%^GREEN%^Elven %^RESET%^handiwork.  A %^BOLD%^%^WHITE%^bright %^YELLOW%^s%^BOLD%^%^MAGENTA%^u%^RED%^n %^RESET%^rises across a beautiful, %^RESET%^%^GREEN%^springtime meadow %^RESET%^within the painting.  Written on the bottom corner of the painting are the initials %^BOLD%^%^RED%^~R.D.~%^RESET%^."
               ]));
    set_exits((["out" : INRMS "ram2"]));
    set_door("door", INRMS "ram2", "out", "wood_key");
    set_door_description("door", "This door has exactly the same color and texture as the %^GREEN%^tree %^RESET%^itself, making it difficult to see unless you are looking directly at it.  Looking close, you can see what appears to be a small keyhole and a knot which appears to serve as a doorknob, as well as a peephole to view what is outside.");
    set_locked("door", 1);
    lock_difficulty("door",  "/daemon/player_housing"->get_phouse_lock_dc("legendary"), "lock");
    set_search("default", "As you look around the room you notice that the large %^RESET%^%^ORANGE%^leather chair %^RESET%^might very well hold something of interest.");
    set_search("chair", (: TO, "search_chair" :));
    searched = 1;
}

void search_chair()
{
    if (searched <= 0) {
        tell_object(TP, "%^RESET%^%^ORANGE%^Upon closer inspection of the chair, you notice a discreetly hidden pocket sewn into the chair.  Oddly enough the pocket seems to be empty.%^RESET%^");
        return 1;
    }
    tell_object(TP, " Upon closer inspection of the chair, you notice a discreetly hidden pocket sewn into the chair.  Contained within is a small %^RESET%^%^ORANGE%^wooden key%^RESET%^.");
    new(OBJT + "wood_key.c")->move(TP);
    searched--;
    return 1;
}

void reset()
{
    ::reset();
    searched = 1;
    taken = 1;
    taken2 = 1;
    uses = random(7);
    uses2 = random(7);
    uses3 = random(7);
}

void init()
{
    ::init();
    add_action("retrieve", "retrieve");
    add_action("open_it", "open");
    add_action("close_it", "close");
    add_action("pour", "pour");
    add_action("serve", "serve");
    add_action("decant", "decant");
    add_action("view", "view");
}

int retrieve(string str)
{
    if (!str) {
        tell_object(TP, "Retrieve what?");
        return 1;
    }
    if (str == "guitar") {
        if (taken <= 0) {
            tell_object(TP, "%^ORANGE%^You look over the instrument rack only to find that the guitar is already missing.%^RESET%^");
            return 1;
        }
        {
            tell_object(TP, "%^GREEN%^You carefully reach over and retrieve a guitar from the rack.%^RESET%^");
            tell_room(ETP, "%^GREEN%^" + TPQCN + " retrieves a guitar from the instrument rack%^RESET%^.", TP);
            new("/d/antioch/antioch2/obj/guitar.c")->move(TP);
            taken--;
            return 1;
        }
    }
    if (str == "violin") {
        if (taken2 <= 0) {
            tell_object(TP, "%^ORANGE%^You look over the instrument rack only to find that the violin is already missing.%^RESET%^");
            return 1;
        }
        {
            tell_object(TP, "%^GREEN%^You carefully reach over and retrieve a violin from the rack.%^RESET%^");
            tell_room(ETP, "%^GREEN%^" + TPQCN + " retrieves a violin from the instrument rack%^RESET%^.", TP);
            new(OBJT + "violin.c")->move(TP);
            taken2--;
            return 1;
        }
    }
}

int close_it(string str)
{
    if (!str) {
        tell_object(TP, "Close what?");
        return 1;
    }
    if ((str == "trapdoor") || (str == "trap door")) {
        if (member_array("up", TO->query_exits()) != -1) {
            tell_object(TP, "You carefully push the trapdoor up and latch it shut.\n");
            tell_room(ETP, "" + TPQCN + " reaches up and closes the trapdoor.  It blends into the ceiling and disappears from view just as it shuts.\n", TP);
            remove_exit("up");
            tell_room(find_object_or_load(INRMS + "ram4"), "A hand reaches up and grabs the trap door, shutting it quietly and causing it to disappear from view.");
            (INRMS + "ram4")->remove_exit("down");
            return 1;
        }
        tell_object(TP, "The trap door is already closed!\n");
        return 1;
    }
}

int open_it(string str)
{
    if (!str) {
        tell_object(TP, "Open what?");
        return 1;
    }
    if ((str == "trapdoor") || (str == "trap door")) {
        if (member_array("up", TO->query_exits()) != -1) {
            tell_object(TP, "The trap door is already open! \n");
            return 1;
        }
        tell_object(TP, "%^GREEN%^You unlatch and open the hidden trap door in the ceiling.\n");
        tell_room(ETP, "%^GREEN%^" + TPQCN + " unlatches and opens a hidden trap door in the ceiling.\n", TP);
        tell_room(find_object_or_load(INRMS + "ram4"), "The trap door suddenly opens!");
        add_exit(INRMS + "ram4", "up");
        (INRMS + "ram4")->add_exit(INRMS + "ram3", "down");
        return 1;
    }
}

int decant(string str)
{
    string mname = TP->query_name();
    if (str != "whiskey") {
        tell_object(TP, "Pour what???");
        return 1;
    }else {
        if ((wizardp(TP)) || (mname == "ramius")) {
            if (uses == 0) {
                tell_object(TP, "%^ORANGE%^The oaken pitcher seems to be empty.  You'll have to gather more.");
                tell_room(ETP, "" + TPQCN + " picks up an aged oak caraffe, frowns slightly and puts it back down.", TP);
                return 1;
            }
            tell_object(TP, "You pick up the caraffe and pour the whiskey into a matching leaf shotglass.");
            tell_room(ETP, "" + TPQCN + " picks up an aged oak caraffe and pours a some whiskey into a matching leaf shotglass.", TP);
            new(OBJT + "whiskey")->move(TO);
            TP->force_me("get whiskey");
            uses - 1;
            return 1;
        }
        tell_object(TP, "You reach for the caraffe but it moves from your reach.");
        tell_room(ETP, "" + TPQCN + " reaches for the caraffe, but it moves from " + TP->query_possessive() + " reach.", TP);
        return 1;
    }
}

int serve(string str)
{
    string mname = TP->query_name();
    if (str != "feywine") {
        tell_object(TP, "Serve what???");
        return 1;
    }else {
        if ((wizardp(TP)) || (mname == "ramius")) {
            if (uses2 == 0) {
                tell_object(TP, "%^BOLD%^%^WHITE%^The crystal bottle seems to be empty.");
                tell_room(ETP, "%^BOLD%^%^WHITE%^" + TPQCN + " picks up a crystal bottle and peers into it.  With a look of disappointment, " + TP->query_subjective() + " puts it back down.", TP);
                return 1;
            }
            tell_object(TP, "%^BOLD%^%^WHITE%^You take a crystal bottle filled with a magical looking drink and carefully pour some into a matching crstal glass.");
            tell_room(ETP, "%^BOLD%^%^WHITE%^" + TPQCN + " picks up a lovely crystal bottle and pours some of its magical looking drink into a matching crystal glass.", TP);
            new(OBJT + "rfeywine")->move(TO);
            TP->force_me("get feywine");
            uses2 - 1;
            return 1;
        }
        tell_object(TP, "You reach for the crystal bottle but it moves from your reach.");
        tell_room(ETP, "" + TPQCN + " reaches for the crystal bottle, but it moves from " + TP->query_possessive() + " reach.", TP);
        return 1;
    }
}

int pour(string str)
{
    string mname = TP->query_name();
    if (str != "tea") {
        tell_object(TP, "Pour what???");
        return 1;
    }else {
        if ((wizardp(TP)) || (mname == "ramius")) {
            if (uses == 0) {
                tell_object(TP, "%^RESET%^%^MAGENTA%^The teapot is empty.");
                tell_room(ETP, "%^RESET%^%^MAGENTA%^" + TPQCN + " picks up a teapot and shakes it, listening.  With a sigh, " + TP->query_subjective() + " sets it back down.", TP);
                return 1;
            }
            tell_object(TP, "%^RESET%^%^MAGENTA%^You pick up a ceramic teapot decorated with leaf designs and pour some tea into a matching leaf cup.");
            tell_room(ETP, "%^RESET%^%^MAGENTA%^" + TPQCN + " picks up an old ceramic teapot decorated in leaf designs and pours some tea into a matching leaf cup.", TP);
            new(OBJT + "tea")->move(TO);
            TP->force_me("get tea");
            uses - 1;
            return 1;
        }
        tell_object(TP, "You reach for the teapot but it moves from your reach.");
        tell_room(ETP, "" + TPQCN + " reaches for the teapot, but it moves from " + TP->query_possessive() + " reach.", TP);
        return 1;
    }
}

void view(string str)
{
    object* people;
    int i;
    people = all_living(find_object_or_load("/d/player_houses/ramius/rooms/ram2.c"));
    tell_object(TP, "You peer through the peephole in the door.");
    tell_room(ETP, "" + TPQCN + " walks over to the peephole and peers through.", TP);
    tell_object(TP, "" + find_object_or_load(INRMS + "ram2.c")->query_long() + "\n");
    for (i = 0; i < sizeof(people); i++) {
        if (!people[i]->query_invis()) {
            tell_object(TP, "" + people[i]->query_short() + " is standing outside the door.");
        }
    }
    return 1;
}
