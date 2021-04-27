#include <std.h>
inherit ARMOUR;

int CHARGES;

void init(){
    ::init();
	set_size(TP->query_size());
    add_action("use_magic","surround");
}

void create() {
    ::create();
		CHARGES = roll_dice(3,2);
		set_name("memento");
		set_id(({"memento","little memento"}));
		set_obvious_short("%^MAGENTA%^a curious little memento%^RESET%^");
		set_short("%^RESET%^%^MAGENTA%^S%^BOLD%^%^BLACK%^G "+
		"%^RESET%^%^MAGENTA%^M%^GREEN%^e%^BOLD%^%^BLACK%^m%^RESET%^"+
		"%^MAGENTA%^e%^BOLD%^n%^RESET%^t%^MAGENTA%^o 2%^BOLD%^"+
		"%^BLACK%^0%^RESET%^%^GREEN%^0%^MAGENTA%^9%^RESET%^");
		set_long("%^RESET%^This chunk of smooth rubble "+
		"glows faintly, alternating from the %^RESET%^%^ORANGE%^"+
		"p%^BOLD%^%^BLACK%^a%^YELLOW%^l%^RESET%^%^ORANGE%^e g"+
		"%^BOLD%^%^BLACK%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d%^YELLOW%^e"+
		"%^RESET%^%^ORANGE%^n %^RESET%^hue to a %^RESET%^"+
		"%^MAGENTA%^s%^GREEN%^i%^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^"+
		"k%^RESET%^l%^MAGENTA%^y p%^GREEN%^u%^BOLD%^%^MAGENTA%^"+
		"r%^RESET%^%^MAGENTA%^p%^RESET%^l%^MAGENTA%^e-g"+
		"%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^e%^GREEN%^e%^MAGENTA%^"+
		"n%^RESET%^.  Cool to the touch, the material has "+
		"the weight and feel of polished metal, though it is as "+
		"thin as a piece of eggshell.  Irregular in shape, several "+
		"small holes pierce the center, allowing one to thread a "+
		"%^RESET%^%^ORANGE%^leather %^RESET%^or %^RESET%^"+
		"%^MAGENTA%^silk %^RESET%^thong through and wear it "+
		"as a piece of abstract jewelry about the neck.  The pale "+
		"pulsating light causing it to be more spectacular then "+
		"its otherwise crude form might suggest.%^RESET%^");
		set_value(100);
		set_lore("%^YELLOW%^OOC: %^BOLD%^%^RED%^On May 3, 2009 "+
		"the world of Shadowgate changed.  Via the efforts "+
		"primarily of Ares and with assistance from other Imms, "+
		"the transformation of the character generation system "+
		"was revised.  Including a new multiclass system, the "+
		"introduction of feats and stat point purchases, along "+
		"with paving the way for other changes to be implemented "+
		"down the road.  This memento was handed out to those "+
		"players online at the time the switch over occurred.\n\n"+
		"%^BOLD%^%^MAGENTA%^IC: %^GREEN%^On 9 Sundays, 690 SG a "+
		"mammoth flying ship was seen crossing the sky.  Why or "+
		"where it came from is of some speculation though many "+
		"rumors speak of a drow, illithid and beholder conspiracy "+
		"to tap new powers and cut through time and space in "+
		"their ever diabolical plans to destroy their enemies. "+
		"The ship, its crew and passenger's last minutes were "+
		"witnessed by much of the realm as the sky ship plowed "+
		"into the Charu Mountains after an apparent malfunction "+
		"several minutes after launch.  This bit of debris is "+
		"a part of what little remains of the ship.  The glow "+
		"about it is said to hold the essence of the underdark "+
		"crystal which stifles magic.");
		set_property("lore difficulty",1);
		set_limbs(({"neck"}));
		set_type("ring");
		set_size(2);
		
		set_wear((:TO,"wearme":));
}


int use_magic(string str){
	object ob;
	
	if(!str){ 
		return notify_fail("Who or what did you want to use the "+
			"trinket's power on?"); 
	}
	
	if(!TO->query_worn()){
        tell_object(TP,"%^MAGENTA%^It probably wont work till you "+
			"are wearing the memento.%^RESET%^");
    return 1;
    }
	
	if(!CHARGES){
		tell_object(TP,"%^MAGENTA%^The memento glows faintly "+
			"then just as quickly grows dark.  What little "+
			"power it had remaining, spent.%^RESET%^");
		return 1;
	}
	
	tell_room(ETO,"%^MAGENTA%^"+TP->QCN+" touches a "+
                "finger to the odd shape necklace's surface.%^RESET%^",TP);
   ETO->set_property("magic resistance",75);
   call_out("end_effect",100);
	CHARGES--;
	return 1;	
}

int wearme(){
	tell_object(TP,"%^MAGENTA%^You run a silk cord through one "+
	"of the little holes in the odd memento and tie it about "+
	"your neck, certain that you could %^WHITE%^surround "+
	"%^MAGENTA%^yourself with its strange powers of turning "+
	"magic aside.");
	tell_room(ETO,"%^MAGENTA%^"+TP->QCN+" loops a silk cord "+
	"through a hole in the small memento.",TP);
	return 1;
}

void end_effect(){
   ETO->set_property("magic resistance",-75);
}
