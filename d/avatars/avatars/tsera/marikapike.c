#include <std.h>
inherit OBJECT;

void create()
{
        ::create();
        set_name("%^RESET%^%^RED%^A gruesome elven head affixed to a pike%^RESET%^");
        set_id(({"head","elf","pike"}));
        set_short("%^RESET%^%^RED%^A bloodied elven head on a pike%^RESET%^");
        set_long("%^RESET%^%^RED%^Affixed to the top of this long pike is the bloodied head of an %^GREEN%^elf."
"  %^RED%^Her %^BOLD%^red hair %^RESET%^%^RED%^is matted and caked with %^BOLD%^blood %^RESET%^%^RED%^and"
" %^ORANGE%^twigs, %^RED%^making it appear as though she had been dragged around before her death.  Her"
" %^BOLD%^%^GREEN%^green eyes %^RESET%^%^RED%^are still opened and her clawed face is stuck in an eternal look"
" of horror.  Detached from the head, a torn and naked torso with various bite and claw marks has been crudely"
" tied to the middle of the pike.  All the limbs are missing.  Affixed to the place where the neck *would* be"
" is a note written with bloody scrawl.%^RESET%^.");
        set_weight(1000000);
        set_value(0);
        set_property("no animate", 1);
       set_read("%^BOLD%^RED%^The Hunt bes not forgettings crimes of Woodbitch and
Lovebitch followers! Better bes chasings the Lovebitch followers out of
townsie until it bes too late!.%^RESET%^");
      set_language("common");
}