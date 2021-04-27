//lab.c - Laboratory for Stefano's tower.  Coded by Circe 9/28/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit "/std/lab";

int door_open;

void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A large laboratory");
    set_short("A large laboratory");
    set_long("The center of this room is occupied by a vertical " +
             "%^ORANGE%^wooden beam%^RESET%^ rising from a hole in the floor " +
             "all the way to a socket in the ceiling. The beam turns continuously " +
             "anticlockwise. About four feet from the floor, the beam has been carefully " +
             "wrapped in strange looking fur. An elaborate apparatus has been set up around " +
             "it at this point and bright %^BOLD%^%^CYAN%^arcing l%^BOLD%^%^WHITE%^i" +
             "%^BOLD%^%^CYAN%^nes%^RESET%^ of %^BOLD%^%^YELLOW%^energy%^RESET%^ occasionally " +
             "coruscate up and down along it. Elsewhere, a long wooden workbench runs along " +
             "three of the four walls of the room, with a few cupboards and cubbys underneath " +
             "it. Stairs leading up and down occupy the final, north wall. Shelves above the " +
             "workbench contain jars, jugs, bottles and all manner of other containers. Here " +
             "and there, a hint of something unpleasant can be seen through the smoky glass of " +
             "one of the jars. A complex distillation has been set up on one side of the workbench, " +
             "and %^BOLD%^%^RED%^mu%^BOLD%^%^BLUE%^l%^BOLD%^%^MAGENTA%^ti%^BOLD%^%^YELLOW%^co" +
             "%^BOLD%^%^CYAN%^lo%^BOLD%^%^BLACK%^u%^BOLD%^%^RED%^r%^BOLD%^%^YELLOW%^ed " +
             "%^BOLD%^%^BLUE%^l%^BOLD%^%^CYAN%^i%^RESET%^%^BLUE%^q%^GREEN%^u%^BOLD%^%^GREEN%^i" +
             "%^BOLD%^%^BLUE%^ds%^RESET%^ drip, bubble or run inexplicably upwards through a " +
             "series of carefully arranged glass tubes." +
             "\n");
    set_smell("default", "A variety of acrid, pungent smells assault your nostrils.");
    set_listen("default", "You can hear a quiet sound of wood sliding over stone.");
    set_items(([
                   ({ "cupboard", "cupboards" }) : "Most of the cupboards contain various beakers, " +
                   "clamps, stands, bowls, grinders, knives, screens, and other paraphenalia of " +
                   "magical research. The cupboard right at the end  is stuck shut and no amount " +
                   "of pulling on its brass handle will shift it.",
                   ({ "jar", "jars" }) : "There are jars of all different sizes arranged on shelves and " +
                   "in various cubbies around the room. There are large ones, medium ones and small ones.",
                   ({ "bottle", "bottles" }) : "There are bottles of all different sizes arranged on shelves and " +
                   "in various cubbies around the room. There are large ones, medium ones and small ones.",
                   ({ "jug", "jugs" }) : "There are jugs of all different sizes arranged on shelves and in " +
                   "various cubbies around the room. There are large ones, medium ones and small ones.",
                   "handle" : "The cupboard at the end of the workbench has a round " +
                   "%^BOLD%^%^YELLOW%^brass handle%^RESET%^ on the door, somewhat different to all " +
                   "the other cupboards in the room.",
                   ({ "small bottle", "small bottles" }) : "You look at one of the smaller bottles. Its dark glass is opaque " +
                   "and you would have to open it to see what is inside.",
                   ({ "large jar", "large jars" }) : "One of the big jars appears to be made of mother of pearl " +
                   "and is closed at the top with a clay stopper. The stopper itself bears a seal of " +
                   "red wax, etched with a strange rune. Glyphs and other magical symbols adorn the " +
                   "sides of the jar.",
                   ({ "medium jug", "medium jugs" }) : "You pick up a medium sized jug " +
                   "and give it a shake. It makes a dull sloshing noise, and when " +
                   "you peer into the top of the jug you can see a dark, oily liquid " +
                   "inside. It smells like tar or creosote.",
                   "workbench" : "The surface of the workbench is hardened oak, shiny with several " +
                   "layers of tough varnish. It bears a few scorch marks and scratches, and at one " +
                   "point a small hole seems to have been burned all the way through the workbench.",
                   "floor" : "The floor is made of simple grey flagstones. It is scrupulously clean, " +
                   "but a few stains can be made out.",
                   "hole" : "Looking closer, you can see two holes, one in the workbench and one in " +
                   "the floor. They seem to be lined up precisely above one another. You could " +
                   "probably peek through the hole in the floor if you crawled under the workbench.",
                   "beam" : "The wood has been %^BOLD%^%^BLACK%^stained dark%^RESET%^, and the beam " +
                   "turns slowly, almost silently. At various points the  beam has been inscribed " +
                   "with %^RED%^glyphs%^RESET%^, %^BLUE%^runes%^RESET%^ and %^BOLD%^%^GREEN%^sigils" +
                   "%^RESET%^ in strange colors. Some of them seem to shimmer, shift, and make your " +
                   "eyes water just to look at them. The mystic symbols all seem to gather in around " +
                   "the point where the strange fur has been wrapped around the beam.",
                   "fur" : "The fur wrapped around the beam is a %^BOLD%^%^CYAN%^light blue color%^RESET%^.  " +
                   "It is short haired, but looks very fine, soft and warm. The complex apparatus seems " +
                   "to have been designed to hold certain items against the fur as it turns.",
                   "apparatus" : "The aparatus is complex, but appears to have been designed to hold " +
                   "certain items against, or near the fur as it turns. A large piece of amber is " +
                   "positioned near the top of the fur, touching it. A metal strip is lower down, " +
                   "touching both the fur and the wood. An %^GREEN%^emerald%^RESET%^ is held " +
                   "slightly back away from the fur, and it %^GREEN%^g%^BOLD%^%^GREEN%^lo" +
                   "%^RESET%^%^GREEN%^ws%^RESET%^ with an eery interior light. A circlet of platinum " +
                   "surrounds the fur, but does not touch it. A rim of %^BOLD%^%^BLUE%^f%^BOLD%^%^CYAN%^r" +
                   "%^BOLD%^%^WHITE%^o%^BOLD%^%^BLUE%^st%^RESET%^ has formed around the circlet.",
                   "stairs" : "The stone staircase takes up most of the space along the north wall of " +
                   "the room. At the top, a large stone slab is supported on a pair of iron bracings " +
                   "that connect to a mechanism hidden within the stones of the ceiling. From this " +
                   "side a simple push or pull is sufficient to open or close the top of the stairwell.",
                   "shelves" : "The shelves and various cubbies in this room are filled with neatly " +
                   "ordered bottles, jars and stoppered jugs.",
                   ({ "tubes", "liquids", "distillation" }) : "Although complex, the arrangement of the glass tubes is neat " +
                   "and precise, and it would probably be possible, with care, to trace the tubing " +
                   "all the way to the end. At various points flames with no apparent source or fuel " +
                   "burn beneath the glass, heating the liquids to precise temperatures as they flow " +
                   "past. There is no obvious reason why some of the liquids flow upwards, but it's probably mystic."
               ]));
    set_search("default", "Something on the floor beneath the workbench catches your eye.");
    set_search("floor", "There is a small hole underneath the workbench.");
    set_exits(([
                   "up" : SHOUSE "tower_lounge",
                   "down" : SHOUSE "cog_room"
               ]));
    set_door("slab", SHOUSE "tower_lounge", "up", 0);
    set_door_description("slab", "The huge slab of stone can be closed easily with a single push.");
    set_door("trapdoor", SHOUSE "cog_room", "down", 0);
    set_door_description("trapdoor", "The trapdoor is made from solid oak, reinforced with bands " +
                         "of iron. It is locked with heavy bolts on this side.");
    set_locked("trapdoor", 1, "lock");
    lock_difficulty("trapdoor",  "/daemon/player_housing"->get_phouse_lock_dc("good"), "lock");
    setOwner("gaius");
    setLabId("gaius");
