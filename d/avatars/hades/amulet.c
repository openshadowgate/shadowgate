//plot item for world getting turned all night
//coded by hades 7/5/20
#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create()
{
    ::create();
    set_name("amulet");
    set_id(({ "amulet", "flame amulet", "flame bearer","flame bearer's amulet" }));
    set_short("%^ORANGE%^flame bearer's amulet%^RESET%^");
    set_obvious_short("%^ORANGE%^amulet of flame%^RESET%^");
    set_lore("This amulet is bestowed upon the one chosen to"+
    " bear the flame.  Myths have it that the cost to"+
    " be chosen as bearer of flame demands an incredible price.  "+
    "Only the bearers of the elements can return balance to the land.");
    set_property("lore difficulty", 30);
    set_long("%^ORANGE%^This flaming amulet is a sight to behold."+
    "  It is a wonder that a crystal burning with a flickering red "+
    "flame doesn't burn.  The flaming jewel in the center is"+
    " wrapped around the neck with a golden thread designed"+
    " to be worn around the neck.%^RESET%^");

    set_size(-1);
    set_value(5000);
    set_wear((: TO, "wear_me" :));
    set_item_bonus("fire resistance", 40);
    set_item_bonus("negative energy resistance", 40);
}

int wear_me()
{
    tell_object(ETO, "You secure the amulet around your "+
    "neck and feel the flame of life burn you");

    return 1;
}
