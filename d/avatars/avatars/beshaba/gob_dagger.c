#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create(){
	::create();
	set_name("dagger");
	set_id(({ "dagger", "venomous dagger" }));
	set_short("%^RESET%^A %^GREEN%^ve%^BOLD%^n%^RESET%^%^GREEN%^om%^BOLD%^o%^YELLOW%^u%^GREEN%^s %^RESET%^dagger%^RESET%^");
	set_obvious_short("A small dagger covered in filth");
	set_long("This small pitted dagger is old and almost beyond repair, with the leather grip tattered and rough against the hand and a disgusting layer of rust aligning the edge of the blade.  While you might not "
	"be able to kill someone with the edge, maybe the filth and flakes of rust will do the job?
"
	);
	set_value(1500);
	set_property("enchantment",0);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^RED%^$M darts close to "+targ->QCN+" and stabs him! "+query_short()+" leaves a wound that already smells fetid.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RED%^"+query_short()+" plunges into "+targ->QCN+", leaving the wound to fester.%^RESET%^");
	tell_object(targ,"%^RED%^"+ETOQCN+" stabs you! The wound left by "+query_short()+" already itches and aches...%^RESET%^");
		targ->set_paralyzed(roll_dice(0,0)+0);
return 0;	}

}
