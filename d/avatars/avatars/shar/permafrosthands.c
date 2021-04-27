#include <std.h>
inherit ARMOUR;
int OWNED;
string owner;

void create(){
	::create();
	set_name("hands of permafrost");
	set_id(({ "hands of permafrost", "ice hands", "permafrost hands", "hands" }));
	set_short("%^BOLD%^%^WHITE%^Hands of %^CYAN%^P%^WHITE%^e%^CYAN%^r%^WHITE%^m%^CYAN%^a%^WHITE%^frost%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A pair of hands fashioned from %^CYAN%^i%^WHITE%^c%^CYAN%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Fashioned from %^CYAN%^ice%^WHITE%^, these pair of hands glisten in the light.  The hands are carved on the smaller side, looking like they were made for a female possibly.  The %^CYAN%^ice%^WHITE%^ is polished as smooth as marble.  Inside the %^CYAN%^ice%^WHITE%^ hands a swirling vortex of snow and frost can be seen.  The fingers and hands are oddly flexible and easy to use.  Such magics that created these hands are beyond the power of mortals.

AVATAR
	);
	set_weight(1);
	set_value(0);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^Blessed onto %^WHITE%^Lady Eiryasha Shdednei%^CYAN%^, Auril's Holy Shard of Ice, for her service to the faith and her devotion to the Frost Maiden.  It is rare for mortals to gain a blessing from a god, but even rarer for the blessings to come in such form.  The hands mark %^WHITE%^Lady Eiryasha%^CYAN%^ as a favored of Auril.

AVATAR
	);
	set_property("lore difficulty",19);
	set_type("ring");
	set_limbs(({ "right hand", "left hand" }));
	set_size(2);
	set_property("enchantment",-1);
	set_ac(2);
      set_property("no animate",1);
      set_property("death keep",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
void init(){
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
      owner = TPQN;
      OWNED = 1;
   }
   ETO->force_me("wear hands");
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Frost and snow swirls around to create a pair of hands for %^CYAN%^"+ETOQCN+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Frost and snow swirls around to form a pair of %^CYAN%^hands%^WHITE%^ sealed in %^CYAN%^i%^WHITE%^c%^CYAN%^e%^RESET%^");
	ETO->set_property("magic resistance",8);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The ice melts away, but frost and snow still holds a vague handslike shape on %^CYAN%^"+ETOQCN+"%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The ice melts away, but the snow and frost still holds it vague handslike shape.");
	ETO->set_property("magic resistance",-8);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 300){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+who->QCN+" is hit with a ray of %^WHITE%^arctic frost%^CYAN%^ emitted from "+ETOQCN+"'s hands.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A ray of %^WHITE%^arctic frost%^CYAN%^ shoots out of your hands, catching "+who->QCN+" in the frigid chill%^RESET%^");
	tell_object(who,"%^BOLD%^%^CYAN%^You are hit with a ray of %^WHITE%^arctic frost%^CYAN%^ emitted from "+ETOQCN+"'s hands.  The cold chilling deep into your soul!");
 who->do_damage("torso",random(4)+1);
}
}
