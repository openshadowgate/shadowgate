#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("%^RESET%^%^BLUE%^S%^RED%^ha%^BLUE%^s%^RED%^hk%^BLUE%^a%^BOLD%^%^WHITE%^ of Pulch%^RED%^r%^WHITE%^itude%^RESET%^");
	set_id(({ "shashka", "sword", "backsword", "ivory sword", "ivory backsword", "shashka of pulchritude" }));
	set_short("%^RESET%^%^BLUE%^S%^RED%^ha%^BLUE%^s%^RED%^hk%^BLUE%^a%^BOLD%^%^WHITE%^ of Pulch%^RED%^r%^WHITE%^itude%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^exquisite %^BOLD%^%^WHITE%^iv%^RESET%^o%^BOLD%^ry %^BLUE%^backsword%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^This beautiful blade seems to have been crafted for a specific deity, and hand, in mind. The blade itself, which is single-edged, is comprised of a single long piece of %^WHITE%^iv%^RE"
	"SET%^o%^BOLD%^ry%^BLUE%^. The edged portion is gently waved all the way down the length. Tiny %^RED%^c%^RESET%^%^RED%^a%^BOLD%^rn%^RESET%^%^RED%^el%^BOLD%^ia%^RESET%^%^RED%^n%^BOLD%^s%^BLUE%^ are spac"
	"ed on the back portion of the blade, sculpted into baby %^RED%^r%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se%^BLUE%^ buds, giving it a serrated appearance. The hilt is wrought %^WHITE%^sil%^CYAN%^v%^WHITE%^"
	"er%^BLUE%^, appearing as a single %^RED%^r%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se%^GREEN%^ le%^RESET%^%^GREEN%^a%^BOLD%^f%^BLUE%^, gently curling down to touch at the pommel. The pommel itself is a ful"
	"ly bloomed %^RED%^r%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^se%^BLUE%^, sculpted from a single large %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y%^BOLD%^%^BLUE%^.
"
	);
	set_value(0);
	set_lore("%^MAGENTA%^This backblade was commissioned by the church of Sune Firehair and crafted by the reknowned (yet rarely heard of) elven smith, Fildowlin Serloonin, specifically to be gifted to the newly an"
	"nointed Paladin, Sir Deve. The %^BLUE%^S%^RED%^ha%^BLUE%^s%^RED%^hk%^BLUE%^a%^BOLD%^%^WHITE%^ of Pulch%^RED%^r%^WHITE%^itude%^RESET%^%^MAGENTA%^ is paired with a specific sheath, %^BOLD%^%^RED%^L%^MAG"
	"ENTA%^ov%^RED%^es %^YELLOW%^Embrace%^RESET%^%^MAGENTA%^, to be embraced when duty doesn't call.%^RESET%^
"
	);
    set_property("lore difficulty",20);
    set("chabonus",1);
    set("wisbonus",1);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),""+ETOQCN+"%^BOLD%^%^BLUE%^ draws forth "+query_short()+" %^BOLD%^%^BLUE%^from it's embrace, holding it forth as %^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r%^ORANGE%^e%^BOLD%^%^BLUE%^ licks at the blades' waved edge.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You draw forth "+query_short()+" %^BOLD%^%^BLUE%^from it's embrace, holding it forth as %^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r%^ORANGE%^e%^BOLD%^%^BLUE%^ licks at the blades' waved edge.%^RESET%^");
	ETO->set_property("magic resistance",10);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" sheathes "+query_short()+" %^BOLD%^%^BLUE%^, returning it to it's companions' embrace, the %^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r%^ORANGE%^e%^BOLD%^%^BLUE%^ slowly sleeping once again.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You sheath "+query_short()+" %^BOLD%^%^BLUE%^returning it to it's companions' embrace, the %^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r%^ORANGE%^e%^BOLD%^%^BLUE%^ slowly sleeping once again.%^RESET%^");
	ETO->set_property("magic resistance",-10);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 850){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^As "+ETOQCN+" %^BOLD%^%^WHITE%^cleanly slices "+targ->QCN+"%^BOLD%^%^WHITE%^, "+ETOQCN+" %^BOLD%^%^WHITE%^quickly backhands them, the %^RED%^c%^RESET%^%^RED%^a%^BOLD%^rn%^RESET%^%^RED%^el%^BOLD%^ia%^RESET%^%^RED%^n%^BOLD%^s%^WHITE%^ lacerating "+targ->QCN+" %^BOLD%^%^WHITE%^ across the face!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you cleanly slice your opponent, you quickly backhand them, the %^RED%^c%^RESET%^%^RED%^a%^BOLD%^rn%^RESET%^%^RED%^el%^BOLD%^ia%^RESET%^%^RED%^n%^BOLD%^s%^WHITE%^ lacerating "+targ->QCN+" %^BOLD%^%^WHITE%^ across the face!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^As "+ETOQCN+" %^BOLD%^%^WHITE%^cleanly slices you, "+ETOQCN+" %^BOLD%^%^WHITE%^quickly backhands you, the %^RED%^c%^RESET%^%^RED%^a%^BOLD%^rn%^RESET%^%^RED%^el%^BOLD%^ia%^RESET%^%^RED%^n%^BOLD%^s%^WHITE%^ lacerating you across the face!%^RESET%^");
		return roll_dice(2,4)+0;	}

}
