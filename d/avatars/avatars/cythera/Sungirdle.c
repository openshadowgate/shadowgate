//Made based on Anestriana for Thayil's Creation Contest 6/05 - Cythera\\
#include <std.h>
inherit ARMOUR;

void create(){
     	::create();
     	set_name("Thayil's truth");
     	set_id(({ "Girdle", "girdle", "Corset", "corset", "Thayil's truth"}));
     	set_short("%^BOLD%^%^CYAN%^Be%^BLUE%^a%^RESET%^%^CYAN%^ut"+
		"%^BLUE%^i%^BOLD%^%^BLUE%^f%^CYAN%^ul %^BLACK%^black"+
		" %^RESET%^%^BLUE%^brocade %^CYAN%^girdle");
	set_long("%^BOLD%^%^BLACK%^This beautiful girdle is made"+
		" from the most intricately woven brocade.  Dyed so"+
		" that the fabric resembles the color of a night sky "+
		"on a moonless night. As the wearer moves, the fabric "+
		"shimmers as it seems to take on an %^CYAN%^inc%^BLUE%^"+
		"an%^RESET%^%^CYAN%^des%^BLUE%^ce%^BOLD%^%^CYAN%^nt"+
		"%^BLACK%^ nature, reflecting the many hues the dark"+
		" brocade absorbs. Six strips of whalebone are sewn into"+
		" the fabric, forcing the walls of the girdle rigid. The "+
		"corset can be pulled tight via thick silk blue laces, "+
		"strung through silver eyelets up the center of the back."+
		" Soft and inviting to the touch, the dark brocade hugs"+
		" its wearer like a second skin, accentuating the most"+
		" sensuous curves, while hiding imperfections "+
		"within its stiff folds\n\n\n\n%^RESET%^Average quality");
    	set_weight(4);
    	set_value(8);
    	set_ac(0);
    	set_size(2);
    	set_type("clothing");
    	set_limbs(({ "torso" }));
    	set_property("creator","anestriana");
    	set_property("quality",98);
    	set_wear((:TO,"wear_func":));
}
int wear_func(){
		 if((string)ETO->query_name() == "thayil"){
			tell_object(ETO,"Your heart is faint and your "+
				"will weak. You worry that you will not be"+
				" able to shoulder future burdens upon your"+
				" meek shoulders, and you are correct in that"+
				" fear. You stand for nothing, and thus you "+
				"shall fall to everything.");
			return 1;
		}else{
			return 1;
		}
}
