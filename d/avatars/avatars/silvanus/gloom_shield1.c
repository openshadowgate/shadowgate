#include <std.h>
inherit ARMOUR;

#define MAXUSES 10
int uses, flag;
string place;

void create(){
	::create();
	set_name("Shield of Gloom");
	set_id(({ "shield", "gloom shield", "shield of gloom" }));
	set_short("%^BOLD%^%^BLACK%^Shield of %^BOLD%^%^WHITE%^G%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^m%^RESET%^");
	set_obvious_short("black shield");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This shield is made from a large piece of blackened %^BOLD%^%^WHITE%^crystal%^BOLD%^%^BLACK%^.  The formation of the shield is such that the bottom is only about one foot across and it gradually widens to span nearly four feet at the top.  A mysterious %^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^m%^RESET%^%^BOLD%^%^BLACK%^ is constantly %^RED%^radiating%^BOLD%^%^BLACK%^ forth from it and occasionally a strange humming sound is emitted by it.%^RESET%^  There is an inscription on the back you might be able to read.
AVATAR
	);
	set_weight(12);
	set_value(1000);
	set_type("shield");
	set_limbs(({ "right hand" }));
//	set_size(2);
	set_property("enchantment",2);
	set_ac(1);
	flag = 1;
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

void init(){
    ::init();
    add_action("read_it","read");
    add_action("make_dark","darkness");
}
int read_it(string str){
    if(!str) notify_fail("Read What?");
    if(str != "shield") return 0;
    write("Darkness it will be, if only you command me.");
    return 1;
}

int make_dark(string str){
    if(str) return 0;
    place = environment(TP);
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!query_worn()) {
      write("You must wear the shield first.");
      return 1;
    }
    if(uses < MAXUSES){
        if(flag != 0){
            tell_room(ETO,"The shield's aura darkens to envelop the room.");
               new("/cmds/wizard/_darkness.c")->use_spell(TO,TP,10);
            flag=0;
            call_out("reset_flag",100,TO);
            uses += 1;
            return 1;
        }
        write("The shield fails to respond.");
        return 1;
     }
     write("The shield is out of charges.");
     return 1;
}

int wear_func(){
   if(TP->query_level() < 15) {
      tell_object(TP,"You are too inexperienced for such a fine shield.");
      return 0;
   }
	tell_room(ETP,"%^BLUE%^A strange humming comes forth from "+ETO->query_cap_name()+"'s "+query_short()+"%^BLUE%^!%^RESET%^",TP);
	tell_object(TP,"%^BLUE%^A strange humming is emitted by your "+query_short()+"%^BLUE%^!%^RESET%^ ");
	ETO->add_attack_bonus(2);
	return 1;
}
int remove_func(){
	tell_room(ETP,"%^BLUE%^"+ETO->query_cap_name()+"'s "+query_short()+"%^BLUE%^ stops its strange humming!%^RESET%^",TP);
	tell_object(TP,"%^BLUE%^Your "+query_short()+"%^BLUE%^ stops its strange humming!%^RESET%^");
	ETO->add_attack_bonus(-2);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 150){
	tell_room(environment(query_worn()),"%^BLUE%^"+ETO->query_cap_name()+"'s "+query_short()+"%^BLUE%^ hums loudly as "+who->query_cap_name()+" strikes it!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BLUE%^Your "+query_short()+"%^BLUE%^ hums loudly as "+who->query_cap_name()+" strikes it!%^RESET%^");
	tell_object(who,"%^BLUE%^"+ETO->query_cap_name()+"'s "+query_short()+"%^BLUE%^ hums loudly as you strike it!%^RESET%^");
		who->do_damage("torso",random(10));
return damage;	}
}