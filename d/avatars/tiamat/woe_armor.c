#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("Armor of Woe");
	set_id(({ "armor", "leather", "jacket" }));
	set_short("%^BOLD%^%^BLACK%^Arm%^RED%^o%^BLACK%^r of Eternal %^WHITE%^W%^RESET%^%^ORANGE%^o%^RED%^e%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^m%^WHITE%^a%^BLACK%^l%^RED%^f%^BLACK%^or%^RESET%^%^ORANGE%^m%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d leather armor%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This leather armor has been crafted from the darkly tanned skins of humanoid faces!  At least one dozen faces of elves, half-elves, humans and halflings have been tanned until black in shade. Eyeless and lidless, their mouths are opened in apparent agony.  They have been stitched together with heavy %^RESET%^%^ORANGE%^leather %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^twine%^BOLD%^%^BLACK%^, forming a macabre jacket of sorts.  Buttons have been formed from %^WHITE%^polished teeth%^BLACK%^ and %^WHITE%^bone%^BLACK%^, allowing the user to secure the jacket along the wrists and breast.  The armor has been lined along the inside with high quality satin, stained in sickening shades of %^RED%^re%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ that can only be %^RED%^blood%^BLACK%^! The jacket makes a stiff, disturbing noise as you handle the leather.%^RESET%^

AVATAR
	);
	set_weight(15);
	set_value(500);
	set_lore(
@AVATAR
This sickening armor is said to be the work of the worst that evil has to offer.  Legend says that a madman with a taste for humanoid flesh collected and tanned the faces of his victims and that the armor was enchanted from a foul magician from the Underdark.  The magic ensnared in the coat was the madman's reward for his participation of the resurrection of a dark goddess.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",4);
	set_ac(4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

void init(){
    ::init();
    if(!living(ETO)) return;
    if(!interactive(ETO)) return;
    
    set_heart_beat(1);

}

int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" develops a perplexed look as they wear the armor",ETO);
	tell_object(ETO,"%^MAGENTA%^You hear the cries of the forsaken in your mind as you don the armor");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" seems more at ease as they slip out of the armor",ETO);
	tell_object(ETO,"%^MAGENTA%^You hear a final whimper from the tormented souls");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 90){
	tell_room(environment(query_worn()),"%^MAGENTA%^One of the faces in the armor worn by "+ETOQCN+" emits a shattering %^BOLD%^scream%^RESET%^%^MAGENTA%^ at "+who->QCN+"",({ETO,who}));
	tell_object(ETO,"%^MAGENTA%^One of the faces in your armor emits a shattering %^BOLD%^scream%^RESET%^%^MAGENTA%^ at "+who->QCN+"!");
	tell_object(who,"%^MAGENTA%^You are struck by a scream emitted by the armor worn by "+ETOQCN+"!");
		who->do_damage("torso",roll_dice(1,10));
return damage;	}

}

void heart_beat(){
    object owner,env;
    int i,xx,yy;
    env = ETO;
    
    if(!objectp(ETO)) return;

    if(objectp(env) && living (env)) {
        owner = env;
        env = EETO;
    }

    xx = random(700);
    yy = random(2);

    
    if((xx > 690)) {
        switch(yy) {
            case 0:
                tell_object(owner,"\n%^RESET%^%^RED%^You hear the final wail of a victim from your past%^RESET%^\n");
                break;
            default:
                tell_object(owner,"\n%^RESET%^%^BLUE%^You hear the sounds of and smells of entrails falling on the ground%^RESET%^\n");
                break;
         }
          }
    }
