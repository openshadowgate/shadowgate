#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("leaf amulet");
    set_short("%^RESET%^%^ORANGE%^The Oakfa%^GREEN%^t%^ORANGE%^her's Re%^GREEN%^p%^ORANGE%^rieve%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^plain l%^GREEN%^e%^ORANGE%^af-sha%^GREEN%^p%^ORANGE%^ed amulet%^RESET%^");
    set_id(({"amulet","leaf amulet","leaf shaped amulet","plain amulet","leaf-shaped amulet","kelemvor-rebirth-blessing999"}));
    set_long("%^RESET%^A simple leather cord supports this amulet of %^ORANGE%^cl%^RED%^a%^ORANGE%^y%^RESET%^, bound "
"through a shaped hole at the top and tied at the back of the neck.  The amulet itself is made in the shape of a single "
"%^GREEN%^oak l%^BOLD%^e%^RESET%^%^GREEN%^af%^RESET%^, its stem encircling the leather cord while its tip points towards "
"the earth when worn.  The upper surface is glazed, imperfectly mixed so that whorls of lighter %^BOLD%^%^GREEN%^viri"
"%^YELLOW%^d%^GREEN%^ian %^RESET%^ripple across deeper %^GREEN%^e%^CYAN%^me%^GREEN%^ra%^BOLD%^l%^RESET%^%^GREEN%^d"
"%^RESET%^.  The underside is the raw %^ORANGE%^o%^RED%^ch%^ORANGE%^re %^RESET%^of fired clay, hard and as rough to touch "
"as the upper surface is smooth.  Not extravagant in appearance, nor crafted of particularly valuable materials or fine "
"skill, the jewelry nonetheless bears something of a %^ORANGE%^ru%^RESET%^s%^ORANGE%^tic charm %^RESET%^to its simple "
"design.\n");
    set_lore("Items as this are precious and rare, remnants of once common priest's talismans created decades before by "
"the faith of Silvanus.  Still empowered with those spells that he once granted, no more could be made following his "
"withdrawal from the realms, and the few that remain are are treasured by those who still remember and pray to him.  "
"These few clergy remained faithful, and claimed that one day he would return to protect over his forests and faithful once "
"more.  Now it seems that long devotion was not in vain, for once again his followers walk the realms...");
    set_property("lore difficulty",25);
    set_property("id difficulty",25);
    set_weight(1);
    set_value(13410);
    set_type("ring");
    set_limbs(({"left hand","right hand"}));
    set_ac(1);
    while((int)query_property("enchantment") != -1) {
      remove_property("enchantment");
      set_property("enchantment",-1);
    }
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    tell_object(ETO,"%^RESET%^%^GREEN%^You feel the protection of the wild upon you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^GREEN%^"+ETO->QCN+" looks calm and assured.%^RESET%^",ETO);
    ETO->set_property("rebirth",TO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^RESET%^%^GREEN%^The protection leaves you.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^GREEN%^"+ETO->QCN+" loses "+ETO->QP+" air of assurance.%^RESET%^",ETO);
    if(ETO->query_property("rebirth")) ETO->remove_property("rebirth");
    return 1;
}

int isMagic(){ return 1; }
int drop(){ return 1;}
