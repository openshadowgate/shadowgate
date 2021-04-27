//cog_room.c - For Stefano's tower.  Coded by Circe 10/2/03
#include <std.h>
#include "stefano.h"
#include <daemons.h>

inherit VAULT;
int open_exit;

void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("A room full of moving cogs");
    set_short("A room full of moving cogs");
    set_long("Most of this level of the tower is taken up with " +
             "a mechanism of turning cogs, driven by a shaft coming through " +
             "the south wall from the waterwheel outside. The cogs are carefully " +
             "crafted and maintained, and turn almost silently on well greased axles.  " +
             "The final cog in the series is a large one, turning slowly parallel to " +
             "the floor in the middle of the room. It drives a dark shaft which " +
             "disappears upwards through a hole in the ceiling. A narrow walkway of " +
             "stone leads on from the stairwell, giving access to the mechanism for " +
             "maintenance purposes. There are no arrowslits on this level of the tower, " +
             "and the walls are quite blank and bare." +
             "\n");
    set_smell("default", "The air smells of metal and grease.");
    set_listen("default", "You can hear the quiet turning of the cogs.");
    set_items(([
                   ({ "walkway", "walk way", "narrow walkway" }) : "The narrow walkway is made of stone slabs " +
                   "held together on a metal framework.  One of the slabs looks unsteady while the others " +
                   "seem stable.",
                   ({ "slab", "uneven slab", "unsteady slab" }) : "One slab at the far end of the walkway has " +
                   "sunk down a little, leaving it uneven and probably a bit of a trip hazard.  Another, " +
                   "sturdier slab just beside it helps support it.",
                   "slab 2" : "The slab alongside the uneven slab looks perfectly normal and uninteresting.",
                   "cogs" : "The cogs are all fashioned from %^BOLD%^%^BLACK%^black iron%^RESET%^ " +
                   "and look well made and sturdy. They mesh together precisely, minimising the " +
                   "noise from the mechanism to barely more than a whisper. Although they turn slowly, " +
                   "there is a relentless unstoppability to the movement which suggests that touching " +
                   "them would probably not be a good idea unless you have a finger or two you can spare.  " +
                   "Strangely, some of the cogs seem to be independent of the main mechanism.",
                   "independent cogs" : "Some of the cogs which are detached from the main mechanism " +
                   "turn clockwise, some counter-clockwise, and some are completely still.",
                   "independent cog" : "This small cog, detached from the main mechanism, turns slowly counter-clockwise.",
                   "independent cog 2" : "This medium sized cog, detached from the main mechanism, appears to be completely still.",
                   "independent cog 3" : "This small cog, detached from the main mechanism, turns slowly clockwise.",
                   "independent cog 4" : "This large cog, detached from the main mechanism, turns slowly clockwise.",
                   "independent cog 5" : "This medium sized cog, detached from the main mechanism, turns slowly counter-clockwise.",
                   "independent cog 6" : "This large cog, detached from the main mechanism, turns slowly counter-clockwise.",
                   "independent cog 7" : "This small cog, detached from the main mechanism, appears to be completely still.",
                   "independent cog 8" : "This medium sized cog, detached from the main mechanism, turns slowly clockwise.",
                   "walls" : "The walls are blank and bare. There is a little condensation on them, no doubt due to the river nearby.",
                   "floor" : "The narrow walkway between the cogs is paved with stone slabs.",
                   "slabs" : "The slabs look mostly well laid, but one has become slightly uneven over time. You wouldn't want to trip over it in here, given the risk of falling into the cog mechanism.",
                   "floor" : "The narrow walkway between the cogs is paved with stone slabs.",
               ]));
    set_search("default", "The two slabs seem to be fairly interesting.");
    set_search("slabs", "The first slab looks incredibly unstable, while the second seems fairly non-descript.");
    set_search("slab", "The first slab could probably be tread upon, but it is hard to tell what the consequences might be.");
    set_search("slab 2", "The slab looks solid at first glance, but looking closer, you notice that it is raised slightly.  You might be able to stomp it into place.");
    set_search("cogs", "Looking more closely, you spot that a few independent cogs seem not to be " +
               "connected to the main mechanism, and either turn on their own, or not at all.");
    set_exits(([
                   "up" : SHOUSE "lab"
               ]));
    set_door("trapdoor", SHOUSE "lab", "up", "rune_key");
    set_door_description("trapdoor", "The trapdoor is made from solid oak, reinforced with bands of iron.");
    set_locked("trapdoor", 1, "lock");
    lock_difficulty("trapdoor",  "/daemon/player_housing"->get_phouse_lock_dc("rare"), "lock");
    open_exit = 0;
}

