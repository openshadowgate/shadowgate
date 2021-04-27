#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("shard of darkness");
	set_id(({ "shard", "darkness shard", "shard of darkness", "spear of the void", "immare", "spear of darkness", "spear" }));
	set_short("%^RESET%^%^ORANGE%^I%^BOLD%^%^BLACK%^m%^RESET%^%^MAGENTA%^m%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^- %^RESET%^%^BLUE%^S%^BOLD%^p%^BLACK%^e%^RESET%^%^BLUE%^ar %^BOLD%^o%^RESET%^%^BLUE%^f t%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^e V%^BOLD%^o%^BLACK%^i%^RESET%^%^BLUE%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^a shard of d%^BOLD%^a%^BLACK%^r%^RESET%^%^BLUE%^kn%^BOLD%^e%^RESET%^%^BLUE%^ss%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^A shard of the %^RESET%^%^BLUE%^darkest material %^BOLD%^ever seen, this weapon has weight to it, and yet focusing upon its surface is nearly impossible.  It's very %^BLACK%^essence %^BLUE%^draws any %^RESET%^%^ORANGE%^knowledge %^BOLD%^%^BLUE%^that you gather from viewing it, and leaves you with only the impression of a %^RESET%^%^BLUE%^void %^BOLD%^so deep and dark that the very fabric of life ceases to exist within it.  Only the tip glints with a faint color, a glitter of pale %^RESET%^%^MAGENTA%^amethyst%^BOLD%^%^BLUE%^, so dark it seems almost like dried blood that flakes away into the %^RESET%^%^BLUE%^void %^BOLD%^as you watch.%^RESET%^

AVATAR
	);
	set_weight(6);
	set_value(5000);
	set_lore(
@AVATAR
%^RED%^Remembered from an ancient journal:%^RESET%^ The fire of heavens burned over the Dresttel hoards and sundered their very bodies from their corrupted spirits.  But the cost was great, for in that moment the Seer Drutok'tre was graced with the darkest of visions.  Rising from the filth of her nest she flew toward the Golden Stag, Ta'marni, and summoned the vision made real.  The dark void that opened above her cast out a single bolt of darkness, the Immare, and though the bravest of the Inomor rushed to stand between it and their general, the bolt found its mark, the heart of the Golden Stag.

AVATAR
	);
	set_property("lore difficulty",23);
	set_type("piercing");
	set_prof_type("spear");
	set_size(3);
	set_wc(2,6);
	set_large_wc(3,4);
	set_property("enchantment",3);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You wrap your hands around the shard of pure darkness and feel the void settle over you.  Emotion, feelings, the very will to live flies from you, leaving you pure and free to bring forth the destruction of what lays in your way.%^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You take a deep breath as the world returns to focus and the cold emptiness of the void dissipates.  Just what have you done?%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 25){
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^A brief flicker at the tip of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLUE%^is all that alerts you to the summoning of a dark power.  A power that forms into a %^RESET%^%^MAGENTA%^pulsating ball %^BOLD%^%^BLUE%^ of void energy that streaks from the weapon's tip and into the very core of "+targ->QCN+"!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^BLUE%^Without compassion, you point the amethyst tip of the "+query_short()+" %^BOLD%^%^BLUE%^ at "+targ->QCN+".  A brief flicker of darkness erupts from the tip, growing in size till it is a large %^RESET%^%^MAGENTA%^pulsating ball %^BOLD%^%^BLUE%^of the very void.  With but a thought you send the ball streaking forward, where it strikes "+targ->QCN+" and burrows into their very core!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^BLUE%^A brief flicker at the tip of "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^BLUE%^is all that alerts you to the summoning of a dark power.  A power that forms into a %^RESET%^%^MAGENTA%^pulsating ball %^BOLD%^%^BLUE%^ of void energy that streaks from the weapon's tip and into your very core!%^RESET%^");
		return roll_dice(4,10)+10;	}

}
