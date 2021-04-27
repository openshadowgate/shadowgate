#include <std.h>
inherit "/d/common/obj/weapon/hhlance";

void create(){
	::create();
	set_name("lance");
	set_id(({ "lance" }));
	set_short("%^BOLD%^%^RED%^A r%^MAGENTA%^o%^RED%^se l%^MAGENTA%^a%^RED%^nce%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A r%^MAGENTA%^o%^RED%^se l%^MAGENTA%^a%^RED%^nce%^RESET%^");
	set_long("%^BOLD%^%^RED%^This is a heavy lance made of %^MAGENTA%^cherry%^RED%^ wood. It has a heavy %^BLACK%^iron point%^RED%^ mounted at the end. Many %^RESET%^%^RED%^e%^BOLD%^%^MAGENTA%^n%^RESET%^%^RED%^grav"
	"ed %^BOLD%^r%^MAGENTA%^o%^RED%^ses line the lance from tip to guard. Overall it is a beautiful piece of craftsmanship, and would serve any young knight well at %^BLUE%^court%^RED%^ or on the %^GREEN%^"
	"field.%^RESET%^
"
	);
	set_value(1000);
	set_lore("%^BOLD%^%^WHITE%^In 694 SG, this lance was fashioned by the skilled crafter and blind poet of Sune, %^GREEN%^Clausius%^WHITE%^. He said that the finery of the lance was not his own design but that whi"
	"ch was the %^BLUE%^will%^WHITE%^ of the tree. It was cut and fashioned out of a single %^RED%^cherry%^WHITE%^ tree from the Temple. Clausius meant for the lance to be for a knight who appreciated the "
	"values of %^YELLOW%^Chivalry%^WHITE%^ in addition to prowess in battle.%^RESET%^
"
	);
    set_property("lore difficulty",10);
    set("chabonus",2);
	set_property("enchantment",2);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^MAGENTA%^"+ETOQCN+"'s "+query_short()+" strikes %^RED%^true%^MAGENTA%^ as it pierces "+targ->QCN+" to the quick!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^Your "+query_short()+" strikes %^RED%^true%^MAGENTA%^ as it pierces "+targ->QCN+" to the quick!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" strikes through your defenses like %^YELLOW%^butter%^MAGENTA%^ with "+ETOQCN+"%^RESET%^");
		return roll_dice(2,10)+0;	}

}
