#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
	::create();
	set_name("%^RESET%^%^BLUE%^B%^ORANGE%^a%^BOLD%^%^WHITE%^dg%^RESET%^%^ORANGE%^e%^BLUE%^r %^CYAN%^Fullplate%^RESET%^");
	set_id(({ "gothic", "gothic plate", "plate", "full plate", "badger plate", "badger full plate", "gothic full plate" }));
	set_short("%^RESET%^%^BLUE%^B%^ORANGE%^a%^BOLD%^%^WHITE%^dg%^RESET%^%^ORANGE%^e%^BLUE%^r %^CYAN%^Fullplate%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^gothic %^BOLD%^%^WHITE%^spiked %^RESET%^%^ORANGE%^fullplate%^RESET%^");
	set_long("%^RESET%^%^MAGENTA%^This suite of fullplate looks deadly and almost cruel. The plate itself fully encases the body, including arms and legs. Along the plate are wicked looking %^BOLD%^%^WHITE%^spikes%"
	"^RESET%^%^MAGENTA%^ ranging from short to almost three inches long. The metal itself is forged %^BLUE%^adamantium%^MAGENTA%^ and has been darkened and dulled to cause no reflection. What this suite of"
	" armor was specifically made for leaves much to the imagination.%^RESET%^
"
	);
	set_value(20000);
	set_lore("%^ORANGE%^Badgers are one of the most deadly invaders when it comes to gnome's burrows. Thus the inventive race constructed a suite of armor that would deal with the critters and allow them not to be "
	"harmed much in the process. Hence the creation of the Badger Fullplate, complete with state-O'-the-Art spikes and deceptive coloring. Now those feisty critters will think twice (do they actually think"
	"?) before entering another burrow!%^RESET%^


%^ORANGE%^On Burrow Invaders and How to Stop Them
%^ORANGE%^Zook Sheppin Fonkin Fnipper%^RESET%^
"
	);
    set_property("lore difficulty",12);
	set_size(1);
	set_property("enchantment",2);
	set_struck((:TO,"strike_func":));
}



int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),""+who->QCN+" %^BOLD%^%^WHITE%^impales themselves on "+ETOQCN+"'s %^BOLD%^%^WHITE%^armor when they strike "+ETOQCN+"%^BOLD%^%^WHITE%^, clumsy oaf!%^RESET%^",({ETO,who}));
	tell_object(ETO,""+who->QCN+" %^BOLD%^%^WHITE%^accidentally impales themselves on your armor as they strike you, haHA!%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^You impale yourself when you strike "+ETOQCN+"'s %^BOLD%^%^WHITE%^armor, ow ow OW!%^RESET%^");
		who->do_damage("torso",roll_dice(1,12));
return damage;	}

}
