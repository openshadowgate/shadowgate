#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("fingerless gloves");
        set_id(({ "gloves", "pair of gloves", "fingerless gloves", "fallfingers", "fallfingers gloves" }));
        set_short("%^BOLD%^%^BLACK%^f%^RESET%^%^CYAN%^a%^RESET%^l%^BOLD%^%^BLACK%^lfi%^RESET%^%^CYAN%^n%^RESET%^g%^BOLD%^%^BLACK%^ers g%^RESET%^%^CYAN%^l%^RESET%^o%^BOLD%^%^BLACK%^ves%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^a pair of %^RESET%^fingerless %^BOLD%^%^BLACK%^gloves%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^These simple %^RESET%^light gray gloves %^BOLD%^%^BLACK%^are knitted from a very thin, sturdy material that is amazingly %^RESET%^%^CYAN%^soft %^BOLD%^%^BLACK%^and %^RESET%^form fitting%^BOLD%^%^BLACK%^.  "
"A small amount of coloration in the gray tones gives the gloves a bit of character, while still matching with almost any garment. Oddly, the gloves lack apparent %^RESET%^finger tips%^BOLD%^%^BLACK%^, though upon touching the place where there should be finger tips reveals that the material is actually there.  "
"This leaves you to wonder what %^RESET%^%^CYAN%^magic %^BOLD%^%^BLACK%^this is that grants all the tactile feeling of a fingerless glove, but still keeps the fingertips warm.%^RESET%^\n");
        set_weight(2);
        set_value(500);
        set_lore("When Sevlin Fallfinger decided to make a set of gloves out of the many cobwebs that clustered in the corners of her shed, she never imagined that she would be weaving the strong strands of normal spiders with the strands from a phase-spider.  "
"After painstakingly unweaving the strands of sticky webbing, she coated each in a fine cotton dust to give them softness and then began to knit them together into a tight woven set of gloves that would be thin enough to allow her to do the dexterous needle work that her profession called for but would allow her to also stay warm.  "
"To her surprise, upon the first time she wore them the finger tips of the gloves phased out of sight, leaving the tips of her fingers apparently exposed even though they stayed toasty warm,!  These fingerless gloves became quite popular with other seamstresses and Sevlin made a fortune by selling them in her shop.");
        set_property("lore difficulty",18);
        set_type("clothing");
        set_limbs(({ "left hand", "right hand" }));
        set_size(2);
        set_property("enchantment",1);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}

int wear_func(){
        if((string)ETO->query_name() != "yuki") {
          tell_object(ETO,"They don't fit you.");
          return 0;
        }
        tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" flexes "+ETO->QP+" fingers as "+ETO->QS+" puts on the gloves.",ETO);
        tell_object(ETO,"%^RESET%^%^CYAN%^You slip the gloves on and your fingers feel toasty warm!");
        return 1;
}

int remove_func(){
        tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" shivers as "+ETO->QS+
" takes the gloves off.",ETO);
        tell_object(ETO,"%^RESET%^%^CYAN%^Your fingers feel chilled as you draw "
"off the warm gloves.");
        return 1;
}
