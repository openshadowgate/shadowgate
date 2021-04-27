#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("white sash");
    set_id(({"sash","white sash","silk sash","white silk sash","cincture","judiciar's cincture","judiciars cincture"}));
    set_short("%^BOLD%^%^WHITE%^Judi%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^iar's Cin%^BLUE%^c%^WHITE%^ture%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^a white silk sash%^RESET%^");
    set_long("%^ORANGE%^Long, flowing %^CYAN%^silk %^ORANGE%^of the "
"finest quality forms this cincture designed to gather garments neatly at "
"the waist.  The %^BOLD%^%^WHITE%^snowy-white sash %^RESET%^%^ORANGE%^is "
"threaded with tiny lengths of glittering weave, that occasionally can be "
"seen in flashes of %^BOLD%^%^BLUE%^cob%^RESET%^%^BLUE%^al%^BOLD%^t "
"%^RESET%^%^ORANGE%^and %^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^let"
"%^ORANGE%^.  It falls in neat folds as it lies, otherwise unadorned "
"except for an emblem at the very end hem on one side.  It has been "
"embroidered in the same %^MAGENTA%^me%^BOLD%^%^BLUE%^ta%^RESET%^"
"%^MAGENTA%^ll%^BOLD%^%^BLUE%^ic %^RESET%^%^ORANGE%^thread, forming a "
"simple design of a pair of %^RESET%^balanced scales %^ORANGE%^resting on "
"a %^GREEN%^longbow%^ORANGE%^.%^RESET%^\n");
    set_lore("This sash marks a member of the elite group of woodsmen "
"under the command of the temple of Tyr.  They are known officially as "
"the Judiciars of the Wild, and are the faction of the church who contend "
"with crimes and judgements committed in the wilderness, outside the "
"jurisdiction of a city's law.  Unlike the priesthood, they are generally "
"left to their own devices for the most part, only required to return to "
"the temple when the occasion arises, in order to record those criminals "
"they have punished according to the doctrine of Tyr - they are usually "
"absolved from any further requirement for ceremonies within the temple "
"itself.");
    set_property("lore difficulty",18);
    set_weight(5);
    set_value(2000);
    set_ac(0);
    set_size(2);
    set_property("enchantment",4);
    set_item_bonus("strength",1);
    set_type("clothing");
    set_limbs(({"waist"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
    if((string)ETO->query_diety() != "tyr" && !ETO->is_class("ranger") && !avatarp(ETO)) {
      tell_object(ETO,"The sash doesn't seem to fit you.");
      tell_room(EETO,"The sash doesn't seem to fit "+ETO->QCN+".",ETO);
      return 0;
    }
    if((int)ETO->query_lowest_level() < 21) {
      tell_object(ETO,"The sash doesn't seem to fit you.");
      tell_room(EETO,"The sash doesn't seem to fit "+ETO->QCN+".",ETO);
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^You proudly secure the sash around "
"your waist.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" %^BOLD%^%^WHITE%^proudly"
" secures the sash around "+ETO->QP+" waist.%^RESET%^",ETO);
    return 1;
}

int removeme() {
    tell_object(ETO,"%^BOLD%^%^WHITE%^You slip free of the silken "
"sash.%^RESET%^");
    return 1;
}

int drop(){ return 1;}