void init()
{
    ::init();
    add_action("turn", "turn");
    add_action("stomp", "stomp");
    add_action("tread_em", "tread");
    add_action("tread_em", "walk");
}

int tread_em(string str)
{
    if (str != "on slab" && str != "slab" && str != "unsteady slab" && str != "on unsteady slab") {
        tell_object(TP, "Where are you trying to walk?");
        return 1;
    }else {
        if (!objectp(TP)) {
            return 1;
        }
        tell_object(TP, "You walk to the unsteady slab and step onto it.  The slab " +
                    "%^BOLD%^%^YELLOW%^lurches%^RESET%^ downwards as you tread on it!");
        tell_room(ETP, "Walking out on the walkway, " + TPQCN + " steps onto the unsteady slab.  The " +
                  "slab %^BOLD%^%^YELLOW%^lurches%^RESET%^ downward!", TP);
        if (TP->query_stats("dexterity") > random(10) + 12) {
            tell_object(TP, "Luckily, you managed to keep your balance!  Otherwise, those cogs " +
                        "would surely eat you alive.");
            tell_room(ETP, "" + TPQCN + " breathes a sigh of relief as " + TP->query_subjective() + " manages " +
                      "to keep " + TP->query_possessive() + " balance above the spinning cogs!", TP);
            return 1;
        }else {
            tell_object(TP, "%^YELLOW%^You are dumped down into the cogs and feel your %^WHITE%^bones " +
                        "%^YELLOW%^being %^RED%^crushed%^YELLOW%^!%^RESET%^");
            tell_room(ETP, "%^YELLOW%^" + TPQCN + " is dumped into the cogs and lets out a " +
                      "gut-wrenching scream as " + TP->query_possessive() + " %^WHITE%^bones %^YELLOW%^are " +
                      "%^RED%^crushed%^YELLOW%^!%^RESET%^", TP);
            TP->do_damage("torso", random(25) + 50);
            TP->add_attacker(TO);
            TP->continue_attack();
            TP->remove_attacker(TO);
            if (!TP->query_ghost()) {
                tell_object(TP, "You shudder as you are dropped back onto the floor, luckily still alive.");
                tell_room(ETP, "" + TPQCN + " drops finally to the floor with a shudder.", TP);
                return 1;
            }else {
                return 1;
            }
        }
        return 1;
    }
}

int stomp(string str)
{
    if (str != "slab 2" && str != "on slab 2") {
        tell_object(TP, "What are you trying to stomp on?");
        return 1;
    }else {
        if (open_exit) {
            tell_object(TP, "You stomp hard on the slab beside the uneven one.  There is a click, " +
                        "and the uneven slab swings upward, hiding the exit.");
            tell_room(ETP, "" + TPQCN + " stomps hard on the slab beside the uneven one.  There is a click, " +
                      "and the uneven slab swings upward, hiding the exit.", TP);
            remove_exit("down");
            "/d/attaya/tunnels/rooms/library"->remove_exit("up");
            tell_room("/d/attaya/tunnels/rooms/library", "The slab lowers with a light click, hiding the upward exit.");
            open_exit = 0;
            return 1;
        }else {
            tell_object(TP, "You stomp hard on the slab beside the uneven one. There is a click, " +
                        "and the uneven slab swings quietly open, revealing an exit down.");
            tell_room(ETP, "" + TPQCN + " stomps hard on the slab beside the uneven one.  There is a " +
                      "click, and the uneven slab swings quietly open, revealing an exit down.", TP);
            add_exit("/d/attaya/tunnels/rooms/library", "down");
            "/d/attaya/tunnels/rooms/library"->add_exit("/d/player_houses/stefano/cog_room", "up");
            tell_room("/d/attaya/tunnels/rooms/library", "A slab in the ceiling slides upward, revealing an opening!");
            open_exit = 1;
            return 1;
        }
    }
    return 1;
}

