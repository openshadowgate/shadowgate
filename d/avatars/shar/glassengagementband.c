#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("band");
	set_id(({ "band", "ring" }));
	set_short("%^BOLD%^%^WHITE%^Diamond Engagement Band%^RESET%^");
	set_obvious_short("diamond band");
	set_long(
@AVATAR
A medium size %^BOLD%^white diamond%^RESET%^ rests on a clear band.  The diamond has been cut into a square shape, and the many facets catch the light giving it a %^BOLD%^dazzling%^RESET%^ property.  A curious band serves as teh bearer of such a fine stone.  The band is actually made of %^BOLD%^%^CYAN%^glass%^RESET%^!  Five strangs of glass have been twisted, giving the ring a spiral effect.  Such a delicate material for a brilliant diamond seems rather odd.

AVATAR
	);
	set_weight(1);
	set_value(200);
	set_lore(
@AVATAR
The Diamond engagement band was created by the elven jeweler, Tel'qaim.  Tel'qaim was widly know for his use of odd materials to create wonderous works of art.  Glasssteel was his favorite.

AVATAR
	);
	set_type("ring");
	set_limbs(({ "right hand" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Slipping on a diamond band, "+ETO->query_cap_name()+" %^BOLD%^%^WHITE%^smiles brightly.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip on the "+query_short()+" %^BOLD%^%^WHITE%^and soon realize the glass is far stronger than it looks, much like your love.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^ You slip off the "+query_short()+" %^BOLD%^%^WHITE%^and realize ring or not, the bond that connects you to your true love is as strong as the diamond.");
	return 1;
}
