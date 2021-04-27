#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("robe");
	set_id(({ "robe of the archmagi", "robe", "robes", "archmagi" }));
	set_short("%^BOLD%^%^CYAN%^Robes of the %^BLUE%^Archmagi%^RESET%^");
	set_obvious_short("robes");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^These robes have been crafted out of a soft but rather strong cotton.  The material takes on a deep blue color, almost a %^RESET%^%^BLUE%^navy%^BOLD%^%^CYAN%^.  A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric.  The runes are hard to make out as they are always morphing and changing, never giving one enough time to read them.  An electrum colored sash serves as a way to close the robes.  As you run your hand across the fabric you notice a pair of pockets hidden in the side seams of the robes.

AVATAR
	);
	set_weight(15);
	set_value(4000);
	set_lore(
@AVATAR
The Robe of the Archmagi is said to only allow a powerful magi to don them.  There have been plenty of tales and rumors of a thief being burnt to cinders when they tried to wear a pair of robes they stole from the robe's owner.  The are seen as a sign of respect and fear by most, for the power it takes to be able to wear them.

AVATAR
	);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func() {
/* Wasn't letting Stefano wear them any more so he asked about it.  Changing it and mailing Shar to confirm the intent.  He realized it might have been a joke but with no notes on who changed it and him not having much time, I went ahead and flipped the sign.  *Styx*  2/24/03
  if (!avatarp(ETO) && ((ETO->query_guild_level("mage") > 30) || ETO->is_class("bard")) ) {
    // more nasty stuff should go here.
*/
   if(!avatarp(ETO) && (ETO->query_guild_level("mage") < 30 || ETO->is_class("bard")) ) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The robes refute your lack of understanding.");
     return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^ "+ETO->query_cap_name()+"'s robe just closed on its own!",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^The runes flash in recognition of your power, causing the sash to belt itself closed.");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" mutters some strange word that you can't understand and "+ETO->query_possessive()+" robes suddenly open!",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You call out %^BLUE%^\"Felegar\"%^CYAN%^, a rune etched on the sash, causing the robes to open as you remove them.");
	return 1;
}
