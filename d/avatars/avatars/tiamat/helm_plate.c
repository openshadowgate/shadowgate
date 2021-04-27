#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Plate of the Vigilant Eye");
	set_id(({ "plate", "fullplate", "armor" }));
	set_short("%^BOLD%^%^WHITE%^Plate%^RESET%^%^CYAN%^ of the %^BOLD%^%^BLUE%^Vigilant Eye%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^Polished %^RESET%^CYAN%^steel fullplate%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^This is an impressive suit of well-crafted full plate armor.  It is primarily forged from %^BOLD%^%^WHITE%^highly polished%^RESET%^%^CYAN%^ fine quality %^RESET%^steel%^CYAN%^, giving it a nearly %^BOLD%^%^WHITE%^glossy white%^RESET%^%^CYAN%^ appearance.  Unlike most traditional plate armor, the edges of this armor are smooth and form fitting, providing the wearer with nearly full range of movement.  Where edges in the armor come together, the plate joints are finished in a braid-like design lightly polished in dull %^RED%^reds%^CYAN%^ and %^BLUE%^blues%^CYAN%^ that add an impressive contrast to the %^BOLD%^%^WHITE%^bright steel%^RESET%^%^CYAN%^.  Etched and painted upon the solid breastplate is the symbol of an upright %^RESET%^war gauntlet%^CYAN%^.  Upon the gauntlet, a single %^BOLD%^%^BLUE%^blue eye%^RESET%^%^CYAN%^ gazes in an ever watchful fashion just over the wearer's heart.%^RESET%^

AVATAR
	);
	set_weight(50);
	set_value(8000);
	set_lore(
@AVATAR
Plate of the Vigilant Eye represents the pinnacle of a holy warrior's armor.  Crafted by the Vigilant of Helm, the armor is a mark of status and armor for Helm's paladins and crusading clerics.  Legends say that if the heart of the warrior ever fails, the Eye in the armor will cease to open.

AVATAR
	);
	set_property("lore difficulty",10);
	set("chabonus",1);
	set_type("armor");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(9);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The Eye of Helm on the breastplate opens with a dull blue glow as "+ETOQCN+" wears the armor!",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The Eye of Helm on your armor opens with a dull blue glow as you wear the armor!");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^The Eye on "+ETOQCN+"'s breastplate fades and closes as they remove the armor.",ETO);
	tell_object(ETO,"%^CYAN%^The Eye on your breastplate fades and closes as you remove the armor.");
	return 1;
}