//Gaius is renting this
    door_open = 0;
}

void init()
{
    ::init();
    add_action("look", "look");
    add_action("open", "open");
    add_action("twist", "twist");
    add_action("pull", "pull");
    add_action("push", "push");
    add_action("trace", "trace");
}

void reset()
{
    ::reset();
    switch (random(3)) {
    case 0:  tell_room(TO, "%^BOLD%^%^CYAN%^An arc of blue energy bursts from the fur " +
                       "and crackles up and then down the length of the beam before dispersing " +
                       "into the complex apparatus%^RESET%^.");
        break;

    case 1:  tell_room(TO, "%^BLUE%^A drip of thick liquid plops into a beaker within " +
                       "the distillation setup, giving off a small whiff of %^BOLD%^%^WHITE%^white smoke%^RESET%^.");
        break;

    case 2:  tell_room(TO, "One of the large jars rattles suddenly on the shelf, with " +
                       "no obvious cause. It stops just as suddenly as it started.");
        break;
    }
    door_open = 0;
}

int look(string str)
{
    if (!str) {
        return 0;
    }
    if (str == "large bottle" || str == "large bottles") {
        switch (random(3)) {
        case 0..1:  tell_object(TP, "You pick up one of the large bottles for a closer look.  " +
                                "The glass is a %^YELLOW%^dull yellow%^RESET%^ in color, and the bottle is " +
                                "full of liquid. A little seems to have spilled out around the cork stopper " +
                                "and there is a distinct smell of alcohol. Floating in amongst some cloudy " +
                                "sediment in the bottom of the bottle is a small, scaly worm.");
            break;

        case 2..3:  tell_object(TP, "The largest bottle, sitting in a cubby on its own, contains " +
                                "a pickled human brain. There is no obvious way that the brain could have got " +
                                "through the narrow neck of the bottle, or any indication of how it might be " +
                                "extracted again if needed.");
            break;
        }
        tell_room(ETP, "" + TPQCN + " picks up one of the large bottles and peers inside at its contents.", TP);
        return 1;
    }
    if (str == "medium bottle" || str == "medium bottles") {
        switch (random(6)) {
        case 0:  tell_object(TP, "You glance at one of the many medium sized bottles.  " +
                             "It is a fairly nondescript clear glass bottle with a rubber stopper, " +
                             "and is filled to the brim with a %^BOLD%^%^CYAN%^light blue%^RESET%^ liquid.");
            break;

        case 1:  tell_object(TP, "You glance at one of the many medium sized bottles.  " +
                             "It is a fairly nondescript clear glass bottle with a rubber stopper, " +
                             "and is filled to the brim with a %^BOLD%^%^RED%^red%^RESET%^ liquid.");
            break;

        case 2:  tell_object(TP, "You glance at one of the many medium sized bottles.  " +
                             "It is a fairly nondescript clear glass bottle with a rubber stopper, " +
                             "and is filled to the brim with a %^RED%^blood colored%^RESET%^ liquid.");
            break;

        case 3:  tell_object(TP, "You glance at one of the many medium sized bottles.  " +
                             "It is a fairly nondescript clear glass bottle with a rubber stopper, " +
                             "and is filled to the brim with a %^BOLD%^%^GREEN%^RESET%^fluorescent green%^RESET%^ liquid.");
            break;

        case 4:  tell_object(TP, "You glance at one of the many medium sized bottles.  " +
                             "It is a fairly nondescript clear glass bottle with a rubber stopper, " +
                             "and is filled to the brim with a %^YELLOW%^yellow%^RESET%^ liquid.");
            break;

        case 5:  tell_object(TP, "You glance at one of the many medium sized bottles.  " +
                             "It is a fairly nondescript clear glass bottle with a rubber stopper, " +
                             "and is filled to the brim with a swirling %^BOLD%^%^GREEN%^g%^YELLOW%^r" +
                             "%^GREEN%^e%^YELLOW%^e%^GREEN%^n %^YELLOW%^a%^GREEN%^n%^YELLOW%^d%^GREEN%^ " +
                             "y%^YELLOW%^e%^GREEN%^l%^YELLOW%^l%^GREEN%^o%^YELLOW%^w%^RESET%^ liquid.");
            break;
        }
        tell_room(ETP, "" + TPQCN + " glances at one of the many medium-sized bottles.", TP);
        return 1;
    }
    if (str == "medium jar" || str == "medium jars") {
        switch (random(6)) {
        case 0:  tell_object(TP, "You pick up one of the medium sized glass jars for a closer " +
                             "look. It is carefully stoppered, but you can see that it contains " +
                             "a large number of %^BLUE%^small blue crystals%^RESET%^.");
            break;

        case 1:  tell_object(TP, "You pick up one of the medium sized glass jars for a closer " +
                             "look. It is carefully stoppered, but you can see that it contains " +
                             "some %^YELLOW%^saffron powder%^.");
            break;

        case 2:  tell_object(TP, "You pick up one of the medium sized glass jars for a closer " +
                             "look. It is carefully stoppered, but you can see that it contains " +
                             "a greasy-looking %^BOLD%^%^BLACK%^black powder%^RESET%^.");
            break;

        case 3:  tell_object(TP, "You pick up one of the medium sized glass jars for a closer " +
                             "look. It is carefully stoppered, but you can see that it contains " +
                             "a pile of %^MAGENTA%^fuming purple crystals%^RESET%^.");
            break;

        case 4:  tell_object(TP, "You pick up one of the medium sized glass jars for a closer " +
                             "look. It is carefully stoppered, but you can see that it contains " +
                             "a strange, s%^BOLD%^%^WHITE%^i%^RESET%^lvery liquid.");
            break;

        case 5:  tell_object(TP, "You pick up one of the medium sized glass jars for a closer " +
                             "look. It is carefully stoppered, but you can see that it contains " +
                             "a number of lumps of soft grey metal kept under oil.");
            break;
        }
        tell_room(ETP, "" + TPQCN + " examines one of the medium-sized glass jars.", TP);
        return 1;
    }
    if (str == "small jar" || str == "small jars") {
        switch (random(5)) {
        case 0:  tell_object(TP, "You pick up one of the small ceramic jars, which seem to " +
                             "contain spell components.  This one has %^BOLD%^%^GREEN%^some frogs' legs%^RESET%^.");
            break;

        case 1:  tell_object(TP, "You pick up one of the small ceramic jars, which seem to " +
                             "contain spell components.  This one has some %^YELLOW%^smelly " +
                             "%^BOLD%^%^BLACK%^ bat g%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^ano%^RESET%^.");
            break;

        case 2:  tell_object(TP, "You pick up one of the small ceramic jars, which seem to " +
                             "contain spell components.  This one has a number of pickled %^BOLD%^%^WHITE%^e" +
                             "%^BOLD%^%^RED%^y%^BOLD%^%^BLUE%^e%^BOLD%^%^RED%^b%^BOLD%^%^WHITE%^alls%^RESET%^.");
            break;

        case 3:  tell_object(TP, "You pick up one of the small ceramic jars, which seem to " +
                             "contain spell components.  This one has some %^BOLD%^%^RED%^phosphorus%^RESET%^.");
            break;

        case 4:  tell_object(TP, "You pick up one of the small ceramic jars, which seem to " +
                             "contain spell components.  This one has some some %^BOLD%^%^YELLOW%^tiny " +
                             "hearing trumpets%^RESET%^.");
            break;
        }
        tell_room(ETP, "" + TPQCN + " picks up a small ceramic jar and studies it.", TP);
        return 1;
    }
    if (str == "large jug" || str == "large jugs") {
        switch (random(3)) {
        case 0:  tell_object(TP, "You look at a big, heavy ceramic jug. As you peek inside, " +
                             "you can see a %^YELLOW%^shrunken, shrivelled head%^RESET%^ lurking at the bottom.");
            break;

        case 1:  tell_object(TP, "You look at a large, earthenware jug stashed under " +
                             "one of the workbench counters. Inside, there is a stash of severed " +
                             "fingers that appear to have been smeared in some sort wax. The ends " +
                             "of them appear to have been cut with a very sharp knife, possibly the " +
                             "result of some attempted diplomacy gone wrong.");
            break;

        case 2:  tell_object(TP, "You look at a big, heavy ceramic jug. Inside, you can make out " +
                             "what looks like a half-dissected human foot.");
            break;
        }
        tell_room(ETP, "Picking up a large jug, " + TPQCN + " examines its contents.", TP);
        return 1;
    }
    if (str == "small jug" || str == "small jugs") {
        switch (random(5)) {
        case 0:  tell_object(TP, "The small jug appears to contain some %^BOLD%^%^WHITE%^sow's milk%^RESET%^.");
            break;

        case 1:  tell_object(TP, "In this small jug is some shiny %^BOLD%^%^WHITE%^quicksilver%^RESET%^.");
            break;

        case 2:  tell_object(TP, "The jug is stuffed full of %^GREEN%^fresh cut nettles%^RESET%^.");
            break;

        case 3:  tell_object(TP, "A small jug full of %^GREEN%^newts' %^BOLD%^%^WHITE%^e" +
                             "%^RESET%^%^RED%^y%^BOLD%^%^WHITE%^e%^RESET%^%^GREEN%^balls%^RESET%^.");
            break;

        case 4:  tell_object(TP, "This small jug contains a clear liquid that smells like raw alcohol.");
            break;
        }
        tell_room(ETP, "Picking up a small jug, " + TPQCN + " examines its contents.", TP);
        return 1;
    }
    return 0;
}