int turn(string str)
{
    if (!str || str == "cog" || str == "cogs" || str == "independent cog") {
        tell_object(TP, "Turn which independent cog which way?  Clockwise or counter-clockwise?");
        return 1;
    }
    if (str == "independent cog 1 counter-clockwise") {
        tell_object(TP, "It's already going that way!");
        return 1;
    }
    if (str == "independent cog 1 clockwise") {
        tell_object(TP, "With some effort, you make the small cog turn in the other " +
                    "direction. Nothing happens, and when you let go of it, it goes back to " +
                    "turning the way it was.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 2 counter-clockwise") {
        tell_object(TP, "You turn the medium sized cog counter-clockwise. Nothing happens, " +
                    "and when you let go of it, it stops moving again.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 2 clockwise") {
        tell_object(TP, "You turn the medium sized cog clockwise. Nothing happens, " +
                    "and when you let go of it, it stops moving again.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 3 counter-clockwise") {
        tell_object(TP, "With some effort, you make the small cog turn in the other direction.  " +
                    "Nothing happens, and when you let go of it, it goes back to turning the way it was.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 3 clockwise") {
        tell_object(TP, "It's already going that way!");
        return 1;
    }
    if (str == "independent cog 4 counter-clockwise") {
        tell_object(TP, "With a heroic effort, you manage to make the large cog turn in the " +
                    "other direction.  Nothing happens, and when you let go of it, it goes back to " +
                    "turning the way it was.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 4 clockwise") {
        tell_object(TP, "It's already going that way!");
        return 1;
    }
    if (str == "independent cog 5 counter-clockwise") {
        tell_object(TP, "It's already going that way!");
        return 1;
    }
    if (str == "independent cog 5 clockwise") {
        tell_object(TP, "With a considerable effort, you make the medium-sized cog turn" +
                    " in the other direction. Nothing happens, and when you let go of it, it goes " +
                    "back to turning the way it was.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 6 counter-clockwise") {
        tell_object(TP, "It's already going that way!");
        return 1;
    }
    if (str == "independent cog 6 clockwise") {
        tell_object(TP, "With a heroic effort, you manage to make the large cog turn in the " +
                    "other direction.  Nothing happens, and when you let go of it, it goes back to " +
                    "turning the way it was.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
/*
   NB turning inedpendent cog 7 counter-clockwise makes the mechanism behind the handprint in the LIBRARY active, so that the secret door can be opened. Turning it clockise makes it inactive again.  This still needs to be added.
 */
    if (str == "independent cog 7 counter-clockwise") {
        tell_object(TP, "You turn the small cog counter-clockwise. Nothing happens, " +
                    "and when you let go of it, it stops moving again.  You almost think you hear " +
                    "a small click, but it's gone as quickly as it came.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        ("/d/attaya/tunnels/rooms/library")->set_property("activated", 1);
        return 1;
    }
    if (str == "independent cog 7 clockwise") {
        tell_object(TP, "You turn the small cog clockwise. Nothing happens, " +
                    "and when you let go of it, it stops moving again.  You almost think you hear " +
                    "a small click, but it's gone as quickly as it came.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        ("/d/attaya/tunnels/rooms/library")->remove_property("activated");
        return 1;
    }
    if (str == "independent cog 8 counter-clockwise") {
        tell_object(TP, "With a considerable effort, you make the medium-sized cog turn" +
                    " in the other direction. Nothing happens, and when you let go of it, it goes " +
                    "back to turning the way it was.");
        tell_room(ETP, "" + TPQCN + " reaches in carefully and turns one of the cogs.", TP);
        return 1;
    }
    if (str == "independent cog 8 clockwise") {
        tell_object(TP, "It's already going that way!");
        return 1;
    }
    tell_object(TP, "Turn which independent cog which way?  Clockwise or counter-clockwise?");
    return 1;
}
