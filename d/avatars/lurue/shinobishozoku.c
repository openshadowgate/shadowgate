#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("black suit");
	set_id(({ "stylized suit", "suit", "black suit", "shinobi shozoku" }));
	set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^nob%^RESET%^%^RED%^i %^BOLD%^%^BLACK%^Sh%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^zok%^RESET%^%^RED%^u%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a st%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^liz%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d su%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This dark two piece suit is designed from high quality black cotton and has been carefully stitched and reinforced with a thin layer of %^RED%^dark red %^BLACK%^silk lining that gives the garment the appearance of %^RED%^blood%^BLACK%^ glimmering amongst the darkness.   The top features long sleeves that tie at the wrists and elbows, over which a thin layer of padded cloth has been secured.  The padding stretches down to loop over the top of the hand, leaving only finger tips and palms exposed.  The front is open and folds across the chest, secured by the obi belt, a carefully arranged and folded strip of %^RED%^silk-lined %^BLACK%^cloth that covers the double tied waist of the pant.  Like the sleeves, the pants also tie at the joints and have a thinly padded cloth shin guard.  On each of the guards, both shin and wrist, there is the image of a feather pressed into the material.  It would be almost invisible except that one side is finely edged with %^RED%^dark red%^BLACK%^ paint.%^RESET%^

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_lore(
@AVATAR
%^BOLD%^%^RED%^Your vision swirls and an image reveals itself to you:  %^BLACK%^A old man stands before four kneeling children.  In the man's hand is a bundle of black cloth.  You are aware the man sees more then the kneeling children, he sees their very nature.  The first he sees has a heart of glowing light.  The second has a heart of solid righteousness.  The third child has a heart of misty ideals.  The fourth and last child holds icy skill in their heart.  The old man commands each rise and attempt to take the bundle from him.  The first tries to explain what will be accomplished for the world by learning from the old man.  The second explains how he is the best choice for all of his qualities.  The third tells how he will travel and broaden the training and grow from the selection.  The fourth simply stands and takes the garment by thrusting a dagger between the man's breast.  The old man dies with a smile on his face.  %^RED%^Your vision swirls and the image vanishes.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",25);
	set_max_internal_encumbrance(20);
	set_type("clothing");
	set_limbs(({ "right leg", "torso" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You wrap the suit on and tie the obi belt secure in the complex method of tradition.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You undo the complex ties of the obi belt and slip the garment free.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 75){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The feathers on "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^ begin to %^RED%^glow%^BOLD%^%^BLACK%^!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The feathers are the arm guards %^RED%^glow %^BLACK%^and "+who->QCN+"'s attack lands without effect, absorbed by the garment as though "+who->QCN+" had struck a pile of feathers.%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^The feathers on "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^ begin to %^RED%^glow%^BOLD%^%^BLACK%^!  Your attack feels as though it landed on a pile of feathers rather then skin!%^RESET%^ ");
return (damage*-100)/100;	}

}