int open(string str)
{
    if (!str) {
        return 0;
    }
    if (str == "small bottle") {
        switch (random(4)) {
        case 0..1:  tell_object(TP, "As you pull the stopper free of the bottle, a plume " +
                                "of %^BOLD%^%^GREEN%^nox%^RESET%^%^GREEN%^iou%^BOLD%^%^GREEN%^s green " +
                                "fumes%^RESET%^ erupts from the bottle and is gone, leaving you coughing " +
                                "and wiping your eyes.");
            tell_room(ETP, "A plume of green fumes rises as " + TPQCN + " opens a bottle and begins coughing.", TP);
            break;

        case 2..3:  tell_object(TP, "A sweet almond scent drifts up from the bottle as you " +
                                "open it, intoxicating without being sickly.");
            tell_room(ETP, "" + TPQCN + " closes " + TP->query_possessive() + " eyes and inhales " +
                      "as " + TP->query_subjective() + " opens a small bottle.", TP);
            break;
        }
        return 1;
    }
    if (str == "large jar") {
        tell_object(TP, "As you break the wax seal, the air is rent by a sudden, unearthly " +
                    "%^BOLD%^%^CYAN%^shriek%^RESET%^.  The stopper flies off in your hand and " +
                    "%^BOLD%^%^YELLOW%^shatters%^RESET%^ against the opposite wall. Bright shafts of " +
                    "%^BOLD%^%^CYAN%^blue light%^RESET%^ leap from the neck of the jar and a %^BOLD%^%^CYAN%^" +
                    "glowing blue spirit%^RESET%^ leaps out, laughing evilly. Once clear of the jar, it " +
                    "turns to look at you, its face curling into a terrifying rictus of anger before it " +
                    "turns away once more, vanishing up through the crack of the trapdoor and disappearing completely.", TP);
        tell_room(ETP, "" + TPQCN + " breaks the seal on a large jar, causing the air to fill with an " +
                  "unearthly %^BOLD%^%^CYAN%^shriek%^RESET%^.  The stopper flies out of " + TP->query_possessive() + " hand and " +
                  "%^BOLD%^%^YELLOW%^shatters%^RESET%^ against the opposite wall. Bright shafts of " +
                  "%^BOLD%^%^CYAN%^blue light%^RESET%^ leap from the neck of the jar and a %^BOLD%^%^CYAN%^" +
                  "glowing blue spirit%^RESET%^ leaps out, laughing evilly. Once clear of the jar, it " +
                  "turns to look at " + TPQCN + ", its face curling into a terrifying rictus of anger before it " +
                  "turns away once more, vanishing up through the crack of the trapdoor and disappearing completely.", TP);
        return 1;
    }
    if (str == "cupboard") {
        tell_object(TP, "You can't open the last cupboard - it's stuck.");
        tell_room(ETP, "" + TPQCN + " looks surprised when " + TP->query_subjective() + " can't open the cupboard.", TP);
        return 1;
    }
    return 0;
}

