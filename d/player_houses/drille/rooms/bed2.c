#include <std.h>
#include "../drille.h"
inherit VAULT;

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("The Pink Room");
    set_short("%^BOLD%^%^WHITE%^The %^MAGENTA%^Pink %^WHITE%^Room%^RESET%^");
    set_long("%^BOLD%^%^MAGENTA%^This room is painted in several different "
"%^CYAN%^shades %^MAGENTA%^of pink. The walls are decorated with a myriad of "
"various images and drawings. So many, in fact, it is almost dazzling. They "
"depict everything from cute %^BLUE%^butteflies %^MAGENTA%^and %^BLUE%^"
"sparrows %^MAGENTA%^to mischievous %^YELLOW%^satyrs %^MAGENTA%^and "
"%^YELLOW%^dryads%^MAGENTA%^, as well as %^GREEN%^candy cane forests "
"%^MAGENTA%^and %^GREEN%^dewy meadows%^MAGENTA%^. The %^WHITE%^bed "
"%^MAGENTA%^has an ornate frame and has been painted all white. Close to the "
"bed is a small night stand, on top of which is a vase holding a bouquet of "
"wild %^RESET%^%^GREEN%^flowers%^BOLD%^%^MAGENTA%^. The window looks out over "
"the forest outside.%^RESET%^");
    set_smell("default","%^BOLD%^%^GREEN%^The flowers give off a fresh and "
"sweet scent.%^RESET%^");
    set_listen("default","%^BOLD%^%^CYAN%^The rustling of the winds can be "
"heard through the window.%^RESET%^");
    set_items(([
      "bed" : "%^BOLD%^%^WHITE%^The bed looks very comfortable and soft. The "
"mattress is down-filled and has a thick quilt is on top. Both the quilt and "
"the sheets are colored %^MAGENTA%^pink%^WHITE%^. Several plush, %^RESET%^"
"%^GREEN%^lime green %^BOLD%^%^WHITE%^pillows are scattred over the bed. The "
"frame is beautifully ornate, sporting several engraved butterflies.%^RESET%^",
      "window" : "%^GREEN%^The great deep forest can be seen through the "
"window.%^RESET%^",
    ]));
    set_exits(([
      "kitchen" : ROOMS"kitchen",
    ]));
    set_door("pink door",ROOMS"kitchen","kitchen",0);
    set_door_description("pink door", "%^BOLD%^%^MAGENTA%^This is a standard "
"oak door, made of heavy oaken planks bound together with iron rivets. What "
"sets it apart from other doors is the fact its painted pink.%^RESET%^");
}
