#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("silk robes");
	set_id(({ "robes", "robe", "weave's fortune", "weave fortune", "blue robe", "silk robes", "silk robe" }));
	set_short("%^BOLD%^%^CYAN%^W%^BLUE%^e%^WHITE%^a%^RESET%^%^BLUE%^v%^BOLD%^%^CYAN%^e's F%^BLUE%^o%^WHITE%^r%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^une%^RESET%^");
	set_obvious_short("%^RESET%^a %^BOLD%^%^CYAN%^bright blue %^RESET%^robe trimmed in %^WHITE%^%^BOLD%^silver%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This long gown is made out of %^BOLD%^bright blue panels %^RESET%^%^CYAN%^of rich, "
"%^BOLD%^l%^BLUE%^u%^WHITE%^s%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^r%^BLUE%^o%^WHITE%^u%^CYAN%^s%^RESET%^ %^CYAN%^silk.  "
"The robe is tailored in a way that it clings close to the torso and can be closed through the use of six %^BOLD%^"
"%^WHITE%^silver buttons %^RESET%^%^CYAN%^that run down the front, while the skirt portion is fluid and flares out "
"around the legs, making for easy, %^BOLD%^g%^BLUE%^r%^WHITE%^a%^RESET%^%^BLUE%^c%^BOLD%^%^CYAN%^e%^BLUE%^f%^WHITE%^u"
"%^CYAN%^l %^RESET%^%^CYAN%^movement.  Sweeping cuffs hang half way down the body, though a slender under-sleeve of "
"%^BOLD%^%^WHITE%^silver silk %^RESET%^%^CYAN%^keeps the arms warm.  Lining the hem, a collection of %^WHITE%^%^BOLD%^"
"silvery %^RESET%^%^CYAN%^embroidered creatures can be seen frolicking around strange, %^BOLD%^m%^BLUE%^y%^WHITE%^s"
"%^RESET%^%^BLUE%^t%^BOLD%^%^CYAN%^i%^BLUE%^c%^WHITE%^a%^CYAN%^l %^RESET%^%^CYAN%^symbols and runes.%^RESET%^\n");
	set("read",
@AVATAR

%^BOLD%^%^CYAN%^As you peer down at the strange symbols, you can hear a voice speaking through the years:

%^BOLD%^%^RED%^*Never stop learning.  Never stop growing.  There is always something new to be mastered, something new to be experienced.  Grow and become strong, but never forget the strength that comes from constantly learning.*%^RESET%^


AVATAR
	);
      set("langage","common");
      set_weight(5);
	set_value(5000);
	set_lore("%^BOLD%^%^CYAN%^Garments such as these are specifically designed for the individual they are given to.  "
"No two robes are ever made the same, and each is sewn with the utmost care and the highest of quality fabrics.  Into "
"these, enchantments and protections are placed as well as wisdom from the Master Magi.  In the case of these robes, "
"%^RED%^Arch-Magi Valas of Mystra %^CYAN%^commissioned and prepared the robes as part of the graduation ceremony for "
"%^WHITE%^Magi Alisyn of Tymora%^CYAN%^, upon the completion of her apprenticeship.%^RESET%^");
	set_property("lore difficulty",10);
	set_max_internal_encumbrance(21);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
      if((string)ETO->query_name() != "alisyn" && !avatarp(ETO)) {
        tell_object(ETO,"%^BOLD%^%^CYAN%^These robes don't fit you.%^RESET%^");
        return 0;
      }
	tell_object(ETO,"%^BOLD%^%^CYAN%^As you wrap the robes about you, you are reminded of all you've accomplished and how well you've done!%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^You draw off the robes, but still feel that sense of accomplishment.%^RESET%^");
	return 1;
}