int pull(string str)
{
    if (!str) {
        tell_object(TP, "What are you trying to pull?");
        return 1;
    }
    if (str == "cupboard") {
        tell_object(TP, "You can't pull it hard enough. It's really stuck.");
        tell_room(ETP, "" + TPQCN + " braces " + TP->query_objective() + "self and pulls the cupboard " +
                  "with all " + TP->query_possessive() + " might, but it won't budge.", TP);
        return 1;
    }
    return 0;
}

int push(string str)
{
    if (!str) {
        tell_object(TP, "What are you trying to push?");
        return 1;
    }
    if (str == "cupboard") {
        tell_object(TP, "Pushing it won't help - it is designed to open outwards. It's just stuck.");
        tell_room(ETP, "" + TPQCN + " pushes on the cupboard like an idiot.  It's obviously supposed " +
                  "to open outward.", TP);
        return 1;
    }
    if (str == "handle") {
        tell_object(TP, "You push the brass handle and it shifts under your hand. There is a " +
                    "soft click, and the cupboard swings open, revealing a few bulging notebooks and a " +
                    "list pinned to the inside of the door.");
        tell_room(ETP, "" + TPQCN + " pushes on the brass handle and the cupboard door swings open with " +
                  "a soft click.", TP);
        door_open = 1;
        return 1;
    }
    return 0;
}

