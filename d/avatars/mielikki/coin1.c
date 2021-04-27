//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("coin");
    set_id(({"item","coin","coin","%^RESET%^%^CYAN%^a slightly tarnished coin%^RESET%^",}));
    set_short("%^RESET%^%^CYAN%^a slightly tarnished coin%^RESET%^");
    set_long(
@ITEM
%^RESET%^%^CYAN%^%^BOLD%^Merely glancing at this coin you can tell it is an ancient form
%^RESET%^%^CYAN%^%^BOLD%^of currency not seen since many years before your birth.  At
%^RESET%^%^CYAN%^%^BOLD%^first the two sides seem to be exactly the same, but after
%^RESET%^%^CYAN%^%^BOLD%^further inspection you can see the fine detail that make up
%^RESET%^%^CYAN%^%^BOLD%^the differences.  Both sides depict a young woman of both
%^RESET%^%^CYAN%^%^BOLD%^grace and beauty.  On one side of the coin the shiny surface
%^RESET%^%^CYAN%^%^BOLD%^reveals the wonder of the heavens with the moon and stars in
%^RESET%^%^CYAN%^%^BOLD%^the background.  The woman's smile seems to portray a sense
%^RESET%^%^CYAN%^%^BOLD%^of warmth and confidence.  The other side has taken much
%^RESET%^%^CYAN%^%^BOLD%^wear and the metallic surface has been plaqued with tarnish
%^RESET%^%^CYAN%^%^BOLD%^blocking out the night sky leaving only the young woman
%^RESET%^%^CYAN%^%^BOLD%^confused in the darkness.  There is an emptiness in her eyes
%^RESET%^%^CYAN%^%^BOLD%^as she searches her surroundings in vain.  Her smile is
%^RESET%^%^CYAN%^%^BOLD%^perhaps of ignorance for she no longer cares to find her way,
%^RESET%^%^CYAN%^%^BOLD%^or bliss for she is content to remain alone.  You feel a
%^RESET%^%^CYAN%^%^BOLD%^sense of invincibility as your weaknesses fade away.

%^RESET%^%^WHITE%^%^BOLD%^some writing seems to outline the border of the coin%^RESET%^
ITEM
        );
    set_weight(0);
    set_value(5000);
}