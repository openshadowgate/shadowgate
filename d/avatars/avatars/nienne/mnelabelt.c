#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("belt of giant strength");
    set_id(({"belt","gold belt","ornate belt","belt of giant strength"}));
    set_short("%^BOLD%^%^WHITE%^Belt of Giant Strength%^RESET%^");
    set_obvious_short("%^BOLD%^%^CYAN%^a m%^BLUE%^i%^CYAN%^thr%^WHITE%^i%^CYAN%^l chain-link belt%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This belt is made of mithril filigree worked "
"into a flexible web making it stronger than any metal known to man, dwarf, or "
"firbolg.  Between the strands, tiny multi%^CYAN%^f%^WHITE%^ace%^BLUE%^t"
"%^WHITE%^ed gems have been set, sparkling in a %^RESET%^%^MAGENTA%^ra%^CYAN%^in"
"%^BLUE%^bo%^GREEN%^w %^BOLD%^%^WHITE%^of hues.  The belt has a solid mithril "
"clasp set with bevelled %^CYAN%^dia%^WHITE%^m%^CYAN%^onds%^WHITE%^.%^RESET%^\n");
    set_lore("This ornate belt was created by the grand shaman Helgatha Rothmar "
"in the firbolg village of Lothwaite.  He is the only one to have ever "
"successfully crafted such a belt, though similar magics are thought to exist "
"elsewhere.  It is said that a belt such as this will increase the strength of "
"the wearer, though only to a certain point.  While usually made of gold, "
"several other kinds were made of other precious metals, such as this one made "
"of mithril.");
    set_property("lore difficulty",15);
    set_property("repairtype",({ "jewel" }));
    set_weight(5);
    set_value(2000);
    set_ac(0);
    set_size(2);
    set_property("enchantment",1);
    set_type("clothing");
    set_limbs(({"waist"}));
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set("strbonus",1);
}

int wearme() {
    if(ETO->query_lowest_level() < 21) {
      tell_object(ETO,"You are not experienced enough to use this equipment.");
      return 0;
    }
    tell_object(ETO,"%^YELLOW%^As you fasten the belt around your waist, you "
"feel power flowing through your sinews.%^RESET%^");
    return 1;
}

int removeme() {
    tell_object(ETO,"%^YELLOW%^You feel the strength of the mighty firbolgs "
"leave you as you unbuckle the belt.%^RESET%^");
    return 1;
}
