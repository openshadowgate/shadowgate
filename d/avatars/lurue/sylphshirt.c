#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("silk shirt");
	set_id(({ "shirt", "shirt of the sylph", "sylph shirt", "silk shirt" }));
	set_short("%^BOLD%^%^BLUE%^S%^RESET%^%^BLUE%^i%^CYAN%^l%^BOLD%^%^BLUE%^k S%^RESET%^%^BLUE%^h%^CYAN%^i%^WHITE%^r%^BOLD%^%^BLUE%^t %^RESET%^%^BLUE%^o%^BOLD%^f %^RESET%^S%^BLUE%^y%^CYAN%^l%^WHITE%^p%^BOLD%^%^BLUE%^h%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^a blue silk shirt%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^BLUE%^This garment is soft to the touch and even lighter against the skin when worn.  Made from a liquid smooth silk, dyed the deep blue of the moonless night's ocean, it has the feel and look of %^BOLD%^%^CYAN%^c%^BLUE%^o%^RESET%^%^CYAN%^o%^BOLD%^l w%^RESET%^%^BLUE%^a%^CYAN%^t%^WHITE%^e%^BOLD%^%^BLUE%^r %^RESET%^%^BLUE%^captured in cloth form.  The deep blue is nearly a midnight blue, but shimmers with highlights of %^BOLD%^a%^RESET%^%^BLUE%^z%^WHITE%^u%^BOLD%^%^BLUE%^re %^RESET%^%^BLUE%^and %^CYAN%^c%^RESET%^y%^CYAN%^an %^BLUE%^as the light plays over it.  %^WHITE%^S%^BOLD%^i%^BLACK%^l%^WHITE%^v%^RESET%^%^WHITE%^er s%^BOLD%^c%^BLACK%^a%^WHITE%^l%^RESET%^lo%^BOLD%^p%^BLACK%^i%^RESET%^ng %^BLUE%^trims the narrow lapel of the shirt, continuing the watery theme.  A wide rippled sash of %^BOLD%^a%^RESET%^%^BLUE%^z%^WHITE%^u%^BOLD%^%^BLUE%^re %^RESET%^%^BLUE%^wraps the waist and keeps the shirt's open front closed, while providing a way to carry a few small items tucked away in the folds.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(1500);
	set_lore(
@AVATAR
%^BOLD%^%^BLUE%^It is said that during moonless nights of midsummer, one of the shyest types of fey makes a brief appearance to celebrate the solstice.  Dressed in garments woven from the very essence of nature, these sylphs dance and play in the dark of the night, reveling in the freedom that the quiet gives them.  It is during this time that they harvest the garments that they weave for the coming year.  Making cloth from water, earth, air and even fire, to clothe themselves for each of the four seasons.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set_max_internal_encumbrance(25);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
      if((string)ETO->query_name() != "farylal" && !avatarp(ETO)) {
	tell_object(ETO,"%^BOLD%^%^BLACK%^You cannot wear this.%^RESET%^");
	return 0;
      }
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+ETOQCN+" sighs as they wrap the "+query_short()+" %^RESET%^%^BLUE%^around themselves.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BLUE%^The silken cloth feels cool to the touch as you wrap your "+query_short()+" %^RESET%^%^BLUE%^around your body.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+ETOQCN+" sighs with regret as they draw the silky "+query_short()+"%^RESET%^%^BLUE%^ off.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^BLUE%^You sigh with regret as you draw the silky "+query_short()+"%^RESET%^%^BLUE%^ off.%^RESET%^");
	return 1;
}
