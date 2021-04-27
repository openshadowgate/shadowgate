#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Conference room of the magi");
    set_long("You enter a large room with a few round tables, some "+
        "strangely designed chairs, spider webs hanging about, and "+
        "various remnants of used spell components on the ground.  "+
        "The walls are of the common gray stone used throughout the "+
        "tower, but they are covered with mystical paintings and "+
        "tapestries depicting scenes of magic and mysticism.  This "+
        "room is generally used as a meeting place for all users "+
        "of magic to discuss their uses and ways of manipulating "+
        "spells, with their differences set aside, if any.  A "+
        "large bulletin board is hung on the west wall for message "+
        "exchange between magic-users.  An archway leads south to "+
        "the levitation room.");
    set_property("light",2);
    set_property("indoors",1);
    set_items( ([
        ({"tables","round tables"}):"Around the room, there "+
            "are four large round tables with various types of "+
            "chairs around them.  The tables don't take up more "+
            "than half of the large room, but still are big enough "+
            "to provide seating for any mage who wants it.  Across "+
            "the table, there are a few burn marks from a few "+
            "poorly planned spell demonstrations, and blood from "+
            "others.",
        ({"chairs","strangely designed chairs","strange chairs"}):
            "Many chairs surround the large tables.  You can judge "+
            "that there are at least fifty of them, all from "+
            "different origins, thus differing styles.  Some "+
            "resemble dragons, others use flowing sweeps of wood "+
            "to give an enchanting appearance to it.  Such a "+
            "collection of chairs gives the room a unique and "+
            "mystical appearance.",
        ({"spiderwebs","spider webs","cobwebs","cob webs"}):"Spider "+
            "webs hang near the corners of the ceiling.",
        ({"remnants","spell components","ground","down","floor"}):
            "Useless scraps of spell components coat the ground.  "+
            "It is obvious that much spell casting goes around "+
            "here.",
        ({"walls","wall","stone","gray stone"}):"The walls are "+
            "made of a cold and featureless gray stone, but are "+
            "covered with paintings and tapestries.",
        ({"paintings","painting","tapestry","tapestries",
            "mystical paintings","mystical painting"}):"Tapestries "+
            "and paintings show various scenes of the many forms of "+
            "magic in ShadowGate.  Many pictures are of powerful "+
            "and feared magi casting fantastic and complex spells, "+
            "while others show dragons, undead armies, and various "+
            "legendary artifacts.",
    ]) );
    set_exits( ([
        "south":ROOMS"tower1"
    ]) );
    set_smell("default","The air is clean but somewhat stuffy.");
    set_listen("default","Your own footsteps echo through this place.");
}