int trace(string str)
{
    if (!str) {
        tell_object(TP, "What are you trying to trace?");
        return 1;
    }
    if (str == "tubing" || str == "tubes" || str == "distillation" || str == "liquids") {
        tell_object(TP, "Your eyes swim a little as you follow the twisting " +
                    "path of the glass tubes all the way to the end, but eventually you " +
                    "can make out the final product of the distillation: a small glass vial " +
                    "into which a thick, %^BOLD%^%^BLACK%^blackish %^RESET%^%^MAGENTA%^purple" +
                    "%^RESET%^ is dripping. It moves like treacle, smells like creosote, and " +
                    "causes a little whiff of %^BOLD%^%^WHITE%^white smoke%^RESET%^ to rise " +
                    "every time another drop falls into the jar.");
        tell_room(ETP, "" + TPQCN + " seems strangely focused on the distillation for a moment.", TP);
        return 1;
    }
    tell_object(TP, "You can't trace that!");
    return 1;
}

/*Twisting the handle is a trap.  Twisted clockwise, the trap sets off poison gas.  Counter-clockwise, the handle sends a jolt of energy to shock the person twisting it.*/

int twist(string str)
{
    int i, j, poison;
    object* inven;
    inven = all_living(TO);
    j = sizeof(inven);

    if (!str) {
        tell_object(TP, "What are you trying to twist?");
        return 1;
    }
    if (str == "handle") {
        tell_object(TP, "Clockwise or counter-clockwise?");
        return 1;
    }
    if (str == "handle clockwise") {
        if (TP->query_true_invis()) {
            return 0;
        }

        tell_object(TP, "%^YELLOW%^You twist the handle clockwise and a strange gas fills the room!");
        tell_room(ETP, "%^YELLOW%^" + TPQCN + " twists the handle, and a strange gas fills the room!", TP);
        for (i = 0; i < j; i++) {
            if (!objectp(inven[i])) {
                continue;
            }
            if (inven[i] == TO) {
                continue;
            }
            if (inven[i] == TP) {
                continue;
            }
            if (inven[i]->query_true_invis()) {
                continue;
            }
            if (!"daemon/saving_d"->saving_throw(inven[i], "paralyzation_poison_death")) {
                tell_object(inven[i], "%^BOLD%^%^GREEN%^The gas seeps into your lungs!");
                poison = roll_dice(10, 10);
                inven[i]->add_poisoning(poison);
                inven[i]->setPoisoner(TO);
            }else {
                tell_object(inven[i], "%^YELLOW%^The sickly gas causes you to cough but little more.");
                inven[i]->do_damage("torso", random(20) + 20);
            }
            if (!objectp(inven[i])) {
                continue; // added to (hopefully) stop bugs (undead dying, etc.) *Styx*  8/15/03
            }
            inven[i]->add_attacker(TO);
            inven[i]->continue_attack();
            inven[i]->remove_attacker(TO);
        }
        if (!"daemon/saving_d"->saving_throw(TP, "paralyzation_poison_death")) {
            tell_object(TP, "%^YELLOW%^The %^GREEN%^gas %^YELLOW%^fills your lungs and " +
                        "weakens your body!");
            poison = roll_dice(15, 10);
            TP->add_poisoning(poison);
            TP->setPoisoner(TO);
            return 1;
        }
        tell_object(TP, "%^YELLOW%^Seeing the gas, you instinctively hold your breath, " +
                    "taking in as little as possible.");
        TP->do_damage("torso", random(30) + 25);
        TP->add_attacker(TO);
        TP->continue_attack();
        TP->remove_attacker(TO);
        return 1;
    }
    if (str == "handle counter-clockwise" || str == "handle counterclockwise") {
        tell_object(TP, "As you twist the handle, a sudden %^BOLD%^%^YELLOW%^jolting " +
                    "%^CYAN%^arc%^RESET%^ of %^BOLD%^%^RED%^energy%^RESET%^ lashes out from the " +
                    "apparatus connected to the column in the center of the room, striking you.");
        tell_room(ETP, "As " + TPQCN + " twists the handle, a sudden %^BOLD%^%^YELLOW%^jolting " +
                  "%^CYAN%^arc%^RESET%^ of %^BOLD%^%^RED%^energy%^RESET%^ lashes out from the " +
                  "apparatus connected to the column in the center of the room, striking " + TP->query_objective() + ".", TP);
        tell_room(ETP, "%^BOLD%^%^WHITE%^The %^YELLOW%^energy %^WHITE%^flickers round the " +
                  "apparatus, seeming to build up again.");
        TP->do_damage("torso", random(50) + 30);
        TP->add_attacker(TO);
        TP->continue_attack();
        TP->remove_attacker(TO);
        return 1;
    }
}

/*
   read list (only once the cupboard door is open): should give a list of the people witnessed by the unseen guardians (see Library) trying to access the Summoning Room, or committing other misdemeanours. The list should give the name or description, the date they were seen, and what their misdemeanour was. Perhaps if someone managed to access the list, they also ought to be able to add/remove names?)
 */
