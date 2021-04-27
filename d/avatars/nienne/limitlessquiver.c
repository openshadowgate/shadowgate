#include <std.h>
inherit "/d/common/obj/lrweapon/flarrows";

void create() {
   ::create();
   set_id(({ "arrows","larrows","longbow arrows","longbow arrow","missiles","quiver","" }));
   set_short("%^RESET%^%^CYAN%^Lim%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^tl%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^s Qui%^BOLD%^%^CYAN%^v%^RESET%^%^CYAN%^er%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^fi%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^ely t%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^o%^CYAN%^led %^RESET%^%^ORANGE%^quiver of flight arrows%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This quiver is made from finely tooled leather, bearing an intricate pattern of intertwined "
"%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^a%^YELLOW%^v%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s %^ORANGE%^and %^RED%^f"
"%^MAGENTA%^l%^BOLD%^%^MAGENTA%^o%^BOLD%^%^RED%^w%^RESET%^%^RED%^e%^MAGENTA%^r%^RED%^s%^ORANGE%^.  Despite its ornate appearance"
", it has been carefully reinforced, and set with a sturdy strap to hold it comfortably over the shoulder.  Inside, it carries "
"numerous %^RESET%^flight arrows %^ORANGE%^which have been sized for a longbow.  Each has been fletched with feathers in a "
"%^BLUE%^v%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^r%^BOLD%^%^GREEN%^i%^YELLOW%^e%^BOLD%^%^RED%^t%^BOLD%^%^MAGENTA%^y %^RESET%^"
"%^ORANGE%^of hues, so that gathered together they have quite a cheerful appearance.%^RESET%^");
   set_lore("%^BOLD%^%^WHITE%^Such a quiver is a common lesser magical item among elvenkind.  Known as some of the finest archers "
"in the land, they often bestow such quivers with a minor enchantment that constantly replenishes the arrows within.  In this way, "
"they are never left unarmed in a dangerous situation.%^RESET%^");
   set_property("lore difficulty",10);
   set_shots(-1);
   set_property("repairtype",({ "leatherwork" }));
}

int is_arrows(){ return 1; }
int isMagic() { return 1; }