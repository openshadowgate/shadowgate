#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("black velvet mask");
    set_id(({ "mask", "black velvet mask", "velvet mask", "mask of shadows"}));
    set_short("%^BOLD%^%^BLACK%^Mask of Shadows%^RESET%^");
    set_obvious_short("A black velvet mask");
    set_long("%^BOLD%^%^BLACK%^A mask made of plush soft black velvet.  The fabric hangs in a way where the "
"entire face is hidden behind the fold of the fabric.  The mask seems as if it ties behind the back of one's "
"head, similar to a headband, and the fabric is allowed to drape freely.  The eyes of the mask have been cut "
"out to allow one to see, though a fine gauze has been sewn over the eyes, to conceal the wearer's identity."
"%^RESET%^");
    set_lore("The Mask of Shadows is attributed to the god Mask.  The mask does not appear to be actually "
"made of shadows, as the name suggests, but of fine black velvet.  The mask is common among the followers of "
"the Lord of Thieves, for they like to keep their identiy hidden.  Even from other followers.  It's hard to "
"say who this masked belonged to as there is such a large number of them circulating.");
    set_property("lore difficulty",12);
    set_weight(5);
    set_value(0);
    set_type("leather");
    set_limbs(({"head"}));
    set_size(2);
    set_property("enchantment",2);
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}

int wear_func() {
    tell_object(ETO,"%^BOLD%^%^WHITE%^You slip on the "+TO->query_obvious_short()+" and feel the blessings of "
"your deity.%^RESET%^");
    return 1;
}

int remove_func(){
    tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the black velvet mask, allowing you to get a look at "
"the face behind the mask.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the mask and can't help but feel naked and exposed.%^RESET%^");
    return 1;
}