#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("%^RESET%^%^RED%^A crucified elf%^RESET%^");
   set_id(({"elf skin","skinned elf","elf","scarecrow","plaque"}));
   set_short("%^RESET%^%^RED%^A crucified elf%^RESET%^");
   set_long("%^RESET%^This is a %^RED%^grizzly %^RESET%^and crude %^ORANGE%^wooden cross %^RESET%^with the skin"
" of an %^BOLD%^%^GREEN%^elf %^RESET%^hung upon it.  The %^ORANGE%^skin %^RESET%^is stretched and torn, stuffed"
" to retain its shape with %^ORANGE%^dirty h%^YELLOW%^a%^RESET%^%^ORANGE%^y%^RESET%^.  As if to be sure"
" this elf was recognizeable, the mop of %^RED%^dark red"
" hair %^RESET%^still sets atop its head, with only a few traces of %^RED%^matted blood %^RESET%^tangled"
" within its lengths.  In cruel irony, his mouth seems perpetually twisted into a lop-sided grin as if it found"
" amusement, or even wonderment, in his cruel fate.  On his forehead, the symbol of %^BOLD%^%^BLACK%^Bane"
" %^RESET%^has been etched into the skin with something very hot, as the edges are burnt a %^BOLD%^%^BLACK%^charred"
" black.  %^RESET%^\nAt the base of the dead elfs feet is a plaque with a %^RED%^dark red %^RESET%^inscription.");
   set_weight(5000);   
   set_read("%^BOLD%^%^RED%^ELVES BEWARE!! AHEAD LIES YOUR FATE!!");
   set_language("common");
}
