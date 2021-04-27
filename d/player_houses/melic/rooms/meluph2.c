//Coded by Diego//

#include <std.h>
#include "../melic.h"
inherit VAULT;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Second Floor Hallway");
    set_long(
        "%^GREEN%^" +
        "There is a door in the north, and east wall. The northern door is somewhat more " +
        "massive then the other doors on this floor. Both doors have locks on them but you " +
        "guess they are ment to keep people out, not to lock anyone in. The walls are coverd " +
        "with large tapestrys and there is a sign above the north door. The corridor is warm " +
        "here and a bit more 'homely' then other parts of the castle. Lit torches line the " +
        "walls.\n" +
        "%^RESET%^"
        );
    set_property("indoors", 1);
    set_property("light", 2);
    set_smell("default", "Only a hint of dust tickles your nose.");
    set_listen("default", "It is quiet and calm.");
    set_items(([
                   "plaque" : "%^BOLD%^%^RED%^Castle Lord's Room%^RESET%^"
               ]));

    set_door("east room door", MROOMS + "melbed3", "east", "mithril key");
    set_locked("east room door", 0, "lock");
    (MROOMS + "melbed3")->set_locked("east room door", 0, "lock");
    set_door_description("east room door", "The door is wooden, much as you would expect.");
    set_string("east room door", "open", "You open the door and see a bedroom.\n");

    set_door("north room door", MROOMS + "melbed4", "north", "mithril key");
    set_locked("north room door", 1, "lock");
    (MROOMS + "melbed4")->set_locked("north room door", 1, "lock");
    set_door_description("north room door", "The door is wooden and is reinforced with " +
                         "iron bars.  There are elaborate decorative carvings on this door and a plaque is " +
                         "mounted in the middle at eye level of a normal sized human.");
    lock_difficulty("north room door",  "/daemon/player_housing"->get_phouse_lock_dc("poor"), "lock");
    set_string("north room door", "open", "You open the door and see a bedroom.\n");
    set_trap_functions(({ "north room door" }), ({ "spear_em" }), ({ "pick" }));

    set_exits(([
                   "north" : MROOMS + "melbed4",
                   "south" : MROOMS + "meluph1",
                   "east"  : MROOMS + "melbed3"
               ]));
}

int spear_em(string str)
{
    if (str != "lock") {
        return 0;
    }
    tell_object(TP, "As you work on the lock with your tools you feel a sudden hitch " +
                "and then a louder click.");
    TP->force_me("emote gulps");
    tell_room(TO, "%^BOLD%^%^RED%^A small hole appears on the west side of the wall.");
    tell_room(TO, "%^BOLD%^%^RED%^A spear shoots out with great velocity!");
    tell_object(TP, "The spear flies directly at you with deadly accuracy!");
    if ((int)TP->query_stats("dexterity") > random(25)) {
        tell_room(TO, "%^BOLD%^%^RED%^The spear flies into the far wall and explodes " +
                  "violently in a loud F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!");
        return 0;
    }
    tell_room(TO, "%^BOLD%^%^RED%^The spear flies into " + TPQCN + " and explodes in a loud " +
              "F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!", TP);
    tell_object(TP, "%^BOLD%^%^RED%^The spear flies into you and explodes in a loud " +
                "F%^YELLOW%^L%^RED%^A%^YELLOW%^S%^RED%^H%^YELLOW%^!");
    TP->do_damage("torso", roll_dice(10, 10));
    TP->add_attacker(TO);
    TP->continue_attack();
    return 0;
}
