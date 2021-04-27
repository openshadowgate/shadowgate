#include <std.h>
inherit OBJECT;

void create(){
        ::create();
        set_name("chalice");
        set_id(({"chalice","crystalline chalice"}));
        set_short("%^BOLD%^%^CYAN%^ornate crystalline chalice%^RESET%^");
        set_long("%^RESET%^%^CYAN%^The cup of this chalice is made entirely of %^BOLD%^transparent crystal%^RESET%^"
"%^CYAN%^, with a narrow base of %^BOLD%^%^BLACK%^lead %^RESET%^%^CYAN%^that is surprisingly heavy.  From this base, "
"whispy wraith-like figures creep their way up the sides of the chalice, their %^BOLD%^%^BLACK%^lead-gray claws %^RESET%^"
"%^CYAN%^reaching out towards its rim as their fanged mouths howl in silent %^RED%^ra%^BOLD%^g%^RESET%^%^RED%^e%^CYAN%^.  "
"The cup itself lacks the gleaming finish so common to such objects, clouded by an odd substance that constantly billows "
"forth from within the depths of the chalice, spilling out in a %^RESET%^pallid mist %^CYAN%^that fades into nothingness "
"as it escapes the goblet.  Just looking upon the ornate piece gives you an %^MAGENTA%^une%^RED%^as%^MAGENTA%^y feeling"
"%^CYAN%^...%^RESET%^\n");
        set_value(0);
        set_weight(2);
        set_lore("You've never seen or heard of anything quite like this item.  But just examining it this closely gives "
"you an uneasy, sinking feeling the longer it is near you...");
        set_property("lore difficulty",2);
}

int isMagic(){ return 1; }
