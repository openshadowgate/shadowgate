#include <std.h>
inherit "/d/common/obj/weapon/longsword";

void create(){
	::create();
	set_name("Archangel's Sword");
	set_id(({ "longsword", "sword" }));
	set_short("%^BOLD%^%^WHITE%^A%^CYAN%^r%^WHITE%^cha%^CYAN%^n%^WHITE%^gel A%^YELLOW%^l%^WHITE%^aka%^YELLOW%^l%^WHITE%^iel's %^RED%^H%^WHITE%^oly %^RED%^A%^WHITE%^ven%^RED%^g%^WHITE%^er%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A%^CYAN%^r%^WHITE%^cha%^CYAN%^n%^WHITE%^gel A%^YELLOW%^l%^WHITE%^aka%^YELLOW%^l%^WHITE%^iel's %^RED%^H%^WHITE%^oly %^RED%^A%^WHITE%^ven%^RED%^g%^WHITE%^er%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This sword is a glowing %^YELLOW%^a%^RED%^f%^YELLOW%^lame%^WHITE%^ with holy light. It stands three and a half feet long with a double edged blade. The cross piece and hilt connect se"
	"emlessly with the blade in a dazzling display. It's %^RED%^aura%^WHITE%^ is like a %^CYAN%^celestial h%^RED%^a%^CYAN%^mm%^RED%^e%^CYAN%^r%^WHITE%^ crushing any evil seemingly close enough to it. It is"
	" an object of %^BLUE%^pure judgement%^WHITE%^ and its %^MAGENTA%^f%^RED%^u%^MAGENTA%^ry%^WHITE%^ is of the %^YELLOW%^heavens%^WHITE%^ itself.%^RESET%^
"
	);
	set_value(100000);
	set_lore("%^BOLD%^%^WHITE%^This blade is of the Celestial Archangel Alakaliel that she wielded for the forces of good during the godswar. It is a sword of righteousness and holy wrath. To hold it is to be %^YEL"
	"LOW%^judged%^WHITE%^, and only the most pure of mortals could hope to hold it. This blade is a weapon of unspeakable power that was raised in battle against the evil god %^BLACK%^Myrkul.%^RESET%^
"
	);
    set_property("lore difficulty",0);
    set("strbonus",2);
    set("conbonus",2);
    set("chabonus",2);
	set_property("enchantment",4);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+"'s %^RED%^blade%^WHITE%^ unleashes %^RED%^holy fury%^WHITE%^ against his enemy!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your %^RED%^blade%^WHITE%^ unleashes %^RED%^holy fury%^WHITE%^ against your enemy!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^WHITE%^DIVINE FURY STRIKES AT YOU as "+ETOQCN+" connects his "+query_short()+" with your body!%^RESET%^");
		return roll_dice(1,20)+20;	}

}
