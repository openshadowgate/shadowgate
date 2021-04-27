#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^WHITE%^lacy w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e garter%^RESET%^");
	set_id(({ "garter", "white garter", "lacy garter" }));
	set_short("%^BOLD%^%^WHITE%^A Lady's Garter%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^lacy w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e garter%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^White lace, as soft and pure as %^RESET%^snow%^BOLD%^, is the highlight of this very sexy and delicate accessory. With its intricate pattern of tiny r%^RESET%^o%^BOLD%^s%^RESET%^e%^BOLD%^s, the lace looks quite fragile and pretty. A single small %^BOLD%^%^RED%^c%^RESET%^%^RED%^r%^BOLD%^%^RED%^i%^RESET%^%^RED%^m%^BOLD%^%^RED%^s%^RESET%^%^RED%^o%^BOLD%^%^RED%^n r%^RESET%^%^RED%^os%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^ with tiny %^RESET%^%^GREEN%^g%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n p%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^ta%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^s%^BOLD%^%^WHITE%^ made from silk decorates the otherwise white garter. The underside is lined with %^RESET%^smooth%^BOLD%^ white velvet for comfort, and the elasticity of the garter makes it quite versatile.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(3500);
	set_lore(
@AVATAR
%^BOLD%^%^MAGENTA%^Longed for by woman everywhere, this sexy garment is known to drive men crazy with desire. Similar to a charm spell or a love potion, the effects of this accessory are potent! It is believed that when a woman allows a man to remove her garter, the symbol of deflowering her is quite unambiguous. %^RESET%^

AVATAR
	);
	set_property("lore difficulty",16);
	set_type("ring");
	set_limbs(({ "right leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
      if((int)ETO->query_highest_level() < 25) {
        notify_fail("You can't wear this.\n");
        return 0;
      }
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" winks as she slowly works the "+query_short()+"%^BOLD%^%^WHITE%^ up her leg.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Slowly slipping on the garter, you revel in the joys of being a woman.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slowly work off the delicate garter.%^RESET%^");
	return 1;
}
