#include <std.h>
#include <daemons.h>

inherit VAULT;
#define OWNERS ({ "slore", "mystra" })
string* killers;

void create()
{
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no sticks", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("A small alchemist shop");
    set_long("In front of you and slightly off-center to the left is "
             "a small counter with another door behind it.  Two shelves hang on "
             "the eastern wall, one on either side of the entry way.  On the "
             "north wall are three larger shelves with some %^ORANGE%^old, torn, "
             "raggedy books %^RESET%^on them.  To the south, some old crates are "
             "stacked up against the wall with boxes lying in front of them.  More "
             "towards the center of the room is a very impressive six ft. tall "
             "statue.  On the western wall, behind the counter, are a great deal "
             "of small storage containers, each one individually labeled.");
    set_listen("default", "A small murmur of chatting customers and passersby "
               "can be heard in the silence.");
    set_smell("default", "The odor you've been smelling seems to be coming "
              "from behind the counter.");
    set_items(([
                   "shelves" : "On the shelves are several jars, labeled and filled with "
                   "some kind of fluid.  Various parts of humanoid and animal anatomies "
                   "are floating in the fluids.",
                   "counter" : "A young lad is tending the counter for the owner, which "
                   "has some strange glyphs scratched on it.",
                   "books" : "Most of these books are so torn, they would probably fall "
                   "apart when handled.  Others are so dirty that you probably couldn't "
                   "read them even if they weren't torn.  A few might be worthwhile to "
                   "keep, but other than that, they are a shabby decoration.",
                   ({ "crates", "boxes" }) : "These are boxes and crates apparently left here "
                   "by the movers, just waiting for something to be done with them.",
                   "statue" : "A lifesize likeness of the Lady of Magic herself.  It is "
                   "carved with remarkable detail.  Her long, dark, flowing hair blows "
                   "in a mimicked breeze, a dark colored robe adorns the breathtakingly "
                   "beautiful body, and the detail extends right down to the hand carved "
                   "jewelry all about her hands and neck.  There is an inscription on "
                   "the base of the statue.",
                   "inscription" : "Perhaps you should try to read it.",
                   ({ "containers", "container" }) : "Each container is labeled to hold a "
                   "different component for magical use.  There are so many of them.",
               ]));
    set_exits(([
                   "west" : "/d/dagger/Torm/city/c75",
                   "east" : "/d/player_houses/slore/backroom",
               ]));
    set_door("door", "/d/player_houses/slore/backroom", "east", "slore key",
             "ornate lock");
    set_lock_description("door", "ornate lock", "This is an ornate lock.  "
                         "At first glance it looks mostly ornamental.");
    set_locked("door", 1, "ornate lock");
    lock_difficulty("door",  "/daemon/player_housing"->get_phouse_lock_dc("good"), "ornate lock");
    set_door("carved door", "/d/player_houses/slore/backroom", "west", 0);
    set_door_description("carved door", "In addition to the carving, this wooden "
                         "door also an opening cut all the way through it in the shape of a "
                         "crescent moon.");
}

void init()
{
    ::init();
    add_action("unlock_me", "waves");
}

int __Read(string str)
{
    if (str == "inscription" || str == "statue") {
        write("The inscription reads:\n  %^YELLOW%^Love magic for itself, "
              "not just a ready weapon to attempt to reshape the realms to your will.");
        return 1;
    }
    return ::__Read(str);
}

void reset()
{
    ::reset();
    if (!present("dean")) {
        find_object_or_load("/d/player_houses/slore/misc/dean_npc")->move(TO);
    }
}

void unlock_me(string str)
{
    if (str != "hands") {
        return 0;
    }
    if ((member_array((string)TPQN, OWNERS) == -1) && !avatarp(TP)) {
        return 0;
    }
    find_object_or_load("/d/player_houses/slore/backroom");
    tell_object(TP, "You wave your hands over your eyes, leaving them a "
                "bright-silver color momentarily and you hear the lock click.");
    tell_room(ETP, "" + TPQCN + " waves her hands over her eyes, leaving them a "
              "bright-silver color momentarily as you hear a soft click.", TP);
    if (!query_locked("door", "ornate lock")) {
        TO->set_open("door", 0);
        TO->set_locked("door", 1, "ornate lock");
        "/d/player_houses/slore/backroom"->set_locked("door", 1, "ornate lock");
        "/d/player_houses/slore/backroom"->set_open("door", 0);
        return 1;
    }
    TO->set_locked("door", 0, "ornate lock");
    "/d/player_houses/slore/backroom"->set_locked("door", 0);
    return 1;
}
