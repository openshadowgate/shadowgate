//file 

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("coin");
    set_id(({"item","coin","coin","%^RESET%^%^CYAN%^a slightly tarnished coin%^RESET%^",}));
    set_short("%^RESET%^%^CYAN%^a slightly tarnished coin%^RESET%^");
    set_long(
"%^RESET%^%^CYAN%^%^BOLD%^Merely glancing at this coin you can tell it is an ancient form "+
"of currency not seen since many years before your birth.  At "+
"first the two sides seem to be exactly the same, but after "+
"further inspection you can see the fine detail that make up "+
"the differences.  Both sides depict a young woman of both "+
"grace and beauty.  On one side of the coin the shiny surface "+
"reveals the wonder of the heavens with the moon and stars in "+
"the background.  The woman's smile seems to portray a sense "+
"of warmth and confidence.  The other side has taken much "+
"wear and the metallic surface has been plaqued with tarnish "+
"blocking out the night sky leaving only the young woman "+
"confused in the darkness.  There is an emptiness in her eyes "+
"as she searches her surroundings in vain.  Her smile is "+
"perhaps of ignorance for she no longer cares to find her way, "+
"or bliss for she is content to remain alone.  You feel a "+
"sense of invincibility as your weaknesses fade away. "+
"some writing seems to outline the border of the coin.%^RESET%^"
        );
    set_weight(0);
    set_value(5000);
    set("read","%^RESET%^%^BLUE%^%^BOLD%^The sisters of light and darkness are present in our daily lives.  Learn from them for they will lead us through life, and the life hereafter.%^RESET%^");
}
