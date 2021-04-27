#include <std.h>
inherit PARMOUR;

string FLAG;
int CHAFLAG;


void create()
{
	::create();
         set_name("robes");
        set_obvious_short("A set of dark red robes");
        set_short("%^BOLD%^%^RED%^Robes of the Archmagi%^RESET%^");
        set_id(({"robes","robes of the archmagi","Robes of the Archmagi","mage robes","magi robes","robe"}));
	set_long(
	"%^BOLD%^%^RED%^These robes are a dark red in color, representing a mage"+
	" who upholds the balance of power between good and evil. They are very"+
        " strong, as they appear to be made out of a very strong cotton"+
        ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
        " The runes are hard to make out as they are always morphing and changing,"+
        " never giving one enough time to read them. The electrum colored sash serves as a"+
        " way to close the robes. These are extremely"+
	" elegant, flowing to the ground. There are probably numerous pockets to"+
        " conceal spell components and the like in them.%^RESET%^ "
	);
	set_weight(5);
	set_type("clothing");
        set_ac(1);
        set_property("enchantment",2);
	set_limbs(({"torso"}));
        set_max_internal_encumbrance(35);
        set_value(35000);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	FLAG = "neutral";
      CHAFLAG = 0;
}

int wearme()
{
	string MASTER;

	if(((TP->is_class("mage"))) && ((!TP->is_class("cleric")) && (!TP->is_class("fighter")) && (!TP->is_class("thief")))){
        if((int)ETO->query_highest_level() < 30) {
		tell_object(ETO,"You are not a strong enough mage to wear these robes.");
		return 0;
	}
		if((string)ETO->query_gender() == "female") MASTER = "mistress";
		if((string)ETO->query_gender() == "male") MASTER = "master";
		if(ALIGN->is_evil(ETO)) {
			if(FLAG != "evil") {
				tell_object(ETO,"%^BOLD%^%^BLACK%^The robes turn the darkest"+
				" black as you slip them on.");
                                tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The robes"+
				" turn pitch black as "+ETO->query_cap_name()+" puts them on,"+
				" reflecting their new "+MASTER+".",ETO);
                               set_obvious_short("A set of pitch black robes");
                                set_short("%^BOLD%^%^BLACK%^Robes of the Archmagi%^RESET%^");
				set_long("%^BOLD%^%^BLACK%^These robes are pitch black in color,"+
				" representing a mage who will stop at nothing to gain ultimate"+
				" power, even if it means using darker forces. They are very"+
        " strong, as they appear to be made out of a very strong cotton"+
        ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
        " The runes are hard to make out as they are always morphing and changing,"+
        " never giving one enough time to read them. The electrum colored sash serves as a"+
        " way to close the robes. These are extremely"+
				" elegant, flowing to the ground. There are probably numerous"+
				" pockets to conceal spell components and the like in"+
				" them.%^RESET%^ ");
				FLAG = "evil";
			}
			else {
				tell_object(ETO,"%^BOLD%^%^BLACK%^The robes feel like a part of"+
				" you as you slip the trusted garment on.");
				tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+""+
				" seems more powerful after slipping on "+ETO->query_possessive()+" robes.",ETO);
			}
		}
		if(ALIGN->is_good(ETO)) {
			if(FLAG != "good") {
				tell_object(ETO,"%^BOLD%^The robes turn a sparkling white as"+
				" you slip them on.");
                                tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The robes"+
				" a bright shade of white as "+ETO->query_cap_name()+" puts them"+
				" on, reflecting their new "+MASTER+".",ETO);
                              set_obvious_short("A set of bright white robes");
                                set_short("%^BOLD%^%^WHITE%^Robes of the Archmagi%^RESET%^");
				set_long("%^BOLD%^%^WHITE%^These robes are bright white in color,"+
				" representing a mage whose intentions are pure and who strives"+
				" for good to maintain control of a power as strong and dangerous"+
                                 " as that of magic. They are very"+
                                 " strong, as they appear to be made out of a very strong cotton"+
        ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
        " The runes are hard to make out as they are always morphing and changing,"+
        " never giving one enough time to read them. The electrum colored sash serves as a"+
        " way to close the robes. These are extremely"+
         " elegant, flowing to the ground."+
				" There are probably numerous pockets to conceal spell components"+
				" and the like in them.%^RESET%^ ");
				FLAG = "good";
			}
			else {
				tell_object(ETO,"%^BOLD%^The robes feel like a part of you"+
				" as you slip the trusted garment on.");
				tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
				" seems more powerful after slipping on "+ETO->query_possessive()+" robes.",ETO);
			}
		}
		if(ALIGN->is_neutral(ETO)) {
			if(FLAG != "neutral") {
				tell_object(ETO,"%^BOLD%^%^RED%^The robes turn a splendid dark"+
				" red as you slip them on.");
                                tell_room(environment(ETO),"%^BOLD%^%^RED%^The robes"+
				" change to a dark red as "+ETO->query_cap_name()+" slips them"+
				" on, reflecting their new "+MASTER+".",ETO);
                               set_obvious_short("A set of dark red robes");
                                set_short("%^BOLD%^%^RED%^Robes of the Archmagi%^RESET%^");
				set_long("%^BOLD%^%^RED%^These robes are a dark red in color,"+
				" representing a mage who upholds the balance of power between"+
        " good and evil. They are very"+
        " strong, as they appear to be made out of a very strong cotton"+
        ". A pair of wide flowing sleeves are trimmed with rune encrusted electrum fabric."+
        " The runes are hard to make out as they are always morphing and changing,"+
        " never giving one enough time to read them. The electrum colored sash serves as a"+
        " way to close the robes. These are extremely"+
         " elegant, flowing to the ground."+
				" There are probably numerous pockets to conceal spell components"+
				" and the like in them.%^RESET%^ ");
				FLAG = "neutral";
			}
			else {
				tell_object(ETO,"%^BOLD%^%^RED%^The robes feel like a part of you"+
				" as you slip the trusted garment on.");
				tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+""+
				" seems more powerful after slipping on "+ETO->query_possessive()+" robes.",ETO);
			}
		}
                ETO->add_stat_bonus("intelligence",1);
                if(ETO->query_stats("charisma") < 21){
                   ETO->add_stat_bonus("charisma",1);
                CHAFLAG = 1;
                }
                ETO->set_property("magic resistance",15);
		return 1;
	}
write("You do not have the dedication of a true magi to wear this robe.");
	return 0;
}

int removeme()
{
	if(FLAG == "neutral") {
		tell_object(ETO,"%^BOLD%^%^RED%^You feel power slip from you as you"+
		" remove your wonderful robes.");
	}
	if(FLAG == "good") {
		tell_object(ETO,"%^BOLD%^You feel power slip from you as you"+
		" remove your wonderful robes.");
	}
	if(FLAG == "evil") {
		tell_object(ETO,"%^BOLD%^%^BLACK%^You feel power slip from you as you"+
		" remove your wonderful robes.");
	}
       ETO->add_stat_bonus("intelligence",-1);
       if(CHAFLAG == 1){
          ETO->add_stat_bonus("charisma",-1);
       CHAFLAG = 0;
       }
       ETO->set_property("magic resistance",-15);
	return 1;
}

void init()
{
	::init();
	add_action("check_put","put");
}

int check_put(string str)
{
	if(!query_worn()) {
		notify_fail("You must be wearing the robes to place something in their"+
		" pockets.\n");
		return 0;
	}
	if(query_worn()) return ::put_into();
}
