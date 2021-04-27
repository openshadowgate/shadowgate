#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("no starve",1);
    set_property("no scry",1);
    set_name("An enclosed fire-lit demiplane");
    set_short("%^RESET%^%^RED%^An enclosed %^BOLD%^fi%^YELLOW%^r%^RED%^e-lit %^RESET%^%^RED%^demiplane%^RESET%^");
    set_long("%^RESET%^%^RED%^This chamber is lit on all sides by %^BOLD%^bri%^WHITE%^l%^YELLOW%^li%^RED%^ant "
"flam%^YELLOW%^e%^RED%^s%^RESET%^%^RED%^, rising up from the floor and seemingly unrestrained.  At once the "
"area seems both enclosed and not, as the flickering shadows beyond the fire fade back into %^BLUE%^darkness"
"%^RED%^, leaving you only to wonder if there are walls beyond or not.  Despite the flames, the air is "
"surprisingly %^CYAN%^cool%^RED%^, almost chill, and it carries the faint coppery scent of %^BOLD%^fr%^RESET%^"
"%^RED%^es%^BOLD%^h blood%^RESET%^%^RED%^.  The floor is made of solid stone, %^BOLD%^%^WHITE%^icy-c%^CYAN%^o"
"%^WHITE%^ld %^RESET%^%^RED%^under your feet, despite the apparent inferno that borders it on all sides.  The "
"only defining point to the enclosed area is what appears to be an altar, %^BOLD%^%^BLACK%^inky-black %^RESET%^"
"%^RED%^and undecorated save for a scattering of %^BOLD%^%^BLACK%^bla%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k "
"vi%^RESET%^%^MAGENTA%^ol%^BOLD%^%^BLACK%^ets %^RESET%^%^RED%^that appear to have been simply discarded there, "
"and a %^ORANGE%^leather handle%^RED%^.%^RESET%^\n");
    set_smell("default","%^BOLD%^%^WHITE%^Chi%^CYAN%^l%^WHITE%^l %^RESET%^%^MAGENTA%^air fills the room, "
"tainted by the faint coppery scent of %^RED%^blood%^MAGENTA%^.%^RESET%^");
    set_listen("default","%^CYAN%^There is no sound here but the constant flicker and lap of %^RED%^fl%^BOLD%^a"
"%^RESET%^%^RED%^mes%^CYAN%^.%^RESET%^");
    set_items(([
      ({ "fire","flame","flames" }) : "%^BOLD%^%^RED%^Bri%^WHITE%^l%^YELLOW%^li%^RED%^ant flam%^YELLOW%^e"
"%^RED%^s %^RESET%^%^RED%^flicker around the entire room's perimeter, enclosing the stone floor from the "
"darkness beyond.%^RESET%^",
      ({ "shadows","darkness" }) : "%^RESET%^%^RED%^Deep %^BLUE%^shadows %^RED%^encircle the room beyond "
"the blazing inferno, leaving you only to wonder if walls and a roof lie beyond.%^RESET%^",
      "floor" : "%^RESET%^%^RED%^Solid stone forms the floor, %^BOLD%^%^WHITE%^icy-c%^CYAN%^o%^WHITE%^ld "
"%^RESET%^%^RED%^to the touch despite the blazing fire that surrounds it on all sides.%^RESET%^",
      "altar" : "%^RESET%^%^RED%^The altar is %^BOLD%^%^BLACK%^inky-black%^RESET%^%^RED%^, a slab "
"of thick stone that forms the only point of orientation in the fire-encircled demiplane.  No cloth or candles "
"serve to glorify the altar; only a scattering of %^BOLD%^%^BLACK%^bla%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k "
"vi%^RESET%^%^MAGENTA%^ol%^BOLD%^%^BLACK%^ets %^RESET%^%^RED%^are strewn across its surface, and beside them a "
"%^ORANGE%^leatherbound handle%^RED%^. Looking closer, you realise at the very base of it is a small niche, no "
"bigger than a mousehole.%^RESET%^",
    ]));
}
