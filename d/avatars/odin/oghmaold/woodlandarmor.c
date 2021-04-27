#include <std.h>
inherit ARMOUR;
int uses;
int query_uses(){return uses;}


void create(){
	::create();
	set_name("woodland armor");
	set_id(({ "armor", " woodland armor", "armor of the woodlands", "leather", "studded leather", "green studded leather" }));
	set_short("%^RESET%^%^GREEN%^A%^BOLD%^r%^RESET%^%^GREEN%^m%^BOLD%^o%^RESET%^%^GREEN%^r %^BOLD%^%^WHITE%^of"
" the %^RESET%^%^ORANGE%^W%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^l"
"%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A deep %^RESET%^%^GREEN%^gr%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^en"
" %^BOLD%^%^BLACK%^studded leather%^RESET%^");
	set_long("%^RESET%^This armor is almost certainly made to blend in with the"
" %^BOLD%^%^GREEN%^f%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^s"
"%^RESET%^%^ORANGE%^t%^RESET%^.  The leather has been died a deep shade of %^RESET%^%^GREEN%^green"
" %^RESET%^with mixed splotches of %^RESET%^%^ORANGE%^browns"
"%^RESET%^, %^BOLD%^%^BLACK%^blacks%^RESET%^, and %^RESET%^%^CYAN%^grays%^RESET%^, making it effective woodland"
" camouflage as well as protection from blows.  The %^BOLD%^%^BLACK%^metal %^RESET%^rivets that stud it are all"
" colored to match the leather as well, leaving no outline that would give the wearer away.  Every bit of this"
" armor is made for functionality rather than extravagance and it looks like it would stand up to many years of"
" harsh treatment with barely a scratch.");
	set_weight(15);
	set_value(10000);
      uses = random(10)+7;
	set_lore("This leather armor was made by the grand armorsmith Ulrich von Osterland for the ranger"
" Pyotr Tsnenokof in the year 620 SG.  It was lost along with its wearer to some unknown menace in the"
" Northern Dagger Reaches some five years later.  This is supposedly Ulrich's masterwork piece of craftsmanship"
" and is quite a prize indeed.  It is said that when wearing this armor, a person can become at one with"
"nature and %^BOLD%^stalk %^RESET%^the wilds.");
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),""+ETOQCN+" wears a suit of green leather.",ETO);
	tell_object(ETO,"You slip on the suit of armor and feel more connected to the land.");
	ETO->add_stat_bonus("dexterity",2);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes a suit of green leather.",ETO);
	tell_object(ETO,"You feel your connection to the land lessen as you remove the armor.");
	ETO->add_stat_bonus("dexterity",-2);
	return 1;
}
void init() {
    ::init();
    add_action("stalk","stalk");
}
void stalk(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(TP,"%^RESET%^%^GREEN%^You must be wearing the armor!%^RESET%^");
   return 1; 
   }
   if(uses<1){
	tell_object(TP,"%^RESET%^%^GREEN%^The armor has no more magic.%^RESET%^");
      TO->remove();
   return 1;
   }  
   tell_object(TP,"%^BOLD%^%^GREEN%^You allow yourself to succumb to the call of the wilds and disappear into the nature that surrounds you!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" simply disappears into the surrounding wilderness!",ETO);
   new("/cmds/priest/_stalk.c")->use_spell(ETO,ETO->query_name(),20,100);
   uses --;
   return 1;
}

