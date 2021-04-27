#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("smithy",1);
    set_name("A neatly kept forge");
    set_short("%^BOLD%^%^RED%^A neatly kept forge%^RESET%^");
    set_long("%^RESET%^A wave of %^BOLD%^%^RED%^heat %^RESET%^hits you when you "
"enter the forge. It is very neatly kept and everything seems to be in "
"perfect order. Several shelves line the walls, containing everything a "
"master of his trade could possibly need. %^CYAN%^Hammers %^RESET%^of various "
"shapes and sizes, %^BOLD%^%^BLACK%^plyers %^RESET%^with wooden handles, "
"thick and strong leather %^ORANGE%^gloves%^RESET%^, jars of coloured "
"%^MAGENTA%^oil %^RESET%^and all kinds of different %^RED%^tools %^RESET%^for "
"sharpening, smoothing, cleaning and engraving%^RESET%^. Every object has its "
"own place and every jar is duly labelled. A stone %^BOLD%^encasement "
"%^RESET%^has been built in one of the corners, holding the heap of %^YELLOW%^"
"b%^RED%^u%^YELLOW%^r%^RED%^n%^YELLOW%^i%^RED%^n%^YELLOW%^g %^RESET%^coals "
"which are used to heat the metal. A large %^BOLD%^%^CYAN%^bellows %^RESET%^"
"is built into the encasement to provide the %^YELLOW%^fire %^RESET%^with "
"%^BOLD%^%^CYAN%^air%^RESET%^. Next to the fire stands a strong and sturdy "
"%^BOLD%^%^BLUE%^anvil%^RESET%^, and beside that a large basin containing "
"dirty water. In the opposite corner stand two large barrels, used for "
"storing billets of metal and blocks of wood. Above the barrels is a large "
"rack, where finished weapons can be stored.%^RESET%^");
    set_smell("default","%^ORANGE%^The smell from the burning coals mix with "
"the odours of metal, wood and oil.%^RESET%^");
    set_listen("default","%^BOLD%^%^RED%^A loud roar rises from the fire pit "
"containing the burning coals.%^RESET%^");
    set_items(([
      "hammers" : "%^CYAN%^The hammers are very sturdy and strong. The iron "
"heads vary in size and have been forged with a flat facing on one side and a "
"round ball peen on the other.%^RESET%^",
      "pliers" : "%^BOLD%^%^BLACK%^The large, long handled pliers are used "
"to lift the glowing metal off the fire and hold it in place on the "
"anvil.%^RESET%^",
      "gloves" : "%^ORANGE%^Long, think leather gloves are a necessity to "
"protect the hands and lower arms of the smith.%^RESET%^",
      ({"jars"}) : "%^MAGENTA%^These jars contain the oils used to colour the "
"weapons. Metallic ink has been mixed into the oil which is then applied to "
"the metal and burnt into the surface.%^RESET%^",
      ({"tools"}) : "%^RED%^These tools are used to sharpen, smooth, clean "
"and engrave weapons. Knives, prying tools, whetstones, cloth rags, rough "
"brushes and files all in perfect order line the shelves waiting to be "
"used.%^RESET%^",
      ({"anvil"}) : "%^BOLD%^%^BLUE%^Standing on a strong, secure block of "
"heavy bricks, the anvil is the central element of the forge. It is shaped "
"like a solid, square block with two horns on each side.%^RESET%^",
      ({"basin"}) : "%^RESET%^The water in this basin is very dirty as it is "
"used to cool of the metal when the work is done. Small fragments of various "
"metals swirl around in the water.%^RESET%^",
    ]));
    set_exits(([
      "kitchen" : ROOMS"kitchen",
    ]));
    set_door("forge door",ROOMS"kitchen","kitchen",0);
    set_door_description("forge door", "%^ORANGE%^This is an oak door "
"enforced with steel plates. It is made of heavy oaken planks bound together "
"with iron rivets.%^RESET%^");
    set_locked("forge door",1);
}
