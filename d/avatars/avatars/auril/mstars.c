#include <std.h>
#define COLORS ({"%^RED%^Red","%^YELLOW%^Yellow","%^BOLD%^%^BLACK%^Black",\
"%^GREEN%^Green","%^BLUE%^Blue","%^BOLD%^%^WHITE%^White","%^CYAN%^Cyan"})

inherit WEAPON;
int x;

void create(){
	::create();
	set_name("whirling stars");
	set_id(({ "star", "shuriken", "whirling stars" }));
	set_short("%^BOLD%^%^WHITE%^S%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^v%^BOLD%^"+
		"%^BLACK%^e%^BOLD%^%^WHITE%^n %^RESET%^%^CYAN%^whirling %^BOLD%^%^YELLOW%^"+
		"st%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^rs%^RESET%^");
	set_obvious_short("shuriken");
	set_long("%^BOLD%^%^WHITE%^This small, exquisitely crafted sh%^BOLD%^%^BLUE%^"+
		"ur%^BOLD%^%^WHITE%^iken has a small design in the center of it. The design depicts "+
		"a %^RESET%^%^RED%^red %^BOLD%^%^WHITE%^flowing tendril of %^BOLD%^%^YELLOW%^m"+
		"%^BOLD%^%^CYAN%^a%^BOLD%^%^YELLOW%^g%^BOLD%^%^CYAN%^i%^BOLD%^%^YELLOW%^c %^BOLD%^"+
		"%^WHITE%^going from bottom to the top. Seven %^BOLD%^%^YELLOW%^stars %^BOLD%^"+
		"%^WHITE%^surround the magic tendril and %^RESET%^sh%^BOLD%^%^WHITE%^im%^RESET%^"+
		"mer %^BOLD%^%^WHITE%^slightly.");
	set_weight(1);
	set_value(5000);
	set_lore("This item is given to faithful of Mystra, helping them protect and devote to "+
		"the weave.");
	set_type("piercing");
	set_prof_type("shuriken");
	set_size(2);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+"'s hand glows brightly for a moment.",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Your hand glows brightly as you wield the shuriken!");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+"'s hand glows brightly for a moment.",ETO);
	tell_object(ETO,"%^BOLD%^%^YELLOW%^Your hand glows brightly as you unwield the shuriken!");
	return 1;
}

void choose_spells() {

	if(random(100) > 80) {
		x = random(3);
		switch(x) {
			case 0:
				x = 4;
				break;
			case 1:
				x = 5;
				break;
			case 2:
				x = 6;
				break;
		}
		return x;
	}

	x = random(4);
  switch(x) {
			case 0:
				x = 1;
				break;
			case 1:
				x = 2;
				break;
			case 2:
				x = 3;
				break;
			case 3:
				x = 4;
				break;
		}

		return x;
}


int hit_func(object targ){
	if(random(1000) < 850 && ETO->is_class("mage")){
		choose_spells();

		tell_room(environment(ETO),ETO->query_cap_name()+"%^BOLD%^%^GREEN%^'s "+COLORS[x]+ 
		"%^BOLD%^%^GREEN%^ star flashes %^CYAN%^brilliantly%^BOLD%^%^GREEN%^ as it comes "+
		"into contact with "+targ->query_cap_name()+"%^BOLD%^%^GREEN%^'s flesh!%^RESET%^",({ETO,targ}));

		tell_object(targ,ETO->query_cap_name()+"%^BOLD%^%^GREEN%^'s "+COLORS[x]+ "%^BOLD%^%^GREEN%^"+
		" star flashes %^CYAN%^brilliantly%^BOLD%^%^GREEN%^ as it comes into contact with your "+
		"flesh!%^RESET%^");
		
		tell_object(ETO,"%^BOLD%^%^GREEN%^Your shuriken's "+COLORS[x]+"%^BOLD%^%^GREEN%^ star "+
			"flashes %^CYAN%^brilliantly%^BOLD%^%^GREEN%^ as it comes into contact with "+ 
			targ->query_cap_name()+ "%^BOLD%^%^GREEN%^'s flesh!%^RESET%^");
	
		switch(x) {
		case 0:
			new("/cmds/wizard/_magic_missile")->use_spell(ETO,targ,random(5) + 3);
			break;
		case 1:
			new("/cmds/wizard/_lightning_bolt")->use_spell(ETO,targ,random(5) + 3);
			break;
		case 2:
			new("/cmds/wizard/_fireball")->use_spell(ETO,targ,random(5) + 3);
			break;
		case 3:
		 new("/cmds/wizard/_acid_arrow")->use_spell(ETO,targ,random(5) + 3);
			break;
		case 4:
			new("/cmds/wizard/_web")->use_spell(ETO,targ,random(5) + 3);
			break;
		case 5:
			new("/cmds/wizard/_hideous_laughter")->use_spell(ETO,targ,random(5) + 3);
			break;
		case 6:
			new("/cmds/wizard/_ray_of_enfeeblement")->use_spell(ETO,targ,random(5) + 3);
			break;
		}
	}
}