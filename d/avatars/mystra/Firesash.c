#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("sash");
	set_id(({ "sash", "fire sash" }));
	set_short("%^BOLD%^%^RED%^Sash of %^YELLOW%^F%^RED%^i%^ORANGE%^r%^RED%^e%^RESET%^");
	set_obvious_short("%^RED%^a flaming sash%^RESET%^");
	set_long(
@AVATAR
%^RED%^%^BOLD%^Fl%^RED%^am%^YELLOW%^es sh%^YELLOW%^o%^YELLOW%^ot %^YELLOW%^out %^YELLOW%^of th%^RED%^is f%^RED%^ir%^YELLOW%^ey p%^RED%^i%^YELLOW%^ec%^YELLOW%^e %^YELLOW%^of cl%^YELLOW%^oth, y%^YELLOW%^et %^RED%^it d%^YELLOW%^o%^YELLOW%^esn't s%^YELLOW%^e%^YELLOW%^em t%^YELLOW%^o burn th%^YELLOW%^e f%^RED%^abr%^RED%^ic.  H%^YELLOW%^e%^RED%^at %^YELLOW%^em%^RED%^in%^RED%^at%^YELLOW%^es fr%^YELLOW%^om %^RED%^its bl%^RED%^az%^RED%^ing s%^YELLOW%^e%^RED%^ams, y%^YELLOW%^et y%^YELLOW%^ou d%^YELLOW%^o n%^YELLOW%^ot f%^YELLOW%^e%^YELLOW%^el %^RED%^it.  It w%^YELLOW%^ould f%^RED%^it n%^RED%^ic%^YELLOW%^ely %^RED%^ar%^YELLOW%^ound %^YELLOW%^on%^YELLOW%^es w%^RED%^ast%^YELLOW%^e, but w%^YELLOW%^e%^RED%^ar wh%^RED%^at l%^YELLOW%^o%^YELLOW%^oks t%^YELLOW%^o th%^YELLOW%^e c%^YELLOW%^omm%^YELLOW%^on %^YELLOW%^obs%^YELLOW%^erv%^YELLOW%^er %^RED%^as pur%^YELLOW%^e fl%^RED%^am%^YELLOW%^es %^RED%^ar%^YELLOW%^ound %^YELLOW%^on%^YELLOW%^es w%^RED%^ast%^YELLOW%^e m%^RED%^ight b%^YELLOW%^e c%^YELLOW%^ons%^RED%^id%^YELLOW%^er%^YELLOW%^ed %^RED%^a cr%^RED%^azy th%^RED%^ing t%^YELLOW%^o d%^YELLOW%^o w%^YELLOW%^ould %^RED%^it n%^YELLOW%^ot?%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(1);
	set_lore(
@AVATAR
%^BOLD%^%^YELLOW%^Th%^RED%^e Bu%^YELLOW%^rning B%^YELLOW%^r%^YELLOW%^azi%^RED%^e%^YELLOW%^rs, %^YELLOW%^a f%^YELLOW%^ac%^RED%^tion of Kossu%^RED%^th's cl%^RED%^e%^YELLOW%^rgy, sp%^RED%^en%^RED%^t qui%^RED%^t%^RED%^e %^YELLOW%^a bi%^RED%^t of %^RED%^tim%^RED%^e %^RED%^t%^YELLOW%^rying %^RED%^to h%^YELLOW%^a%^YELLOW%^rn%^RED%^ess %^RED%^th%^RED%^e fl%^YELLOW%^am%^RED%^es of Kossu%^RED%^th %^RED%^to %^RED%^ench%^YELLOW%^an%^RED%^t w%^RED%^e%^YELLOW%^apons %^YELLOW%^and %^YELLOW%^a%^YELLOW%^rmo%^YELLOW%^r fo%^YELLOW%^r %^RED%^th%^RED%^ei%^YELLOW%^r %^YELLOW%^adv%^RED%^en%^RED%^tu%^YELLOW%^ring n%^RED%^e%^RED%^eds.  Of %^RED%^th%^RED%^e%^YELLOW%^r%^RED%^e f%^RED%^ew succ%^RED%^ess%^RED%^es, %^RED%^th%^RED%^e Fi%^YELLOW%^r%^RED%^es%^YELLOW%^ash w%^YELLOW%^as %^YELLOW%^a f%^YELLOW%^avo%^YELLOW%^ri%^RED%^t%^RED%^e %^YELLOW%^as i%^RED%^t w%^YELLOW%^as %^RED%^e%^YELLOW%^asily s%^RED%^e%^RED%^en %^YELLOW%^and l%^RED%^ef%^RED%^t no l%^YELLOW%^as%^RED%^ting sc%^YELLOW%^a%^YELLOW%^rs f%^YELLOW%^rom us%^RED%^e.  Th%^RED%^e pu%^YELLOW%^r%^RED%^e fi%^YELLOW%^r%^RED%^e s%^YELLOW%^ash didn'%^RED%^t %^YELLOW%^r%^RED%^e%^YELLOW%^ally func%^RED%^tion w%^RED%^ell %^YELLOW%^as %^YELLOW%^a b%^RED%^el%^RED%^t, bu%^RED%^t h%^RED%^eld sp%^RED%^eci%^YELLOW%^al %^YELLOW%^abili%^RED%^ti%^RED%^es %^RED%^to k%^RED%^e%^RED%^ep i%^RED%^t's w%^RED%^e%^YELLOW%^a%^YELLOW%^r%^RED%^e%^YELLOW%^r s%^YELLOW%^af%^RED%^e du%^YELLOW%^ring %^RED%^t%^YELLOW%^r%^YELLOW%^av%^RED%^els, %^RED%^ev%^RED%^en known %^RED%^to b%^RED%^e %^YELLOW%^abl%^RED%^e %^RED%^to c%^YELLOW%^as%^RED%^t %^YELLOW%^a fi%^YELLOW%^r%^RED%^eb%^YELLOW%^all o%^YELLOW%^r %^RED%^two du%^YELLOW%^ring c%^YELLOW%^ruci%^YELLOW%^al b%^YELLOW%^a%^RED%^t%^RED%^tl%^RED%^es in %^RED%^tim%^RED%^es of n%^RED%^e%^RED%^ed.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",20);
	set("chabonus",-1);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",2);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The "+query_short()+" around "+ETOQCN+" waist comes to life when struck and sends a ball of flame at "+who->QCN+"%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^You respond to the blow to your "+query_short()+" with a brilliant blast of fire%^RESET%^");
	tell_object(who,"%^BOLD%^%^RED%^You are hit with a burst of flames by the "+query_short()+" worn by "+ETOQCN+"%^RESET%^");
		who->do_damage("torso",roll_dice(5,2));
return damage;	}

}
