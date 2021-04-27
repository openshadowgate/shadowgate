//pocket dimension for fear carrier in dream isle, godswar.
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(LEDGE);
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_name("An eternally shifting nightmare-scape");
    set_short("%^RESET%^%^BLUE%^An eternally %^CYAN%^sh%^GREEN%^i%^MAGENTA%^f%^BLUE%^ti%^GREEN%^n%^CYAN%^g %^BLUE%^nightmare-scape%^RESET%^");
    set_long("%^RESET%^%^BLUE%^An eternally %^CYAN%^sh%^GREEN%^i%^MAGENTA%^f%^BLUE%^ti%^GREEN%^n%^CYAN%^g %^BLUE%^nightmare-scape%^RESET%^\n"
"%^CYAN%^This place seems shaped from the stuff of %^BLUE%^nightmares %^CYAN%^and %^MAGENTA%^chaos%^CYAN%^. At each turn, where absolute %^BOLD%^%^BLACK%^darkness "
"%^RESET%^%^CYAN%^does not already hold dominion, mind-bending visions take the form of %^RED%^horrors %^CYAN%^both familiar and beyond imagining. Lifeless "
"%^RESET%^corpses %^CYAN%^spring forth with grasping limbs and gnashing teeth, shifting to become %^ORANGE%^mires %^CYAN%^and pitfalls that birth fanged monsters "
"with %^RED%^blazing eyes%^CYAN%^. Fearful forms flit at the edges of your vision, never quite within enough focus to bring them a sense of reality. Beyond it all, "
"the %^MAGENTA%^whispers %^CYAN%^of the void echo, snarl and hiss in your ears, never allowing a moment's peace or a reprieve to gather your thoughts. Search as "
"you might, you can see no way to escape this terrible place...%^RESET%^\n");
    set_smell("default","%^ORANGE%^It seems impossible to gather your senses enough to focus.%^RESET%^");
    set_listen("default","%^MAGENTA%^Whispers %^GREEN%^of the void echo, snarl and hiss in your ears, never allowing a moment's peace.%^RESET%^");
}