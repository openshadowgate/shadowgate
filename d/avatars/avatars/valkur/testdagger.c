#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("dagger");
	set_id(({ "dagger", "sharp dagger", "ruby dagger" }));
	set_short("%^RED%^Ruby %^BLUE%^Dagger%^RESET%^");
	set_obvious_short("a sharp dagger");
	set_long(
@AVATAR
%^RED%^This long sharp dagger is made of pure %^BOLD%^ruby%^RESET%^ and %^WHITE%^sparkles%^RED%^ brightly in the fainest light like %^BOLD%^blood%^RESET%^%^RED%^.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR


     Interesting thing Lurue is teaching me.

          I hit return twice that time by accident, so i shall hope no-one notices and move on.


AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(200);
	set_lore(
@AVATAR
           What goes down the stairs?
                Alone or in pairs
          Rolls over the neighbours dog?
           It fits on your back
            Its good for a snack
               Its log log log
  Its loooog its loooog its big its heavy its WOOD!
 Its loooog its loooog its better than bad its GOOD!

AVATAR
	);
	set_property("lore difficulty",1);
	set("conbonus",1);
	set("chabonus",-1);
	set_type("piercing");
	set_prof_type("small blades");
	set_size(2);
	set_wc(1,4);
	set_large_wc(1,3);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func(){
	tell_room(environment(ETO),"%^RESET%^"+query_short()+"%^RESET%^%^BLUE and grin %^RED%^devilishly%^RESET%^",ETO);
	tell_object(ETO,"%^BLUE%^You firmly grip the hilt of your");
	ETO->do_damage("torso",random(5));
	return 1;
}


int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"%^RESET%^%^RED%^ "+ETOQCN+" rends his target with his "+query_short()+" %^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^RED%^ You rend your target with your "+query_short()+" %^RESET%^");
	tell_object(targ,"%^RESET%^%^RED%^ "+ETOQCN+" rends you with his "+query_short()+" %^RESET%^");
		return roll_dice(0,0)+0;	}

}
