#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
   	set_name("bracelets");
	set_short("%^BOLD%^%^CYAN%^Bracelets of %^BLUE%^P"+
		"%^CYAN%^o%^BLUE%^w%^CYAN%^e%^BLUE%^r%^RESET%^");
     	set_obvious_short("%^BOLD%^%^CYAN%^A pair of light blue metal bracelets%^RESET%^");
  	set_id(({"bracelets","bracelets of power","Bracelets of Power"}));
	set_long(
	"%^BOLD%^%^CYAN%^These bracelets are made of a lovely sky blue metal,"+
	" power almost seems to flow through them as you watch. They are each"+
	" an inch wide at least and are perfect circles, exactly alike. %^RESET%^"
	);
	set_weight(5);
	set_value(2000);
	set_ac(0);
	set_property("enchantment",1);
	set_type("clothing");
	set_limbs(({"right arm"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
//    if(!random(3)) FLAG = 1;
//    else FLAG = 0;
}

int wearme()
{
int mystat,curstat;
mystat = ETO->query_base_stats("strength");
curstat = ETO->query_stats("strength");
    if(ALIGN->is_evil(ETO)) {
      tell_object(ETO,"The bracelets will not be worn by someone with your evil nature!");
      return 0;
    }
    if(ETO->query_property("evil item")) {
       tell_object(ETO,"The bracelets refuse to be worn while you're using such evil items.");
       return 0;
    }
	if(ETO->query_lowest_level() < 20) {
		tell_object(ETO,"You are not experienced enough to use this equipment.");
		return 0;
	}
    if(mystat < curstat){
      tell_object(ETO,"The bracelets refuse to be worn with something "+
         "already granting you strength!");
      return 0;
    }
    
//    if(FLAG == 1) 
//    { 
        calculate_bonus(); 
        if(str_bonus) ETO->add_stat_bonus("strength",str_bonus);
        if(exc_bonus) ETO->add_stat_bonus("exceptional_strength",exc_bonus);
        ETO->do_encumbrance();
//    }
	
    tell_object(ETO,"%^BOLD%^%^CYAN%^You feel the bracelets strengthen your arms as"+
	" you slip them over your wrists.");
    ETO->set_property("good item",1);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel weak once more as you remove"+
	" the bracelets.");
//    if(FLAG == 1)
//    {
        if(str_bonus) ETO->add_stat_bonus("strength",str_bonus * -1);
        if(exc_bonus) ETO->add_stat_bonus("exceptional_strength",exc_bonus * -1);
        ETO->do_encumbrance();
//    }  

    ETO->set_property("good item",-1);
	return 1;
}

void calculate_bonus()
{
    int strength,ex_strength;

    strength = ETO->query_base_stats("strength");
     ex_strength = ETO->query_stats("exceptional_strength");

    if(strength < 18) { str_bonus = 1; }

    else if(strength == 18)
    {
        if(ex_strength == -1)                           { exc_bonus = 76; }
        else if(ex_strength > 1  && ex_strength < 76)   { exc_bonus = 76 - ex_strength; }
        else if(ex_strength > 75 && ex_strength < 90)   { exc_bonus = 99 - ex_strength; }
        else if(ex_strength > 89 && ex_strength < 99)   { exc_bonus = 00 - ex_strength; }
        else if(ex_strength == 00)                       { str_bonus = 1; }
    }
    
    else if(strength > 18) { return; }    

    return;
}
            
